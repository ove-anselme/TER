#include <VirtualWire.h>
#include <VirtualWire_Config.h>

//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//https://www.instructables.com/id/RF-315433-MHz-Transmitter-receiver-Module-and-Ardu/
//http://www.genotronex.com/
//..................................
 
void setup()
{
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4800); // Bits per sec
  Serial.begin(4800);
  pinMode(13, OUTPUT);
  Serial.println("Go");
  vw_rx_start(); // Start the receiver PLL running
  
}
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
      Serial.print("Message reçu : ");
  
      int unite=buf[0]-'0';
      int dizaine=buf[1]-'0';
      int valeur =  dizaine * 10 + unite;

      Serial.println(valeur);
  }
}
