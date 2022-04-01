#include <VirtualWire.h>
#include <VirtualWire_Config.h>

//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//https://www.instructables.com/id/RF-315433-MHz-Transmitter-receiver-Module-and-Ardu/
//http://www.genotronex.com/
//..................................

char *controller;
void setup() {
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(4800);// speed of data transfer Kbps
Serial.begin(4800);

}

int i=0;
char cstr[16];

void loop(){
i++;
itoa(i,cstr,10);
controller=cstr;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
Serial.println(controller);
delay(1000);

}
