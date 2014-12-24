  /* 
 Arduino-powered photobooth firmware
 Simple Switch Labs
 April 10, 2011
 */
#include "pins.h"
#include "sevenseg.h"

//byte sleepTab[] = {
//      0,   0,   0,   0,   0,   0,   0,   0,   0,   1,
//      1,   1,   2,   3,   4,   5,   6,   8,  10,  13,
//     15,  19,  22,  26,  31,  36,  41,  47,  54,  61,
//     68,  76,  84,  92, 101, 110, 120, 129, 139, 148,
//    158, 167, 177, 186, 194, 203, 211, 218, 225, 232,
//    237, 242, 246, 250, 252, 254, 255, 255, 254, 252, 
//    250, 246, 241, 237, 232, 225, 218, 211, 203, 194, 
//    186, 177, 167, 158, 148, 139, 129, 120, 110, 101,
//    92, 84, 76, 68, 61, 54, 47, 41, 36, 31, 26, 22, 
//    19, 15, 13, 10, 8, 6, 5, 4, 3, 2, 1, 1, 1, 0, 0, 
//    0, 0, 0, 0, 0, 0, 0 };
    
//int sleep_position = sizeof(sleepTab);
int sleep_position = 0;
int sleep = sleep_position;
int sleep_speed = 8;

int camera_timer = 0; //tracks how long the camera has been idle and gives it a wakeup signal


