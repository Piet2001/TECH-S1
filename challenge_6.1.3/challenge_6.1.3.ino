const int rood = 11;
const int button = 8;
const int fadedelay = 50;

int buttonstate = 0;
int lastbuttonstate = 0;
int count = 0;
int ledaan = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(rood, OUTPUT); 
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
 buttonstate = !debounce(button);
  if(buttonstate != lastbuttonstate){
    if(buttonstate == HIGH)
      {
        count++;
        Serial.println(count);
        while(count == 3)
        {
          if(ledaan == 0)
          {
            digitalWrite(rood,HIGH);
            count = 0;
            ledaan = 1;
          }
          else
          {
            digitalWrite(rood,LOW);
            count = 0;
            ledaan = 0;
          }
        }
      } 
    }
    lastbuttonstate = buttonstate;

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
