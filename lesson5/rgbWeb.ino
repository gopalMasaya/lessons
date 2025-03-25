#include <WiFi.h>
#include <Adafruit_NeoPixel.h>

#define RGB_PIN 48   // Onboard RGB LED
#define NUMPIXELS 1  
#define MOTOR_PIN 5  // GPIO pin for the motor relay or motor driver

Adafruit_NeoPixel pixels(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

const char* ssid = "Creative";
const char* password = "Radhe1008";

WiFiServer server(80);
bool motorState = false;  // Track motor state

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  pixels.begin();
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);  // Motor OFF by default
}

void setColor(int r, int g, int b) {
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels.show();
}

void toggleMotor(bool state) {
  digitalWrite(MOTOR_PIN, state ? HIGH : LOW);
  motorState = state;
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();
  
  if (request.indexOf("/set_color") != -1) {
    int r = request.substring(request.indexOf("r=") + 2).toInt();
    int g = request.substring(request.indexOf("g=") + 2).toInt();
    int b = request.substring(request.indexOf("b=") + 2).toInt();
    
    setColor(r, g, b);
    Serial.printf("Color set: R=%d, G=%d, B=%d\n", r, g, b);
    
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();
    client.print("{\"status\":\"success\",\"r\":");
    client.print(r);
    client.print(",\"g\":");
    client.print(g);
    client.print(",\"b\":");
    client.print(b);
    client.print("}");
  }

  if (request.indexOf("/toggle_motor") != -1) {
    motorState = !motorState;
    toggleMotor(motorState);
    
    Serial.printf("Motor %s\n", motorState ? "ON" : "OFF");
    
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();
    client.print("{\"status\":\"success\",\"motor\":");
    client.print(motorState ? "on" : "off");
    client.print("}");
  }
}
