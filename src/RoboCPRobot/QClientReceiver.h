#pragma once
#include "XMLConfig.h"
#include "Command.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>

#ifdef ENABLE_LOGGING
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <glog/raw_logging.h>
#endif

#include <boost/asio.hpp>


using boost::asio::ip::tcp;

using namespace std;

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

// Class purpose: Receiving commands from server
class ClientReceiver
{
  Q_OBJECT
public:
  void Start ();
  ClientReceiver(XMLConfig * x);
  ~ClientReceiver(void);
  
signals:

public slots:
  void connected();
  void disconnected();
  void readyRead();
  
private:
  string port;
  QTcpSocket *socket;
  Command com;
};


