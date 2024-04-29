#include <Servo.h> 
Servo servol;

void setup() 
{
  servol.attach(9);
  Serial.begin(9600);
}

void loop() 
{
  
    servol.write(180);
    //siczac();
    
}

void siczac()
{
  servol.write(0);
  delay(1000);
  servol.write(180);
  delay(1000);
}
