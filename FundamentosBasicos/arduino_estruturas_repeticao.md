
# Estruturas de Repetição no Arduino 🔁

As **estruturas de repetição** permitem executar blocos de código múltiplas vezes de forma controlada. São essenciais em automações, leituras contínuas e contagens.

---

## 🔁 `while`

Executa o bloco de código **enquanto** a condição for verdadeira.

```cpp
int contador = 0;

while (contador < 5) {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  contador++;
}
```

🧠 *Útil quando você quer repetir até que algo aconteça.*

---

## 🔂 `for`

Usado quando você já sabe **quantas vezes** quer repetir algo.

```cpp
for (int i = 0; i < 10; i++) {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}
```

📌 *Perfeito para criar pisca-pisca, contadores ou repetições controladas.*

---

## 🔁 `do...while`

Garante que o bloco de código execute **pelo menos uma vez**, mesmo que a condição seja falsa.

```cpp
int valor = 0;

do {
  valor = analogRead(A0);
  delay(100);
} while (valor < 500);
```

---

## 🧠 Boas Práticas

- Sempre tenha **condições de saída claras** para evitar loops infinitos.
- Use `for` quando o número de repetições for conhecido.
- Combine estruturas com `if`, `digitalRead` ou `analogRead` para controlar dispositivos.

---

## ⚠️ Evite Loops Infinitos

```cpp
while (true) {
  // Executa para sempre — cuidado ao usar!
}
```

🔄 *Se usar, inclua delay ou lógica condicional para evitar travamento.*

---

## 📚 Recursos Úteis

- [Laços de Repetição – Arduino](https://www.arduino.cc/reference/en/#structure-control)
- [Exemplos práticos – Arduino IDE](https://www.arduino.cc/en/Tutorial/HomePage)
