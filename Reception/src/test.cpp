/*
#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <ESP32Servo.h>

int Val;
//uint8_t ValRecue;
uint8_t My_Data = 0;
Servo esc; //Creating a servo class with name as esc

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  memcpy(&My_Data, incomingData,sizeof(My_Data));
 // ValRecue = My_Data;

}

void setup() {
  // put your setup code here, to run once:
  Val = 1000;
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  esp_now_init();

  esp_now_register_recv_cb(OnDataRecv);

  
  esc.attach(5); //Specify the esc signal pin,Here as D8
  
  esc.writeMicroseconds(1000); //initialize the signal to 1000

  //delay(10)
  
 
}

void loop() {
  Serial.println(My_Data);
  // put your main code here, to run repeatedly:

 //Création de la variable ValRecue, ce sera la ValRecueeur reçu par le recepteur
  
  //ValRecue= analogRead(A0); //on lis sur la Broche A0 les données analogique

  /////////////////////
  //Debut du code recepteur
  
  
  
  //Fin du code recepteur
  ////////////////////
  
  //ValRecue= map(ValRecue, 0, 1023,1000,2000); //mapping ValRecue to minimum and maximum 
  //map(ValRecueeur,min_ValRecueeur,max_ValRecueeur,min_change,max_change)
  //ValRecueeur : la variable
  //min_ValRecueeur ou max_ValRecueeur : ValRecueeur min ou max de la variable (changer ces ValRecueeur si besoin)
  //min_change ou max_change : la nouvelle ValRecueeur min et max qu'on soit avoir

  switch (My_Data)
  {
  case 0:
    if(Val<2000)
    {
      Val++;
    }
    break;

  case 1:
    if (Val >1000)
    {
      Val--;
    }
    break;

  case 255:
    /* code 
    break;

  default:
    break;
  }
  esc.writeMicroseconds(Val); //using ValRecue as the signal to esc
  
  //Serial.println(Val);
}
*/