
# Entrada, Saída e Declaração de Variáveis no Arduino 📥📤

Neste guia, explicamos como usar os **pinos de entrada e saída** no Arduino e como declarar variáveis para armazenar dados.

---

## 🔌 Pinos de Entrada e Saída

### `pinMode(pino, modo)`
Define se um pino será de entrada (`INPUT`) ou saída (`OUTPUT`).

```cpp
pinMode(13, OUTPUT);  // Define o pino 13 como saída
pinMode(2, INPUT);    // Define o pino 2 como entrada
```

---

## 📤 Saída Digital: `digitalWrite()`

Usado para **ligar ou desligar** dispositivos digitais (LEDs, relés, etc.).

```cpp
digitalWrite(13, HIGH);  // Liga o pino 13 (5V)
digitalWrite(13, LOW);   // Desliga o pino 13 (0V)
```

---

## 📥 Entrada Digital: `digitalRead()`

Usado para **ler o estado** de botões ou sensores digitais.

```cpp
int estado = digitalRead(2);  // Lê o valor (HIGH ou LOW) do pino 2
```

---

## 📥 Entrada Analógica: `analogRead()`

Lê valores variáveis de sensores (ex: LDR, potenciômetro).

```cpp
int valor = analogRead(A0);  // Valor de 0 a 1023
```

---

## 📤 Saída Analógica (PWM): `analogWrite()`

Gera sinal **PWM** (simula tensão analógica) de 0 a 255 em pinos com `~`.

```cpp
analogWrite(5, 128);  // Meio brilho se for LED (pino 5 com ~)
```

---

## 🧮 Declaração de Variáveis

Em Arduino (C/C++), é necessário informar o tipo da variável:

| Tipo      | Exemplo            | Descrição                        |
|-----------|--------------------|----------------------------------|
| `int`     | `int valor = 0;`   | Números inteiros (-32k a 32k)    |
| `float`   | `float temp = 24.5;`| Números com casas decimais       |
| `bool`    | `bool ligado = true;`| Verdadeiro ou falso             |
| `char`    | `char letra = 'A';` | Armazena um caractere            |
| `String`  | `String nome = "LED";`| Cadeia de caracteres            |

---

## 🧠 Boas Práticas

- Sempre declare variáveis **antes do uso**, de preferência fora do `loop()`.
- Use nomes **significativos** para facilitar a leitura.
- Cuidado com o uso de `float` em projetos que exigem precisão ou desempenho.

---

## 📚 Recursos Úteis

- [Referência de Variáveis – Arduino.cc](https://www.arduino.cc/reference/en/#variables)
- [Entrada e Saída Digital – Arduino.cc](https://www.arduino.cc/en/Tutorial/BuiltInExamples)
