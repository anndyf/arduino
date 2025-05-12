# Usando `millis()` no Lugar de `delay()` ⏲️

`millis()` retorna o tempo (em milissegundos) desde que o Arduino foi ligado. Permite controlar tempo **sem travar o programa** como o `delay()` faz.

---

## 🧪 Exemplo de Piscar LED com `millis()`

```cpp
unsigned long tempoAnterior = 0;
int intervalo = 1000;
bool estado = false;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (millis() - tempoAnterior >= intervalo) {
    tempoAnterior = millis();
    estado = !estado;
    digitalWrite(13, estado);
  }
}
```

---

✅ Vantagem: o código **continua executando** outras tarefas enquanto espera.