// morse code arduino LED flasher
// by Joshua Eanes for NCAT ECEN102 2/2/2022
// morseSequence() switch statement from shubham_rana_77, https://www.geeksforgeeks.org/morse-code-implementation/

int t = 500; // set base time for delays, standard for morse is 1 second
int tDot = t; // time for dot
int tDash = 3*t; // time for dash 
int tInside = t; // gap between dots and dashes
int tOutside = 2*t; // gap between characters of word, standard for morse is 3 seconds
int tSpace = 5*t; // gap between words, standard for morse is 7 seconds

int led = 13; // LED_BUILTIN

// input string to be coded into morse
// letters, numbers, spaces only
String message = String("hello world");

void setup(){
  
  Serial.begin(115200);
  delay(2000);
  
  pinMode(led, OUTPUT);
  
  if (message == ""){
    Serial.println("Nothing to say?");
    for (int k = 0; k < 20; k++){
      digitalWrite(led, HIGH);
      delay(250);
      digitalWrite(led, LOW);
      delay(250);            
    }
    exit(0);
  }
  else {
    Serial.println("Begin morse code translation");
    Serial.println("Translate \"" + message + "\" to morse:\n");     
    message.replace(" " , "/"); // don't like spaces
    //Serial.println("appended: " + message);
  }
}

void loop(){
  
  Serial.println("BEGIN MESSAGE");
  
  digitalWrite(led, LOW);
  
  for (int i = 0; i < message.length(); i++){  // iterate through "message"
    //Serial.println(message[i]);

    String sequence = morseSequence(tolower(message[i])); // pass lowercase char from message into morseSequence(), return "sequence"
    
    for (int j = 0; j < sequence.length(); j++){ // iterate through sequence
      char target = sequence[j];  // assign characters in sequence to variable "target"

      // handle blinking and timing
      Serial.print(target);
      switch (target){       
      // action for dot
      case '.':
        digitalWrite(led, HIGH);
        delay(tDot);
        digitalWrite(led, LOW);
        delay(tInside);
        break;   
      // action for dash
      case '-': 
        digitalWrite(led, HIGH);
        delay(tDash);
        digitalWrite(led, LOW);
        delay(tInside);
        break;
      case '/':
        delay(tSpace);
        break;
      default:            
        Serial.println("ERROR - INVALID CHARACTER");  // handle bad input
        for (int k = 0; k < 10; k++){
          digitalWrite(led, HIGH);
          delay(250);
          digitalWrite(led, LOW);
          delay(250);
          break;
        }
      }
    }
    delay(tOutside);
    Serial.println();
  }
  Serial.println("\nEND OF MESSAGE");
  Serial.println("---------------");
  delay(5000);
}

// pass char, return string of morse sequence
String morseSequence(char x){
    switch (x){
    case 'a':
        return ".-";
    case 'b':
        return "-...";
    case 'c':
        return "-.-.";
    case 'd':
        return "-..";
    case 'e':
        return ".";
    case 'f':
        return "..-.";
    case 'g':
        return "--.";
    case 'h':
        return "....";
    case 'i':
        return "..";
    case 'j':
        return ".---";
    case 'k':
        return "-.-";
    case 'l':
        return ".-..";
    case 'm':
        return "--";
    case 'n':
        return "-.";
    case 'o':
        return "---";
    case 'p':
        return ".--.";
    case 'q':
        return "--.-";
    case 'r':
        return ".-.";
    case 's':
        return "...";
    case 't':
        return "-";
    case 'u':
        return "..-";
    case 'v':
        return "...-";
    case 'w':
        return ".--";
    case 'x':
        return "-..-";
    case 'y':
        return "-.--";
    case 'z':
        return "--..";
    case '1':
        return ".----";
    case '2':
        return "..---";
    case '3':
        return "...--";
    case '4':
        return "....-";
    case '5':
        return ".....";
    case '6':
        return "-....";
    case '7':
        return "--...";
    case '8':
        return "---..";
    case '9':
        return "----.";
    case '0':
        return "-----";
    case '/':
        return "/";
    default:
        exit(0);
    }
}

// this took way too long and it technically doesn't do what the professor asked for it to do
