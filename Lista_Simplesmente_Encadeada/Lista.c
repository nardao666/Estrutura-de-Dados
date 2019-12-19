#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


struct no {
  int cod;
  struct no *prox;
};

struct no *Lista = NULL,*Fim = NULL;
int tam = 0;

void Tamanho() {
  struct no *P = NULL;
  P = Lista;
  if ( Lista == NULL )
     printf ("\n\n\t\tLista vazia.");
  else {
	  printf ("\n\n\t\tLista com %d elemento(s): \n\n\t\t", tam);
	  while ( P != NULL ) {
		printf ("%d  -> ", P->cod);
		P = P->prox;
	  }
	  printf ("NULL");
  }
}

void Inserir_frente() {
    struct no *P = NULL;
    int num;
    printf ("\n\n\t\tDigite um numero: ");
    scanf ("%d", &num);
    P = (struct no *) malloc (sizeof (struct no));
    P->cod = num;
    P->prox = Lista;
    if ( Lista == NULL )      
       Fim = P;               
    Lista = P;                
    printf ("\n\n\t\tElemento incluido = \"%d\"", num);
    tam++;
}

void Inserir_final() {
  struct no *P = NULL;
  int num;
  printf ("\n\n\t\tDigite um numero: ");
  scanf ("%d", &num);
  P = (struct no *) malloc (sizeof (struct no));
  P->cod = num;
  P->prox = NULL;
  if ( Lista == NULL )
	  Lista = P;         
  else
	  Fim->prox = P;
  Fim = P;
  printf ("\n\n\t\tElemento incluido = \"%d\"", P->cod);
  tam++;
}

void Inserir_apos() {
	struct no *P = NULL, *Ant = NULL;
	int  pos, num, x;
	printf ("\n\n\t\tDigite a posicao a ser incluido o elemento: ");
	scanf ("%d", &pos);
	if ( pos > tam+1 ) {            
	   printf ("\n\n\t\tLista com apenas %d elementos.", tam);
	   printf ("\n\t\tImpossivel inclusao!!!");
	}
	else {
		  if ( pos == 1 )
		       Inserir_frente();   
		  else
		       if ( pos == tam + 1 )
			  Inserir_final();    
		       else {
			  printf ("\n\t\tDigite um numero: ");
			  scanf ("%d", &num);
			  Ant = Lista;
			  for ( x = 2; x < pos; x++)
				Ant = Ant->prox;
				P = (struct no *) malloc (sizeof (struct no));
				P->cod = num;
				P->prox = Ant->prox;
				Ant->prox = P;
				printf ("\n\n\t\tElemento incluido = \"%d\"", P->cod);
				tam++;
			  }
	}
}



void Remover_frente() {
  struct no *P = NULL;
  if ( Lista == NULL )
	  printf ("\n\n\t\tLista vazia.");
  else {
	  P = Lista;
	  Lista = Lista->prox;
	  printf ("\n\n\t\tElemento excluido = \"%d\"", P->cod);
	  free (P);             
	  tam--;
  }
}

void Remover_final() {
  struct no *Ant = NULL;
  if ( Lista == NULL )
	printf ("\n\n\t\tLista vazia.");
  else if ( tam == 1 ) {
	   printf ("\n\n\t\tElemento excluido = %d !", Lista->cod);
	   free (Lista);
	   Lista = Fim = NULL;
	   tam--;
       }
       else {
	      Ant = Lista;
	      while ( Ant->prox != Fim )
		 Ant = Ant->prox;
	      Ant->prox = NULL;
	      printf ("\n\n\t\tElemento excluido = \"%d\"", Fim->cod);
	      free (Fim);             
	      Fim = Ant;
	      tam--;
	    }
}

void Remover_apos() {
	struct no *Exc = NULL, *Ant = NULL;
	int  pos;
	printf ("\n\n\t\tDigite a posicao a ser incluido o elemento: ");
	scanf ("%d", &pos);
	if ( pos > tam || pos < 1 ) {       
	    printf ("\n\t\tLista com apenas %d elementos.", tam);
	    printf ("\n\t\tImpossivel exclusao!!!");
	}
	else {
	     if ( pos == 1 )
		  Remover_frente();   
	     else
		  if ( pos == tam )
			  Remover_final();    
		  else {
			  Exc = Lista;
			  for (int x = 1; x < pos; x++) {
				Ant = Exc;
				Exc = Exc->prox;
			  }
			  Ant->prox = Exc->prox;
			  printf ("\n\n\t\tElemento excluido = \"%d\"", Exc->cod);
			  free (Exc);
			  tam--;
		  }
	}
}
