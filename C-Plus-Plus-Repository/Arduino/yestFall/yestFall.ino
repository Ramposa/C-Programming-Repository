#include <Wire.h>
 #define BLYNK_PRINT Serial
 #include <ESP8266WiFi.h>
 #include <BlynkSimpleEsp8266.h>
 const int MPU_addr = 0x68; // I2C address of the MPU-6050
 int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
 float ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0;
 boolean fall = false; //stores if a fall has occurred
 boolean trigger1 = false; //stores if first trigger (lower threshold) has occurred
 boolean trigger2 = false; //stores if second trigger (upper threshold) has occurred
 boolean trigger3 = false; //stores if third trigger (orientation change) has occurred
 byte trigger1count = 0; //stores the counts past since trigger 1 was set true
 byte trigger2count = 0; //stores the counts past since trigger 2 was set true
 byte trigger3count = 0; //stores the counts past since trigger 3 was set true
 int angleChange = 0;
  // WiFi network info.
 char auth[] = "YGXyRFBsrdHEYq4QXsLttGT91wqDZDaI"; //Auth code sent via Email
 const char *ssid = "IoTTestNetwork"; // Enter your Wi-Fi Name
 const char *pass = "7HzOTHxq"; // Enter your Wi-Fi Password
