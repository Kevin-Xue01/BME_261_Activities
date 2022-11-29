String incomingByte = ""; 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readString();
    incomingByte.replace("e", "*");
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
}
