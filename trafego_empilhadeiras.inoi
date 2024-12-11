// Definição dos pinos dos sensores
const int sensorA = 2; // Sensor A
const int sensorB = 3; // Sensor B
const int sensorC = 4; // Sensor C
const int sensorD = 5; // Sensor D (para o sentido B)

// Definição dos LEDs do semáforo de cima (Sentido B)
const int S1_V = 9;  // LED vermelho do semáforo de cima
const int S1_A = 10; // LED amarelo do semáforo de cima
const int S1_G = 11; // LED verde do semáforo de cima

// Definição dos LEDs do semáforo de baixo (Sentido A)
const int S2_V = 6;  // LED vermelho do semáforo de baixo
const int S2_A = 7;  // LED amarelo do semáforo de baixo
const int S2_G = 8;  // LED verde do semáforo de baixo

unsigned long inicioDeteccao = 0;  // Tempo de início da detecção
unsigned long inicioAlerta = 0;    // Tempo de início do alerta no sensor A ou B
unsigned long esperaAposC = 0;     // Tempo após passar pelo sensor C
bool piscando = false;             // Controle para indicar modo piscando
bool emDeteccao = false;           // Controle para indicar se está no tempo de detecção
bool alertaAtivo = false;          // Controle para ativar alerta
String sentidoAtual = "";          // Indica o sentido atual ("A" ou "B")

void setup() {
  pinMode(sensorA, INPUT_PULLUP);
  pinMode(sensorB, INPUT_PULLUP);
  pinMode(sensorC, INPUT_PULLUP);
  pinMode(sensorD, INPUT_PULLUP);

  pinMode(S1_V, OUTPUT);
  pinMode(S1_A, OUTPUT);
  pinMode(S1_G, OUTPUT);

  pinMode(S2_V, OUTPUT);
  pinMode(S2_A, OUTPUT);
  pinMode(S2_G, OUTPUT);

  setSemaforo("INICIAL"); // Configuração inicial
  Serial.begin(9600);
  Serial.println("Sistema de controle de tráfego iniciado.");
}

void loop() {
  int leituraA = digitalRead(sensorA);
  int leituraB = digitalRead(sensorB);
  int leituraC = digitalRead(sensorC);
  int leituraD = digitalRead(sensorD);

  // Detecção de alerta no sensor A ou B (sozinhos por 3 segundos)
  if (!alertaAtivo && sentidoAtual == "") {
    if (leituraA == LOW && leituraB == HIGH) {
      if (inicioAlerta == 0) inicioAlerta = millis();
      if (millis() - inicioAlerta >= 3000) {
        ativarAlerta();
      }
    } else if (leituraB == LOW && leituraA == HIGH) {
      if (inicioAlerta == 0) inicioAlerta = millis();
      if (millis() - inicioAlerta >= 3000) {
        ativarAlerta();
      }
    } else {
      inicioAlerta = 0; // Reseta o tempo de alerta se ambos ou nenhum estiver ativo
    }
  }

  // Sai do estado de alerta se nenhum sensor A ou B estiver ativo
  if (alertaAtivo && leituraA == HIGH && leituraB == HIGH) {
    desativarAlerta();
  }

  // Detecta sentido de passagem (A ou B) com 4 segundos de detecção
  if (!piscando && sentidoAtual == "" && !alertaAtivo) {
    if (leituraA == LOW && leituraB == LOW) {
      iniciarDeteccao("A"); // Prioridade ao sentido A
    } else if (leituraD == LOW) {
      iniciarDeteccao("B");
    } else {
      resetarDeteccao();
    }
  }

  // Ativa o sentido se a detecção durar 4 segundos
  if (emDeteccao && millis() - inicioDeteccao >= 4000) {
    ativarRota(sentidoAtual);
    emDeteccao = false;
  }

  // Detecta meio do percurso no sensor C
  if (leituraC == LOW && sentidoAtual != "") {
    if (!piscando) {
      piscando = true;
      esperaAposC = millis();
      Serial.println("Meio do percurso detectado no sentido " + sentidoAtual);
    }
  }

  // Pisca LEDs durante o tempo de espera após a passagem no sensor C
  if (piscando) {
    piscarLedsAmbos();
  }

  // Conclui o ciclo após 3 segundos piscando
  if (piscando && millis() - esperaAposC >= 3000) {
    concluirCiclo();
    piscando = false;
    sentidoAtual = "";
  }

  // Pisca todos os LEDs durante o alerta
  if (alertaAtivo) {
    piscarTodosOsLeds();
  }
}

