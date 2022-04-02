#include "Bp.h"
#include <Arduino.h>

void ReadBouton ( const int Pin ,int * StateBuf)
{
    (* StateBuf) = digitalRead( Pin );
}