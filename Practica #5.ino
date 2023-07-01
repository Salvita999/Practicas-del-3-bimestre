#include "LedControl.h"     // incluye libreria LedControl
LedControl lc=LedControl(11,13,10,1);

int VALOR;			// almacena valor leido del sensor
int Buzzer = 6;

byte uno[8]= {      // array que contiene todos los elementos de las
B00001000,
B00011010,
B00111110,
B00111110,
B01111110,
B01111110,
B00111100,
B00011000};

byte uno2[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011100,
B00100000,
B00111000,
B00000100,
B00000100,
B00111000,
B00000000};

byte uno3[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011000,
B00100100,
B00100100,
B00111100,
B00100100,
B00100100,
B00000000};

byte uno4[8]= {      // array que contiene todos los elementos de las
B00000000,
B00100000,
B00100000,
B00100000,
B00100000,
B00100000,
B00111100,
B00000000};

byte uno5[8]= {      // array que contiene todos los elementos de las
B00000000,
B00100100,
B00100100,
B00100100,
B00100100,
B00100100,
B00011000,
B00000000};

byte uno6[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011000,
B00100100,
B00100100,
B00111100,
B00100100,
B00100100,
B00000000};

byte uno7[8]= {      // array que contiene todos los elementos de las
B00000000,
B00111000,
B00100100,
B00100100,
B00100100,
B00100100,
B00111000,
B00000000};

byte uno8[8]= {      // array que contiene todos los elementos de las
B00000000,
B00111000,
B00100100,
B00111000,
B00110000,
B00101000,
B00100100,
B00000000};

byte uno9[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011000,
B00100100,
B00100100,
B00100100,
B00100100,
B00011000,
B00000000};

byte uno10[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011000,
B00100100,
B00001100,
B00010000,
B00100000,
B00111100,
B00000000};

byte uno11[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011000,
B00100100,
B00011100,
B00000100,
B00000100,
B00000100,
B00000000};

byte uno12[8]= {      // array que contiene todos los elementos de las
B00000000,
B00011000,
B00011000,
B00011000,
B00011000,
B00000000,
B00011000,
B00000000};

byte uno13[8]= {      // array que contiene todos los elementos de las
B11111111,
B11100111,
B11100111,
B11100111,
B11100111,
B11111111,
B11100111,
B11111111};

byte uno14[8]= {      // array que contiene todos los elementos de las
B00000000,
B00000000,
B00000000,
B00111100,
B00111100,
B00000000,
B00000000,
B00000000};







void setup(){
  Serial.begin(9600);		// inicializa comunicacion serie a 9600 bps
  // entradas analogicas no requieren inicializacion
  pinMode(Buzzer, OUTPUT); //Configura el estado del pin como salida
  lc.shutdown(0,false);     // enciende la matriz
  lc.setIntensity(0,4);     // establece brillo
  lc.clearDisplay(0);     // blanquea matriz
}

void loop(){
  VALOR = analogRead(A0);	// lee entrada A0 y asigna a variable VALOR
  if(VALOR > 1000){
    Serial.println(VALOR);	// imprime en monitor serial el valor
    delay(500);			// breve demora de medio segundo
    mostrar_15();        

    delay(500);


    mostrar_12();        

    delay(500);

    mostrar_13();        

    delay(500);

    mostrar_1();        

    delay(1000); 
  }
  else{
    digitalWrite(Buzzer,LOW);
  }
  Serial.println(VALOR);	// imprime en monitor serial el valor
  delay(500);			// breve demora de medio segundo  
  mostrar_16();        

  delay(500);     

  mostrar_2();        

  delay(500); 

  mostrar_3();        

  delay(500);

  mostrar_4();        

  delay(500);

  mostrar_5();        

  delay(500);

  mostrar_6();        

  delay(500);

  mostrar_7();        

  delay(500);

  mostrar_9();        

  delay(500);

  mostrar_8();        

  delay(500);
  
  mostrar_14();        

  delay(500);

   mostrar_10();        

  delay(500);

  mostrar_9();        

  delay(500);

  mostrar_10();        

  delay(500);

  mostrar_10();        

  delay(500);

  mostrar_9();        

  delay(500);

  mostrar_9();        

  delay(500);

  mostrar_11();        

  delay(500);
}

void mostrar_1(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_2(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno2[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_3(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno3[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_4(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno4[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_5(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno5[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_6(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno6[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_7(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno7[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_9(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno9[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_8(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno8[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_10(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno10[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_11(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno11[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_12(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno12[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_13(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno13[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_14(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno14[i]);    // establece fila con valor de array uno en misma posicion
  }
}
void mostrar_15(){     // funcion mostrar_1
  tone(Buzzer, 1000);//tono de buzzer
  delay(500);//tiempo del buzzer
  noTone(Buzzer);//no tone
}
void mostrar_16(){     // funcion mostrar_1
  noTone(Buzzer);//buzzer apagado
  delay(500);//tiempo 
}
