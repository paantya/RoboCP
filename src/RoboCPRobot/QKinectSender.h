#pragma once
#include "SenderBase.h"
#include "KinectData.h"
#include "KinectBuffer.h"
#include "XMLConfig.h"
#include <boost/asio.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include "pcl/compression/octree_pointcloud_compression.h"

#ifdef ENABLE_LOGGING
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <glog/raw_logging.h>
#endif

using boost::asio::ip::tcp;
using namespace pcl;
using namespace pcl::octree;
using namespace std;

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

//Class purpose: taking KinectData object from buffer and sending it via TCP-IP
class KinectSender : public SenderBase
{
  Q_OBJECT
public:
  void Start();
  KinectSender(XMLConfig * x, KinectBuffer * buf);
  ~KinectSender(void);

signals:

public slots:
  void connected();
  void disconnected();
  void readyRead();
    
  
private:
  OctreePointCloudCompression<PointXYZ>* octreeCoder;
  KinectBuffer * buffer;
  int port;
  QTcpSocket *socket;

};
