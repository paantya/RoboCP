#pragma once
#include "Controller.h"
#include <time.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "XMLConfig.h"
#include "CameraReceivedBuffer.h"
#include "ImageFlowProcessing.h"

class CameraController :
  public Controller
{
private:
  int cameraNum;
  int fps;
  int width;
  int height;
  CameraReceivedBuffer *buffer;
public:
  void Start(void);
  CameraReceivedBuffer *GetBuffer(void);
  CameraController(XMLConfig *x, CameraReceivedBuffer *buf);
  ~CameraController(void);
};
