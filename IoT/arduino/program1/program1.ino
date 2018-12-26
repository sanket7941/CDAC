void setup() {
  pinMode(16, OUTPUT); // D0: RED
  pinMode(5, OUTPUT);  // D1: YELLOW
}

void loop() {
  digitalWrite(16, HIGH);
  delay(1000);

  digitalWrite(5, HIGH);
  delay(1000);

  digitalWrite(16, LOW);
  delay(1000);

  digitalWrite(5, LOW);
  delay(1000);

}
