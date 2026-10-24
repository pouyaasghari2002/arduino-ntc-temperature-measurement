int pin_out=A1; 
int R1 = 1e4; 
float T0 = 298.15; // T0 = 25 C 
double V_NTC = 0; // NTC Voltage 
double R_NTC = 0; 
double Vcc = 5; 
void setup() { 
  Serial.begin(9600); // Set A0 as INPUT 
  pinMode(pin_out,INPUT); 
} 
void loop() { 
  V_NTC=analogRead(pin_out)/1023.00*Vcc; 
  R_NTC = V_NTC*R1 / (V_NTC - Vcc); 
  Serial.print("Voltage:"); 
  Serial.print(V_NTC); 
  Serial.print("\t"); 
  Serial.print("\t"); 
  Serial.print("Resistance:");
  Serial.println(R_NTC); 
  delay(200); 
}