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

    // Initialize capturing from webcam
    capture = cvCaptureFromCAM(-1);
    //Throw an error when no device is connected
   /* if(NULL==(capture= cvCaptureFromCAM(0)))
    {
        printf("Could not detect camera.\n");
    }
    else
        qDebug() << "Connected to webcam" << endl;*/

    /*if (IWROpenTracker() == ERROR_SUCCESS) {
        qDebug() << "Connected to headset" << endl;
        if (IWRSetFilterState)
            IWRSetFilterState(TRUE);
    }*/

    posX1 = 0;
    posY1 = 0;
    posX2 = 0;
    posY2 = 0;
    oppositeSide = 0;
    adjacentSide = 0;
    angleDegrees = 0;
    angleRads = 0;
    HTyaw = 0;
    HTpitch = 0;
    HTroll = 0;
}

IplImage* LegoThread::GetThresholdedImage(IplImage* img)
{
    // Convert the image into an HSV image

    IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
    cvCvtColor(img, imgHSV, CV_BGR2HSV);
    IplImage* imgThreshed1 = cvCreateImage(cvGetSize(img), 8, 1);
    //IplImage* imgThreshed2 = cvCreateImage(cvGetSize(img), 8, 1);

    //Convert to thresholded image for HSV color range selected
    //In Colorpic Hue needs to be divided by 2, as OCV has 180 range and ColorPic has 360. Sat and Val have 256 range
    //in both programs.
    //Change color based on what was selected from the demographics menu.
//    FILE * pFile;
//    pFile = fopen ("configdata.txt","r");

//    char trackingColor [100];
//    fgets (trackingColor , 100 , pFile );
//    fgets (trackingColor , 100 , pFile );
//    fgets (trackingColor , 100 , pFile );
//    fgets (trackingColor , 100 , pFile );

//    //Select green
//    if (trackingColor[12] == 'g')
//    {
//        printf("Green selected \n");
//        min_color1 = cvScalar(50,60,60,0);
//        max_color1 = cvScalar(80,180,256,0);
//    }
//    //Select orange
//    else if (trackingColor[12] == 'o')
//    {
//        printf("Orange selected \n");
//        min_color1 = cvScalar(50,60,60,0);
//        max_color1 = cvScalar(80,180,256,0);
//    }
//    //Select pink
//    else if (trackingColor[12] == 'p')
//    {
//        printf("Pink selected \n");
//        min_color1 = cvScalar(50,60,60,0);
//        max_color1 = cvScalar(80,180,256,0);
//    }
//    else
//        printf("Nothing selected \n");

    //Combine two thresholded images to account for color wrap around (if color wrap around exists for color of objects tracked)
    cvInRangeS(imgHSV, min_color1, max_color1, imgThreshed1);
    //cvInRangeS(imgHSV, min_color2, max_color2, imgThreshed2);
    //cvOr(imgThreshed1, imgThreshed2, imgThreshed1);

    //Flip image horizontally for normal playback
    cvFlip(imgThreshed1, NULL, 1);
    cvReleaseImage(&imgHSV);
    //cvReleaseImage(&imgThreshed2);
    return imgThreshed1;
}

IplImage* LegoThread::GetBlurredImage(IplImage* img)
{
    //Convert raw image to a blurred image using a Gaussian blur
    IplImage* imgBlur = cvCreateImage(cvGetSize(img), 8, 3);
    cvSmooth(img, imgBlur, CV_GAUSSIAN, 11, 11);
    return imgBlur;
}

IplImage* LegoThread::GetResizedImage(IplImage* img)
{
    //Resize image to 1/4 size to speed up processing
    IplImage* imgResized = cvCreateImage(cvSize(img->width, img->height), 8, 3);
    cvResize(img, imgResized, CV_INTER_AREA);
    return imgResized;
}

IplImage* LegoThread::GetDilatedImage(IplImage* img)
{
    //(Optional) Perform iterations of erosion on the image to filter noise
    cvErode(img, img, NULL, 1);
    //Perform iterations of dilation on the threshed image
    cvDilate(img, img, NULL, 6);
    return img;
}

