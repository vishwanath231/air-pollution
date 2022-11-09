int pin = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(pin);
  Serial.println(a);
  // int percentage = map(a,100, 450,0,100);
  // Serial.println(percentage);
  delay(2000);

} 
