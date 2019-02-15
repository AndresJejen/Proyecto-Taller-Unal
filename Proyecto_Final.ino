#include "DHT.h"

DHT dht(11, DHT11);

int T;
int H;

int T_d, T_u;
int H_d, H_u;

int valor= 0;

const int timeThreshold = 150;
long timeCounter = 0;

void dibujar(int numero,int decena){

  switch (numero) {
    case 0:
      digitalWrite(3+decena,LOW);
      digitalWrite(5+decena,LOW);
      digitalWrite(7+decena,LOW);
      digitalWrite(9+decena,LOW);
      break;
    case 1:
      digitalWrite(3+decena,HIGH);
      digitalWrite(5+decena,LOW);
      digitalWrite(7+decena,LOW);
      digitalWrite(9+decena,LOW);
      break;
    case 2:
      digitalWrite(3+decena,LOW);
      digitalWrite(5+decena,HIGH);
      digitalWrite(7+decena,LOW);
      digitalWrite(9+decena,LOW);
      break;
    case 3:
      digitalWrite(3+decena,HIGH);
      digitalWrite(5+decena,HIGH);
      digitalWrite(7+decena,LOW);
      digitalWrite(9+decena,LOW);
      break;
    case 4:
      digitalWrite(3+decena,LOW);
      digitalWrite(5+decena,LOW);
      digitalWrite(7+decena,HIGH);
      digitalWrite(9+decena,LOW);
      break;
    case 5:
      digitalWrite(3+decena,HIGH);
      digitalWrite(5+decena,LOW);
      digitalWrite(7+decena,HIGH);
      digitalWrite(9+decena,LOW);
      break;
    case 6:
      digitalWrite(3+decena,LOW);
      digitalWrite(5+decena,HIGH);
      digitalWrite(7+decena,HIGH);
      digitalWrite(9+decena,LOW);
      break;
    case 7:
      digitalWrite(3+decena,HIGH);
      digitalWrite(5+decena,HIGH);
      digitalWrite(7+decena,HIGH);
      digitalWrite(9+decena,LOW);
      break;
    case 8:
      digitalWrite(3+decena,LOW);
      digitalWrite(5+decena,LOW);
      digitalWrite(7+decena,LOW);
      digitalWrite(9+decena,HIGH);
      break;
    case 9:
      digitalWrite(3+decena,HIGH);
      digitalWrite(5+decena,LOW);
      digitalWrite(7+decena,LOW);
      digitalWrite(9+decena,HIGH);
      break;
    default:
      // statements
      break;
  }
}

void blink() {
    if (millis() > timeCounter + timeThreshold)
   {

      if (valor== 0){
        valor = 1;
      }
      else if(valor==1){
        valor = 0;
      }
      else{
      
      }
      
      timeCounter = millis();
   }
}

void setup() {
  dht.begin();
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  H = (int) dht.readHumidity();
  // Read temperature as Celsius (the default)
  T = (int) dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);
  T_u = T%10;
  T_d = T/10;

  H_u = H%10;  
  H_d = H/10;

  if (valor == 0){
    dibujar(T_u,0);
    dibujar(T_d,1);
  }
  else if(valor == 1){
    dibujar(H_u,0);
    dibujar(H_d,1); 
  }
  else{}

  Serial.println(T);
  Serial.println(H);
  Serial.println();
  
}
