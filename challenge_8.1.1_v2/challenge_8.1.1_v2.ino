const int rood = 11;
const int green = 10;
const int button[3] = {8, 7, 6};
const int officalcode[4] = {3, 1, 1, 2};

int buttonstate1 = 0;
int lastbuttonstate1 = 0;
int buttonstate2 = 0;
int lastbuttonstate2 = 0;
int buttonstate3 = 0;
int lastbuttonstate3 = 0;
int count = 0;
int correct = 0;
int code[4] = {0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rood, OUTPUT);
  pinMode(green, OUTPUT);
  for (int i = 0; i < 3; i++)
  {
    pinMode(button[i], INPUT_PULLUP);
  }
  Serial.println("Voer code in");
  digitalWrite(rood, HIGH);
}

void loop()
{
  while (count < 4)
  {
    buttonpress();
  }
  if (count == 4)
  {
    check();
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

void buttonpress()
{
  buttonstate1 = !debounce(button[0]);
  if (buttonstate1 != lastbuttonstate1)
  {
    if (buttonstate1 == HIGH)
    {
      code[count] = 1;
      Serial.print("1");
      count++;
    }
    lastbuttonstate1 = buttonstate1;
  }
  buttonstate2 = !debounce(button[1]);
  if (buttonstate2 != lastbuttonstate2)
  {
    if (buttonstate2 == HIGH)
    {
      code[count] = 2;
      Serial.print("2");
      count++;
    }
    lastbuttonstate2 = buttonstate2;
  }
  buttonstate3 = !debounce(button[2]);
  if (buttonstate3 != lastbuttonstate3)
  {
    if (buttonstate3 == HIGH)
    {
      code[count] = 3;
      Serial.print("3");
      count++;
    }
    lastbuttonstate3 = buttonstate3;
  }
}

void check()
{
  Serial.println();
  Serial.println("Code ingevoerd");
  Serial.print("Checking.");
  for (int p = 0; p < 6; p++)
  {
    delay(500);
    Serial.print(".");
  }
  delay(500);
  Serial.println(".");

  for (int c = 0; c < 4; c++)
  {
    if (code[c] == officalcode[c])
    {
      correct++;
    }
  }
  if (correct == 4)
  {
    Serial.println("Kluis open");
    digitalWrite(rood, LOW);
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
    digitalWrite(rood, HIGH);
  }
  else
  {
    Serial.println("Code onjuist");
    for (int r = 0; r < 3; r++)
    {
      digitalWrite(rood, LOW);
      delay(500);
      digitalWrite(rood, HIGH);
      delay(500);
    }
  }
  count = 0;
  correct = 0;
  Serial.println("Voer code in");
}
