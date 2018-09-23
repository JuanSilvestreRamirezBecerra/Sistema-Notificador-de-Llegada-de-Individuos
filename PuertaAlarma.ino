#include <avr/sleep.h>
#define buzzer 11//pin donde esta la salida para el buzzer
#define puerta 3//pin que recibe la señal de la entrada
#define led 12//Luz para ver modoSleep

volatile int estadoPuerta = LOW;//El estado de la puerta es cerrado

void setup()
{
  pinMode(buzzer, OUTPUT);//Se define el buzzer como pin de salida
  pinMode(led,OUTPUT);//Se define el led con un pin de salida
  pinMode(puerta, INPUT); //Se define el pin puerta como entrada
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Establecemos el modo de bajo consumo.
  attachInterrupt(digitalPinToInterrupt(puerta), interrupcion, RISING); //Se crea una interrupcion con el pin puerta
  Serial.begin(9600);
}

void loop()
{
  if(estadoPuerta==LOW){
     digitalWrite(led,LOW);//Apaga el led con la alarma
     sleep_enable();//inicializamos el modo bajo consumo
     sleep_mode();//ponemos el modo bajo consumo.

  }else{
     sleep_disable();//desactivamos el modo bajo consumo
     digitalWrite(led,HIGH);//enciende el led con la alrma
     alarma(estadoPuerta);//Manda el estado de la puerta a la alarma
  }
   
  
 
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
