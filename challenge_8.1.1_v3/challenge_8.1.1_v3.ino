const int rood = 11;
const int green = 10;
const int button[3] = {8, 7, 6};
const int officalcode[4] = {3, 1, 1, 2};
int state[3] = {0, 0, 0};
int laststate[3] = {0, 0, 0};
int count = 0;
bool correct = true;
int code[4] = {0, 0, 0, 0};
void setup()
{
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
    checkstart();
    bool correct = check();
    if(correct == true)
    {
      goed();
    }
    else
    {
      fout();
    }
    count = 0;
    Serial.println("Voer code in");
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
  for (int n = 0; n < 3; n++)
  {
    buttonpress2(n);
  }
}
void buttonpress2(int nummer)
{
  state[nummer] = !debounce(button[nummer]);
  if (state[nummer] != laststate[nummer])
  {
    if (state[nummer] == HIGH)
    {
      int invoer = nummer + 1;
      code[count] = invoer;
      Serial.print(invoer);
      count++;
    }
    laststate[nummer] = state[nummer];
  }
}
void checkstart()
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
}
bool check()
{
  int digitnr = 0;
  bool correct = true;
  while (digitnr < 4 && correct == true)
  {
    if (code[digitnr] != officalcode[digitnr])
    {
      correct = false;
    }
    digitnr++;
  }
  return correct;
}
void goed()
{
  Serial.println("Kluis open");
  digitalWrite(rood, LOW);
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  digitalWrite(rood, HIGH);
}
void fout()
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
