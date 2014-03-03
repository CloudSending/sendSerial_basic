//check received data at the serial monitor

void setup(){
  Serial.begin(19200);
}

void loop(){
  if(Serial.available()){
    Serial.write(Serial.read());
  }
}

