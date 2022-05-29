// Include LCD display library for I2C
#include <LiquidCrystal_I2C.h>
// Include Ultrasonic Sensor library for Distance
#include <NewPing.h>

// Create NewPing object : (Trig, Echo, MaxDistance)
NewPing sonar(10, 11, 400);     

// Create LCD object : Use 0x27 If 0x3F Doesn't work
LiquidCrystal_I2C lcd(0x3F, 16, 2); 

// Pin connected to Push-Button
int buttonPin = 2;

void setup() {
  // Setup LCD with backlight and initialize
  lcd.backlight();
  lcd.init();
  lcd.clear();

  // Set buttonPin as an INPUT_PULLUP pin
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == 0){
    int distance = sonar.ping_cm();
    if(distance == 0){
      lcd.clear();
      lcd.print("Wrong Distance");
    }else{
      lcd.clear();
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print(" cm");
    }
  }
}
