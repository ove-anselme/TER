// Arduino digital pins

#define BUTTON_PIN  2
#define LED_PIN     13
/*

// Used Arduino 0017
// This does does some error checking to try to make sure the receiver on this one way RF serial link doesn't repond to garbage

#define NETWORK_SIG_SIZE 3

#define VAL_SIZE         2
#define CHECKSUM_SIZE    1
#define PACKET_SIZE      (NETWORK_SIG_SIZE + VAL_SIZE + CHECKSUM_SIZE)
 
// The network address byte and can be change if you want to run different devices in proximity to each other without interfearance
#define NET_ADDR 5
 
const byte g_network_sig[NETWORK_SIG_SIZE] = {0x8F, 0xAA, NET_ADDR};  // Few bytes used to initiate a transfer

/*
// Receives an unsigned int over the RF network
unsigned int readUInt(bool wait){
  int pos = 0;          // Position in the network signature
  unsigned int val;     // Value of the unsigned int
  byte c = 0;           // Current byte
  
  if((Serial.available() < PACKET_SIZE) && (wait == false))  {
    return 0xFFFF;
    }
    
  while(pos < NETWORK_SIG_SIZE)  {
    while(Serial.available() == 0); // Wait until something is avalible
    c = Serial.read();
    if (c == g_network_sig[pos]){
      if (pos == NETWORK_SIG_SIZE-1)
      {
        byte checksum;

        while(Serial.available() < VAL_SIZE + CHECKSUM_SIZE); // Wait until something is avalible
        val=  Serial.read();
        val+= ((unsigned int)Serial.read())*256;
        checksum =  Serial.read();
        
        if (checksum != ((val/256) ^ (val&0xFF)))
        {
          // Checksum failed
          pos = -1;
        }
      }
      ++pos;
    }
    else if (c == g_network_sig[0])
    {
      pos = 1;
    }
    else
    {
      pos = 0;
      if (!wait)
      {
        return 0xFFFF;
      }
    }
  }
  return val;
}*/


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
 // Serial.begin(1200);  // Hardware supports up to 2400, but 1200 gives longer range
}

void loop(){
  boolean light_led = false;
 /* if (readUInt(true) == 271) // Check to see if we got the 71 test number
  {
    light_led = true;
}*/
  if (light_led)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
  }
}
