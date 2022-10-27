#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
/*
Voce devera implementar uma programa que simule o funcionamento de uma
agenda telefonica. Para isso, implemente um programa principal que tenha
um menu retornavel onde o usuario escolhe dentre as opcoes possíveis.

Requisitos funcionais:

-Funcoes da agenda:

1-Insere contato
2-Busca contato por nome
3-Edita contato (pode alterar o nome ou o telefone)
4-Remove contato pelo nome
5-Apagar todos os contatos
6-Encerrar o programa

-E possivel inserir contatos com o mesmo nome, porem nao e possivel inserir
contatos com o mesmo telefone
-Coloque mensagens para informar ao usuario sempre que houver erros.
Por exemplo, quando o contato nao for inserido, pois ja existe um contato
com o mesmo telefone na agenda, ou quando o contato nao for removido por nao
existir na agenda ninguem com aquele nome

Requisitos nao funcionais:

-Nao e permitido o uso de variaveis globais
-Utilize uma lista dinamica simplesmente encadeada como estrutura de dados,
 implementando as funcoes declaradas em agenda.h.
-Nao e permitido adicionar novas funcoes ou alterar a funcoes existentes em
agenda.h. Se for necessario, crie novas funcoes no programa principal

Opcional: implemente funcoes para carregar e salvar contatos em um arquivo
para nao precisar inserir contatos na mao toda vez que quiser testar o programa
*/

void imprimeMenu() {
    printf("\nDigite o numero da opcao desejada:\n");
    printf("1- Inserir contato\n");
    printf("2- Buscar contato\n");
    printf("3- Remover contato\n");
    printf("4- Mostrar lista\n");
    printf("5- Apagar todos os contatos\n");
    printf("0- Sair do Programa\n");
}

void preencheContato(struct contato *dados) {
    printf("Digite o nome:\n");
    fflush(stdin);
    scanf("%s", dados->nome);
    printf("Digite o numero de telefone:\n");
    scanf("%d", &dados->telefone);
}

int main()
{
    Lista *l;
    int opcao = -1;
    char nome[50];
    struct contato *dados;
    l = NULL;
    l = criar();
    dados = (struct contato*)malloc(sizeof(struct contato));

    while(opcao != 0){
        imprimeMenu();
        scanf("%d", &opcao);
        if(opcao == 1){
            preencheContato(dados);
            insereContato(l, *dados);
        }else if(opcao == 2){
            printf("\nInforme o nome do contato: ");
            fflush(stdin);
            gets (nome);
            buscaContato(l, nome, dados);
            printf("--------------------------------\n");
            printf("Nome: %s\nTelefone: %d\n", dados->nome, dados->telefone);
            printf("--------------------------------\n");
        }else if(opcao == 3){
            printf("Informe o nome do contato: ");
            fflush(stdin);
            gets (nome);
            removeContato(l, nome);
        }else if(opcao == 4){
            if(vazia(l)) printf("Lista vazia.\n");
            imprimeLista(l);
        }else if(opcao == 5){
            destruir(l);
            printf("Todos os contatos foram apagados com sucesso.\n");
        }else if(opcao == 0){
            printf("Finalizando o programa\n");
            destruir(l);
        }else{
            printf("Opcao invalida. Tente novamente\n");
        }
    }













    return 0;
}
