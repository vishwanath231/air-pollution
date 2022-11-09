#include <Wire.h>              
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
     
float tempPin = 3;      

int pin = A0; 

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup(){

  pinMode(pin, INPUT); 
 
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  dht.begin();
 

  Serial.begin(9600); 
}

void loop(){

  int a = analogRead(pin);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Serial.print("Humidity= ");
  // Serial.print(h);
  

  // Serial.print("temperature: ");
  // Serial.print(t);
  // Serial.println("c ");

  // Serial.print("air: ");
  // Serial.println(a);
 
  lcd.setCursor(0,0);
  lcd.print("air:");
  lcd.print(a);

  lcd.setCursor(7,0);
  lcd.print("tmp:");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(3,1);
  lcd.print("hum:");
  lcd.print(h);
  lcd.print("%");

  delay(1000);

}
