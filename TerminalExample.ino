/*Developer: Frederik Hauke

Important Notices:
    This Arduino-Code is written for building a bidirectional Connection from a
    microcontroller via Bluetooth. Before starting the Android-Application, the 
    Bluetooth-Modul (HC-05) has to be coupled to the Smartphone. In the special 
    case of the HC-05 the default PinCode for initiating the Coupling-Process is "1234".

Wiring: 
  GND of HC-05 to GND Arduino, VCC of HC-05 to VCC Arduino,
  TX HC-05 to Arduino Pin 10 (RX)
  RX HC-05 to TX Arduino (TX)
 */
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // RX | 

int LEDPin = 13;

void setup() {
  
  BTserial.begin(9600);  
  pinMode(LEDPin,OUTPUT);  
}

void loop ()
{
  if(BTserial.available())
  {
  char daten=BTserial.read();
 
  if(daten=='H')
    {
     digitalWrite(LEDPin, HIGH); 
     BTserial.print("LED on");
      BTserial.print(";");  
    }
  else if (daten=='L')
  {
   digitalWrite(LEDPin, LOW);
   BTserial.print("LED off");
      BTserial.print(";");
  }
}
}

