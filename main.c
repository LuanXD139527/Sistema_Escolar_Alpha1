#include <stdio.h>

#define LIMITE_ALUNOS 100

// Lê um inteiro >= min, repetindo até a entrada ser válida
int ler_inteiro(const char *mensagem, int min) {
    char linha[64];
    int valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return min;   // fim da entrada (EOF): evita loop infinito
        }

        // sscanf retorna 1 se leu um inteiro com sucesso
        if (sscanf(linha, "%d", &valor) == 1 && valor >= min) {
            return valor;
        }

        printf("Valor invalido. Tente novamente.\n");
    }
}

int main() {
    int total_alunos = 0;
    int disciplinas_contadas = 0;

    printf("=== Contagem de alunos matriculados ===\n");

    int total_disciplinas = ler_inteiro("Numero de disciplinas: ", 1);

    for (int i = 1; i <= total_disciplinas; i++) {
        char mensagem[64];
        snprintf(mensagem, sizeof(mensagem), "Alunos na disciplina %d: ", i);

        int alunos = ler_inteiro(mensagem, 0);

        total_alunos += alunos;
        disciplinas_contadas++;

        if (total_alunos >= LIMITE_ALUNOS) {
            printf("Limite de %d alunos atingido. Encerrando.\n", LIMITE_ALUNOS);
            break;
        }
    }

    printf("\nDisciplinas contadas: %d\n", disciplinas_contadas);
    printf("Total de alunos: %d\n", total_alunos);

    return 0;
}