#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "requisicao.h"

const char* get_nome(Requisicao* requisicao){
    return requisicao->nome;
}

const char* get_inscricao(Requisicao* requisicao){
    return requisicao->inscricao;
}

const char* get_procedimento(Requisicao* requisicao){
    return requisicao->procedimento;
}

Requisicao* cria_requisicao(char nome[40],char inscricao[40],char procedimento[40]){
    Requisicao* requisicao = (Requisicao*)malloc(sizeof(Requisicao));
    if(requisicao == NULL){
        printf("Alocacao de memoria mal sucedida!\n");
        return NULL;
    }
    strncpy(requisicao->nome,nome,sizeof(requisicao->nome - 1));
    requisicao->nome[sizeof(requisicao->nome - 1)] = '\0';
    strncpy(requisicao->inscricao,inscricao,sizeof(requisicao->inscricao - 1));
    requisicao->inscricao[sizeof(requisicao->inscricao - 1)] = '\0';
    strncpy(requisicao->procedimento,procedimento,sizeof(requisicao->procedimento - 1));
    requisicao->procedimento[sizeof(requisicao->procedimento - 1)] = '\0';

    return requisicao;
}

int libera(Requisicao* requisicao){
    free(requisicao);
}