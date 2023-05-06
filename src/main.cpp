#include <Arduino.h>

String inputString = "";
bool stringComplete = false;

void setup() {
  Serial1.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);

  inputString.reserve(200);
}

void loop() {                   
  if(stringComplete){
    // for(int i=0;i<3;i++){
    //     digitalWrite(LED_BUILTIN, HIGH);
    //     delay(500);                      
    //     digitalWrite(LED_BUILTIN, LOW);
    //     delay(500);  
    // }

   // inputString.replace(':', ';');
    Serial1.println(inputString);  // only for testing directly to the PC

    inputString="";
    stringComplete = false;
  }  
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run each time just before loop() ends, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent1() { 
  while (Serial1.available()) {
    char inChar = (char)Serial1.read();
    inputString += inChar;
   
    if (inputString.endsWith(":")) {        
      stringComplete = true;      
    }
  }
}