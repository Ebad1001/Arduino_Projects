#include <LiquidCrystal.h>

// const int GND;   // connect it to GND
// const int VDD;   // connect it to 5V
const int VO = 6;   // connect it to a PWM to adjust contrast (here 6, optimal value = 150/255)
const int RS = 12;  // connect it to a digital pin (here 12)
// const int RW;    // connect it to a GND (Low for Write)
const int EN = 11;  // connect it to a digital pin (here 11)
// const int D0;
// const int D1;    // These pins are not used //
// const int D2;    // in 4-pin mode           //
// const int D3;
const int D4 = 5;   // connect it to a digital pin (here 12)
const int D5 = 4;   // connect it to a digital pin (here 12)
const int D6 = 3;   // connect it to a digital pin (here 12)
const int D7 = 2;   // connect it to a digital pin (here 12)
// const int BLA;   // connect it to 5V
// const int BLK;   // connect it to GND

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);                    // syntax for 4-pin mode (recommended)
// LiquidCrystal lcd(RS, EN, D0, D1, D2, D3, D4, D5, D6, D7); // syntax for 8-pin mode

void setup()
{
  // adjust contrast
  pinMode(VO, OUTPUT);
  analogWrite(VO, 150); 

  // initialize the lcd with width and height
  lcd.begin(16, 2); 

  // Set cursor to first line
  lcd.setCursor(0, 0);
  // print a string literal
  lcd.print("Hello, World!");

  // Set cursor to second line
  lcd.setCursor(0, 1);
  // print a variable value
  char myName[] = "Ebad";
  lcd.print(myName);
  int myNumber = 1001;
  lcd.print(myNumber);

  delay(2000);
}

int temp = 30;

void loop()
{
  // clear the display and set the cursor to the top left corner
  lcd.clear();
  lcd.print("temp: ");
  lcd.print(temp);
  lcd.print(" C");
  
  delay(2500);
  temp += random(-3, 4);
}

/*
  Advantages of 4-Bit Mode: (Recommended)
  1. Pin Conservation: This leaves more pins available for sensors, buttons, and other components
  2. Adequate Performance: The speed difference is negligible for most applications
  3. Hardware Simplicity: Fewer connections reduce wiring complexity and Less chance of connection errors
  4. Power Efficiency: Fewer active pins means slightly lower power consumption

  Advantages of 8-Bit Mode:
  1. Faster data transfer: Each byte is sent in one operation instead of two
  2. Simpler timing: No need to split bytes into nibbles (8bits to 4bits)
  3. Better for high-frequency updates: When rapidly updating display content
  4. Simpler code: The LiquidCrystal library handles the 4-bit complexity automatically
*/