#pragma once
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "DisplacementImages.h"
#include "Controller.h"
#include <opencv2/video/tracking_c.h>//for func "cvCalcOpticalFlowPyrLK()" if you use Linux

#define PI 3.1415  

class ImageFlowProcessing:
	public Controller
{
public:
	void Start(void);
	void CountDisplacement(IplImage *Img1, IplImage *Img2, DisplacementImages *Displacement);
	void ShowOpticalFlow(CvCapture *Capture);
	ImageFlowProcessing(void);
	~ImageFlowProcessing(void);
};