void iniciarDeteccao(String sentido) {
  if (!emDeteccao || sentidoAtual != sentido) {
    inicioDeteccao = millis();
    sentidoAtual = sentido;
    emDeteccao = true;
    Serial.println("Detecção no sentido " + sentido + " iniciada. Aguardando 4 segundos.");
  }
}

void resetarDeteccao() {
  if (emDeteccao) {
    Serial.println("Detecção interrompida.");
    emDeteccao = false;
    sentidoAtual = "";
  }
}

void ativarRota(String sentido) {
  Serial.println("Rota ativada no sentido " + sentido);
  setSemaforo(sentido);
}

void ativarAlerta() {
  alertaAtivo = true;
  Serial.println("Alerta ativado! Pessoa detectada no sensor A ou B por 3 segundos.");
}

void desativarAlerta() {
  alertaAtivo = false;
  Serial.println("Alerta desativado. Retornando ao estado inicial.");
  setSemaforo("INICIAL");
}

void concluirCiclo() {
  Serial.println("Ciclo concluído. Voltando ao estado inicial.");
  setSemaforo("INICIAL");
}

void setSemaforo(String estado) {
  if (estado == "INICIAL") {
    // Ambos os semáforos com verde ativado inicialmente
    digitalWrite(S1_V, LOW);
    digitalWrite(S1_A, LOW);
    digitalWrite(S1_G, HIGH);

    digitalWrite(S2_V, LOW);
    digitalWrite(S2_A, LOW);
    digitalWrite(S2_G, HIGH);
  } else if (estado == "A") {
    // Sentido A:
    // Semáforo de baixo (S2): Amarelo e Vermelho ligados
    // Semáforo de cima (S1): Apenas Vermelho ligado
    digitalWrite(S1_V, HIGH); // S1 Vermelho
    digitalWrite(S1_A, LOW);  // S1 Amarelo
    digitalWrite(S1_G, LOW);  // S1 Verde

    digitalWrite(S2_V, HIGH); // S2 Vermelho
    digitalWrite(S2_A, HIGH); // S2 Amarelo
    digitalWrite(S2_G, LOW);  // S2 Verde
  } else if (estado == "B") {
    // Sentido B:
    // Semáforo de cima (S1): Amarelo e Vermelho ligados
    // Semáforo de baixo (S2): Apenas Vermelho ligado
    digitalWrite(S1_V, HIGH); // S1 Vermelho
    digitalWrite(S1_A, HIGH); // S1 Amarelo
    digitalWrite(S1_G, LOW);  // S1 Verde

    digitalWrite(S2_V, HIGH); // S2 Vermelho
    digitalWrite(S2_A, LOW);  // S2 Amarelo
    digitalWrite(S2_G, LOW);  // S2 Verde
  }
}

void piscarLedsAmbos() {
  static unsigned long lastBlinkTime = 0;
  static bool estado = false;

  if (millis() - lastBlinkTime >= 500) { // Alterna o estado a cada 500ms
    lastBlinkTime = millis();
    estado = !estado;

    // Pisca LEDs do semáforo de cima (S1)
    digitalWrite(S1_V, estado ? HIGH : LOW);
    digitalWrite(S1_A, estado ? HIGH : LOW);

    // Pisca LEDs do semáforo de baixo (S2)
    digitalWrite(S2_V, estado ? HIGH : LOW);
    digitalWrite(S2_A, estado ? HIGH : LOW);
  }
}

void piscarTodosOsLeds() {
  static unsigned long lastBlinkTime = 0;
  static bool estado = false;

  if (millis() - lastBlinkTime >= 500) { // Alterna o estado a cada 500ms
    lastBlinkTime = millis();
    estado = !estado;

    // Pisca todos os LEDs do semáforo de cima (S1)
    digitalWrite(S1_V, estado ? HIGH : LOW);
    digitalWrite(S1_A, estado ? HIGH : LOW);
    digitalWrite(S1_G, estado ? HIGH : LOW);

    // Pisca todos os LEDs do semáforo de baixo (S2)
    digitalWrite(S2_V, estado ? HIGH : LOW);
    digitalWrite(S2_A, estado ? HIGH : LOW);
    digitalWrite(S2_G, estado ? HIGH : LOW);
  }
}
