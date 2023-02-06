#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// initialize the library with the numbers of the interface pins
char ssid[] = "@t";
char pass[] = "kb223122";
char auth[] = "5PyhnTBaffTiEUeMwOsWr3l3YUQTzdMJ";
WidgetLCD lcd(V1);
WidgetLCD lcd1(V2);
WidgetLCD lcd2(V3);
int sensorPin   = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor


void setup() {
Serial.begin(115200); //sets serial port for communication
Blynk.begin(auth, ssid, pass);

pinMode(D6, OUTPUT);
pinMode(D7, OUTPUT);
pinMode(D8, OUTPUT);
//
  


lcd.clear();
lcd.print(0,0,"UNDERGROUND CABLE");
//lcd.setCursor(0, 1);
lcd.print(0,1,"FAULT LOCATOR");

delay(1000);
delay(1000);
lcd.clear();

lcd.print(0,0,"R-LINE");
lcd1.print(0,0,"Y-LINE");
lcd2.print(0,0,"B-LINE");
  
}
void loop()
{
// -----R - LINE--------------
digitalWrite(D6, HIGH);
digitalWrite(D7, LOW);
digitalWrite(D8, LOW); 


sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen


 if( (sensorValue <= 20) )
{
   //Serial.print("R -  NF,") ;
   lcd.print(1,0,"R -  NF,") ;
 }

  else if( (sensorValue >= 150) && (sensorValue <= 170)  )
{  
 //Serial.print("R - 4KM,") ;
 lcd.print(1,0,"R - 4KM,") ;
}
  else if( (sensorValue >= 200) && (sensorValue <= 230)  )
{  
 //Serial.print("R - 6KM,") ;
 lcd.print(1,0,"R - 6KM,") ;
}
  else if( (sensorValue >= 350) && (sensorValue <= 370)  )
{  
 //Serial.print("R - 8KM,") ;
 lcd.print(1,0,"R - 8KM,") ;
} 

// -----Y - LINE--------------
digitalWrite(D6, LOW);
digitalWrite(D7, HIGH);
digitalWrite(D8, LOW); 


sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen


 if( (sensorValue <= 20) )
{
   lcd1.print(1,0,"Y -  NF,") ;
 }

  else if( (sensorValue >= 150) && (sensorValue <= 170)  )
{  
 lcd1.print(1,0,"Y - 4KM,") ;
}
  else if( (sensorValue >= 200) && (sensorValue <= 230)  )
{  
 lcd1.print(1,0,"Y - 6KM,") ;
}
  else if( (sensorValue >= 350) && (sensorValue <= 370)  )
{  
 lcd1.print(1,0,"Y - 8KM,") ;
} 
// -----B - LINE--------------
digitalWrite(D6, LOW);
digitalWrite(D7, LOW);
digitalWrite(D8, HIGH); 


sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen


 if( (sensorValue <= 20) )
{
   lcd2.print(1,0,"B -  NF,") ;
 }

  else if( (sensorValue >= 150) && (sensorValue <= 170)  )
{  
 lcd2.print(1,0,"B - 4KM,") ;
}
  else if( (sensorValue >= 200) && (sensorValue <= 230)  )
{  
 lcd2.print(1,0,"B - 6KM,") ;
}
  else if( (sensorValue >= 350) && (sensorValue <= 370)  )
{  
 lcd2.print(1,0,"B - 8KM,") ;
} 
Blynk.run();
}
