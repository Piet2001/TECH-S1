const int buttonred = 2;     // the number of the pushbutton pin 
const int ledred =  12;       // the number of the LED pin 
const int buttongreen = 4;    // button for green led
const int ledgreen = 8;       // green led

int statered = 0;           // variable for reading the pushbutton status 
int stategreen = 0;         // status for the button of the green led
 
void setup() 
{
    pinMode(ledred, OUTPUT);   
    pinMode(buttonred, INPUT_PULLUP); 
    pinMode(ledgreen, OUTPUT);
    pinMode(buttongreen, INPUT_PULLUP);
 } 
 
void loop() {
  statered = digitalRead(buttonred);
  stategreen = digitalRead(buttongreen); 
 
  if (statered == LOW) 
  {
    digitalWrite(ledred, HIGH);   
   } 
   else {
      digitalWrite(ledred, LOW);   
      }
  if (stategreen == LOW) {
    digitalWrite(ledgreen, HIGH);   
    } else {
      digitalWrite(ledgreen, LOW);   
      } 
     } 
