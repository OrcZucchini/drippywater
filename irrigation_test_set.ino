#include <DHT.h>
#define TYPE DHT11
int sensorPin = 3;

DHT dht(sensorPin, TYPE);
float humidity;
float temp1;
float temp2;

int relay = 2;

//button sensor
int button = 5;
int number;

int sensVal = A0;
float moist;

//clock
const unsigned long interval_1 = 1000;
unsigned long past_1 = 0;
const unsigned long interval_2 = 50;
unsigned long past_2 = 0;

void setup() {
Serial.begin(9600);
dht.begin();
pinMode(relay, OUTPUT);
pinMode(sensVal, INPUT);
pinMode(button, INPUT);
}

void loop() {
unsigned long currentTime = millis();

number = digitalRead(button);

if(currentTime - past_1 >= interval_1){
  humidity = dht.readHumidity();
  temp1 = dht.readTemperature();
  temp2 = dht.readTemperature(true);
  moist = analogRead(sensVal);

  past_1 = currentTime; 
  
}

else if( number == 1){
  for(int j = 0; j<= 10; j++){
    digitalWrite(relay, HIGH);
    delay(1000);
  }
  
}

else if(number == 0) {
    digitalWrite(relay, LOW);
  
}

Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print( "% Temperature: " );
  Serial.print(temp1);
  Serial.print( " C Temperature: " );
  Serial.print(temp2);
  Serial.print(" F");
  Serial.print(" Soil Moisture: ");
  Serial.print(moist);
  Serial.print(" Button Status: ");
  Serial.println(number);

}
