#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

int bacaan1,bacaan2,bacaan3,bacaan4,bacaan5,bacaan6;
int servo1Pos,servo2Pos,servo3Pos,servo4Pos,servo5Pos,servo6Pos;
int servo1PPos,servo2PPos,servo3PPos,servo4PPos,servo5PPos,servo6PPos;
int servo1save,servo2save,servo3save,servo4save,servo5save,servo6save;

//Pin Motor
const int kiri_depan0 = 16;
const int kiri_depan1 = 17;
const int kanan_depan0 = 20;
const int kanan_depan1 = 21;
const int kiri_belakang0 = 14;
const int kiri_belakang1 = 15;
const int kanan_belakang0 = 18;
const int kanan_belakang1 = 19;

const byte interruptPin = 2;
int switch_pin = 13;
int mode;

const int delta = 10;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

ros::NodeHandle  nh;

int limiter(int angle){
  if(angle >= 180){
    angle = 180;
  }else if(angle <= 0){
    angle = 0;
  }
  return angle;
}

void maju(){
  digitalWrite(kiri_depan0, HIGH);
  digitalWrite(kiri_depan1, LOW);  
  digitalWrite(kanan_depan0, HIGH);
  digitalWrite(kanan_depan1, LOW);
  digitalWrite(kiri_belakang0, HIGH);
  digitalWrite(kiri_belakang1, LOW);  
  digitalWrite(kanan_belakang0, HIGH);
  digitalWrite(kanan_belakang1, LOW); 
}

void mundur(){
  digitalWrite(kiri_depan0, LOW);
  digitalWrite(kiri_depan1, HIGH);  
  digitalWrite(kanan_depan0, LOW);
  digitalWrite(kanan_depan1, HIGH);
  digitalWrite(kiri_belakang0, LOW);
  digitalWrite(kiri_belakang1, HIGH);  
  digitalWrite(kanan_belakang0, LOW);
  digitalWrite(kanan_belakang1, HIGH); 
}

void belok_kanan(){
  digitalWrite(kiri_depan0, HIGH);
  digitalWrite(kiri_depan1, LOW);  
  digitalWrite(kiri_belakang0, HIGH);
  digitalWrite(kiri_belakang1, LOW);
}

void belok_kiri(){
  digitalWrite(kanan_depan0, HIGH);
  digitalWrite(kanan_depan1, LOW);  
  digitalWrite(kanan_belakang0, HIGH);
  digitalWrite(kanan_belakang1, LOW);   
}

void diam(){
  digitalWrite(kanan_depan0, LOW);
  digitalWrite(kanan_depan1, LOW);  
  digitalWrite(kanan_belakang0, LOW);
  digitalWrite(kanan_belakang1, LOW);
  digitalWrite(kiri_depan0, LOW);
  digitalWrite(kiri_depan1, LOW);  
  digitalWrite(kiri_belakang0, LOW);
  digitalWrite(kiri_belakang1, LOW);
}

void simpan(){
  servo1save = servo1Pos;
  servo2save = servo2Pos;
  servo3save = servo3Pos;
  servo4save = servo4Pos;
  servo5save = servo5Pos;
  servo6save = servo6Pos;
}

void gerak(){
  servo1.write(servo1save);
  servo2.write(servo2save);
  servo3.write(servo3save);
  servo4.write(servo4save);
  servo5.write(servo5save);
  servo6.write(servo6save);
}



void servo_cb( const std_msgs::UInt16& cmd_msg){
  if(cmd_msg.data == 0){
    servo1Pos = servo1PPos + delta;
    servo1Pos = limiter(servo1Pos);
    servo1.write(servo1Pos);
    servo1PPos = servo1Pos;
  }
  else if(cmd_msg.data == 1){
    servo1Pos = servo1PPos - delta;
    servo1Pos = limiter(servo1Pos);
    servo1.write(servo1Pos);
    servo1PPos = servo1Pos;
  }
  else if(cmd_msg.data == 2){
    servo2Pos = servo2PPos + delta;
    servo2Pos = limiter(servo2Pos);
    servo2.write(servo2Pos);
    servo2PPos = servo2Pos;
  }
  else if(cmd_msg.data == 3){
    servo2Pos = servo2PPos - delta;
    servo2Pos = limiter(servo2Pos);
    servo2.write(servo2Pos);
    servo2PPos = servo2Pos;
  }
  else if(cmd_msg.data == 4){
    servo3Pos = servo3PPos + delta;
    servo3Pos = limiter(servo3Pos);
    servo3.write(servo3Pos);
    servo3PPos = servo3Pos;
  }
  else if(cmd_msg.data == 5){
    servo3Pos = servo3PPos - delta;
    servo3Pos = limiter(servo3Pos);
    servo3.write(servo3Pos);
    servo3PPos = servo3Pos;
  }
  else if(cmd_msg.data == 6){
    servo4Pos = servo4PPos + delta;
    servo4Pos = limiter(servo4Pos);
    servo4.write(servo4Pos);
    servo4PPos = servo4Pos;
  }
  else if(cmd_msg.data == 7){
    servo4Pos = servo4PPos - delta;
    servo4Pos = limiter(servo4Pos);
    servo4.write(servo4Pos);
    servo4PPos = servo4Pos;
  }
  else if(cmd_msg.data == 8){
    servo5Pos = servo5PPos + delta;
    servo5Pos = limiter(servo5Pos);
    servo5.write(servo5Pos);
    servo5PPos = servo5Pos;
  }
  else if(cmd_msg.data == 9){
    servo5Pos = servo5PPos - delta;
    servo5Pos = limiter(servo5Pos);
    servo5.write(servo5Pos);
    servo5PPos = servo5Pos;
  }
  else if(cmd_msg.data == 10){
    servo6Pos = servo6PPos + delta;
    servo6Pos = limiter(servo6Pos);
    servo6.write(servo6Pos);
    servo6PPos = servo6Pos;
  }
  else if(cmd_msg.data == 11){
    servo6Pos = servo6PPos - delta;
    servo6Pos = limiter(servo6Pos);
    servo6.write(servo6Pos);
    servo6PPos = servo6Pos;
  }
  else if(cmd_msg.data == 12){
    maju();
  }
  else if(cmd_msg.data == 13){
    mundur();
  }
  else if(cmd_msg.data == 14){
    belok_kiri();
  }
  else if(cmd_msg.data == 15){
    belok_kanan();
  }
  else if(cmd_msg.data == 16){
    gerak();
  }
  else if(cmd_msg.data == 17){
    diam();
  }
}

