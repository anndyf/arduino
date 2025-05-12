# Sensor de Temperatura e Umidade com DHT11 🌡️💧

O DHT11 mede **temperatura e umidade** e exige biblioteca específica.

---

## 📦 Biblioteca

Instale: **DHT sensor library by Adafruit**

```cpp
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float umidade = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C, Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");
  delay(2000);
}
```