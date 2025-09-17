#include "requisicao.h"
#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void imprime(Requisicao *requisicao) {
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Endereco: %p\nNome        : %40s\nInscricao   : %40d\nProcedimento: %40s\n\n", requisicao, get_nome(requisicao), get_inscricao(requisicao), get_procedimento(requisicao));
    // No objeto Requisição temos os campos: nome (nome da pessoa), inscrição (ordem de chegada), procedimento (procedimento que ele irá realizar)
    // E possui alguns métodos como: get_nome() get_inscricao() e get_procedimento()
}

int main() {
    char nomes[][40] = {"Joao", "Jose", "Maria", "Silvia", "Sonia", "Pedro", "Lucas", "Bernardete", "Lucia", "Olivia"}; 
    //Vetor de nomes de 40 caracteres com quantidade dinâmica de posições
    char procedimentos[][20] = {"123.1", "345.6", "678.9", "098.1", "758.5", "23.4", "5.98", "4,32", "3.3", "1.4"};
    //Vetor de procedimentos de 20 caracteres com quantidade de posições dinâmicas
    Estrutura *estrutura = create();
    // ? O objeto Estrutura possui um método chamado create(), o que ele faz?
    // * Palpite: Create inicializa uma lista vazia
    int i;
    Requisicao *requisicao;
    // Criando um ponteiro para uma requisição sem inicialização
    for(i = 0; i < 10; i++) {
        //Iterando 10 repetições
        requisicao = cria_requisicao(nomes[i], i, procedimentos[i]);
        //O objeto Requisição possui um método cria_requisição que recebe o nome da pessoa, a posição dela na fila e o procedimento que ela quer fazer
        inserir(estrutura, requisicao);
        // ? Chama o método inserir da onde? Da estrutura? esse método faz o que?
        // * Palpite: Inserir insere um valor no fim da fila (push)
        printf("Insercao de %40s, quantidade na estrutura: %04d\n", get_nome(requisicao), get_size(estrutura));
        // Printa o nome do usuário e a quantidade de pessoas na fila (estrutura)
    }
    printf("Fim da insercao.\nInicio da remocao\n");
    for(i = 0; i < 10; i++) {
        Requisicao *r = remover(estrutura);
        // * Palpite: Remove o primeiro da fila (pop)
        printf("Removido    %40s, quantidade na estrutura: %04d\n", get_nome(r), get_size(estrutura));
        imprime(r);
        libera(r);
        // * Palpite: Libera o espaço da memória (dica de que precisamos usar malloc ou calloc)
    }
    libera_estrutura(estrutura);
    return EXIT_SUCCESS;
}
