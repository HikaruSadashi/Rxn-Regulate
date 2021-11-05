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

//int or boolean for the value of opening or closing? how do we open and close

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  pressureValue = analogRead(pressureInputPin); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi

  if (pressureValue >= 10){
    //openValve();
  } else if (pressureValue >= 10){
    //closeValve();
  }
}


void openValve(){
  if valve already open cause value is still above psi 10 dont change
  if not then actually open it by
}
//mechanisim might have to change if u have to provide a set value of voltage to keep open or closed ig? (go look at spec sheet lazy)
//by creating a var of state that u set to 1 or 0 or u 
change and an ifstatement checks it each time it runs and changes 
