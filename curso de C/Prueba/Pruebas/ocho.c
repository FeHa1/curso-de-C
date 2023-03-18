/* Aca trabajamos con INSERTAR Y ELIMINAR EN UNA LISTA SIMPLEMENTE ENLAZADA*/
/* Este es un ejemplo de una lista simplemente enlazada sin eliminar*/

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int num;
    struct list *sig;
} nodol;


nodol *insertarporcabezadelista(nodol *h) // va a devolver la posicion de memoria de puntero que se modificó
{
    nodol *a = NULL; // la "a" va a ser la variable local 
    if (h -> num % 2 != 0)
    {
        a = (nodol*)malloc(sizeof(nodol));
        a -> num = 0; // aca inserto una cajita antras del cabeza de lista 
        a -> sig = h; // con esto hago que "a" apunte a "h" 
        h = a; // aca hago que "h" apunte a la caja que habia insertado en la fila anterior de "a -> num = 0"
    }
    return h; // retorno "h" porque es el que tiene la nueva direccion 
}


void cargar (nodol *h) 
{
  printf("ingrese numero: ");
  scanf("%d",&h->num);
  if (h->num==0)
  {
    h->sig=NULL;
  }
  else
  {
    h->sig=(nodol*)malloc(sizeof(nodol));
    cargar(h->sig);
  }        
}


void mostrar (nodol *h)
{
  if (h->sig != NULL)
  {
    printf("%d\n ",h->num);
    mostrar(h->sig);
  }
}


void insertarenlalista(nodol *h)
{
    nodol *a = NULL;
    while (h -> sig != NULL)
    {
        if (h -> num % 2 != 0)
        {
            a = (nodol*)malloc(sizeof(nodol));
            a -> num = 0;
            a -> sig = h -> sig;
            h -> sig = a;
            h = h -> sig; // cuando inserte estoy salteando el valor que inserte para que no se quede ahi y deje
                          // sin evaluar las otras cajas que quedan por analizar 
        }
        h = h -> sig; // esta linea comparte la funcion con la linea de arriba 
    }
}


int main()
{
  nodol *p = NULL;
  p = (nodol*)malloc(sizeof(nodol));
  cargar(p);
  mostrar(p);
  p = insertarporcabezadelista(p); // esto es para avisarle cual es mi nueva direccion, sino el programa se queda
                                   // con el primer valor que le ingrese y no lo cambia
  printf("\nLa lista con insercion por cabeza es: ");
  mostrar(p);
  insertarenlalista(p);
  printf("\nLa lista con insercion es: ");
  mostrar(p);

  return 0;
}



/* Este es un ejemplo de insertar y eliminar en las listas simplemente enalazadas*/

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
        int num;
        struct list *sig;
} nodol;
 

nodol *insertarporcabezadelista(nodol *h) // va a devolver la posicion de memoria de puntero que se modificó
{
    nodol *a = NULL; // la "a" va a ser la variable local 
    if (h -> num % 2 != 0)
    {
        a = (nodol*)malloc(sizeof(nodol));
        a -> num = 0; // aca inserto una cajita antras del cabeza de lista 
        a -> sig = h; // con esto hago que "a" apunte a "h" 
        h = a; // aca hago que "h" apunte a la caja que habia insertado en la fila anterior de "a"
    }
    return h; // retorno "h" porque es el que tiene la nueva direccion 
}


nodol *eliminar1(nodol *h)
{
    nodol *a = NULL;
    while (h -> num % 2 == 0) // aca estoy eliminando los impares 
    {
        a = h -> sig;
        free(h); // este se usa para eliminar las cajas que no quiero ya que no cumple con la condicion 
        h = a;
    }
    return h;
}
        

void cargar (nodol *h) 
{
  printf("ingrese numero: ");
  scanf("%d",&h->num);
  if (h->num==0)
        h->sig=NULL;
  else
  {
    h->sig=(nodol*)malloc(sizeof(nodol));
    cargar(h->sig);
  }        
}


void mostrar (nodol *h)
{
  if (h->sig != NULL)
  {
    printf("%d\n ",h->num);
    mostrar(h->sig);
  }
}


