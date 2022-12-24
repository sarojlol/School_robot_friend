#include <Arduino.h>
#include <pin_define.h>
#include <motor.h>

void Forward() //เดินหน้า ขา 4,7,8,12
{
  digitalWrite(M_IN1, HIGH);   digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN2, LOW);    digitalWrite(M_IN4, LOW);
  analogWrite (M_ENA, 255);    analogWrite (M_ENB, 255);//ปรับความเร็วได้ 0-255
}
void Backward() //ถอยหลัง
{
  digitalWrite(M_IN1, LOW);     digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN2, HIGH);    digitalWrite(M_IN4, HIGH);
  analogWrite (M_ENA, 255);     analogWrite (M_ENB, 255);//ปรับความเร็วได้ 0-255 
}
void Turn_Left() //เลี้ยวซ้าย
{
  digitalWrite(M_IN1, LOW);     digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN2, LOW);     digitalWrite(M_IN4, LOW);
  analogWrite (M_ENA, 0);       analogWrite (M_ENB, 255);
}
void Turn_Right() //เลี้ยวขวา
{
  digitalWrite(M_IN1, HIGH);    digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN2, LOW);     digitalWrite(M_IN4, LOW);
  analogWrite (M_ENA, 255);     analogWrite (M_ENB, 0);
}
void Spin_Left() //หมุนซ้าย
{
  digitalWrite(M_IN1, LOW);     digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN2, HIGH);    digitalWrite(M_IN4, LOW);
  analogWrite (M_ENA, 255);     analogWrite (M_ENB, 255);
}
void Spin_Right() //หมุนขวา
{
  digitalWrite(M_IN1, HIGH);    digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN2, LOW);     digitalWrite(M_IN4, HIGH);
  analogWrite (M_ENA, 255);     analogWrite (M_ENB, 255); 
}
void Stop() //หยุด
{
  digitalWrite(M_IN1, LOW);     digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN2, LOW);     digitalWrite(M_IN4, LOW);
  analogWrite (M_ENA, 0);       analogWrite (M_ENB, 0);
}