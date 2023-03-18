/* Pasar una palabra al reves de forma recursiva. Ej: el "hola" pasarlo como "aloh" */

# include <stdio.h>

void invertir(int c)
{
    if (c == '.') // el "\n" es para que termine la linea cuando el usuario apreta ENTER, antes lo haciamos con el '.'
    {
        return; // este este caso particular el return va a ejecturar lo que le sigue fuera del if, que es el "putchar(c)"
    }
    else
    {
        c = getchar(); // y este va a ir recorriendo la oracion 
        invertir(c); // este sirve para ir apilando las letras, cuando termina se va a encontrar con el "return" del "if" de arriba
        
    }
    putchar(c); // para que me muestre cada una de las letras que voy cambiando tiene que estar en esta posicion
                // desapila y muestra las letras en el orden que se habian apilado en el "invertir(c)"
}



int main()
{
    int c;
    printf("\nIngrese una palabra: ");
    c = getchar();
    invertir(c);
    putchar(c);
    
    return 0;
}


/* Ahora reescribimos lo que esta ya aclarado todo en la carpeta, pero es sobre el funcionamiento de los PUNTEROS*/

#include <stdio.h>

int main(void)
{
    int a = 30, b = 50;
    int *p; 
    p = &a;
    *p = 100;
    p = &b;
    *p = 200;
    printf("%d %d", a, b);
    
    return 0;
}


/* Esto explica para que sirven los punteros*/

#include <stdio.h>
 
void invertir(int *a, int *b) // los "*" son para que el "&" sepa que me refiero a estos valores y su direccion de memoria.
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
 

int main(void)
{
    int a = 30, b = 50;
    invertir (&a, &b); // los "&" son para llamar a las variables de la funcion "void invertir" de arriba, sino no las reconoce.
    printf("%d %d", a, b);
    return 0;
    
}


/* Aca recorremos un arreglo desde un puntero*/

#include <stdio.h>

int main(void)
{
    int vec[5] = {0}, i; // el "{0}" es que al arreglo, en este caso de 5 posiciones, lo inicializo en 0
    int *p = NULL; // para decirle a C que el puntero no acumule basura le asigno la constante del lenguaje "NULL", que significa que 
                   // el puntero tiene valor 0, ejemolo: a = 0 (es lo mismo)
    p = &vec[0];
    *(p + 0) = 100;
    for (i = 0; i < 5; i++)
    {
        printf("%d", *(p + i));
    }
    
    return 0;
}


/* Aca pongo otro ejemplo pero mas elaborado*/

#include <stdio.h>

int main(void)
{
    int vec[5] = {0}, i; // el "{0}" es que al arreglo, en este caso de 5 posiciones, lo inicializo en 0
                         // si queremos imprimir un numero mas grande de lo que nos permite "vec" no se va a mostrar
    int *p = NULL; // para decirle a C que el puntero no acumule basura le asigno la constante del lenguaje "NULL", que significa que 
                   // el puntero tiene valor 0, ejemolo: a = 0 (es lo mismo)
    p = &vec[0];
    *(p + 0) = 100; // el "0" vendria a representar la posicion en el arreglo en la que se quiere meter en numero "100"
    for (i = 0; i < 5; i++)
    {
        printf("%d", *(p + i));
    }
    
    return 0;
}


//para anotar lo de la clase

#include <stdio.h>

void intercambio(int *a, int *b) //le pongo void porque no puedo devolver solo un valor, 
                               //tengo que hacerlo con los dos, y pongo void para que no vuelva ninguno 
{
    int aux;
    aux = *a; //con el * nos referimos al contenido donde se alojo esa variable 
    *a = *b;
    *b = aux;

    return; 
}


int main()
{
    int a, b;
    printf("\nIngrese dos valores: ");
    scanf("%d", &a); //con el & hablamos de la direccion de memoria de una variable
    scanf("%d", &b);
    printf("\nLa posicion de memoria de la variable es: %p", &a); //para mostrar la posicion de memoria se pone el "&"
                                        //el "%p" sirve para mostrar el "&a" osea la direccion donde se guardo esa memoria
    intercambio(&a, &b); //en lugar de mandar los valores tal cual, mando la direccion de memoria donde se alojaron "a" y "b"S
    printf("\nLos valores cambiados son: %d %d", a, b);

    return 0;
}



/*************************************************************************************************************************************************************/

//Repaso de listas simplemente enlazadas

#include <stdio.h>
#include <stdlib.h> 


typedef struct numeros
{
    int num;
    struct numeros *sig;
}nodon;


void cargar(nodon *h)
{
    printf("\nIngrese el numero: ");
    scanf("%d", &h->num);
    
    if(h->num == 0)
    {
        h->sig = NULL;
    }
    
    else
    {
        h->sig = (nodon *)malloc(sizeof(nodon));
        cargar(h->sig);
    }
}


void recorrer(nodon *h, int *cont)
{
    while(h->sig != NULL)
    {
        if(h->num % 3 == 0)
        {
            *cont = *cont+1;
        }
        
        h = h->sig;
    }
}


mostrar(nodon *h)
{
    if(h->sig != NULL)
    {
        printf("\nEl numero es: ");
        mostrar(h->sig);
    }
}


int main()
{
    int cont = 0;
    nodon *p = NULL;
    p = (nodon *)malloc(sizeof(nodon));
    cargar(p);
    mostrar(p);
    recorrer(p, &cont); //le pongo "&" al cont porque como es una funcion void voy a usarlo como puntero, dentro de la funcion
    printf("\nLa cantidad de multiplos de 3 es:  %d", cont);

    return 0;
}



//INSERTAR POR CABEZA Y EN CUALQUIER LUGAR DE LA LISTA 

#include <stdio.h>
#include <stdlib.h> 


typedef struct numeros
{
    int num;
    struct numeros *sig;
}nodon;


void cargar(nodon *h)
{
    printf("\nIngrese el numero: ");
    scanf("%d", &h->num);
    
    if(h->num == 0)
    {
        h->sig = NULL;
    }
    
    else
    {
        h->sig = (nodon *)malloc(sizeof(nodon));
        cargar(h->sig);
    }
}


void recorrer(nodon *h, int *cont)
{
    while(h->sig != NULL)
    {
        if(h->num % 3 == 0)
        {
            *cont = *cont+1;
        }
        
        h = h->sig;
    }
}


mostrar(nodon *h)
{
    if(h->sig != NULL)
    {
        printf("\nEl numero es: ", h->num);
        mostrar(h->sig);
    }
}


nodon *insertar_por_cabeza(nodon *h) //asi se hace si se quiere insertar por cabeza
{
    nodon *aux;
    
    if(h->num % 2 == 0)
    {
        aux = (nodon *)malloc(sizeof(nodon));
        aux -> num = (h->num / 2);
        aux->sig = h;
        h = aux; //**
    }
    
    return aux; //tambien puedo retornar "k" porque los dos quedaron apuntando al mismo nodo (como se ve en donde está el "**")
}


