#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {

  dht.begin(); 
   
  Wire.setSDA(12);
  Wire.setSCL(13);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);


}

void loop() {

  delay(2000);
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float F = dht.readTemperature(true);

  if(isnan(hum)||isnan(temp)||isnan(F)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  delay(2000);

  display.clearDisplay();
  display.setCursor(0,10);
  display.print("HUMIDITY : ");
  display.display();
  display.println(hum);
  display.display();

  display.print("TEMPERATURE : ");
  display.display();
  display.println(temp);
  display.display();
}
