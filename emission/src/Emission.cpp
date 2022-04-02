#include "Emission.h"
#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{

    if (status == ESP_NOW_SEND_SUCCESS)
    {
        Serial.println("Envoie  donné ok !!");
    }
    else
    {
        Serial.println("Erreur Envoie de donnée!!");
    }
}

void emissionInit(uint8_t *Adresse_Mac, esp_now_send_cb_t cb)
{

    // Initialisation du moniteur série
    Serial.begin(115200);

    // Definir l'ESP32 en tant que station WIFI
    WiFi.mode(WIFI_STA);

    // init ESP-NOW

    if (esp_now_init() == ESP_OK)
    {
        Serial.println("Initialisation OK !! ");
        Serial.println("cool");
    }

    else
    {
        Serial.println("Erreur Initialisation");
        ESP.restart();
    }

    // Appel d'une fonction de callback  **concept encore flou pour moi pour le moment **
    esp_now_register_send_cb(OnDataSent);

    /*
      Appairrage
    */

    // La structure Peerinfo

    esp_now_peer_info peerInfo;
    memcpy(peerInfo.peer_addr, Adresse_Mac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    // Mise en place de la fonction peer et des verification afférentes

    if (esp_now_add_peer(&peerInfo) == ESP_OK)
    {
        Serial.println("Appairage Réussi");
    }
    else
    {
        Serial.println("Erreur Appairage");
    }
}

void emission(uint8_t *Adresse_Mac, uint8_t My_Data)
{
    esp_err_t Statut_Envoi = esp_now_send(Adresse_Mac, &My_Data, sizeof(My_Data));

    if (Statut_Envoi == ESP_OK)
    {
        Serial.println("Envoie OK pi!!");
    }
    else
    {
        Serial.println("Erreur Envoie !! ");
    }
}