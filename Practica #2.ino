#include <LiquidCrystal_I2C.h> //incluye la libreria LiquidCrystal_I2C
LiquidCrystal_I2C lcd_1(0x27,16,2); //pone los parametros para la LCD

#include <Servo.h> //incluye la libreria LiquidCrystal_I2C
Servo Servomotor1; //nombre del nuevo servomotor
Servo Servomotor2; //nombre del nuevo servomotor
Servo Servomotor3; //nombre del nuevo servomotor
#define servoPin1 3 //Numero del pin del servomotor1
#define servoPin2 5 //Numero del pin del servomotor2
#define servoPin3 6 //Numero del pin del servomotor3
int Angulo1 = 0; //Servira para usar los angulos con los servomotores
int Angulo2 = 0; //Servira para usar los angulos con los servomotores
int Angulo3 = 0; //Servira para usar los angulos con los servomotores

#define boton1 1 //incluye el boton 1
#define boton2 9 //incluye el boton 2
#define boton3 4 //incluye el boton 3
#define boton4 8 //incluye el boton 4
#define tonePin 7 //incluye el buzzer

#define POT1 A0 //Pin del potenciometro
#define POT2 A1 //Pin del potenciometro
#define POT3 A2 //Pin del potenciometro
int potValue1; //Indica el valor del POT1
int potValue2; //Indica el valor del POT2
int potValue3; //Indica el valor del POT3

void setup() { //Esta funcion se repetira una sola vez 
  Servomotor1.attach(servoPin1); //selecciona el pin para el servomotor
  pinMode(POT1,INPUT); //Ingresa el valor del potenciometro 1 como entrada
  Servomotor1.write(Angulo1); //selecciona la variable encargada de cambiar el angulo del servomotor

  Servomotor2.attach(servoPin2); //selecciona el pin para el servomotor
  pinMode(POT2,INPUT); //Ingresa el valor del potenciometro 2 como entrada
  Servomotor2.write(Angulo2); //selecciona la variable encargada de cambiar el angulo del servomotor
  
  Servomotor3.attach(servoPin3); //selecciona el pin para el servomotor
  pinMode(POT3,INPUT); //Ingresa el valor del potenciometro 3 como entrada
  Servomotor3.write(Angulo3); //selecciona la variable encargada de cambiar el angulo del servomotor
  
  pinMode(boton1,INPUT_PULLUP); //Configura el buzzer como salida
  pinMode(boton2,INPUT_PULLUP); //Configura el buzzer como salida
  pinMode(boton3,INPUT_PULLUP); //Configura el buzzer como salida
  pinMode(boton4,INPUT_PULLUP); //Configura el buzzer como salida
  pinMode(2,INPUT); //Configura el pin 2 como entrada
  pinMode(tonePin,OUTPUT); //Configura el buzzer como salida
  Serial.begin(9600); //Inicia la variable serial
  lcd_1.init(); //Inicia la LCD
  lcd_1.backlight(); //Configura el brillo
  lcd_1.clear(); //Elimina lo que aparezca en pantalla

  
}

void loop() { //Esta funcion se repetira una infinitas veces hata que haya una interrupcion
  potValue1 = analogRead(POT1); //actualiza el valor actual del potenciometro1
  Angulo1 = map(potValue1,0,1023,0,180); //ingresa el valor drel potenciometro en el angulo1 y lo convierte a angulos
  Servomotor1.write(Angulo1); //imprime el valor del servomotor 1
  delay(10); //se actualiza cada 0.1 segundos

  potValue2 = analogRead(POT2); //actualiza el valor actual del potenciometro2
  Angulo2 = map(potValue2,0,1023,0,180); //ingresa el valor drel potenciometro en el angulo2 y lo convierte a angulos
  Servomotor2.write(Angulo2); //imprime el valor del servomotor 2
  delay(10); //se actualiza cada 0.1 segundos

  potValue3 = analogRead(POT3); //actualiza el valor actual del potenciometro3 
  Angulo3 = map(potValue3,0,1023,0,180); //ingresa el valor drel potenciometro en el angulo3 y lo convierte a angulos
  Servomotor3.write(Angulo3); //imprime el valor del servomotor 3
  delay(10); //se actualiza cada 0.1 segundos
  
  if(digitalRead(boton1) == LOW) //cuando se cumpla la funcion del boton1
  {
    Angulo1=100; //Se actualizara el angulo1
    Servomotor1.write(Angulo1); //se actualiza el servomotor1
    Angulo2=90; //Se actualizara el angulo2
    Servomotor2.write(Angulo2); //se actualiza el servomotor2
    Angulo3=180; //Se actualizara el angulo3
    Servomotor3.write(Angulo3); //se actualiza el servomotor3
    lcd.clear(); //Borrara el texto de la LCD
      lcd.setCursor(0, 0); //el texto aparecera en la linea y posicion
      lcd.print("=====acceso====="); //Imprimira el Texto
      lcd.setCursor(0, 1); //el texto aparecera en la linea y posicion
      lcd.print("====permitido===");//Verifica que la contraseña esta correcta
      delay(2000);
  }
  
  if(digitalRead(boton2) == LOW) //cuando se cumpla la funcion del boton2
  {
    Angulo1=180; //Se actualizara el angulo1
    Servomotor1.write(Angulo1); //se actualiza el servomotor1
    Angulo2=180; //Se actualizara el angulo1
    Servomotor2.write(Angulo2); //se actualiza el servomotor2
    Angulo3=180; //Se actualizara el angulo1
    Servomotor3.write(Angulo3); //se actualiza el servomotor3
  }
  
  if(digitalRead(boton3) == LOW) //cuando se cumpla la funcion del boton3
  {
    Angulo1=10; //Se actualizara el angulo1
    Servomotor1.write(Angulo1); //se actualiza el servomotor1
    Angulo2=50; //Se actualizara el angulo2
    Servomotor2.write(Angulo2); //se actualiza el servomotor2
    Angulo3=60; //Se actualizara el angulo3
    Servomotor3.write(Angulo3); //se actualiza el servomotor3
  }

  if(digitalRead(boton4) == LOW) //cuando se cumpla la funcion del boton4
  {
    Angulo1=0; //Se actualizara el angulo1
    Servomotor1.write(Angulo1); //se actualiza el servomotor1
    Angulo2=0; //Se actualizara el angulo2
    Servomotor2.write(Angulo2); //se actualiza el servomotor2
    Angulo3=0; //Se actualizara el angulo3
    Servomotor3.write(Angulo3); //se actualiza el servomotor3
  }
}

