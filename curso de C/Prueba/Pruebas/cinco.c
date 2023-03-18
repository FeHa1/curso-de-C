/* VAMOS A VER EJERCICIOS DE RECURSIVIDAD*/

/* Esto es sin hacerlo recursivo, osea que es iterativa*/

#include <stdio.h>

int main()
{
    int a, b, c;
    
    printf("Ingrese 'a': ");
    scanf("%d", &a);
    printf("Ingrese 'b': ");
    scanf("%d", &b); 
    
    c = producto(a, b); 
    printf("%d", &c);
}

int producto(int a, int b)
{
    int i, acum = 0;
    for (i = 0; i < b; i++) // pongo 0 en la variable 'i' asi no tengo que poner '<=' como condicion 
    {
        acum = acum + a;
        
    }
    
    return acum; 
}


/* Este es el mismo que el de arriba solo que hecho Recursivo*/

#include <stdio.h>

int main()
{
    int a, b, c;
    
    printf("Ingrese 'a': ");
    scanf("%d", &a);
    printf("Ingrese 'b': ");
    scanf("%d", &b); 
    
    c = producto(a, b); 
    printf("%d", &c);
}

int producto(int a, int b) // el 'b' podriamos decir que va a jugar el papel de ser la cantidad de veces que 'a' se va a repetir
// por eso en los parametros de abajo se pone 'b-1'*
{
    
    if (b == 0 || a == 0) // se supone que si ambos son '0' directmente se trmina la funcion
    {
        return 0;
    }
    
    else
    {
        return producto(a, b-1) +a; // *aca se pone eso porque el numero de 'b' va a tener que ir haciendose mas chico asi en algun punto
        // la funcion se corta (porque llega a 0), y 'a' se va aumentando, no en valor, sino en cantidad de veces que es sumado 
        // si hay dudas de esto mira la carpeta.
    }

return 0;
}


/* Ingresar "n" y calcular en forma recursiva la suma de los primeros "n" numeros naturales*/
/* EJEMPLO:
n = 8       1+2+3+4+5+6+7+8
n = 4       1+2+3+4
n = 2       1+2
*/

#include <stdio.h>

int main()
{
    int n, a;
    printf("Ingrese un valor para 'n': ");
    scanf("%d", &n);
    a = suma(n);
    printf("%d", &a);
}

int suma(int n) // si 'n' fuese 3 lo que va a hacer el programa es restarle 1 para despues sumarlo por el nuemro original*
{
    if (n == 0)
    {
        return 0;
    }
    
    else
    {
        return suma(n-1) +n; // *practicamente lo que pasa aca es que se hace 3-1= 2, y al 2 se le suma 3, y asi hasta que 
        // el resultado sea 0 para que cierre el ciclo 
    }
}



/* Este es un ejercicio donde utilizamos la recursividad para encontrar el producto de los numeros*/ 
/* Por definicion es esto : 
El resultado de la multiplicación de varios números se llama producto. Los números que se multiplican se llaman factores o 
coeficientes, e individualmente: multiplicando (número a sumar o número que se está multiplicando) y multiplicador 
(veces que se suma el multiplicando)
*/

#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1; // aca se devuelve 1 y no 0 porque el factorial de 0 es 1 por regla de la teoria
    }
    else
    {
        return factorial(n-1)*n; // ahora como quiero sacar el factorial en lugar de sumarlo por el 'n' se multiplica
    }
}


int main(void)
{
    int n;
    printf("Ingrese el numero para calcular su factorial: ");
    scanf("%d", &n);
    printf("\nEl factorial es: %d ", factorial(n)); // esta (factorial(n)) es una manera de llamar a la funcion sin la 
    // necesidad de hacer otra variable (como en los ejemplos anteriores que llamabamos a las variables de afuera)
    
    return 0;
}


/* Aca vemos el problema de recursividad en un arreglo*/

# include <stdio.h>

void mostrar(int vec[], int n)
{
    int i; 
    for (i = 0; i < n; i++)
    {
        printf("\nEl %d valor es: %d", i, vec[i]);
    }
}

void cargar(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
    }
}

int suma(int vec[], int n)
{
    if (n < 0) // se hace esto porque tenemos la posicion 0 con valores, por ende no podemos poner 'n == 0' 
               // ya que no lo tomaria en cuenta
    {
        return 0;
    }
    else
    {
        return suma(vec, n-1) + vec[n];
    }
}

int main(void)
{
    int vec[100], dim, s; // aca pongo 100 de manija porque no voy acompletarlo, es para que sobren lugares
    printf("Ingrese la dimension del arreglo: ");
    scanf("%d", &dim);
    cargar(vec, dim);
    mostrar(vec, dim);
    s = suma(vec, dim); 
    printf("\nLa suma de los elementos del arreglo es: %d", s);
    return 0;
}




