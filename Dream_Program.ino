#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

MMA8452Q accel;

int led = 3;

int p = 0;

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void setup() {
  // Debugging output
  Serial.begin(9600);

  accel.init();
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  // Print a message to the LCD. We track how long it takes since
  // this library has been optimized a bit and we're proud of it :)
  //int time = millis();
  //Serial.print("test");
  //lcd.print("Hello, world!");
  //time = millis() - time;
  //Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  
  lcd.print("Welcome to Luci");
  delay(2000);
  lcd.clear();
  lcd.print("Press SELECT");
  lcd.setCursor(0,1);
  lcd.print("to continue");

 

  lcd.setBacklight(WHITE);
}

uint8_t i=0;

void loop() {
  lcd.setCursor(0, 1);
  //lcd.print(millis()/1000);
  lcd.setCursor(16,1);
  // set the display to automatically scroll:
//  lcd.autoscroll();
//  // print from 0 to 9:
//  for (int thisChar = 0; thisChar < 10; thisChar++) {
//    lcd.print(thisChar);
//    delay(500);
//  }
//  // turn off automatic scrolling
//  lcd.noAutoscroll();

  uint8_t buttons = lcd.readButtons();

  //button conditionals
  if (buttons){
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_SELECT) {
      
      lcd.setCursor(0,0);
      lcd.print("Luci is");
      lcd.setCursor(0,1);
      lcd.print("a Lucid");
      
      delay(1500);
      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Dreaming");
      lcd.setCursor(0,1); 
      lcd.print("Assitant");

      delay(2000);
      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Press UP to");
      lcd.setCursor(0,1); 
      lcd.print("Begin Program");
      
//      lcd.setBacklight(RED);
//      delay(2500);
//      lcd.clear();

    }
  }
  if (buttons){
    if (buttons & BUTTON_UP) { 
      dreamProgram();
    }
  }

  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();
    
    // accel.read() will update two sets of variables. 
    // * int's x, y, and z will store the signed 12-bit values 
    //   read out of the accelerometer.
    // * floats cx, cy, and cz will store the calculated 
    //   acceleration from those 12-bit values. These variables 
    //   are in units of g's.
    // Check the two function declarations below for an example
    // of how to use these variables.
    printCalculatedAccels();
    //printAccels(); // Uncomment to print digital readings
    
    // The library also supports the portrait/landscape detection
    //  of the MMA8452Q. Check out this function declaration for
    //  an example of how to use that.
    printOrientation();
    //delay(150);
    Serial.println(); // Print new line every time.
  }

  if(p==1){
    delay(10000);
    for(int k = 0; k < 5; k++){
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }
}

void dreamProgram() {
  uint8_t buttons = lcd.readButtons();
  
  lcd.setCursor(0,0);
  lcd.print("Dream Program");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Your Light");
  lcd.setCursor(0,1);
  lcd.print("Sequence is set");
  
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Please lie down");
  
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Place the sensor");
  lcd.setCursor(0,1);
  lcd.print("on your bed");

  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("and put on");
  lcd.setCursor(0,1);
  lcd.print("the sleep mask");

  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Now tracking");
  lcd.setCursor(0,1);
  lcd.print("your sleep...");

  p = 1;
  
//  if(p==1);{
//    digitalWrite(led, HIGH); 
//    delay(100);
//    digitalWrite(led, LOW);
//    delay(100);
//    digitalWrite(led, HIGH); 
//    delay(100);
//    digitalWrite(led, LOW);
//    delay(100);
//    digitalWrite(led, HIGH); 
//    delay(100);
//    digitalWrite(led, LOW);
//    delay(100);
//    digitalWrite(led, HIGH); 
//    delay(100);
//    digitalWrite(led, LOW);
//  }



//  delay(10000);
//  for(int j = 0; j<5; j++){
//    digitalWrite(led, HIGH); 
//    delay(100);
//    digitalWrite(led, LOW);
//  }
  //digitalWrite(led, LOW);

  

//  lcd.setCursor(0,0);
//  lcd.print("Press RIGHT");
//  lcd.setCursor(0,1);
//  lcd.print("To continue");
//
//  delay(2000);
//  lcd.clear();
//
//  lcd.setCursor(0,0);
//  lcd.print("Or press LEFT");
//  lcd.setCursor(0,1);
//  lcd.print("To Change things");


//  if(buttons){
//    if(buttons & BUTTON_RIGHT){
//      lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print("right");
//    }
//  }
}

void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.cx, accel.cy,
//  and accel.cz variables.
// Before using these variables you must call the accel.read()
//  function!
void printCalculatedAccels()
{ 
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.readPL()
// function, which reads the portrait/landscape status of the
// sensor.
void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
