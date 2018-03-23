#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int ldr1Tl = A0;
const int ldr50Krs = A1;
const int ldr25Krs = A2;
const int ldr10Krs = A3;
const int ldr5Krs = A6;
const int btnLcd = 4;
const int btnReset = 3;
int backlightLcd;

int count = 0;
double toplampara = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("HOSGELDINIZ");
  delay(1000);
  lcd.clear();
  delay(500);
  lcd.setCursor(2, 0);
  lcd.print("HOSGELDINIZ");
  delay(1000);
  lcd.clear();
  delay(500);
  lcd.setCursor(2, 0);
  lcd.print("HOSGELDINIZ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Toplam Paraniz:");
  lcd.setCursor(0, 1);
  lcd.print(toplampara);
  lcd.print(" TL");

  backlightLcd = 1;

  pinMode(ldr1Tl, INPUT);
  pinMode(ldr50Krs, INPUT);
  pinMode(ldr25Krs, INPUT);
  pinMode(ldr10Krs, INPUT);
  pinMode(ldr5Krs, INPUT);
  pinMode(btnReset, INPUT);
  pinMode(btnLcd, INPUT);



}

void loop() {

  int durum1Tl = analogRead(ldr1Tl);
  int durum50Krs = analogRead(ldr50Krs);
  int durum25Krs = analogRead(ldr25Krs);
  int durum10Krs = analogRead(ldr10Krs);
  int durum5Krs = analogRead(ldr5Krs);
  int durumReset = digitalRead(btnReset);
  int durumLcd = digitalRead(btnLcd);


  if (durumReset == 1) {
    toplampara = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Toplam Paraniz:");
    lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");
  }
  if (durumLcd == 1)
  {
    if (backlightLcd == 1)
    {
      lcd.setBacklight(LOW);
      backlightLcd = 0;
      Serial.println("Ekran Kapalı");
      delay(1000);
    }
    else
    {
      Serial.println("Ekran Açık.");
      lcd.clear();
      lcd.setBacklight(HIGH);
      backlightLcd = 1;
      lcd.setCursor(2, 0);
      lcd.print("HOSGELDINIZ");
      delay(1000);
      lcd.clear();
      delay(500);
      lcd.setCursor(2, 0);
      lcd.print("HOSGELDINIZ");
      delay(1000);
      lcd.clear();
      delay(500);
      lcd.setCursor(2, 0);
      lcd.print("HOSGELDINIZ");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Toplam Paraniz:");
      lcd.setCursor(0, 1);
      lcd.print(toplampara);
    }
  }

  if (durum1Tl <= 400) {
    lcd.setBacklight(HIGH);
    backlightLcd = 1;
    delay(1000);
    Serial.println("1 TL atıldı.");
    toplampara = toplampara + 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1 TL atildi.");
    lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");
        count = 0;
          delay(2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Toplam Paraniz:");
          lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");


  }
  else if (durum50Krs <= 400) {
    lcd.setBacklight(HIGH);
    backlightLcd = 1;
    Serial.println("50 Kuruş atıldı.");
    toplampara = toplampara + 0.5;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("50 Kurus atildi.");
    lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");
        count = 0;
              delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Toplam Paraniz:");
          lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");


  }
  else  if (durum25Krs <= 300) {
    lcd.setBacklight(HIGH);
    backlightLcd = 1;
    Serial.println("25 Kuruş atıldı.");
    toplampara = toplampara + 0.25;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("25 Kurus atildi.");
    lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");
        count = 0;
              delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Toplam Paraniz:");
          lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");


  }
  else  if (durum10Krs <= 400) {
    lcd.setBacklight(HIGH);
    backlightLcd = 1;
    Serial.println("10 Kuruş atıldı.");
    toplampara = toplampara + 0.10;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("10 Kurus atildi.");
    lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");
    count = 0;
              delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Toplam Paraniz:");
          lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");

  }
  else  if (durum5Krs <= 400) {
    lcd.setBacklight(HIGH);
    backlightLcd = 1;
    Serial.println("5 Kuruş atıldı.");
    toplampara = toplampara + 0.05;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("5 Kurus atildi.");
    lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");
    count = 0;
              delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Toplam Paraniz:");
          lcd.setCursor(0, 1);
    lcd.print(toplampara);
    lcd.print("TL");

  }
  else {
    count++;
    delay(10);
  }

  if (count > 3000)
  { lcd.setBacklight(LOW);
    backlightLcd = 0;
    count = 0;
  }

}



