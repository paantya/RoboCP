#pragma once
#include "SenderBase.h"
#include "Send.h"
#include "SendBuffer.h"
#include "XMLConfig.h"
#include <boost/asio.hpp>

#ifdef ENABLE_LOGGING
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <glog/raw_logging.h>
#endif

using boost::asio::ip::tcp;
using namespace std;

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

//Class purpose: taking Send object from buffer and sending it via TCP-IP
class SendSender : public SenderBase
{
  Q_OBJECT
public:
  void Start(); 
  SendSender(XMLConfig * x, SendBuffer * buf);
  ~SendSender(void);

signals:

public slots:
  void connected();
  void disconnected();
  void readyRead();

private:
  SendBuffer * buffer;
  int port;  
  QTcpSocket *socket;
};
