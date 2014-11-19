#include "QSendSender.h"


SendSender::SendSender (XMLConfig * x, SendBuffer * buf)
{
  port = atoi(x->SendPort.c_str() ); //reading port from config
  buffer = buf;
}

SendSender::~SendSender (void)
{
}

void KinectSender::connected()
{
  qDebug() << "SendSender: Connected!\n"; //TODO: write in log
  #ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "SendSender: Connected!");
  #endif
  while (socket->state() == 4 ) {
    /*
    *
    * Как заменить код в этом цикле на Qt?
    *
    */  
    boost::archive::xml_oarchive oa (socketStream); // We want to send objects in XML
    boost::shared_ptr<Send> sendData;
    sendData = buffer->Dequeue(); // Reading Send object from buffer     
    oa << BOOST_SERIALIZATION_NVP (sendData); // Serializing and sending it
	}  
  
}

void KinectSender::disconnected()
{
  qDebug() << "disconnected. :(\n"; //TODO: write in log
	#ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "disconnected.");
  #endif
}

void SendSender::Start ()
{
  try {
  socket = new QTcpSocket(this);
  connect(socket, SIGNAL(connected()),this, SLOT(connected()));
  connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
  connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

  tcp::iostream socketStream;

  qDebug() << "SendSender: Waiting for connection..\n"; //TODO: write in log
  #ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "SendSender: Waiting for connection..");
  #endif
  
  socket->connectToHost(localhost, port);; // waiting from connection from any IP
  
  }
  catch (exception& e) {
    cout << "SendSender: Exception: " << e.what () << endl; //TODO: write in log
    #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO, "SendSender: Exception: %s", e.what());
    #endif
  }

}
