/**
  ******************************************************************************
  * @file    BiaxialServo.cpp
  * @author  Elechouse Team
  * @version V1.0
  * @date    2013-05-17
  * @brief   This file provides all the BiaxialServo firmware functions.
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

#include "BiaxialServo.h"

/**
	@brief constructor
*/
BiaxialServo :: BiaxialServo()
{

}

/**
	@brief begin function of MOTOR class, must called in Arduino **setup** funciton.
	@param xy_pin_num --> pin used to control xy direction servo
	@param yz_pin_num --> pin used to control yz direction servo
*/
void BiaxialServo :: begin(int xy_pin_num, int yz_pin_num)
{
	xy_pin = xy_pin_num;
	yz_pin = yz_pin_num;
	
	servo_xy.attach(xy_pin);
	servo_yz.attach(yz_pin);

	xy_angle = 90;
	yz_angle = 0;

	servo_xy.write(xy_angle);
	servo_yz.write(yz_angle);
}

/**
	@brief yz servo up
*/
void BiaxialServo :: up()
{
	yz_angle+=BIAXIALSERVO_YZ_ANGLE_INC;
	if(yz_angle>BIAXIALSERVO_YZ_ANGLE_MAX) {
		yz_angle = BIAXIALSERVO_YZ_ANGLE_MAX;
	}
	servo_yz.write(yz_angle);
}

/**
	@brief yz servo down
*/
void BiaxialServo :: down()
{
	yz_angle-=BIAXIALSERVO_YZ_ANGLE_INC;
	if(yz_angle < BIAXIALSERVO_YZ_ANGLE_MIN) {
		yz_angle = BIAXIALSERVO_YZ_ANGLE_MIN;
	}
	servo_yz.write(yz_angle);
}

/**
	@brief xy servo left
*/
void BiaxialServo :: left()
{
	xy_angle += BIAXIALSERVO_XY_ANGLE_INC;
	if(xy_angle>BIAXIALSERVO_XY_ANGLE_MAX) {
		xy_angle = BIAXIALSERVO_XY_ANGLE_MAX;
	}
	servo_xy.write(xy_angle);
}

/**
	@brief yz servo right
*/
void BiaxialServo :: right()
{
	/** camera right */
	xy_angle -= BIAXIALSERVO_YZ_ANGLE_INC;
	if(xy_angle < BIAXIALSERVO_YZ_ANGLE_MIN) {
		xy_angle = BIAXIALSERVO_YZ_ANGLE_MIN;
	}
	servo_xy.write(xy_angle);
}

/**
	@brief center the two servos
*/
void BiaxialServo :: center()
{
	xy_angle = 90;
	yz_angle = 0;
	servo_xy.write(xy_angle);
	servo_yz.write(yz_angle);
}