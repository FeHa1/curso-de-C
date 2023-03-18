/* ACA VEMOS MULTILISTAS*/ //multi level linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista1
{
     int legajo;
     char nombre[30];
     struct lista2 *l2; //con esto el programa entiende que hay dos listas, ya que se encuentra con dos "struct" y que tambien asigne otro puntero (l2)
     struct lista1 *sig;
}nodo1;


typedef struct lista2
{
     char nombre_mat[20];
     int nota;
     struct lista2 *sig2; //esto viene a actuar como un "sig" normal que avanza hacia la derecha, pero lo hace en la segunda lista que creamos arriba 
}nodo2;


void crearlistamateria(nodo2 *);
void crearlista(nodo1 *);
void mostrarlistamaterial(nodo2 *);


void crearlistamateria(nodo2 *h)
{
     printf("\nIngrese el nombre de la materia: ");
     scanf("%s", h -> nombre_mat);

     if (strcmp(h -> nombre_mat, "x")==0)
     {
          h -> sig2 == NULL;
     }

     else
     {
          printf("\nINgrese nota: ");
          scanf("%d", &h -> nota);
          h -> sig2 = (nodo2 *)malloc(sizeof(nodo2));
          crearlistamateria(h -> sig2);
     }
}




void crearlista(nodo1 *h)
{
     printf("ing legajo");
     scanf("%d",&h->legajo);

     if(h->legajo==0)
     {
          h->sig=NULL;
     }

     else
     {
          printf("ing nombre");
          scanf("%s", h->nombre); //le saco el "&" porque es un string
          h->l2=(nodo2 *)malloc(sizeof(nodo2)); //aca livero espacio de memoria para lo que voy a hacer abajo
          crearlistamateria(h->l2); //con esto creo las "sublistas" que se desprenden de las listas principales
          h->sig=(nodo1 *)malloc(sizeof(nodo1));
          crearlista(h->sig);
     }
}



void mostrarlistamaterias(nodo2 *h)
{
     if (h -> sig2 != NULL)
     {
          printf("\n%d", &h -> legajo);
          printf("\n%s", h -> nombre);
          mostrarlistamateria(h -> sig2);
     }
}



void mostrarlista(nodo1 *h) //va a mostrar al alumno y despues todas las materias, los mismo con los que le siguen 
{
     if (h -> sig != NULL)
     {
          printf("\n%d", h -> legajo);
          printf("\n%s", h -> nombre);
          mostrarlistamateria(h -> l2);
          mostrarlista(h -> sig);
     }
}



void crearlista(nodo1 *);
//void mostrarlistamateria(nodo2 *);
void mostrarlista(nodo1 *);


