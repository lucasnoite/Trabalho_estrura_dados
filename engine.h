#ifndef ENGINE_H
#define ENGINE_H
#define tipoitem char


#ifndef ENGINE_H
#define ENGINE_H

#define tipoitem char

// Nó da lista
typedef struct Node {
    tipoitem valor;
    struct Node *prox;
} Node;

// Pilha
typedef struct {
    Node *topo;
} *pilha;

// Funções
pilha cria(void);
Node* insert_list(Node *l, tipoitem x);
Node* remove_list(Node *l);
void push(pilha p, tipoitem x);
int is_void(pilha p);
tipoitem pop(pilha p);
void livre(pilha p);
void imprime(pilha p);

int prioridade(char op);

int infix_to_postfix(char infixa[], char posfixa[]);

float avaliar_posfixa(char posfixa[], float valores[]); 


#endif


