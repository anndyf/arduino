# Controle de Cargas com Módulo Relé 🔌

O módulo relé permite ligar e desligar aparelhos de maior tensão com segurança.

---

## 🧪 Exemplo

```cpp
int rele = 7;

void setup() {
  pinMode(rele, OUTPUT);
}

void loop() {
  digitalWrite(rele, HIGH);  // Liga o relé
  delay(2000);
  digitalWrite(rele, LOW);   // Desliga o relé
  delay(2000);
}
```

---

⚠️ **Segurança:** use cargas AC apenas se o relé for adequado e houver isolamento.