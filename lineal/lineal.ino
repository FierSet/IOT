
int LED[10];
int cantidad_leds;
float resV, sinval;
int intencidad = 5, ledval;
void setup() 
{
  //Serial.begin(9600);
  pinMode(intencidad, OUTPUT);
  /*
   * //array de leds
  cantidad_leds = (sizeof(LED) / sizeof(int));
  
  for(int i = 0; i < cantidad_leds; i++)
  {
      LED[i] = i + 4;
      pinMode(LED[i], OUTPUT);
  }
  */
}

void leds()
{
  for(int i = 0; i < cantidad_leds; i++)
  {
     resV = analogRead(A0);
     //Serial.print("Delay: "); Serial.println(resV);
     digitalWrite(LED[i], HIGH); 
     delay(resV);
     digitalWrite(LED[i], LOW);
  }
  for(int i = cantidad_leds; i >= 0; i--)
  {
     resV = analogRead(A0);
     digitalWrite(LED[i], HIGH);
     //Serial.print("Delay: "); Serial.println(resV);
     delay(resV);
     digitalWrite(LED[i], LOW);
  }
}

void ondas()
{
  for(int i = 0; i <= 10; i++)
  {
    resV = analogRead(A0);
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[10 -  i], HIGH);
    
    delay(resV);
    
    digitalWrite(LED[i], LOW);
    digitalWrite(LED[10 -  i], LOW);
  }
}

void pelota()
{
  int revote = 10;
  
  while(revote > 0)
  {
    for(int i = 0; i < revote; i++)
    {
      resV = analogRead(A0);
      digitalWrite(LED[i], HIGH);
      delay(resV);
      digitalWrite(LED[i], LOW);
    }
   
    for(int i = revote; i > 0; i--)
    {
      resV = analogRead(A0);
      digitalWrite(LED[i], HIGH);
      delay(resV);
      digitalWrite(LED[i], LOW);
    }
    revote--;
  }
}

void intencida()
{
  for(int x = 0; x < 180; x++)
  {
    sinval = (sin(x*(3.1412/18)));
    ledval = int(sinval*255);
    analogWrite(intencidad, ledval);
    delay(25);
  }
}

void loop() 
{
  //leds();
  //ondas();
  //pelota();
  intencida();
}
