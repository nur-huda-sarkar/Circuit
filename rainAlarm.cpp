#include <Servo.h>

const int rainSensorPin = A0; // Rain Sensor analog output
const int servoPin = 9; // Servo connected to pin 9
const int buzzerPin = 8; // Buzzer connected to pin 8

Servo myServo;

void setup() {
Serial.begin(9600);
myServo.attach(servoPin); // Attach servo to pin 9
pinMode(buzzerPin, OUTPUT); // Buzzer pin set to output
myServo.write(0); // Start with 0° position
}

void loop() {
int rainValue = analogRead(rainSensorPin);
Serial.print("Rain Sensor Value: ");
Serial.println(rainValue);

if (rainValue < 400) { // Rain detected
myServo.write(90); // Servo goes to 90°
digitalWrite(buzzerPin, HIGH); // Buzzer on
} else {
myServo.write(0); // Servo goes to 0°
digitalWrite(buzzerPin, LOW); // Buzzer off
}

delay(500);
}