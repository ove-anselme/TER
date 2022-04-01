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
      Serial.println("Message reçu : longeur du message =  ");
      Serial.println(buflen);

      
      int millier=buf[0]-'0';
      int centaine=buf[1]-'0';
      int dizaine=buf[2]-'0';
      int unite=buf[3]-'0';
     
      int valeur;
      int P_unite=0;
      int P_dizaine=1;
      int P_centaine=2;
      int P_millier=3;

      if(buflen==1)
      {
        centaine=0;
        dizaine=0;
        unite=0;
      }
      
      if(buflen==2)
      {
        dizaine=0;
        unite=0;
      }
       if(buflen==3)
      {
        unite=0;
      }
      
      if( (48 > buf[3] and buf[3] < 57) or buflen==3)
      {
        P_unite=3;
        P_dizaine=0;
        P_centaine=1;
        P_millier=2;
        unite=0;
      }
      if( (48 >buf[2] and buf[2] < 57) or buflen==2 )
      {
        dizaine=0;
        P_unite=3;
        P_dizaine=2;
        P_centaine=0;
        P_millier=1;
      }

       if((48 > buf[1] and buf[1] < 57) or buflen==1)
      {
        centaine=0;
        P_unite=3;
        P_dizaine=2;
        P_centaine=1;
        P_millier=0;
      }
      
      if((48 > buf[0] and buf[0] < 57))
      {
        millier=0;
      }
      
      Serial.print("buf[0] = ");
      Serial.print(buf[0]);
      Serial.print(" et millier = ");
      Serial.println(millier); 

      Serial.print("buf[1] = ");
      Serial.print(buf[1]);
      Serial.print(" et centaine = ");
      Serial.println(centaine); 

      Serial.print("buf[2] = ");
      Serial.print(buf[2]);
      Serial.print(" et dizaine = ");
      Serial.println(dizaine); 
      
      Serial.print("buf[3] = ");
      Serial.print(buf[3]);
      Serial.print(" et unite = ");
      Serial.println(unite); 


      valeur = millier * pow(10,P_millier) + centaine * pow(10,P_centaine) + dizaine * pow(10,P_dizaine) + unite * pow(10,P_unite) ;
      
      Serial.print("valeur = ");
      Serial.println(valeur);

      Serial.println("Fin du Message ");
      Serial.println();
      Serial.println();
  }
}
