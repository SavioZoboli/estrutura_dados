#include "requisicao.h"
#include <stdio.h>

int main(){
    Requisicao* requisicao;
    requisicao = cria_requisicao("Savio","1","123.2");
    printf("Endereco: %p\nNome        : %40s\nInscricao   : %40d\nProcedimento: %40s\n\n", requisicao, get_nome(requisicao), get_inscricao(requisicao), get_procedimento(requisicao));

    libera(requisicao);
    return 0;
}