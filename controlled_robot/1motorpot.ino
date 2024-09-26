const int M1SPEED = 33;
const int M1F = 25;
const int M1B = 26;
const int pot = 13;

int val;

void setup() {
  pinMode(M1F, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M1SPEED, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600); // Start serial communication
  analogWrite(M1SPEED, 0); // Start with motor stopped
}

void loop() {
  val = analogRead(pot);            
  val = map(val, 0, 1023, 0, 255); 

  if (val > 0) {
    digitalWrite(M1F, HIGH);  // Set direction forward
    digitalWrite(M1B, LOW);
    analogWrite(M1SPEED, val); // Set speed
  } else {
    digitalWrite(M1F, LOW); // Stop the motor if val is 0
    digitalWrite(M1B, LOW);
    analogWrite(M1SPEED, 0);
  }

  Serial.println(val); // Print the current speed value for debugging
}