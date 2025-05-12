
# Condicionais e Operadores no Arduino 🔀

As **estruturas condicionais** são usadas para tomar decisões no código. Combinadas com operadores, elas permitem que o programa responda a diferentes situações, como acender um LED se um botão estiver pressionado.

---

## 🧭 `if`, `else if`, `else`

### ✅ `if`: executa um bloco se a condição for verdadeira

```cpp
if (digitalRead(2) == HIGH) {
  digitalWrite(13, HIGH);
}
```

### 🔁 `else`: executa se a condição do `if` for falsa

```cpp
if (digitalRead(2) == HIGH) {
  digitalWrite(13, HIGH);
} else {
  digitalWrite(13, LOW);
}
```

### 🔄 `else if`: testa outras condições

```cpp
int valor = analogRead(A0);

if (valor > 800) {
  // muito claro
} else if (valor > 400) {
  // média luz
} else {
  // pouca luz
}
```

---

## ⚙️ Operadores de Comparação

| Operador | Significado     | Exemplo          | Resultado   |
|----------|------------------|------------------|-------------|
| `==`     | Igual            | `x == 10`        | `true` se `x` for 10 |
| `!=`     | Diferente        | `x != 5`         | `true` se `x` não for 5 |
| `>`      | Maior que        | `x > 100`        | `true` se `x` maior que 100 |
| `<`      | Menor que        | `x < 10`         | `true` se `x` menor que 10 |
| `>=`     | Maior ou igual   | `x >= 50`        | `true` se `x` ≥ 50 |
| `<=`     | Menor ou igual   | `x <= 300`       | `true` se `x` ≤ 300 |

---

## 🔗 Operadores Lógicos

| Operador | Significado          | Exemplo                        |
|----------|----------------------|--------------------------------|
| `&&`     | E (AND)              | `x > 10 && x < 50`             |
| `||`     | OU (OR)              | `x < 10 || x > 90`             |
| `!`      | NÃO (NOT)            | `!estado` inverte o valor booleano |

---

## 🧠 Boas Práticas

- Use parênteses para agrupar expressões complexas.
- Compare sensores com `if` e atue com `digitalWrite`, `analogWrite`, etc.
- Não confunda `=` (atribuição) com `==` (comparação).

---

## 📚 Recursos Úteis

- [Condicional – Arduino Reference](https://www.arduino.cc/reference/en/#structure-control)
- [Operadores – C++ Arduino](https://www.arduino.cc/reference/en/#structure-operators)
