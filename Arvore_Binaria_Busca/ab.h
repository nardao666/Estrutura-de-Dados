typedef struct{
    char elem[MAX];
} tipo_elem;

struct list_node{
    tipo_elem elem;
    struct list_node *lig_left, *lig_right, *father;
};
typedef struct list_node nodo;

typedef struct{
    int nelem;
    nodo *root;
} Tree;

Tree *Definir();
int size(Tree *);
bool isEmpty(Tree *);
nodo *root(Tree *);
nodo *parent(nodo *);
bool isInternal(nodo *);
bool isExternal(nodo *);
bool isRoot(nodo *);
bool isLeft(nodo *); // Implementado a mais
bool isRight(nodo *); // Implementado a mais
nodo *leftChild(nodo *);
nodo *rightChild(nodo *);
nodo *sibiling(nodo *);
void swap(nodo *, nodo *);
void replace(nodo *, tipo_elem);
nodo *remove_nodo(Tree *, nodo *);
nodo *get_leaf(nodo *); // Implementado a mais
nodo *insertLeft(Tree *, nodo *, tipo_elem);
nodo *insertRight(Tree *, nodo *, tipo_elem);
nodo *insertRoot(Tree *, tipo_elem); // Implementado a mais
nodo *search(Tree *, nodo *, tipo_elem);
nodo *expandExternal(Tree *, nodo *);
nodo *removeAboveExternal(Tree *, nodo *);
nodo *leaf_null(nodo *); // Implementado a mais
