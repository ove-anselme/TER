#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

uint8_t My_Data = 0;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  memcpy(&My_Data, incomingData,sizeof(My_Data));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  esp_now_init();

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  Serial.println(My_Data);
  // put your main code here, to run repeatedly:
}