void manual(){
  //Servo1
  bacaan1 = analogRead(A0);
  bacaan1 = map(bacaan1, 0, 1023, 0, 180);
  servo1Pos = bacaan1; 
  if (servo1PPos > servo1Pos) {
    for ( int j = servo1PPos; j >= servo1Pos; j--){
      servo1.write(j);
      delay(20);
    }
  }
  if (servo1PPos < servo1Pos) {
    for ( int j = servo1PPos; j <= servo1Pos; j++) {
      servo1.write(j);
      delay(20);
    }
  }
  servo1PPos = servo1Pos;

  //Servo2
  bacaan2 = analogRead(A1);
  bacaan2 = map(bacaan2, 0, 1023, 0, 180);
  servo2Pos = bacaan2; 
  if (servo2PPos > servo2Pos) {
    for ( int j = servo2PPos; j >= servo2Pos; j--){
      servo2.write(j);
      delay(20);
    }
  }
  if (servo2PPos < servo2Pos) {
    for ( int j = servo2PPos; j <= servo2Pos; j++) {
      servo2.write(j);
      delay(20);
    }
  }
  servo2PPos = servo2Pos;

  //Servo3
  bacaan3 = analogRead(A2);
  bacaan3 = map(bacaan3, 0, 1023, 0, 180);
  servo3Pos = bacaan3; 
  if (servo3PPos > servo3Pos) {
    for ( int j = servo3PPos; j >= servo3Pos; j--){
      servo3.write(j);
      delay(20);
    }
  }
  if (servo3PPos < servo3Pos) {
    for ( int j = servo3PPos; j <= servo3Pos; j++) {
      servo3.write(j);
      delay(20);
    }
  }
  servo3PPos = servo3Pos;

  //Servo4
  bacaan4 = analogRead(A3);
  bacaan4 = map(bacaan4, 0, 1023, 0, 180);
  servo4Pos = bacaan4; 
  if (servo4PPos > servo4Pos) {
    for ( int j = servo4PPos; j >= servo4Pos; j--){
      servo4.write(j);
      delay(20);
    }
  }
  if (servo4PPos < servo4Pos) {
    for ( int j = servo4PPos; j <= servo4Pos; j++) {
      servo4.write(j);
      delay(20);
    }
  }
  servo4PPos = servo4Pos;

  //Servo5
  bacaan5 = analogRead(A4);
  bacaan5 = map(bacaan5, 0, 1023, 0, 180);
  servo5Pos = bacaan5; 
  if (servo5PPos > servo5Pos) {
    for ( int j = servo5PPos; j >= servo5Pos; j--){
      servo5.write(j);
      delay(20);
    }
  }
  if (servo5PPos < servo5Pos) {
    for ( int j = servo5PPos; j <= servo5Pos; j++) {
      servo5.write(j);
      delay(20);
    }
  }
  servo5PPos = servo5Pos;

  //Servo6
  bacaan6 = analogRead(A5);
  bacaan6 = map(bacaan6, 0, 1023, 0, 180);
  servo6Pos = bacaan6; 
  if (servo6PPos > servo6Pos) {
    for ( int j = servo6PPos; j >= servo6Pos; j--){
      servo6.write(j);
      delay(20);
    }
  }
  if (servo6PPos < servo6Pos) {
    for ( int j = servo6PPos; j <= servo6Pos; j++) {
      servo6.write(j);
      delay(20);
    }
  }
  servo6PPos = servo6Pos;
}

ros::Subscriber<std_msgs::UInt16> sub("joycontrol", servo_cb);

void setup(){
  Serial.begin(57600);

  pinMode(switch_pin, OUTPUT);

  pinMode(kiri_depan0,OUTPUT);
  pinMode(kiri_depan1,OUTPUT);
  pinMode(kanan_depan0,OUTPUT);
  pinMode(kanan_depan1,OUTPUT);
  pinMode(kiri_belakang0,OUTPUT);
  pinMode(kiri_belakang1,OUTPUT);
  pinMode(kanan_belakang0,OUTPUT);
  pinMode(kanan_belakang1,OUTPUT);
  
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);

  servo1PPos = 90;
  servo1.write(servo1PPos);
  servo2PPos = 130;
  servo2.write(servo2PPos);
  servo3PPos = 90;
  servo3.write(servo3PPos);
  servo4PPos = 180;
  servo4.write(servo4PPos);
  servo5PPos = 90;
  servo5.write(servo5PPos);
  servo6PPos = 90;
  servo6.write(servo6PPos);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), simpan, RISING);
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  mode = digitalRead(switch_pin);
  if(mode == HIGH){
    nh.spinOnce();
    delay(1);
  }else if(mode == LOW){
    manual();
  }
}
