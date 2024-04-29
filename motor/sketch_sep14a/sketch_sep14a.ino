int polo1 = 9, polo2 = 10, BOTTON = 8;
bool estado = true;

void setup() {
  pinMode(polo1, OUTPUT);  
  pinMode(polo2, OUTPUT); 
  pinMode(BOTTON, INPUT);
}

void loop() 
{

  if(digitalRead(BOTTON) == 1)
  { 
    estado = !estado;   
    delay(500); 
  }
  
  if (estado)
  {
    digitalWrite(polo1, HIGH);
    digitalWrite(polo2, LOW);
  }
  else
  {
    digitalWrite(polo1, LOW);
    digitalWrite(polo2, HIGH);
  }

  

  
   //
}
