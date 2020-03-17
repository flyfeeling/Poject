#!/bin/sh
set -e
#sudo yum install -y sqlite3
#sudo yum install -y libsqlite3-dev
#sudo yum install -y lua5.3
sudo yum install -y automake
sudo yum install -y libtool
sudo yum install -y libsysfs-devel.x86_64

#sudo yum install mysql-server -y
#sudo yum install mysql-client -y
#sudo yum install libmysqlclient-dev -y

sudo tar zxvf protobuf-cpp-3.4.0.tar.gz
cd protobuf-3.4.0  
sudo  sh ./autogen.sh
sudo  ./configure
sudo make -j4

cd ..
sudo tar zxvf lua-5.3.0.tar.gz
sudo cd lua-5.3.0  
sudo make linux -j4

cd ..
sudo tar zxvf sqlite-autoconf-3270200.tar.gz
cd sqlite-autoconf-3270200
sudo  ./configure
sudo make -j4


