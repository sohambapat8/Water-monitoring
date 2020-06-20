#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define OLED_ADDR 0x3D //I2C address of OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);



#define StartConvert 0


const byte numReadings = 20;     //the number of sample times
byte ECsensorPin = A1;  //EC Meter analog output,pin on analog 1
unsigned int AnalogSampleInterval=25,printInterval=700;  //analog sample interval;serial print interval
unsigned int readings[numReadings];      // the readings from the analog input
byte index = 0;                  // the index of the current reading
unsigned long AnalogValueTotal = 0;                  // the running total
unsigned int AnalogAverage = 0,averageVoltage=0;                // the average
unsigned long AnalogSampleTime,printTime;
float ECcurrent;



void setup() {
 // initialize serial communication with computer:
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Conductivity Sensor");
  display.println("Shows:");
  display.println("- Salinity");
  //display.println("- Whether the water is safe to use");
  
  display.display();

  delay(500);
  // initialize all the readings to 0:
  for (byte thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
  AnalogSampleTime=millis();
  printTime=millis();
}

void loop() {
  /*
   Every once in a while,sample the analog value and calculate the average.
  */
  if(millis()-AnalogSampleTime>=AnalogSampleInterval)
  {
    AnalogSampleTime=millis();
     // subtract the last reading:
    AnalogValueTotal = AnalogValueTotal - readings[index];
    // read from the sensor:
    readings[index] = analogRead(ECsensorPin);
    // add the reading to the total:
    AnalogValueTotal = AnalogValueTotal + readings[index];
    // advance to the next position in the array:
    index = index + 1;
    // if we're at the end of the array...
    if (index >= numReadings)
    // ...wrap around to the beginning:
    index = 0;
    // calculate the average:
    AnalogAverage = AnalogValueTotal / numReadings;
  }
  
   
   /*
   Every once in a while,print the information on the OLED display.
  */
  if(millis()-printTime>=printInterval)
  {
    printTime=millis();
    averageVoltage=AnalogAverage*(float)5000/1024;
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    //Serial.print("Analog value:");
    //Serial.print(AnalogAverage);   //analog average,from 0 to 1023
    display.print("    Voltage:");
    display.print(averageVoltage);  //millivolt average,from 0mv to 4995mV
    display.println("mV    ");
    /*if(averageVoltage > 200 && averageVoltage < 800){
      display.println("The water is not useable");
    }
    else if(averageVoltage > 801){
      display.println("The water is very salty");
    }*/
    display.display();

    

  }

}
