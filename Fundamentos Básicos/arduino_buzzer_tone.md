# Controle de Buzzer com `tone()` 🔊

O comando `tone()` permite gerar som com frequências definidas em buzzers passivos.

---

## 🧪 Exemplo

```cpp
void setup() {
  tone(8, 1000); // Toca som de 1000 Hz no pino 8
  delay(1000);
  noTone(8);     // Para o som
}
```

---

## ℹ️ Detalhes

- `tone(pino, frequência)` → inicia som
- `noTone(pino)` → para o som