void insertar_despues_de_cada_nodo(nodon *h) //asi se hace si se quiere insertar en cualquier otro lugar de la lista menos en la cabeza
{
    nodon *aux = NULL; //es una buena practica, si no lo hago no pasa nada pero es para que se entienda donde está
    while(h->sig != NULL)
    {
        aux = (nodon *)malloc(sizeof(nodon));
        aux->num = h->num + 1; //si tengo un 12 el nuevo nodo que ingrese va a ser un 13
        aux->sig = h->sig;
        h->sig = aux; 
        h = h->sig->sig;
    }
}




int main()
{
    int cont = 0;
    nodon *p = NULL;
    p = (nodon *)malloc(sizeof(nodon));
    cargar(p);
    mostrar(p);
    recorrer(p, &cont); //le pongo "&" al cont porque como es una funcion void voy a usarlo como puntero, dentro de la funcion
    printf("\nLa cantidad de multiplos de 3 es:  %d", cont);
    p = insertar_por_cabeza(p);
    insertar_despues_de_cada_nodo(p); //como es una funcion void no le pongo el "p" porque no devuelve nada
    printf("\nLa lista con insercion por cabeza de lista es: ");
    mostrar(p);

    return 0;
}

//está medio sus


//ELIMINAR POR CABEZA Y EN CUALQUIER LUGAR DE LA LISTA 

#include <stdio.h>
#include <stdlib.h> 


typedef struct numeros
{
    int num;
    struct numeros *sig;
}nodon;


void cargar(nodon *h)
{
    printf("\nIngrese el numero: ");
    scanf("%d", &h->num);
    
    if(h->num == 0)
    {
        h->sig = NULL;
    }
    
    else
    {
        h->sig = (nodon *)malloc(sizeof(nodon));
        cargar(h->sig);
    }
}


void recorrer(nodon *h, int *cont)
{
    while(h->sig != NULL)
    {
        if(h->num % 3 == 0)
        {
            *cont = *cont+1;
        }
        
        h = h->sig;
    }
}


mostrar(nodon *h)
{
    if(h->sig != NULL)
    {
        printf("\nEl numero es: ", h->num);
        mostrar(h->sig);
    }
}


nodon *insertar_por_cabeza(nodon *h) //asi se hace si se quiere insertar por cabeza
{
    nodon *aux;
    
    if(h->num % 2 == 0)
    {
        aux = (nodon *)malloc(sizeof(nodon));
        aux -> num = (h->num / 2);
        aux->sig = h;
        h = aux; //**
    }
    
    return aux; //tambien puedo retornar "k" porque los dos quedaron apuntando al mismo nodo (como se ve en donde está el "**")
}


void insertar_despues_de_cada_nodo(nodon *k) //asi se hace si se quiere insertar en cualquier otro lugar de la lista menos en la cabeza
{
    nodon *aux = NULL; //es una buena practica, si no lo hago no pasa nada pero es para que se entienda donde está
    while(h->sig != NULL)
    {
        aux = (nodon *)malloc(sizeof(nodon));
        aux->num = h->num + 1; //si tengo un 12 el nuevo nodo que ingrese va a ser un 13
        aux->sig = h->sig;
        h->sig = aux; 
        h = h->sig->sig;
    }
}




int main()
{
    int cont = 0;
    nodon *p = NULL;
    p = (nodon *)malloc(sizeof(nodon));
    cargar(p);
    mostrar(p);
    recorrer(p, &cont); //le pongo "&" al cont porque como es una funcion void voy a usarlo como puntero, dentro de la funcion
    printf("\nLa cantidad de multiplos de 3 es:  %d", cont);
    p = insertar_por_cabeza(p);
    insertar_despues_de_cada_nodo(p); //como es una funcion void no le pongo el "p" porque no devuelve nada
    printf("\nLa lista con insercion por cabeza de lista es: ");
    mostrar(p);

    return 0;
}

//está medio sus




//PRACTICA PARA EL PARCIAL
/*
-Crear y mostrar una lista con numeros enteros. Termina con num=-2.
-Insertar en otra lista los numeros impares. Mostrarla.
-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int num;
	struct lista *sig;
}nodo;


void crear(nodo *p)
{
    printf("\nIngrese numeros enteros: ");
    scanf("%d", &p->num);

   	if (p->num==-2)
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


void mostrar(nodo *p)
{
    if (p->sig !=NULL)
	{
        	printf ("%d\n", p->num);
        	mostrar (p->sig);
	}

	return;
}

//-Insertar en otra lista los numeros impares. Mostrarla.
void impares(nodo *p, nodo *q)
{
    while(p->sig !=NULL)
    {
        if(p->num % 3 == 0 && p->num % 2 != 0)
        {
            q->num = p->num;
            q->sig = (nodo *)malloc(sizeof(nodo));
            q = q->sig;
        }
        
        p = p->sig;
    }
    
    q->sig = NULL;
}


//-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
float promedio(nodo *p)
{
    float prom = 0, suma = 0, cont = 0;

    while(p->sig != NULL)
    {
        suma += p->num; 
        cont++;
        p = p->sig;
    }
    
    prom = suma/cont;

    return prom;
}




/*nodo* insertar1(nodo *p)
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
    	while(p->sig!=NULL)
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
}*/

//-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
nodo* eliminar1(nodo* p, float prom)
{
	nodo *aux;
    while(p->num % 3 == 0 && p->num % 2 != 0 && p->num < prom)//condicion de eliminacion
    {
    	aux=p->sig;
    	free(p);
    	p=aux;
	}

    return p;
}

