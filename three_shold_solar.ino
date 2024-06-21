
void setup() {
  Serial.begin(9600);               // initialize serial communication at 9600 bits per second:
}

// the loop routine runs over and over again forever:
void loop() {
  
  int lighting_intensity  = analogRead(A0);          // read the input on analog pin 0:
  Serial.println(lighting_intensity);               // print out the value you read:
  delay(500);                                      // delay in between reads for stability
}
