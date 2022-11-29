#include <Wire.h>
int address = 0x48;

int baudrate = 9600;
byte val = 0;
void setup()
{
    Wire.begin();
    Serial.begin(baudrate);
    }

    void loop()
    {
    Serial.print("temperature in Celsius: ");


    int temperature;

    Wire.beginTransmission(address);

    Wire.write(val);

    Wire.requestFrom(address, 1);
    if (Wire.available() > 0) {
    temperature = Wire.read();
    Serial.println(temperature);
    }

    else {
    Serial.println("---");
    }
    delay(1000);
    }
