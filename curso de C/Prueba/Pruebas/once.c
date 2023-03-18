/* ACA VEMOS ARBOLES BINARIOS */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int* );
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int, int *,int*);


int main ()
{
    int raiz;
    int cont=0;
    int cont1=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,raiz,&cont,&cont1);
    printf("\nla cantidad de multiplos de la raiz es %d",cont);
    printf("\n la cantidad de nodos hojas impares es %d",cont1);

    return 0;
}

void crear (treenode **hoja,int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{




    if (numero>(*hoja)->dato)
    {

        insertar (&(*hoja)->der,elem);

    }
    
    else
    {

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}


void mostrar (treenode *hoja,int raiz,int *cont,int *cont1)
{
    if (hoja!=NULL)
    {


        mostrar(hoja->izq,raiz,cont,cont1);
        if (hoja->dato%raiz==0 && hoja->dato!=raiz)
               *cont=*cont+1;

        if (hoja->izq==NULL && hoja->der==NULL && hoja->dato%2!=0)
                *cont1=*cont1+1;

        printf("%d ",hoja->dato);
        mostrar(hoja->der,raiz,cont,cont1);

    }
    return;
}



/* Actividad que hicimos con Juan*/

/*
Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar:
a)Cantidad de los elementos pares con un hijo.
b)Mínimo elemento impar del árbol. 
*/


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void crear(treenode **hoja);
void insertar(treenode **hoja,int elem);
void mostrar(treenode *hoja,int *contPares,int * Minim);


int main(){
    int contPares=0,Minim;
    
    printf ("**************\n");
    printf("arboles\n");
    treenode *arbol=NULL;
    
    
    crear(&arbol);
    printf ("**************\n");
    printf ("mostrar arbols\n");
    printf ("**************\n");
    Minim=arbol->dato;
    
    
    mostrar(arbol,&contPares,&Minim);
    printf("\n");
    
    printf ("**************\n");
    printf ("cantidad de elementos pares con un hijo\n");
    printf ("**************\n");
    printf ("%d\n",contPares);
    
    printf ("**************\n");
    printf ("minimo valor impar\n");
    printf ("**************\n");
    printf ("%d",Minim);
    
    

    return 0;
}


void crear(treenode **hoja){
    int num;
    
    printf("\ningrese numero\n");
    scanf("%d",&num);
    while(num!=-1){
        insertar(&(*hoja),num);
        printf("ingrese numero: \n");
        scanf("%d",&num);
    }
}


void insertar(treenode **hoja,int elem){
    int num= elem;
    if(elem==-1)
    {
        return;
    }

    if(*hoja==NULL){
        (*hoja)=(treenode *)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }

    else
    {
        if(num>(*hoja)->dato){
            insertar(&(*hoja)->der,elem);
        }
        else
        {
            insertar(&(*hoja)->izq,elem);
        }
    }
    return;
}


void mostrar(treenode *hoja,int *contPares,int *Minim){
    if(hoja!=NULL){
        mostrar(hoja->izq,contPares,Minim);
        printf("%d\n",hoja->dato);
        mostrar(hoja->der,contPares,Minim);
        if(hoja->dato %2==0 && ((hoja->der != NULL && hoja->izq == NULL)||(hoja->der == NULL && hoja->izq != NULL)))
        {
            *contPares=*contPares+1;
        }
        if(*Minim>hoja->dato && hoja->dato%2 !=0)
        {
            *Minim= hoja->dato;
        }
    }
}

