#include<LiquidCrystal.h>
#define trig 9
#define echo 10
#define yerayari 2
#define olcme 11
#define sicaklik 12
const int sensor_pin=A3;
int sensor_deger=0;
float voltaj_deger=0;
float sicaklik_deger=0; 
float sure=0;
float mesafe=0;
float ilkmesafe=0;
byte surat[8]={B00000,B00000,B00000,B01010,B00000,B10001,B01110};
LiquidCrystal lcd(8,7,6,5,4,3);
float mesafeolc()
{
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  sure=pulseIn(echo,HIGH);
  mesafe=(sure/2)/28.5;
  return mesafe;
}
void setup()
{
  
Serial.begin(9600);
lcd.begin(16,2);
lcd.createChar(1,surat);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(yerayari,INPUT);
pinMode(olcme,INPUT);
pinMode(sicaklik,OUTPUT);
lcd.setCursor(0,0);
lcd.print(" Boy ve Sicaklik");
lcd.setCursor(0,1);
lcd.write(byte(1));
lcd.print(" Olcum Cihazi ");
lcd.write(byte(1));
delay(6000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Kalibrasyon icin");
lcd.setCursor(0,1);
lcd.print("Kirmizi Butona");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Uzunluk icin");
lcd.setCursor(0,1);
lcd.print("Mavi Butona");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Sicaklik icin");
lcd.setCursor(0,1);
lcd.print("Yesil Butona");
delay(3000);
lcd.clear();
lcd.print("  !!Basiniz!!");
delay(1500);
lcd.clear();
while((digitalRead(yerayari)==LOW) )
{
lcd.setCursor(0,0);
lcd.print("Kalibrasyon icin");
lcd.setCursor(0,1);
lcd.print("Butona Basiniz!!");
delay(100);

if(digitalRead(yerayari)==HIGH)
{
  
  delay(50);
  ilkmesafe=mesafeolc();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Kalibrasyon");
  lcd.setCursor(0,1);
  lcd.print("Yapildi");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Kalibrasyon=");
  lcd.setCursor(0,1);
  lcd.print(ilkmesafe);
  lcd.print("cm");
  delay(2000);
  lcd.clear();
 break;
}

}

}

void loop()
{
  sensor_deger=analogRead(sensor_pin);
  voltaj_deger=(sensor_deger/1023.0)*5000;
  sicaklik_deger=voltaj_deger/10.0;
  if(digitalRead(olcme)==HIGH)
  {
 lcd.setCursor(0,0);
 lcd.print("Boyunuz");
 lcd.setCursor(0,1);
 float boy=ilkmesafe-mesafeolc();
 lcd.print(boy);
 lcd.print("cm");
 delay(2000);
 lcd.clear();
 if(boy>=175)
 {
  lcd.setCursor(0,0);
  lcd.print("Uzun");
  lcd.setCursor(0,1);
  lcd.print("Boylusunuz ");
  lcd.write(byte(1));
  lcd.write(byte(1));
  lcd.write(byte(1));
  delay(2000);
  lcd.clear();
 }
 else if((boy>=160) && (boy<175))
 {
  lcd.setCursor(0,0);
  lcd.print("Orta");
  lcd.setCursor(0,1);
  lcd.print("Boylusunuz ");
  lcd.write(byte(1));
  lcd.write(byte(1));
  delay(2000);
  lcd.clear();
 }
  else if((boy<160))
 {
  lcd.setCursor(0,0);
  lcd.print("Kisa");
  lcd.setCursor(0,1);
  lcd.print("Boylusunuz ");
  lcd.write(byte(1));
  delay(2000);
  lcd.clear();
 }
 }
 else
 {
  lcd.setCursor(0,0);
  lcd.print("   Olcum icin");
  lcd.setCursor(0,1);
  lcd.print("  !!Basiniz!!");
  delay(200);
  lcd.clear();
 }
 if(digitalRead(sicaklik)==HIGH)
 {
  lcd.setCursor(0,0);
  lcd.print("Sicaklik=");
  lcd.setCursor(0,1);
  lcd.print(sicaklik_deger);
  lcd.print(" C");
  
  delay(2000);
  lcd.clear();
 }
 
}


