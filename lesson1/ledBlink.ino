#define LED_PIN 14

void setup() {
  // put your setup code here, to run once:
pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_PIN,HIGH);
delay(300);
digitalWrite(LED_PIN,LOW);
delay(1000);
}
