#include "calibraterotation.h"
#include "ui_calibraterotation.h"

calibrateRotation::calibrateRotation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calibrateRotation)
{
    ui->setupUi(this);
    ui->captureError->setVisible(false);
    capture = cvCaptureFromCAM(-1);
    posX1 = 0;
    posY1 = 0;
    posX2 = 0;
    posY2 = 0;
    oppositeSide = 0;
    adjacentSide = 0;
    angleDegrees = 0;
    angleRads = 0;
    bool rightExtentCalibrated = false;
    bool leftExtentCalibrated = false;
}

calibrateRotation::~calibrateRotation()
{
    delete ui;
}

void calibrateRotation::calibrate(int leftRightIndex)
{
    IplImage* frame = 0;
    frame = cvQueryFrame(capture);
    // Quit if no frame can be captured, return to capturing the next frame
    if(!frame) {
        ui->captureError->setVisible(true);
        return;
    }

    ui->captureError->setVisible(false);

    //Setup sequences to get contours
    CvSeq* contours;
    CvSeq* result;
    CvMemStorage *storage = cvCreateMemStorage(0);

    //Create moments for both color blobs
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    CvMoments *moments2 = (CvMoments*)malloc(sizeof(CvMoments));

    //Process image
    IplImage* imgResized = GetResizedImage(frame);
    IplImage* imgBlurred = GetBlurredImage(imgResized);
    IplImage* imgThresh = GetThresholdedImage(imgBlurred);
    IplImage* imgDilated = GetDilatedImage(imgThresh);

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
            }
        }
    }

    //Write angles to correct variable
    if(posY2 != posY1)
    {
        if (leftRightIndex == 1){
            alphaLeftActual = abs(posX2-posX1)/abs(posY2-posY1);
        }
        else{
            alphaRightActual = abs(posX2-posX1)/abs(posY2-posY1);
        }
    }
    else
    {
        ui->captureError->setVisible(true);
    }

    // Release images and moments
    cvReleaseImage(&imgThresh);
    cvReleaseImage(&imgResized);
    cvReleaseImage(&imgBlurred);
    cvReleaseImage(&imgDilated);
    cvReleaseMemStorage(&storage);
    delete moments;
    delete moments2;
}

IplImage* calibrateRotation::GetThresholdedImage(IplImage* img)
{
    // Convert the image into an HSV image

    IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
    cvCvtColor(img, imgHSV, CV_BGR2HSV);
    IplImage* imgThreshed1 = cvCreateImage(cvGetSize(img), 8, 1);
    //IplImage* imgThreshed2 = cvCreateImage(cvGetSize(img), 8, 1);

    //Convert to thresholded image for HSV color range selected
    //In Colorpic Hue needs to be divided by 2, as OCV has 180 range and ColorPic has 360. Sat and Val have 256 range
    //in both programs.
    //Change color based on what was selected from the configuration toolbox in the calibration menu

        //Select orange
        if (ui->neonOrange->isChecked())
        {
            min_color1 = cvScalar(50,60,60,0);
            max_color1 = cvScalar(80,180,256,0);
        }
        //Select pink
        else if (ui->neonPink->isChecked())
        {
            min_color1 = cvScalar(50,60,60,0);
            max_color1 = cvScalar(80,180,256,0);
        }
        //Choose green by default
        else
        {
            min_color1 = cvScalar(50,60,60,0);
            max_color1 = cvScalar(80,180,256,0);
        }

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

IplImage* calibrateRotation::GetBlurredImage(IplImage* img)
{
    //Convert raw image to a blurred image using a Gaussian blur
    IplImage* imgBlur = cvCreateImage(cvGetSize(img), 8, 3);
    cvSmooth(img, imgBlur, CV_GAUSSIAN, 11, 11);
    return imgBlur;
}

IplImage* calibrateRotation::GetResizedImage(IplImage* img)
{
    //Resize image to 1/4 size to speed up processing
    IplImage* imgResized = cvCreateImage(cvSize(img->width, img->height), 8, 3);
    cvResize(img, imgResized, CV_INTER_AREA);
    return imgResized;
}

IplImage* calibrateRotation::GetDilatedImage(IplImage* img)
{
    //(Optional) Perform iterations of erosion on the image to filter noise
    cvErode(img, img, NULL, 1);
    //Perform iterations of dilation on the threshed image
    cvDilate(img, img, NULL, 6);
    return img;
}

void calibrateRotation::on_rightExtentCapture_clicked()
{
    int rightIndex = 2;
    rightExtentCalibrated = true;
    calibrate(rightIndex);
    return;
}

void calibrateRotation::on_leftExtentCapture_clicked()
{
    int leftIndex = 1;
    leftExtentCalibrated=true;
    calibrate(leftIndex);
    return;
}

void calibrateRotation::on_completeButton_clicked()
{
    //Write alphaRightActual and alphaLeftActual to DB
    //If left and right were not calibrated,just write zeros.
//    if (rightExtentCalibrated == true && leftExtentCalibrated == true)
//    {

//    }
//    else
//    {

//    }
    this->hide();
}

void calibrateRotation::on_cancelButton_clicked()
{
    this->hide();
}

//logic to select only green, pink, or orange color tracking radio button, but not more than one
void calibrateRotation::on_neonGreen_clicked()
{
    if(ui->neonOrange->isChecked())
        ui->neonOrange->setChecked(false);
    else if(ui->neonPink->isChecked())
        ui->neonPink->setChecked(false);
    else
        ui->neonGreen->setChecked(true);
}

void calibrateRotation::on_neonOrange_clicked()
{
    if(ui->neonGreen->isChecked())
        ui->neonGreen->setChecked(false);
    else if(ui->neonPink->isChecked())
        ui->neonPink->setChecked(false);
    else
        ui->neonOrange->setChecked(true);
}

void calibrateRotation::on_neonPink_clicked()
{
    if(ui->neonOrange->isChecked())
        ui->neonOrange->setChecked(false);
    else if(ui->neonGreen->isChecked())
        ui->neonGreen->setChecked(false);
    else
        ui->neonPink->setChecked(true);
}