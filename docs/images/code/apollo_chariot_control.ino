## Arduino Control Code

#include <Servo.h>

// Motor enable pins
#define EN1 5
#define EN2 6
#define EN3 9

// Motor direction pins
#define IN1 2
#define IN2 4
#define IN3 7
#define IN4 8
#define IN5 13
#define IN6 12

Servo servo1;
Servo servo2;
Servo servo3;

void sweepServo(Servo &servo, int startAngle, int endAngle, int stepDelay) {

  if (startAngle < endAngle) {
    for (int pos = startAngle; pos <= endAngle; pos++) {
      servo.write(pos);
      delay(stepDelay);
    }
  } 
  else {
    for (int pos = startAngle; pos >= endAngle; pos--) {
      servo.write(pos);
      delay(stepDelay);
    }
  }
}

void setup() {

  servo1.attach(3);
  servo2.attach(10);
  servo3.attach(11);

  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(EN3, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  servo1.write(170);
  servo2.write(20);
  servo3.write(7);

  delay(1000);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);

  analogWrite(EN1, 80);
  analogWrite(EN2, 80);
  analogWrite(EN3, 255);

  delay(5000);

  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
  analogWrite(EN3, 0);

  delay(1000);

  sweepServo(servo1, 180, 135, 10);
  sweepServo(servo2, 10, 45, 10);
  sweepServo(servo3, 7, 45, 10);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);

  analogWrite(EN1, 80);
  analogWrite(EN2, 80);
  analogWrite(EN3, 255);

  delay(5000);

  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
  analogWrite(EN3, 0);

  delay(1000);
}
