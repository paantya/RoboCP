#pragma once
#include "QClientReceiver.h"


ClientReceiver::ClientReceiver(XMLConfig * x)
{
  port = x->CommandPort; // Reading port from config
}


ClientReceiver::~ClientReceiver(void)
{
}

void MyTcpSocket::connected()
{
  qDebug() << "ClientReceiver: Connected!\n"; //TODO: write in log
	#ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "ClientReceiver: Connected!");
  #endif
}

void MyTcpSocket::disconnected()
{
  qDebug() << "disconnected. :(\n"; //TODO: write in log
	#ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "disconnected.");
  #endif
}

void MyTcpSocket::readyRead()
{
  // read the data from the socket
  ia >> BOOST_SERIALIZATION_NVP(com);/*
  *
  *      Как заменить чтение из сокета  ia >> BOOST_SERIALIZATION_NVP(com)  
  *           и последующую её сериализацию?
  *
  *
  *           socket->readAll();
  *
  *
  */
  qDebug() << "New command: " << com.ComType << " " << com.ComCondition << " " << com.Value << '\n'; // TODO: command buffer
  #ifdef ENABLE_LOGGING
	RAW_LOG (INFO, "New command: %d %d %f", com.ComType, com.ComCondition, com.Value);
  endif

}


void ClientReceiver::Start ()
{
  try {
  socket = new QTcpSocket(this);
  connect(socket, SIGNAL(connected()),this, SLOT(connected()));
  connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
  connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

  tcp::iostream socketStream;

  qDebug() << "ClientReceiver: Waiting for connection..\n"; //TODO: write in log
	#ifdef ENABLE_LOGGING
  RAW_LOG (INFO, "ClientReceiver: Waiting for connection..");
  #endif
  
	boost::archive::xml_iarchive ia(socketStream); // We will receive objects in XML
	//Command com вынес в обявление класса в QClientReceiver.h
  
  socket->connectToHost(localhost, port);; // waiting from connection from any IP
  }
  catch (exception& e) {
    cout << "ClientReceiver: Exception: " << e.what () << endl; //TODO: write in log
    #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO, "ClientReceiver: Exception: %s", e.what());
    #endif
  }
}
