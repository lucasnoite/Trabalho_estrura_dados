#include <stdio.h>
#include <stdlib.h>
#include "engine.h"


pilha cria(void){
    pilha p = (pilha) malloc(sizeof(*p));
    p->topo = NULL;
    return p;
}


Node* insert_list(Node *l, tipoitem x){
    Node* p = (Node*) malloc(sizeof(Node));
    p->valor = x;
    p->prox = l;
    return p;
}


Node* remove_list(Node *l){
    if (l == NULL) return NULL;
    Node* next = l->prox;
    free(l);
    return next;
}


void push(pilha p, tipoitem x){
    p->topo = insert_list(p->topo, x);
}


int is_void(pilha p){
    return (p->topo == NULL);
}


tipoitem pop(pilha p){
    if(is_void(p)){
        printf("Pilha vazia!\n");
        return '\0';
    }
    tipoitem v = p->topo->valor;
    p->topo = remove_list(p->topo);
    return v;
}


void livre(pilha p){
    Node* q = p->topo;
    while(q != NULL){
        Node* tmp = q->prox;
        free(q);
        q = tmp;
    }
    free(p);
}


void imprime(pilha p){
    Node* q = p->topo;
    while(q != NULL){
        printf("%c ", q->valor);
        q = q->prox;
    }
    printf("\n");
}

int prioridade(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

float avaliar_posfixa(char posfixa[], float valores[]) {

    pilha p = cria();
    float op1, op2;
    char c;
    char buffer[40]; 
    float result;

    for (int i = 0; posfixa[i] != '\0'; i++) {

        c = posfixa[i];

        
        if (isalpha(c)) {
            float v = valores[c - 'A'];

            
            tipoitem x;
            float* ptr = (float*)&x;
            *ptr = v;

            push(p, x);
        }

      
        else if (c=='+' || c=='-' || c=='*' || c=='/') {

           
            if (p->topo == NULL || p->topo->prox == NULL) {
                printf("ERRO: operandos insuficientes na expressão!\n");
                return 0;
            }

          
            tipoitem t2 = pop(p);
            tipoitem t1 = pop(p);

            float *f2 = (float*)&t2;
            float *f1 = (float*)&t1;

            op1 = *f1;
            op2 = *f2;

            float r = 0;

            if (c == '+') r = op1 + op2;
            if (c == '-') r = op1 - op2;
            if (c == '*') r = op1 * op2;

            if (c == '/') {
                if (op2 == 0) {
                    printf("ERRO: divisão por zero!\n");
                    return 0;
                }
                r = op1 / op2;
            }

           
            tipoitem aux;
            float* pf = (float*)&aux;
            *pf = r;

            push(p, aux);
        }

        else {
            printf("ERRO: símbolo inválido na pós-fixa: %c\n", c);
            return 0;
        }
    }

    
    if (p->topo == NULL || p->topo->prox != NULL) {
        printf("ERRO: expressão pós-fixa inválida!\n");
        return 0;
    }

    tipoitem t = pop(p);
    float* ptr = (float*)&t;
    result = *ptr;

    return result;
}

int infix_to_postfix(char infixa[], char posfixa[]) {
    pilha p = cria();
    int j = 0; 
    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];

        if (c == ' ') continue; 

      
        if (isalpha(c)) {
            posfixa[j++] = c;
        }

        
        else if (c == '(') {
            push(p, c);
        }

       
        else if (c == ')') {
            while (!is_void(p) && p->topo->valor != '(')
                posfixa[j++] = pop(p);

            if (is_void(p)) {
                printf("ERRO: Parênteses desbalanceados!\n");
                return 0;
            }
            pop(p); 
        }

        
        else if (c=='+' || c=='-' || c=='*' || c=='/') {

            while (!is_void(p) &&
                   prioridade(p->topo->valor) >= prioridade(c))
            {
                posfixa[j++] = pop(p);
            }
            push(p, c);
        }

        else {
            printf("ERRO: Símbolo inválido encontrado: %c\n", c);
            return 0;
        }
    }

    
    while (!is_void(p)) {
        char op = pop(p);
        if (op == '(') {
            printf("ERRO: Parênteses desbalanceados!\n");
            return 0;
        }
        posfixa[j++] = op;
    }

    posfixa[j] = '\0';
    return 1;
}
