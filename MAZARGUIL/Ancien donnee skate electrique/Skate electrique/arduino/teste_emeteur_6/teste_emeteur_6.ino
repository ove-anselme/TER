#include <VirtualWire.h>
#include <VirtualWire_Config.h>

//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//https://www.instructables.com/id/RF-315433-MHz-Transmitter-receiver-Module-and-Ardu/
//http://www.genotronex.com/
//..................................

char *controller;

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output


void setup() {

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4800);// speed of data transfer Kbps
  Serial.begin(4800);

}

char cstr[16];
int X_Position;
int vitesse;
int vitesse_1;
int vitesse_final;

void loop(){
  
  X_Position=analogRead(X_pin);
  vitesse = X_Position;
  if (vitesse<0){
    vitesse_1=0;    
  }
  else{
    vitesse_1=vitesse;
  }

  vitesse_final=map(vitesse,519,1022,0,30);
  itoa(vitesse_final,cstr,10);
  controller=cstr;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  Serial.println(X_Position);
  Serial.println(controller);
  delay(1000);

}
