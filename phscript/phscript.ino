#define phsensor 0

void setup() {
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {

  float totalvalue = 0;

  for(int i=0; i<50; i++){
    totalvalue+=analogRead(phsensor);
  }

  float phvalue = 3.5*totalvalue*5.0/1024/50; //converting the total value to mmillivolt then pH.

  Serial.print("pH level is ");
  Serial.print(phvalue,2); //output to 2 d.p.


  if (phvalue >= 8.5){
    Serial.print(" . This is alkaline and not safe to drink.");
  }

  else if (phvalue <= 6.5){
    Serial.print(" . This is acidic and not safe to drink.");
  }

  else{
    Serial.print(" . This is safe to drink.");
  }

  Serial.println(" ");

  delay(1600);
  

}
