#define BLYNK_PRINT Serial // Comment this out to disable prints and save space
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "bs8yZnDRaaEWgsDijAChXezZFuag74-O";
char ssid[]="V2040";
char pass[]="regzaa24";

#define DHTPIN D4

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); 3333`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````,LQ
SimpleTimer timer;
void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V20, h); //kelembaban
  Blynk.virtualWrite(V24, t); //suhu
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  timer.setInterval(1000L, sendSensor);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
