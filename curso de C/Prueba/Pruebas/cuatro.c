/* Estos son ejercicios donde trabajamos para buscar letras, los cuales son llamados caracteres */

# include <stdio.h>

int main()
{
    int c; // declaro la variable, y lo hago de forma entrea (int) porque lo va a relacionar con un valor numerico, el cual esta definido en la "TABLA DE ASCII"
    printf("Ingrese la frase terminada en punto: ");
    c = getchar(); // Lo que va a hacer esto es dejarme ingresar la frase en memoria y en "c" me queda el primer caracter de la frase 
    putchar(c); // esto lo que va a hacer es devolverme la letra en la cual se asigno "c", y se necesita esta funcion porque "getchar()" no devuelve la letra sino el valor numerico 
    
    return 0; 
}


/* Ahora este es otro ejemplo de lo mismo pero en lugar de que devuelva la primera letra, ahora recorre una oracion*/

# include <stdio.h>

int main()
{
    int c, cont = 0; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar();  
    while (c != '.') // se lo tiene que dejar con comillas simples porque estamos comparando con una sola letra o un conjunto. Si no se pone, sale error de compilacion.
                     // y que sea distinto de '.' hace que recorra todas las letras hasta toparse contra el punto de la oracion, entonces "c" es la variable que recorre la oracion     
    {
        cont ++; // como mi objetivo es contar la cantidad de caracteres que tenga la frase (inclusive los caracteres en blanco) yo voy a usar un contador para irlos contando.
        putchar(c); // y este lo ponia para que me imprima el caracter en pantalla. 
        c = getchar(); // se vuelve a poner porque sino nunca va a salir del ciclo "while" y se quedaria en el primer caracter. 
                       // Tambien se tiene que poner el "printf()" porque sino no imprime nada. 
    }
    printf("\nLa cantidad de caracteres de la frase es %d: ", cont); // lo que se va a imprimir es el numero de caracteres de la oracion, contando tambien los espacios en blanco.
    
    return 0; 
}


/* Si quisieramos no contar los espacios en blanco solo tenemos que proceder con el siguiente ejemplo*/ 

# include <stdio.h>

int main()
{
    int c, cont = 0; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar();  
    while (c != '.') 
    {
        if (c != ' ') // el espacio entre las "' '" significa que no va a contar los espacios en blanco, ya que el "while" contara todos los datos si queda solo.
                      // se tiene que dejar si o si un espacio entre las comillas simbles('') ya que lo que no debe contar son los espacios en blanco y asi se lo planteamos.
        {
            cont++; 
        }
        
        putchar(c);
        c = getchar(); 
    }
    printf("\nLa cantidad de caracteres de la frase es %d: ", cont); 
    
    return 0; 
}


/* Para contar solo las letras especificas se actua de la siguiente manera*/

# include <stdio.h>

int main()
{
    int c, cont = 0; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar();  
    while (c != '.') 
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') // se separan con dos "||" (vendria a ser como una ´o´), de otra manera no funciona  
        {
            cont++; 
        }
        
        putchar(c);
        c = getchar(); 
    }
    printf("\nLa cantidad de caracteres de la frase es %d: ", cont); 
    
    return 0; 
}


/* Esto es para sacar la ultima letra de cada palabra de las oraciones */

# include <stdio.h>

int main()
{
    int c, cont = 0, aux ; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar();  
    while (c != '.') 
    {
        while (c != ' ' && c != '.')
        {
            aux = c; // En el ciclo interior, va guardando en aux el ultimo caracter leido que no sea blanco o punto
            c = getchar(); // si en el ciclo "while" estoy por la ultima palabra el "c = getchar()" lee el '.', por ende se va porque la condicion es que fuese distinto del punto
        }                  // *continuo abajo con el if*
        putchar(aux); 
        
        if (c != '.') // si yo pido otro caracter pierdo el punto que saque del "while", por eso pregunto si "c" no es punto pido otro caracter, si es, 
                      // directamente que vaya al "while" general y se termine de arreglar 
        
        {
            c = getchar(); 
        }
        
    }
    
    return 0; 
}


