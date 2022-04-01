#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo class with name as esc

void setup()
{

  esc.attach(8); //Specify the esc signal pin,Here as D8
  
  esc.writeMicroseconds(1000); //initialize the signal to 1000
  
  Serial.begin(9600);

}

void loop()
{
  
  int val; //Création de la variable val, ce sera la valeur reçu par le recepteur
  
  val= analogRead(A0); //on lis sur la Broche A0 les données analogique

  /////////////////////
  //Debut du code recepteur
  
  
  
  //Fin du code recepteur
  ////////////////////
  
  val= map(val, 0, 1023,1000,2000); //mapping val to minimum and maximum 
  //map(valeur,min_valeur,max_valeur,min_change,max_change)
  //valeur : la variable
  //min_valeur ou max_valeur : valeur min ou max de la variable (changer ces valeur si besoin)
  //min_change ou max_change : la nouvelle valeur min et max qu'on soit avoir
  
  esc.writeMicroseconds(val); //using val as the signal to esc
  
  Serial.println(val);

}
