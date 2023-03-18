/*MATRICES*/
/*
Cargar una matriz de n*n de números enteros. Mostrar:
a) la sumatoria de los elementos de la 2º fila.
b) el mayor elemento de la segunda columna.
c) el promedio de todos los múltiplos de 5 en la matriz.
d) la sumatoria de la diagonal principal de la matriz.
e) el elemento mínimo de cada fila.
f) los elementos de la diagonal secundaria.
g) los elementos que se encuentran debajo de la diagonal principal.
h) si la matriz es simétrica.
*/

#include <stdio.h>

void cargar(int mat[10][10], int dim)
{
    int i, j;
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            printf("\nIngrese los valores de la matriz: ");
            scanf("%d", &mat[i][j]);
        }
    }
}

/*a) la sumatoria de los elementos de la 2º fila.*/
int suma(int mat[10][10], int dim)
{
    int i, j, acum=0; 
    for(i=1; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            acum += mat[i][j];
        }
    }
    
    return acum;
}

/*b) el mayor elemento de la segunda columna.*/
int mayor(int mat[10][10], int dim)
{
    int i, j, may=0;
    for(i=0; i<dim; i++)
    {
        for(j=1; j<dim; j++)
        {
            if(mat[i][j] > may)
            {
                may = mat[i][j];
            }
        }
    }
    
    return may;
}

/*c) el promedio de todos los múltiplos de 5 en la matriz.*/
float promedio(int mat[10][10], int dim)
{
    int i, j, acum=0, cont=0;
    float prom=0;
    
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            if(mat[i][j] % 5 == 0)
            {
                acum += mat[i][j];
                cont += 1;
            }
        }
    }
    
    return acum/cont;
}

/*d) la sumatoria de la diagonal principal de la matriz.*/
int diagPrin(int mat[10][10], int dim)
{
    int i=0, j=0, acum=0;
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            if(i == j)
            {
                acum += mat[i][j];
            }
        }
    }
    
    return acum;
}

/*e) el elemento mínimo de cada fila.*/
int minimo(int mat[10][10], int dim)
{
    int i, j, min;
    
    for(i=0; i<dim; i++)
    {
        min=mat[i][0];
        
        for(j=0; j<dim; j++)
        {
            if(mat[i][j] < min)
            {
                min = mat[i][j];
            }
        }
        
        printf("\nEl minimo elemento es: %d", min);
    }
}

/*f) los elementos de la diagonal secundaria.*/
int diagSecu(int mat[10][10], int dim)
{
    int i, j;
    for(i=0; i<dim; i++)
    {
        for(j=dim-1; j<=dim; j--)
        {
            printf("%d", mat[i][j-1]);
        }
    }
}//está mal pero va quieriendo 

void mostrar(int mat[10][10], int dim)
{
    int i, j;
    for(i=0; i<dim; i++)
    {
        printf("\n");
        for(j=0; j<dim; j++)
        {
            printf("%d\t", mat[i][j]);
        }
    }
}

int main()
{
    int mat[10][10], dim, may=0, acum=0, cont=0, min=0;
    float prom;
    printf("\nIngrese la dimension de la matriz: ");
    scanf("%d", &dim);
    cargar(mat, dim);
    suma(mat, dim);
    printf("\nLa suma de los elementos de la segunda fila son: %d\n", suma(mat, dim));
    mayor(mat, dim);
    printf("\nEl mayor elemento de la matriz es: %d\n", mayor(mat, dim));
    promedio(mat, dim);
    printf("\nEl promedio de todos los multiplos de 5 es: %f", promedio(mat, dim));
    diagPrin(mat, dim);
    printf("\nLa suma de los elementosd de la diagonal principal es: %d", diagPrin(mat, dim));
    minimo(mat, dim);
    diagSecu(mat, dim);
    printf("\nLos elementos de la diagonal secundaria son: %d", diagSecu(mat, dim));
    mostrar(mat, dim);

    return 0;
}

//falta


/*---------------------------------------------------------------------------------------------------------------------------------------------*/

