#include <WiFiNINA.h> // Libery to connect the WiFi
#include <ThingSpeak.h> // 
#include "dht.h"
/*#define Atomizer 0 // A0
#define AirPIN 1 // A1
#define MQ2pin 2 // A2*/

int motorPin = 4;
/*float sensorValue;  //variable to store sensor value
float atomizerValue;
float airValue;*/
float motorValue;
const int dht_apin = A3; // Analog Pin sensor is connected to A3
/*char ssid[] = "CENSORED"; // Network name
const char password [] = "CENSORED"; // PWD
const unsigned long channel_id = CENSORED; // CH ID
const char write_api_key[] = "CENSORED";// API key LOOK INNTO API KEYS TAB*/

dht DHT; // Initalize dht to DHT
//WiFiClient client; // Connect to to a specified internet IP address

void setup() {
  // Setting up connection
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  /*delay(100);
  Serial.print("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.println("Attempting to Connect to " + String(ssid) + " .");
    delay(100);
  }
  Serial.println();
  Serial.println("Connected!");
  ThingSpeak.begin(client);*/
  }

void loop() {

  /*airValue = analogRead(AirPIN); // read analog input pin 1
  sensorValue = analogRead(MQ2pin); // read analog input pin 2*/
  motorValue = analogRead(motorPin); // read analog input pin 2
  DHT.read22(dht_apin);
  
  Serial.println("Posting Humdity " + String(DHT.humidity, 2) + "% to ThingSpeak");
  ThingSpeak.setField(1, String(DHT.humidity, 2));
  
  Serial.println("Posting Temperature " + String(DHT.temperature, 2) + " to ThingSpeak");
  ThingSpeak.setField(2, String(DHT.temperature, 2));
  
  /*Serial.println("Posting MQ2 " + String(sensorValue, 2) + " to ThingSpeak");
  ThingSpeak.setField(3, String(sensorValue, 2));*/

// GROVE START IF STATEMENT
  if(DHT.humidity>=50){ //if the humidity % is equal or above the setpoint 51% the atomizer turn ON (HIGH)
      /*digitalWrite(Atomizer,LOW);*/
      digitalWrite(motorPin, HIGH);
      Serial.print("ATOMIZER OFF \n MOTOR ON \n");
      Serial.println("Posting Atomizer OFF" + /*String(atomizerValue, 0) +*/ String(motorValue, 1) + " to ThingSpeak");
      //ThingSpeak.setField(4, String(atomizerValue= 0));
      ThingSpeak.setField(6, String(motorValue= 1));
    }

    else if(DHT.humidity<=30){ 
      //digitalWrite(Atomizer,HIGH);
      digitalWrite(motorPin, LOW);
      Serial.print("ATOMIZER ON \n MOTOR OFF \n");;
      Serial.println("Posting Atomizer ON" + /*String(atomizerValue, 1) +*/ String(motorValue, 0) +  " to ThingSpeak");
      //ThingSpeak.setField(4, String(atomizerValue = 1));
      ThingSpeak.setField(6, String(motorValue= 0));
    }

    else if(DHT.humidity){
      //digitalWrite(Atomizer,LOW);
      digitalWrite(motorPin, LOW);
      Serial.print("ATOMIZER OFF \n MOTOR OFF \n");
      Serial.println("Posting Atomizer OFF " + /*String(atomizerValue, 0) +*/ String(motorValue, 0) +  " to ThingSpeak");
      //ThingSpeak.setField(4, String(atomizerValue = 0));
      ThingSpeak.setField(6, String(motorValue= 0));
    }
// GROVE END

  /*Serial.println("Posting " + String(airValue, 2) + " to ThingSpeak");
  ThingSpeak.setField(5, String(airValue, 2));*/
  
  //ThingSpeak.writeFields(channel_id, write_api_key);
  Serial.println();
  //delay(300000); // 5min delay
  delay(15000); // 15s delay Testing purposes
}
