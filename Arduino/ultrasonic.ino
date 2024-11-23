#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "AYUSH";
const char* password = "12345678";

const char* server = "http://api.thingspeak.com/update";
const char* apiKey = "4W45KHNTHF8KAVUG";

const int trigPin = 12;
const int echoPin = 14;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  

  WiFi.begin(ssid, password);
  Serial.println("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCm = duration * SOUND_VELOCITY / 2;

  distanceInch = distanceCm * CM_TO_INCH;

  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

  if (WiFi.status() == WL_CONNECTED) { 
    WiFiClient client;
    HTTPClient http;

    String url = String(server) + "?api_key=" + apiKey + "&field1=" + String(distanceCm) + "&field2=" + String(distanceInch);
    http.begin(client, url); // Specify the URL with the WiFiClient
    int httpResponseCode = http.GET(); // Send the request

    if (httpResponseCode > 0) {
      Serial.print("ThingSpeak Response: ");
      Serial.println(httpResponseCode); // HTTP response code
    } else {
      Serial.print("Error in HTTP request: ");
      Serial.println(httpResponseCode);
    }
    http.end(); // Free resources
  } else {
    Serial.println("Wi-Fi not connected");
  }

  delay(10000); // Wait 10 seconds before next measurement
}