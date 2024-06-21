const int LEDPIN = 10;           // define digital pin for LED           
String message ;                // Create variable to store the message
void setup() {
  pinMode(LEDPIN, OUTPUT);                       // state of digital pin
  Serial.begin(9600);                           // open serail with baud rate
}

void loop() {
  if (Serial.available() > 0) {
    message = Serial.readStringUntil('\n');          //read message from serial
      // loop to select each charcter in message 
      for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        int bits[8];

        //Loop to convert ASCII characters to binary bits
        for (int z = 0; z < 8; z++) {
          bits[z] = c % 2;
          c /= 2;
        }
        // Reverse the binary bits
        for (int j = 0; j < 4; j++) {
          int temp = bits[j];
          bits[j] = bits[7 - j];
          bits[7 - j] = temp;
          bits[0] = 1;               // Set the first bit to 1
        }
        // Write the binary bits to the LED pin
        for (int p = 0; p < 8; p++) {
          digitalWrite(LEDPIN, bits[p]);
          delay(10);
          Serial.print(bits[p]);
        }  
        // Turn off the LED after each character transmission
        digitalWrite(LEDPIN, LOW);
        delay(10); 
    }
  }
}
