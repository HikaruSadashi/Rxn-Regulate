//Dont commit this yet, reference in disc I guess plus shiesty uni doing arduino while this is for 1 year olds, like lego? but lego coo
//While first years use eagle and upper years teach them damn this is sad ngl
//Should do school work, will plan in a bit
//Due to the lack of components in this simulation
//In this scenario 

//////
//=> The pentiometer will act as the pressure sensor outputing analog (by changing resistance in this case)
//=> The led will either be on or off, acting as the valve, on or off but normally in a closed state
//Differences in simulation are (broken doe so), are the lack of relay in the circuitry.



//Defining constants and variables
const int pressureInputPin = A0; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds
float pressureValue = 0; //variable to store the value coming from the pressure transducer
int valveState = 0; //1 for energized/open & 0 for closed

void setup() {
  // put your setup code here, to run once:
  // The A0 pin will read analog from transducer and from pentiometer here but
  //but the 13 will act as the A3 which we use to order or output to the valve/led in this scenario
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // (tab broken), but anyways all is left is to convert pento analog to digital & the time delay thing
  pressureValue = analogRead(pressureInputPin); //reads value from input pin and assigns to variable
   
  //pressure or resistance is too much open vale or turn on led!!
  //NOTE!!: I think once u call digital write it just keeps providing so ud have to close it once pressure is lower
  if (pressureValue >= 511){
    openValve();
  } else if (pressureValue < 511) {
   	closeValve(); 
  }
  //There is a problem, it always calls a function, which means it keeps digital writing
  //Lets only digital write if the state is not the same
}


//inside or outside the loop?
//lets say its a normally closed circuit; solenoid is closed when unenergized => Energize to open
void openValve(){
  if (valveState == 0) {
    digitalWrite(13, HIGH);
    valveState = 1;
  }
}
void closeValve(){
  if (valveState == 1) {
  	digitalWrite(13, LOW);
  	valveState = 0;
  }
}