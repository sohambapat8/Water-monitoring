#define phsensor 2
#define turbiditysensor 3


void setup() {
  Serial.begin(9600);
}

void loop() {

  float ph_totalvalue = 0;

  for(int i=0; i<50; i++){
    ph_totalvalue+=analogRead(phsensor);
  }

  float phvalue = 3.5*ph_totalvalue*5.0/1024/50; //converting the total value to mmillivolt then pH.

  Serial.print("pH level is ");
  Serial.print(phvalue,2); //output to 2 d.p.

  Serial.println(" ");

  float turbidity_totalvalue = 0;

   for(int i=0; i<50; i++){
    turbidity_totalvalue+=analogRead(turbiditysensor);
  }

  float volt = ((turbidity_totalvalue/1024)*5)/50;

  Serial.print("Turbidity level is ");
  Serial.print(volt);
  Serial.println(" ");
//  Serial.println(volt);

  turbidity_totalvalue = 0;


  if (phvalue <=9.5 && phvalue >=6.5 && volt > 3.8){
    Serial.println("Good water quality"); 
  }

  else if (phvalue < 6.5 && volt > 3.5){
    Serial.println("Warning, please check water");
  }

  else{
    Serial.println("Poor water quality. Not advisable to drink");
  }

  delay(2900);
  

}
