# Festa Junina

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(1)$**.

Considerando $E$, $S$ e $L$ como pontos em uma reta e $d(a, b)$ a distância entre dois pontos $a$ e $b$, a distância total a ser percorrida será dada por:

$$d(E, S) + d(S, L) + d(L, E)$$

A observação relevante para este problema é o fato de que a ordem dos lugares que Luísa vai não importa, desde que ela saia de $E$, passe por $S$ e $L$ (em qualquer ordem) e volte para $E$.

## Solução

```cpp
#include <iostream>
using namespace std;

int main() {
    int e, s, l;
    cin >> e >> s >> l;

    cout << (abs(e - s) + abs(s - l) + abs(l - e)) << '\n';

    return 0;
}
```