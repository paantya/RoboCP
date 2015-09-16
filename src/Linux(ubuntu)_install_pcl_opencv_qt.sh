#!/bin/bash

echo "update and upgrade all packeg:"
sudo apt-get update
sudo apt-get upgrade

echo "install QT:"
sudo apt-get install qt5.3
echo "end install QT.\n"

echo "install PCL:"
sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
sudo apt-get update
sudo apt-get install libpcl-all
echo "end install PCL.\n"

echo "install git:"
sudo apt-get install git
echo "end install git.\n"

echo "install CMake:"
sudo apt-get install cmake
echo "end install CMake.\n"

echo "install OpenCV:"
mkdir build_opencv
cd build_opencv
echo "install wget & unzip for download & unzip OpenCV_libs:"
sudo apt-get install wget unzip
wget http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/2.4.9/opencv-2.4.9.zip
unzip opencv-2.4.9.zip
cd opencv-2.4.9
echo "Для отображения окошек OpenCV требуется установленная библиотека GTK+ 2.x:"
sudo apt-get install libgtk2.0-dev
cmake CMakeLists.txt
make
sudo make install
cd ../..
rm -r build_opencv
echo "end install OpenCV.\n"

