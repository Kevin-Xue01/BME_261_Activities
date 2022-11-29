String incomingByte = ""; 
int led_pin = 9;
int brightness = 0;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = String(Serial.readString());
    incomingByte.trim();
    Serial.print(incomingByte.length());
    if(incomingByte.equals("+")){
      if(brightness < 255){
        brightness = brightness + 5;
      }
    }
    else if(incomingByte == "-"){
      if(brightness > 0){
        brightness = brightness - 5;
      }
    }
    analogWrite(led_pin, brightness);
  }
}
