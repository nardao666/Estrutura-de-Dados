#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


struct no {
  int cod;
  struct no *prox, *ant;
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
	  printf ("NULL  <=>  ");
	  while ( P != NULL ) {
		printf ("%d  <=>  ", P->cod);
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
    P->ant = NULL;
    Lista = P;
    if ( Fim == NULL ) Fim = Lista;               
    else (P->prox)->ant = P;
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
  P->ant = Fim;
  if ( Lista == NULL )  Lista = P;         
  else Fim->prox = P;
  Fim = P;
  printf ("\n\n\t\tElemento incluido = \"%d\"", P->cod);
  tam++;
}

void Inserir_apos() {
	struct no *P = NULL, *Aux = NULL;
	int  pos, num;
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
			  Aux = Lista;
			  for (int x = 2; x < pos; x++)
				Aux = Aux->prox;
				P = (struct no *) malloc (sizeof (struct no));
				P->cod = num;
				P->prox = Aux->prox;
				P->ant = Aux;
                Aux->prox = P;
                (P->prox)->ant = P;

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
	  if (Lista == NULL) Fim = NULL;
      else Lista->ant = NULL;
	  printf ("\n\n\t\tElemento excluido = \"%d\"", P->cod);
	  free (P);             
	  tam--;
  }
}

void Remover_final() {
  struct no *P = NULL;
  if ( Lista == NULL )
	printf ("\n\n\t\tLista vazia.");
  else if ( tam == 1 ) {
	   printf ("\n\n\t\tElemento excluido = %d !", Lista->cod);
	   free (Lista);
	   Lista = Fim = NULL;
	   tam--;
       }
       else {
	      P = Fim;
   	      printf ("\n\n\t\tElemento excluido = \"%d\"", Fim->cod);
	      Fim=Fim->ant;
	      if (Fim == NULL) Lista = NULL;
          else Fim->prox = NULL;

	      free (P);             
	      tam--;
	    }
}

void Remover_apos() {
	struct no *Exc = NULL, *Aux = NULL;
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
				Aux = Exc;
				Exc = Exc->prox;
			  }
			  Aux->prox = Exc->prox;
			  Aux->ant = Exc->ant;
			  printf ("\n\n\t\tElemento excluido = \"%d\"", Exc->cod);
			  free (Exc);
			  tam--;
		  }
	}
}
