#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


int power=12;
int battery=13;
const float referenceVolts = 5.0;
const int batteryPin = 0;
const int ENA = 9;
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;


void setup()
{
pinMode (power, OUTPUT );
pinMode (battery, OUTPUT);
digitalWrite (power, HIGH);
digitalWrite (battery, LOW);
lcd.begin(16, 2);
Serial.begin(9600);
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
pinMode (ENA, OUTPUT);
}


void loop() 
{
int val = analogRead(batteryPin);
float voltage = (val / 1023.0) * referenceVolts;
Serial.println(voltage);
delay(500);
analogWrite(ENA, 255);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);

if (voltage>3) 
{
digitalWrite (power, LOW);
digitalWrite (battery, HIGH);
lcd.print(" CHARGED");
lcd.setCursor(0, 0);
delay(1500);
lcd.clear();
lcd.print(" ELECTRIC POWER");
lcd.setCursor(0, 1);
delay(1500);
lcd.clear();
}


else if (voltage<1) 
{
digitalWrite (power, HIGH);
digitalWrite (battery, LOW);
lcd.print(" LOW BATTERY");
lcd.setCursor(0, 0);
delay(1500);
lcd.clear();
lcd.print("MECHANICAL POWER");
lcd.setCursor(0, 1);
delay(1500);
lcd.clear();
}
}