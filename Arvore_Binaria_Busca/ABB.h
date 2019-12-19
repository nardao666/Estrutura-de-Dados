#define bool int
#define true 1
#define false 0

// Descricao da estrutura de registro do elem contido em nodos.

typedef struct{
                char chave[30];
                char info[30];
                }tipo_elem;

// Estrutura do Nodo de Arvore Binaria.
               
typedef struct Arvore_nodo nodo;

// Estrutura da Arvore Binaria.

typedef struct Binaria Arvore_Binaria;                          

// Funcao criacao estrutura arvore binaria ABB

 Arvore_Binaria *Definir(void);
 
// Funcao retorno de elemento de nodo (tipo elem). Nulo se inexistente.

 tipo_elem Conteudo(Arvore_Binaria *AB, nodo *noh);
 
// Funcao expansao de no em folha vazia

 nodo *CriaNoh(nodo *noh, tipo_elem x);
 
// Funcao booleana para qualificacao de filho esquerdo

 bool EhFilhoEsq(Arvore_Binaria *AB,nodo *noh);
 
// Funcao booleana para qualificacao de raiz

 bool EhRaiz(Arvore_Binaria *AB, nodo *noh);

// Funcao Checar no raiz da arvore.

 nodo *Raiz(Arvore_Binaria *AB);
 
// Funcao Checar mae de no especificado na arvore

 nodo *Mae(Arvore_Binaria *AB, nodo *noh);
 
// Funcao Checar se no especificado eh interno

 bool NoInterno(Arvore_Binaria *AB, nodo *noh);
 
// Funcao Checar se no especificado eh externo

 bool NoExterno(Arvore_Binaria *AB, nodo *noh);
 
// Funcao para retorno do nodo irmao de nodo informado se nodo nao eh valido retorna null

 nodo *Irmao(Arvore_Binaria *AB, nodo *noh);
 
// Funcao cria novo nodo do lado direito de noh informado com elemento x.

 void CriaNohDir(nodo *noh,tipo_elem x);
 
// Funcao cria novo nodo do lado esquerdo de noh informado com elemento x.

 void CriaNohEsq(nodo *noh,tipo_elem x);
 
// Funcao retorno de quantidade de nodos em arvore binaria.

 int Numero_nos(Arvore_Binaria *AB);
 
// Funcao de caminhamento de arvore binaria em modo inter-fixado.

 void Inter_Fixado(Arvore_Binaria *AB, nodo *noh);
  
// Funcao retornar ponteiro do filho esquerdo do noh

 nodo *Filho_Esquerdo(Arvore_Binaria *AB, nodo *noh);

// Funcao retornar ponteiro do filho direito do noh

 nodo *Filho_Direito(Arvore_Binaria *AB, nodo *noh);

// Funcao insere nodo em arvore binaria.

 bool Insere(Arvore_Binaria *AB,tipo_elem x);
 
// Funcao checar se arvore esta vazia.

 bool Vazia(Arvore_Binaria *AB);

// Funcao  Impressao de arvore com caminhamento pre-order
 
 void pretrav(Arvore_Binaria *AB,nodo *noh);
 
// Funcao Impressao de arvore com caminhamento pos-order

 void postrav(Arvore_Binaria *AB,nodo *noh);
 
// Funcao Atribui elemento a nodo

 void Atribui(Arvore_Binaria *AB, nodo *noh, tipo_elem x);
    
// Funcao Pesquisa arvore por chave informada retornando o nodo

 nodo *Pesquisa_AB(Arvore_Binaria *AB, char *chave, nodo *noh);

// Funcao de caminhamento de estrutura arvore binaria em modo inter-fixado.

 void Inter_Fixado(Arvore_Binaria *AB,nodo *noh);
 
// Funcao Remove nodo externo e concatena braco de arvore.

 void removeAboveExternal(Arvore_Binaria *AB, nodo *noh);
 
// Funcao Menor elemento da sub-Arvore direita

 nodo *EncontreSubstituto(Arvore_Binaria *AB, nodo *noh);
 
