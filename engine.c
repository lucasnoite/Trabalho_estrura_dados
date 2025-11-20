#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

// Criar pilha
pilha cria(void){
    pilha p = (pilha) malloc(sizeof(*p));
    p->topo = NULL;
    return p;
}

// Inserir no início da lista
Node* insert_list(Node *l, tipoitem x){
    Node* p = (Node*) malloc(sizeof(Node));
    p->valor = x;
    p->prox = l;
    return p;
}

// Remover do início da lista
Node* remove_list(Node *l){
    if (l == NULL) return NULL;
    Node* next = l->prox;
    free(l);
    return next;
}

// Push
void push(pilha p, tipoitem x){
    p->topo = insert_list(p->topo, x);
}

// Pilha vazia
int is_void(pilha p){
    return (p->topo == NULL);
}

// Pop
tipoitem pop(pilha p){
    if(is_void(p)){
        printf("Pilha vazia!\n");
        return '\0';
    }
    tipoitem v = p->topo->valor;
    p->topo = remove_list(p->topo);
    return v;
}

// Liberar pilha
void livre(pilha p){
    Node* q = p->topo;
    while(q != NULL){
        Node* tmp = q->prox;
        free(q);
        q = tmp;
    }
    free(p);
}

// Imprimir
void imprime(pilha p){
    Node* q = p->topo;
    while(q != NULL){
        printf("%c ", q->valor);
        q = q->prox;
    }
    printf("\n");
}
