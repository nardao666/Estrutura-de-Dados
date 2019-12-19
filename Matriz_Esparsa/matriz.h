// M � Linhas, N � Colunas
// i � Linhas, j � Colunas
// x � Linhas, y � Colunas

/* Para adicionar elementos a matriz basta alterar o valor das Constantes M e N
conforme as informa��es acima*/

#define M 5
#define N 5
#define MAX 50

#include <stdlib.h>
#include <stdio.h>

typedef struct list_node{
        int i, j;
        struct list_node *lig_col, *lig_lin;
        double elem;
}nodo;
typedef struct{
       int qtd;
       nodo *cols[N], *lins[M];
}Matriz;

double get(Matriz *L,int lin, int col);

Matriz *Define(void);

void set(Matriz *L, int lin, int col, double value);

int qt_cell(Matriz *L);