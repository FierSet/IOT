char buffer[18];
int ledPin1 = 3;
int ledPin2 = 5;
int ledPin3 = 6;

int sinval;
float RGB1[3];
float RGB2[3];
float INC[3];
char valorteclado;
int red, green, blue;
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(Serial.available())
  Serial.read();
  randomSeed(analogRead(0));
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;

  RGB2[0] = random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);
  
}

void aleatorio()
{
  randomSeed(analogRead(0));
  for (int x=0; x<3; x++) {
  INC[x] = (RGB1[x] - RGB2[x]) / 256; }
  for (int x=0; x<256; x++) {
  red = int(RGB1[0]);
  green = int(RGB1[1]);
  blue = int(RGB1[2]);
  analogWrite (RedPin, red);
  analogWrite (GreenPin, green);
  analogWrite (BluePin, blue);
  delay(100);
  RGB1[0] -= INC[0];
  RGB1[1] -= INC[1];
  RGB1[2] -= INC[2];
  }
  for (int x=0; x<3; x++) {
  RGB2[x] = random(556)-300;
  RGB2[x] = constrain(RGB2[x], 0, 255);
  delay(1000);
  }
}

void teclado()
{
  if (Serial.available() > 0) {
int index=0;
delay(100); // let the buffer fill up
int numChar = Serial.available();
if (numChar>15) {
numChar=15;
}
  
  while (numChar--) {
buffer[index++] = Serial.read();
}
splitString(buffer);
}
}

void splitString(char* data) {
Serial.print("Data entered: ");
Serial.println(data);
char* parameter;
parameter = strtok (data, " ,"); // Note that this is a space before the comma in " , "
while (parameter != NULL) {
setLED(parameter);
parameter = strtok (NULL, " ,"); // space before the comma in " , "
}
// Clear the text and serial buffers
for (int x=0; x<16; x++) {
buffer[x]='\0';
}
while(Serial.available())
Serial.read();}
void setLED(char* data) {
if ((data[0] == 'r') || (data[0] == 'R')) {
int Ans = strtol(data+1, NULL, 10);
Ans = constrain(Ans,0,255);
analogWrite(RedPin, Ans);
Serial.print("Red is set to: ");
Serial.println(Ans);
}
if ((data[0] == 'g') || (data[0] == 'G')) {
int Ans = strtol(data+1, NULL, 10);
Ans = constrain(Ans,0,255);
analogWrite(GreenPin, Ans);
Serial.print("Green is set to: ");
Serial.println(Ans);
}
if ((data[0] == 'b') || (data[0] == 'B')) {
int Ans = strtol(data+1, NULL, 10);
Ans = constrain(Ans,0,255);
analogWrite(BluePin, Ans);
Serial.print("Blue is set to: ");
Serial.println(Ans);
}
}

void fuego()
{
  analogWrite(ledPin1, random(120)+135);
  analogWrite(ledPin2, random(120)+135);
  analogWrite(ledPin3, random(120)+135);
  delay(random(100));
}
void loop() {
  //fuego();
  //aleatorio();
  teclado();
}
