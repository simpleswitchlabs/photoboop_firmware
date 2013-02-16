#include <WProgram.h>

void photo_light(int number)
{
  //turns on the photo light associated with number
  switch (number)
  {
  case 1:
    analogWrite(PIN_1,BRIGHT);
    break;

  case 2:
    analogWrite(PIN_2,BRIGHT);
    break;

  case 3:
    analogWrite(PIN_3,BRIGHT);
    break;

  case 4:
    analogWrite(PIN_4,BRIGHT);
    break;
  }
}


void photo_dark(int number)
{
  //turns off the photo light associated with number
  switch (number)
  {
  case 1:
    digitalWrite(PIN_1,0);
    break;

  case 2:
    digitalWrite(PIN_2,0);
    break;

  case 3:
    digitalWrite(PIN_3,0);
    break;

  case 4:
    digitalWrite(PIN_4,0);
    break;
    
  default:
    break;
  }
}

void photo_dark_all()
{
  digitalWrite(PIN_1,0);
  digitalWrite(PIN_2,0);
  digitalWrite(PIN_3,0);
  digitalWrite(PIN_4,0);
}

void photo_light_all()
{
  digitalWrite(PIN_1,1);
  digitalWrite(PIN_2,1);
  digitalWrite(PIN_3,1);
  digitalWrite(PIN_4,1);
}

void photo_show(int number)
{
  switch(number)
  {
    case 1:
      digitalWrite(PIN_1,1);
      digitalWrite(PIN_2,0);
      digitalWrite(PIN_3,0);
      digitalWrite(PIN_4,0);
      break;
      
    case 2:
      digitalWrite(PIN_1,1);
      digitalWrite(PIN_2,1);
      digitalWrite(PIN_3,0);
      digitalWrite(PIN_4,0);
      break;
      
    case 3:
      digitalWrite(PIN_1,1);
      digitalWrite(PIN_2,1);
      digitalWrite(PIN_3,1);
      digitalWrite(PIN_4,0);
      break;
      
    case 4:
      digitalWrite(PIN_1,1);
      digitalWrite(PIN_2,1);
      digitalWrite(PIN_3,1);
      digitalWrite(PIN_4,1);
      break;
  }
}
