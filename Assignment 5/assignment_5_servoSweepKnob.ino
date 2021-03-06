// Arduino servo control with potentiometer
// Joshua Eanes for NCAT ECEN102
#include <Servo.h>

Servo servo;

int potPin = A0;  // potentiometer pin
int potVal = 0; // potentiometer value
int oldPotVal = 0;  //
int servoPin = 9; // servo pin
int servoPos = 0; // servo initial position
int switchPin = 8;  // switch pin for two different modes, held low
bool switchState;  // switch on or off
int t = 15; // time in ms, for delay

void setup() {
  Serial.begin(115200);
  servo.attach(servoPin); // initialize servo
  pinMode(switchPin, INPUT);  // initialize switch input
}

void loop() {
  switchState = digitalRead(switchPin); // get the switch state
  Serial.println(switchState); 
  // knob mode
  if (switchState){
    potVal = analogRead(potPin);                 // get pot value
    Serial.println(potVal);                 // print pot val to serial
    potVal = map(potVal, 0, 1023, 0, 180);  // set servo boundaries in relation to 10k pot
    servo.write(potVal);                   // move servo
    delay(t);
  }
  // sweep mode
  else{    
    for (servoPos = 0; servoPos <= 180; servoPos ++) { // move towards pi
      servo.write(servoPos);
      delay(t);
      if (switchState){ // don't wait for loop to finish to switch modes
        break;
      }
    }
    for (servoPos = 180; servoPos >= 0; servoPos --) { // move away from pi
      servo.write(servoPos);
      delay(t);
      if (switchState){
        break;
      }      
    }
  }  
}
