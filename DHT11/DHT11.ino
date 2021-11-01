#define BLYNK_PRINT Serial

// setting library
#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk
#include <DHT.h>

char auth[] = "mrO7DRPIA-nTrG-1yLB9QYaSwabxMU_C"; //token yang dikirim dari blynk ke email masing masing
char ssid[] = "WiFi";
char pass[] = "apaandahh";

#define DHTPIN 14
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || (isnan(t)) { // mengecek kondisi apabila suhu dan kelembapan tidak ada
    Serial.println("Failed to read temp amd humidity")
    retun;
  }

  Blynk.virtualWrite(V1, t); // setting virtual suhu di BLynk
  Blynk.virtualWrite(V2, h); // setting virtual kelembapam di Blynk 
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin(); // sensor mulai membaca suhu dan kelembapan
  timer.setInterval(1000, sendSensor); // waktu untuk mengirimkan data setiap satu detik sekali

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
  
}
