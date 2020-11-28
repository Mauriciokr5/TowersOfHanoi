#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"


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



void tower(int a,Pila *ptrFrom,Pila *ptrAux,Pila *ptrTo){

    if(a==1){
      printf("     Movemos el disco 1 de %c a %c\n", towerName(*ptrFrom), towerName(*ptrTo));
      *ptrTo=pushTower(topTower(*ptrFrom),*ptrTo);
      *ptrFrom=popTower(*ptrFrom);
/*
       printPilas( *ptrFrom);
       printPilas( *ptrAux);
       printPilas( *ptrTo);*/
       counter++;
       return;
    }
    else{
       tower(a-1,ptrFrom,ptrTo,ptrAux);

       printf("     Movemos el disco %d de %c a %c\n", a, towerName(*ptrFrom), towerName(*ptrTo));

       *ptrTo=pushTower(topTower(*ptrFrom),*ptrTo);
       *ptrFrom=popTower(*ptrFrom);
/*
       printPilas( *ptrFrom);
       printPilas( *ptrAux);
       printPilas( *ptrTo);*/
       counter++;

       tower(a-1,ptrAux,ptrFrom,ptrTo);
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

     tower(n,&pilaA,&pilaB,&pilaC);
     printPilas( pilaA);
     printPilas( pilaB);
     printPilas( pilaC);

     printf("Total de movimientos: %d\n", counter);

     getchar();

     return 0;
}