/* Esto es para sacar la primera letra de cada palabra de las oraciones */

# include <stdio.h>

int main()
{
    int c, cont = 0, pri ; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar(); // aca queda la primer letra de la primer palabra
    while (c != '.') 
    {
        pri = c; // esta variable lo que hace es almacenar la primera letra que quedo arriba en "c=getchar()"
        
        while (c != ' ' && c != '.') // en este "while" recorre toda la palabra y va a salir si encuentra un blanco o un punto 
        {
            c = getchar(); // si en el ciclo "while" estoy por la ultima palabra el "c = getchar()" lee el '.', por ende se va porque la condicion es que fuese distinto del punto
        }                  // *continuo abajo con el if*
        
        printf("\nLa primera letra de cada palabra es: "); // sale del "while" porque evidentemente encontro un espacio e imprime el valor de "putchar(pri)"
        putchar(pri); // aca se llama a la funcion para que se pueda imprimir en pantalla
        
        if (c != '.')  // si yo pido otro caracter pierdo el punto que saque del "while", por eso pregunto si "c" no es punto pido otro caracter, si es, 
                      // directamente que vaya al "while" general y se termine de arreglar 
        {
            c = getchar(); 
        }
        
    }
    
    return 0; 
}


/* El problema del anterior es que si ponemos muchos espacios entre oraciones nos los va a tomar como caracteres y los va a imprimir, por ende recurrimos a esta manera de ejecutarlo*/

# include <stdio.h>

int main()
{
    int c, cont = 0, pri, aux ; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar(); // aca queda la primer letra de la primer palabra
    while (c != '.') 
    {
        while (c == ' ' && c != '.') // 
        {
            c = getchar();
        }
        
        pri = c; // esta variable lo que hace es almacenar la primera letra que quedo arriba en "c=getchar()"
        
        while (c != ' ' && c != '.') // en este "while" recorre toda la palabra y va a salir si encuentra un blanco o un punto 
        {
            aux = c; 
            c = getchar(); // si en el ciclo "while" estoy por la ultima palabra el "c = getchar()" lee el '.', por ende se va porque la condicion es que fuese distinto del punto
        }                  // *continuo abajo con el if*
        
        //putchar(aux); 
        printf("\nLa primera letra de cada palabra es: "); // sale del "while" porque evidentemente encontro un espacio e imprime el valor de "putchar(pri)"
        putchar(pri); // aca se llama a la funcion para que se pueda imprimir en pantalla
        
        if (c != '.')  // si yo pido otro caracter pierdo el punto que saque del "while", por eso pregunto si "c" no es punto pido otro caracter, si es, 
                      // directamente que vaya al "while" general y se termine de arreglar 
        {
            c = getchar(); 
        }
        
    }
    
    return 0; 
}

/* Este ejemplo es para contar la cantidad de palabras que empiezan y terminan con la misma letra y que las imprima en pantalla*/

# include <stdio.h>

int main()
{
    int c, cont = 0, pri, aux ; 
    printf("Ingrese la frase terminada en punto: ");
    c = getchar(); // aca queda la primer letra de la primer palabra
    while (c != '.') 
    {
        while (c == ' ' && c != '.') // 
        {
            c = getchar();
        }
        
        pri = c; // esta variable lo que hace es almacenar la primera letra que quedo arriba en "c=getchar()"
        
        while (c != ' ' && c != '.') // en este "while" recorre toda la palabra y va a salir si encuentra un blanco o un punto 
        {
            aux = c; 
            c = getchar(); // si en el ciclo "while" estoy por la ultima palabra el "c = getchar()" lee el '.', por ende se va porque la condicion es que fuese distinto del punto
        }                  // *continuo abajo con el if*
        
        printf("\nLa primera letra de cada palabra es: "); // sale del "while" porque evidentemente encontro un espacio e imprime el valor de "putchar(pri)"
        putchar(pri); // aca se llama a la funcion para que se pueda imprimir en pantalla
        
        if (pri == aux)
        {
            cont ++; 
        }
        
        if (c != '.')  // si yo pido otro caracter pierdo el punto que saque del "while", por eso pregunto si "c" no es punto pido otro caracter, si es, 
                      // directamente que vaya al "while" general y se termine de arreglar 
        {
            c = getchar(); 
        }
        
        printf("\nLa cantidad de palabras que comienzan y terminan con la misma letra son %d: \n", cont);
    }
    
    return 0; 
}


