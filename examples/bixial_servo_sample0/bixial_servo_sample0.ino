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

