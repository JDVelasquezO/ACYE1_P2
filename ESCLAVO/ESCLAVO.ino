#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(23);
  // Wire.onRequest(); // Llama una funcion por parámetros, enviamos datos
  Wire.onReceive(getData); // Se activa cuando el maestro recibe datos
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}


// Sin parametros y tipo void
void getData() {
  Serial.println(Wire.read());  
}
