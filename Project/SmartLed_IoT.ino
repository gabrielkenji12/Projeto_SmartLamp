/*************************************************************
  Download desse projeto no GitHub
https://github.com/gabrielkenji12/Projeto_SmartLamp

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

*/
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
const int LDRPin = A0;  //define a pin for Photo resistor
#define ledPin D1 //D1     //define a pin for LED
int sensorValue = 0; //define variable off sensor
int count=0; //define counting
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "54fdc59952b541b286382a20289fd95a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iPhone";
char pass[] = "nawf1997";

void setup()
{
  // Debug console
  Serial.begin(9600);  //debugging  serial communcation
  pinMode( ledPin, OUTPUT ); 
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  
  Blynk.run();
  sensorValue=analogRead(A0);   //read  the value of the photoresistor.
  Serial.println(sensorValue);  // value of the photoresistor to the serial monitor.
  Blynk.virtualWrite(ledPin,HIGH);
  if(sensorValue<300){
    if(count==0){
      Blynk.notify("Está escuro"); 
      count = 1;
    }
  } else {         
      count = 0;                                           
  }
    
   
}

