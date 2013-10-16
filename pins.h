//pins and settings for the photobooth

//  **** editable settings ****
#define SOUNDLEVEL 1 //numbers between 1 and 10 work well. Higher numbers = less sensitive to sound triggering

#define CAMERA_TRIGGER_DELAY 100 //make this larger if you're having trouble getting camera to trigger properly

#define SHOTS 4 //the number of photos per photo booth run

//pick one of the CAM settings - if both are turned on, the photo 
#define DSLR_CAM false
#define CHDK_CAM true

//turn on if using photoboop-controlled flash - turn off if the camera is controlling the flash
#define WIRED_FLASH true

// ***pin assignments - don't play with unless you know what you're doing***

//defining the segments A-G  
//A==top middle, B==top right, C==bottom right, D==bottom middle
//E==bottom left, F==top left, G == center middle
//decimal points aren't used
#define PIN_A 12 //
#define PIN_B 11 //
#define PIN_C 2 //
#define PIN_D 3 //
#define PIN_E 4 //correct
#define PIN_F 7
#define PIN_G 8

//there are generally two kinds of 7-segment displays
//common anode: turn_on == 0 turn_off == 1
//common cathode: opposite of common anode
#define TURN_ON 0
#define TURN_OFF 1

//IR LED for IR remote only cameras 
#define IR_LED 13

//PWM pins to display which photo is being taken 
#define PIN_1 9 
#define PIN_2 10 
#define PIN_3 5 
#define PIN_4 6
#define BRIGHT 255 //value between 0 and 255 for LED brightness

//RGB LED in the button is hooked up to the same PWM pins as PIN_1 through PIN_3
#define RED_PIN 9
#define GRN_PIN 10
#define BLU_PIN 5

//the button
#define BUTTON_PIN 16

//the USB camera trigger (works with CHDK enabled canon cameras, on USB pin 1)
#define USB_REMOTE 15


//speaker - must be a pin that can do analog in and PWM
#define PIEZO_PIN 14
#define FLASH 14 //for triggering FLASHES instead

//wired remote
#define WIRED_FOCUS 17
#define WIRED_SHUTTER 18

//stuff for hand wired canon point and shoots
#define POWER_TOGGLE 13 //IR LED
#define POWER_SENSE 19 //A5, should be >2V when camera is on
