#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


struct no {
  int cod;
  int prio;
  struct no *prox;
};

struct no *Lista = NULL,*Fim = NULL;

int tam = 0;

int target=10;


void ord() { 

     int i;	 
	 struct no *pi;
	 struct no *min;
	 struct no *aux;
for(i=0;i<=tam;i++){ 
  for (pi=Lista ; pi!=NULL ; pi=pi->prox) {
    min = pi;
    for (aux = pi->prox; aux!=NULL ; aux=aux->prox) {
      if(pi->prio < aux->prio) {
        min = aux;
      }
    }
    if (pi != min) {
      int swap = pi->prio;
      
      int swap1= pi->cod;
      
      pi->prio=min->prio;
      pi->cod=min->cod;
      min->cod=swap1;
      min->prio=swap;

    }
  }
}
printf ("\n\n\t\tFila ordena.");
}

void Tamanho() {
  struct no *P = NULL;
  P = Lista;
  if ( Lista == NULL )
     printf ("\n\n\t\tFila vazia.");
  else {
	  printf ("\n\n\t\tFila com %d elemento(s): \n\n\t\t", tam);
	 
	  while ( P != NULL ) {
		printf ("<- [%d|%d]  ", P->cod, P->prio);

		P = P->prox;
	  }
	  
  }
}
  
void Inserir_final() {
  struct no *P = NULL;
  int num,num1;
  printf ("\n\n\t\tDigite um numero: ");
  scanf ("%d", &num);
  printf ("\n\t\tDigite uma prioridade: ");
  scanf ("%d", &num1);
  if(num1 >= target) printf("\n\n\t\tValor invalido.");
  else{
  P = (struct no *) malloc (sizeof (struct no));
  P->cod = num;
  P->prio = num1;
  P->prox = NULL;
  if ( Lista == NULL )
	  Lista = P;         
  else
	  Fim->prox = P;
  Fim = P;
  printf ("\n\n\t\tElemento incluido = \"%d\"", P->cod);
  printf ("\n\t\tPrioridade incluido = \"%d\"", P->prio);
  tam++;
  ord();
  }
}



void Remover_frente() {
  struct no *P = NULL;
  if ( Lista == NULL )
	  printf ("\n\n\t\tFila vazia.");
  else {
	  P = Lista;
	  Lista = Lista->prox;
	  printf ("\n\n\t\tElemento excluido = \"%d\"", P->cod);
	  printf ("\n\t\tPrioridade excluido = \"%d\"", P->prio);
	  free (P);             
	  tam--;
  }
}


void Primeiro_elemento() {
  struct no *P = NULL;
  P = Lista;
  if ( Lista == NULL )
     printf ("\n\n\t\tFila vazia.");
  else {
       printf ("\n\n\t");
    	printf ("O primeiro elemento da Fila eh \"%d|%d\"", P->cod, P->prio);
		
	   }
}