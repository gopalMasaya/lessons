#define LEDC_TIMER_RESOLUTION 12   // 12-bit resolution (0-4095)
#define LEDC_BASE_FREQ 1000  // PWM frequency

#define L_pwm 4          // GPIO pin for LED output
#define L_forward 5
#define L_back 6

 #define r_pwm 7          // GPIO pin for LED output
 #define r_forward 15
 #define r_back 16




#define MAX_DUTY ((1 << LEDC_TIMER_RESOLUTION) - 1)

String input ="";
int power = 0;
String dir = "";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
ledcAttach(L_pwm, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);
ledcAttach(r_pwm, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);



pinMode(L_forward,OUTPUT);
pinMode(L_back,OUTPUT);
pinMode(r_forward,OUTPUT);
pinMode(r_back,OUTPUT);


delay(200);

}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available()){
  input = Serial.readStringUntil('\n');
  dir = input.substring(0,1);
  String speed = input.substring(1,4);
   power = input.toInt();
  digitalWrite(L_forward,HIGH);
  digitalWrite(L_back,LOW);
  
  digitalWrite(r_forward,HIGH);
  digitalWrite(r_back,LOW);
  
   delay(50);
   Serial.println(power);
   delay(200);
}

 ledcWrite(L_pwm, power);
 ledcWrite(r_pwm, power);
 delay(20);
}


