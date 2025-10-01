# 🚀 Primeiros Passos com Arduino: Botão e LED

Este é o seu primeiro projeto prático. Você vai aprender a usar um botão para controlar um LED. É a base para entender como o Arduino interage com o mundo físico.

-----

### 📋 O que você vai precisar

  * **Arduino Uno:** O cérebro do projeto.
  * **Protoboard:** Para montar o circuito sem solda.
  * **1 Botão de pressão:** A sua entrada.
  * **1 LED:** A sua saída.
  * **1 Resistor de 220Ω:** Para proteger o LED.
  * **1 Resistor de 10kΩ:** Para o botão.
  * **Jumpers:** Cabos para fazer as conexões.

-----

### 🧱 Passo 1: Montando o Circuito

Siga este diagrama para conectar todos os componentes na protoboard.

1.  **Conecte o Botão:**

      * Um lado do botão vai para o **5V** do Arduino.
      * O outro lado do botão vai para o **pino digital 3** e, com um resistor de **10kΩ**, para o **GND**.
      * **Conceito:** O resistor de 10kΩ é um `pull-down`. Ele garante que o pino 3 esteja sempre em `LOW` (0V) quando o botão não está pressionado, evitando leituras "flutuantes".

2.  **Conecte o LED:**

      * O terminal mais longo (o ânodo) do LED vai para o **pino digital 2**.
      * O terminal mais curto (o cátodo) vai para o **GND**, mas passe por um resistor de **220Ω** para protegê-lo de uma corrente alta.

![Diagrama do Circuito - Botão e LED](Circuitos/2- led_botao.png)
-----

### 💻 Passo 2: O Código

Abra a IDE do Arduino e copie e cole este código. Ele é simples, mas ensina os conceitos essenciais.

```cpp
// ==== 🌍 Variáveis Globais (Escopo Global) ====
// Definimos os pinos aqui para que possamos usá-los em qualquer parte do código.
const int PINO_BOTAO = 3; // O botão está conectado ao pino 3
const int PINO_LED = 2;  // O LED está conectado ao pino 2

void setup() {
  // ==== 🔌 Pinos de Entrada e Saída ====
  // Dizemos ao Arduino como cada pino irá funcionar.
  pinMode(PINO_BOTAO, INPUT); // O pino do botão será uma ENTRADA (recebe sinal)
  pinMode(PINO_LED, OUTPUT);   // O pino do LED será uma SAÍDA (envia sinal)
}

void loop() {
  // ==== 📥 Entrada Digital: digitalRead() ====
  // A cada instante, o Arduino lê o estado do botão (pressionado ou solto).
  // A variável 'estadoBotao' é LOCAL, só existe dentro de loop().
  int estadoBotao = digitalRead(PINO_BOTAO);

  // ==== 🔀 Condicional: if/else ====
  // Agora, o Arduino toma uma decisão com base no que ele leu.
  if (estadoBotao == HIGH) {
    // Se o botão estiver pressionado (sinal HIGH), o código aqui é executado.
    digitalWrite(PINO_LED, HIGH); // ==== 📤 Saída Digital: digitalWrite() ====
                                  // O Arduino envia um sinal HIGH para ligar o LED.
  } else {
    // Se o botão estiver solto (sinal LOW), o código aqui é executado.
    digitalWrite(PINO_LED, LOW); // ==== 📤 Saída Digital: digitalWrite() ====
                                 // O Arduino envia um sinal LOW para desligar o LED.
  }
}
```

-----

### ✅ Passo 3: Executando o Projeto

1.  Conecte o Arduino ao computador via cabo USB.
2.  Na IDE do Arduino, vá em **Ferramentas \> Placa** e selecione "Arduino Uno".
3.  Vá em **Ferramentas \> Porta** e selecione a porta serial correta.
4.  Clique no botão "Carregar" (a seta para a direita) para enviar o código para o seu Arduino.
5.  Pronto\! Pressione o botão na protoboard. Você verá o LED acender. Solte-o e o LED apagará.

Você acaba de criar sua primeira interação entre hardware e software, usando conceitos fundamentais como variáveis, `pinMode`, `digitalRead` e `digitalWrite`.
