String incomingByte = ""; 
int led_pin = 8;
boolean led_on = false;
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
      digitalWrite(led_pin, HIGH);
      delay(5000);  
    }
    else if(incomingByte == "-"){
      digitalWrite(led_pin, LOW);
      delay(5000);  
    }
  }
}
