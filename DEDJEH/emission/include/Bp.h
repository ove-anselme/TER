#ifndef __BP__
#define __BP__
#include <Arduino.h>

const int Bp1 = 18;
const int Bp2 = 19;

/**
 * @brief Fonction qui prend en paramettre le numéro d'une pin (INPUT_PULLUP) et renvoie l'etat du bouton poussoir
 * 
 * @param Pin 
 * @return int 
 */
void ReadBouton ( const int Pin ,uint8_t * StateBuf);

//void DataBouton ()


void IRAM_ATTR fonction_ISR_Bp1(void);
void IRAM_ATTR fonction_ISR_Bp2(void);

/*
void setup() {
    Serial.begin(115200);
    pinMode(33, INPUT_PULLUP);
    attachInterrupt(33, fonction_ISR, CHANGE);
}

void loop() {
}
*/

#endif