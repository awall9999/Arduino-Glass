
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        Serial1.begin(9600);    // opens serial port 1, sets data rate to 9600 bps
}

void loop() {

  if (Serial1.available())
    Serial.write(Serial1.read());  //read data from Bluetooth and send it to USB
  if (Serial.available())
    Serial1.write(Serial.read());  //read data from USB and send it to Bluetooth 
}
