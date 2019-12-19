#define MAX 20
#define TRUE 1
#define FALSE 0
#define bool int

#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

Tree *Definir(){
     Tree *T;
     T = (Tree *) malloc(sizeof(Tree));
     T->root = NULL;
     
     return T;
}

nodo *leaf_null(nodo *father){
      nodo *Pa;
      Pa = (nodo *) malloc(sizeof(nodo));
      
      sprintf("", Pa->elem.elem);
      Pa->lig_left = NULL;
      Pa->lig_right = NULL;
      Pa->father = father;
}

int size(Tree *T){
     return (T->nelem);
}
bool isEmpty(Tree *T){
     return (T->nelem == 0);
}
nodo *root(Tree *T){
     return (T->root);
}
nodo *parent(nodo *c){
     return (c->father);
}

bool isInternal(nodo *c){
     bool check = 0;
     if(leftChild(c) != NULL) check = 1;
     if(rightChild(c) != NULL) check = 1;
     return check;
}
bool isExternal(nodo *c){
     if(!(isInternal(c))) return 1;
     return 0;
}
bool isRoot(nodo *c){
     if(c->father == NULL) return 1;
     return 0;
}

bool isLeft(nodo *c){// Verifica se o elemento c eh filho esquerdo do pai
     if(isRoot(c)) return 0;
     if(c->father->lig_left == c) return 1;
     return 0;
}
bool isRight(nodo *c){// Verifica se o elemento c eh filho direito do pai
     if(isRoot(c)) return 0;
     if(c->father->lig_right == c) return 1;
     return 0;
}

nodo *leftChild(nodo *c){
     if(c != NULL) return (c->lig_left);
     else return NULL;
}
nodo *rightChild(nodo *c){
     if(c != NULL) return (c->lig_right);
     else return NULL;
}
nodo *sibiling(nodo *c){
     if(isRoot(c)) return NULL;
     
     if(isLeft(c)) return leftChild(c->father);
     else if(isRight(c)) return rightChild(c->father);
     else return NULL;
}

void swap(nodo *c, nodo *d){
     nodo *aux = c;

     if(isLeft(c)) c->father->lig_left = d;
     else if(isRight(c)) c->father->lig_right = d;
     c->father = d->father;
     
     c->father->lig_left = leftChild(d);
     c->father->lig_right = rightChild(d);
     
     if(isLeft(aux)) d->father->lig_left = aux;
     else if(isRight(aux)) d->father->lig_right = aux;
     d->father = aux->father;
     
     d->father->lig_left = leftChild(aux);
     d->father->lig_right = rightChild(aux);
}

void replace(nodo *c, tipo_elem p){
     if(c != NULL) c->elem = p;
}

nodo *remove_nodo(Tree *T, nodo *c){
     nodo *Pa, *aux;
     while(c != NULL){
           Pa = get_leaf(c);
           if(Pa != NULL) free(Pa);
     }
     return c;
}
nodo *get_leaf(nodo *c){
     if(isInternal(c)){
           if(c->lig_left != NULL) get_leaf(c->lig_left);
           else get_leaf(c->lig_right);
     }
     return c;
}

nodo *insertLeft(Tree *T, nodo *c, tipo_elem p){
     nodo *Pa;
     
     Pa = (nodo *) malloc(sizeof(nodo));
     Pa->elem = p;
     Pa->father = c;
     Pa->lig_left = Pa->father->lig_left;
     Pa->lig_right = NULL;
     Pa->father->lig_left = Pa;
     
     T->nelem++;
     return Pa;
}
nodo *insertRight(Tree *T, nodo *c, tipo_elem p){
     nodo *Pa;
     
     Pa = (nodo *) malloc(sizeof(nodo));
     Pa->elem = p;
     Pa->father = c;
     Pa->lig_right = Pa->father->lig_right;
     Pa->lig_left = NULL;
     Pa->father->lig_right = Pa;

     T->nelem++;
     return Pa;
}
nodo *insertRoot(Tree *T, tipo_elem p){
     if(T->root == NULL){
         nodo *Pa;
         
         Pa = (nodo *) malloc(sizeof(nodo));
         Pa->elem = p;
         Pa->father = NULL;
         Pa->lig_right = NULL;
         Pa->lig_left = NULL;
         T->root = Pa;
    
         T->nelem++;
         return Pa;
     }
}

nodo *search(Tree *T, nodo *c, tipo_elem p){
     if(c == NULL) c = T->root;
     if(strcmp(c->elem.elem, p.elem) != 0){
           if(isInternal(c)){
                 search(T, c->lig_left, p);
                 search(T, c->lig_right, p);
           }
     }else return c;
     return NULL;
}

nodo *expandExternal(Tree *T, nodo *c){
     nodo *Pa_l, *Pa_r;
     if(isExternal(c)){
           Pa_l = leaf_null(c);
           Pa_r = leaf_null(c);
           
           c->lig_left = Pa_l;
           c->lig_right = Pa_r;
           return c;
     }
     return NULL;
}
nodo *removeAboveExternal(Tree *T, nodo *c){
     nodo *Pa, *aux;
     Pa = c;
     
     if(isExternal(c)){
           if(c != T->root){
                 aux = c->father;
                 c->father = aux->father;
                 if(isLeft(aux)) aux->father->lig_right = c;
                 else aux->father->lig_left = c;

                 if(isLeft(c)) free(aux->lig_right);
                 else free(aux->lig_left);

                 free(aux);
           }else{
                 free(Pa);
           }
     }
}
