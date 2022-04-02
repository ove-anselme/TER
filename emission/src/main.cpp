#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "Emission.h"
#include "Bp.h"




uint8_t My_Data = 0;

uint8_t StateBp1 = 0;
uint8_t StateBp2 = 0;

void setup()
{
  pinMode(Bp1, INPUT_PULLUP);
  pinMode(Bp2, INPUT_PULLUP);
  emissionInit(Adresse_Mac, OnDataSent);
  Serial.println("cool");
  
}

void loop()
{
  ReadBouton(Bp1,&StateBp1);
  ReadBouton(Bp2,&StateBp2);

  if ((StateBp1 == 0 || StateBp1 ==1) && StateBp2 ==1)
  {
    My_Data = StateBp1;

  }
  else
  {
    My_Data = -1;
  }
  emission(Adresse_Mac, My_Data);
  //delay(20);
}