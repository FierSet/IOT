
int verde = 8;
int amarillo = 9;
int rojo = 10;
int boton = 13;
int transe = 12;
int transen = 11;

void setup() 
{
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(transe, OUTPUT);
  pinMode(transen, OUTPUT);
  pinMode(boton, INPUT);

}

void semaforo()
{
  for(int i = 0; i <= 3; i++)
  {
    digitalWrite(verde, HIGH);
    delay(500);
    digitalWrite(verde, LOW);
    delay(500);
  }
  //digitalWrite(verde, LOW);
  delay(200);
  digitalWrite(amarillo, HIGH);
  delay(2000);
  digitalWrite(amarillo, LOW);
  delay(500);
  digitalWrite(rojo, HIGH);
  digitalWrite(transe, HIGH);
  digitalWrite(transen, LOW);
  delay(3000);
  for(int i = 0; i <= 3; i++)
  {
    digitalWrite(transe, HIGH);
    delay(500);
    digitalWrite(transe, LOW);
    delay(500);
  }
  digitalWrite(rojo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(transen, HIGH);
  delay(3000);
}

void loop() 
{
  if(digitalRead(boton) == LOW)
    semaforo();
  else
  {
    digitalWrite(verde, HIGH);
    digitalWrite(transen, HIGH);
  }
}
