/**
 * Exemple de code pour la bibliothèque VirtualWire – Serveur d'envoi de variable
 */

#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);

  // Initialisation de la bibliothèque VirtualWire
  // Vous pouvez changez les broches RX/TX/PTT avant vw_setup() si nécessaire
  vw_setup(2000);
  vw_rx_start(); // On peut maintenant recevoir des messages

  Serial.println("Go !"); 
  
}

void loop() {
  float valeur;
  byte taille_message = sizeof(float);

  /* 
   La variable "taille_message" doit impérativement être remise à 
   la taille de la variable avant de pouvoir recevoir un message. 
   Le plus simple est d'utiliser une variable locale pour ne pas
   avoir à réassigner la valeur à chaque début de loop().
   */
  Serial.println("attente du message");
     digitalWrite(13,LOW);

  // On attend de recevoir un message
  vw_wait_rx();

  if (vw_get_message((byte *) &valeur, &taille_message)) {
    // On copie le message, qu'il soit corrompu ou non
  
    Serial.println(valeur); // Affiche le message
     Serial.println("message reçue");

     digitalWrite(13,HIGH);

  }
}
