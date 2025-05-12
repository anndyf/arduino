# Display LCD 16x2 com I2C 🟦

Com o adaptador I2C, o display LCD usa apenas 2 pinos (SDA e SCL).

---

## 📦 Biblioteca

Instale: **LiquidCrystal_I2C by Frank de Brabander**

---

## 🧪 Exemplo

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço pode ser 0x27 ou 0x3F

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Olá, mundo!");
  lcd.setCursor(0, 1);
  lcd.print("Arduino + LCD");
}

void loop() {}
```