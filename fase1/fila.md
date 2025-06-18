# Fila

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(n)$**.

Um aluno conseguirá colar na prova se e somente se houver algum aluno com altura maior ou igual a dele à sua direita.

Formalmente, considerando $n$ o número de alunos e que cada um possui um índice $i$ tal que $(1 \leq i \leq n)$, e considerando $a_{i}$ a altura do $i$-ésimo aluno, o aluno $i$ conseguirá colar na prova se e somente se houver algum aluno $j$ tal que:

$$i < j \ ∧ a_{i} < a_{j}$$

Para verificar isso, vamos analisar todos os alunos da direita para a esquerda, e manter salva a maior altura que encontrarmos. Se a altura $a_{i}$ for menor ou igual a maior altura atual, significa que o aluno $i$ consegue colar. Em caso contrário, o aluno $i$ não consegue colar, e a maior altura atual passará a ser $a_{i}$. Inicialmente, a maior altura é a do aluno mais à direita, que nunca conseguirá colar.

## Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maior_altura = a[n - 1];
    int contador = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= maior_altura) {
            contador++;
        }
        else {
            maior_altura = a[i];
        }
    }

    cout << contador << '\n';

    return 0;
}
```