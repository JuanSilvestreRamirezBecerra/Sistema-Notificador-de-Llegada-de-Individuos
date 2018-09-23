#define buzzer 11
#define puerta 8

void setup() 
{
  pinMode(buzzer, OUTPUT);
}

void loop() 
{
  
  if(digitalRead(puerta)==LOW){
    }
  else
  {
    alarma();
  }

}

void alarma()
{
  
    for(int x=0;x<7;x++)
    {
      
      analogWrite(buzzer,128); //emite sonido
      delay(200); //espera
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(200);//espera 
    }
  for(int z=0;z<5;z++)
    {
      analogWrite(buzzer,128); //emite sonido
      delay(100); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera 
      
      analogWrite(buzzer,128); //emite sonido
      delay(100); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera 
     
      analogWrite(buzzer,128); //emite sonido
      delay(100); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera 
     
      analogWrite(buzzer,128); //emite sonido
      delay(100); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera 
     
      analogWrite(buzzer,128); //emite sonido
      delay(100); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera 
     
      analogWrite(buzzer,128); //emite sonido
      delay(100); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera 
     
      analogWrite(buzzer,128); //emite sonido
      delay(300); //espera 
      digitalWrite(buzzer, LOW); //deja de emitir
      delay(100);//espera
    }
}
