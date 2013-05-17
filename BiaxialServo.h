/**
  ******************************************************************************
  * @file    BiaxialServo.h
  * @author  Elechouse Team
  * @version V1.0
  * @date    2013-05-17
  * @brief   This file contains all the functions prototypes for the BiaxialServo
  *          firmware library functions.
  ******************************************************************************
    @note
         This driver is use for driving two servos(like Tower Pro SG90)
  ******************************************************************************
  * @section  HISTORY
  
    V1.0    Initial version.
  
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, ELECHOUSE SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2013 ELECHOUSE</center></h2>
  ******************************************************************************
  */

#ifndef __BIAXIAL_SERVO_H
#define __BIAXIAL_SERVO_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "wiring_private.h"
#include "Servo.h"

#define BIAXIALSERVO_XY_ANGLE_MAX            175
#define BIAXIALSERVO_XY_ANGLE_MIN            5
#define BIAXIALSERVO_XY_ANGLE_INC            3

#define BIAXIALSERVO_YZ_ANGLE_MAX            160
#define BIAXIALSERVO_YZ_ANGLE_MIN            0
#define BIAXIALSERVO_YZ_ANGLE_INC            3

class BiaxialServo{
public:
	BiaxialServo();
	void begin(int xy_pin_num, int yz_pin_num);
	void up();
	void down();
	void left();
	void right();
	void center();
private:
	
	Servo servo_xy;		/*!< xy direction servo*/
	Servo servo_yz;		/*!< yz direction servo*/
	
	int xy_angle;		/*!< xy direction servo angle*/
	int yz_angle;		/*!< yz direction servo angle**/
	
	int xy_pin;			/*!< xy direction servo pin number*/
	int yz_pin;			/*!< xy direction servo pin number**/
};


#endif