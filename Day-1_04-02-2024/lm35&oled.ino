#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int lm35Pin = A0; // LM35 analog pin

void setup() {
  Serial.begin(9600);
  
  // Initialize the OLED display with I2C address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Temperature:");
  display.display();
  delay(1000);
}

void loop() {
  
  int sensorValue = analogRead(lm35Pin);
  
 
  float temperature = sensorValue / 9.31; 
  
  // Display temperature on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  // Display temperature on OLED display
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,16);
  display.print(temperature);
  display.print(" C");
  display.display();

  delay(1000); 
}