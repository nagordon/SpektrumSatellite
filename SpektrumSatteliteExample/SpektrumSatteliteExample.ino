//SpektrumSattelite Receiver Libriary
//Tested with Arduino DUE, Orange RX DSMX and Spektrum DX9
//To make it work on UNO or similar, change all shorts to ints and select the right serial (in the libriary)
#include <SpektrumSattelite.h>

#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3);  // Spektrum serial port

SpektrumSattelite rx;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200); //Uses Serial3 for input as default
}


void loop()
{
  rx.getFrame();

  Serial1.print("ch1:");
  Serial1.print(rx.getAile());
  Serial1.print("\t");
  
  Serial1.print("ch2:");
  Serial1.print(rx.getThro());
  Serial1.print("\t");
  
  Serial1.print("ch3:");
  Serial1.print(rx.getElev());
  Serial1.print("\t");
  
  Serial1.print("ch4:");
  Serial1.print(rx.getRudd());
  Serial1.print("\t");
  
  Serial1.print("ch5:");
  Serial1.print(rx.getGear());
  Serial1.print("\t");
  
  Serial1.print("ch6:");
  Serial1.print(rx.getPitc());
  Serial1.print("\t");
  
  Serial1.print("ch7:");
  Serial1.print(rx.getAux2());
  Serial1.print("\t");
  
  Serial1.print("ch8:");
  Serial1.print(rx.getAux3());
  Serial1.print("\t");
  
  Serial1.print("ch9:");
  Serial1.print(rx.getAux4());
  Serial1.print("\t");
  
  Serial1.print('\n');
}
