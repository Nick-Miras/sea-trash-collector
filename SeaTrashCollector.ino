#define MOTOR_PIN_A_1 2
#define MOTOR_PIN_A_2 3
#define ENABLE_PIN_A 5
#define MOTOR_PIN_B_1 7
#define MOTOR_PIN_B_2 8
#define ENABLE_PIN_B 9
#include <SoftwareSerial.h>

// Define Bluetooth communication pins
SoftwareSerial bluetooth(0, 1); // RX, TX

void setup() {
  pinMode(MOTOR_PIN_A_1, OUTPUT);
  pinMode(MOTOR_PIN_A_2, OUTPUT);
  pinMode(ENABLE_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B_1, OUTPUT);
  pinMode(MOTOR_PIN_B_2, OUTPUT);
  pinMode(ENABLE_PIN_B, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);
}

// MOTOR A

void moveMotorAForward() {
  digitalWrite(MOTOR_PIN_A_1, HIGH);
  digitalWrite(MOTOR_PIN_A_2, LOW);
  analogWrite(ENABLE_PIN_A, 255);
}

void moveMotorABackwards() {
  digitalWrite(MOTOR_PIN_A_1, LOW);
  digitalWrite(MOTOR_PIN_A_2, HIGH);
  analogWrite(ENABLE_PIN_A, 255);
}

void stopMotorA() {
  digitalWrite(MOTOR_PIN_A_1, LOW);
  digitalWrite(MOTOR_PIN_A_2, LOW);
  analogWrite(ENABLE_PIN_A, 0);
}

// MOTOR B

void moveMotorBForward() {
  digitalWrite(MOTOR_PIN_B_1, HIGH);
  digitalWrite(MOTOR_PIN_B_2, LOW);
  analogWrite(ENABLE_PIN_B, 255);
}

void moveMotorBBackwards() {
  digitalWrite(MOTOR_PIN_B_1, LOW);
  digitalWrite(MOTOR_PIN_B_2, HIGH);
  analogWrite(ENABLE_PIN_B, 255);
}

void stopMotorB() {
  digitalWrite(MOTOR_PIN_B_1, LOW);
  digitalWrite(MOTOR_PIN_B_2, LOW);
  analogWrite(ENABLE_PIN_B, 0);
}

void moveLeft() {
  moveMotorABackwards();
  moveMotorBForward();
}

void moveRight() {
  moveMotorBBackwards();
  moveMotorAForward();
}

void moveForward() {
  moveMotorAForward();
  moveMotorBForward();
}

void moveBackwards() {
  moveMotorABackwards();
  moveMotorBBackwards();
}

void stopMotors() {
  stopMotorA();
  stopMotorB();
}

void loop() {
  if (bluetooth.available()) {
    char data = bluetooth.read();

    switch (data) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackwards();
        break;
      case 'S':
        stopMotors();
        break;
      case 'L':
        moveLeft();
        break;
      case 'R':
        moveRight();
        break;
      default:
        break;
    }
  }
}