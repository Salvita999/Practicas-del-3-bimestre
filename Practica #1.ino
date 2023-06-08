// C++ code
//
#include <LiquidCrystal_I2C.h> //incluye la libreria LiquidCrystal_I2C
LiquidCrystal_I2C lcd_1(0x27,16,2); //pone los parametros para la LCD

#define boton  3 //boton en pin 2
#define bomba  11 //bomba en pin 11
#define Trig 10
#define echo 9
float time;
float distancia;
float porcentaje;
const float velocidad=0.0343;
int tonePin = 6;

byte vacio[8]={       // Representa una variable de 8 bytes para guardar caracteres
0b00000,
0b00000,
0b00001,
0b00111,
0b01111,
0b11111,
0b01000,
0b01111,





};
byte vacio1[8]={       // Representa una variable de 8 bytes para guardar caracteres
0b00000,
0b00000,
0b10000,
0b11100,
0b11110,
0b11111,
0b00010,
0b11110,





};
byte vacio2[8]={       // Representa una variable de 8 bytes para guardar caracteres
0b01000,
0b01000,
0b01000,
0b11000,
0b10100,
0b10011,
0b10000,
0b10000,




};
byte vacio3[8]={       // Representa una variable de 8 bytes para guardar caracteres
0b00010,
0b00010,
0b00010,
0b00011,
0b00101,
0b11001,
0b00001,
0b00001,



};
byte vacio4[8]={       // Representa una variable de 8 bytes para guardar caracteres
0b00000,
0b00000,
0b00001,
0b00111,
0b01111,
0b11111,
0b01000,
0b01000,





};
byte vacio5[8]={       // Representa una variable de 8 bytes para guardar caracteres
0b00000,
0b00000,
0b10000,
0b11100,
0b11110,
0b11111,
0b00010,
0b00010,



};

void setup()
{
  pinMode(boton, INPUT_PULLUP); //Configura el estado del pin como entrada con pull up
  pinMode(bomba, OUTPUT); //Configura el estado del pin como salida

  pinMode(Trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(tonePin, OUTPUT); 
  Serial.begin(9600);
  lcd_1.init(); //Inicia la LCD
  lcd_1.backlight(); //Configura el brillo
  lcd_1.clear(); //Elimina lo que aparezca en pantalla
  
  lcd_1.begin(16, 2);
  lcd_1.createChar(0,vacio);  // Crea un carácter tomando los valores que previamente habíam
  lcd_1.createChar(1,vacio1);  // Crea un carácter tomando los valores que previamente habíam
  lcd_1.createChar(2,vacio2);  // Crea un carácter tomando los valores que previamente habíam
  lcd_1.createChar(3,vacio3);  // Crea un carácter tomando los valores que previamente habíam
  lcd_1.createChar(4,vacio4);  // Crea un carácter tomando los valores que previamente habíam
  lcd_1.createChar(5,vacio5);  // Crea un carácter tomando los valores que previamente habíam
}

void loop()
{
  digitalWrite(bomba,HIGH); //Indica el estado de la bomba como en HIGH
  digitalWrite(Trig,HIGH);
  delay(100);
  digitalWrite(Trig,LOW);
  time=pulseIn(echo,HIGH);
  distancia=(time)*velocidad/2;
  porcentaje=(distancia)*100/11;
  Serial.print(porcentaje);
  Serial.println("%");

  digitalWrite(bomba,HIGH); //Indica el estado de la bomba como en HIGH
  lcd_1.setCursor(1,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(0));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(1));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("Su bomba esta ");
  lcd_1.setCursor(1,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(2));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(3));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("a: "); 
  lcd_1.print( porcentaje);
  lcd_1.print("%"); 
  
  delay(1001);

  lcd_1.clear();

if(distancia>=12){
  digitalWrite(bomba,HIGH); //Indica el estado de la bomba como en HIGH
  lcd_1.setCursor(1,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(4));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(5));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("Su bomba ");
  lcd_1.setCursor(1,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(2));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(3));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("esta vacia ");
  tone(tonePin, 195, 92.2130625);
     tone(tonePin, 311, 128.571375);
    delay(142.857083333);
    tone(tonePin, 233, 128.571375);
    delay(142.857083333);
    delay(285.714166667);
    tone(tonePin, 311, 128.571375);
    delay(142.857083333);
    tone(tonePin, 233, 128.571375);
    delay(142.857083333);
    delay(285.714166667);
    tone(tonePin, 311, 128.571375);
    delay(142.857083333);
    tone(tonePin, 233, 128.571375);
    delay(142.857083333);
    delay(285.714166667);
    tone(tonePin, 311, 128.571375);
    delay(142.857083333);
    tone(tonePin, 233, 128.571375);
    delay(142.857083333);
    delay(285.714166667);
  
  delay(1001);

  lcd_1.clear();
  
}
  

if(distancia<=4){
  digitalWrite(bomba,HIGH); //Indica el estado de la bomba como en HIGH
  lcd_1.setCursor(1,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(0));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(1));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("Su bomba ");
  lcd_1.setCursor(1,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(2));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(3));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("esta llena ");
  
  delay(1001);

  lcd_1.clear();
  
}

if(digitalRead(boton) == LOW){
  lcd_1.clear();
  digitalWrite(bomba,LOW); //Indica el estado de la bomba como en HIGH
  lcd_1.setCursor(1,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(0));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(1));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("Vaciando ");
  lcd_1.setCursor(1,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(2));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(3));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("la bomba ");
  tone(tonePin, 195, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 220, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 246, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 277, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 195, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 220, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 246, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 277, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 207, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 233, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 261, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 293, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 207, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 233, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 261, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 293, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 220, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 246, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 277, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 311, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 220, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 246, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 277, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 311, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 233, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 261, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 293, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 329, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 233, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 261, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 293, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 329, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 246, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 277, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 311, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 349, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 261, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 293, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 329, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 369, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 277, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 311, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 349, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 391, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 293, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 329, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 369, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    tone(tonePin, 415, 92.2130625); //Frecuencia que tendra el sonido
    delay(102.458958333); //tiempo de espera
    delay(409.835833333); //tiempo de espera
  

  lcd_1.clear();
  


  digitalWrite(bomba,HIGH); //Indica el estado de la bomba como en HIGH
  lcd_1.setCursor(1,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(4));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(5));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,0);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("Su bomba ");
  lcd_1.setCursor(1,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(2));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(2,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.write(byte(3));      // Escribe el carácter 0 (smile)
  lcd_1.setCursor(4,1);      // posiciona el cursor en la casilla "0" dela fila "0")
  lcd_1.print("esta vacia ");

  tone(tonePin, 349, 184.426125); //Frecuencia que tendra el sonido
    delay(204.917916667); //tiempo de espera
    tone(tonePin, 369, 184.426125); //Frecuencia que tendra el sonido
    delay(204.917916667); //tiempo de espera
    tone(tonePin, 391, 184.426125); //Frecuencia que tendra el sonido
    delay(204.917916667); //tiempo de espera
    tone(tonePin, 415, 2028.687375); //Frecuencia que tendra el sonido
    delay(2254.09708333); //tiempo de espera
    delay(4815.57104167); //tiempo de espera
    tone(tonePin, 1174, 1567.6220625); //Frecuencia que tendra el sonido
    delay(1741.80229167); //tiempo de espera
  
  delay(3001);

  lcd_1.clear();
}

  
}
