#include <Wire.h>
#include "Adafruit_DRV2605.h"

/* This is the I2C address of the multiplexor */
#define TCAADDR 0x70

/* Struct that defines a vibrotactile motor and pairs it to an 
SCX/SDX output on the Multiplexor */
struct Motor {
   Adafruit_DRV2605  vib;
   uint8_t   tca_id;
}; 

/* Assign unique motor objects to represent the 4 vibrotactile motors
 connected to the device */
struct Motor motor_top_left;

struct Motor motor_top_right;

struct Motor motor_bottom_left;

struct Motor motor_bottom_right;


/* Trigger a provided effect on the specified Motor */
void playVibration(Motor motor, int effect) {

  // Select the output on the multiplexor
  tcaselect(motor.tca_id);

  /* This delay is optional
     It is included in order to pad the output select
     on the multiplexor so as to prevent dropping the signal
     it is purely precautionary.
  */
  delay(500);
  
  // Set the effect to be played
  motor.vib.setWaveform(0, effect);
  motor.vib.setWaveform(1, 0);

  // play the effect
  motor.vib.go();

}

/* 
  Send a bit to the multiplexor in order to select the provided output.
  (The multiplexor switches its output based on the last bit sent to it's I2C address.)
  Retrieved from: 
  https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout/overview
*/
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

/* Primary setup function for arduino, which is run at the beginning of execution */
void setup(void) 
{
  // Initiate I2C protocol as master
  Wire.begin();


  // Stage tca address 7 on Multiplexor
  tcaselect(7);
  // Assign tca address of 7 to the top left motor
  motor_top_left.tca_id = 7;
  // Initialize top left motor
  motor_top_left.vib.begin();
  motor_top_left.vib.selectLibrary(1);
  motor_top_left.vib.setMode(DRV2605_MODE_INTTRIG); 

  // Stage tca address 1 on Multiplexor
  tcaselect(1);
  // Assign tca address of 1 to the top left motor
  motor_top_right.tca_id = 1;
  // Initialize top right motor
  motor_top_right.vib.begin();
  motor_top_right.vib.selectLibrary(1);
  motor_top_right.vib.setMode(DRV2605_MODE_INTTRIG); 

  // Stage tca address 3 on Multiplexor
  tcaselect(3);
  // Assign tca address of 3 to the top left motor
  motor_bottom_left.tca_id = 3;
  // Initialize bottom left motor
  motor_bottom_left.vib.begin();
  motor_bottom_left.vib.selectLibrary(1);
  motor_bottom_left.vib.setMode(DRV2605_MODE_INTTRIG); 

  // Stage tca address 2 on Multiplexor
  tcaselect(2);
  // Assign tca address of 2 to the top left motor
  motor_bottom_right.tca_id = 2;
  // Initialize bottom right motor
  motor_bottom_right.vib.begin();
  motor_bottom_right.vib.selectLibrary(1);
  motor_bottom_right.vib.setMode(DRV2605_MODE_INTTRIG); 

  // Initialize I2C Serial connection at baud rate of 57600
  // Note: 57600 is picked arbitratily at the time of development
  // It is necessary that the monitoring application also communicate
  // at this baud rate in order to pass messages across successfully.
  Serial.begin(57600);
  Serial.println("Setup Complete");

}

/* Main run loop that runs continuously during execution. */
void loop(void) 
{
  while (Serial.available() > 0) { // if any data is available
    char incomingByte = Serial.read(); // read byte

    // Monitoring application will communicate by transmitting 1 byte
    // In the range of 0-F, each representing a colour from the colour dictionary
    switch(incomingByte) {
        case '0':
          Serial.println("teal");
          playVibration(motor_top_left, 47);
          playVibration(motor_top_left, 47);
          break;
        case '1':
          Serial.println("blue");      
          playVibration(motor_top_left, 48);
          playVibration(motor_top_left, 48);
          break;

        case '2':
          Serial.println("green");
          playVibration(motor_top_left, 49);
          playVibration(motor_top_left, 49);
          break;

       case '3':
        Serial.println("yellowgreen");
          playVibration(motor_top_left, 50);
          playVibration(motor_top_left, 50);
          break;

       case '4':
        Serial.println("red");
          playVibration(motor_top_right, 47);
          playVibration(motor_top_right, 47);
          break;

       case '5':
        Serial.println("purple");
          playVibration(motor_top_right, 48);
          playVibration(motor_top_right, 48);
          break;

       case '6':
        Serial.println("magenta");
          playVibration(motor_top_right, 49);
          playVibration(motor_top_right, 49);
          break;

       case '7':
        Serial.println("pink");
          playVibration(motor_top_right, 50);
          playVibration(motor_top_right, 50);
          break;

       case '8':
        Serial.println("brown");
          playVibration(motor_bottom_right, 47);
          playVibration(motor_bottom_right, 47);
          break;

       case '9':
        Serial.println("orange");
          playVibration(motor_bottom_right, 48);
          playVibration(motor_bottom_right, 48);
          break;

       case 'a':
        Serial.println("yellow");
          playVibration(motor_bottom_right, 49);
          playVibration(motor_bottom_right, 49);
          break;

       case 'b':
        Serial.println("tan");
          playVibration(motor_bottom_right, 50);
          playVibration(motor_bottom_right, 50);
          break;

       case 'c':
         Serial.println("black");
          playVibration(motor_bottom_left, 47);
          playVibration(motor_bottom_left, 47);
          break;

       case 'd':
          Serial.println("grey");
          playVibration(motor_bottom_left, 48);
          playVibration(motor_bottom_left, 48);
          break;

       case 'e':
        Serial.println("beige");
          playVibration(motor_bottom_left, 49);
          playVibration(motor_bottom_left, 49);
          break;

       case 'f':
        Serial.println("white");
          playVibration(motor_bottom_left, 50);
          playVibration(motor_bottom_left, 50);
          break;
    }
    
    Serial.println(incomingByte); // send byte back for diagnostic purposes
  }
  
}
