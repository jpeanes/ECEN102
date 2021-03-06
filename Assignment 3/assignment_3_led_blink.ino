// ECEN102.003 Activity #3, Led blink tutorial
// Joshua Eanes 1/29/2022

// set pin variables
int green = 12; // green LED
int yellow = 11; // yellow LED
int red = 10; // red LED

int modeSelect = 8; // connect pin to change modes
int potAdj = 0; // potentiometer value


void setup() {
  // initialize serial monitor
  Serial.begin(115200);
  
  // set pin modes
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(modeSelect, INPUT);
}

void loop() {
  // get potentiometer resistance
  int potVal = analogRead(A0);
  Serial.println(potVal); // print potVal to serial
  // choose mode with switch
  bool mode = digitalRead(modeSelect);
  Serial.println(mode); // print mode to serial
  // 
  if(mode == 1){
    // blink example
    digitalWrite(green, HIGH);
    delay(potVal);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(potVal);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(potVal);
    digitalWrite(red, LOW);
  }
  else{
    // potentiometer control
    if(potVal >= 1000){
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    }
    else if(potVal < 1000 && potVal >=600){
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
    }
    else if(potVal < 600 && potVal >=400){
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
    }
    else if(potVal < 400 && potVal >=10){
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
    }
    else{
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);    
    }
  }
}
