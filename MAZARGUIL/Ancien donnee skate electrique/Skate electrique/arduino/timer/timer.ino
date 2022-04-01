/*
  Timer et interruptions
  https://www.locoduino.org/spip.php?article84
 */
 
const byte Led = 13; // LED du module
#define LedToggle digitalWrite (Led, !digitalRead(Led))
 
byte Compteur = 0;  //Compteur pour interruption
 
void setup(){
 
  // Initialise le Timer 2 pour déclencher les interruptions à intervalle régulier
  TCCR2A = 0; //default 
  TCCR2B = 0b00000110; // clk/256 est incrémenté toutes les 16uS  
  TIMSK2 = 0b00000001; // TOIE2 
  sei();               // autorise les interruptions
}

// Boucle principale
void loop() {
 
 
}
 
// routine d'interruption du timer
ISR (TIMER2_OVF_vect) 
{  
  // 256-6 --> 250X16uS = 4mS  
  // Recharge le timer pour que la prochaine interruption se déclenche dans 4mS
  TCNT2 = 6;
 
  if (Compteur++ == 250) {
    //250*4mS = 1S - la Led est allumée 1 S et éteinte 1 S
    Compteur=0;  
    LedToggle;
  }  
} 
