#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include "ABB.h"

// Estrutura do Nodo de Arvore Binaria.
               
struct Arvore_nodo { 
                    tipo_elem elem;
                    struct Arvore_nodo *filho_esq, *filho_dir;
                    struct Arvore_nodo *mae;};

// Estrutura da Arvore Binaria.

struct Binaria{
                int nelem;
                nodo *raiz;};                          


// Funcao inserir novo elemento na arvore e retornar true se operacao sucesso, e false se jah existir elemento igual 
// na arvore.
bool Insere(Arvore_Binaria *AB,tipo_elem x){
     int flag;
     nodo *w,*noh;
     noh=Raiz(AB);
     w=Pesquisa_AB(AB,x.chave,noh);
     if(w==NULL){
            flag=0;
            if(noh==NULL){AB->raiz=CriaNoh(noh,x);flag=1;};
            while(flag==0){
               if(strcmp(x.chave,noh->elem.chave)>0){
                 if(noh->filho_dir==NULL){
                    noh->filho_dir=CriaNoh(noh,x);
                    flag=1;}
                 else{
                    noh=Filho_Direito(AB,noh);}
               }
               else{
                 if(noh->filho_esq==NULL){
                    noh->filho_esq=CriaNoh(noh,x);
                    flag=1;}
                 else{
                    noh=Filho_Esquerdo(AB,noh);}
               }
            }            
            AB->nelem++;
            return true;}
     return false;
     }
    
// Funcao Pesquisa na arvore por chave informada retornando o nodo     
nodo *Pesquisa_AB(Arvore_Binaria *AB,char *chave,nodo *noh){
     tipo_elem x;
     if(noh!=NULL){
     x=Conteudo(AB,noh);
     if(strcmp(chave,x.chave)<0)return Pesquisa_AB(AB,chave,Filho_Esquerdo(AB,noh));
     if(strcmp(chave,x.chave)>0)return Pesquisa_AB(AB,chave,Filho_Direito(AB,noh));}
     return noh;
         }     
         
// Funcao Retorno de elemento do nodo informado
tipo_elem Conteudo(Arvore_Binaria *AB, nodo *noh){
          if(noh!=NULL)return (noh->elem);
          tipo_elem nulo;
          nulo.chave[0]='\0';
          nulo.info[0]='\0';
          return nulo;}
     
// Funcao retornar nodo direito de nodo informado.     
nodo *Filho_Direito(Arvore_Binaria *AB,nodo *noh){
     return (noh->filho_dir);}



// Funcao retornar nodo esquerdo de nodo informado.     
nodo *Filho_Esquerdo(Arvore_Binaria *AB,nodo *noh){
     return (noh->filho_esq);}

// Funcao retornar irmao de nodo informado. Se nao eh nodo valido sair.
nodo *Irmao(Arvore_Binaria *AB,nodo *noh){
     if(EhRaiz(AB,noh))return NULL;
     if(EhFilhoEsq(AB,noh))
       return (Filho_Direito(AB,Mae(AB,noh)));
     return (Filho_Esquerdo(AB,Mae(AB,noh)));
     }
     
// Funcao cria nodo novo do lado direito de nodo informado com elemento x.
void CriaNohDir(nodo *noh, tipo_elem x){
     noh->filho_dir=CriaNoh(noh,x);
     return; }
     
// Funcao cria nodo novo do lado esquerdo de nodo informado com elemento x.
void CriaNohEsq(nodo *noh, tipo_elem x){
     noh->filho_esq=CriaNoh(noh,x);
     return;}
     
 // Funcao  Impressao de arvore com caminhamento pre-order
void pretrav(Arvore_Binaria *AB,nodo *noh){
     if(noh!=NULL){
       printf("%d\n",noh->elem);
       pretrav(AB,Filho_Esquerdo(AB,noh));
       pretrav(AB,Filho_Direito(AB,noh));}
       }

// Funcao Impressao de arvore com caminhamento por-order
void postrav(Arvore_Binaria *AB, nodo *noh){
     if(noh!=NULL){
      postrav(AB,Filho_Esquerdo(AB,noh));
      postrav(AB,Filho_Direito(AB,noh));
      printf("%s\n",noh->elem);}
      }
            
