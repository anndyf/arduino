#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

RTC_DS1307 rtc;

#define PINO_RELE 3  // Sirene ou buzzer

// Estrutura dos períodos
struct Periodo {
  int inicio;  // em minutos
  int fim;
  const char* nome;
};

Periodo periodos[] = {
  {420, 465, "1M"},   // 07:00 - 07:45
  {465, 510, "2M"},   // 07:45 - 08:30
  {510, 555, "3M"},   // 08:30 - 09:15
  {555, 600, "4M"},   // 09:15 - 10:00
  {600, 620, "Int"},  // 10:00 - 10:20
  {620, 665, "5M"},   // 10:20 - 11:05
  {665, 710, "6M"},   // 11:05 - 11:50

  {780, 825, "1T"},   // 13:00 - 13:45
  {825, 870, "2T"},   // 13:45 - 14:30
  {870, 915, "3T"},   // 14:30 - 15:15
  {915, 960, "4T"},   // 15:15 - 16:00
  {960, 980, "Int"},  // 16:00 - 16:20
  {980, 1025, "5T"},  // 16:20 - 17:05
  {1025, 1070, "6T"}, // 17:05 - 17:50

  {1110, 1155, "1N"}, // 18:30 - 19:15
  {1155, 1175, "Int"},// 19:15 - 19:35
  {1175, 1220, "2N"}, // 19:35 - 20:20
  {1220, 1265, "3N"}, // 20:20 - 21:05
  {1265, 1310, "4N"}  // 21:05 - 21:50
};


// Lista de horários de alarme (hora, minuto)
const int NUM_ALARMES = 19;
int alarmes[NUM_ALARMES][2] = {
  {7, 0}, {7, 45}, {8, 30}, {9, 15}, {10, 0}, {10, 20}, {11, 5},
  {13, 0}, {13, 45}, {14, 30}, {15, 15}, {15, 35}, {16, 20}, {17, 5},
  {18, 30}, {19, 15}, {19, 35}, {20, 20}, {21, 5}
};

// Variáveis do alarme
bool alarmeAtivado = false;
unsigned long tempoDisparo = 0;
int ultimoMinutoDisparado = -1;
bool mostrarDisplay = true;
unsigned long ultimoToggle = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  rtc.begin();

  pinMode(PINO_RELE, OUTPUT);
  digitalWrite(PINO_RELE, LOW);
  //rtc.adjust(DateTime(2025, 5, 13, 14, 54, 0));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro no display OLED");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  DateTime now = rtc.now();
  int hora = now.hour();
  int minuto = now.minute();
  int agoraMin = hora * 60 + minuto;

  // Determina período
  const char* periodo = "Fora";
  for (auto& p : periodos) {
    if (agoraMin >= p.inicio && agoraMin < p.fim) {
      periodo = p.nome;
      break;
    }
  }

  // Verifica disparo de alarme (segunda a sexta)
  if (now.dayOfTheWeek() >= 1 && now.dayOfTheWeek() <= 5) {
    for (int i = 0; i < NUM_ALARMES; i++) {
      if (hora == alarmes[i][0] && minuto == alarmes[i][1] &&
          minuto != ultimoMinutoDisparado && !alarmeAtivado) {
        digitalWrite(PINO_RELE, HIGH);
        alarmeAtivado = true;
        tempoDisparo = millis();
        ultimoToggle = millis();
        mostrarDisplay = false;
        ultimoMinutoDisparado = minuto;

        Serial.print("ALARME DISPARADO em ");
        if (hora < 10) Serial.print("0");
        Serial.print(hora);
        Serial.print(":");
        if (minuto < 10) Serial.print("0");
        Serial.println(minuto);
      }
    }
  }

  // Piscar display durante alarme
  if (alarmeAtivado) {
    if (millis() - ultimoToggle >= 500) {
      mostrarDisplay = !mostrarDisplay;
      ultimoToggle = millis();
    }
    if (millis() - tempoDisparo >= 5000) {
      digitalWrite(PINO_RELE, LOW);
      alarmeAtivado = false;
      mostrarDisplay = true;
    }
  }

  // Atualiza display se permitido
  if (mostrarDisplay) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(20, 10);
    if (hora < 10) display.print("0");
    display.print(hora);
    display.print(":");
    if (minuto < 10) display.print("0");
    display.print(minuto);

    display.setTextSize(1);
    display.setCursor(50, 40);
    display.print(periodo);
    display.display();
  } else {
    display.clearDisplay();  // Piscar
    display.display();
  }

  // Serial Monitor
  if (!alarmeAtivado) {
    Serial.print("Hora: ");
    if (hora < 10) Serial.print("0");
    Serial.print(hora);
    Serial.print(":");
    if (minuto < 10) Serial.print("0");
    Serial.print(minuto);
    Serial.print(" | Periodo: ");
    Serial.println(periodo);
  }

  delay(1000);
}
