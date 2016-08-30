

#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 9  // Connect RST to pin 9 (req. for SPI and I2C)
#define PIN_DC    8  // Connect DC to pin 8 (required for SPI)
#define PIN_CS    10 // Connect CS to pin 10 (required for SPI)
#define DC_JUMPER 0
// Also connect pin 13 to SCK and pin 11 to MOSI

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. The parameters include:
// 1 - Reset pin: Any digital pin
// 2 - D/C pin: Any digital pin (SPI mode only)
// 3 - CS pin: Any digital pin (SPI mode only, 10 recommended)
MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS);
//MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration

// I2C is great, but will result in a much slower update rate. The
// slower framerate may be a worthwhile tradeoff, if you need more
// pins, though.
String bluedata;
String command;
byte value;
byte valueall[15];
char valuechar[15];

void setup()
{
  Serial1.begin(9600);
  oled.begin();    // Initialize the OLED
  delay(1000);
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
       // Delay 1000 ms
  oled.clear(PAGE);
  oled.display();
  
  oled.setFontType(1); 
  oled.setCursor(0, 0);
 oled.print("ArduinoGlasses V1.0");
 oled.display();
 delay(2000); 
 oled.clear(ALL);
 oled.clear(PAGE);
 oled.display();
 oled.setCursor(0, 10);
 oled.print("Glasses");
 oled.setCursor(10, 30);
 oled.print("Ready");
 oled.display();
// oled.clear(ALL);
oled.clear(PAGE);
}

void loop()
{
if(Serial1.available()){
     delay(100);
     while(Serial1.available()) {
      value = (Serial1.read());
      if (value == 43 || value == 45){
         
        for (int i=0; i <= 15; i++){
            
        valueall[i] = value;
        value = (Serial1.read());
          
        }
      int a=0;
       String value = ((char*)valueall);
    //oled.println(test.substring(0, 6));

  
for (a=0; a <=15; a++){
  //oled.print(valueall[a]);
  valuechar[a]=valueall[a];
  //oled.print("-");
  
}
//oled.clear(ALL);
//oled.clear(PAGE);
oled.setCursor(0, 20);
//command =  valuechar[1];command += valuechar[2];command += valuechar[3];command += valuechar[4]; // build number
if (valuechar[0] == 43 && valueall[7] == 49) oled.print("+");
if (valuechar[0] == 45 && valueall[7] == 49) oled.print("-");
if (valuechar[0] == 43 && valueall[7] == 41) oled.print("~");
if (valuechar[0] == 45 && valueall[7] == 41) oled.print("~");
if (valuechar[0] == 43 && valueall[7] == 17) oled.print("+");
if (valuechar[0] == 45 && valueall[7] == 17) oled.print("-");
if (valuechar[0] == 43 && valueall[7] == 9) oled.print("~");
if (valuechar[0] == 45 && valueall[7] == 9) oled.print("~");

oled.print(valuechar[1]);
if (valueall[6] == 49) oled.print(".");
oled.print(valuechar[2]);
if (valueall[6] == 50) oled.print(".");
oled.print(valuechar[3]);
if (valueall[6] == 52) oled.print(".");
oled.print(valuechar[4]);

oled.setCursor(0, 35);
if (valueall[9] == 64 && valueall[10] == 128) oled.print("mV");
if (valueall[9] == 0 && valueall[10] == 128) oled.print("V");
if (valueall[9] == 0 && valueall[10] == 32) oled.print("R");
if (valueall[9] == 32 && valueall[10] == 32) oled.print("K");
if (valueall[9] == 16 && valueall[10] == 32) oled.print("M");
if (valueall[9] == 0 && valueall[10] == 64) oled.print("A");
if (valueall[9] == 64 && valueall[10] == 64) oled.print("mA");
if (valueall[9] == 128 && valueall[10] == 64) oled.print("uA");
if (valueall[9] == 0 && valueall[10] == 2) oled.print("Grad C");
if (valueall[9] == 0 && valueall[10] == 1) oled.print("Grad F");
if (valueall[9] == 0 && valueall[10] == 8) oled.print("Hz");
oled.display();
oled.clear(PAGE);
      }
     }
 }





  
 
        
}
