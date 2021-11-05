/* 
  Measure pressure (in units of psi) using the pressure transducer (sensor)
  Maintain a psi of 10 by:
    Opening or closing the valve based on if its under or above
    *Note: just waiting for prsesure to change could result in issues cause it depends on speed of feedback loop (times it takes for system to react)
    *Therefore we can make tests to check how much gas releases, or calculations, or etc.
*/

// defining constants & variables
const int pressureInputPin = A0; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds
float pressureValue = 0; //variable to store the value coming from the pressure transducer
int valveState = 0; //1 for energized/open & 0 for closed

void setup() {
  // put your setup code here, to run once:
  
  //we might have to do this if we want the digital or analog pins to send out or turn on or off, like for LED in the tinkercad tut but
  //but why are we using a3 to open valve? where did I get that code from
  pinMode(A3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  pressureValue = analogRead(pressureInputPin); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi

  if (pressureValue >= 10){
    openValve();
    valveState = 0
  }
}

//lets say its a normally closed circuit; solenoid is closed when unenergized => Energize to open
void openValve(){
    digitalWrite(A3, HIGH);
}
void closeValve(){
  valveState = 0;
}
