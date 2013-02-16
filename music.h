#include <WProgram.h>

// defines for the frequency of the notes (.5 x freq of mid C)
#define NOTE_AN    220     // 440 Hz
#define NOTE_AS    233     // 466 Hz
#define NOTE_BN    247     // 493 Hz
#define NOTE_CN    261     // 523 Hz
#define NOTE_CS    277     // 554 Hz
#define NOTE_DN    294     // 588 Hz
#define NOTE_DS    311     // 622 Hz
#define NOTE_EN    330     // 658 Hz
#define NOTE_FN    349     // 698 Hz
#define NOTE_FS    370     // 740 Hz
#define NOTE_GN    392     // 784 Hz
#define NOTE_GS    415     // 830 Hz
// defines for the duration of the notes (in ms)
#define LEN_WH    1024 //whole note
#define LEN_H      512 //half
#define LEN_DQ     448 
#define LEN_Q      256 //quarter
#define LEN_QT     170
#define LEN_DE     192
#define LEN_E      128 //eight
#define LEN_ET      85 

void ToneOut(int pitch, int duration){  // pitch in Hz, duration in ms
  int delayPeriod;
  long cycles, i;  

 // pinMode(PIEZO_PIN, OUTPUT);           // turn on output pin
  delayPeriod = (500000 / pitch) - 7;   // calc 1/2 period in us -7 for overhead
  cycles = ((long)pitch * (long)duration) / 1000; // calc. number of cycles for loop

  for (i=0; i<= cycles; i++){           // play note for duration ms
    digitalWrite(PIEZO_PIN, HIGH);
    delayMicroseconds(delayPeriod);
    digitalWrite(PIEZO_PIN, LOW);
    delayMicroseconds(delayPeriod - 1); // - 1 to make up for digitaWrite overhead
  }
 // pinMode(PIEZO_PIN, INPUT);            // shut off pin to avoid noise from other operations
} 


void PlayNote(int note, int duration)
{
  int pitch = 0;
  
  switch (note)
  {
    case 1:
      pitch = NOTE_AN;
      break;
    case 2:
      pitch = NOTE_BN;
      break;
    case 3:
      pitch = NOTE_CN;
      break;
    case 4:
      pitch = NOTE_DN;
      break;
    case 5:
      pitch = NOTE_EN;
      break;
    case 6:
      pitch = NOTE_FN;
      break;
    case 7:
      pitch = NOTE_GN;
      break;
      default:
      pitch = NOTE_GN;
  }
  
  ToneOut(pitch, duration);
}