/* RECURSIVIDAD */
/* Diseñar un algoritmo recursivo que permita hacer la división por restas sucesivas.*/

#include <stdio.h>

int cociente(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    
    else
    {
        return cociente (a - b, b) + 1; // pongo dos veces B porque es un valor que no quiro que cambie 
    }
}



int main()
{
    int a, b; 
    printf("\nIngrese un numero: ");
    scanf("%d", &a);
    printf("\nIngrese otro numero: ");
    scanf("%d", &b);
    printf("\nEl cociente es: %d", cociente(a, b));
    
    return 0;
}



/*Este es para sacar el producto de los numeros ingresados de manera recursiva*/

#include <stdio.h>

int producto(int a, int b)
{
    if(b==0)
    {
        return 0;
    }
    
    return producto(a, b-1)+a;
}


int main()
{
    int a, b;
    printf("\nIngrese los valores: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\nEl producto es: %d", producto(a, b));
    
    return 0;
}


/*En  este calculamos la potencia de los numeros que ingresemos de manera recursiva*/

#include <stdio.h>

int potencia(int a, int b)
{
    if(b==0)
    {
        return 1; //pongo 1 porque nunca va a ser 0, dado que cualquier numero elevado a la 0 da 1
    }
    
    return potencia(a, b-1)*a; //como la potencia es multiplicar "x" numero "n" cantidad de veces se pone asi 
                               //por ejemplo 2^4 es igual a 2x2x2x2 
}


int main()
{
    int a, b;
    printf("\nIngrese los valores: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\nLa potencia es: %d", potencia(a, b));
    
    return 0;
}


/*Calculamos el factorial de manera recursiva*/

#include <stdio.h>

int factorial(int num)
{
    if(num==0)
    {
        return 1; //se pone 1 porque ningun factorial va a dar 0
    }
    
    return factorial(num-1)*num; //ponemos "(num-1)*num" debido a que hacemos que el nuermo que se ingreso sea menor a que cuando lo multiplicamos
                                 //por ejemplo si ingresamos un 4, num-1 lo va a volver 3 y lo va a multiplicar por 4 que es el valor inicial
}


int main()
{
    int num;
    printf("\nIngrese los valores: ");
    scanf("%d", &num);
    printf("\nEl factorial es: %d", factorial(num));
    
    return 0;
}


/*Dados dos numeros calcular la division entera (no con coma) de manera recursiva*/

#include <stdio.h>

int cociente(int a, int b)
{
    if(a-b<0) //pongo asi para que no me de numero con coma 
              //ejemplo si hago 20/8 se hace 20-8=12, 12-8=4, toma este como referencia pero lo hace una vez mas para que corte: 4-8=-4 (este no lo toma)
    {
        return 0;
    }
    
    return cociente(a, b-1)+1; //cuando se divide nos fijamos la cantidad de veces que el numero se tiene que decrementar por el divisor 
                               //por ejemplo 10/2 es 5 porque es 2-2-2-2-2, ese mismo razonamiento se aplica para esto
}


int main()
{
    int a, b;
    printf("\nIngrese los valores: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\nEl cociente es: %d", cociente(a, b));
    
    return 0;
}


/*ARREGLOS Y RECURSIVIDAD*/
/*En este caso tenemos el arreglo definido con sus valores*/

#include <stdio.h>

int suma(int vec[], int dim)
{
    if(dim<0)
    {
        return 0;
    }
    
    return suma(vec, dim-1)+vec[dim];
}