void insertarenlalista(nodol *h)
{
    nodol *a = NULL;
    while (h -> sig != NULL)
    {
        if (h -> num % 2 != 0)
        {
            a = (nodol*)malloc(sizeof(nodol));
            a -> num = 0;
            a -> sig = h -> sig;
            h -> sig = a;
            h = h -> sig; // cuando inserte estoy salteando el valor que inserte para que no se quede ahi y deje
                          // sin evaluar las otras cajas que quedan por analizar 
        }
        h = h -> sig; // esta linea comparte la funcion con la linea de arriba 
    }
}


void eliminar2(nodol *h)
{
    nodol *a = NULL;
    while (h -> sig != NULL)
    {
        if (h -> sig -> num % 2 != 0) // este es un ejemplos en el que eliminamos los pares
        {
            a = h -> sig -> sig;
            free(h -> sig);
            h -> sig = a;
             
        }
        h = h -> sig; // en este caso esto es para que no pare desoues de que hizo una eliminacion 
                      // sino que siga con el siguiente y asi sucesivamente 
    }
}


int main()
{
  nodol *p = NULL;
  p = (nodol*)malloc(sizeof(nodol));
  cargar(p);
  mostrar(p);
  /*
  p = insertarporcabezadelista(p); // esto es para avisarle cual es mi nueva direccion, sino el programa se queda
                                   // con el primer valor que le ingrese y no lo cambia
  printf("\nLa lista con insercion por cabeza es: ");
  mostrar(p);
  insertarenlalista(p);
  printf("\nLa lista con insercion es: ");
  mostrar(p);
  */
  p = eliminar1(p);
  mostrar(p);
  eliminar2(p);
  printf("\nLista con eliminacion: ");
  mostrar(p);

  return 0;
}



