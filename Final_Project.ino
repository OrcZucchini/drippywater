//DHT Sensor
#include <DHT.h>
#define TYPE DHT11
int sensorPin = D3;

DHT dht(sensorPin, TYPE);
float humidity;
float temp1;
float temp2;

//relay for the water pump
int relay = D7;

//soil moisture sensor
int sensVal = A0;
float moist;

//button sensor
int button = D8;
int number;

//clock
const unsigned long interval_1 = 300000;
unsigned long past_1 = 0;

void setup() {
dht.begin();
pinMode(relay, OUTPUT);
pinMode(sensVal, INPUT);
pinMode(button, INPUT);


}

void loop() {

unsigned long currentTime = millis();

//data
if(currentTime - past_1 >= interval_1){
  humidity = dht.readHumidity();
  temp1 = dht.readTemperature();
  temp2 = dht.readTemperature(true);
  moist = analogRead(sensVal);

  past_1 = currentTime; 
  
}

//button
  number = digitalRead(button);

//Putting everything together
if(moist >= 270 && temp1 <= 25.5){
    for( int j = 0; j < 420; j++){//the number represents the seconds
      digitalWrite(relay, HIGH);
      j = j++;
      delay(1000);
    }
  }
else if(number == 1){
    for( int j = 0; j < 420; j++){//the number represents the seconds
      digitalWrite(relay, HIGH);
      j = j++;
      delay(1000);
    }
  }

else if (number == 0){
  digitalWrite(relay, LOW);
  }

else{
  digitalWrite(relay,LOW);
}


}
