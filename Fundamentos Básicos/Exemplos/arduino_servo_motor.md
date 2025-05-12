# Controle de Servo Motor com `Servo.h` 🌀

Usamos a biblioteca `Servo.h` para controlar o ângulo de um servo motor.

---

## 📦 Exemplo

```cpp
#include <Servo.h>

Servo meuServo;

void setup() {
  meuServo.attach(9);     // conecta no pino 9
}

void loop() {
  meuServo.write(90);     // vai para 90 graus
  delay(1000);
  meuServo.write(0);      // vai para 0 graus
  delay(1000);
}
```

---

✅ A maioria dos servos funciona de 0° a 180°.