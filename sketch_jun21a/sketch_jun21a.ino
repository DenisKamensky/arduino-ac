#include "thermistor.h"

Thermistor thermistor;
void setup () {
  Serial.begin(9600);
  thermistor.setupPin(A0);
 }

 void loop () {
    float data = thermistor.measureCelcium();
    Serial.println(data);
    delay(1000);
 }

