#pragma once
#include "Received.h"
#include <time.h>
#include <opencv/cv.h>
#include "DisplacementImages.h"
class CameraReceived :
  public Received
{
public:
  IplImage *Frame;
  Vector Motion;
  time_t Time;
  CameraReceived(IplImage *ImageToSave);
  CameraReceived();
  ~CameraReceived(void);
};
