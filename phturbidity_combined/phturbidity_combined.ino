#define phsensor 0
#define turbiditysensor 2

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


  if (phvalue >= 8.5){
    Serial.print(". This is alkaline.");
  }

  else if (phvalue <= 6.5){
    Serial.print(". This is acidic.");
  }

  else{
    Serial.print(". This is safe to drink.");
  }

  Serial.println(" ");

  float turbidity_totalvalue = 0;

  turbidity_totalvalue = 0;

   for(int i=0; i<50; i++){
    turbidity_totalvalue+=analogRead(turbiditysensor);
  }

//  Serial.println(analogRead(turbiditysensor));

  float volt = ((turbidity_totalvalue/1023)*5)/50;

//  float volt = ((float)analogRead(turbiditysensor)/1023)*5;

//  int test = analogRead(turbiditysensor);
//
//  volt += ((float)analogRead(sensorPin)/1023)*5;

  Serial.println(volt);

  turbidity_totalvalue = 0;


  if (phValue <=8.5 && phValue >=6.5 && volt > 3.5){
    println("Good water quality"); 
  }

  else if (phValue <6.5 && 2<volt){
    println("Warning, please check water");
  }

  else{
    println("Poor water quality. Not advisable to drink");
  }

  delay(2900);
  

}