/* CARACTERES */
/* Aca vemos un ejemplo de caracteres, la consigna era contar cuantas palabras terminaban en "s"*/ 

#include <stdio.h>

int main() 
{
  int c, cont=0, aux;
  printf("Ingrese la frase: ");
  c=getchar();
  while(c!='.')
  {   
    while(c!=' ' && c !='.')
    {
      aux=c; // como la "c" recorre todas las frases, dejo que el "aux" almacene la ultima letra de cada frase, que en este caso la condicion es que termine en "s"
      c=getchar();
    }

    if(aux == 's') // se pone el "if" afuera del "while" porque (mirar la clase)
    {
        cont++;
    }

    while(c==' '&& c!='.') // esto se hace para cuando hay muchos espacios entre palabra y palabra, de esta manera no sale error
    {
      c=getchar();
    }
    
   
  }
  printf("\nLa cantidad de palabras terminadas en S son: %d", cont);

  return 0;
}



/*Este es otro ejemplo en el que cuento la cantidad de "s" que hay en total en las frases que ingrese*/

#include <stdio.h>

int main()
{
    int c, cont = 0;
    
    printf("\nIngrese la frase: ");
    c = getchar(c);
    while(c != '.')
    {
        if(c == 's')
        {
            cont++;
        }
        
        c = getchar();
    // putchar(c) // no esta mal pero por culpa del IDE me queda un bucle infinito 
        
    }
    
    printf("\nLas frases terminadas en S son: %d", cont);
    
    return 0; 
}



/* Aca en este ejemplo lo que se hace es contar las palabras que empiezan con "s"*/


#include <stdio.h>

int main() 
{
  int c, cont=0, aux;
  printf("Ingrese la frase: ");
  c=getchar();
  while(c!='.')
  {   
    while(c!=' ' && c !='.')
    {                           // con esta rutina salteo los blancos, por si el usuario empezo con espacios o puso mas de un espacio entre palabra y palabra
      c=getchar();
    }

    aux=c; // si salteo los blancos (como hice arriba) me quedo con la primera letra de la palabra

    while(c==' '&& c!='.') // esto se hace para cuando hay muchos espacios entre palabra y palabra, de esta manera no sale error
    {
      c=getchar();
    }
    

    if(aux == 's') 
    {
        cont++;
    }   
  }

  printf("\nLa cantidad de palabras terminadas en S son: %d", cont);

  return 0;
}


/*Aca hacemos la cantidad de palabras que tiene la frase*/

#include <stdio.h>

int main()
{
    int c, cont = 0, cont1 = 0;
    printf("\nIngrese la frase: ");
    c = getchar();
    while(c != '.')
    {
        while(c == ' ' && c != '.')
        {
            c = getchar();
        }

        cont = 0;
        while(c != ' ' && c != '.') // aca lo que hace es  contar las letras hasta que llegue al blanco, donde pasa al "if"
        {
            cont++;
            c = getchar();
        }

        if(cont != 0) // aca en el "if" lo que pasa es que recibe las letras que salieron del "while" de arriba y si la cantidad de letras es distinta de 0 
                      // entiende que es una palabra, entonces la suma al cont1 (donde se almacenara la cantidad de palabras)
        {
            cont1++;
        }
    }

    printf("\nLa cantidad de palabras que tiene la frase es: %d", cont1);

    return 0;
}


