const unsigned long eventInterval=1000;
unsigned long previousTime= 0;
const int sensorPin=A0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  unsigned long currentTime = millis();

  if( currentTime - previousTime >= eventInterval){
      getTemp();
    previousTime=currentTime;
  }
 
}
float getTemp(){
  int sensorval = analogRead(sensorPin);
  float voltage = (sensorval/1024.0)*5.0;
  float temprature = (voltage - 0.5)*100;
  
  //consolWrite("Sensor :",sensorval); 
  //consolWrite("Voltage :",voltage); 
  consolWrite("Temprature :",temprature);
 // Serial.println("*******************");
  //delay(1000);
return temprature;
}

void consolWrite(String navn,float value){
 // Serial.print(navn);
  Serial.println(value);
}