/*INSERTAR Y ELIMINAR EN LISTAS SIMPLEMENTE ENLAZADAS*/
/*Eliminar e insertar los valores que correspondan (no se la consigna porque lo hicimos en clase)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumnos
{
  int legajo;
  char nombre[30];
  int cant;
  struct alumnos *sig;
}nodoa;


void crearlista(nodoa *h)
{
	printf("ingrese legajo");
	scanf("%d",&h->legajo);
	if (h->legajo==0)
  {
    h->sig=NULL;
  }
		
	else
  {
		printf("ingrese nombre y apellido");
		scanf("%s",h->nombre);
		printf("ingrese cant de materias aprobadas");
		scanf("%d",&h->cant);
	  h->sig=(nodoa *)malloc(sizeof(nodoa));
		crearlista(h->sig);
	}
}


void mostrarlista(nodoa *h){
if (h->sig!=NULL)
  {
		printf("%d \n",h->legajo);
		printf("%s \n",h->nombre);
		printf("%d  \n",h->cant);
		mostrarlista(h->sig);
	}
	
}


nodoa *insertarporcabeza(nodoa *h)
{
	nodoa *aux=NULL;
	if(h->cant==0)
  {
		aux=(nodoa *)malloc(sizeof(nodoa));
		aux->legajo=h->legajo; //este apunta al primer nodo 
		strcpy(aux->nombre, h->nombre); //se cambian los valores con el "strcpy" dado que no lo puedo cambiar de otra manera por ser de tipo char
		aux->cant=1; //esto esta asi con este valor para ejemplificar como se inserta y no cambiar nada 
		aux->sig=h; //aca se apunta al primer nodo
		h=aux; //y hacemos que "h" vaya a la posicion en la que esta "aux" pera que sea el nuevo primer nodo
	}

	return h;
}


void insertar(nodoa *h) //aca inserto entre los nodos
{
	nodoa *aux=NULL;
	while(h->sig!=NULL)
  {
		if(h->cant==0)
    {
			aux=(nodoa *)malloc(sizeof(nodoa));
		  aux->legajo=h->legajo; 
		  strcpy(aux->nombre, h->nombre); 
		  aux->cant=1; 
			aux->sig=h->sig; //hago que "aux" apunte al nodo que esta adelante, por eso no pongo "aux->sig=h" como arriba 
			h->sig=aux; //aca hago que la cajita anterior apunte al nodo "aux", porque si no hago esto se pierde el cabeza de lista
                  //se enlaza del nuevo nodo (aux) a la lista y de la lista al nuevo nodo (aux) porque si hago primero de la lista
                  //al nuevo nodo (aux) pierdo todo el resto de los nodos que tenia por delante
		}          

		h=h->sig; //aca solo camino en "h"
	}
}


nodoa *eliminarporcabeza(nodoa *h) //devuelve una direccion de memoria, por eso el "nodoa *"
{
	nodoa *aux=NULL;
	while(h->cant==50) //esta es la condicion de eliminacion que funciona para este caso nomas 
  {
		aux=h->sig; //hago que el "aux" avance una cajita adelante de donde encontro que se cumple la condicion
		free(h); //libero la cajita de atras de "aux", porque es la que cumple la condicion 
		h=aux; //aca hago que "h" apunte a donde apunta "aux", que vendria a ser el nodo siguiente al nodo que acabo de borrar
	}

	return h; //retorno "h" para que le mande al programa principal en donde se va a parar "p" a la hora de devolver
}


void eliminar(nodoa *h)
{
	nodoa *aux=NULL;
	while(h->sig!=NULL) 
  {
    if(h->sig->cant==50) //el primero viene de eliminar por cabeza de lista (osea que nunca va a cumplir la condicion) por eso cuando quiera 
                         //eliminar voy a preguntar por el siguiente 
    {
			aux=h->sig->sig; //me salto la caja que voy a eliminar para poner el "aux" 
			free(h->sig); //elimino la caja siguiente a "h", por eso arriba salto dos cajas para poner el "aux"
			h->sig=aux; //aca lo enlazo con el "aux"
		}

    else
    {
			h=h->sig; //con esto directamente camino hacia el siguiente nodo, pero solo si no borre
		}
	}
}


int main() 
{
  nodoa *p=NULL;
	nodoa *q=NULL;
	p=(nodoa *)malloc(sizeof(nodoa));
	q=(nodoa *)malloc(sizeof(nodoa));
	crearlista(p);
	mostrarlista(p);
	p=insertarporcabeza(p);
	insertar(p);
	p=eliminarporcabeza(p);
	eliminar(p);
	printf("la lista con eliminaciones es");
	mostrarlista(p);
}



/*Hacer insercion y eliminacion pero agregando otra lista*/
/*
1) Generar una lista con los numeros multiplos de 2
2) Eliminar los nuemros impares
3) Insertar el doble despues de cada nodo impar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numeros
{
  int num;
  struct numeros *sig;
}nodoa;


void crearlista(nodoa *h)
{
	printf("ingrese nuemro: ");
	scanf("%d",&h->num);

	if (h->num==-1)
  {
    h->sig=NULL;
  }
		
	else
  {
	  h->sig=(nodoa *)malloc(sizeof(nodoa));
		crearlista(h->sig);
	}
}


void mostrarlista(nodoa *h)
{
	if (h->sig!=NULL)
  {
		printf("%d  \n",h->num);
		mostrarlista(h->sig);
	}
}


void generar(nodoa *h, nodoa *t)
{
  while(h->sig != NULL)
  {
    if(h->num%2==0)
    {
      t->num = h->num;
      t->sig = (nodoa *)malloc(sizeof(nodoa));
      t = t->sig;
    }

    h = h->sig;
  }

  t->sig = NULL;
}


nodoa *insertarporcabeza(nodoa *h)
{
	nodoa *aux=NULL;
	if(h->num)
  {
		aux=(nodoa *)malloc(sizeof(nodoa));
		aux->legajo=h->legajo; //este apunta al primer nodo 
		strcpy(aux->nombre, h->nombre); //se cambian los valores con el "strcpy" dado que no lo puedo cambiar de otra manera por ser de tipo char
		aux->cant=1; //esto esta asi con este valor para ejemplificar como se inserta y no cambiar nada 
		aux->sig=h; //aca se apunta al primer nodo
		h=aux; //y hacemos que "h" vaya a la posicion en la que esta "aux" pera que sea el nuevo primer nodo
	}

	return h;
}


void insertar(nodoa *h) //aca inserto entre los nodos
{
	nodoa *aux=NULL;
	while(h->sig!=NULL)
  {
		if(h->num%2 == 0)
    {
			aux=(nodoa *)malloc(sizeof(nodoa));
		  aux->num=(h->num)*2; //pongo *2 porque queremos agregarr el doble de lo que estamos apuntando 
			aux->sig=h->sig; //hago que "aux" apunte al nodo que esta adelante, por eso no pongo "aux->sig=h" como arriba 
			h->sig=aux; //aca hago que la cajita anterior apunte al nodo "aux", porque si no hago esto se pierde el cabeza de lista
                  //se enlaza del nuevo nodo (aux) a la lista y de la lista al nuevo nodo (aux) porque si hago primero de la lista
                  //al nuevo nodo (aux) pierdo todo el resto de los nodos que tenia por delante
      h=h->sig; //con este camino sobre el que inserte y me paro sobre el proximo numero (que es la linea de abajo)
		}          

		h=h->sig; //aca solo camino en "h"
	}
}


nodoa *eliminarporcabeza(nodoa *h) //este elimina por cabeza
                                   //devuelve una direccion de memoria, por eso el "nodoa *"
{
	nodoa *aux=NULL;
	while(h->num%3 == 0) //esta es la condicion de eliminacion que funciona para este caso nomas 
  {
		aux=h->sig; //hago que el "aux" avance una cajita adelante de donde encontro que se cumple la condicion
		free(h); //libero la cajita de atras de "aux", porque es la que cumple la condicion 
		h=aux; //aca hago que "h" apunte a donde apunta "aux", que vendria a ser el nodo siguiente al nodo que acabo de borrar
	}

	return h; //retorno "h" para que le mande al programa principal en donde se va a parar "p" a la hora de devolver
}


void eliminar(nodoa *h) //este elimina en cualqueir lugar de la lista
{
	nodoa *aux=NULL;
	while(h->sig!=NULL) 
  {
    if(h->sig->num%3 == 0) //el primero viene de eliminar por cabeza de lista (osea que nunca va a cumplir la condicion) por eso cuando quiera 
                         //eliminar voy a preguntar por el siguiente 
    {
			aux=h->sig->sig; //me salto la caja que voy a eliminar para poner el "aux" 
			free(h->sig); //elimino la caja siguiente a "h", por eso arriba salto dos cajas para poner el "aux"
			h->sig=aux; //aca lo enlazo con el "aux"
		}

    else
    {
			h=h->sig; //con esto directamente camino hacia el siguiente nodo, pero solo si no borre
		}
	}
}


int main() 
{
  nodoa *p=NULL;
	nodoa *q=NULL;
	p=(nodoa *)malloc(sizeof(nodoa));
	q=(nodoa *)malloc(sizeof(nodoa));
	crearlista(p);
	mostrarlista(p);
  generar(p, q);
  printf("\nLa lista con numeros pares es: ");
  mostrarlista(q);
  p=eliminarporcabeza(p);
	eliminar(p);
	printf("la lista con eliminaciones es: ");
  mostrarlista(p);
	insertar(p);
  printf("\nLa lista con inserciones es: ");
  mostrarlista(p);
}




/*********************************************************************************************************************/

