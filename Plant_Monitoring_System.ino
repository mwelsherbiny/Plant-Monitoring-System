#include <DHT11.h>
#include <LiquidCrystal.h>

// LCD
int RS = 8;
int E = 9;
int D4 = 10;
int D5 = 11;
int D6 = 12;
int D7 = 13;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

// DHT11
int dht = 6;
int temperature;
float humidity;
DHT11 dht11(dht);

// Moisture Sensor
int MoistureSensor = A0;
int moisture;

// LDR
int LDR = A1;
int light;

// Water Pump
int waterPump = 2;

void setup()
{
  pinMode(waterPump, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  // Display Temperature & Humidity
  temperature = dht11.readTemperature();
  humidity = dht11.readHumidity();
  lcd.print("T: ");
  lcd.print(temperature);
  lcd.print("   H: ");
  lcd.print(humidity);

  lcd.setCursor(0, 1);
  
  // Display Light
  light = analogRead(LDR);
  lcd.print("L:");
  if (light >= 500)
  {
    lcd.print("High");
  }
  else
  {
    lcd.print("Low "); 
  }  
  
  // Display Moisture
  moisture = analogRead(MoistureSensor);
  lcd.print("  M: ");
  lcd.print(moisture);
  
  // Control Water Pump
  if (moisture < 400)
  {
    digitalWrite(waterPump, HIGH);
  }
}
