/**
  ******************************************************************************
  * @file    biaxial_servo_sample0.cpp
  * @author  Elechouse Team
  * @version V1.0
  * @date    2013-05-16
  * @brief   This file provides a demostration on 
              how to use biaxialservo driver
  ******************************************************************************
  * @note:
         Usage:
           - i --> up; 
           - k --> down; 
           - j --> left; 
           - l --> right;
           - o --> center; 
         This demo also can be used with Openwrt(wifi-car project).
  ******************************************************************************
  * @section  HISTORY
  
    V1.0    Initial version.
  */

#include "Servo.h"
#include "BiaxialServo.h"

BiaxialServo myCamera;
int xy_pin = 7;
int yz_pin = 8;

void setup()
{
  Serial.begin(115200);

#ifdef __DEBUG
  Serial.println("-----------Smart Car --------------\r\n");
#endif
  
  myCamera.begin(xy_pin, yz_pin);
}

void loop()
{
  unsigned char buf;

  if(Serial.available()){
    buf=Serial.read();
#ifdef __DEBUG
    Serial.write(buf);
#endif
    switch(buf){
      /** camera control */
    case 'i': 
    case 'I':
      /** camera up */
      myCamera.up();
      break;
    case 'k': 
    case 'K':
      /** camera down */
      myCamera.down();
      break;
    case 'j': 
    case 'J':
      /** camera left */
      myCamera.left();
      break;
    case 'L': 
    case 'l':
      /** camera right */
      myCamera.right();
      break;
    case 'O': 
    case 'o':
      /** center camera */
      myCamera.center();
      break;

    }
  }
}

