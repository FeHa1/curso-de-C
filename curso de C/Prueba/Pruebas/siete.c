/* Aca trabajamos con LISTAS  SIMPLEMENTE ENLAZADAS*/
/* Hay que tener en cuenta que cuando ingrese el nombre y apellido voy a tener que ponerle "_" porque sino no lo reconoce*/

#include <stdio.h>
#include <stdlib.h> // es una libreria nueva donde estan las funciones "malloc()" y 

typedef struct alumno // entre las librerias y el programa principal es donde se declara la estructura
{
    int legajo;
    char nombre_y_apellido [30]; // es un arreglo, por eso le ponemos 30
    struct alumno *sig // esto esta explicado en la teoria, "sig" es de siguiente
}
nodoalum; // esto me va a servir para definir un puntero a la estructura de abajo (int main(void))


void crearlista(nodoalum *q)
{
    printf("Ingrese numero de legajo: ");
    scanf("%d", &q -> legajo); // el "->" significa siguiente, igual esta explicado en la carpeta
    
    if (q -> legajo == 0)
    {
        q -> sig = NULL;
    }
    
    else
    {
        printf("Ingrese su nombre y apellido: ");
        scanf("%s", q -> nombre_y_apellido); // pongo "%s" porque es un char, no un int y tampoco tiene "&" por ser char
        q -> sig = (nodoalum*)malloc(sizeof(nodoalum)); // como estamos en memoria dinamica para reservar espacio de memoria uso la 
                                                        // constante del lenguaje "malloc()", que mas que nada abre espacio, no reserva
        crearlista(q -> sig);
    }
}


void mostrarlita(nodoalum *q) // esta funcion es para que me muestre los valores que se ingresaron en pantalla
{
    if (q -> sig != NULL)
    {
        printf("\nEl numero de legajo es: %d", q -> legajo);
        printf("\nEl nombre y el apellido del alumno son: %s", q -> nombre_y_apellido); // pongo "%s" porque es un char, no un int
        mostrarlita(q -> sig);
    }
}


int main(void)
{
    nodoalum *p = NULL;
    p = (nodoalum*)malloc(sizeof(nodoalum));
    crearlista(p);
    mostrarlita(p);
    
    return 0;
}



/* LISTAS ENLAZADAS*/
/* Esto es un ejemplo visto en clase, la mayoria esta en la carpeta*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
        int num;
        struct list *sig;
} nodol;
        

void cargar (nodol *h) 
{
  printf("ingrese numero");
  scanf("%d",&h->num);
  if (h->num==0) 
        h->sig=NULL; //significa que a la cajita que le ponga 0 va a ser NULL, llo que indicaria el punto de corte
                     // el 0 no afecta las operaciones (ejemplo multiplicaciones) porque como es NULL no lo toma el programa 
  else
  {
    h->sig=(nodol*)malloc(sizeof(nodol)); //con esto reservo espacio de memoria para seguir poniendo nodos
    cargar(h->sig); //este agrega otro nodo para agregar otro valor, practicamente va agregando nodos durante la marcha siempre
                    //y cuando sean distintos de 0 (NULL)
  }        
}


void mostrar (nodol *h)
{
  if (h->sig !=NULL)
  {
    printf("%d\n ",h->num); //aca apunto al contenido del nodo
    mostrar(h->sig);
  }
}


int main()
{
  nodol *p=NULL;
  p=(nodol*)malloc(sizeof(nodol));
  cargar(p);
  mostrar(p);

  return 0;
}



/* Este es un ejemplo en el que pedimos nombre, nota de alumno y ponemos los desaprobados*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // en esta libreria esta la funcion "strcmp" y "strcpy"


typedef struct alumnosS
{
    char nombre_apellido[15];
    int nota;
    struct alumnosS *sig // puntero que apunta al siguiente alumno 
}alumno;


void mostrar(alumno *q)
{
    if (q -> sig != NULL)
    {
        printf("\nEl nombre es: %s", nombre_apellido);
        printf("\nLa nota es: %d", q -> nota);
    }
}



void cargar(alumno *q)
{
    printf("\nIngresar nombre: ");
    scanf("%s", q -> nombre_apellido); // aca no pongo el "&" porque es una variable de tipo "char" 
    
    if (strcmp(q -> nombre_apellido, "x")== 0) // si quiero comparar letras para eso tengo que usar la funcion "strcmp()" y usar la libreria "#include <string.h>"
    {
        q -> sig = NULL;
    }
    
    else
    {
        printf("\nIngrese nota: ");
        scanf("%d", &q -> nota);
        q -> sig = (alumno *)malloc(sizeof(alumno)); // reservo espacio de memoria
        cargar(q -> sig); // aca se llama recursivamente 
    }
}


void generar(alumno *q, alumno *d) // este es un ejemplo donde separamos a los que desaprobaron 
{
    while (q -> sig != NULL)
    {
        if (q -> nota < 6) // es la condicion para los que estan desaprobados
        {
            strcpy(d -> nombre_apellido, q -> nombre_apellido); // copia el que recibe primero (la "d") y despues el que le da el valor (la "q")
            d -> nota = q -> nota;
            d -> sig = (alumno *)malloc(sizeof(alumno));
            d = d -> sig; // esto es en caso de que haya pasado
        }
        q = q -> sig;
    }
    d -> sig = NULL; // tengo que poner esto porque sino cuando vaya a acabar no va a encontrar en NULL por ende no va a cortar
}


int main()
{
    alumno *p = NULL;
    alumno *h = NULL;
    p = (alumno *)malloc(sizeof(alumno));
    h = (alumno *)malloc(sizeof(alumno));
    cargar(p);
    mostrar(p);
    generar(p, h);  
    printf("\nLa lista con desaprobados es: %d");
    mostrar(h); // como estamos en la misma estructura no debemos hacer un "mostrar" nuevo
    
    return 0;
}



/*LISTAS SIMPLEMENTE ENLAZADAS*/
/*Aca hay un ejemplo en el que vemos el ingreso de un numero y su sueldo*/

