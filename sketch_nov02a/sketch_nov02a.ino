
int val = 0;
void setup() {
  // put your setup code here, to run once:
  // pre check for some values

  //SIMULATION from here now on
  //variables for the simulation?
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = hallRead();
  Serial.print("sensor = ");
  Serial.println(val);
}
