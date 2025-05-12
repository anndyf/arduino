# Funções Personalizadas no Arduino 🔧

As **funções** permitem agrupar instruções para facilitar a leitura, reutilização e organização do código. No Arduino, as funções personalizadas seguem a mesma lógica do C/C++.

---

## 🧱 Estrutura de uma Função

```cpp
tipo nomeDaFuncao(parâmetros) {
  // código
  return valor;  // se a função não for void
}
```

---

## ✅ Exemplo 1: Função sem parâmetros e sem retorno

```cpp
void acenderLed() {
  digitalWrite(13, HIGH);
}
```

🧠 Essa função apenas executa uma ação, sem receber nem retornar dados.

---

## ✅ Exemplo 2: Função com parâmetro (sem retorno)

```cpp
void piscarLed(int pino) {
  digitalWrite(pino, HIGH);
  delay(500);
  digitalWrite(pino, LOW);
  delay(500);
}
```

📌 Ao chamar `piscarLed(9);`, o LED no pino 9 piscará por 0,5s.

---

## ✅ Exemplo 3: Função com retorno (retorna um valor)

```cpp
int dobrar(int numero) {
  return numero * 2;
}
```

Uso:

```cpp
int resultado = dobrar(5);  // resultado será 10
```

---

## ✅ Exemplo 4: Função para ler sensor e decidir ação

```cpp
bool estaClaro(int pinoSensor) {
  int valor = analogRead(pinoSensor);
  return valor < 400;
}
```

Uso:

```cpp
if (estaClaro(A0)) {
  digitalWrite(13, LOW);  // apaga LED se estiver claro
} else {
  digitalWrite(13, HIGH); // acende LED se estiver escuro
}
```

---

## 🔁 Reaproveitamento com Parâmetros

Você pode usar múltiplos parâmetros para tornar suas funções reutilizáveis:

```cpp
void controlarDispositivo(int pino, bool estado) {
  digitalWrite(pino, estado ? HIGH : LOW);
}
```

Uso:

```cpp
controlarDispositivo(7, true);   // liga
controlarDispositivo(7, false);  // desliga
```

---

## 📌 Observações

| Tipo de função | Palavra-chave | Retorno         |
|----------------|----------------|------------------|
| Procedimento   | `void`         | Nenhum           |
| Função simples | `int`, `bool`, `float` | Retorna valor |

---

## 🧠 Boas Práticas

- Nomeie funções com verbos que indicam ação (ex: `lerSensor()`, `ligarLed()`)
- Use funções para evitar repetição de código
- Separe funções de controle e de leitura para clareza

---

## 📚 Recursos Úteis

- [Funções em Arduino – Arduino.cc](https://www.arduino.cc/reference/en/#functions)
- [Tutorial de funções – Aprendendo Arduino](https://www.arduinoecia.com.br/arduino-funcoes/)