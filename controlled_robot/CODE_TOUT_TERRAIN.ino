#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

char command;

const int M1F = 25;
const int M1B = 26;
const int M2F = 27;
const int M2B = 14;
const int M1SPEED = 33;
const int M2SPEED = 12;

void setup() {
  pinMode(M1F, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(M1SPEED, OUTPUT);
  pinMode(M2SPEED, OUTPUT);
  
  Serial.begin(9600);
  SerialBT.begin("ESP32_BT");
  
  Serial.println("The device started, now you can pair it with Bluetooth!");
  STOP();
      analogWrite(M1SPEED, 0);
      analogWrite(M2SPEED, 0);
}

void FWD() {
  digitalWrite(M1F, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, HIGH);
  digitalWrite(M2B, LOW);
}

void BACK() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, HIGH);
}

void RIGHT() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2F, HIGH);
  digitalWrite(M2B, LOW);
}

void LEFT() {
  digitalWrite(M1F, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, HIGH);
}

void UP_LEFT() {
  digitalWrite(M1F, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, LOW);
}

void UP_RIGHT() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, HIGH);
  digitalWrite(M2B, LOW);
}

void DOWN_LEFT() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, LOW);
}

void DOWN_RIGHT() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, HIGH);
}

void STOP() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, LOW);
}

void loop() {
  while (SerialBT.available()) {
    command = SerialBT.read();
    
    if (command == 'F') {
      FWD();
      Serial.println("FORWARD");
    } else if (command == 'B') {
      BACK();
      Serial.println("BACK");
    } else if (command == 'R') {
      RIGHT();
      Serial.println("RIGHT");
    } else if (command == 'L') {
      LEFT();
      Serial.println("LEFT");
    } else if (command == 'G') {
      UP_LEFT();
      Serial.println("UP LEFT");
    } else if (command == 'I') {
      UP_RIGHT();
      Serial.println("UP RIGHT");
    } else if (command == 'H') {
      DOWN_LEFT();
      Serial.println("DOWN LEFT");
    } else if (command == 'J') {
      DOWN_RIGHT();
      Serial.println("DOWN RIGHT");
    } else if (command >= '0' && command <= '9') {
      int speed = command - '0';
      int pwmValue = speed * 25;
      analogWrite(M1SPEED, pwmValue);
      analogWrite(M2SPEED, pwmValue);
      Serial.print("Speed set to: ");
      Serial.println(pwmValue);
    } else if (command == 'q') {
      analogWrite(M1SPEED, 255);
      analogWrite(M2SPEED, 255);
      Serial.println("Speed set to 100%");
    } else {
      STOP();
      Serial.println("STOP");
    }
  }
}
