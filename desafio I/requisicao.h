// Por enquanto o procedimento parece possuir esses dados aqui:
// Atributos: Nome, Inscrição e Procedimento
// Métodos: get_nome, get_inscricao e get_procedimento, cria_requisicao(nome,inscricao,procedimento)

#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct Requisicao {
    char nome[40];
    char inscricao[40];
    char procedimento[40];
} Requisicao;



const char* get_nome(Requisicao* requisicao);

const char* get_inscricao(Requisicao* requisicao);

const char* get_procedimento(Requisicao* requisicao);

Requisicao* cria_requisicao(char nome[40],char inscricao[40],char procedimento[40]);

int libera(Requisicao* requisicao);

#endif