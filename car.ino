#include <SoftwareSerial.h>

#define motR1 4       // Правый мотор.
#define motR2 5
#define motL1 6        // Левый мотор.
#define motL2 7

SoftwareSerial mySerial(0, 1); // RX, TX

int speed = 250;
char message = 's';

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode (motR1, OUTPUT);
  pinMode (motR2, OUTPUT);
  pinMode (motL1, OUTPUT);
  pinMode (motL2, OUTPUT);
}

void loop() {
  if (mySerial.available() > 0) {
    char message = (char)mySerial.read();
    Serial.write(message);

    if (message == 'f') {
      forward();
    }
    else if (message == 'b') {
      backward();
    }
    else if (message == 'r') {
      rotate_right();
    }
    else if (message == 'l') {
      rotate_left();
    }
    else if (message == 's') {
      stop();
    }
  }
}

void forward() {
  digitalWrite (motL2, HIGH);
  analogWrite (motL1, speed);
  digitalWrite (motR1, HIGH);
  analogWrite (motR2, speed);
}
void backward() {
  digitalWrite (motL2, LOW);
  analogWrite (motL1, speed);
  digitalWrite (motR1, LOW);
  analogWrite (motR2, speed);
}
void rotate_right() {
  digitalWrite (motL2, HIGH);
  analogWrite (motL1, speed);
  digitalWrite (motR1, LOW);
  analogWrite (motR2, speed);
}
void rotate_left() {
  digitalWrite (motL2, HIGH);
  analogWrite (motL1, 150);
  digitalWrite (motR1, HIGH);
  analogWrite (motR2, speed);
}
void stop() {
  analogWrite(motL1, 0);
  analogWrite(motR2, 0);
}
