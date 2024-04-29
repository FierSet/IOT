#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // create an lcd object and assign the pins
int maxC=0, minC=100, maxF=0, minF=212;
int scale = 1;
int buttonPin=8;

void setup() {
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  // analogReference(INTERNAL1V1); If you have an Arduino Mega
  pinMode(buttonPin, INPUT);
  lcd.clear();
}

void loop() {
  practica_23();
  //sensor();//24
}

void sensor()
{
  lcd.setCursor(0,0); // set cursor to home position
  int sensor = analogRead(0); // read the temp from sensor
  int buttonState = digitalRead(buttonPin); // check for button press
  switch (buttonState) { // change scale state if pressed
  case HIGH:
  scale=-scale; // invert scale
  lcd.clear();
}
  switch (scale) { // decide if C or F scale
  case 1:
  celsius(sensor);
  break;
  case -1:
  fahrenheit(sensor);
  }
  delay(250);
}

void celsius(int sensor) {
lcd.setCursor(0,0);
int temp = (sensor * 5 * 100 / 1024); // convert to C
lcd.print(temp);
lcd.write(B11011111);
lcd.print("C ");
if (temp>maxC) {maxC=temp;}
if (temp<minC) {minC=temp;}
lcd.setCursor(0,1);
lcd.print("H=");
lcd.print(maxC);
lcd.write(B11011111);
lcd.print("C L=");
lcd.print(minC);
lcd.write(B11011111);
lcd.print("C ");
}

void fahrenheit(int sensor) {
lcd.setCursor(0,0);
float temp = ((sensor * 0.1074188) * 1.8)+32; // convert to F
lcd.print(int(temp));
lcd.write(B11011111); // print degree symbol
lcd.print("F ");
if (temp>maxF) {maxF=temp;}
if (temp<minF) {minF=temp;}
lcd.setCursor(0,1);
lcd.print("H=");
lcd.print(maxF);
lcd.write(B11011111);
lcd.print("F L=");
lcd.print(minF);
lcd.write(B11011111);
lcd.print("F ");
}

void practica_23()
{
  // run the 7 demo routines
  basicPrintDemo();
  displayOnOffDemo();
  setCursorDemo();
  scrollLeftDemo();
  scrollRightDemo();
  cursorDemo();
  createGlyphDemo();
}

void basicPrintDemo() {
lcd.clear(); // Clear the display
lcd.print("Basic Print"); // print some text
delay(2000);
}

void displayOnOffDemo() {
lcd.clear(); // Clear the display
lcd.print("Display On/Off"); // print some text
for(int x=0; x < 3; x++) { // loop 3 times
lcd.noDisplay(); // turn display off
delay(1000);
lcd.display(); // turn it back on again
delay(1000);
}
}

void setCursorDemo() {
lcd.clear(); // Clear the display
lcd.print("SetCursor Demo"); // print some text
delay(1000);
lcd.clear(); // Clear the display
lcd.setCursor(5,0); // cursor at column 5 row 0
lcd.print("5,0");
delay(2000);
lcd.setCursor(10,1); // cursor at column 10 row 1
lcd.print("10,1");
delay(2000);
lcd.setCursor(3,1); // cursor at column 3 row 1
lcd.print("3,1");
delay(2000);
}
void scrollLeftDemo() {
lcd.clear(); // Clear the display
lcd.print("Scroll Left Demo");
delay(1000);
lcd.clear(); // Clear the display
lcd.setCursor(7,0);
lcd.print("Beginning");
lcd.setCursor(9,1);
lcd.print("Arduino");
delay(1000);
for(int x=0; x<16; x++) {
lcd.scrollDisplayLeft(); // scroll display left 16 times
delay(250);
}
}
void scrollRightDemo() {
lcd.clear(); // Clear the display
lcd.print("Scroll Right");
lcd.setCursor(0,1);
lcd.print("Demo");
delay(1000);
lcd.clear(); // Clear the display
lcd.print("Beginning");
lcd.setCursor(0,1);
lcd.print("Arduino");
delay(1000);
for(int x=0; x<16; x++) {
lcd.scrollDisplayRight(); // scroll display right 16 times
delay(250);
}
}

void cursorDemo() {
lcd.clear(); // Clear the display
lcd.cursor(); // Enable cursor visible
lcd.print("Cursor On");
delay(3000);
lcd.clear(); // Clear the display
lcd.noCursor(); // cursor invisible
lcd.print("Cursor Off");
delay(3000);
lcd.clear(); // Clear the display
lcd.cursor(); // cursor visible
lcd.blink(); // cursor blinking
lcd.print("Cursor Blink On");
delay(3000);
lcd.noCursor(); // cursor invisible
lcd.noBlink(); // blink off
}
void createGlyphDemo() {
lcd.clear();
byte happy[8] = { // create byte array with happy face
B00000,
B00000,
B10001,
B00000,
B10001,
B01110,
B00000,
B00000};
byte sad[8] = { // create byte array with sad face
B00000,
B00000,
B10001,
B00000,
B01110,
B10001,
B00000,
B00000};
lcd.createChar(0, happy); // create custom character 0
lcd.createChar(1, sad); // create custom character 1
for(int x=0; x<5; x++) { // loop animation 5 times
lcd.setCursor(8,0);
lcd.write((byte)0); // write custom char 0
delay(1000);
lcd.setCursor(8,0);
lcd.write(1); // write custom char 1
delay(1000);
}
}
