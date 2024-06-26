#define MOTOR_PIN_A_1 2
#define MOTOR_PIN_A_2 3
#define SPEED_PIN_A 5
#define MOTOR_PIN_B_1 7
#define MOTOR_PIN_B_2 8
#define SPEED_PIN_B 9
#include <SoftwareSerial.h>

// Define Bluetooth communication pins
SoftwareSerial bluetooth(0, 1); // RX, TX
short motorSpeed = 255;

void setup() {
  pinMode(MOTOR_PIN_A_1, OUTPUT);
  pinMode(MOTOR_PIN_A_2, OUTPUT);
  pinMode(SPEED_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B_1, OUTPUT);
  pinMode(MOTOR_PIN_B_2, OUTPUT);
  pinMode(SPEED_PIN_B, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);
}

// MOTOR A

void moveMotorAForward() {
  digitalWrite(MOTOR_PIN_A_1, HIGH);
  digitalWrite(MOTOR_PIN_A_2, LOW);
  analogWrite(SPEED_PIN_A, motorSpeed);
}

void moveMotorABackwards() {
  digitalWrite(MOTOR_PIN_A_1, LOW);
  digitalWrite(MOTOR_PIN_A_2, HIGH);
  analogWrite(SPEED_PIN_A, motorSpeed);
}

void stopMotorA() {
  digitalWrite(MOTOR_PIN_A_1, LOW);
  digitalWrite(MOTOR_PIN_A_2, LOW);
  analogWrite(SPEED_PIN_A, motorSpeed);
}

// MOTOR B

void moveMotorBForward() {
  digitalWrite(MOTOR_PIN_B_1, HIGH);
  digitalWrite(MOTOR_PIN_B_2, LOW);
  analogWrite(SPEED_PIN_B, motorSpeed);
}

void moveMotorBBackwards() {
  digitalWrite(MOTOR_PIN_B_1, LOW);
  digitalWrite(MOTOR_PIN_B_2, HIGH);
  analogWrite(SPEED_PIN_B, motorSpeed);
}

void stopMotorB() {
  digitalWrite(MOTOR_PIN_B_1, LOW);
  digitalWrite(MOTOR_PIN_B_2, LOW);
  analogWrite(SPEED_PIN_B, motorSpeed);
}

// MOTOR A and B

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

void setMotorSpeed(short speed) {
  motorSpeed = speed;
}

void loop() {
  if (bluetooth.available()) {
    char data = bluetooth.read();
    Serial.println(data);

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