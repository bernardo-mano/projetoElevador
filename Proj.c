#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int frequencia;
} Temperatura;

int main() {
    int i, j, n = 20;
    int *vetor;
    Temperatura *relatorio;
    int count = 0;

   
    vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }
// o usurio digita as temperaturas, que são armazenadas acima no vetor dinamico (malloc)
    printf("Digite as %d temperaturas:\n", n);
    for (i = 0; i < n; i++) {
        printf("Temperatura %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }


    relatorio = (Temperatura *)malloc(n * sizeof(Temperatura));
    if (relatorio == NULL) {
        printf("Erro de alocação de memória.\n");
        free(vetor);
        return 1;
    }

    // Contagem de quantas vezes cada temperatura aparece
    for (i = 0; i < n; i++) {
        int encontrado = 0;
        for (j = 0; j < count; j++) {
            if (relatorio[j].valor == vetor[i]) {
                relatorio[j].frequencia++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            relatorio[count].valor = vetor[i];
            relatorio[count].frequencia = 1;
            count++;
        }
    }

    // ordenando do maior para a menor frequência
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (relatorio[i].frequencia < relatorio[j].frequencia) {
                Temperatura temp = relatorio[i];
                relatorio[i] = relatorio[j];
                relatorio[j] = temp;
            }
        }
    }

    // Impressão do relatório
    printf("\nRELATÓRIO DE FREQUÊNCIA\n");
    printf("=======================\n");
    for (i = 0; i < count; i++) {
        printf("%d - %d %s\n", relatorio[i].valor, relatorio[i].frequencia,
               relatorio[i].frequencia > 1 ? "VEZES" : "VEZ");
    }


    free(vetor);
    free(relatorio);

    return 0;
}
