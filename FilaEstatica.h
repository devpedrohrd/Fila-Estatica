//Arquivo FilaEstatica.h
#define MAX 5 //tamanho maximo da fila
struct numeros{
    int numero; //numero a ser inserido na fila
};

typedef struct fila Fila; //definicao do tipo fila

Fila* cria_Fila();
void libera_Fila(Fila* fi); 
int consulta_Fila(Fila* fi, struct numeros *num);
int insere_Fila(Fila* fi, struct numeros num);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);

