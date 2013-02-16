  /* 
 Arduino-powered photobooth firmware
 Simple Switch Labs
 April 10, 2011
 */
#include "pins.h"
#include "sevenseg.h"
#include "music.h"
#include "lights.h"


int READY_ = 4;
int BUSY_ = 3;
int CHANGE_ = 2;
int POSES_ = 1;


void setup()
{
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);

  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  
  pinMode(PIEZO_PIN, OUTPUT);
  
  pinMode(FLASH, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

  pinMode(USB_REMOTE, OUTPUT);

  pinMode(WIRED_FOCUS, OUTPUT);
  pinMode(WIRED_SHUTTER, OUTPUT);
  
  digitalWrite(WIRED_FOCUS,0);
  digitalWrite(WIRED_SHUTTER,0);

  //a quick test of the displays
  
  digitalWrite(FLASH, 1);
  
  for(int i = 0; i<10; i++)
  {
    show(i);
    delay(120);
  }
  
  digitalWrite(FLASH,0);

  segments_off();

  for(int j = 1; j<5; j++)
  {
    photo_light(j);
    delay(120);
    photo_dark(j);
  }


}


void loop()
{
      photo_booth();
}


void photo_booth()
{
  delay(50);
  int button_state = digitalRead(BUTTON_PIN);
  
  if(button_state == 1)
  {
    camera_wakeup();
    photo_dark_all();
    photo_light(BUSY_);
    
    for(int shot_number = (SHOTS); shot_number > 0; shot_number --)
    {
      show(shot_number);
      
      if(shot_number < SHOTS)
      {
        for(int i=4;i>0;i--)
        {
          photo_light(CHANGE_);
          delay(400);
          photo_dark(CHANGE_);
          photo_light(POSES_);
          delay(400);
          photo_dark(POSES_);
        }
        delay (500);
      }
      else
      {
        delay(2000);
      }
      
      take_a_picture();
      show(shot_number); //this repetition fixes problems with display
          
    }
   
  }
  
  else
  {
    show(SHOTS);
    photo_dark_all();
    photo_light(READY_);
  }
}


void camera_wakeup()
{
  //triggers the remote so the camera wakes up
  digitalWrite(WIRED_FOCUS,HIGH);
  digitalWrite(USB_REMOTE,HIGH);
  //digitalWrite(WIRED_SHUTTER,HIGH);
  delay(CAMERA_TRIGGER_DELAY);
  //digitalWrite(WIRED_SHUTTER,LOW);
  //digitalWrite(WIRED_FOCUS,LOW);
//  digitalWrite(USB_REMOTE,LOW);
//  delay(CAMERA_TRIGGER_DELAY);
  //digitalWrite(WIRED_FOCUS,HIGH);
  //digitalWrite(USB_REMOTE,HIGH);
//  digitalWrite(WIRED_SHUTTER,HIGH);
//  delay(CAMERA_TRIGGER_DELAY);
  digitalWrite(WIRED_SHUTTER,LOW);
  digitalWrite(WIRED_FOCUS,LOW);
  digitalWrite(USB_REMOTE,LOW);
}

  

void take_a_picture()
{
  //this 600ms sequence should handle most cameras
  //if needed, make CAMERA_TRIGGER_DELAY longer
  
  //circle(0);
  digitalWrite(WIRED_FOCUS,HIGH);
  digitalWrite(USB_REMOTE,HIGH);
  delay(CAMERA_TRIGGER_DELAY);

  //circle(1);
  delay(CAMERA_TRIGGER_DELAY);
  
  //circle(2);
  digitalWrite(USB_REMOTE,LOW);
  delay(CAMERA_TRIGGER_DELAY);
  
  //circle(3);
  digitalWrite(WIRED_SHUTTER,HIGH);
  delay(CAMERA_TRIGGER_DELAY);
  
  //circle(4);
  digitalWrite(USB_REMOTE,HIGH);
  delay(CAMERA_TRIGGER_DELAY);
  
  //circle(5);
  delay(CAMERA_TRIGGER_DELAY);
  digitalWrite(WIRED_FOCUS,LOW);
  digitalWrite(WIRED_SHUTTER,LOW);
  digitalWrite(USB_REMOTE,LOW);
  
  digitalWrite(FLASH,HIGH);
  delay(75);
  digitalWrite(FLASH,LOW);
  
}


void countdown(int number, int note)
{
  for(int i = number; i>0; i--)
  {
    show(i);
    PlayNote(note,LEN_E);
    delay(1000-LEN_E); //makes each pause 1 second long
  }
}





