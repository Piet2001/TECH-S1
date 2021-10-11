const int rood = 12;
const int geel = 11;
const int groen = 10;
const int buttonled = 8;
const int buttonrichting = 2;

int buttonstateled = 0;
int lastbuttonstateled = 0;
int count = 1;
int buttonstaterichting = 0;
int lastbuttonstaterichting = 0;
int richting = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rood, OUTPUT); 
  pinMode(geel, OUTPUT); 
  pinMode(groen, OUTPUT);
  pinMode(buttonled, INPUT_PULLUP);
  pinMode(buttonrichting, INPUT_PULLUP); 
}

void loop() {
  buttonstaterichting = digitalRead(buttonrichting);
  if(buttonstaterichting != lastbuttonstaterichting){
    if(buttonstaterichting == HIGH)
    {
      if(richting == 1)
      {
        richting = 0;
        Serial.print("richting:");
        Serial.println(richting);
        delay(50);
      }
      else
      {
        richting = 1;
        Serial.print("richting:");
        Serial.println(richting);
        delay(50);
      } 
    }
    lastbuttonstaterichting = buttonstaterichting;
  }
  buttonstateled = digitalRead(buttonled);
  if(buttonstateled != lastbuttonstateled){
    if(buttonstateled == HIGH)
    {
      if(richting == 1)
      {
        count++;
        Serial.print("led:");
        Serial.println(count);
      }
      else
      {
        count--;
        Serial.print("led:");
        Serial.println(count);
      }
    }
    lastbuttonstateled = buttonstateled;
  }
        if(count == 1)
        { 
           digitalWrite (geel, LOW);
           digitalWrite (groen, LOW);
           digitalWrite (rood, HIGH); 
           delay(50);   
        }
        if(count == 2)
        { 
           digitalWrite (rood, LOW);
           digitalWrite (groen, LOW);
           digitalWrite (geel, HIGH); 
           delay(50);   
        }
        if(count == 3)
        { 
           digitalWrite (geel, LOW);
           digitalWrite (rood, LOW);
           digitalWrite (groen, HIGH); 
           delay(50);   
        }
        if(count == 4)
        {
          count = 1;
        }
        if(count == 0)
        {
          count = 3;
        }
}
