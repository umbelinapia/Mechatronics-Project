#include <ESP32Servo.h>
#define PUL 1
#define DIR 2
Servo myservo;
int pos = 0; 

void setup() {
  // put your setup code here, to run once:
  
  pinMode(PUL, OUTPUT);
  pinMode(DIR, OUTPUT);
  myservo.attach(4);

}

void loop() {
  // put your main code here, to run repeatedly:
  //direction LOW is Clockwise
  //direction HIGH is Anti-clockwise
  digitalWrite(DIR, LOW);

  //pulse is the control signal
  digitalWrite(PUL, HIGH);
  delayMicroseconds(1000);
  digitalWrite(PUL, LOW);
  delayMicroseconds(1000);

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }

}
