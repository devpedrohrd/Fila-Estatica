#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h" //inclui os Protótipos

// Definição do tipo Fila
struct fila
{
    int inicio, final;         // variáveis que indicam o início e o final da fila
    struct numeros dados[MAX]; // vetor que armazena os elementos da fila
};

Fila *cria_Fila()
{
    Fila *fi; // declaração do ponteiro para uma estrutura do tipo Fila

    fi = (Fila *)malloc(sizeof(struct fila)); // aloca dinamicamente um espaço de memória do tamanho da estrutura Fila
    if (fi != NULL)
    {                   // verifica se a alocação foi bem sucedida
        fi->inicio = 0; // inicializa o início da fila
        fi->final = 0;  // inicializa o final da fila
        fi->final = 0;  // inicializa o final da fila
    }
    return fi; // retorna o ponteiro para a fila criada
}

void libera_Fila(Fila *fi)
{
    free(fi); // libera o espaço de memória alocado
}

int consulta_Fila(Fila *fi, struct numeros *num)
{
    if (fi == NULL || Fila_vazia(fi)) // verifica se a fila foi criada e se está vazia
        return 0;
    int pos = (fi->inicio + 1) % MAX; // calcula a posição do primeiro elemento da fila
    fi->dados[pos] = *num;            // copia o conteúdo da estrutura num para fi->dados[pos]
    return 1;
}

int insere_Fila(Fila *fi, struct numeros num)
{
    if (fi == NULL) // verifica se a fila foi criada
        return 0;
    if (Fila_cheia(fi)) // verifica se a fila está cheia
        return 0;
    fi->final = (fi->final + 1) % MAX;
    fi->dados[fi->final] = num; // insere o elemento no final da fila
    return 1;
}

int remove_Fila(Fila *fi)
{
    if (fi == NULL || Fila_vazia(fi)) // verifica se a fila foi criada e se está vazia
        return 0;
    fi->inicio = (fi->inicio + 1) % MAX; // remove o elemento do início da fila

    return 1;
}

int tamanho_Fila(Fila *fi)
{
    if (fi == NULL) // verifica se a fila foi criada
        return -1;
    int cont = 0;          // inicializa o contador
    int i = fi->inicio;    // inicializa o i com o início da fila
    while (i != fi->final) // percorre a fila até o final
    {
        i = (i + 1) % MAX; // incrementa o i e verifica se chegou ao final da fila
        cont++;            // incrementa o contador
    }
    return cont; // retorna o tamanho da fila
}

int Fila_cheia(Fila *fi)
{
    if (fi == NULL) // verifica se a fila foi criada
        return -1;
    if (fi->inicio == (fi->final + 1) % MAX) // verifica se a fila está cheia
        return 1;
    else
        return 0; // fila não está cheia
}

int Fila_vazia(Fila *fi)
{
    if (fi == NULL) // verifica se a fila foi criada
        return -1;
    return (fi->inicio == fi->final); // retorna 1 se a fila estiver vazia e 0 caso contrário
}

void imprime_Fila(Fila *fi)
{
    if (fi == NULL) // verifica se a fila foi criada
        return;
    int i = fi->inicio;    // inicializa o i com o início da fila
    while (i != fi->final) // percorre a fila até o final
    {
        i = (i + 1) % MAX;                           // incrementa o i e verifica se chegou ao final da fila
        printf("Número: %d\n", fi->dados[i].numero); // imprime os elementos da fila

        printf("-------------------------------\n");
    }
}
