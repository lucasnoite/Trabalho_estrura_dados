#ifndef ENGINE_H
#define ENGINE_H

#define tipoitem char


typedef struct Node {
    tipoitem valor;
    struct Node *prox;
} Node;


typedef struct {
    Node *topo;
} *pilha;


pilha cria(void);
Node* insert_list(Node *l, tipoitem x);
Node* remove_list(Node *l);
void push(pilha p, tipoitem x);
int is_void(pilha p);
tipoitem pop(pilha p);
void livre(pilha p);
void imprime(pilha p);

#endif
