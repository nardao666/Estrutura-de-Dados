#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include <time.h>

void main () {
	int op;
	// Menu de escolha pra o usuario
	do {
		system("clear");
		printf ("\n\t *****************************************");
		printf ("\n\t *     LISTA SIMPLESMENTE ENCADEADA      *");
		printf ("\n\t *****************************************");
		printf ("\n\t *  1. Mostrar a lista.                  *");
		printf ("\n\t *  2. Incluir um elemento no inicio.    *");
		printf ("\n\t *  3. Incluir um elemento no final.     *");
		printf ("\n\t *  4. Incluir um elemento pela posicao. *");
		printf ("\n\t *  5. Excluir o primeiro elemento.      *");
		printf ("\n\t *  6. Excluir o ultimo elemento.        *");
		printf ("\n\t *  7. Excluir um elemento pela posicao. *");
		printf ("\n\t *  8. Sair do programa.                 *");
		printf ("\n\t *****************************************");
		printf ("\n\t    Digite a opcao:");
		
		scanf ("%d", &op);
		switch (op) {
			case 1 : Tamanho(); getchar(); break; // retorna o tamanho da lista
			case 2 : Inserir_frente(); getchar(); break;// inserir um elemento no começo da lista
			case 3 : Inserir_final(); getchar(); break;// inserir um elemento no final da lista
			case 4 : Inserir_apos(); getchar(); break;// inserir um elemento na posição que o usuario quer na lista
			case 5 : Remover_frente(); getchar(); break;// remove um elemento no começo da lista
			case 6 : Remover_final(); getchar(); break;// remove um elemento no final da lista
			case 7 : Remover_apos(); getchar(); break;// remove um elemento na posição que o usuario quer da lista
			case 8 : printf ("\n\n\t\tFinalizando o programa..."); getchar(); break; // sair do programa
			default : printf ("\n\n\t\tOpcao invalida."); getchar(); // para caso o usuario digite algo diferente do menu
		}
		printf("\n\n\t\t");
		getchar();
	} while (op != 8);

}
