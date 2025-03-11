#define led1 14
#define led2 13

void setup() {
  // put your setup code here, to run once:
pinMode(14,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
delay(200);
digitalWrite(led1,LOW);
digitalWrite(led1,HIGH);
delay(500);
}
