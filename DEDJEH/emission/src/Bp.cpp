#include "Bp.h"
#include <Arduino.h>

void ReadBouton ( const int Pin ,uint8_t * StateBuf)
{
    (* StateBuf) = digitalRead( Pin );
}
//int ove=ets_printf();
/*
void IRAM_ATTR fonction_ISR_Bp1(void) {
    // Code de la fonction
    
}

void IRAM_ATTR fonction_ISR_Bp2(void) {
    //code pour la fonction
    
}
*/