int main()
{
     nodo1 *p = NULL;
     p = (nodo1*)malloc(sizeof(nodo1);
     crearlista(p);
     mostrarlista(p);

     return 0;
}


/*********************************************************************************************************************/

/*ARBOLES BINARIOS DE BUSQUEDA*/

/*
Dado un arbol binario de busqueda hallar: 
a) El elemento maximo y el elemento minimo. 
b) La cantidad de nodos con un solo hijo que son divisores de la raiz. 
c) El peromedio de nodos hojas multiplos de la raiz. 
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("Ingrese numero: ");
    scanf ("%d", &numero);
    *raiz = numero;
    while (numero!=-1)
    {
        insertar(&(*hoja), numero);
        printf ("\nIngrese numero: ");
        scanf ("%d", &numero);
    }
}


void insertar(treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
    {
        return;
    }
        
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    
    else
    {
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


void mostrar (treenode *hoja, int raiz, int *menor, int *mayor, int *cant, float *acum_prom, float *cont_prom)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, menor, mayor, cant, acum_prom, cont_prom);
        printf("%d ",hoja->dato);
        //El elemento maximo y el elemento minimo
        if(hoja->dato > *mayor)
        {
            *mayor = hoja->dato; 
        }
        
        if(hoja->dato < *menor)
        {
            *menor = hoja->dato;
        }
        //La cantidad de nodos con un solo hijo que son divisores de la raiz. 
        if(((hoja->der == NULL && hoja->izq != NULL) || (hoja->der != NULL && hoja->izq == NULL)) && (raiz % hoja->dato == 0))
        {
            *cant += 1;
        }
        //El peromedio de nodos hojas multiplos de la raiz. 
        if((hoja->der == NULL && hoja->izq == NULL) && (hoja->dato % raiz == 0))
        {
            *acum_prom = *acum_prom + hoja->dato;
            *cont_prom = *cont_prom + 1;
        }
        
        mostrar(hoja->der, raiz, menor, mayor, cant, acum_prom, cont_prom);
    }
    
    return;
}


int main ()
{
    int raiz, menor, mayor, cant = 0; 
    float acum_prom = 0, cont_prom = 0;
    
    treenode* arbol=NULL;
    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("\nEl arbol es: \n");
    
    menor = raiz;
    mayor = raiz;
    
    mostrar(arbol, raiz, &menor, &mayor, &cant, &acum_prom, &cont_prom);
    
    printf("\nEl menor elemento es: %d", menor);
    printf("\nEl mayor elemento es: %d", mayor);
    printf("\nLa cantidad de nodos con un solo hijo mult. de la raiz son: %d", cant);
    printf("\nEl promedio de los multiplos de la raiz es: %f", acum_prom/cont_prom);

    return 0;
}


//ARBOL BINARIO 

/*
a) Buscar el mayor elemento del árbol divisor de la raíz
b) Cantidad de nodos hojas impares.
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("Ingrese numero: ");
    scanf ("%d", &numero);
    *raiz = numero;
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("\nIngrese numero: ");
        scanf ("%d",&numero);
    }
}


void insertar(treenode **hoja,int elem)
{
    int numero=elem;

    if (elem==-1)
    {
        return;
    }
        
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    
    else
    {
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


void mostrar (treenode *hoja, int raiz, int *mayor, int *impar)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, mayor, impar);
        printf("%d ", hoja->dato);
        //Buscar el mayor elemento del árbol divisor de la raíz
        if((hoja->dato > *mayor) && (raiz % hoja->dato == 0) && (hoja->dato != raiz))
        {
            *mayor = hoja->dato;
        }
        //Cantidad de nodos hojas impares.
        if((hoja->dato % 2 != 0) && (hoja->der == NULL && hoja->izq == NULL))
        {
            *impar += 1;
        }
        mostrar(hoja->der, raiz, mayor, impar);
    }
    
    return;
}


int main ()
{
    int raiz, mayor, impar;
    treenode* arbol=NULL;
    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("\nEl arbol es: \n");
    
    mostrar(arbol, raiz, &mayor, &impar);
    
    mayor = raiz;
    
    printf("\nEl mayor elemento del arbol divisor de la raiz es: %d", mayor);
    printf("\nLa cantidad de nodos hojas impares es: %d", impar);

    return 0;
}

//le falta un poco 



/*
a) Cantidad de los elementos pares con un hijo.
b) Mínimo elemento impar del árbol.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("Ingrese numero: ");
    scanf ("%d", &numero);
    *raiz = numero;
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("\nIngrese numero: ");
        scanf ("%d",&numero);
    }
}


void insertar(treenode **hoja,int elem)
{
    int numero=elem;

    if (elem==-1)
    {
        return;
    }
        
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    
    else
    {
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


void mostrar (treenode *hoja, int raiz, int *cont, int *min)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, cont, min);
        printf("%d ",hoja->dato);
        //Cantidad de los elementos pares con un hijo.
        if(hoja->dato % 2 == 0 && (hoja->der == NULL && hoja->izq != NULL) || (hoja->der != NULL && hoja->izq == NULL))
        {
            *cont += 1;
        }
        //Mínimo elemento impar del árbol.
        if((hoja->dato < *min) && (hoja->dato % 2 != 0))
        {
            *min = hoja->dato;
        }
        mostrar(hoja->der, raiz, cont, min);
    }
    
    return;
}


int main ()
{
    int raiz, cont = 0, min;
    treenode* arbol=NULL;
    crear (&arbol, &raiz);
    
    printf ("**************\n");
    printf ("\nEl arbol es: \n");
    
    min = raiz;
    
    mostrar(arbol, raiz, &cont, &min);
    
    printf("\nLa cantidad de elementos pares con un hijo es: %d", cont);
    printf("\nEl minimo elemento impar del arbol es: %d", min);

    return 0;
}





