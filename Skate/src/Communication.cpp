#include "esp_now.h"
#include <Arduino.h>
#include "WiFi.h"
#include "Communication.h"


void Comm_Init(void)
{
    // Set device as a Wi-Fi Station
    WiFi.mode ( WIFI_STA );

    //Esp_Now Initialization
    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Erreur Innitialisation !!");
        return;
    }
}

