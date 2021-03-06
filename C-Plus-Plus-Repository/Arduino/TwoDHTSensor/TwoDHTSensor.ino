#include <DHT.h>;

#define DHTPIN1 0 
#define DHTPIN2 1

DHT dht[] = {
  {DHTPIN1, DHT11},
  {DHTPIN2, DHT22},
};

float humidity[4];
float temperature[4];

void setup()
{
  Serial.begin(9600);
  for (auto& sensor : dht) {
    sensor.begin();
  }
}

void loop()
{
  for (int i = 0; i < 4; i++) {
    temperature[i] = dht[i].readTemperature();
    humidity[i] = dht[i].readHumidity();
  }

  for (int i = 0; i < 4; i++) {
    Serial.print(F("Temperature "));
    Serial.print(i);
    Serial.println(temperature[i]);
    Serial.print(F("Humidity "));
    Serial.print(i);
    Serial.println(humidity[i]);
  }
  delay(5000);
}