//-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
void eliminar2(nodo* p, float prom)
{
	nodo *aux;
	while(p->sig!=NULL&& p->sig->sig!=NULL)
	{
    	if(p->num % 3 == 0 && p->num % 2 != 0 && p->num < prom)//condicion de eliminacion
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
    float prom = 0, suma = 0;
    nodo *p=NULL;
    nodo *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("\nTodos los nuemeros son: \n");
    mostrar(p);
    impares(p, q);
    printf("\nLos impares de la lista son: \n");
    mostrar(q);
    prom = promedio(p);
    /*p = insertar1(p);
    insertar2(p);*/
    p = eliminar1(p, prom);
    eliminar2(p, prom);
    printf("\nla lista con los impares eliminados es: \n");
    mostrar(p);

    return 0;
}

//5 7 14 6 2 9 3 21 3 6 2 4 8



/*
Se tiene información de las olimpiadas 2016, con ella crear y mostrar una lista simplemente enlazada con el código del país, 
la cantidad de medallas de oro, la cantidad de plata y la cantidad de medallas de bronce de ese país. Se pide:

-Generar una nueva lista con el código del país y la totalidad de medallas ganadas. 
-Insertar al final de la lista generada la totalidad de medallas con el código de país igual a 00
-Eliminar aquellos países que no ganaron medalla de oro.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int cod_pais;
	int oro;
	int plata;
	int bronce;
	struct lista *sig;
}nodo;


typedef struct lista2
{
    int cod_pais2;
    int medallas;
    struct lista2 *sig;
}nodo2;


void crear (nodo *p)
{
    printf("\nIngrese el codigo de pais: ");
    scanf("%d", &p->cod_pais);

   	if (p->cod_pais==0)
	{
        p->sig=NULL;
	}

    else
	{
        printf("\nIngrese las medallas de oro: ");
        scanf("%d", &p->oro); 
        printf("\nIngrese las medallas de plata: ");
        scanf("%d", &p->plata); 
        printf("\nIngrese las medallas de bronce: ");
        scanf("%d", &p->bronce); 
        
    	p->sig=(nodo*)malloc(sizeof(nodo));
    	crear(p->sig);
	}

	return;
}


void mostrar (nodo *p)
{
    if (p->sig !=NULL)
	{
        printf ("\nEl codigo de pais es: %d", p->cod_pais);
        printf ("\nLas medallas de oro son: %d", p->oro);
        printf ("\nLas medallas de plata son: %d", p->plata);
        printf ("\nLas medallas de bronce son: %d", p->bronce);
        
        mostrar (p->sig);
	}

	return;
}


//-Generar una nueva lista con el código del país y la totalidad de medallas ganadas. 
void generar(nodo *p, nodo2 *q)
{
    while(p->sig != NULL)
    {
        q->cod_pais2 = p->cod_pais;
        q->medallas = p->oro + p->plata + p->bronce;
        q->sig = (nodo2*)malloc(sizeof(nodo2));
        q = q->sig;
        p = p->sig;
    }
    
    q->sig = NULL;
}


void mostrar2(nodo2 *q)
{
    if(q->sig != NULL)
    {
        printf("\nEl codigo de pais es: %d", q->cod_pais2);
        printf("\nLa suma de las medallas del pais: %d", q->medallas);
        
        mostrar2(q->sig);
    }
}


int total_medallas(nodo2 *q)
{
    int acum = 0;
    while(q->sig != NULL)
    {
        acum += q->medallas;
        q = q->sig;
    }
    
    return acum;
}

/* //no pedia insertar por cabeza.
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
}*/

//-Insertar al final de la lista generada la totalidad de medallas con el código de país igual a 00
void insertar2(nodo2 *q, int total)
{
  	nodo2 *aux;
	while(q->sig != NULL)
	{
    	q=q->sig;
	}
	
	aux=(nodo2 *)malloc(sizeof(nodo2));
    aux->cod_pais2 = 00; //valor a insertar
    aux->total = total;
    aux->sig=q->sig;
    q->sig=aux;
}


nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while(p->oro == 0)//condicion de eliminacion
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
	while(p->sig!=NULL && p->sig->sig!=NULL)
	{
    	if(p->sig->oro == 0)//p->sig->oro porque sino estaria borrando en el que estoy parado, por eso pregunto por el proximo
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
    int total;
    int acum = 0;
    nodo *p=NULL;
    nodo2 *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    mostrar(p);
    printf("\n----------------------------");
    generar(p, q);
    printf("\n----------------------------");
    printf("\nla nueva lista es: ");
    mostrar2(q);
    printf("\nEL total de todas las medallas de los paises es: %d", total_medallas(q));
    total = total_medallas(q);
    insertar2(q, total);
    p = eliminar1(p);
    eliminar2(p);
    mostrar(p);

    return 0;
}




/*
a) Crear y mostrar la lista. Termina con num=1000.
b) Generar otra lista con aquellos números múltiplos de 3. Mostrarla
c) Si la suma de nodos consecutivos de la lista original es mayor a 20 agregar adelante del primer nodo (que se suma) un nodo con num=0.
d) Si la suma de nodos consecutivos es menor a 10 eliminar el segundo nodo que se suma. Mostrar la lista.
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
    printf("\nIngrese numeros: ");
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
    	printf ("\n%d", p->num);
    	printf("\n");
    	mostrar (p->sig);
	}

	return;
}

//Generar otra lista con aquellos números múltiplos de 3. Mostrarla
void generar(nodo *p, nodo *q)
{
    while(p->sig != NULL)
    {
        if(p->num % 3 == 0)
        {
            q->num = p->num;
            q->sig = (nodo *)malloc(sizeof(nodo));
            q = q->sig;
            p = p->sig; 
        }
        
        else
        {
            p = p->sig; 
        }
    }
    
    q->sig = NULL;
}

//Si la suma de nodos consecutivos de la lista original es mayor a 20 agregar adelante del primer nodo (que se suma) un nodo con num=0.
int suma_numeros(nodo *p)
{
    int suma = 0;
    while(p->sig != NULL)
    {
        suma = p->num + p->sig->num;
        p = p->sig;
    }
    
    return suma;
}

/*
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
	while(p->sig!=NULL)
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
	while(p->sig!=NULL&& p->sig->sig!=NULL)
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
*/

int main()
{
    int suma;
    nodo *p=NULL;
    nodo *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);
    generar(p, q);
    printf("\n----------------------------------------------------------");
    printf("\nLa nueva lista es: ");
    mostrar(q);
    printf("\nLa suma es: %d", suma_numeros(p));
    suma = suma_numeros(p);
    /*p = insertar1(p);
    insertar2(p);
    p = eliminar1(p);
    eliminar2(p);*/
    mostrar(p);

    return 0;
}