int main()
{
    int vec[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    printf("\nIngrese los valores: ");
    printf("\nLa suma del arreglo es: %d", suma(vec, 9)); //se pone desde el 9 porque las cajitas del arreglo son de 0 al 9 (osea 10 posociones) 
    
    return 0;
}


/*En este caso es el arreglo sin los valores*/

#include <stdio.h>

int suma(int vec[], int dim)
{
    if(dim<0)
    {
        return 0;
    }
    
    return suma(vec, dim-1)+vec[dim];
}

void cargar(int vec[], int dim)
{
    if(dim<0)
    {
        return; //queda solo el "return" porque es de tipo "void", no devuelve nada
    }

    printf("\ningrese valor: ");
    scanf("%d", &vec[dim]);
    cargar(vec, dim-1); 
}

void mostrar(int vec[], int dim)
{
    if(dim<0)
    {
        return; //queda solo el "return" porque es de tipo "void", no devuelve nada
    }

    printf("\nEl valor es: %d", vec[dim]);
    mostrar(vec, dim-1); 
}

int main()
{
    int vec[10], dim;
    printf("\nIngrese los valores: ");
    scanf("%d", &dim);
    cargar(vec, dim-1); //el "dim" va a ir de la ultima posicion hasta la primera 
    mostrar(vec, dim-1);
    printf("\nLa suma del arreglo es: %d", suma(vec, dim-1)); 
    
    return 0;
}


/*Aca usamos la recursividad y lo que vimos de caracteres*/

#include <stdio.h>

void invertir(int c)
{
    if(c == '\n')
    {
        return; //queda solo el "return" porque es de tipo "void", no devuelve nada
    }

    c = getchar;
    invertir(c);
    putchar(c);
}


int main()
{
    int c;
    printf("\nIngrese frase terminada en ENTER: ");
    c = getchar;
    invertir(c); //esto es para dar vuelta la frase. Ej: hola --> aloh
    putchar(c); //hay que poner este aca porque sino se come la primera letra. Ej hola --> alo (se come la H)
    
    return 0;
}


/*******************************************************************************************************************************************/

/*LISTAS SIMPLEMENTE ENLAZADAS*/

//Ejemplo con nombre, edad y sueldo 

#include <stdio.h>
#include <stdlib.h>

typedef struct empleados
{
    char nombre[30];
    int edad;
    float sueldo;
    struct empleados *sig;
}nodoempleados;


void cargar(nodoempleados *h) //p=h
{
    printf("\nIngrese el nombre: ");
    scanf("%s", h->nombre); //como es un "string" no hace falta que lleve el "&"
    
    if(strcmp(h->nombre, "x") == 0)
    {
        h->sig = NULL;
    }
    
    else
    {
        printf("\nIngrese edad: ");
        scanf("%d", &h->edad);
        printf("\nIngrese sueldo: ");
        scanf("%f", &h->sueldo);
        h->sig = (nodoempleados *)malloc(sizeof(nodoempleados));
        cargar(h->sig);
    }
}


void mostrar(nodoempleados *h) //p=h
{
    if(h->sig!=NULL)
    {
        printf("\nEl nombre es: %s", h->nombre);
        printf("\nLa edad es: %d", h->edad);
        printf("\nEl sueldo es: %f", h->sueldo);
        mostrar(h->sig);
    }
}


int main()
{
    nodoempleados *p=NULL;
    p = (nodoempleados *)malloc(sizeof(nodoempleados));
    cargar(p);
    mostrar(p);
    
    return 0;
}



/*
Crear una lista simplemente enlazada con dos numeros enteros. Finalizar cuando el primer numero ingresado e cero. Mostrarla. 
a) Cantidad de nodos donde el primer numero es multiplo del segundo. 
b) Generar una lista con aquellos nodos donde la suma de los numeros es mayor a 20. 
c) Generar una lista con el promedio de los numeros enteros. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct numeros //éste es para los puntos "a" y "b"
{
    int num1;
    int num2; 
    struct numeros *sig;
}nodonum; 


typedef struct promedio //éste es para el punto "c" 
{
    int prom;
    struct promedio *sig;
}nodoprom; 


void cargar(nodonum *h) 
{
    printf("\nIngrese el primer numero: ");
    scanf("%d", &h->num1); 
    
    if(h->num1 == 0)
    {
        h->sig = NULL;
    }
    
    else
    {
        printf("\nIngrese el segundo numero: ");
        scanf("%d", &h->num2); 
        h->sig = (nodonum *)malloc(sizeof(nodonum));
        cargar(h->sig);
    }
}


int multiplos(nodonum *h, int cant) //la hago "int" porque quiero devolver lo que me diga el contador
                                    //éste es de manera recursiva
{
    if(h->sig == NULL)
    {
        return cant;
    }
    
    if(h->num1 % h->num2 == 0)
    {
        cant+=1;
    }
    
    return multiplos(h->sig, cant);
}

/*
int multiplos(nodonum *h, int cant) //la hago "int" porque quiero devolver lo que me diga el contador
                                    //éste es de manera iterativa
{
    while (h->sig!=NULL)
    {
        if(h->num % h->num1==0)
        {
            cant=cant+1;
        }
           
        h=h->sig;
    }
    
    return cant;
}
*/


void generar(nodonum *h, nodonum *m) //aca estan los dos punteros, "p" y "q" 
                                     //este es de manera recursiva
{
    if(h->sig == NULL)
    {
        m->sig = NULL;
        return;
    }
    
    else
    {
        if(h->num1 + h->num2 > 20)
        {
            m->num1 = h->num1;
            m->num2 = h->num2; 
            m->sig = (nodonum *)malloc(sizeof(nodonum));
            generar(h->sig, m->sig);
        }
        
        else
        {
            generar(h->sig, m); //cuando no suman 20 avanzo en "h" pero en "m" no avanzo, tengo que poner el "m" igual porque 
                                //la funcion tiene dos parametros, me slata error si no lo pongo
        }
    }
}

/*
void generar(nodonum *h, nodonum *m) //aca estan los dos punteros, "p" y "q" 
                                     //este es de manera iterativa
{
    while(h->sig != NULL)
    {
        if(h->num1 + h->num2 > 20)
        {
            m->num1 = h->num1;
            m->num2 = h->num2; 
            m->sig = (nodonum *)malloc(sizeof(nodonum));
            m = m->sig;
            h = h->sig; 
        }
        
        else
        {
            h = h->sig;
        }
        
        m->sig = NULL;
    }
}
*/

void mostrar(nodonum *h) 
{
    if(h->sig!=NULL)
    {
        printf("\n-----------NODO----------\n");
        printf("%d", h->num1);
        printf("%d", h->num2);
        mostrar(h->sig);
    }
}


void generar2(nodonum *h, nodoprom *m) //aca estan los dos punteros, "p" y "r" 
                                       //este es de manera recursiva
{
    if(h->sig == NULL) //condicion de punto de corte
    {
        m->sig = NULL;
        return;
    }
    
    m->prom = (h->num1 + h->num2) / 2;
    m->sig = (nodoprom *)malloc(sizeof(nodoprom));
    generar2(h->sig, m->sig);
}


/*
void generar2(nodonum *h, nodoprom *m) //aca estan los dos punteros, "p" y "r" 
                                        //este es de manera iterativa
{
    while(h->sig == NULL) //condicion de punto de corte
    {
        m->prom = (h->num1 + h->num2)/2;
        m->sig = (nodoprom *)malloc(sizeof(nodoprom));
        generar2(h->sig, m->sig);
    }
    
    m->sig = NULL;
}
*/


void mostrar2(nodoprom *h)
{
    if(h->sig!=NULL)
    {
        printf("---------------------\n");
        printf(" %d\n", h->prom);
        
        mostrar2(h->sig);
    }
}


int main() 
{
    int cant = 0;
    nodonum *p = NULL;
    nodonum *q = NULL;
    nodoprom *r = NULL;
    p = (nodonum *)malloc(sizeof(nodonum)); // para el primer "typedef" 
    q = (nodonum *)malloc(sizeof(nodonum)); // para el primer "typedef" 
    r = (nodoprom *)malloc(sizeof(nodoprom)); // para el segundo "typedef"
    cargar(p);
    mostrar(p);
    printf("\nLa cantidad de multiplos es: %d", multiplos(p, cant));
    generar(p, q); 
    printf("\nLa nueva lista es: "); //no le pongo nada porque es de tipo "void" 
    mostrar(q);
    generar2(p, r);
    printf("\nEl promedio de la lista es: "); //no le pongo nada porque es de tipo "void" 
    mostrar2(r); 
    
    return 0;
}




/*
Dada la siguiente estructura:

 typedef struct lista {
 int codmat;
 char nombre [15];
 struct lista * sig;
 } nodo;

a) Crear y mostrar la lista (la carga finaliza cuando codmat=0). Se cargan todos los
códigos de materias iguales, seguidos y ordenados.
b) Mostrar los alumnos que pertenecen a una materia.
c) Mostrar el código de materia que cuenta con más alumnos.
*/


#include <stdio.h> 
#include <stdlib.h>

typedef struct lista 
{
    int codmat;
    char nombre [30];
    struct lista * sig;
}nodo;


void crear(nodo *h)
{
    printf("\nIngrese el codigo de materia: ");
    scanf("%d", &h->codmat);
    
    if(codmat==0)
    {
        h->sig = NULL;
    }
    
    else
    {
        printf("\nIngrese el nombre: ");
        scanf("%s", h->nombre); //no pongo "&" porque es de tipo char
        h->sig = (nodo *)malloc(sizeof(nodo));
        cargar(h->sig);
    }
}




void mostrar(nodo *h)
{
    if(h->sig != NULL)
    {
        printf("\nCodigo de materia: %d", h->codmat);
        printf("\nAlumno: %s", h->nombre);
        mostrar(h->sig);
    }
}


int main()
{
    nodo *p = NULL;
    p = (nodo *)malloc(sizeof(nodo));
    cargar(p);
    mostrar(p);
    
    
    
    return; 
}


// FALTA TERMINAR