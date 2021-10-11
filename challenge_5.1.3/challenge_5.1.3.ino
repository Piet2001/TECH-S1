const int rood = 12;
const int geel = 11;
const int groen = 10;
const int button = 8;

int buttonstate = 0;
int lastbuttonstate = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode (rood, OUTPUT); 
  pinMode (geel, OUTPUT); 
  pinMode (groen, OUTPUT);
  pinMode (button, INPUT_PULLUP); 
}

void loop() {
  buttonstate = digitalRead(button);
    if(buttonstate != lastbuttonstate)
    {
      if(buttonstate == HIGH)
      {
        count++;
        Serial.println(count);
      }
      lastbuttonstate = buttonstate;
    }
        if(count == 1)
        { 
           digitalWrite (groen, LOW);
           digitalWrite (rood, HIGH);    
        }
        if(count == 2)
        { 
           digitalWrite (rood, LOW);
           digitalWrite (geel, HIGH);    
        }
        if(count == 3)
        { 
           digitalWrite (geel, LOW);
           digitalWrite (groen, HIGH);    
        }
        if(count == 4)
        {
          count = 1;
        }
}
