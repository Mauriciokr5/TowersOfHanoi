#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct Nodo{
  Elem dato;
  struct Nodo *next;
} *Pila;

void ImpElem(Elem x){ printf("%d", x);}

int EsMenor(Elem x, Elem y){ return x<y; }

Pila empty(){ return NULL; }

Pila push(Elem e, Pila l){
  Pila t = (Pila)malloc(sizeof(struct Nodo));
  t->dato=e;
  t->next=l;
  return t;
}

int isempty(Pila l){ return l==NULL; }
Elem top(Pila l){ return l->dato; }
Pila pop(Pila l){ return l->next; }