/*Pilas y Colas*/
//Ejemplo con maximo y promedio con PILAS.

#include<stdlib.h>
#include<string.h>


#define CANT 4


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *acum, int *max, int *segundo, int *cont)

{
     	printf("%d \n", aux.dato);
     	*acum=*acum+aux.dato;
     	if (aux.dato > *max)
            *max=aux.dato;
            
        if (aux.dato > segundo )
                *cont=*cont+1;
            
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

int main()
{


   int i,num,acum=0,max,segundo,cont=0;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	if (i==1)
        segundo=num;
   	apilar(&p, crear_nodo(num));
   }
   max=num;

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&acum, &max, &segundo, &cont);
   }
   printf("%d\n",acum/CANT);
   printf("%d \n",max);
   printf("%d \n",cont);
   

   getch();
   return 0;
}


/*
Dada una pila de numeros enteros determinar: 
a) La cantidad de numeros multiplos del ultimo numero ingresado a la pila. 
b) El valor minimo y la posicion dentro de la pila. 
c) Ingresar un numero por teclado y determinar si esta en la pila, cuantas veces esta 
   y sino esta mostrar un cartel. 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *acum, int *max, int *segundo, int *cont, int *ultimo, int *min, int *posicion)

{
    *posicion = *posicion-1;
    
     	printf("%d \n", aux.dato);
     	*acum=*acum+aux.dato;
     	if (aux.dato > *max)
     	{
            *max=aux.dato;
     	}
            
        if(aux.dato < *min)
        {
            *min = aux.dato;
            *posicion;
        }
            
        if (aux.dato & *ultimo == 0 && aux.dato != *ultimo)
        {
            *cont=*cont+1;
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
   int i,num,acum=0,max,segundo,cont=0, ultimo, min, posicion;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	if (i==1)
        segundo=num;
   	apilar(&p, crear_nodo(num));
   }
   max=num;
   min=num;
   ultimo=num;

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&acum, &max, &segundo, &cont, &ultimo, &min, &posicion);
   }
   printf("%d\n",acum/CANT);
   printf("%d \n",max);
   printf("\nLa cantidad de multiplos del ultimo es: %d",cont);
   printf("\nEl valor minimo y su posicion es: %d", min, posicion);
   

   getch();
   return 0;
}


//COLAS
/*



me olvide de copiar




*/






