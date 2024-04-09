
//#define LDRPIN A0   // Pin connected to the LDR sensor

void setup() {

pinMode(A0,INPUT);
Serial.begin(115200);
Serial.println("LDR Test!");
}

void loop() {
  
//  int ldrVal = 0; 
//  const float GAMMA = 0.7;
//  const float RL10 = 50;

  //Getting the value of light
//  ldrVal = digitalRead(LDRPIN);
    int lux = 0;
    lux = analogRead(A0);
     
//  float voltage = ldrVal / 1024. * 5;
//  float resistance = 200 * voltage / (1 - voltage / 5);
//  float lux = pow(RL10 * pow(10, GAMMA) / resistance, (1 / GAMMA));

   delay(200); // Wait for 2 secondss
//  float lightLevel = map(lightValue, 0, 1023, 0, 100);
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.print("Lux");
  Serial.println(" ");

//  delay(2000); // Wait for 2 seconds
}
