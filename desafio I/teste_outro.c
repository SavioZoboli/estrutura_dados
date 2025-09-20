#include "requisicao.h"
#include "estrutura.h"
#include <stdio.h>

int main(){
    Requisicao* requisicao;
    requisicao = cria_requisicao("Savio",1,"123.2");
    Requisicao* requisicao2 = cria_requisicao("Alberto",2,"123.2");
    Requisicao* requisicao3 = cria_requisicao("Leticia",3,"123.2");
    Requisicao* requisicao4 = cria_requisicao("Cleusa",4,"123.2");
    printf("Endereco: %p\nNome        : %40s\nInscricao   : %40d\nProcedimento: %40s\n\n", requisicao, get_nome(requisicao), get_inscricao(requisicao), get_procedimento(requisicao));

    Estrutura* estrutura = create();

    printf("Criado estrutura no endereco %p \n",estrutura);
    
    inserir(estrutura,requisicao);
    inserir(estrutura,requisicao2);
    inserir(estrutura,requisicao3);
    inserir(estrutura,requisicao4);

    printf("Ultimo paciente e %40s \n",get_nome(get_last(estrutura)));
    printf("Primeiro paciente e %40s \n",get_nome(get_first(estrutura)));

    remover(estrutura);

    printf("Ultimo paciente e %40s \n",get_nome(get_last(estrutura)));
    printf("Primeiro paciente e %40s \n",get_nome(get_first(estrutura)));

    libera(requisicao);

    libera_estrutura(estrutura);
    return 0;
}