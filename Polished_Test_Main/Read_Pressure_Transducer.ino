/* 
  test sketch that displays displays pressure transducer psi value on the serial monitor
*/

//defining constants & variables
const int pressureInputPin = A0; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds
float pressureValue = 0; //variable to store the value coming from the pressure transducer

void setup() {
  //put your setup code here, to run once:
  //note: analog input pin defined above
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  //put your main code here, to run repeatedly:
  pressureValue = analogRead(pressureInputPin); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert
  delay(500);
  Serial.println(pressureValue);
}
