const int rood = 11;
const int button = 8;

int count = 0;
int buttonstate = 0;
int lastbuttonstate = 0;
int buttonpresscount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rood, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() 
{
  buttonpress();
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

void buttonpress()
{
  buttonstate = !debounce(button);
  if (buttonstate != lastbuttonstate) 
  {
    if (buttonstate == HIGH)
    {
      buttonpresscount++;
      Serial.println(buttonpresscount);
    }
    lastbuttonstate = buttonstate;
  }
}
