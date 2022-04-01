void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initialise la communication entre le PC et Arduino

}

void loop() {
  
  Serial.println(analogRead(A0));

  // put your main code here, to run repeatedly:

}
