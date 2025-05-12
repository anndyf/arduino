# Sensor de Temperatura com LM35 🌡️

O LM35 gera uma tensão proporcional à temperatura: **10mV por °C**.

---

## 🧪 Exemplo de Leitura

```cpp
int sensor = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensor);
  float temperatura = (leitura * 5.0 / 1023.0) * 100;
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  delay(1000);
}
```

---

🧠 A conversão transforma a leitura analógica (0–1023) em volts e depois em graus Celsius.