/*PILAS Y COLAS*/
/*
MODELO DE COLAS
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux)
{
  	printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i,num;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    
    while(num != -1)
    {
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p));
   }
   return 0;
}


/*MODELO DE PILAS*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux)
{
    printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{
   int i,num;
   nodo* p=NULL;


    printf("Ingrese un numero: ");
    scanf("%d",&num);
    
    while(num != -1)
    {
        apilar(&p, crear_nodo(num));
       	printf("Ingrese un numero: \n");
       	scanf("%d", &num);
    }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p));
   }

   return 0;
}


/*PILAS*/

/*
1) La cantidad de números múltiplos de 3.
2) El promedio de aquellos números divisores de 4.
3) La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
4) El número máximo y su posición en la pila.
5) El número mínimo y su posición en la pila.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *mulTres, float *cantDivCuatro, float *acumDivCuatro, int *primero, int *acumPrim, int *maximo, int *pos_actual, int *posMax, int *posMin, int *minimo)
{
    //La cantidad de números múltiplos de 3.
    if(aux.dato % 3 == 0)
    {
        *mulTres += 1;
    }
    
    //El promedio de aquellos números divisores de 4.
    if(4 % aux.dato == 0)
    {
        *cantDivCuatro += 1;
        *acumDivCuatro = *acumDivCuatro + aux.dato;
    }
    
    //La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
    if(aux.dato % *primero == 0)
    {
        *acumPrim = *acumPrim + aux.dato;
    }
    
    //El número máximo y su posición en la pila.
    if(aux.dato > *maximo)
    {
        *maximo = aux.dato;
        *posMax = *pos_actual;
    }
    
    //El número mínimo y su posición en la pila.
    if(aux.dato < *minimo)
    {
        *minimo = aux.dato;
        *posMin = *pos_actual;
    }
    
    *pos_actual = *pos_actual - 1;
    
    printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");

  	u->siguiente = *p;
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{
   int i,num, mulTres=0, cont_pos=0, primero, acumPrim=0, maximo=0, pos_actual=0, posMax=0, posMin=0, minimo=0;
   float cantDivCuatro=0, acumDivCuatro=0;
   nodo* p=NULL;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    
    maximo = num;
    minimo = num;
    
    while(num != -1)
    {
        cont_pos += 1;
        if(cont_pos == 1)
        {
            primero = cont_pos;
        }

        apilar(&p, crear_nodo(num));
       	printf("Ingrese un numero: \n");
       	scanf("%d", &num);
    }

    pos_actual = cont_pos;

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), &mulTres, &cantDivCuatro, &acumDivCuatro, &primero, &acumPrim, &maximo, &pos_actual, &posMax, &posMin, &minimo);
   }
   
   printf("\nLa cantidad de multiplos de 3 es: %d", mulTres);
   printf("\nEl promedio de los numeros divisores de 4 es: %f", acumDivCuatro/cantDivCuatro);
   printf("\nLa sumatoria de los multiplos del primer numero ingresado son: %d", acumPrim);
   printf("\nEl maximo elemento es %d y su posicion es %d", maximo, posMax);
   printf("\nEl minimo elemento es %d y su posicion es %d", minimo, posMin);

   return 0;
}


/*COLAS*/

