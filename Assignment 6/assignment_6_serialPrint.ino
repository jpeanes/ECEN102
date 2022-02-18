// ECEN102 assignment 6, printing to the serial monitor
// Prints potentiometer value from analog pin 0 to serial
// Joshua Eanes, 2/18/2022 NCAT

#include <math.h>

int oldVal = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial){
    ;
  }
}

void loop() {
  int potVal = analogRead(A0);
  if (potVal > (oldVal + 5) || potVal < (oldVal - 5)){
    Serial.println(potVal);
  }
  oldVal = potVal;
  delay(10);
}