// Funcao Retorno se nodo informado eh ou nao um nodo raiz
bool EhRaiz(Arvore_Binaria *AB, nodo *noh){
     if(noh==NULL) exit(0);
     if((noh->mae)==NULL) return true;
     else return false;}

// Funcao retorna numero de nos da arvore.
int Numero_nos(Arvore_Binaria *AB){
    return AB->nelem;}
                  
// Funcao checar se arvore esta vazia.
bool Vazia(Arvore_Binaria *AB){
     if(Numero_nos(AB)==0) return true;
     else return false;}
     
// Funcao Checar no raiz da arvore.
nodo *Raiz(Arvore_Binaria *AB){
     return AB->raiz;}
     
// Funcao Checar mae de no especificado na arvore
nodo *Mae(Arvore_Binaria *AB,nodo *noh){
//     printf("\nEntrando na rotina Mae");
     return noh->mae;}

// Funcao Checar se no especificado eh interno
bool NoInterno(Arvore_Binaria *AB, nodo *noh){
     if((Mae(AB,noh)!=NULL)&&(NoExterno(AB,noh)==false))return true;
     else return false;}
     
// Funcao Checar se no especificado eh externo
bool NoExterno(Arvore_Binaria *AB, nodo *noh){
     if((Filho_Esquerdo(AB,noh)==NULL)||(Filho_Direito(AB,noh)==NULL))
        return true;
     else 
        return false;}

// Funcao para encontrar substituto a no interno a ser removido.
nodo *EncontreSubstituto(Arvore_Binaria *AB,nodo *noh){
     noh=Filho_Direito(AB,noh);
     while(Filho_Esquerdo(AB,noh)){
          noh=Filho_Esquerdo(AB,noh);}
     return noh;}
             


// Funcao para retornar se nodo eh filho esquerdo
bool EhFilhoEsq(Arvore_Binaria *AB,nodo *noh){
     nodo *q;
     q=Mae(AB,noh);
     if(EhRaiz(AB,noh))
       return false;
     if(Filho_Esquerdo(AB,noh)==noh)
       return true;
     return false;
     }

// Funcao Cria noh em folha vazia.
nodo *CriaNoh(nodo *noh, tipo_elem x){
     nodo *novo;
     novo=(nodo*) malloc(sizeof(nodo));
     novo->mae=noh;
     novo->filho_esq=NULL;
     novo->filho_dir=NULL;
     novo->elem=x;
     return novo;}              


         
// Funcao Definicao da arvore binaria de busca.
Arvore_Binaria *Definir(void){
               Arvore_Binaria *AB;
               AB=malloc(sizeof(Arvore_Binaria));
               AB->nelem=0;
               AB->raiz=NULL;
               return AB;
               }
               
// Funcao Remove nodo externo e concatena.
void removeAboveExternal(Arvore_Binaria *AB,nodo *noh){
     nodo *v,*z;
     v=Mae(AB,noh);
     z=NULL;
     if(Filho_Esquerdo(AB,noh)!=NULL){
       z=Filho_Esquerdo(AB,noh);
       z->mae=v;};
     if(Filho_Direito(AB,noh)!=NULL){
       z=Filho_Direito(AB,noh);
       z->mae=v;};
     if(v!=NULL){  
     if(Filho_Esquerdo(AB,v)==noh)
       v->filho_esq=z;
     else
       v->filho_dir=z;};
     if(EhRaiz(AB,noh))AB->raiz=z;     
     free(noh);
     AB->nelem--;
     }
     
// Funcao Atribui elemento a nodo
void Atribui(Arvore_Binaria *AB, nodo *noh, tipo_elem x){
     noh->elem=x;
     }
     
// Funcao de caminhamento de estrutura arvore binaria em modo inter-fixado.

void Inter_Fixado(Arvore_Binaria *AB,nodo *noh){
     if(noh!=NULL){
       Inter_Fixado(AB,Filho_Esquerdo(AB,noh));
       printf("\n");
       printf("\t\t\t %s               %s",noh->elem.chave,noh->elem.info);
       Inter_Fixado(AB,Filho_Direito(AB,noh));}

       }
       