/*
Se ingresan los siguientes datos de los empleados de una empresa: Nro de legajo, nombre y apellido, años de antiguedad en la empresa y sueldo. 
Generar una lista simplemente enlazada con estos datos. La carga termina con el nro de legajo igual a cero. Mostrar la lista.

a) Generar una nueva lista con aquellos empleados que tienen mas de 10 años en la empresa e incrementar el sueldo en un 15%. Mostrar la lista.
b) Generar una nueva lista con los sueldos de cada empleado y al final insertar el monto total que la empresa debe pagar en sueldos.
c) Eliminar de la lista original a aquellos empleados que tienen menos de 4 años de antigüedad generando con ellos una lista nueva.
d) Insertar antes de cada nodo de aquellos empleados que tienen más de 30 años de antiguedad en la lista  original un nodo incrementando el 30% de sueldo.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista
{
	int legajo;
	char nom_ape[30];
	int anio;
	int sueldo;
	struct lista *sig;
}nodo;


typedef struct lista2
{
    int legajo2;
    int sueldos2;
    struct lista2 *sig;
}nodo2;


void crear (nodo *p)
{
    
    printf("\nIngrese el legajo: ");
    scanf("%d", &p->legajo);

   	if (p->legajo==0)
	{
        p->sig=NULL;
	}

    else
	{
	    printf("\nIngrese el nombre y el apellido: ");
        scanf("%s", p->nom_ape);
        printf("\nIngrese los años de antiguedad: ");
        scanf("%d", &p->anio);
        printf("\nIngrese el sueldo: ");
        scanf("%d", &p->sueldo);
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear(p->sig);

	}

	return;
}

void mostrar(nodo *p)
{
    if(p->sig !=NULL)
	{
        printf ("\nEl legajo es: %d", p->legajo);
        printf ("\nEl nombre y el apellido es: %s", p->nom_ape);
        printf ("\nLos años de antiguedad son: %d", p->anio);
        printf ("\nEL sueldo es: %d", p->sueldo);
        mostrar (p->sig);
	}

	return;
}

//Generar una nueva lista con aquellos empleados que tienen mas de 10 años en la empresa e incrementar el sueldo en un 15%. Mostrar la lista.
void generar(nodo *p, nodo *q)
{
    while(p->sig != NULL)
    {
        if(p->anio > 10)
        {
            q->sig = (nodo*)malloc(sizeof(nodo));
            q->legajo = p->legajo;
            strcpy(q->nom_ape, p->nom_ape);
            q->anio = p->anio;
            q->sueldo = p->sueldo *1.15;
            p = p->sig;
            q = q->sig;
        }
        
        else
        {
            p = p->sig;
        }
    }
    
    q->sig = NULL;
}

//Generar una nueva lista con los sueldos de cada empleado y al final insertar el monto total que la empresa debe pagar en sueldos.
void generar2(nodo *p, nodo2 *r)
{
    while(p->sig != NULL)
    {
        r->sig = (nodo2*)malloc(sizeof(nodo2));
        r->legajo2 = p->legajo;
        r->sueldos2 = p->sueldo;
        p = p->sig;
        r = r->sig;
    }
    
    r->sig = NULL;
}


void mostrar2(nodo2 *r)
{
    if(r->sig != NULL)
    {
        printf("\nEl legajo es: %d", r->legajo2);
        printf("\nEl sueldo es: %d", r->sueldos2);
        mostrar2(r->sig);
    }
}

//Eliminar de la lista original a aquellos empleados que tienen menos de 4 años de antigüedad generando con ellos una lista nueva.
void generar3(nodo *p, nodo *s)
{
    while(p->sig != NULL)
    {
        if(p->anio < 4)
        {
            s->sig = (nodo*)malloc(sizeof(nodo));
            s->legajo = p->legajo;
            strcpy(s->nom_ape, p->nom_ape);
            s->anio = p->anio;
            s->sueldo = p->sueldo;
            p = p->sig;
            s = s->sig;
        }
    }
    
    s->sig = NULL;
}

// Al final insertar el monto total que la empresa debe pagar en sueldos.
int total_sueldos(nodo2 *r)
{
    int acum = 0;
    while(r->sig != NULL)
    {
        acum += r->sueldos2;
        r = r->sig;
    }
    
    return acum;
}

//Al final insertar el monto total que la empresa debe pagar en sueldos.
void insertar2(nodo2 *r, int total)
{
  	nodo2 *aux = NULL;
	while(r->sig != NULL && r->sig->sig != NULL)
	{
    	r = r->sig;
	}

    aux = (nodo2 *)malloc(sizeof(nodo2));
	aux->sueldos2 = total;
	aux->sig = r->sig;
	r->sig = aux;
}

//Insertar antes de cada nodo de aquellos empleados que tienen más de 30 años de antiguedad en la lista  original un nodo incrementando el 30% de sueldo.
nodo* insertar1(nodo *p)
{
	nodo *aux = NULL;
	if(p->anio > 30)
	{
    	aux=(nodo *)malloc(sizeof(nodo));
    	aux->legajo = p->legajo;
    	strcpy(aux->nom_ape, p->nom_ape);
    	aux->anio = p->anio;
    	aux->sueldo = p->sueldo *1.30;
    	aux->sig = p;
    	p = aux;
	}

	return p;
}

//Insertar antes de cada nodo de aquellos empleados que tienen más de 30 años de antiguedad en la lista  original un nodo incrementando el 30% de sueldo.
void insertar3(nodo *p)
{
  	nodo *aux = NULL;
	while(p->sig != NULL && p->sig->sig != NULL)
	{
    	if(p->sig->anio > 30) 
    	{
        	aux=(nodo *)malloc(sizeof(nodo));
        	aux->legajo = p->sig->legajo;
        	strcpy(aux->nom_ape, p->sig->nom_ape);
        	aux->anio = p->sig->anio;
        	aux->sueldo = p->sig->sueldo *1.30;
        	aux->sig = p;
        	p = aux;
        	p = p->sig;
    	}

    	p=p->sig;
	}
}


nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while(p->anio < 4)
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
	while(p->sig!=NULL && p->sig->sig!=NULL)
	{
    	if(p->sig->anio < 4)
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
    int total;
    nodo *p=NULL;
    nodo *q=NULL;
    nodo *s=NULL;
    nodo2 *r=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    s = (nodo*)malloc(sizeof(nodo));
    r = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    mostrar(p);
    generar(p, q);
    printf("\nLa nueva lista es: ");
    mostrar(q);
    printf("\n-------------------------------------");
    generar2(p, r);
    printf("\nLa lista solo con los sueldos de cada empleado es: ");
    mostrar2(r);
    printf("\n-------------------------------------");
    total = total_sueldos(r);
    generar3(p, s);
    printf("\nLa lista con los empleado con menos de 4 años de antiguedad es: ");
    mostrar(s);
    printf("\n-------------------------------------");
    printf("\nLa lista con insercion es: ");
    insertar2(r, total);
    mostrar2(r);
    printf("\n-------------------------------------");
    printf("\nLa lista con eliminacion es: ");
    p = eliminar1(p);
    eliminar2(p);
    printf("\n-------------------------------------");
    printf("\nLa lista con los empleados que tienen mas de 30 años de antiguedad es: ");
    insertar3(p);
    p = insertar1(p);
    printf("\nLa lista queda: ");
    mostrar(p);

    return 0;
}

//le falta un poco pero está planteado 



/*
Crear una lista con tres numeros enteros que termina con el primer valor en 0. Mostrarla.
Generar otra lista con la suma de los tres numeros del nodo si la suma de los mismos supera a 10.
Insertar antes de cada nodo otro nodo con la mitad de cada valor del nodo.
Eliminar aquellos nodos cuya productoria es menor a 30.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int num1;
	int num2;
	int num3;
	struct lista *sig;
}nodo;


typedef struct lista2
{
    int suma;
    struct lista2 *sig;
}nodo2;


void crear (nodo *p)
{
    printf("\nIngrese el numero: ");
    scanf("%d", &p->num1);

   	if (p->num1==0)
	{
        p->sig=NULL;
	}

    else
	{
	    printf("\nIngrese el numero: ");
        scanf("%d", &p->num2);
        printf("\nIngrese el numero: ");
        scanf("%d", &p->num3);
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear(p->sig);

	}

	return;
}

void mostrar(nodo *p)
{
    if(p->sig !=NULL)
	{
        printf ("\nEl primer numero es: %d", p->num1);
        printf ("\nEl segundo numero es: %d", p->num2);
        printf ("\nEl tercer numero es: %d", p->num3);
        mostrar(p->sig);
	}

	return;
}

//Generar otra lista con la suma de los tres numeros del nodo si la suma de los mismos supera a 10.
void generar(nodo *p, nodo2 *q)
{
    while(p->sig != NULL)
    {
        if((p->num1 + p->num2 + p->num3) > 10)
        {
            q->sig = (nodo2*)malloc(sizeof(nodo2));
            q->suma = (p->num1 + p->num2 + p->num3);
            q = q->sig;
            p = p->sig;
        }
        
        else 
        {
            p = p->sig;
        }
    }
    
    q->sig = NULL;
}


void mostrar2(nodo2 *q)
{
    if(q->sig != NULL)
    {
        printf("\nLa suma es: %d", q->suma);
        mostrar2(q->sig);
    }
}

//Insertar antes de cada nodo otro nodo con la mitad de cada valor del nodo.
nodo* insertar1(nodo *p)
{
	nodo *aux = NULL;
	aux=(nodo *)malloc(sizeof(nodo));
	aux->num1 = p->num1/2;
    aux->num2 = p->num2/2;
    aux->num3 = p->num3/2;
	aux->sig=p;
	p=aux;

	return p;
}


void insertar2 (nodo *p)
{
  	nodo *aux = NULL;
	while(p->sig != NULL && p->sig->sig != NULL)
	{
    	aux=(nodo *)malloc(sizeof(nodo));
    	aux->num1 = p->sig->num1/2;
    	aux->num2 = p->sig->num2/2;
    	aux->num3 = p->sig->num3/2;
    	aux->sig=p->sig;
    	p->sig=aux;

    	p=p->sig->sig;
	}
}


nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while((p->num1* p->num2 * p->num3) < 30)
	{
    	aux=p->sig;
    	free(p);
    	p=aux;

	}

	return p;
}

//Eliminar aquellos nodos cuya productoria es menor a 30.
void eliminar2(nodo* p)
{
	nodo *aux;
	while(p->sig!=NULL && p->sig->sig!=NULL)
	{
    	if((p->sig->num1* p->sig->num2 * p->sig->num3) < 30)
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
    nodo2 *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    printf("\nLa lista es: ");
    mostrar(p);
    printf("\n-------------------------------");
    generar(p, q);
    printf("\nLa nueva lista es: ");
    mostrar2(q);
    printf("\n-------------------------------");
    printf("\nLa lista con las inserciones es: ");
    insertar2(p);
    p = insertar1(p);
    mostrar(p);
    printf("\n-------------------------------");
    printf("\nLa lista con las eliminaciones es: ");
    p = eliminar1(p);
    eliminar2(p);
    mostrar(p);
    printf("\n-------------------------------");
    

    return 0;
}





/*
La cadena de hoteles Hilton tiene establecimientos en todo el mundo. Para conocer las ganancias, se ingresa código de país, numero 
de establecimiento y su recaudación mensual (en millones de dólares) en una lista simplemente enlazada.

El ingreso de datos termina con el código de país igual a cero.
Se deben ingresar los datos ordenados por país y establecimiento.

-Mostrar la lista.
-Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.
-Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
-Ingresar un nuevo hotel con el código de país y la recaudación mensual e Insertarlas en orden en la lista.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int cod_pais;
	int establecimiento;
	int recaudacion;
	struct lista *sig;
}nodo;


void crear(nodo *p)
{
    printf("\nIngrese el codigo del pais: ");
    scanf("%d", &p->cod_pais);

   	if (p->cod_pais==0)
	{
        p->sig=NULL;
	}

    else
	{
	    printf("\nIngrese el numero del establecimiento: ");
	    scanf("%d", &p->establecimiento);
	    printf("\nIngrese la recaudacion del hotel: ");
	    scanf("%d", &p->recaudacion);
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear(p->sig);

	}

	return;
}

void mostrar (nodo *p)
{
    if(p->sig !=NULL)
	{
        printf ("\nEl codigo del hotel es: %d", p->cod_pais);
        printf ("\nEL numero del establecimiento es: %d", p->establecimiento);
        printf ("\nLa recaudacion del hotel es: %d", p->recaudacion);
        mostrar (p->sig);
	}

	return;
}


int suma_total(nodo *p)
{
    int acum = 0;
    while(p->sig != NULL)
    {
        acum += p->recaudacion;
        p = p->sig;
    }
    
    return acum;
}


float prom_total(nodo *p)
{
    int acum = 0, cont = 0; 
    float prom;
    
    while(p->sig != NULL)
    {
        acum += p->recaudacion;
        cont += 1;
        p = p->sig;
    }
    
    prom = acum/cont;
    
    return prom;
}

//Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.
void insertar2 (nodo *p, int suma)
{
  	nodo *aux = NULL;
	while(p->sig->sig!=NULL)
	{
    	p = p->sig; 
	}
	
	aux=(nodo *)malloc(sizeof(nodo));
	aux->cod_pais = 100;
	aux->establecimiento = 0;
	aux->recaudacion = suma;
	aux->sig=p->sig;
	p->sig=aux;
	p=p->sig;
}

//Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
nodo* eliminar1(nodo* p, float prom)
{
	nodo *aux = NULL;
	while(p->recaudacion < prom)
	{
    	aux=p->sig;
    	free(p);
    	p=aux;
	}

	return p;
}

//Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
void eliminar2(nodo* p, float prom)
{
	nodo *aux = NULL;
	while(p->sig!=NULL&& p->sig->sig!=NULL)
	{
    	if(p->sig->recaudacion < prom)//condicion de eliminacion
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
    int suma;
    float prom;
    nodo *p=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("\nLa lista original es: ");
    mostrar(p);
    suma = suma_total(p);
    prom = prom_total(p);
    printf("\n-------------------------------");
    printf("\nLa lista con insercion es: ");
    insertar2(p, suma);
    mostrar(p);
    printf("\n-------------------------------");
    printf("\nLa lista con eliminacion es: ");
    p = eliminar1(p, prom);
    eliminar2(p, prom);
    mostrar(p);
    printf("\n-------------------------------");
    

    return 0;
}


/*
a) Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).
b) Generar una lista nueva con el promedio de ambos números.
c) Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.
d) Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int num1;
	int num2;
	struct lista *sig;
}nodo;

typedef struct lista2
{
    float prom;
    struct lista2 *sig;
}nodo2;


void crear (nodo *p)
{
    printf("\nIngrese el primer numero: ");
    scanf("%d", &p->num1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &p->num2);

    if(p->num1 == 0 && p->num2 == 0)
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

void mostrar(nodo *p)
{
    if (p->sig !=NULL)
	{
    	printf ("\nEL primer numero es: %d", p->num1);
    	printf ("\nEL segundo numero es: %d", p->num2);
    	mostrar (p->sig);
	}

	return;
}

//Generar una lista nueva con el promedio de ambos números.
void generar(nodo *p, nodo2 *q)
{
    while(p->sig != NULL)
    {
        q->sig = (nodo2*)malloc(sizeof(nodo2));
        q->prom = (p->num1 + p->num2)/2;
        q = q->sig;
        p = p->sig;
    }
    
    q->sig = NULL;
}


void mostrar2(nodo2 *q)
{
    if(q->sig != NULL)
    {
        printf("\nEl promedio es: %f", q->prom);
        mostrar2(q->sig);
    }
    
    return;
}

//Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.
void insertar2 (nodo *p)
{
  	nodo *aux;
	while(p->sig!=NULL)
	{
    	if((p->num1 + p->num2) > 15) 
    	{
        	aux = (nodo *)malloc(sizeof(nodo));
        	aux->num1 = p->num1/2;
        	aux->num2 = p->num2/2;
        	aux->sig = p->sig;
        	p->sig = aux;
    	}

    	p = p->sig;
	}
}

//Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while(p->num1 % p->num2 == 0)
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
	while(p->sig!=NULL&& p->sig->sig!=NULL)
	{
    	if(p->sig->num1 % p->sig->num2 == 0)
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
    nodo *p = NULL;
    nodo2 *q = NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    printf("\nLa lista original es: ");
    mostrar(p);
    printf("\n-----------------------\n");
    generar(p, q);
    printf("\nLa lista generada es: ");
    mostrar2(q);
    printf("\n-----------------------\n");
    insertar2(p);
    printf("\nLa lista con insercion es: ");
    mostrar(p);
    printf("\n-----------------------\n");
    p = eliminar1(p);
    eliminar2(p);
    printf("\nLa lista con eliminacion es: ");
    mostrar(p);
    printf("\n-----------------------\n");
    
    return 0;
}





/*
-Crear y mostrar una lista con numeros enteros. Termina con num=-2.
-Insertar en otra lista los numeros impares. Mostrarla.
-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
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
    printf("\nIngrese numeros: ");
    scanf("%d", &p->num);

   	if (p->num==-2)
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

//-Insertar en otra lista los numeros impares. Mostrarla.
void generar(nodo *p, nodo *q)
{
    while(p->sig != NULL)
    {
        if(p->num % 2 != 0)
        {
            q->num = p->num;
            q->sig = (nodo*)malloc(sizeof(nodo));
            q = q->sig;
        }
        
        p = p->sig;
    }
    
    q->sig = NULL;
}

//-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
float promedio(nodo *p)
{
    float prom = 0, suma = 0, cont = 0;
    
    while(p->sig != NULL)
    {
        suma += p->num;
        cont += 1;
        p = p->sig;
    }
    
    prom = suma/cont;
    
    return prom;
}


//-Eliminar todos los valores menores al promedio de la lista de numeros impares. Mostrarla. 
nodo* eliminar1(nodo* p, float promedio)
{
	nodo *aux;
	while(p->num % 2 != 0 && p->num < promedio)
	{
    	aux=p->sig;
    	free(p);
    	p=aux;

	}

	return p;
}


void eliminar2(nodo* p, float promedio)
{
	nodo *aux;
	while(p->sig!=NULL&& p->sig->sig!=NULL)
	{
    	if(p->sig->num % 2 != 0 && p->sig->num < promedio)
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
    float prom;
    nodo *p=NULL;
    nodo *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);
    generar(p, q);
    prom = promedio(p);
    printf("\nEl promedio es: %f", prom);
    printf("------------------------------\n");
    printf("\nLa lista normal es: \n");
    mostrar(p);
    p = eliminar1(p, prom);
    eliminar2(p, prom);
    printf("------------------------------\n");
    printf("\nLa lista con eliminacion es: \n");
    mostrar(p);
    printf("------------------------------\n");
    printf("\nLa lista con los impares es: \n");
    mostrar(q);

    return 0;
}

//IMPECABLE


/*
a) Crear y mostrar la lista. Termina con num=0.
b) Generar otra lista con aquellos números múltiplos de 3. Mostrarla
c) Si la suma de nodos consecutivos de la lista original es mayor a 20 agregar adelante del primer nodo (que se suma) un nodo con num=0.
d) Si la suma de nodos consecutivos es menor a 10 eliminar el segundo nodo que se suma. Mostrar la lista.
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
    printf("\nIngrese valores: ");
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


void generar(nodo *p, nodo *q)
{
    while(p->sig != NULL)
    {
        if(p->num % 3 == 0)
        {
            q->num = p->num;
            q->sig = (nodo*)malloc(sizeof(nodo));
            q = q->sig;
        }
        
        p = p->sig;
    }
    
    q->sig = NULL;
}


int suma(nodo *p)
{
    int acum = 0;
    
    while(p->sig != NULL)
    {
        acum += p->num;
        p = p->sig;
    }
    
    return acum;
}


nodo* insertar1(nodo *p, int suma)
{
	nodo *aux;
	if(suma < 20)
	{
    	aux = (nodo *)malloc(sizeof(nodo));
    	aux->num = 0;
    	aux->sig = p;
    	p = aux;
	}

	return p;
}

/*
void insertar2 (nodo *p)
{
  	nodo *aux;
	while(p->sig!=NULL)
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
	while(p->sig!=NULL&& p->sig->sig!=NULL)
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
*/

