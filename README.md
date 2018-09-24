# SistemasProgramables

# Tecnológico Nacional de México

# Instituto Tecnológico de León

Carrera: Ingeniería en Sistemas computacionales

Alumno: Juan Silvestre Ramírez Becerra.

Materia: Sistemas Programables

Profesor: Carlos Rafael Levy Rojas

León, Guanajuato 23 de Septiembre de 2018

# Sistema-Notificador-de-Llegada-de-Individuos

# Descripción de la práctica:

Una alarma con arduino para el acceso a una puerta. Cuando la puerta se abre, la alarma debe sonar.

Requisito indispensable:
Reducir el consumo de energía al mínimo. Mientras la alarma no esté sonando el arduino deberá consumir la mínima cantidad de energía.
Cuando la puerta se cierre esta deberá de dejar de sonar y regresar al estado de bajo consumo energético.

# Entorno de desarrollo de practica
Se utilizo un Sistema opertaivo Ubuntu 16.05 LTS y ID Arduino para el desarrollo de la practica, tambien se empleo un repositorio git para luego subirlo a github
# Materiales usados

-Arduino UNO 
-Cable USB 
-Placa de prototipado o protoboard 
-12 cables o jumpers 
-2 Diodos Led (Rojo,Azul) 
-2 Resistencias de 220Ω y 10KΩ
-Potenciometro de 10kΩ 
-Reed Switch
-Buzzer

# Objetivo

Lograr un sistema de alarma que simule una puerta que al abrirla se escuche una alarma que avise el estado de su cambio

# Descripcion de la solucion Circuito Fisico

* Se utilizo una placa arduino uno, en la cual se coloco el buzzer en el pin 11 como salida digital, esa salida se conecto a el lado 
 positivo del buzzer y el lado negativo a GND
* Se conecto un potenciometro el cual su salida va a el pin A0 de las entradas analogicas de la placa arduino y respectivamente se
 dio corriente de 5v y GND
* Se conecto una salida del pin 12 a un par de leds conectados en serie conectados hacia una resistencia de 220Ω que esta esta hacia GND
* Se utilizo un red switch conectado con en forma de un PULL UP con una resistencia de 10kΩ, la señal de 0 y 1 es recibida por
 el pin 3 ya que este en la placa de arduino uno puede manejar interrupciones

# Descripcion de la solucion Codigo IDE Arduino(pseudocodigo)

Tomando en cuenta la descripcion de la practica se necesita tener un ahorro de energia
ya que esto es muy importante en proyectos que sean mas grandes; Inlui una libreria(<avr/sleep.h>) para usar
un metodo para dormir el arduino(set_sleep_mode()) y evitar el consumo de este mismo al no necesitar todo el tiempo 
su ejecucion del codigo.
Se definio el buzzer para el pin 11, el reed switch para el pin 3 que disparara una interrupcion que en este proyecto 
representa a una persona que  abre nuestra puerta;
Se añadio algo extra un led en el pin 12 que funciona solo como advertencia de que la puerta se abrio y 
un potenciometro, que esta conectado a el pin A0 de las entradas analogicas, el cual es usado para establecer un volumen 
para el buzzer  dentro de un rango de valores,este funciona como nuestra alarma,hay una variable entera que se utilizara para 
guardar esos valores que nos dara el potenciometro, se declara una variable volatil ya que se utilizara en la ISR,
es necesario que sea volatil, ese sera nuestro estado de la puerta utilizado en la interrupcion.

Definiendo esto, en el "set up" establecemos la funcion de cada pin, el buzzer sera una salida, el led sera una salida,
ahi mismo definimos una interrupcion que recibe tres parametro, la interrupcion que en este caso es que la puerta a sido
irrumpida que es representada con el reed switch sera una entrada de control, el nombre de la interrupcion(metodo)
y el modo de disparo que en este caso es RISING ya que cambia de 0 logico a 1 logico, ahi se puso un Serial.begin(9600)
para monitoriar los valores obtenidos del potenciometro que mas adelante sera utilizado en nuestro buzzer.
Se utilizo una funcion de la libreria <avr/sleep.h>, la cual es set_sleep_mode() para poner a dormir el arduino
este metodo esta sobrecargado y recibe diferentes parametros, entre esos se escojio SLEEP_MODE_PWR_DOWN
que se supone es el que te da un mayor ahorro de energia en la ejecucion.

En el metodo interrupcion() solo niego el valor de mi variable volatil, el "estadoPuerta" que tengo, este cambia de 0(cerrado)
a 1(abierto) indicando que la puerta ha sido abierta.

En mi loop monitero el valor actual de mi potenciometro que utilizando una
funcion map() la cual obtiene un rango de valores utiles para luego asignarlo a mi variable
volumen ademas tengo una sentencia condicional en la cual si mi estado de la puerta es 0(cerrado) simplemente inicializo 
el modo bajo de consumo, ponemos el modo bajo de consumo y apagamos nuestros leds que avisan si la puerta se abrio, en cambio si 
mi estado de puerta es 1(abierto) desactivamos el modo dormir(despertamos al arduino) y ejecutamos muestro metodo
alarma el cual recibe el estado de la puerta, ahi hacemos que mediante una escritura analogica
el buzzer que funge como alarma empiece a sonar, ahi utilizamos el volumen que produjo el potencimetro que dara valor 
al buzzer que hara aumentar o disminuir en un rango el sonido emitido.

Si la entrada cambia a 0(cerrado), en el loop el arduino entrara a dormir y se ahorrara la energia por ende
todos los procesos paran hasta que de nuevo la interrupcion cambie el "estadoPuerta" a 1(abierto)  y se repita el ciclo. 




