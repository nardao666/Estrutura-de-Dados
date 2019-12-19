#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


int main () {
	int op;
	int i, j, l, c;
	float valor;
	Matriz *L;
	L = Define();    
	do {
		system("clear");
		printf ("\n\t *****************************************");
		printf ("\n\t *          Matriz Esparsa               *");
		printf ("\n\t *****************************************");
		printf ("\n\t *  1. Mostrar a Matriz.                 *");
		printf ("\n\t *  2. Incluir elemento na Matriz.       *");
		printf ("\n\t *  3. Sair do programa.                 *");
		printf ("\n\t *****************************************");
		printf ("\n\t    Digite a opcao:");
		
		scanf ("%d", &op);
		switch (op) {
		
			case 1 :
                 printf ("\n\n\t\tMatriz com %d elemento(s): \n\n\t\t", qt_cell(L));
                 printf("\n\n");

        for(i = 0; i < M; i++){
                      printf ("\t");
          for(j = 0; j < N; j++){
                printf(" %f ", get(L, i, j));
          }
          printf("\n\n");
    }       getchar(); break;
			case 2 :
                 printf ("\n\n\t\tDigite o numero da linha: ");
                 scanf ("%d", &l);
                 printf ("\n\t\tDigite o numero da coluna: ");
                 scanf ("%d", &c);  
                 printf ("\n\t\tDigite o valor: ");
                 scanf ("%f", &valor);  
                 
                  if (l>=M || c>=N)
                          printf ("\n\n\t\tValor da linha e/ou coluna invalido !");
                          
                 else                
                 set(L, l, c, valor);
//               printf ("\n\t\tAdicionado a Matriz na linha \"%d\" e coluna \"%d\" o valor \"%f\" ",l, c, valor);
            getchar();     
            break;
			
			case 3 : printf ("\n\n\t\tFinalizando o programa..."); getchar(); break;
			
			default : printf ("\n\n\t\tOpcao invalida.");
		}
		printf("\n\n\t\t");
		getchar();
	} while (op != 3);
return(0);
}
