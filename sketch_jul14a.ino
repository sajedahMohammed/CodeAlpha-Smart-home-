#include <Servo.h>

Servo door;

const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 7;
const int buzzerPin = 8;
const int servoPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);

  door.attach(servoPin);
  door.write(0);   

  Serial.begin(9600);
}

void loop() {

  int lightValue = analogRead(ldrPin);

  if (lightValue < 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  int motion = digitalRead(pirPin);

  if (motion == HIGH) {

    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);

    door.write(90);
    delay(3000);

    door.write(0);
  }

  delay(100);
}