/*
1) La productoria de los números múltiplos de 7.
2) El promedio de aquellos números divisores del último número ingresado a la cola.
3) Sumatoria de aquellos números divisores de primer elemento ingresado a la cola.
4) El número máximo y su posición en la cola.
5) El número mínimo y su posición en la cola.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, float *contSiete, float *acumSiete, int *ultimo, float *contUltimo, float *acumUltimo, int *primero, int *acumPrimero, int *maximo, int *posMax, int *minimo, int *posMin)
{
    *posMax = *posMax + 1;
    *posMin = *posMin + 1;
    
    //La productoria de los números múltiplos de 7.
    if(aux.dato % 7 == 0)
    {
        *contSiete += 1;
        *acumSiete += aux.dato;
    }
    
    //El promedio de aquellos números divisores del último número ingresado a la cola.
    if(*ultimo % aux.dato == 0)
    {
        *contUltimo += 1;
        *acumUltimo += aux.dato;
    }
    
    //Sumatoria de aquellos números divisores de primer elemento ingresado a la cola.
    if(*primero % aux.dato == 0)
    {
        *acumPrimero += aux.dato;
    }
    
    //El número máximo y su posición en la cola.
    if(aux.dato > *maximo)
    {
        *maximo = aux.dato;
        *posMax;
    }
    
    //El número mínimo y su posición en la cola.
    if(aux.dato < *minimo)
    {
        *minimo = aux.dato;
        *posMin;
    }
    
    printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i,num, cont_pos=0, pos_actual=0, ultimo=0, primero, acumPrimero=0, maximo=0, posMax=0, minimo=0, posMin=0;
   float contSiete=0, acumSiete=0, contUltimo=0, acumUltimo=0;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    
    primero = num;
    maximo = num;
    minimo = num;
    
    while(num != -1)
    {
        cont_pos += 1;
        acolar(&p, &u, crear_nodo(num));
        ultimo = num;
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }

   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &contSiete, &acumSiete, &ultimo, &contUltimo, &acumUltimo, &primero, &acumPrimero, &maximo, &posMax, &minimo, &posMin);
   }
   
   printf("\nEl producto de los multiplos de 7 es: %f", acumSiete/contSiete);
   printf("\nEl producto de los divisores de ultimo numero es: %f", acumUltimo/contUltimo);
   printf("\nLa sumatoria de los divisores del primer numero es: %d", acumPrimero);
   printf("\nEl elemento maximo es %d y su posicion es %d", maximo, posMax); //lo de la posicion esta raro 
   printf("\nEl elemento minimo es %d y su posicion es %d", minimo, posMin);
   
   
   return 0;
}




/*---------------------------------------------------------------------------------------------------------------------------------------------*/

/*ARBOLES BINARIOS*/
//Modelo para las practicas

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
	int dato_num;
	struct arbol *izq;
    struct arbol *der;
}arbol_nodo;

void crear (arbol_nodo **hoja, int *raiz){
    int numero;
    printf("Ingrese Raiz:\n");
    scanf("%d",&numero);

    *raiz=numero;

    while (numero!= -1){
        insertar(&(*hoja),numero);
        printf("Ingrese numero:\n");
        scanf("%d", &numero);
    }
}

