#define LED_PIN 14           // GPIO pin for LED output
#define POT_PIN 1            // Analog input pin for potentiometer
#define LEDC_TIMER_RESOLUTION 12   // 12-bit resolution (0-4095)
#define LEDC_BASE_FREQ 5000  // PWM frequency

#define MAX_DUTY ((1 << LEDC_TIMER_RESOLUTION) - 1)
String step="";
int power = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32-S3 Potentiometer LED Control");
  
  // Set up analog input
  analogReadResolution(12);  // Match our LED resolution
  
  // Setup LED PWM
  ledcAttach(LED_PIN, LEDC_BASE_FREQ, LEDC_TIMER_RESOLUTION);
}

void loop() {
  if(Serial.available()){
    step = Serial.readStringUntil('\n');
    power = step.toInt();
     ledcWrite(LED_PIN, power);

  }
  // Read the potentiometer value (0-4095)
  int potValue = analogRead(POT_PIN);
  
  // Set LED brightness based on pot position
 // ledcWrite(LED_PIN, potValue);
  
  // Print values for debugging
  Serial.print("Pot value: ");
  Serial.print(power);
  Serial.print(" | LED brightness: ");
  Serial.println(potValue);
  
  // Small delay to prevent serial flooding
  delay(100);
}