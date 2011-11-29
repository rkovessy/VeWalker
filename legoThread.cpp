#include "legoThread.h"

//Connection *connection = new Bluetooth();
//Brick *nxt = new Brick(connection);
//Motor *motor = new Motor(OUT_A, connection);
//Tilt *tilt = new Tilt (IN_1, connection, 0x02);
//Compass *compass = new Compass (IN_1, connection, 40, 0x02);
//Xyz_position *result = new Xyz_position();

LegoThread::LegoThread() {
    PI = (asin(0.5) * 6.0);
    counter = 0;
    magnitude = 0.0;
    lastrValueNXT = 0.0;
    //connection->connect(port); // '3' is the port the NXT is connected to via bluetooth. Different for every laptop
    qDebug() << "Connected to NXT" << endl;

    // Initialize capturing from webcam
    capture = NULL;
    //Throw an error when no device is connected
    if(NULL==(capture= cvCaptureFromCAM(0)))
    {
        printf("Could not detect camera.\n");
    }
    else
        qDebug() << "Connected to webcam" << endl;

    posX1 = 0;
    posY1 = 0;
    posX2 = 0;
    posY2 = 0;
    oppositeSide = 0;
    adjacentSide = 0;
    angleDegrees = 0;
    angleRads = 0;
}

IplImage* LegoThread::GetThresholdedImage(IplImage* img)
{
    // Convert the image into an HSV image
    IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
    cvCvtColor(img, imgHSV, CV_BGR2HSV);
    IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);
    cvInRangeS(imgHSV, cvScalar(0, 0, 236), cvScalar(119, 19, 255), imgThreshed);
    cvReleaseImage(&imgHSV);
    return imgThreshed;
}

void LegoThread::run()
{
    qDebug("LegoThread is running!");
    bool flag = false;
   do {
        time.restart();
        //UpdateRoll();
        //UpdateRotation();
        UpdateCamera();
        msec = double(time.elapsed());
        if (msec == 0.0) {
            //qDebug() << "msec == 0, divided by 0";
            //emit sendMotor(magnitude * timer_interval, false, zTrans); // sends data to GLWidget and updates graphics
        }
        //else
            //emit sendMotor(magnitude * timer_interval / msec, stepped, zTrans); // sends data to GLWidget and updates graphics
        //counter++;
    } while (!flag);
    exec();
}

void LegoThread::set(double a, int t) {
    timer_interval = double(t);
    double tmp = a / 2.0 + 2.0; // converts to feet from index of heights, ie 2' = 0, 2'6" = 1...
    height = tmp / 10.0; // converts to pixels
   // variance = motor->get_rotation(); // person must be standing still at start to get variance correct
    lastrValueNXT = 0;
    //firstroll = double(compass->read());
    emit sendMotor(0.0, false, height); // sends data to GLWidget and updates graphics
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}

void LegoThread::UpdateRotation()
{
   // rValueNXT = motor->get_rotation() - variance; // gets motors current position
    if (startupdating) {
        magnitude = abs(rValueNXT - lastrValueNXT) * PI / 180.0 * 0.3; // pi/180 to convert to rad, .3 = radius of walker, d = rtheta
        zTrans = height / 30.0 * sin(PI * (rValueNXT + 20) / 40) + height + height / 30;
    }
    if (rValueNXT > lastrValueNXT && left) {
        stepped = true;
        left = false;
    }
    else if (rValueNXT < lastrValueNXT && !left) {
        stepped = true;
        left = true;
    }
    else
        stepped = false;
    lastrValueNXT = rValueNXT; // present rValueNXT becomes the last one for the next UpdateRotation()
}

void LegoThread::UpdateRoll()// the left to right motion of the head
{
    if (counter % 2 == 0)
        //roll = double(compass->read());

        anglediff = roll - firstroll;
        if (fabs(anglediff) <= 180)
            anglediff = anglediff;
        else if (roll > firstroll)
            anglediff = roll - 360.0 - firstroll;
        else
            anglediff = 360.0 - firstroll + roll;

        anglediff /= 100;
    if (fabs(anglediff) < 0.15)
        anglediff = 0.0;
    emit sendCompass(anglediff);
}

void LegoThread::UpdateCamera()
{
    // Hold a single frame captured from the camera
    IplImage* frame = 0;
    frame = cvQueryFrame(capture);
    // Quit if no frame can be captured, return to capturing the next frame
    if(!frame) {
        return;
    }

    //Setup sequences to get contours
    CvSeq* contours;
    CvSeq* result;
    CvMemStorage *storage = cvCreateMemStorage(0);

    //Create moments for both IR leds
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    CvMoments *moments2 = (CvMoments*)malloc(sizeof(CvMoments));

    IplImage* imgThresh = GetThresholdedImage(frame);

    cvShowImage("video", imgThresh);
    //Get the contour vectors and store in contours
    cvFindContours(imgThresh, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

    //If at least one contour vector exists, begin getting data on the contours
    if(contours)
    {
        if (contours->first)
        {
            //For the first contour, store an array of points on the contour in result and then setup the moment data for the first vector
            result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);
            cvMoments(result, moments, 1);
            moment101 = cvGetSpatialMoment(moments, 1, 0);
            moment011 = cvGetSpatialMoment(moments, 0, 1);
            area1 = cvGetCentralMoment(moments, 0, 0);

            //Discard values that do not fit in range of camera for first point and set x and y values
            if (abs(moment101/area1) < 1000 || abs(moment011/area1)< 1000)
            {
                posX1 = moment101/area1;
                posY1 = moment011/area1;
                printf("LED1 position (%d,%d)\n", posX1, posY1);
            }


        }

        if (contours->h_next)
        {
            //For the second contour, store an array of points on the contour in result and then setup the moment data for the first vector
            result = cvApproxPoly(contours->h_next, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);
            cvMoments(result, moments2, 1);
            moment102 = cvGetSpatialMoment(moments2, 1, 0);
            moment012 = cvGetSpatialMoment(moments2, 0, 1);
            area2 = cvGetCentralMoment(moments2, 0, 0);

            //Discard values that do not fit in range of camera for second point and set x and y values
            if (abs(moment102/area2) < 1000 || abs(moment012/area2)< 1000)
            {
                posX2 = moment102/area2;
                posY2 = moment012/area2;
                printf("LED2 position (%d,%d)\n", posX2, posY2);
            }
        }
        emit sendCameraValues(posX1, posX2, posY1, posY2);
    }

    else
        printf("No contours detected.\n");
    oppositeSide = abs(posY2-posY1);
    adjacentSide = abs(posX2-posX1);
    if (adjacentSide != 0)
    {
        angleRads = atan(oppositeSide/adjacentSide);
        angleDegrees = angleRads*180/3.14159;
    }
    else
        angleDegrees=0;



    //printf("Theta: (%f)\n", angleDegrees);
    // Release the thresholded image and moments
    cvReleaseImage(&imgThresh);
    cvReleaseMemStorage(&storage);
    delete moments;
    delete moments2;

    // Release camera on exit
    //cvReleaseCapture(&capture);
}

/*
void LegoThread::UpdateTilt()
{
    if (counter % 20 == 0) {
    tilt->read(*result);
    tiltx = result->x;
    tilty = result->y;
    tiltz = result->z;
    qDebug()<< "x =" << tiltx << "y=" << tilty << "z=" << tiltz;
}
}*/
