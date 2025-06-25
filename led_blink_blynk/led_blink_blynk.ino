

// Blynk Template details (from Blynk console)
#define BLYNK_TEMPLATE_ID "TMPL3ZYwy7anr"
#define BLYNK_TEMPLATE_NAME "LED ESP"
#define BLYNK_AUTH_TOKEN "fFLZxtJ-PSEJymtfWQdsWbznMJGELdn1"

// Include required libraries
#include <WiFi.h>                  // ESP32 uses the standard WiFi library
#include <BlynkSimpleEsp32.h>      // Use the ESP32 Blynk library

// WiFi credentials
char ssid[] = "AMAL";           // Replace with your WiFi SSID
char pass[] = "1291to91two9";           // Replace with your WiFi password

// Define the LED pin
const int ledPin = 2;  // Use GPIO2 on ESP32 (similar to D2 on ESP8266, but use GPIO number for ESP32)

// Blynk virtual button function on V0
BLYNK_WRITE(V0) {
  int value = param.asInt();        // Read 1 (ON) or 0 (OFF) from Blynk button
  digitalWrite(ledPin, value);      // Set LED ON/OFF based on button press
}

void setup() {
  pinMode(ledPin, OUTPUT);          // Set GPIO2 as OUTPUT
  digitalWrite(ledPin, LOW);        // Start with LED OFF

  Serial.begin(9600);               // Begin Serial for debug output
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  // Connect to WiFi + Blynk
}

void loop() {
  Blynk.run();                      // Keep Blynk running in background
}
