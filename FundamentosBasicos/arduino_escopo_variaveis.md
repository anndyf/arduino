# Escopo de Variáveis no Arduino 🧮

O **escopo** define onde uma variável pode ser acessada no código.

---

## 🌍 Variável Global

Declarada fora das funções. Pode ser usada em qualquer lugar.

```cpp
int contador = 0;

void loop() {
  contador++;
}
```

---

## 📍 Variável Local

Declarada dentro de uma função. Só existe ali.

```cpp
void loop() {
  int leitura = analogRead(A0); // só existe aqui
}
```

---

## 🧠 Dicas

- Use variáveis locais quando possível (mais seguras).
- Use globais apenas se for necessário compartilhar dados entre funções.