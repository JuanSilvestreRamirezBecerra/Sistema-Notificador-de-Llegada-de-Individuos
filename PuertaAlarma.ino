#define buzzer 11//pin donde esta la salida para el buzzer
#define puerta 3//pin que recibe la señal de la entrada

volatile int estadoPuerta = LOW;//El estado de la puerta es cerrado

void setup()
{
  pinMode(buzzer, OUTPUT);//Se define el buzzer como pin de salida
  pinMode(puerta, INPUT); //Se define el pin puerta como entrada
  attachInterrupt(digitalPinToInterrupt(puerta), interrupcion, RISING); //Se crea una interrupcion con el pin puerta
}

void loop()
{
  
  alarma(estadoPuerta);//Manda el estado de la puerta a la alarma
}

void interrupcion() {
  estadoPuerta = !estadoPuerta;//Si se irrumpe la puerta, hay un cambio de estado de cerrado a abierto y viceversa
}

void alarma(int estado)
{
  if (estadoPuerta == LOW) {//Si el estado de la puerta es cerrado no pasa nada
  } else {//Si el estado de la puerta es abierto suena la alarma de seguridad
    analogWrite(buzzer, 500); //emite sonido
    delay(200); //espera
    digitalWrite(buzzer, LOW); //deja de emitir
    delay(100);//espera
  }
}
