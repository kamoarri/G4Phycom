#include <Servo.h>

#define SENSOR_PIN A0           // pin de sensor emg
#define LED_PIN 13              // pin de LED
#define SERVO_THUMB_PIN 9       // pin de servo para pulgar
#define SERVO_FINGERS_PIN 8     // pin de servo para dedos
#define SERVO_THUMB_ANGLE 45    // angulo del servo del pulgar cuando se active
#define SERVO_FINGERS_ANGLE 45  // angulo del servo para dedos cuando se active
#define THRESHOLD 90            // valor umbral al cual se abrirá o cerrará la mano

Servo thumb;
Servo fingers;

int sensorValue = 0;  // lectura de sensor emg

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  fingers.attach(SERVO_FINGERS_PIN);
  thumb.attach(SERVO_THUMB_PIN);
}

void loop() {

  sensorValue = analogRead(SENSOR_PIN);
  Serial.println(sensorValue);
  
  if (sensorValue < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    for (int posThumb = 0; posThumb <= SERVO_THUMB_ANGLE; posThumb += 1) {
      thumb.write(posThumb);
      delay(15);
    }
    for (int posFingers = 0; posFingers <= SERVO_FINGERS_ANGLE; posFingers += 1) {
      thumb.write(posFingers);
      delay(15);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    thumb.write(0);
    fingers.write(0);
  }
  delay(100);
}