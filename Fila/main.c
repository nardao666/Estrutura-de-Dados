#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main () {
	int op;
	// Menu de escolha pra o usuario
	do {
		system("clear");
		printf ("\n\t *****************************************");
		printf ("\n\t *                FILA                   *");
		printf ("\n\t *****************************************");
		printf ("\n\t *  1. Mostrar a Fila.                   *");
		printf ("\n\t *  2. Incluir elemento na Fila.         *");
		printf ("\n\t *  3. Excluir elemento na Fila.         *");
    	printf ("\n\t *  4. Mostrar 1o. elemento da Fila.     *");
		printf ("\n\t *  5. Sair do programa.                 *");
		printf ("\n\t *****************************************");
		printf ("\n\t    Digite a opcao:");
		
		scanf ("%d", &op);
		switch (op) {
			case 1 : Tamanho_Fila(); getchar(); break; // retorna o tamanho da lista
			case 2 : enqueue(); getchar(); break;// inserir um elemento no começo da lista
			case 3 : dequeue();; getchar(); break;// inserir um elemento no final da lista
			case 4 : front(); getchar(); break;// retorna o 1º elemento da Fila
			case 5 : printf ("\n\n\t\tFinalizando o programa..."); getchar(); break; // sair do programa
			default : printf ("\n\n\t\tOpcao invalida."); getchar(); // para caso o usuario digite algo diferente do menu
		}
		printf("\n\n\t\t");
		getchar();
	} while (op != 5);
return(0);
}
