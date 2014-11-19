#include "QKinectSender.h"


KinectSender::KinectSender(XMLConfig * x, KinectBuffer * buf)
{
  port = atoi(x->KinectPort.c_str() ); //Reading port from config

  // We will encode point clouds before sending via octreeCoder
  // Parameters for constructor are taken from config
  octreeCoder = new OctreePointCloudCompression<PointXYZ> (x->CompressionProfile, x->ShowStatistics, x->PointResolution,
                                                         x->OctreeResolution, x->DoVoxelGridDownDownSampling, x->IFrameRate,
                                                         x->DoColorEncoding, x->ColorBitResolution);
  buffer = buf;
}

void KinectSender::connected()
{
  qDebug() << "KinectSender: Connected!\n"; //TODO: write in log
  #ifdef ENABLE_LOGGING
	RAW_LOG (INFO, "KinectSender: Connected!");
  #endif
  
  while (socket->state() == 4 ) {
    /*
    *
    * Как заменить код в этом цикле на Qt?
    *
    */
	  boost::shared_ptr<KinectData> pdata;
	  pdata = buffer->Dequeue(); // Read KinectData from buffer
	  socketStream << pdata->Time; // Send time
	  socketStream.flush();
	  octreeCoder->encodePointCloud (pdata->Cloud, socketStream); // Then send point cloud	
	}
}

void KinectSender::disconnected()
{
  qDebug() << "disconnected. :(\n"; //TODO: write in log
	#ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "disconnected.");
  #endif
}


void KinectSender::Start()
{
  try {
  socket = new QTcpSocket(this);
  connect(socket, SIGNAL(connected()),this, SLOT(connected()));
  connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
  connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

  tcp::iostream socketStream;

  qDebug() << "KinectSender: Waiting for connection...\n"; //TODO: write in log
  #ifdef ENABLE_LOGGING
	RAW_LOG (INFO, "KinectSender: Waiting for connection..");
  #endif
  
  socket->connectToHost(localhost, port);; // waiting from connection from any IP
  }
  catch (exception& e) {
    cout << "KinectSender: Exception: " << e.what () << endl; //TODO: write in log
    #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO, "KinectSender: Exception: %s", e.what());
    #endif
  }

}

KinectSender::~KinectSender(void)
{
  delete (octreeCoder);
}