/*Este es un ejemplo en el que vemos cuantas "a" hay en una oracion*/

#include <stdio.h>

int main()
{
    int c, cont = 0;
    
    c =getchar(); //si no se pone este, no te toma la primer letra
    while (c != '\n')
    {
        putchar (c);
        if (c == 'a') //se pone aca porque si lo pones abajo del "getchar" no tratas el caracter y directamente toma el que sigue
                      //(esto en caso de que la primer letra sea con "a" como dice la condicion)
        {
            cont ++;
        }
        c= getchar();
    }
    printf ("\nLa cantidad de A es: %d", cont);
    
    return 0;
}


/*Este es un ejemplo para ver la cantidad de vocales*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contv = 0;
    
    c =getchar();
    while (c != '\n')
    {
        putchar (c);
        if (c == 'a')
        {
            cont ++;
        }
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
           contv ++; 
        }
        c= getchar();
    }
    
    printf ("\nLa cantidad de A es: %d", cont);
    printf ("\nLa cantidad de vocales es: %d", contv);
    
    return 0;
}


/*Este es un ejemplo de si queremos ver las primeras letras de cada frase de la oracion*/

#include <stdio.h>

int main() 
{
    int c;
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        putchar(c); //este lo que hace es quedarse con la primera letra, no las recorre todas como si haria si estuviese dentro del "while"
        while (c != '.' && c != ' ')
        {
            c = getchar();
        }
        
        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
        }
    }
    
    return 0;
}




/*Este es un ejemplo en el que vemos como hacemos si queremos buscar la ultima letra de cada frase y tenemos blancos
adelante de la oraion y al final antes del punto*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contv = 0;
    int ultimo;
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        while (c != '.' && c != ' ')
        {
            ultimo = c;
            c = getchar();
        }
        putchar(ultimo); //esto va a devolver todas las ultimas letras de cada palabra de la oracion
        
        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
            
        }
    }
    
    return 0;
}


/*Este es un ejemplo en el que contamos las palabras que empiezan con A y terminan con S*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contv = 0;
    int ultimo, primera;
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        primera = c; //este guarda la primera letra de cada palabra de la oracion
        while (c != '.' && c != ' ')
        {
            ultimo = c; //este guarda la ultima letra de cada palabra de la oracion
            c = getchar();
        }
        putchar (ultimo);
        
        if(primera == 'a' && ultimo == 's')
        {
            cont++;
        }

        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
            
        }
    }
    
    printf("\nLas cantidad de palabras que empiezan con A y terminan con S son: %d", cont);
    
    return 0;
}


/*Aca calculamos la cantidad de palabras con mas de 3 letras*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contLetras = 0, contPal = 0;
    
    c =getchar();
    
    while (c != '.' && c == ' ')
    {
        c = getchar();
    }
    
    while (c != '.')
    {
        while (c != '.' && c != ' ')
        {
            contLetras++;
            putchar(c);
            c = getchar();
        }
        
        if(contLetras > 3)
        {
            contPal++;
        }
        contLetras = 0; //se reinicia el contador de letras porque sino se nos acumulan 
        
        while (c != '.' && c == ' ')
        {
            c = getchar();
            
        }
    }
    
    printf("\nLa cantidad de palabras de la oracion que tienen mas de 3 letras son: %d", contPal);
    
    return 0;
}


/*En este ejemplo calculamos la cantidad de palabras que hay en una frase*/

#include <stdio.h>

int main() 
{
    int c, cont = 0;
    
    c =getchar();
    while (c != '.' && c == ' ')
    {
        c = getchar();
    }    
    
    while (c != '.')
    {
        while (c != '.' && c != ' ')
        {
            putchar(c);
            c = getchar();
        }
        cont ++; //como sale de la lectura de palabras lo unico que hacemos es contarlas
        
        while (c != '.' && c == ' ')
        {
            c = getchar();
        }
        
    }
    
    printf ("\nCantidad de palabras: %d", cont);
    return 0;
}


