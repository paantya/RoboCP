#pragma once
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "XMLConfig.h"
#include "KinectData.h"
#include "KinectBuffer.h"
#include "KinectViewer.h"
#include "pcl/compression/octree_pointcloud_compression.h"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <boost/asio.hpp>

#ifdef ENABLE_LOGGING
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <glog/raw_logging.h>
#endif

using boost::asio::ip::tcp;

using namespace pcl;
using namespace pcl::io;

using namespace std;

// Class purpose: receiving KinectData from robot and giving them to KinectBuffer
class KinectReceiver
{
public:
  void Start ();
  KinectReceiver(XMLConfig * x, KinectBuffer* b);
  ~KinectReceiver(void);
private:
  KinectBuffer* kinectBuffer;
  OctreePointCloudCompression<PointXYZ>* octreeCoder;
  string ip;
  string port;
};
