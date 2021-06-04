#include <Servo.h>

int bacaan1,bacaan2,bacaan3,bacaan4,bacaan5,bacaan6;
int servo1Pos,servo2Pos,servo3Pos,servo4Pos,servo5Pos,servo6Pos;
int servo1PPos,servo2PPos,servo3PPos,servo4PPos,servo5PPos,servo6PPos;

int currentMillis = 0;
int previousMillis = 0;
int interval = 1000;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {
  Serial.begin(115200); 
  
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);

  servo1PPos = 90;
  servo1.write(servo1PPos);
  servo2PPos = 90;
  servo2.write(servo2PPos);
  servo3PPos = 90;
  servo3.write(servo3PPos);
  servo4PPos = 90;
  servo4.write(servo4PPos);
  servo5PPos = 90;
  servo5.write(servo5PPos);
  servo6PPos = 90;
  servo6.write(servo6PPos);
  
} 
void loop(){
  
  Serial.print(servo1PPos);
  Serial.print(",");
  Serial.print(servo2PPos);
  Serial.print(",");
  Serial.print(servo3PPos);
  Serial.print(",");
  Serial.print(servo4PPos);
  Serial.print(",");
  Serial.print(servo5PPos);
  Serial.print(",");
  Serial.println(servo6PPos);
}
