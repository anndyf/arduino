# Sensor de Luz com LDR 🌞

Um LDR varia sua resistência conforme a luz. Usamos `analogRead()` para ler esse valor.

---

## 🧪 Exemplo

```cpp
int ldr = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(ldr);
  Serial.println(valor);
  delay(500);
}
```

---

📈 Valores baixos = luz intensa  
📉 Valores altos = ambiente escuro