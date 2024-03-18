#include "DHT.h"
#define dht_type DHT11

int pino_dht11 = A1;
int pino_lm35 = A5;
DHT dht_1 = DHT(pino_dht11, dht_type);

void setup() {
  Serial.begin(9600);
  dht_1.begin();
}

void loop() {
  float umidade = dht_1.readHumidity();
  float temperatura = analogRead(pino_lm35) * 0.00488 * 100;
  if(isnan(temperatura) or isnan(umidade)){
    Serial.println("Erro ao ler"); 
  } else {
  
    Serial.print(umidade);
    Serial.print(" % ");
    Serial.print(temperatura);
    Serial.println(" ºC");
  }
  delay(2000);
}