int main()
{
    int sum;
    nodo *p=NULL;
    nodo *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("\nLa lista original es: \n");
    mostrar(p);
    sum = suma(p);
    printf("\n--------------------------------------\n");
    printf("\nLa suma de todos los numeros es %d: ", sum);
    generar(p, q);
    printf("\n--------------------------------------\n");
    printf("\nLa lista generada con los multiplos de 3 es: \n");
    mostrar(q);
    
    p = insertar1(p, suma);
    /*insertar2(p);
    p = eliminar1(p);
    eliminar2(p);*/
    printf("\n--------------------------------------\n");
    printf("\nLa lista con insercion es: \n");
    mostrar(p);

    return 0;
}

//hay uno que no se hacer, pero el resto todo bien




#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int cod_pais;
	int oro;
	int plata;
	int bronce;
	struct lista *sig;
}nodo;


typedef struct lista2
{
    int cod_pais2;
    int medallas;
    int total;
    struct lista2 *sig;
}nodo2;


void crear (nodo *p)
{
    printf("\nIngrese el codigo de pais: ");
    scanf("%d", &p->cod_pais);

   	if (p->cod_pais==0)
	{
        p->sig=NULL;
	}

    else
	{
        printf("\nIngrese las medallas de oro: ");
        scanf("%d", &p->oro); 
        printf("\nIngrese las medallas de plata: ");
        scanf("%d", &p->plata); 
        printf("\nIngrese las medallas de bronce: ");
        scanf("%d", &p->bronce); 
        
    	p->sig=(nodo*)malloc(sizeof(nodo));
    	crear(p->sig);
	}

	return;
}


