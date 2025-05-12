# Comunicação I2C no Arduino 📡

O protocolo I2C permite comunicação entre múltiplos dispositivos usando **dois fios**: SDA (dados) e SCL (clock).

---

## 📘 Conexões (Arduino UNO)

| Fio | Pino no UNO |
|-----|--------------|
| SDA | A4           |
| SCL | A5           |

---

## 🧪 Exemplo com I2C Scanner

```cpp
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Escaneando...");
}

void loop() {
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Encontrado: 0x");
      Serial.println(addr, HEX);
    }
  }
  delay(5000);
}
```

---

✅ Útil para descobrir o endereço de dispositivos como LCD I2C, sensores etc.