#include <Arduino.h>

//******7-segment utilities*********

void segments_off()
{
  //turns all segments off
  digitalWrite(PIN_A,TURN_OFF);
  digitalWrite(PIN_B,TURN_OFF);
  digitalWrite(PIN_C,TURN_OFF);
  digitalWrite(PIN_D,TURN_OFF);
  digitalWrite(PIN_E,TURN_OFF);
  digitalWrite(PIN_F,TURN_OFF);
  digitalWrite(PIN_G,TURN_OFF);
}

void segments_on()
{
  //turns all segments on
  digitalWrite(PIN_A,TURN_ON);
  digitalWrite(PIN_B,TURN_ON);
  digitalWrite(PIN_C,TURN_ON);
  digitalWrite(PIN_D,TURN_ON);
  digitalWrite(PIN_E,TURN_ON);
  digitalWrite(PIN_F,TURN_ON);
  digitalWrite(PIN_G,TURN_ON);
}


void segment_light(int segment)
{
  switch(segment)
  {
  case 0:
    digitalWrite(PIN_A, TURN_ON);
  case 1:
    digitalWrite(PIN_B, TURN_ON);
  case 2:
    digitalWrite(PIN_C, TURN_ON);
  case 3:
    digitalWrite(PIN_D, TURN_ON);
  case 4:
    digitalWrite(PIN_E, TURN_ON);
  case 5:
    digitalWrite(PIN_F, TURN_ON);
  case 6:
    digitalWrite(PIN_G, TURN_ON);
  }
}

void show(int number)
{
  //takes a 0-9 number and sets the appropriate character for the LED display
  //doesn't test if the number is in range 
  //(if number isn't in range, character isn't changed)

  switch (number)
  {
  case 0:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_ON);
    digitalWrite(PIN_E,TURN_ON);
    digitalWrite(PIN_F,TURN_ON);
    digitalWrite(PIN_G,TURN_OFF);
    break;

  case 1:
    digitalWrite(PIN_A,TURN_OFF);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_OFF);
    digitalWrite(PIN_E,TURN_OFF);
    digitalWrite(PIN_F,TURN_OFF);
    digitalWrite(PIN_G,TURN_OFF);
    break;

  case 2:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_OFF);
    digitalWrite(PIN_D,TURN_ON);
    digitalWrite(PIN_E,TURN_ON);
    digitalWrite(PIN_F,TURN_OFF);
    digitalWrite(PIN_G,TURN_ON);
    break;

  case 3:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_ON);
    digitalWrite(PIN_E,TURN_OFF);
    digitalWrite(PIN_F,TURN_OFF);
    digitalWrite(PIN_G,TURN_ON);
    break;

  case 4:
    digitalWrite(PIN_A,TURN_OFF);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_OFF);
    digitalWrite(PIN_E,TURN_OFF);
    digitalWrite(PIN_F,TURN_ON);
    digitalWrite(PIN_G,TURN_ON);
    break;

  case 5:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_OFF);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_ON);
    digitalWrite(PIN_E,TURN_OFF);
    digitalWrite(PIN_F,TURN_ON);
    digitalWrite(PIN_G,TURN_ON);
    break;

  case 6:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_OFF);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_ON);
    digitalWrite(PIN_E,TURN_ON);
    digitalWrite(PIN_F,TURN_ON);
    digitalWrite(PIN_G,TURN_ON);
    break;

  case 7:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_OFF);
    digitalWrite(PIN_E,TURN_OFF);
    digitalWrite(PIN_F,TURN_OFF);
    digitalWrite(PIN_G,TURN_OFF);
    break;

  case 8:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_ON);
    digitalWrite(PIN_E,TURN_ON);
    digitalWrite(PIN_F,TURN_ON);
    digitalWrite(PIN_G,TURN_ON);
    break;

  case 9:
    digitalWrite(PIN_A,TURN_ON);
    digitalWrite(PIN_B,TURN_ON);
    digitalWrite(PIN_C,TURN_ON);
    digitalWrite(PIN_D,TURN_OFF);
    digitalWrite(PIN_E,TURN_OFF);
    digitalWrite(PIN_F,TURN_ON);
    digitalWrite(PIN_G,TURN_ON);
    break;
  }

}

void showLetter(char letter)
{
  //can spell out the following (capital only) letters: A, C, D, E, e, F, G, g, H, h, I, J, L, O, o, P, S, Y (other decent candidates: R, Z)
  //will display '8' if given bad data
  
  switch (letter)
  {
    case 'A':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON);  
      break;
      
    case 'B': //actually lowercase
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON);  
      break;
      
    case 'C':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF); 
      break;
      
    case 'D': //actually lowercase
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_OFF);
      digitalWrite(PIN_G,TURN_ON);  
      break;
      
    case 'E':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'e':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'F':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'G':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF); 
      break;
      
    case 'g':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_OFF);
      digitalWrite(PIN_G,TURN_ON); 
      break;

    case 'H':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'h':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
  
   case 'I':
     show(1);
     break;
     
   case 'J':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_OFF);
      digitalWrite(PIN_G,TURN_OFF); 
      break;
      
   case 'L':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF); 
      break;
      
   case 'O':
     show(0);
     break;
     
   case 'o':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_OFF);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
   case 'P':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'R': //actually lowercase
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_OFF);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'S':
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_OFF);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
    case 'U':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF); 
      break;
      
    case 'Y':
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_ON); 
      break;
      
   default:
     show(8);
  }
}

void circle(int number) //displays a circle with a segment missing
{
  switch (number)
  {
    case 0:
      digitalWrite(PIN_A,TURN_OFF);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF);  
      break;
      
    case 1:
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_OFF);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF);  
      break;
      
    case 2:
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_OFF);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF);  
      break;

    case 3:
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_OFF);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF);  
      break;
      
     case 4:
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_OFF);
      digitalWrite(PIN_F,TURN_ON);
      digitalWrite(PIN_G,TURN_OFF);  
      break;

     case 5:
      digitalWrite(PIN_A,TURN_ON);
      digitalWrite(PIN_B,TURN_ON);
      digitalWrite(PIN_C,TURN_ON);
      digitalWrite(PIN_D,TURN_ON);
      digitalWrite(PIN_E,TURN_ON);
      digitalWrite(PIN_F,TURN_OFF);
      digitalWrite(PIN_G,TURN_OFF);  
      break;
 
   default:
     circle(0);
  }
}
