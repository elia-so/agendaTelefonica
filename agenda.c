#include <stdlib.h>
#include <stdio.h>
#include "agenda.h"
#include <string.h>

//DADOS DA ESTRUTURA ELEMENTO.
struct elemento {
    struct contato dados;
    struct elemento *proximo;
};
//DEFININDO A ESTRUTURA ELEMENTO.
typedef struct elemento Elemento;

//CRIANDO A LISTA QUE VAI APONTAR PARA O INICIO DA LISTA.
Lista* criar() {
    Lista *l;
    l = (Lista*)malloc(sizeof(Lista));
    if(l != NULL) {
        *l = NULL;
    }
    return l;
}
//CRIANDO UM AUX PARA NAO PERDER A REFERENCIA DO ELEMENTO E ASSIM CONSEGUIR REMOVER O ELEMENTO.
void destruir(Lista *li) {
    if(*li == NULL) {
        free(*li);
    }else {
        Elemento *aux;
        while(*li != NULL) {
            aux = *li;
            *li = (*li)->proximo;
            free(aux);
        }
    }
}
//VERIFICA SE A LISTA ESTÁ VAZIA.
int vazia(Lista *ldse){
    if(ldse == NULL){
        return 1;
    }else if(*ldse == NULL){
        return 1;
    }else{
        return 0;
    }
}

int insereContato(Lista* l, struct contato ctt) {
    if(l == NULL) return 0;
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL) return 0;

    Elemento* aux = *l;
    while(aux != NULL){
        if(ctt.telefone == aux->dados.telefone){
            printf("\nNao e possivel inserir contatos com o mesmo telefone.\n");
            return 0;
        }
        aux = aux->proximo;
    }

    novo->dados = ctt;
    novo->proximo = (*l);
    *l = novo;
    return 1;
}

int buscaContato(Lista* l, char nome[50], struct contato* ctt) {
    if(vazia(l)) return 0;
    for(Elemento* i = *l; i != NULL; i = i->proximo) {
        if(!strcmp(i->dados.nome, nome)) {
            *ctt = i->dados;
            return 1;
        }
    }
    return 0;
}

int removeContato(Lista *l, char nome[50]) {
    if(*l == NULL) {
        printf("A lista esta vazia.\n");
        return 0;
    }
    if(vazia(l)) {
        return 0;
    }else if(!strcmp((*l)->dados.nome, nome)) {
        Elemento *aux = *l;
        *l = aux->proximo;
        free(aux);
        return 1;
    } else {
        Elemento *ant = *l;
        Elemento *aux = ant->proximo;
        while(aux != NULL && strcmp(aux->dados.nome, nome)) {
            ant = aux;
            aux = aux->proximo;
        }
        if(aux == NULL) {
            printf("Contato inexistente.\n");
            return 0;
        }
        ant->proximo = aux->proximo;
        free(aux);
        printf("Contato removido com sucesso.\n");
        return 1;
    }
}

int imprimeLista(Lista *l){
    if(l== NULL){
        return 0;
    }else{
        Elemento *aux = *l;
        while(aux != NULL){
            printf("--------------------------------\n");
            printf("Nome: %s\nTelefone: %d\n", aux->dados.nome, aux->dados.telefone);
            printf("--------------------------------\n");
            aux = aux->proximo;
        }
        return 1;
    }
}
