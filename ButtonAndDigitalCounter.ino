int a = 8;
int b = 9;
int c = 4;
int d = 5;
int e = 6;
int f = 2;
int g = 3;
  
bool bPress = false;
int ButtonPin = 10;

int ButtonPushCounter = 0;
int ButtonState = 0;
int LastButtonState = 0;

void setup() {

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(ButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
  displayDigit(ButtonPushCounter);

}

void loop() {
  ButtonState = digitalRead(ButtonPin);

  if(ButtonState != LastButtonState) {
    if (ButtonState == LOW) {
      bPress = true;
      ButtonPushCounter++;
      if (ButtonPushCounter > 9) ButtonPushCounter =0;
      Serial.println("on");
   }
   else {
    Serial.println("off");
   }
   delay(50);        
  }
  
  LastButtonState = ButtonState;

  if (bPress) {
    turnOff();
    displayDigit(ButtonPushCounter);         
  }

}

void displayDigit(int digit) {

if(digit != 1 && digit != 4)
digitalWrite(a, HIGH);

if(digit != 5 && digit != 6)
digitalWrite(b, HIGH);

if(digit != 2)
digitalWrite(c, HIGH);

if(digit != 1 && digit != 4 && digit != 7)
digitalWrite(d, HIGH);

if(digit == 2 || digit == 6 || digit == 8 || digit == 0)
digitalWrite(e, HIGH);

if(digit != 1 && digit != 2 && digit != 3 && digit != 7)
digitalWrite(f, HIGH);

if(digit != 0 && digit != 1 && digit != 7)
digitalWrite(g, HIGH);

}

void turnOff(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW); 
}
