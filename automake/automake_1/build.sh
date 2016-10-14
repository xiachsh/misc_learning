#!/bin/bash 


cd hand
###### Run autoscan  and modify configure.scan and move to configure.ac
#autoscan

##### Run aclocal to generate aclocal.m4 #####
aclocal        

##### run autoheader to generate config.h.in####
autoheader 

##### create Makefile.am ########
##### run automake to generate the Makefile.in###
touch COPYING INSTALL NEWS README AUTHORS ChangeLog
automake --add-missing

######  run autoconf to generate configure########
autoconf

cd ..



###### Run autoscan  and modify configure.scan and move to configure.ac
#autoscan

##### Run aclocal to generate aclocal.m4 #####
aclocal        

##### run autoheader to generate config.h.in####
autoheader 

##### create Makefile.am ########
##### run automake to generate the Makefile.in###
touch COPYING INSTALL NEWS README AUTHORS ChangeLog
automake --add-missing

######  run autoconf to generate configure########
autoconf


###### compile ######
./configure 
make


./arm
