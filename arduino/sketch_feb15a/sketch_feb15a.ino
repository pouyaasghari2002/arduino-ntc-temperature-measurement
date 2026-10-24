# include<TimerOne.h> 
int pin_out=A0; 
int R1 = 1e4; 
float T0 = 298.15; // T0 = 25 C 
int Sampling_Frequency = 5; 
double V_NTC = 0; // NTC Voltage 
double R_NTC = 0; 
double Temperature = 0; 
double Vcc = 5; 
//B,R0 : coefficients of the calibration curve 
float B=3892,R0=9953; 
void setup() { 
  Serial.begin(9600); 
  // Set A0 as INPUT 
  pinMode(pin_out,INPUT); 
  analogReference(EXTERNAL); 
  Timer1.initialize(1000000/Sampling_Frequency); 
  Timer1.attachInterrupt(Sampling); 
} 
void loop() { 
  //Resistance : NTC_Resistnce, V2=3.83v 
  R_NTC = R1*(3.83 - V_NTC)/(Vcc - 3.83 + V_NTC);
  //Temperature Calculation 
  Temperature = 1/((1/T0)+(1/B)*log(R_NTC/R0))-273.15; 
  // Print Output 
  Serial.print("Voltage:"); 
  Serial.print(V_NTC); 
  Serial.print("\t"); 
  Serial.print("Temperature:"); 
  Serial.print(Temperature,5); 
  Serial.print(" C"); 
  Serial.print("\t"); 
  Serial.print("Resistance:");
  Serial.println(R_NTC); 
  delay(200); 
} 
// Sampling Function 
void Sampling(){ 
  // ADC Range of 0 - 3.49 
  V_NTC = analogRead(pin_out)/1023.00*3.49; 
}