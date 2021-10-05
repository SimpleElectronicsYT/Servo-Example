/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob

 bastardized by Simple Electronics (www.youtube.com/simpleelectronics)
 on October 4th, 2021
 
*/
#include <Wire.h>                       // needed for i2c function
#include <LiquidCrystal_I2C.h>          // i2c LCD library
#include <Servo.h>                      // wonderful servo library

LiquidCrystal_I2C lcd(0x27,16,2);       // set the LCD address to 0x27 for a 16 chars and 2 line display

Servo myservo;                          // create servo object to control a servo

int potpin = 8;                         // analog pin used to connect the potentiometer
int val;                                // variable to read the value from the analog pin

void setup() {
  myservo.attach(3);                    // attaches the servo on pin 9 to the servo object
  lcd.init();                           // initialize the LCD
  lcd.backlight();                      // turn on the backlight
  lcd.setCursor(0, 0);                  // set the cursor to position 0 horizontal and 0 vertical
  lcd.print("Servo angle: ");           // put some words on the LCD to contextualize the number
}

void loop() {
  val = analogRead(potpin);             // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 180, 0);      // scale it to use it with the servo (value between 0 and 180)
  lcd.setCursor(13, 0);                 // set the cursor right after our text
  lcd.print("   ");                     // write over the old number with spaces (erases specific characters)
  lcd.setCursor(13, 0);                 // set the cursor to right after our context text
  lcd.print(val);                       // print out the angle value of the servo
  myservo.write(val);                   // sets the servo position according to the scaled value

  delay(15);                            // waits for the servo to get there; gives time to stabilize

}
