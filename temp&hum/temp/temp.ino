



#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN A0

void setup(){
  Serial.begin(115200);\
  delay(1000);
}

void loop(){
  DHT.read(DHT11_PIN);
  Serial.print("Current Humidity= ");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print("temperature= ");
  Serial.print(DHT.temperature);
  Serial.println("c ");
  delay(1000);
  
}
