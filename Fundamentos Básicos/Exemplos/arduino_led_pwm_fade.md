# Controle de LED com PWM (Fade) 💡

Usando `analogWrite()`, podemos controlar o brilho de um LED via PWM (modulação por largura de pulso).

---

## 🔧 Exemplo de Fade com PWM

```cpp
void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(9, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(9, i);
    delay(10);
  }
}
```

---

## ℹ️ Observações

- Use pinos com símbolo `~` para PWM (ex: 3, 5, 6, 9, 10, 11 no UNO).
- O valor de `analogWrite()` vai de 0 a 255.