void setup()
{
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GRN_PIN, OUTPUT);
  pinMode(BLU_PIN, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  
  pinMode(FLASH, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

  pinMode(USB_REMOTE, OUTPUT);

  pinMode(WIRED_FOCUS, OUTPUT);
  pinMode(WIRED_SHUTTER, OUTPUT);
  
  pinMode(POWER_TOGGLE, OUTPUT);
  pinMode(POWER_SENSE, INPUT);
  
  digitalWrite(WIRED_FOCUS,0);
  digitalWrite(WIRED_SHUTTER,0);
  
  camera_checkpower();

  //a quick test of the displays
  
  digitalWrite(FLASH, 1);
  
  for(int i = 0; i<10; i++)
  {
    show(i);
    delay(120);
  }
  
  digitalWrite(FLASH,0);

  segments_off();




}


void loop()
{
  delay(50);
  int button_state = digitalRead(BUTTON_PIN);
  
  if(button_state == 1)
  {
    camera_timer = 0;
    sleep_position = 0;
    
    rgbled('r');
    
    camera_wakeup();
    
    for(int i = 4; i > 0; i--)
    {
      countdown(5);
      take_a_picture();
    }
   
  }
  
  else
  {
    show(0);
    camera_timer ++;
    if(camera_timer > 600) //600 is about 1/2 minutes, most cameras fall asleep after 2 minutes
    {
      camera_wakeup();
      camera_timer = 0;
      sleep_position = 0;
    }
    
    sleep_position+=sleep_speed;
    //if(sleep_position > sizeof(sleepTab)-2)
    if(sleep_position > 255)
    {
      if(sleep_position > 510)
      {
        sleep_position = 0;
        sleep = sleep_position;
      }
      else
      {
        sleep = 255 - (sleep_position-255);
      }        
    }
    else
    {
      sleep = sleep_position;
    }

      
    //analogWrite(GRN_PIN, sleepTab[sleep_position]);
    analogWrite(GRN_PIN, sleep);
    digitalWrite(RED_PIN, 0);
    digitalWrite(BLU_PIN, 0);
    
  }
}


void camera_wakeup()
{
  camera_checkpower();
  
  //triggers the remote so the camera wakes up
  digitalWrite(WIRED_FOCUS,HIGH);
  digitalWrite(USB_REMOTE,HIGH);
  delay(CAMERA_TRIGGER_DELAY);
  digitalWrite(WIRED_SHUTTER,LOW);
  digitalWrite(WIRED_FOCUS,LOW);
  digitalWrite(USB_REMOTE,LOW);
}
  

void take_a_picture()
{
  //this 600ms sequence should handle most cameras
  //if needed, make CAMERA_TRIGGER_DELAY longer
  if(CHDK_CAM)
  {
    show(0);
    digitalWrite(USB_REMOTE,HIGH);
    delay(CAMERA_TRIGGER_DELAY);
   
    digitalWrite(USB_REMOTE,LOW);
    delay(CAMERA_TRIGGER_DELAY);
    
    rgbled('0');
    delay(CAMERA_TRIGGER_DELAY);
    
  
    digitalWrite(USB_REMOTE,HIGH);
    delay(CAMERA_TRIGGER_DELAY * 2);
    
    rgbled('w');
    delay(CAMERA_TRIGGER_DELAY);
    digitalWrite(USB_REMOTE,LOW);
    
    rgbled('0');
    delay(CAMERA_TRIGGER_DELAY); //added this delay to hopefully prevent whiteout
    
    if(WIRED_FLASH)
    {
      digitalWrite(FLASH,HIGH);
      delay(25);
      digitalWrite(FLASH,LOW);
    }
    
    rgbled('r');
  }
  else if(DSLR_CAM)
  {
    show(0);
    digitalWrite(WIRED_FOCUS,HIGH);
    digitalWrite(USB_REMOTE,HIGH);
    delay(CAMERA_TRIGGER_DELAY);
   
    digitalWrite(USB_REMOTE,LOW);
    delay(CAMERA_TRIGGER_DELAY);
    
    rgbled('0');
    digitalWrite(WIRED_SHUTTER,HIGH);
    delay(CAMERA_TRIGGER_DELAY);
    
  
    digitalWrite(USB_REMOTE,HIGH);
    delay(CAMERA_TRIGGER_DELAY * 2);
    
    rgbled('w');
    delay(CAMERA_TRIGGER_DELAY);
    digitalWrite(WIRED_FOCUS,LOW);
    digitalWrite(WIRED_SHUTTER,LOW);
    digitalWrite(USB_REMOTE,LOW);
    
    rgbled('0');
    delay(CAMERA_TRIGGER_DELAY); //added this delay to hopefully prevent whiteout
    digitalWrite(FLASH,HIGH);
    delay(25);
    digitalWrite(FLASH,LOW);
    
    rgbled('r');
    
    if(WIRED_FLASH)
    {
      digitalWrite(FLASH,HIGH);
      delay(25);
      digitalWrite(FLASH,LOW);
    }
  }
  
}


void countdown(int number)
{
  for(int i = number; i>-1; i--)
  {
    show(i);
    delay(1000); //makes each pause 1 second long
  }
}

void rgbled(char color)
{
  switch (color)
  {
    case 'r'://red
      analogWrite(RED_PIN, 254);
      analogWrite(GRN_PIN, 0);
      analogWrite(BLU_PIN, 0);
      break;
      
    case 'w'://white
      analogWrite(RED_PIN, 254);
      analogWrite(GRN_PIN, 254);
      analogWrite(BLU_PIN, 254);
      break;
      
    case '0'://black
      analogWrite(RED_PIN, 0);
      analogWrite(GRN_PIN, 0);
      analogWrite(BLU_PIN, 0);
      break;
      
    case 'b': //blue
      analogWrite(RED_PIN, 0);
      analogWrite(GRN_PIN, 0);
      analogWrite(BLU_PIN, 254);
      break;
  }
          
}

void camera_checkpower()
{
  //for use with hand-wired cameras
  //if the power sense line is too low, will attempt to power on the camera
  
//  int power_level = analogRead(POWER_SENSE);
//  
//  while (power_level < 50)
//  {
//    rgbled('b'); //sets the rgb led to bright blue while trying to power the camera back on
//    
//    digitalWrite(POWER_TOGGLE, HIGH);
//    delay(500);
//    digitalWrite(POWER_TOGGLE, LOW);
//    delay(100);
//    power_level = analogRead(POWER_SENSE);
//  }
}