void LegoThread::run()
{
    qDebug("LegoThread is running!");
    bool flag = false;
   do {

        msec = double(time.elapsed());
        if (msec >= 40)
        {
            UpdateCamera();
            time.restart();
        }
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
    //emit sendMotor(0.0, false, height); // sends data to GLWidget and updates graphics
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}


//Now Defunct - Feb 5th, 2012
/*
void LegoThread::UpdateRotation()
{
    rValueNXT = motor->get_rotation() - variance; // gets motors current position
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
*/

//Now Defunct - Feb 5th, 2012
/*void LegoThread::UpdateRoll()// the left to right motion of the head
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
}*/

//In its own thread, vuzixthread
/*void LegoThread::UpdateHTracking()
{
    IWRZeroSet();

    DWORD trk_res=IWRGetTracking(&HTyaw,&HTpitch, &HTroll);

    emit sendHTrackerValues(HTyaw, HTpitch, HTroll);
    //printf("yaw: [%li], pitch: [%li], roll: [%li]\n", HTyaw, HTpitch, HTroll);


}*/

void LegoThread::UpdatePotRotation()
{

    emit sendPotRotation(potRotation);
    //printf("yaw: [%li], pitch: [%li], roll: [%li]\n", HTyaw, HTpitch, HTroll);


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

    //cvShowImage("Raw Video", frame);
    //cvSaveImage("Raw.jpg",frame);


    //Setup sequences to get contours
    CvSeq* contours;
    CvSeq* result;
    CvMemStorage *storage = cvCreateMemStorage(0);

    //Create moments for both color blobs
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    CvMoments *moments2 = (CvMoments*)malloc(sizeof(CvMoments));

    //Resize image to reduce processing time
    IplImage* imgResized = GetResizedImage(frame);

    //Apply blur to improve detection under different lighting
    IplImage* imgBlurred = GetBlurredImage(imgResized);
    //cvSaveImage("imgBlurred.jpg",imgBlurred);
    //cvShowImage("Blurred", imgBlurred);

    //Get threshed image based on color selected for tracking
    IplImage* imgThresh = GetThresholdedImage(imgBlurred);
    //cvSaveImage("imgThresh.jpg",imgThresh);
    //cvShowImage("Thresholded", imgThresh);

    //Dilate image
    IplImage* imgDilated = GetDilatedImage(imgThresh);
    //cvSaveImage("imgDilated.jpg",imgDilated);
    //cvShowImage("Processed Video", imgDilated);


    //Get the contour vectors and store in contours
    cvFindContours(imgDilated, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

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
            if (abs(moment101/area1) < 10000 || abs(moment011/area1)< 10000)
            {
                posX1 = moment101/area1;
                posY1 = moment011/area1;
                moment_center1= cvPoint(posX1, posY1);
                //printf("Shoulder position 1(%d,%d)\n", posX1, posY1);

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
            if (abs(moment102/area2) < 10000 || abs(moment012/area2)< 10000)
            {
                posX2 = moment102/area2;
                posY2 = moment012/area2;
                moment_center2 = cvPoint(posX2, posY2);
                //printf("      Shoulder position 2: (%d,%d)\n", posX2, posY2);
            }
        }

        //Send cooridnates of moments as a signal
        emit sendCameraValues(posX1, posX2, posY1, posY2);
    }

    // Release images and moments
    cvReleaseImage(&imgThresh);
    cvReleaseImage(&imgResized);
    cvReleaseImage(&imgBlurred);
    cvReleaseImage(&imgDilated);
    cvReleaseMemStorage(&storage);
    delete moments;
    delete moments2;

    //Reset all position values - mywindow will not create a rotation around the z-axis if a value is zero,
    //ie. one or more contours are not present. Therefore, in each loop all values must be reset.
    posX2=0;
    posY2=0;
    posX1=0;
    posY1=0;

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
