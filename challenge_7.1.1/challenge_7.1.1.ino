const int rood = 11;
const int button = 8;

int count = 0;
int buttonstate = 0;
int lastbuttonstate = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rood, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  buttonstate = !debounce(button);
  if (buttonstate != lastbuttonstate) {
    if (buttonstate == HIGH)
    {
      Serial.println("start");
      for (int i = 0; i < 3; i++)
      {
        Serial.println(i);
        digitalWrite(rood, HIGH);
        delay(1000);
        digitalWrite(rood, LOW);
        delay(1000);
      }
    }
    lastbuttonstate = buttonstate;
  }
}

boolean debounce(int pin)
{
  boolean state;
  boolean previousState;
  previousState = digitalRead(pin);
  for (int counter = 0; counter < 10; counter++)
  {
    delay(1); //wait 1 millisecond
    state = digitalRead(pin); //read the pin
    if (state != previousState)
    {
      counter = 0; //reset the counter
      previousState = state;
    }
  }
  return state;
}
