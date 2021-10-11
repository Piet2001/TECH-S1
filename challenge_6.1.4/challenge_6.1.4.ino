const int rood = 11;
const int button = 8;
const int fadedelay = 50;

int ledaan = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(rood, OUTPUT); 
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
          while(i <= 255)
          {
            analogWrite(rood, i);
            delay(fadedelay);
            Serial.println(i);
            i += 5;
          }
          while(i >= 0)
          {
            analogWrite(rood, i);
            delay(fadedelay);
            Serial.println(i);
            i -= 5;
          }
} 
