#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct Estrutura_ Estrutura;
typedef struct Node_ Node;

Estrutura* create();

void inserir(Estrutura* estrutura, Requisicao* requisicao);

int get_size(Estrutura* estrutura);

Requisicao* remover(Estrutura* estrutura);

void libera_estrutura(Estrutura* estrutura);

void libera_node(Node* node);

// Funções utilizadas para debugar, não solicitado no exercício.

//Requisicao* get_last(Estrutura* estrutura);

//Requisicao* get_first(Estrutura* estrutura);

#endif