#include <stdio.h>
#include <stdlib.h>

typedef struct numeros
{
    int num;
    float sueldo;
    struct numeros *sig;
}nodon;


void crearlista(nodon *h)
{
    printf("ingrese valor numerico");
    scanf("%d",&h->num);
    if (h->num==0)   
    {
        h->sig=NULL;//significa que a la cajita que le ponga 0 va a ser NULL, llo que indicaria el punto de corte
                     // el 0 no afecta las operaciones (ejemplo multiplicaciones) porque como es NULL no lo toma el programa 
    }

    else
    {
        printf("ingrese sueldo"); //lo pongo aca porque si el numero es 0 ¿para que voy a preguntar el sueldo? por eso no 
        scanf("%f",&h->sueldo); //lo pongo arriba
        h->sig=(nodon*)malloc(sizeof(nodon)); //este agrega otro nodo para agregar otro valor, practicamente va agregando nodos 
                                              //durante la marcha siempre                     
        crearlista(h->sig); //y cuando sean distintos de 0 (NULL)
    }
}


void mostrarlista(nodon *h)
{
    if (h->sig!=NULL)
    {
        printf("%d \n",h->num); //aca apunto al contenido del nodo
        printf("%f \n",h->sueldo); //aca apunto al contenido del nodo
        mostrarlista(h->sig);
    }
}


int main() 
{
    nodon *p=NULL;
    p=(nodon *)malloc(sizeof(nodon));
    crearlista(p);
    mostrarlista(p);
    
    return 0;
}



/*Esto es lo mismo que lo de arriba pero hecho de manera iterativa, no con punteros como en el caso de arriba*/

#include <stdio.h>
#include <stdlib.h>

typedef struct numeros
{
    int num;
    float sueldo;
    struct numeros *sig;
}nodon;


void crearlista(nodon *h)
{
    printf("ingrese valor numerico");
    scanf("%d",&h->num);
    while(h->num != 0)
    {
        printf("\nIngrese el sueldo: ");
        scanf("%d", &h->sueldo);
        h->sig = (nodon *)malloc(sizeof(nodon));
        h = h->sig; //esto es para caminar al siguiente nodo
        printf("\nIngrese el sueldo: "); //y vuelve a pedir el proximo nodo
        scanf("%d", &h->sueldo);
    }

    h->sig = NULL; //cuando el valor sea 0 va a salir del ciclo y automaticamente le voy a poner NULL
}


void mostrarlista(nodon *h)
{
    if (h->sig!=NULL)
    {
        printf("%d \n",h->num); //aca apunto al contenido del nodo
        printf("%f \n",h->sueldo); //aca apunto al contenido del nodo
        h = h->sig; //con este camino sobre las caju¿itas y las voy imprimiendo, y las puedo caminar porque estoy 
                    //dentro de un ciclo "while"
    }
}


