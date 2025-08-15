#include <SoftwareSerial.h>

// Définir les broches moteurs
int enA = 11;
int in1 = 12;
int in2 = 13;

int enB = 10;
int in3 = 8;
int in4 = 7;

// Créer une liaison série logicielle pour Bluetooth
SoftwareSerial bluetooth(2, 3); // RX, TX

void setup() {
  // Initialiser les moteurs
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);

  // Initialiser la communication série
  bluetooth.begin(9600);
  Serial.begin(9600); // Facultatif, pour debug via USB

  stopMotors();
}

void loop() {
  if (bluetooth.available()) {
    char cmd = bluetooth.read();
    Serial.println(cmd); // Debug facultatif

    switch (cmd) {
      case 'f': forward(); break;
      case 'b': backward(); break;
      case 'l': turnLeft(); break;
      case 'r': turnRight(); break;
      case 's': stopMotors(); break;
    }
  }
}

void forward() {
  digitalWrite(in1, LOW ); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  analogWrite(enA, 255); analogWrite(enB, 255);
}

void backward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 255); analogWrite(enB, 255);
}

void turnLeft() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enA, 200); analogWrite(enB, 200);
}

void turnRight() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  analogWrite(enA, 200); analogWrite(enB, 200);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}