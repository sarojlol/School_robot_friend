#include <Arduino.h>
#include <pin_define.h>
#include <motor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);

char rev_char;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(M_IN1, OUTPUT);
  pinMode(M_IN2, OUTPUT);
  pinMode(M_IN3, OUTPUT);
  pinMode(M_IN4, OUTPUT);
  pinMode(M_ENA, OUTPUT);
  pinMode(M_ENB, OUTPUT);

  pinMode(fan, OUTPUT);
  analogWrite(fan, 255);
  analogWrite(M_ENA, 0);
  analogWrite(M_ENB, 0);
}

void loop() {
  if(bluetooth.available()){
    rev_char = bluetooth.read();
    switch (rev_char)
    {
    case 'F': //เดิเหน้า
      Forward();
      break;
    case 'G'://ถอยหลัง
      Backward();
      break;
    case 'Q'://เลี้ยวซ้าย
      Turn_Left();
      break;
    case 'E'://เลี้ยวขวา
      Turn_Right();
      break;
    case 'L'://หมุนซ้าย
      Spin_Left();
      break;
    case 'R'://หมุนขวา
      Spin_Right();
      break;
    case 'S'://หยุด
      Stop();
      break;
    case 'M'://เปิดพัดลม
      analogWrite(fan, 0);
      break;
    case 'm'://ปิดพัดลม
      analogWrite(fan, 255);
      break;
    }
  }
}