int main() 
{
    nodon *p=NULL;
    p=(nodon *)malloc(sizeof(nodon));
    crearlista(p);
    mostrarlista(p);
    
    return 0;
}



/*Aca vemos como generar otra lista para los valores que no cumplen la condicion*/

#include <stdio.h>
#include <stdlib.h>

typedef struct numeros
{
    int num;
    float sueldo;
    struct numeros *sig;
}nodon;


void crearlista(nodon *h)
{
    printf("ingrese valor numerico");
    scanf("%d",&h->num);
    while(h->num!=0)
    {
        printf("ingrese sueldo");
        scanf("%f",&h->sueldo);
        h->sig=(nodon *)malloc(sizeof(nodon));
        h=h->sig;
        printf("ingrese valor numerico");
        scanf("%d",&h->num);
    }
    
    h->sig=NULL;
}


void mostrarlista(nodon *h)
{
    while(h->sig!=NULL)
    {
        printf("%d \n",h->num);
        printf("%f \n",h->sueldo);
        h=h->sig;
    }
}


void generar(nodon *h, nodon *a)
{
    while(h->sig!=NULL)
    {
        if(h->sueldo < 3000)
        {
            a->num=h->num; //hago que el valor menor a 3000 se mueva desde "h" (que esta con el puntero p) hacia "a" (que esta con el puntero q)
            a->sueldo=h->sueldo; //hago lo mismo que explique en la linea anterior 
            a->sig=(nodon *)malloc(sizeof(nodon)); //reservo espacio de memoria
            a=a->sig; //si no hago esto no se mueve del primer nodo
        }
        
        h=h->sig;
    }
    
    a->sig=NULL; //cuando sale del "while" significa que se ingreso un 0, por ende se pone NULL para que pare de generar cajitas
                 //esto es solo para la segunda tanda de cajitas de "q" ya que la de "p" ya la hicimos arriba en la funcion "crearlista"
}


int main() 
{
    nodon *p=NULL;
    nodon *q=NULL;
    p=(nodon *)malloc(sizeof(nodon));
    q=(nodon *)malloc(sizeof(nodon)); //creo otra lista de cajitas para cuando necesita mover los valores que no cumplen la condicion
    crearlista(p);
    mostrarlista(p);
    generar(p,q);
    printf("la nueva lista es \n"); //esto es para separar la lista de los valores que no cumplen la condicion, porque sino 
                                    //aparece todo junto y desprolijo
    mostrarlista(q); //este muestra los valores de la nueva lista
    
    return 0;
}





/*********************************************************************************************************************/


/*MULTILISTAS*/
/*
Vemos ejemplo con aluno y profesores en cada materia.
*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct alumnos
{
    char nomyape[30];
    struct materias *m;
    struct alumnos *sig;
}nodoa;


typedef struct materias
{
    char nom_mat[30];
    char profesor[30];
    struct materias *m;
}nodom;


void crear_lista_alumnos(nodoa *h)
{
    printf("\nIngrese el nombre del alumno: ");
    scanf("%s", h->nomyape);
    
    if(strcmp(h->nomyape, "x") == 0)
    {
        h->sig = NULL;
    }
    
    else
    {
        h->m = (nodom*)malloc(sizeof(nodom)); 
        crear_lista_materias(h->sig);
    }
}


void crear_lista_materias(nodom *h)
{
    printf("\nIngrese el nombre de la materia: ");
    scanf("%s", h->nom_mat);
    
    if(strcmp(h->nom_mat, "x") == 0)
    {
        h->m = NULL;
    }
    
    else
    {
        printf("\nIngrese el nombre del profesor: ");
        scanf("%s", h->profesor);
        h->m = (nodom*)malloc(sizeof(nodom));
        crear_lista_materias(h->m);
    }
}


void mostrar_lista_alumnos(nodoa *h)
{
    if(h->sig != NULL)
    {
        printf("\nEl nombre del alumnos es: %s", h->nomyape);
        mostrar_lista_materias(h->m);
        mostrar_lista_alumnos(h->sig);
    }
}


void mostrar_lista_materias(nodom *h)
{
    if(h->m != NULL)
    {
        printf("\nEl nombre de la materia es: %s", h->nom_mat);
        printf("\nEl nombre del profesor es: %s", h->profesor);
        mostrar_lista_materias(h->m);
    }
}


int main()
{
    nodoa *p = NULL;
    p = (nodoa*)malloc(sizeof(nodoa));
    crear_lista_alumnos(p);
    mostrar_lista_alumnos(p);
    
    
    return 0;
}










