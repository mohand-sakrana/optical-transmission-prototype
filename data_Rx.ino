int bits[8];                 // Declare bits array globally
#define SOLARPIN A0         // define analog pin for LED
#define THRESHOLD 560      // lighting_intensity as threshold
char receivedMessage[9];  // Array to store 8 bits + null terminator

void setup() {
  pinMode(SOLARPIN, INPUT);    // state of digital pin
  Serial.begin(9600);         // open serail with baud rate
}

void loop() {
  int reading = analogRead(SOLARPIN);     // store reading of solar panel in varaible

  if (reading > THRESHOLD) {
    for (int i = 0; i < 8; i++) {       // loop to receive each 8-bit segment separately 
      if (analogRead(SOLARPIN) > THRESHOLD) {  
        bits[i] = 1;                   
      } else {
        bits[i] = 0;
      }
      delay(10);
    }
    // Convert bits to ASCII and store in receivedMessage
    for (int j = 0; j < 8; j++) {
      receivedMessage[j] = bits[j] ;
      bits[0] = 0 ;                        // set first bit  to 0
    }
    int m = 0;
    for (int j = 1; j < 8; j++) {
      if (bits[j] == 1) {
        m += (1 << (7 - j));             // covert binary bits to decimal
      }
    }
    char n = m;                                 // covert decimal NO. to character
    String message = "";                       // Create variable to store the message
    message += n;                             // Print the characters sequentially        
    //Serial.print(receivedMessage);         // print binary bits 
      Serial.print(message);                // print character
    //Serial.print(m)                      // print decmial of character  
  }
}
