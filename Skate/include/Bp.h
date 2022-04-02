#ifndef __BP__
#define __BP__

const int Bp1 = 18;
const int BP2 = 19;

/**
 * @brief Fonction qui prend en paramettre le numéro d'une pin (INPUT_PULLUP) et renvoie l'etat du bouton poussoir
 * 
 * @param Pin 
 * @return int 
 */
void ReadBouton ( const int Pin ,int * StateBuf);


#endif