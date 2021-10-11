const int rood = 12;
const int button = 8;

int buttonstate = 0;
int lastbuttonstate = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(rood, OUTPUT); 
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
 buttonstate = digitalRead(button);
  if(buttonstate != lastbuttonstate){
    if(buttonstate == HIGH)
      {
        count = 0;
        Serial.println("start");
        while(count<3)
        {
          digitalWrite(rood,HIGH);
          delay(1000);
          digitalWrite(rood,LOW);
          delay(1000);
          count++;
          Serial.println(count);
        }
      } 
    }
    lastbuttonstate = buttonstate;
  
}
