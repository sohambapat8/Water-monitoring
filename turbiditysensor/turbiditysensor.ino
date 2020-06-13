#define turbiditysensor 0

void setup() {
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {

  float totalvalue = 0;

  float volt = ((float)analogRead(turbiditysensor)/1023)*5;

//  int test = analogRead(turbiditysensor);
//
//  volt += ((float)analogRead(sensorPin)/1023)*5;

  Serial.println(volt);

}
