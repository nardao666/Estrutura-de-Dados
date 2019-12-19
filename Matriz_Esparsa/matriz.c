#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

int qt_cell(Matriz *L){
       return (L->qtd);
}


Matriz *Define(){
       int x;
       Matriz *L;

       L = (Matriz *) malloc(sizeof(Matriz));
       L->qtd = 0;

       for(x = 0; x < M; x++){
             L->lins[x] = (nodo *) malloc(sizeof(nodo));
             
             L->lins[x]->i = x;
             L->lins[x]->j = 0;
             L->lins[x]->elem = 0;
             
             if(x != 0) L->lins[x - 1]->lig_lin = L->lins[x];
             L->lins[x]->lig_col = NULL;
       }
       for(x = 0; x < N; x++){
             L->cols[x] = (nodo *) malloc(N * sizeof(nodo));

             L->cols[x]->i = 0;
             L->cols[x]->j = x;
             L->cols[x]->elem = 0;
             
             if(x != 0) L->cols[x - 1]->lig_col = L->cols[x];
             L->cols[x]->lig_lin = NULL;
       }
       
       return L;
}


double get(Matriz *L, int lin, int col){
       nodo *aux;

       for(aux = L->lins[lin]; aux != NULL; aux = aux->lig_col){
               if(aux->j == col) return aux->elem;
       }
       return 0;
}

void set(Matriz *L, int lin, int col, double value){
       //int i=0, j=0;
       nodo *aux, *atual;
       
       if(value == 0){
           if(get(L, lin, col) == 0) printf("O valor na linha %d e coluna %d eh 0!\n", lin, col);
           else{
                nodo *last;
                atual = (nodo *) malloc(sizeof(nodo));
                
                if(col != 0){
                    for(aux = L->lins[lin]; (aux != NULL) && (col < aux -> j); last = aux, aux = aux->lig_col)
                    last->lig_col = aux;
                }else{
                    L->lins[lin]->elem = 0;
                }

                if(col != 0){
                    for(aux = L -> cols[col]; (aux != NULL) && (lin < aux -> j); last = aux, aux = aux->lig_lin)
                    last -> lig_lin = aux;
                }else{
                    L->cols[col]->elem = 0;
                }
                
                //printf("O elemento: %dX%d, continha o conteudo: %f", lin, col, atual->elem);
                free(atual);
                printf("\n\n\t\t Sucesso em excluir o elemento!\n\n");
                L -> qtd--;
           }
       }else{
           if(get(L, lin, col) == 0){
                nodo *last;
                atual = (nodo *) malloc(sizeof(nodo));
                
                atual -> i = lin; atual -> j = col;
                atual -> elem = value;
                atual -> lig_col = NULL;
                atual -> lig_lin = NULL;
                
                aux = L -> lins[lin];
                if(col != 0){
                    if(aux -> lig_col == NULL){
                            aux -> lig_col = atual;
                            atual -> lig_col = NULL;
                    }else{
                        for(aux = L -> lins[lin]; (aux != NULL) && (col < aux -> j); last = aux, aux = aux->lig_col)
                        last -> lig_col = atual;
                        atual -> lig_col = aux;
                    }
                printf ("\n\n\tAdicionado a Matriz na linha \"%d\" e coluna \"%d\" o valor \"%f\" ",lin, col, value);
                }else{
                    atual -> lig_col = aux -> lig_col;
                    L -> lins[lin] = atual;
                }

                aux = L -> cols[col];
                if(lin != 0){
                    if(aux -> lig_lin == NULL){
                            aux -> lig_lin = atual;
                            atual -> lig_lin = NULL;
                    }else{
                        for(aux = L -> cols[col]; (aux != NULL) && (lin < aux -> i); last = aux, aux = aux->lig_lin)
                        last -> lig_lin = atual;
                        atual -> lig_lin = aux;
                    }
                }else{
                    atual -> lig_lin = aux -> lig_lin;
                    L -> cols[col] = atual;
                }
                L -> qtd++;
           }else{
               for(aux = L -> lins[lin]; aux == NULL; aux = aux -> lig_col){
                       if(aux -> j > col) printf("\n\n\t\tElemento nao eh valido!\n");
                       if(aux -> j == col) aux->elem = value;
               }
           }
       }
}