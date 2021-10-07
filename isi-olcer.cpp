#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
int val;
int tempPin = A0;
String cel_S;
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float C = mv/10;
  float F = (C/1.8) + 32;
  float K =  C+273.15;
  
  /*her zaman aynı karater de sayı üretmek gerekli yani 1.50 yerine 01.50 yazmak buda yenileme sırasında sayıların kaymasını engelleyecek*/
  if(C<10){    cel_S="0"+(String)(C); } else {  cel_S=(String)(C);  }
  
  Serial.print("TEMPRATURE = ");
  Serial.print(cel_S);
  Serial.print("*C");
  Serial.print(F);
  Serial.print("*F"); 
  Serial.print(K);
  Serial.print("*K"); 
  Serial.println();
  
   lcd.setCursor(4,0); 
   lcd.print(K);
   lcd.setCursor(10,0); 
   lcd.print("K");
   lcd.setCursor(0,1); 
   lcd.print(cel_S);
   lcd.setCursor(5,1); 
   lcd.print("C");
   lcd.setCursor(10,1); 
   lcd.print(F);
   lcd.setCursor(15,1); 
   lcd.print("F");
   delay(100);
}