/*
Hacer una pila con lo siguiente: 

1) La cantidad de números múltiplos de 3.
2) El promedio de aquellos números divisores de 4.
3) La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
4) El número máximo y su posición en la pila.
5) El número mínimo y su posición en la pila.
6) Ingresar un numero por teclado y calcular la cantidad de veces que está en la pila.
Si no está, mostrar una leyenda.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *cont, int *acum, float *prom, int *primero, int *acum_sum, int *pos_max, int *max, int *pos_min, int *min, int *cont_sim, int num2, int *p1)
{

    printf("\n%d", aux.dato);
    if(aux.dato % 3 == 0 && aux.dato % 2 != 0)
    {
        *cont += 1;
    }
    
    if(aux.dato % 4 == 0)
    {
        *acum += aux.dato;
        *cont += 1;
        
        *prom = *acum/ *cont;
    }
    
    if(aux.dato % *primero == 0)
    {
        *acum_sum += aux.dato;
    }
    
    if(aux.dato > *max)
    {
        *max = aux.dato;
        *pos_max = *p1;
    }
    
    if(aux.dato < *min)
    {
        *min = aux.dato;
        *pos_min = *p1;
    }
    
    if(aux.dato == num2)
    {
        *cont_sim += 1;
    }
    
    *p1 = *p1 - 1; 
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
    int i, num, cont = 0, acum = 0, primero, acum_sum = 0, pos_max, max, pos_min, min, cont_sim = 0, num2, p1;
    float  prom = 0;
    nodo* p=NULL;
   
    for(i=0; i<CANT; i++)
    {
   	    printf("\nIngrese un numero: ");
   	    scanf("%d", &num);
   	    if(i == 0)
   	    {
   	        primero = num;
   	    }
   	    apilar(&p, crear_nodo(num));
    }
    
    printf("\nIngrese otro numero: ");
    scanf("%d", &num2);
    
    p1 = CANT;
    
    max = num;

    printf("\nVamos a desapilar todo\n");
	  while(p!=NULL)
    {
    	mostrar(desapilar(&p), &cont, &acum, &prom, &primero, &acum_sum, &pos_max, &max, &pos_min, &min, &cont_sim, num2, &p1);
    }
    
    printf("\nLa cantidad de multiplos de 3 es: %d", cont);
    printf("\nEl promedio de los divisores de 4 es: %f", prom);
    printf("\nLa sumatoria de aquellos números múltiplos del primer elemento son: %d", acum_sum);
    printf("\nEl elemento maximo es %d y está en la posicion %d", max, pos_max);
    printf("\nEl elemento minimo es %d y está en la posicion %d", min, pos_min);
    printf("\nLa cantidad de veces que esta un numero en la pila es: %d", cont_sim);

    getch();
    return 0;
}

//corregido e impecable

/*
1) La productoria de los números múltiplos de 7.
2) El promedio de aquellos números divisores del último número ingresado a la cola
3) Sumatoria de aquellos números divisores de primer elemento ingresado a la cola.
4) El número máximo y su posición en la cola.
5) El número mínimo y su posición en la cola.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *primero, int *acum_prim, int *ultimo, int *acum_ulti, int *cont_ulti, int *max, int *min, int *pos_max, int *pos_min, int *produc)
{
    *pos_min = pos_min + 1;
    *pos_max = pos_max + 1;
    
    printf("%d \n", aux.dato);
    //La productoria de los números múltiplos de 7.
    if(aux.dato % 7 == 0)
    {
        *produc = *produc * aux.dato; 
    }
    //El promedio de aquellos números divisores del último número ingresado a la cola
    if(*ultimo % aux.dato == 0)
    {
        *acum_ulti += aux.dato;
        *cont_ulti += 1;
    }
    //Sumatoria de aquellos números divisores de primer elemento ingresado a la cola.
    if(*primero % aux.dato == 0)
    {
        *acum_prim += aux.dato;
    }
    //El número máximo y su posición en la cola.
    if(aux.dato > *max)
    {
        *max = aux.dato;
        *pos_max;
    }
    //El número mínimo y su posición en la cola.
    if(aux.dato < *min)
    {
        *min = aux.dato;
        *pos_min;
    }
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
    
	if(*p==NULL)
	{
        *p = *u = q; /*porque hay uno solo*/
	}
	
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
    int i, num, primero, acum_prim = 0, ultimo, acum_ulti, cont_ulti, max, min, pos_max = 0, pos_min = 0, produc = 0;
    nodo* p=NULL;
    nodo* u=NULL;

    for(i=0; i<CANT; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);
        if(i == 0)
        {
            primero = num;
        }
        acolar(&p, &u, crear_nodo(num));
    }
    
    ultimo = num;
    
    max = num;
    min = num; 
    
    printf("\nVamos a desacolar todo\n");
	  while(p!=NULL)
    {
        mostrar(desacolar(&p), &primero, &acum_prim, &ultimo, &acum_ulti, &cont_ulti, &max, &min, &pos_max, &pos_min, &produc);
    }
    
    printf("\nLa productoria de los multiplos de 7 es: %d", produc);
    printf("\nEl promedio de los numeros divisores del ultimo es: %f", acum_ulti/cont_ulti);
    printf("\nLa sumatoria de los divisores del primer elemento es: %d", acum_prim);
    printf("\nEl numero maximo es %d y su posicion en la cola es %d", max, pos_max); //las posiciones estan medio raras
    printf("\nEl numero minimo es %d y su posicion en la cola es %d", min, pos_min); //las posiciones estan medio raras
    
    return 0;
}



