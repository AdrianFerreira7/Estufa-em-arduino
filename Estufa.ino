
#include "DHT.h"
#include <LiquidCrystal.h>
 
#define DHTPIN 6 
const int lampada = 7;
const int agua = 8;
 
#define DHTTYPE DHT11 

LiquidCrystal lcd(12,11,5,4,3,2);
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  pinMode(lampada, OUTPUT);
  pinMode(agua, OUTPUT);
 Serial.begin(9600); 
 Serial.println("DHTxx test!");
 lcd.begin(16, 2); 
 
 dht.comeco();
}
 
void loop() {
 int x = 0;
 float h = dht.le_umidade();
 float t = dht.ler_Temperatura();
 
 if (isnan(t) || isnan(h)) {
 Serial.println("Falha ao ler de DHT");
 } else {
 Serial.print("Umidade: "); 
 Serial.print(h);
 Serial.print(" %\t");
 Serial.print("Temperatura: "); 
 Serial.print(t);
 Serial.println(" *C");
delay(10);
 lcd.setCursor(0, 0);
  lcd.print("Umidade: "); 
 lcd.print(h);
  lcd.print(" %");
 lcd.setCursor(0, 1);
 lcd.print("Temp.:  "); 
 lcd.print(t);
 lcd.println(" *C");
 delay(10);
  while(x != 0){
    if(t <= 25){
      digitalWrite(lampada, HIGH);
      x++;
  }else{
    x=0;
  }
  }while(x != 0){
    if(h < 50){
      digitalWrite(agua, HIGH);
      x++;
    }else{
      x=0;
    }
  }
}
}