# IoT JSON Streamer

This project demonstrates a basic program for an IoT device to send JSON data to a server endpoint. We use an ESP8266 module and an ultrasonic sensor to measure distance (in centimeters and inches) and upload the data to ThingSpeak. The JSON file from ThingSpeak is downloaded and sent to a Flask server endpoint.

## Features
- Measure distance using an ultrasonic sensor.
- Send data (distance in cm and inches) to ThingSpeak via ESP8266.
- Download JSON data from ThingSpeak and post it to a Flask server.

---

## Hardware Requirements
- ESP8266 Module
- Ultrasonic Sensor (e.g., HC-SR04)
- Jumper wires
- Power supply

---

## Software Requirements
- Arduino IDE
- Python 3
- Flask
- Postman

---

## Deployment

### Step 1: Setting up the ESP8266
1. Connect the ultrasonic sensor to the ESP8266:
   - *Trig Pin:* GPIO 12
   - *Echo Pin:* GPIO 14
     ![image](https://github.com/user-attachments/assets/fdb566c7-1114-48fa-8f30-570e1ecd1182)

2. Flash the Arduino code from the [Arduino/iot_arduino_code.ino](./Arduino/iot_arduino_code.ino) file using the Arduino IDE.
   - Set the Wi-Fi credentials in the code:
     cpp
     const char* ssid = "YOUR_SSID";
     const char* password = "YOUR_PASSWORD";
     
   - Replace the ThingSpeak API key with your API key:
     cpp
     const char* apiKey = "YOUR_API_KEY";
     
3. Open the serial monitor to verify the distance readings and HTTP response from ThingSpeak.
   ![image](https://github.com/user-attachments/assets/dea9dc07-650a-4a6a-b42f-8d57018a0d1e)
---

### Step 2: Configuring the Server
1. Install Flask:
   ```bash    
   pip install flask
#### Json Data Representation using Postman
![image](https://github.com/user-attachments/assets/30b4f010-1c97-4410-83fc-3f84c4c1196d)

![image](https://github.com/user-attachments/assets/51c5c37f-7ae0-40a7-9002-aa63d2d19ee9)