void mostrar (nodo *p)
{
    if (p->sig !=NULL)
	{
        printf ("\nEl codigo de pais es: %d", p->cod_pais);
        printf ("\nLas medallas de oro son: %d", p->oro);
        printf ("\nLas medallas de plata son: %d", p->plata);
        printf ("\nLas medallas de bronce son: %d", p->bronce);
        
        mostrar (p->sig);
	}

	return;
}


//-Generar una nueva lista con el código del país y la totalidad de medallas ganadas. 
void generar(nodo *p, nodo2 *q)
{
    while(p->sig != NULL)
    {
        q->cod_pais2 = p->cod_pais;
        q->medallas = p->oro + p->plata + p->bronce;
        q->sig = (nodo2*)malloc(sizeof(nodo2));
        q = q->sig;
        p = p->sig;
    }
    
    q->sig = NULL;
}


void mostrar2(nodo2 *q)
{
    if(q->sig != NULL)
    {
        printf("\nEl codigo de pais es: %d", q->cod_pais2);
        printf("\nLa suma de las medallas del pais: %d", q->medallas);
        
        mostrar2(q->sig);
    }
}


int total_medallas(nodo2 *q)
{
    int acum = 0;
    while(q->sig != NULL)
    {
        acum += q->medallas;
        q = q->sig;
    }
    
    return acum;
}

/* //no pedia insertar por cabeza.
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
}*/

//-Insertar al final de la lista generada la totalidad de medallas con el código de país igual a 00
void insertar2(nodo2 *q, int total)
{
  	nodo2 *aux;
	while(q->sig != NULL)
	{
    	q=q->sig;
	}
	
	aux=(nodo2 *)malloc(sizeof(nodo2));
    aux->cod_pais2 = 00; //valor a insertar
    aux->total = total;
    aux->sig=q->sig;
    q->sig=aux;
}


nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while(p->oro == 0)//condicion de eliminacion
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
	while(p->sig!=NULL && p->sig->sig!=NULL)
	{
    	if(p->sig->oro == 0)//p->sig->oro porque sino estaria borrando en el que estoy parado, por eso pregunto por el proximo
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
    int total;
    int acum = 0;
    nodo *p=NULL;
    nodo2 *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    mostrar(p);
    printf("\n----------------------------");
    generar(p, q);
    printf("\n----------------------------");
    printf("\nla nueva lista es: ");
    mostrar2(q);
    printf("\nEL total de todas las medallas de los paises es: %d", total_medallas(q));
    total = total_medallas(q);
    insertar2(q, total);
    p = eliminar1(p);
    eliminar2(p);
    mostrar(p);

    return 0;
}


//falta



/*
a) Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).
b) Generar una lista nueva con el promedio de ambos números.
c) Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.
d) Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int num1;
	int num2;
	struct lista *sig;
}nodo;

typedef struct lista2
{
    float prom;
    struct lista2 *sig;
}nodo2;

//Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).
void crear (nodo *p)
{
    printf("\nIngrese el primer numero: ");
    scanf("%d", &p->num1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &p->num2);

   	if(p->num1 == 0 && p->num2 == 0)
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


void mostrar(nodo *p)
{
    if(p->sig != NULL)
	{
        printf("\nEl primer numero es: %d", p->num1);
        printf("\nEl segundo numero es: %d", p->num2);
        mostrar (p->sig);
	}

	return;
}

//Generar una lista nueva con el promedio de ambos números.
void generar(nodo *p, nodo2 *q)
{
    while(p->sig != NULL)
    {
        q->sig = (nodo2*)malloc(sizeof(nodo2));
        q->prom = (p->num1 + p->num2)/2;
        q = q->sig;
        p = p->sig;
    }
    
    q->sig = NULL;
    
    return;
}

void mostrar2(nodo2 *q)
{
    if(q->sig != NULL)
    {
        printf("\nEL promedio es: %f", q->prom);
        mostrar2(q->sig);
    }
    
    return;
}

/*
//Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.
nodo* insertar1(nodo *p)
{
	nodo *aux;
	if((p->num1 + p->num2) > 15)
	{
    	aux=(nodo *)malloc(sizeof(nodo));
    	aux->num1 = p->num1/2;
    	aux->num2 = p->num2/2;
    	aux->sig=p;
    	p=aux;
	}

	return p;
}*/

//Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.
void insertar2 (nodo *p)
{
  	nodo *aux;
	while(p->sig != NULL)
	{
    	if((p->num1 + p->num2) > 15) 
    	{
        	aux=(nodo *)malloc(sizeof(nodo));
        	aux->num1 = p->num1/2;
        	aux->num2 = p->num2/2;
        	aux->sig = p->sig;
        	p->sig = aux;

    	}

    	p = p->sig;
	}
}

//Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while(p->num1 % p->num2 == 0)
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
	while(p->sig!=NULL&& p->sig->sig!=NULL)
	{
    	if(p->sig->num1 % p->sig->num2 == 0)
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
    nodo2 *q=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    printf("\nLa lista original es: ");
    mostrar(p);
    printf("\n-----------------------------\n");
    generar(p, q);
    printf("\nLa lista generada es: ");
    mostrar2(q);
    //p = insertar1(p);
    printf("\n-----------------------------\n");
    insertar2(p);
    printf("\nLa lista con insercion es: \n");
    mostrar(p);
    printf("\n-----------------------------\n");
    p = eliminar1(p);
    eliminar2(p);
    printf("\nLa lista con eliminacion es: ");
    mostrar(p);

    return 0;
}

//esta bien


