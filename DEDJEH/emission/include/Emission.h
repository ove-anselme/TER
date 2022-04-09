#ifndef __EMISSION__
#define __EMISSION__

#include <esp_now.h>


void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void emissionInit(uint8_t *Adresse_Mac, esp_now_send_cb_t cb);
// void pairing (esp_now_peer_info* peerInfo);
void emission(uint8_t *Adresse_Mac, uint8_t My_Data);

#endif