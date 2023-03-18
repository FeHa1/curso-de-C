/* ACA VEMOS PILAS Y COLAS */
/* ESTE ES UN EJEMPLO DE COMO HACER PILAS*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 


#define CANT 4 // esta es una variable global de valor 4 siempre en este codigo 


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux)
{
    printf("%d \n", aux.dato); // "aux.dato" es para mostrar el contenido de lo que guardamos en desapilar 
}


nodo* crear_nodo(int dato ) // esto es como lo que veniamos haciendo hasta ahora pero lo aclaro en la carpeta igual 
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}


void apilar(nodo** p, nodo* u) // apilar recibe que "p" esta apuntando a NULL y a la direccion de "u"
{
    printf("apilar_nodo\n");

  	u->siguiente = *p; // aca hago que "*p" apunte a NULL
  	printf("%02d p=%X u=%X\n", u->dato, *p, u); // quiero mostrar "u -> dato" pero con dos decimales (%02d), con lo que aparece al lado p=%X u=%X significa que 
                                                // quiero que me muestre la direccion de memoria de "*p" y "u" 

	*p = u; // "*p" es el que va a mantener el tope de pila, el "u" es el que me permite guardar memoria y hacer el enganche pero muere en la funcion apilar
}


nodo desapilar(nodo** p) // va a ir a donde este apuntando "*p" 
                         // el valor nodo va a devolver un entero 
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;                                          // todo lo de aca esta aclarado en la carpeta

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}


int main()
{
    int i,num;
    nodo* p=NULL;


    for(i=0; i<CANT; i++) // hay que acordarse que CANT tiene valor 4, osea que me va a permitir ingresar 4 numeros
                          // en esta funcion se ingresan los valores con los que se trabajan
    {
   	    printf("Ingrese un numero \n");
   	    scanf("%d",&num);
   	    apilar(&p, crear_nodo(num)); // se pone "&p" y no "p" (como se hace en un puntero normal) porque quiero la direccion de memoria 
                                     // donde se almaceno "p" // tambien hay un segundo parametro "crear_nodo(num)" que aclare en la carpeta
    }


    printf("\nVamos a desapilar todo\n"); // con esta funcion se van a desapilar siendo el ultimo que entro el primero en salir
	while(p!=NULL)
    {
    	mostrar(desapilar(&p)); // aca llamo al mostrar, pero el mostrar llama al desapilar
                                // entonces primero se ejecuta el desapilar y despues el mostrar
    }


   return 0;
}



/* ESTE ES UN EJERCICIO QUE ES LO MISMO DE ARRIBA SOLO QUE CON OTRAS ACLARACIONES*/
/* De los numeros que ingreso a la pila contar cuantos son multiplos de 4*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4  


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *cont, int *acum) // tambien es una funcion "void" osea que no devuelve nada por eso hay que poner "*cont", porque lo uso 
                                              // desde su contenido 
                                              // tambien podemos hacer otras operaciones (como sacar el promedio) pero seguir llamando al contenido
{
    // cont = 0; // no pongo un "cont" aca porque no va a avanzar nunca porque, cuando vuelve para seguir sumando, vuelve a cero 
    printf("%d \n", aux.dato); // aca tengo el dato que acabo de desapilar
    if(aux.dato % 4 == 0)
    {
        *cont = *cont + 1;
        *acum = *acum + aux.dato;
    }
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);  

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


int main() // lo mas logico seria hacerlo en el "int main()" porque ingreso un numero y lo cuento abajo ++
{
    int i,num, cont = 0, acum = 0; // pongo aca el contador para que los vaya sumando, pero lo de arriba en el "mostrar" es lo importante 
    nodo* p=NULL;


    for(i=0; i<CANT; i++) // ++aca abajo podria contarlo , pero no se puede, hay que hacerlo en la funcion "mostrar" porque es la mas facil
    {
   	    printf("Ingrese un numero \n");
   	    scanf("%d",&num);
   	    apilar(&p, crear_nodo(num)); 
    }


    printf("\nVamos a desapilar todo\n"); 
	while(p!=NULL)
    {
    	mostrar(desapilar(&p)); 
    }

    printf("\nLos numeros multiplos de 4 son: %d", cont);
    printf("\nEl promedio de los valores es: %d", acum);

    return 0;
}



/* ESTE ES UN EJEMPLO DE COMO HACER COLAS*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10 


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


void acolar(nodo** p, nodo** u, nodo *q) // esto es lo unico que va a cambiar con respecto a las pilas, el resto es todo muy parecido, por no decir igual
                                        // *q es la direccion donde recervamos memoria para el nuevo nodo 
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    {
        *p = *u = q; /*porque hay uno solo*/
    }
    
    else
    {
    	(*u)->siguiente = q;
    	(*u) = q;
    }
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u); // cuando imprimo, imprimo la direccion de memoria de *p y *u
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
   nodo* p=NULL; // ambos punteros estan en NULL +
   nodo* u=NULL; // +

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num)); //  vemos que tenemos dos putnteros "p" y "u"

   }


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p));
   }
   return 0;
}



/*
Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4

typedef struct pila
{
    int dato;
    struct pila *sig;
    
}nodo;


void mostrar (nodo aux, int *acum, int num2)
{
    printf("%d \n", aux.dato);  
    if(aux.dato > num2)
    {
        *acum = *acum + aux.dato;
    }   
}


nodo *crear_nodo(int dato)
{
    nodo *u;
    u = (nodo*)malloc(sizeof(nodo));
    u -> dato = dato; 
    u -> sig = NULL;
    
    return u;
}


void apilar(nodo **p, nodo *u)
{
    printf("\nApilar nodo: ");
    u -> sig = *p;
    
    printf("%d", u -> dato);
    *p = u;
}


nodo desapilar(nodo **p)
{
    nodo *aux;
    nodo dato;
    
    dato = **p;
    aux = *p;
    *p = (*p) -> sig;
    free(aux);
    
    return dato;
}


int main()
{
    int i, num, acum = 0, num2;
    nodo *p = NULL; 
    
    for(i = 0; i < CANT; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &num);
        
        if(i == 0) // esto es para quedarme con el primer numero 
        {
            num2 = num;
        }
        
        apilar(&p, crear_nodo(num));
    }
    
    printf("\nVamos a desapilar todo: "); 
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), &acum, num2); 
    }

    printf("\nEl resultado es: %d", acum);
   return 0;
}
