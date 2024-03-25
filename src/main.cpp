#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println("Platformio is properly setup for Arduino framework");
    delay(500);
}