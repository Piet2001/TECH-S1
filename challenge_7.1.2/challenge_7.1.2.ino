const int rood = 11;
const int button = 8;
const int button2 = 7;

int state1 = 0;
int laststate1 = 0;
int state2 = 0;
int laststate2 = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rood, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop()
{
  state1 = !debounce(button);
  buttonpress(3, 1000, state1, laststate1);
  state2 = !debounce(button2);
  buttonpress(5, 1000, state2, laststate2);
}

void led(int aantal, int delayms)
{
  Serial.println("start");
  for (int i = 0; i < aantal; i++)
  {
    digitalWrite(rood, HIGH);
    delay(delayms);
    digitalWrite(rood, LOW);
    delay(delayms);
    Serial.println(i);
  }
}

void buttonpress(int aantal, int delayms, bool state, bool laststate)
{
  if (state != laststate)
  {
    if (state == HIGH)
    {
      led(aantal, delayms)
    }
  }
  laststate = state;
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
