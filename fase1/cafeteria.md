# Cafeteria

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(1)$**.

O problema consiste em determinar se existe algum número de doses de café que podem ser adicionadas à xícara tal que a quantidade restante seja um número entre $a$ e $b$.

Formalmente, o problema consiste em determinar o valor-verdade da seguinte proposição:

$$\exists x \in \N (a \leq c - d \cdot x \land c - d \cdot x \leq b)$$

Isso pode ser resolvido de forma iterativa, encontrando o menor valor de $x$ tal que:

$$c - d \cdot x \leq b$$

e verificando se:

$$a \leq c - d \cdot x$$

## Solução

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x;
    for (x = 0; b < c - d * x; x++);

    if (a <= c - d * x) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}
```

Esse problema também pode ser resolvido utilizando as definições matemáticas:

$$a \leq c - d \cdot x \leq b$$

Isolando o $x$ da desigualdade da esquerda:

$$a \leq c - d \cdot x$$
$$a - c \leq -(d \cdot x)$$
$$c - a \geq d \cdot x$$
$$\frac{c - a}{d} \geq x$$

Isolando o $x$ da desigualdade da direita:

$$c - d \cdot x \leq b$$
$$-(d \cdot x) \leq b - c$$
$$d \cdot x \geq c - b$$
$$x \geq \frac{c - b}{d}$$

Assim, obtemos:

$$\frac{c - b}{d} \leq x \leq \frac{c - a}{d}$$

Sabendo que os valores são inteiros, arredondamos os valores para cima e para baixo (_ceil_ e _floor_), da esquerda para a direita.

$$\lceil{\frac{c - b}{d}} \rceil \leq x \leq \lfloor{\frac{c - a}{d}} \rfloor$$

Para que o intervalo não seja vazio, isto é, para que exista ao menos um valor $x \in \N$ válido, verificamos se o final do intervalo é maior ou igual ao início. Em caso positivo, a resposta para o problema é sim, em caso contrário, a resposta é não.

$$\lceil{\frac{c - b}{d}} \rceil \leq \lfloor{\frac{c - a}{d}} \rfloor$$

## Solução

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((c - b + d - 1) / d <= (c - a) / d) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}
```
