#include "estrutura.h"
#include "requisicao.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node_ {
    Requisicao* requisicao;
    Node* next;
} Node;

typedef struct Estrutura_ {
    Node* head;
    Node* last;
    int tamanho;
} Estrutura;

Estrutura* create(){
    Node* head = (Node*) malloc(sizeof(Node));
    if(head == NULL) return NULL;
    head->requisicao = NULL;
    head->next = NULL;
    Estrutura* estrutura = (Estrutura*) malloc(sizeof(Estrutura));
    if(estrutura == NULL) return NULL;
    estrutura->head = head;
    estrutura->last = NULL;
    estrutura->tamanho = 0;
    return estrutura;
}

void inserir(Estrutura* estrutura,Requisicao* requisicao){
    Node* novo = (Node*) malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->requisicao = requisicao;
    novo->next = NULL;
    // Pegar o ultimo endereço da fila, colocar o next como o endereço do item que estamos inserindo
    Node* last = estrutura->last;
    if(last == NULL){ // Caso não possua nodes inseridos (fila vazia)
        // Adiciona como primeiro node
        Node* head = estrutura->head;
        head->next = novo;
    }else{
        // Adiciona na sequência
        last->next = novo;
    }

    estrutura->last = novo;
    estrutura->tamanho++;
}

int get_size(Estrutura* estrutura){
    return estrutura->tamanho;
}

Requisicao* remover(Estrutura* estrutura){
    Node* primeiro = estrutura->head->next;
    if(primeiro == NULL) return NULL;
    estrutura->head->next = primeiro->next;
    libera_node(primeiro);
    estrutura->tamanho--;
    return primeiro->requisicao;
}

void libera_node(Node* node){
    printf("Liberado node %p \n",node);
    free(node);
}


void libera_estrutura(Estrutura* estrutura){
    // Iterar nos nós até que ache o nó com o next = NULL
    // Ir armazenando em uma variavel o endereço do proximo nó
    // Desalocar o nó e partir para o próximo
    // por fim, liberar a estrutura

    Node* node = estrutura->head->next;
    while(node != NULL){
        Node* liberado = node;
        node = node->next;
        libera_node(liberado);
    }
    printf("Liberando a estrutura %p \n",estrutura);
    free(estrutura);
}

// Funções utilizadas para debugar, não solicitado no exercício.

/*

Requisicao* get_first(Estrutura* estrutura){
    return estrutura->head->next->requisicao;
}

Requisicao* get_last(Estrutura* estrutura){
    return estrutura->last->requisicao;
}

*/



