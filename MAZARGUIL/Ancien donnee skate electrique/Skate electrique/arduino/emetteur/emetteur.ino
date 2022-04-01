/* 
  RF Blink - Transmit sketch 
     Written by ScottC 17 Jun 2014
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Transmitter: FS1000A/XY-FST
     Description: A simple sketch used to test RF transmission.          
 ------------------------------------------------------------- */

#include <Servo.h> // Appel de la library Servo.h

 #define rfTransmitPin 4  //RF Transmitter pin = digital pin 4   
  #define ledPin 13        //Onboard LED = digital pin 13

int valeur = 0; // Variable potentiomètre
Servo esc ; // Créé une variable de type Servo et on lui attribue comme nom : esc

 void setup(){
  esc.attach(8); // On attribue la pin 8 à la variable esc
  esc.writeMicroseconds(1000); // On attribue la valeur min   
  pinMode(ledPin, OUTPUT);
  pinMode(rfTransmitPin, OUTPUT); 
  Serial.begin(9600);  
 }

 void loop(){
  valeur = analogRead(A0); 
  int valeuresc = map (valeur ,0 , 784, 1000, 4000);
  esc.writeMicroseconds(valeuresc); // On attribue la variable mappé qu'on attribue à l'esc
  Serial.println(valeuresc);

  digitalWrite(rfTransmitPin, HIGH);     //Transmit a HIGH signal
  digitalWrite(ledPin, HIGH);            //Turn the LED on
  delay(valeuresc);                      //Wait for 1 second
       
  digitalWrite(rfTransmitPin,LOW);      //Transmit a LOW signal
  digitalWrite(ledPin, LOW);            //Turn the LED off
  delay(valeuresc);
     
 }