/*
La cadena de hoteles Hilton tiene establecimientos en todo el mundo. Para conocer las ganancias, se ingresa código de país, numero 
de establecimiento y su recaudación mensual (en millones de dólares) en una lista simplemente enlazada.

El ingreso de datos termina con el código de país igual a cero.
Se deben ingresar los datos ordenados por país y establecimiento.

-Mostrar la lista.
-Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.
-Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
-Ingresar un nuevo hotel con el código de país y la recaudación mensual e Insertarlas en orden en la lista.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
	int cod_pais;
	int establecimiento;
	int recaudacion;
	struct lista *sig;
}nodo;


void crear (nodo *p)
{
    printf("\nIngrese el codigo del pais del hotel: ");
    scanf("%d", &p->cod_pais);

   	if (p->cod_pais==0)
	{
        	p->sig=NULL;
	}

	else
	{
	    printf("\nIngrese el establecimiento del hotel: ");
        scanf("%d", &p->establecimiento);
        printf("\nIngrese la recaudacion total del hotel: ");
        scanf("%d", &p->recaudacion);
    	p->sig=(nodo*)malloc(sizeof(nodo));
    	crear(p->sig);

	}

	return;
}

void mostrar (nodo *p)
{
    if (p->sig !=NULL)
	{
        printf("\nEl codigo de pais es: %d", p->cod_pais);
        printf("\nEl establecimiento donde se encuentra el hotel es: %d", p->establecimiento);
        printf("\nLa recaudacion del hotel fue: %d", p->recaudacion);
        mostrar(p->sig);
	}

	return;
}

int suma_recaudacion(nodo *p)
{
    int acum = 0;
    
    while(p->sig != NULL)
    {
        acum = acum + p->recaudacion;
        p = p->sig;
    }
    
    return acum;
}

float promedio(nodo *p)
{
    int acum = 0, cont = 0;
    float prom;
    
    while(p->sig != NULL)
    {
        acum += p->recaudacion;
        cont += 1;
        prom = acum/cont;
        
        p = p->sig;
    }
    
    //prom = acum/cont;
    
    return prom;
}

//-Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.
void insertar2 (nodo *p, int suma)
{
  	nodo *aux;
	while(p->sig->sig != NULL) //se pone asi porque acordate que el ultimo nodo es el que tiene el 0 y al lado el NULL, sino llega hasta el ultimo (antes 
	                           // del 0, y eso evita que se sumen)
	{
    	p = p->sig;
	}
	
	//lo pongo abajo del while para que camine todo lo que tenga que caminar hasta llegar al ultimo (con 0 y NULL) donde hace el enlace del aux
	
	aux=(nodo *)malloc(sizeof(nodo));
	aux->cod_pais = 100;
	aux->establecimiento = 0;
	aux->recaudacion = suma;
	aux->sig=p->sig;
	p->sig=aux;

    return;
}

//-Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
nodo* eliminar1(nodo* p, float prom)
{
	nodo *aux;
	while(p->recaudacion < prom)
	{
    	aux=p->sig;
    	free(p);
    	p=aux;

	}

	return p;
}

void eliminar2(nodo* p, float prom)
{
    	nodo *aux;
    	while(p->sig!=NULL&& p->sig->sig!=NULL)
    	{
        	if(p->sig->recaudacion < prom)
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
    int suma = 0;
    float prom; 
    nodo *p=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("\n\nLa lista principal es: \n");
    mostrar(p);
    printf("\n----------------------------\n");
    prom = promedio(p); //lo pongo aca arriba porque sino va a sumar al promedio el valor que inserte abajo (que es la suma de las recaudaciones)
    printf("\n----------------------------\n");
    suma = suma_recaudacion(p);
    //printf("\nsuma: %d", suma_recaudacion(p)); 
    insertar2(p, suma);
    printf("\nLa lista con insercion es: \n");
    mostrar(p);
    printf("\n----------------------------\n");
    p = eliminar1(p, prom);
    eliminar2(p, prom);
    printf("\nLa lista con eliminacion es: \n");
    mostrar(p);
    printf("\n----------------------------\n");

    return 0;
}

//IMPECABLE

/*
Una encuestadora necesita obtener algunas estadisticas sobre el Previaje. Para ello se le pide a cada persona los siguientes datos:

Nombre y apellido
Edad
Monto total a gastar en las vacaciones

-La carga de datos finaliza cuando el nombre y apellido de la persona es "X".

-El Previaje otorga a cada persona un credito del 50% sobre el monto total a gastar en las vacaciones con un tope máximo de $100,000. 


a) Cargar los datos en una lista simplemente enlazada. Mostrarla
b) Generar una lista simplemente enlazada con el nombre y apellido, edad y crédito por el previaje.
c) Generar una nueva lista con nombre y apellido y el porcentaje que representa el credito del previaje
   segun el monto a gastar en las vacaciones ingresado.
d) Insertar antes de cada nodo de la lista generada en el punto b) el nombre y apellido, edad y un 1 si tiene en el valor del crédito 
   $100000 y un 2 si tiene un crédito menor a $100000.
e) Eliminar de la lista original aquellas personas que tienen una edad entre 19 y 30 años y el monto a gastar en las vacaciones es mayor a $200000.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista
{
	char nombre[30]; //ACORDATE DE DEFINIR CUANTOS VALORES QUERES PARA EL CHAR QUE SINO NO TE CORRE
	int edad;
	int monto;
	struct lista *sig;
}nodo;


typedef struct lista2
{
    char nombre2[30];
    float porcentaje;
    struct lista2 *sig;
}nodo2;


void crear (nodo *p)
{
    printf("\nIngrese el nombre: ");
    scanf("%s", p->nombre);

   	if (strcmp(p->nombre, "x") == 0)
	{
        p->sig=NULL;
	}

    else
	{
	    printf("\nIngrese la edad: ");
	    scanf("%d", &p->edad);
	    printf("\nIngrese el monto: ");
	    scanf("%d", &p->monto);
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear(p->sig);
	}

	return;
}

//a) Cargar los datos en una lista simplemente enlazada. Mostrarla
void mostrar(nodo *p)
{
    if (p->sig !=NULL)
	{
        printf ("\nEl nombre es: %s", p->nombre);
        printf("\nLa edad es: %d", p->edad);
        printf("\nEl monto es: %d\n", p->monto);
        mostrar(p->sig);
	}

	return;
}

//b) Generar una lista simplemente enlazada con el nombre y apellido, edad y crédito por el previaje.
void generar(nodo *p, nodo *q)
{
    while(p->sig != NULL)
    {
        strcpy(q->nombre, p->nombre);
        q->edad = p->edad;
        
        if(p->monto > 100000)
        {
            q->monto = 100000;
        }
        
        if(p->monto <= 100000)
        {
            q->monto = p->monto / 2;
        }
        
        q->sig = (nodo*)malloc(sizeof(nodo));
        q = q->sig;
        p = p->sig;
    }
    
    q->sig = NULL;
}

void mostrar2(nodo2 *r)
{
    if(r->sig != NULL)
    {
        printf("\nEl porcentaje es: %f\n", r->porcentaje);
        mostrar2(r->sig);
    }
}

//c) Generar una nueva lista con nombre y apellido y el porcentaje que representa el credito del previaje
//   segun el monto a gastar en las vacaciones ingresado.
void generar2(nodo *q, nodo2 *r)
{
    while(q->sig != NULL)
    {
        strcpy(r->nombre2, q->nombre);
        
        if(q->monto > 100000)
        {
            r->porcentaje = ((100 * 100000)/q->monto);
        }
        
        if(q->monto < 100000)
        {
            r->porcentaje = 50;
        }
        
        r->sig = (nodo2*)malloc(sizeof(nodo2));
        r = r->sig;
        q = q->sig;
    }
    
    r->sig = NULL;
}


nodo* insertar1(nodo *q)
{
	nodo *aux;
    
    aux=(nodo *)malloc(sizeof(nodo));
    strcpy(aux->nombre, q->nombre);
    aux->edad = q->edad;
    
    if(q->monto == 10000)
    {
        aux->monto = 1;
    }
    
    if(q->monto < 100000)
    {
        aux->monto = 2;
    }
    
    aux->sig = q;
    q = aux;

	return q;
}

//d) Insertar antes de cada nodo de la lista generada en el punto b) el nombre y apellido, edad y un 1 si tiene en el valor del crédito 
//   $100000 y un 2 si tiene un crédito menor a $100000.
void insertar2 (nodo *q)
{
  	nodo *aux;
	while(q->sig->sig != NULL)
	{
        aux=(nodo *)malloc(sizeof(nodo));
        strcpy(aux->nombre, q->sig->nombre);
        aux->edad = q->sig->edad;
        
        if(q->sig->monto == 10000)
        {
            aux->monto = 1;
        }
        
        if(q->sig->monto < 100000)
        {
            aux->monto = 2;
        }

        aux->sig=q->sig;
        q->sig=aux;

    	q=q->sig;
	}
}

//e) Eliminar de la lista original aquellas personas que tienen una edad entre 19 y 30 años y el monto a gastar en las vacaciones es mayor a $200000.
nodo* eliminar1(nodo* p)
{
	nodo *aux;
	while((p->edad > 19 && p->edad < 30) && (p->monto > 200000))
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
	while(p->sig!=NULL && p->sig->sig!=NULL)
	{
    	if((p->sig->edad > 19 && p->sig->edad < 30) && (p->sig->monto > 200000))
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
    nodo *q=NULL;
    nodo2 *r=NULL;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    r = (nodo2*)malloc(sizeof(nodo2));
    crear(p);
    printf("\n\nLa lista original es: \n");
    mostrar(p);
    printf("\n-------------------------------\n");
    generar(p, q);
    printf("\n\nLa lista generada es: \n");
    mostrar(q); //la consigna dice mostrar la lista generada, por eso tengo que llamar a "q", aunque en la propia funcion "mostrar(nodo *p)"
                //no este definida
    printf("\n-------------------------------\n");
    generar2(q, r);
    printf("\nLa segunda lista generada es: \n");
    mostrar2(r);
    printf("\n-------------------------------\n");
    insertar2(q);
    q = insertar1(q);
    printf("\nLa lista con insercion es: \n");
    mostrar(q);
    printf("\n-------------------------------\n");
    p = eliminar1(p);
    eliminar2(p);
    printf("\nLa lista con eliminacion es: \n");
    mostrar(p);
    printf("\n-------------------------------\n");

    return 0;
}







