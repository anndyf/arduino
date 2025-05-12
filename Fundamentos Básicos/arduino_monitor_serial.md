
# Monitor Serial no Arduino 📟

O **Monitor Serial** é uma ferramenta da IDE do Arduino que permite enviar e receber dados do Arduino para o computador via porta USB. Ele é essencial para **debug**, **leituras de sensores** e **interação com o usuário**.

---

## 🔌 Iniciando a Comunicação

```cpp
void setup() {
  Serial.begin(9600);
}
```

- `Serial.begin(9600)`: inicia a comunicação na velocidade de **9600 bauds** (valor padrão).
- Deve estar dentro do `setup()`.

---

## 🖨️ Enviando Dados para o Computador

### `Serial.print()`

Envia texto ou valores sem pular linha.

```cpp
Serial.print("Temperatura: ");
Serial.print(25);
```

### `Serial.println()`

Envia texto ou valores e pula para a próxima linha.

```cpp
Serial.println("Arduino conectado!");
```

---

## 📥 Lendo Dados do Usuário (Entrada Serial)

```cpp
if (Serial.available() > 0) {
  int valor = Serial.parseInt();  // Lê número inteiro enviado
  Serial.print("Valor recebido: ");
  Serial.println(valor);
}
```

---

## 📊 Exemplo Completo

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(A0);
  Serial.print("Sensor A0: ");
  Serial.println(leitura);
  delay(1000);
}
```

Abra o **Monitor Serial** (lupa no canto superior direito da IDE) para visualizar os dados.

---

## 🧠 Boas Práticas

- Certifique-se de que o baud rate no Monitor Serial seja o mesmo do `Serial.begin()`.
- Use `Serial.print()` para debug em tempo real.
- Não use `Serial.read()` sem verificar `Serial.available()` antes.

---

## 📚 Recursos Úteis

- [Serial – Arduino Reference](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
- [Tutorial de Serial Monitor – Arduino](https://docs.arduino.cc/built-in-examples/communication/serial)