/*En este ejemplo queremos que cuando devuelva la lectura (que pone todas las palabras juntas) tenga mas de un espacio entre 
palabra y palabra*/

#include <stdio.h>

int main() 
{
    int c;
    
    c =getchar();
    while (c != '.' && c == ' ')
    {
        c = getchar();
    }    
    
    while (c != '.')
    {
        while (c != '.' && c != ' ')
        {
            putchar(c);
            c = getchar();
        }
        
        while (c != '.' && c == ' ')
        {
            c = getchar();
        }
        
        putchar(' '); //se ponen aca porque al salir del "while" sabemos que nos dejo al principio de la palabra o en la marca
        putchar(' '); //de fin, en el ultimo caracter de la secucencia 
    }
    
    return 0;
}


/*******************************************************************************************************************************************/

/*Cargar una matriz haciendo el cargar de manera recursiva*/

// Ingresar los NxN elementos de una matriz. Calcular el producto de los elementos de la diagonal principal recursivamente. 
// El producto de la diagonal principal es la multiplicacion de los elementos de la diagonal.

#include <stdio.h> 

void cargar(int mat[10][10], int dim, int i, int j)
{

    if(i>=dim) //ésto es para que entre obligatoriamente, si "dim=3" pregunta si el "if(i>3 && j>3)", no es asi, entonces pregunta a los 
               //otros "if" donde ahi si guarda los valores ingresados. 
    {
        return;
    }
    
    if(j<dim) //pregunta si "j<3", como "j" está en 0 avanza con la condicion, corta cuando no se cumpla mas en el ida y vuelta de la recursividad
    {
        printf("fila %d columna %d\n ", i, j);
        scanf("%d", &mat[i][j]);
        cargar(mat, dim, i, j+1); //el que va cambiando es el "j", de ésta manera va a hacer la primera fila pero va viendo los valores que estan en las 
                                  //columnas
    }

    else 
    {
        j=0; //aca englobamos todo, cuanto termina de recorrer el "j" avanza al "i" desde la columna 0
        cargar(mat, dim, i+1, j); 
    }
    
}


void mostrar(int mat[10][10], int dim)
{
    int i, j;
    for(i=0; i<dim; i++)
    {
        printf("\n ");
        
        for(j=0; j<dim; j++)
        {
            printf("%d\t", mat[i][j]); 
        }
    }
}


int diag_princ(int mat[10][10], int dim)
{
    if(dim < 0) //porque sino me devuelve la dimension i=0 y j=0
    {
        return 1; //para que multiplique por 1 al resultado dado
    }
    
    return diag_princ(mat, dim-1) *mat[dim][dim]; 
}


int main()
{
    int mat[10][10], dim, i=0, j=0;;
    printf("\nIngrese la dimension: ");
    scanf("%d", &dim);
    cargar(mat, dim, i, j);
    mostrar(mat, dim);
    printf("\nEl productode los elementos de la diagonal principal es: %d", diag_princ(mat, dim-1)); //si tengo una matriz de 3x3 en el codigo empieza en
    //0, entonces para nosotros es de 1 a 3 y para el codigo es de 0 a 2, por eso a ese 3 que ingresamos le restamos 1 para que el programa lo entienda
}




/*PUNTEROS*/


int main()
{
    int vec[30] //[4, 8, 3]
    int *p; 
    p = &vec[0]; //voy a la direccion donde se almaceno el valor de la caja 0
    *(p+0) = 4; //->        for(i=0; i<n; i++){
    *(p+1) = 8; //->            scanf("%d", *(p+i));
    *(p+2) = 3; //->        }
    p++; //ejemplos
    p--; //ejemplos 

    // si hago solo "*p+2" suma de manera matematica, osea que queda "4+2"
}


/*
5- Escribir un programa efectúe las siguientes operaciones:
a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y
mostrarlo.
b) Declarar un puntero a float.
c) Asignar al puntero la dirección del arreglo.
d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada
posición.
*/






