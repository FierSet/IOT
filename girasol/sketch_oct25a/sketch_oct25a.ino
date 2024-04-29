#include <Servo.h> 
Servo servo_ejexy;
int LDR_der = 0, LDR_izq = 1;
int G = 90;

void setup() 
{
  Serial.begin(9600);
  pinMode(LDR_der, INPUT);
  pinMode(LDR_izq, INPUT);
  servo_ejexy.attach(3);
  
}

void loop() 
{
  //girasol();
  //palabrisas();
}

void palabrisas()
{
  servo_ejexy.write(180);
  delay(1000);
  servo_ejexy.write(0);
  delay(1000);
  /*
  for(int i = 0; i <= 180; i++)
  {
    servo_ejexy.write(i);
    delay(5);
  }

  for(int i = 180; i >= 0; i--)
  {
    servo_ejexy.write(i);
    delay(5);
  }
  */
}

void girasol()
{
  int buffer_der = analogRead(LDR_der), buffer_izq = analogRead(LDR_izq);
  /*
  Serial.print("derecho: ");
  Serial.print(buffer_der);
  Serial.print(" izquierdo: ");
  Serial.println(buffer_izq);
  */
  if ( (buffer_der < (buffer_izq - (buffer_izq*0.10))) )
    G += 2;
  else if( (buffer_izq < (buffer_der - (buffer_der*0.10))) )
    G -= 2;
    
  if (G > 180)
    G = 180;
  else if(G < 0)
    G = 0;
    
  servo_ejexy.write(G);
  
  Serial.print(G); Serial.println("°");
  //delay(5);
  
}
