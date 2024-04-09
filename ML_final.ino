#include "DHT.h"
#define DHTPIN 2    // Definig pin 2 for DHT11 Seonsor

// Defining the model/type of DHT sensor used
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(115200);
  Serial.println("Sensor Values!!");

  dht.begin();
}

void loop() {
  
  delay(1000);
  
  int lux = 0;
  lux = analogRead(A0);
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float f = dht.readTemperature(true);

//  Compute heat index in Fahrenheit (the default)
//  float hif = dht.computeHeatIndex(f, h);
//  Compute heat index in Celsius (isFahreheit = false)
//  float hic = dht.computeHeatIndex(t, h, false);

  Serial.println("");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C        ");
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.print("Lux");
  Serial.println(" ");
  float a=0,b=0,c=0,d=0;
  a=-0.95215825;
  b=0.40587284;
  c= -0.2408559;
  d= 83.88153208919869;
  float y_predict = a*t + b*h + c*lux + d;

  if(y_predict <0){
    y_predict =0;
  }
    
  Serial.println("Current Rain Probablity: ");
  Serial.print(y_predict);
  Serial.println("");

  

}
