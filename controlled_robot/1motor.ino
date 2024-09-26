const int M1SPEED = 33;
const int M1F = 25;
const int M1B = 26;
int val = 255;

void setup() {
  pinMode(M1F, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M1SPEED, OUTPUT);
  Serial.begin(9600); // Start serial communication
  analogWrite(M1SPEED, 0); // Start with motor stopped
}

void loop() {
    digitalWrite(M1F, HIGH);  
    digitalWrite(M1B, LOW);
    analogWrite(M1SPEED, val); 
    delay(5000);
    digitalWrite(M1F, LOW);  
    digitalWrite(M1B, HIGH);
    analogWrite(M1SPEED, val);     
    delay(5000);
}