//const char* ssid = "CENSORED";           
//const char* password = "CENSORED";  

#include <ESP8266WiFi.h>
void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("CENSORED", "CENSORED");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("WHAT");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}
void loop() {}
