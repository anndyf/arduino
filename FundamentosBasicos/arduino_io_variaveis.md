# 🚀 Entrada, Saída e Declaração de Variáveis no Arduino 💡

Neste guia, explicamos como usar os **pinos de entrada e saída** no Arduino e como declarar variáveis para armazenar dados.

-----

## 🔌 Pinos de Entrada e Saída\!

### `pinMode(pino, modo)`

Define se um pino será de entrada (`INPUT`) ou saída (`OUTPUT`).

```cpp
pinMode(13, OUTPUT);  // Define o pino 13 como saída
pinMode(2, INPUT);    // Define o pino 2 como entrada
```

-----

## 🟢 Saída Digital: `digitalWrite()`

Usado para **ligar ou desligar** dispositivos digitais (LEDs, relés, etc.) com um simples `HIGH` (ligado) ou `LOW` (desligado).

```cpp
digitalWrite(13, HIGH);  // Liga o pino 13 (5V)
digitalWrite(13, LOW);   // Desliga o pino 13 (0V)
```

-----

## 🟡 Entrada Digital: `digitalRead()`

Usado para **ler o estado** de botões ou sensores digitais, retornando `HIGH` ou `LOW`.

```cpp
int estado = digitalRead(2); // Lê o valor (HIGH ou LOW) do pino 2
```

-----

## 🔵 Entrada Analógica: `analogRead()`

Lê valores variáveis de sensores (ex: LDR, potenciômetro) em uma escala de **0 a 1023**.

```cpp
int valor = analogRead(A0);  // Valor de 0 a 1023
```

-----

## 🌈 Saída Analógica (PWM): `analogWrite()`

Gera um sinal **PWM** (simula tensão analógica) de **0 a 255** em pinos com o símbolo `~` (por exemplo, no pino 5).

```cpp
analogWrite(5, 128); // Meio brilho se for LED (pino 5 com ~)
```

-----

## 🧮 Declaração de Variáveis: Armazenando Informações

Em Arduino (C/C++), é necessário informar o **tipo da variável** para reservar o espaço correto na memória.

| Tipo      | Exemplo                 | Descrição                                 |
| :-------- | :---------------------- | :---------------------------------------- |
| `int`     | `int valor = 0;`        | Números inteiros (-32k a 32k)             |
| `float`   | `float temp = 24.5;`    | Números com casas decimais                |
| `bool`    | `bool ligado = true;`   | Verdadeiro ou falso                       |
| `char`    | `char letra = 'A';`     | Armazena um caractere                     |
| `String`  | `String nome = "LED";`  | Cadeia de caracteres                      |

-----

## 🧠 Escopo de Variáveis: Onde Sua Variável Vive?

O **escopo** define onde uma variável pode ser acessada no seu código.

### 🌍 Variável Global

Declarada **fora** das funções. Pode ser usada em **qualquer lugar** do programa.

```cpp
int contador = 0; // Variável global

void setup() {
  // ...
}

void loop() {
  contador++; // 'contador' é acessível aqui
}
```

### 📍 Variável Local

Declarada **dentro de uma função**. Só existe e pode ser usada **ali dentro**.

```cpp
void loop() {
  int leitura = analogRead(A0); // 'leitura' só existe aqui dentro
}
```

-----

## ✨ Boas Práticas e Dicas\!

  - ✅ Sempre declare variáveis **antes do uso**, de preferência fora do `loop()` se forem globais, ou no início da função se forem locais.
  - ✍️ Use nomes **significativos** para as variáveis para facilitar a leitura e manutenção do código.
  - 💡 **Prefira variáveis locais** quando possível, pois elas tornam o código mais seguro e modular.
  - ⚠️ Cuidado com o uso de `float` em projetos que exigem alta precisão ou desempenho crítico.

-----

## 📚 Recursos Úteis para Continuar Aprendendo\!

  - [Referência de Variáveis – Arduino.cc](https://www.arduino.cc/reference/en/#variables)
  - [Entrada e Saída Digital – Arduino.cc](https://www.arduino.cc/en/Tutorial/BuiltInExamples)

-----
