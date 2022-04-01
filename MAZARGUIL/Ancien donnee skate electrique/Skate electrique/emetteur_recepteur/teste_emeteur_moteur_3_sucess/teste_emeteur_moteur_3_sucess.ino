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
const int potentiometre = 0; // analog pin connected to X output

void setup() {

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4800);// speed of data transfer Kbps
  Serial.begin(4800);

}

int potentiometre_Position=0;
char cstr[16];
char buf[3];
void loop(){
  potentiometre_Position=analogRead(potentiometre);
  itoa(potentiometre_Position,cstr,10);
  controller=cstr;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  /*
   
   buf[0]=controller[0];
   buf[1]=controller[1];
   buf[2]=controller[2];
   buf[3]=controller[3];
   int millier=buf[0]-'0';
      int centaine=buf[1]-'0';
      int dizaine=buf[2]-'0';
      int unite=buf[3]-'0';
     
      int valeur;
      int P_unite=0;
      int P_dizaine=1;
      int P_centaine=2;
      int P_millier=3;

      
      if(unite == -48)
      {
        P_unite=3;
        P_dizaine=0;
        P_centaine=1;
        P_millier=2;
        unite=0;
      }
      if(dizaine == -48)
      {
        dizaine=0;
        P_unite=3;
        P_dizaine=2;
        P_centaine=0;
        P_millier=1;
      }

       if(centaine == -48)
      {
        centaine=0;
        P_unite=3;
        P_dizaine=2;
        P_centaine=1;
        P_millier=0;
      }
      
      if(millier == -48)
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
*/
      Serial.print("controller = ");
      Serial.println(controller);
     // Serial.println();
      //Serial.println();

      
      
      delay(100);

}
