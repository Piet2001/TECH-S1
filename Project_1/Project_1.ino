int ledrood=12;
int ledgeel=10;
int ledgroen=8;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledrood, OUTPUT);
  pinMode(ledgeel, OUTPUT);
  pinMode(ledgroen, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledrood, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledgroen, LOW);
  delay(500);                       // wait for a second
  digitalWrite(ledrood, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgeel, HIGH);
  delay(500);                       // wait for a second
  digitalWrite(ledgeel, LOW);
  digitalWrite(ledgroen, HIGH);
  delay(500);
}
