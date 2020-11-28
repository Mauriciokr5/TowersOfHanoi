/*#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Pila.h"

using namespace std;

int counter = 0;

char towerName(Pila tower){
  switch(top(tower)){
    case -1:return 'A';
    case -2:return 'B';
    case -3:return 'C';
    default:return 0;
  }
}
Pila pushTower(Elem disk,Pila tower){
  Elem towerID = top(tower);
  return push(towerID, push(disk, pop(tower)));
}
Pila popTower(Pila tower){
  Elem towerID = top(tower);
  return push(towerID, pop(pop(tower)));
}
Elem topTower(Pila tower){ return top(pop(tower));}
Pila createTower(int NumDisk, Pila p){
  for (int i = NumDisk; i>0; i--)
    p = pushTower(i,p);
  return p;
}
void printPila(Pila pila){
  if(!isempty(pila)) {
    printf("\t|\t%d\t|\n",top(pila));
    printPila(pop(pila));
  }
}
void printPilas(Pila pila){
  printPila(pop(pila) );
  printf("\t—————————————————\n");
  printf("\t\t%c\n\n\n", towerName(pila));
}
void mover(Pila from, Pila to, Pila *ptrFrom, Pila *ptrTo){
  *ptrTo=push(top(from),to);
  *ptrFrom=pop(from);
}



void tower(int a,Pila &from,Pila &aux,Pila &to){
  Elem auxEle;

    if(a==1){
      printf("     Movemos el disco 1 de %c a %c\n", towerName(from), towerName(to));
      to = pushTower(topTower(from),to);
      from = popTower(from);

       printPilas( from);
       printPilas( aux);
       printPilas( to);
       counter++;
       return;
    }
    else{
       tower(a-1,from,to,aux);
       printf("     Movemos el disco %d de %c a %c\n", a, towerName(from), towerName(to));
       to = pushTower(topTower(from),to);
       from = popTower(from);
       printPilas( from);
       printPilas( aux);
       printPilas( to);
       counter++;

       tower(a-1,aux,from,to);
    }

}


int main(){
  Pila pilaA, pilaB, pilaC;
  pilaA = push(-1,empty());
  pilaB = push(-2,empty());
  pilaC = push(-3,empty());


     int n;
     printf("          Torre de Hanoi\n");
     printf("     Ingese numero de discos:");
     scanf("\t%d", &n);
     pilaA = createTower(n,pilaA);

     printPilas( pilaA);
     printPilas( pilaB);
     printPilas( pilaC);

     tower(n,pilaA,pilaB,pilaC);

     printf("Total de movimientos: %d\n", counter);

     getchar();

     return 0;
}*/
#include "stdio.h"
#include "stdlib.h"
//constante
#define TAMPILA 10

//declarar la pila
struct pila {
	int item[TAMPILA];
	int tope;
};
typedef struct pila TDA_PILA;

//funciones prototipos pila
int push(TDA_PILA& p, int e);
int pop(TDA_PILA& p, int& e);
int stacktop(TDA_PILA p, int& e);
int empty(TDA_PILA p);
void startpila(TDA_PILA& p);

//funciones prototipos torre de hanoi
void t_Hanoi(int n, TDA_PILA& A, TDA_PILA& B, TDA_PILA& C,
	TDA_PILA* a, TDA_PILA* b, TDA_PILA* c);
void mostrar(TDA_PILA C);

int main() {
	int n;

	//crear e inicializar las torres (pilas)
	//La torre A sera usada como torre de origen
	//La torre B sera usada como torre auxiliar
	//La torre C sera usada como torre de destino
	TDA_PILA A, B, C;
	startpila(A);
	startpila(B);
	startpila(C);

	//obtener las posiciones de las torres
	TDA_PILA* a = &A;
	TDA_PILA* b = &B;
	TDA_PILA* c = &C;


	printf("******\tTORRE DE HANOI\t******");

	printf("\nIngrese la cantidad de disco(s): ");
	scanf("%d", &n);

	printf("\nInicializando la Torre A con disco(s) del 1 al %d", n);
	for (int i = n; i > 0; i--)
		push(A, i);
	printf("\n\tTorre llena exitosamente");

	printf("\nLos elementos de la Torre A son: ");
	mostrar(A);
	printf("\n\t");
	system("pause");

	t_Hanoi(n, A, B, C, a, b, c);

	printf("\n\tDiscos movidos exitosamente");
	printf("\nLos elementos de la Torre C son: ");
	mostrar(C);

	printf("\n\t");
	system("pause");
	return 0;
}

//Ingresar los discos a la torre
int push(TDA_PILA& p, int e) {
	if (p.tope == TAMPILA - 1)
		return 0;
	p.item[++p.tope] = e;
	return 1;
}

//Sacar los discos a la torre
int pop(TDA_PILA& p, int& e) {
	if (empty(p))
		return 0;
	e = p.item[p.tope--];
	return 1;
}

//Funcion de pila
int stacktop(TDA_PILA p, int& e) {
	if (empty(p))
		return 0;
	e = p.item[p.tope];
	return 1;
}

//Conocer si la torre esta vacia
int empty(TDA_PILA p) {
	if (p.tope == -1)
		return 1;
	return 0;
}

//Iniciar Pila
void startpila(TDA_PILA& p) {
	p.tope = -1;
}

//Implementar torre de hanoi recursiva
void t_Hanoi(int n, TDA_PILA& A, TDA_PILA& B, TDA_PILA& C,
	TDA_PILA* a, TDA_PILA* b, TDA_PILA* c) {
	int e;
	char aux, aux1;

	//Indentificar de cual torre se saca los discos
	if (a == &A)
		aux = 'A';
	else if (b == &A)
		aux = 'B';
	else if (c == &A)
		aux = 'C';

	if (a == &C)
		aux1 = 'A';
	else if (b == &C)
		aux1 = 'B';
	else if (c == &C)
		aux1 = 'C';

	//Recursividad torre de hanoi
	if (n == 1) {
		pop(A, e);
		push(C, e);
		printf("\nDisco %d movido de la Torre %c a la Torre %c", n, aux, aux1);

	}
	else {
		t_Hanoi(n - 1, A, C, B, a, b, c);
		pop(A, e);
		push(C, e);
		printf("\nDisco %d movido de la Torre %c a la Torre %c", n, aux, aux1);
		t_Hanoi(n - 1, B, A, C, a, b, c);
	}

}

//Mostrar los discos de la torre destino
void mostrar(TDA_PILA C) {
	int e;
	while (pop(C, e))
		printf("%d", e);
}