/*
Crear una pila con la siguiente información:

Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *primero, int *acum_pri)
{
    printf("%d \n", aux.dato);
    if(aux.dato > *primero)
    {
        *acum_pri = *acum_pri + aux.dato;
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
    int i, num, primero, acum_pri = 0;
    nodo* p=NULL;
    
    for(i=0; i<CANT; i++)
    {
   	    printf("\nIngrese un numero: ");
   	    scanf("%d",&num);
   	    if(i == 0)
   	    {
   	        primero = num;
   	    }
   	    apilar(&p, crear_nodo(num));
    }
    
    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), &primero, &acum_pri);
    }
    
    if(acum_pri != 0)
    {
        printf("\nLa suma de los elementos mayores al primer elemento es: %d", acum_pri);
    }
    
    if(acum_pri == 0)
    {
        printf("\nNo hay ningun elemento mayor al primer elemento.");
    }

    getch();
    return 0;
}


/*
Crear una cola con la siguiente información:

Desarrollar una función que permita mostrar el promedio de tres primeros
números ingresados a la cola. Si no hubiese tres números, mostrar una leyenda y
no calcular el promedio. 
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

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
    
	if(*p==NULL)
	{
        *p = *u = q; /*porque hay uno solo*/
	}
	
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
    int i, num, primero, segundo, tercero, nums;
    float prom;
    nodo* p=NULL;
    nodo* u=NULL;

    for(i=0; i<CANT; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d",&num);
        if(i == 0)
        {
            primero = num;
        }
        
        if(i == 1)
        {
            segundo = num;
        }
        
        if(i == 2)
        {
            tercero = num;
        }
        
        acolar(&p, &u, crear_nodo(num));
    }
    
    nums = primero + segundo + tercero; 
    
    prom = nums/3;

    printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
    {
        mostrar(desacolar(&p));
    }
    
    printf("\nEl promedio de los 3 primeros numeros es: %f", prom);
    
    return 0;
}



/*
Escribir la función necesaria para calcular la cantidad de elementos múltiplos del
último número ingresado a la pila. Si no hubiera ningún número mostrar una
leyenda.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *ultimo, int *cant)
{
    printf("%d \n", aux.dato);
    if(aux.dato % *ultimo == 0 && aux.dato != *ultimo)
    {
        *cant += 1;
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
    int i, num, ultimo, cant = 0;
    nodo* p=NULL;
   
    for(i=0; i<CANT; i++)
    {
   	    printf("\nIngrese un numero: ");
   	    scanf("%d",&num);
   	    apilar(&p, crear_nodo(num));
    }
    
    ultimo = num;

    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), &ultimo, &cant);
    }
    
    printf("\nLa cantidad de multiplos del ultimo numero ingresado son: %d", cant);

    getch();
    return 0;
}






