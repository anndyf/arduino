# Modularização de Código no Arduino 🧩

Modularizar é **dividir o programa em partes menores (funções)** para facilitar a organização e manutenção.

---

## 🎯 Por que modularizar?

- Reutilização de código
- Clareza no programa
- Facilita correções e testes

---

## 🧱 Exemplo

```cpp
void inicializarPinos() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void lerSensor() {
  int valor = analogRead(A0);
  Serial.println(valor);
}
```

---

## 🧠 Dica

- Deixe o `setup()` e `loop()` organizados chamando funções curtas.