void insertar(arbol_nodo **hoja, int num){
    int numero=num;
    if (num== -1)
        return;
    if (*hoja ==NULL){
        (*hoja)=(arbol_nodo*)malloc(sizeof(arbol_nodo));
        (*hoja)->dato_num=num;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else{
        if(numero>(*hoja)->dato_num)
            insertar(&(*hoja)->der,num);
        else
            insertar(&(*hoja)->izq,num);
    }

    return;
}

void mostrar(arbol_nodo *hoja){
    if (hoja != NULL){
        mostrar(hoja->izq);
        printf(" %d ", hoja->dato_num);
        mostrar(hoja->der);
    }

    return;
}

int main(){
    int raiz;
    printf("Arboles\n");

    arbol_nodo* arbol=NULL;

    crear(&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar(arbol);

    return 0;
}


/*
a) Sumatoria de los elementos pares con dos hijos.
b) Mínimo elemento par divisor de la raíz del árbol.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
	int dato_num;
	struct arbol *izq;
    struct arbol *der;
}arbol_nodo;

void crear (arbol_nodo **hoja, int *raiz){
    int numero;
    printf("Ingrese Raiz:\n");
    scanf("%d",&numero);

    *raiz=numero;

    while (numero!= -1){
        insertar(&(*hoja),numero);
        printf("Ingrese numero:\n");
        scanf("%d", &numero);
    }
}

void insertar(arbol_nodo **hoja, int num){
    int numero=num;
    if (num== -1)
        return;
    if (*hoja ==NULL){
        (*hoja)=(arbol_nodo*)malloc(sizeof(arbol_nodo));
        (*hoja)->dato_num=num;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else{
        if(numero>(*hoja)->dato_num)
            insertar(&(*hoja)->der,num);
        else
            insertar(&(*hoja)->izq,num);
    }
    
    return;
}

void mostrar(arbol_nodo *hoja, int raiz, int *acum, int *min){
    if (hoja != NULL){
        mostrar(hoja->izq, raiz, acum, min);
        printf(" %d ", hoja->dato_num);
        
        if(hoja->dato_num % 2 == 0 && hoja->dato_num != raiz && (hoja->der != NULL && hoja->izq != NULL)) //Sumatoria de los elementos pares con dos hijos. 
        {
            *acum = *acum + hoja->dato_num;
        }
        
        if(hoja->dato_num % 2 == 0 && raiz % hoja->dato_num == 0 && hoja->dato_num < *min) //Mínimo elemento par divisor de la raíz del árbol.
        {
            *min = hoja->dato_num;
        }
        mostrar(hoja->der, raiz, acum, min);
    }
    
    return;
}

int main(){
    int raiz, acum=0, min;
    printf("Arboles\n");

    arbol_nodo* arbol=NULL;

    crear(&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    
    min = raiz;
    
    mostrar(arbol, raiz, &acum, &min);
    
    printf("\nLa suma de los elementos pares con dos hijos es: %d", acum);
    printf("\nEl minimo elemento par divisor de la raiz es: %d", min);

    return 0;
}


/*
a) El valor máximo múltiplo de la raíz.
b) La cantidad de nodos hojas divisores de la raíz.
c) La sumatoria de aquellos nodos pares con un hijo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
	int dato_num;
	struct arbol *izq;
    struct arbol *der;
}arbol_nodo;

void crear (arbol_nodo **hoja, int *raiz){
    int numero;
    printf("Ingrese Raiz:\n");
    scanf("%d",&numero);

    *raiz=numero;

    while (numero!= -1){
        insertar(&(*hoja),numero);
        printf("Ingrese numero:\n");
        scanf("%d", &numero);
    }
}

void insertar(arbol_nodo **hoja, int num){
    int numero=num;
    if (num== -1)
        return;
    if (*hoja ==NULL){
        (*hoja)=(arbol_nodo*)malloc(sizeof(arbol_nodo));
        (*hoja)->dato_num=num;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else{
        if(numero>(*hoja)->dato_num)
            insertar(&(*hoja)->der,num);
        else
            insertar(&(*hoja)->izq,num);
    }

    return;
}

void mostrar(arbol_nodo *hoja, int raiz, int *max, int *cant, int *acum){
    if (hoja != NULL){
        mostrar(hoja->izq, raiz, max, cant, acum);
        printf(" %d ", hoja->dato_num);
        
        if(hoja->dato_num > *max && hoja->dato_num % raiz == 0) //El valor máximo múltiplo de la raíz.
        {
            *max = hoja->dato_num;
        }
        
        if(raiz % hoja->dato_num == 0 && (hoja->der == NULL && hoja->izq == NULL)) //La cantidad de nodos hojas (no tienen hijo) divisores de la raíz.
        {
            *cant = *cant + 1;
        }
        
        if(hoja->dato_num % 2 == 0 && (hoja->der != NULL && hoja->izq == NULL || hoja->der == NULL && hoja->izq != NULL)) //La sumatoria de aquellos nodos pares con un hijo.
        {
            *acum = *acum + hoja->dato_num;
        }
        mostrar(hoja->der, raiz, max, cant, acum);
    }

    return;
}

int main(){
    int raiz, max, cant=0, acum=0;
    printf("Arboles\n");

    arbol_nodo* arbol=NULL;

    crear(&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    
    max = raiz;
    
    mostrar(arbol, raiz, &max, &cant, &acum);
    
    printf("\nEl numero maximo multiplo de la raiz es: %d", max);
    printf("\nLa cantidad de nodos hojas divisores de la raiz son: %d", cant);
    printf("\nLa sumatoria de los nodos pares con un hijo es: %d", acum);

    return 0;
}


/*---------------------------------------------------------------------------------------------------------------------------------------------*/

/*LISTAS SIMPLEMEMENTE ENLAZADAS*/
/*MODELO DE LISTAS*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int num;
	struct lista *sig;
}nodo;


void crear (nodo *p)
{

    	scanf("%d", &p->num);

   	if (p->num==0)
	{
        	p->sig=NULL;
	}

    	else
	{
        	p->sig=(nodo*)malloc(sizeof(nodo));
        	crear(p->sig);

	}

	return;
}

void mostrar (nodo *p)
{
    	if (p->sig != NULL)
	{
        	printf ("%d\n", p->num);
        	mostrar (p->sig);
	}

	return;
}


nodo* insertar1(nodo *p)
{
    	nodo *aux;
    	if()//condicion de insercion
    	{
        	aux=(nodo *)malloc(sizeof(nodo));
        	aux->num=0;//valor a insertar
        	aux->sig=p;
        	p=aux;
    	}

    	return p;
}


void insertar2 (nodo *p)
{
  	nodo *aux;
    	while(p->sig != NULL && p->sig->sig != NULL)
    	{
        	if() //condicion de insercion
        	{
            	aux=(nodo *)malloc(sizeof(nodo));
            	aux->num=0;//valor a insertar
            	aux->sig=p->sig;
            	p->sig=aux;

        	}

        	p=p->sig;
    	}
}


nodo* eliminar1(nodo* p)
{
	nodo *aux;
    	while()//condicion de eliminacion
    	{
        	aux=p->sig;
        	free(p);
        	p=aux;

    	}

    	return p;
}


void eliminar2(nodo* p)
{
    	nodo *aux;
    	while(p->sig != NULL && p->sig->sig != NULL)
    	{
        	if()//condicion de eliminacion
        	{
            	aux=p->sig->sig;
            	free(p->sig);
            	p->sig=aux;
        	}

        	else
        	{
            	p=p->sig;
        	}
    	}
}


int main()
{
    nodo *p=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);
    p = insertar1(p);
    insertar2(p);
    p = eliminar1(p);
    eliminar2(p);
    mostrar(p);

    return 0;
}



/*
Dada una lista de numeros enteros insertar la mitad antes de cada numero par. 
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int num;
	struct lista *sig;
}nodo;

void crear (nodo *p)
{
    printf("\nIngrese un numero: ");
    scanf("%d", &p->num);

   	if (p->num==0)
	{
        	p->sig=NULL;
	}

    	else
	{
        	p->sig=(nodo*)malloc(sizeof(nodo));
        	crear(p->sig);

	}

	return;
}

void mostrar (nodo *p)
{
    	if (p->sig !=NULL)
	{
        	printf ("%d\n", p->num);
        	mostrar (p->sig);
	}

	return;
}

//Dada una lista de numeros enteros insertar la mitad antes de cada numero par.
nodo* insertar1(nodo *p)
{
    	nodo *aux;
    	if(p->num % 2 == 0)
    	{
        	aux=(nodo *)malloc(sizeof(nodo));
        	aux->num=p->num/2;
        	aux->sig=p;
        	p=aux;
    	}

    	return p;
}

//Dada una lista de numeros enteros insertar la mitad antes de cada numero par.
void insertar2 (nodo *p)
{
  	nodo *aux;
    	while(p->sig != NULL && p->sig->sig != NULL)
    	{
        	if(p->sig->num) //condicion de insercion
        	{
            	aux=(nodo *)malloc(sizeof(nodo));
            	aux->num=p->sig->num/2;
            	aux->sig=p->sig;
            	p->sig=aux;

        	}

        	p=p->sig;
    	}
}

int main()
{
    nodo *p=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("\nLa lista sin insercion ni eliminacion es: \n");
    mostrar(p);
    p = insertar1(p);
    insertar2(p);
    printf("\nLa lista con insercion es: ");
    mostrar(p);

    return 0;
}