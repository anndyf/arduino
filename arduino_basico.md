
# Fundamentos Básicos de Arduino 🔌

Arduino é uma plataforma de prototipagem eletrônica baseada em hardware e software de código aberto, ideal para quem está começando na eletrônica e na programação.

---

## 🧠 O que é o Arduino?

- Uma **placa microcontroladora** (como o Arduino UNO, Mega, Nano)
- Conectada ao computador via USB
- Programada com uma linguagem baseada em C/C++

---

## 🧾 Estrutura de um Código Arduino

```cpp
void setup() {
  // Este bloco roda uma única vez ao iniciar
}

void loop() {
  // Este bloco roda repetidamente em loop
}
```

- `setup()`: define configurações iniciais, como os pinos
- `loop()`: executa o que o Arduino deve fazer continuamente

---

## 📌 Principais Comandos

| Comando            | Descrição                                         |
|--------------------|--------------------------------------------------|
| `pinMode(pino, modo)` | Define se o pino será entrada ou saída       |
| `digitalWrite(pino, valor)` | Envia nível alto (`HIGH`) ou baixo (`LOW`) |
| `digitalRead(pino)` | Lê o valor de um pino digital                   |
| `analogRead(pino)`  | Lê valores de 0 a 1023 (ex: sensor LDR)         |
| `analogWrite(pino, valor)` | Envia sinal PWM de 0 a 255               |
| `delay(ms)`         | Pausa a execução por milissegundos              |

---

## 🧱 Tipos de Pinos

- **Digitais (D0 a D13)**: podem ser entrada ou saída
- **Analógicos (A0 a A5)**: usados para leitura de sensores (0–1023)
- **PWM (~)**: indicados com ~ (ex: D3, D5, D6) e usados com `analogWrite`

---

## 🛠️ Funções e Lógica

- `if`, `else`: controle de decisões
- `for`, `while`: laços de repetição
- `Serial.begin(9600)`: inicia comunicação serial
- `Serial.print() / println()`: envia mensagens para o monitor serial

---

## 🔋 Tensão e Corrente

- Operação com **5V ou 3.3V**
- Limite de corrente por pino: **40mA**
- Use resistores para proteger LEDs e componentes

---

## 📚 Recursos Úteis

- [Referência Oficial do Arduino (Inglês)](https://www.arduino.cc/reference/en/)
- [Guia em Português – FilipeFlop](https://www.filipeflop.com/blog/guia-inicial-arduino/)
