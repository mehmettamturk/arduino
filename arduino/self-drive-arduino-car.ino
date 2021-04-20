/**
* @author <mehmettamturk>
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Mesafe Pinleri
#define echoPin 6
#define trigPin 7

// Motor Pinleri
const int motorIN1 =  10;
const int motorIN2 =  11;
const int motorIN3 =  8;
const int motorIN4 =  9;

// Ekran Tanimlama
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor = 0;
int counter = 0;

// Led Pinleri
int pinArray[] = {2, 3, 4, 5};
int timer = 50;

void setup() {
//  lcd.init();                     
//  lcd.backlight();
//  lcd.print("   34 MT 1989   ");

  // Mesafe Pinleri
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);

  // Motor Pinleri
  pinMode(motorIN1, OUTPUT);  
  pinMode(motorIN2, OUTPUT);
  pinMode(motorIN3, OUTPUT);  
  pinMode(motorIN4, OUTPUT);

  // Led Pinleri
//  for (int count=0;count<4;count++) {
//    pinMode(pinArray[count], OUTPUT);
//  }

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readString();
    Serial.println(str);
    if(str.indexOf("w") > -1) {
      Serial.println("ileriii!!!");
      ileri(0);
    } else if (str.indexOf("s") > -1) {
      Serial.println("geriiii!!!");
      geri(0);
    } else if (str.indexOf("a") > -1) {
      Serial.println("solaaaa");
      sol(0);
    } else if (str.indexOf("d") > -1) {
      Serial.println("sagaaa");
      sag(0);
    } else {
      Serial.println("duuur");
      dur(0);
    }
    
  }
  // Mesafe Olc
//  int olcum = mesafe();
//  Serial.println(olcum);
//
//  if (olcum > 50) {
//    ileri(olcum);
//  } else if (olcum < 50) {
//    dur(olcum);
//    delay(100);
//    sag(olcum); 
//    delay(10);
//  }
//
//  int count = 0;
//  for (count=0;count<3;count++) {
//   digitalWrite(pinArray[count], HIGH);
//   delay(timer);
//   digitalWrite(pinArray[count + 1], HIGH);
//   delay(timer);
//   digitalWrite(pinArray[count], LOW);
//   delay(timer*2);
//  }
//
//  for (count=3;count>0;count--) {
//   digitalWrite(pinArray[count], HIGH);
//   delay(timer);
//   digitalWrite(pinArray[count - 1], HIGH);
//   delay(timer);
//   digitalWrite(pinArray[count], LOW);
//   delay(timer*2);
//  }

}

int mesafe() {
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);

  return distance;
}

int dur(int olcum) {
//  ekranaYaz("Dur!", String(olcum));
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2,  LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4,  LOW);
}

int ileri(int olcum) {
//  ekranaYaz("Ileri:", String(olcum));
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2,  HIGH);
  digitalWrite(motorIN3, HIGH);
  digitalWrite(motorIN4,  LOW);
}

int geri(int olcum) {
//  ekranaYaz("Geri:", String(olcum));
  digitalWrite(motorIN1, HIGH);
  digitalWrite(motorIN2,  LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4,  HIGH);
}

int sol(int olcum) {
//  ekranaYaz("Sol:", String(olcum));
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2,  HIGH);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4,  HIGH);
}

int sag(int olcum) {
//  ekranaYaz("Sag", String(olcum));
  digitalWrite(motorIN1, HIGH);
  digitalWrite(motorIN2,  LOW);
  digitalWrite(motorIN3, HIGH);
  digitalWrite(motorIN4,  LOW);
}

int mesafeYaz(int olcum) {
  lcd.setCursor(0,0);
  lcd.print("Mesafe: ");
  lcd.print(olcum);
  if (olcum < 10) {
    lcd.print("   cm");
  } else if (olcum < 100) {
    lcd.print("  cm");
  } else {
    lcd.print(" cm");
  }
}

int ekranaYaz(String data1, String data2) {
  ekraniTemizle();
  lcd.setCursor(0,0);
  lcd.print(data1);
  lcd.setCursor(0,1);
  lcd.print(data2);
}

int ekraniTemizle() {
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print("                 ");
}

/*
---------------

Ekran:

GND --> GND
VNC --> 5 Volt
SDA --> A4
SCL --> A5

---------------

Mesafe Olcer:

VCC --> 5 Volt
Trig--> 7
Echo--> 6
GND --> GND

---------------

MotorBoard

IN1 --> 8
IN2 --> 9
IN3 --> 10
IN4 --> 11
GND --> GND

---------------

Ledler

LED1 --> 2
LED2 --> 3
LED3 --> 4
LED4 --> 5

*/