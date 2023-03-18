/* Esto es un ejercicio de matrices. */

#include <stdio.h>

void cargar(int mat[5][5], int n) // los '[][]' no pueden quedar vacios porque para que C entienda que no es un "arreglo largo" hay que colocarle numeros, 
// de otro modo nos sale error de compilacion
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           printf("\nIngrese elemento %d: ");
           scanf("%d", &mat[i][j]); // las filas son las 'i' y las columnas son la 'j'
        }
    }
}



void mostrar (int mat[5][5], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           printf("\nEl elemento es %d ", mat[i][j]);
        }
    } 
}



int main()
{
    int mat[5][5], n; // 'mat' es por la matriz. 'n' es la cantidad de filas o columnas.
    printf("\nIngrese la cantidad de filas o columnas (menor de 5): "); // aca no hace alta poner el '"%d"' porque ya defini que va a ser un entero desde antes.
    scanf("%d", &n);
    cargar(mat, n);
    mostrar(mat, n); 
    
    return 0;
}



/*Ejemplo que dio la profe en la clase sobre MATRICES*/

#include <stdio.h>

// Online C compiler to run C program online

void cargar(int a[ ][ 10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("fila %d columna %d\n ",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
}

void mostrar(int a[ ][ 10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
      printf("\n ");
      for(j=0;j<dim;j++)
        {
            printf(" %d\t ",a[i][j]);
            
        }
        
    }
}




int main() {
   int mat[10][10],dim;
    printf("ingrese dimension de la matriz menor a 10 filas ");
    scanf("%d",&dim); 
   cargar(mat,dim);
   mostrar(mat,dim);
    
    return 0;
}



/*Aca tenemos un ejemplo donde se buscan los maximos elementos de la matriz*/

void cargar(int a[][10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("fila %d columna %d\n ",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
}


void mostrar(int a[][10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
      printf("\n ");
      for(j=0;j<dim;j++)
        {
            printf(" %d\t ",a[i][j]);
            
        }
        
    }
}


void maximo(int a[][10], int dim)
{
    int i, j, max = a[0][0]; //el "a[0][0]" es para inicializar 0 en ambas posiciones (i y j) y que de ahi empiece a recorrer
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
}


int main() {
   int a[10][10],dim;
    printf("ingrese dimension de la matriz menor a 10 filas: ");
    scanf("%d",&dim); 
   cargar(a,dim);
   mostrar(a,dim);
   maximo(a, dim);
    
    return 0;
}



/*Aca tenemos un ejemplo donde se busca el mayor elemento de cada fila*/

void cargar(int a[][10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("fila %d columna %d\n ",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
}


void mostrar(int a[][10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
      printf("\n ");
      for(j=0;j<dim;j++)
        {
            printf(" %d\t ",a[i][j]);
        }
    }
}


void maximo(int a[][10], int dim)
{
    int i, j, max = a[0][0]; //el "a[0][0]" es para inicializar 0 en ambas posiciones (i y j) y que de ahi empiece a recorrer
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        printf("\nEl valor maximo de la fila %d es %d", i, max);
        max = a[i+1][0]; //el "j" lo inicializo en 0 pra que vaya recorriendo y a "i" le sumo 1 para que vaya saltando las filas a medida
                         //de que haya terminado de recorrer "j"
    }
}


int main() {
   int a[10][10],dim;
    printf("ingrese dimension de la matriz menor a 10 filas: ");
    scanf("%d",&dim); 
   cargar(a,dim);
   mostrar(a,dim);
   maximo(a, dim);
    
    return 0;
}


/*******************************************************************************************************************************************/

/*Unos ejercicios de caracteres que quedaron en la clase*/
//Dejar 3 blancos entre palabra y palabra

#include <stdio.h>

int main()
{
    int c;
    printf("\nIngrese la frase: ");
    c=getchar();

    while(c != '.')
    {
        while(c != ' ' && c!= '.')
        {
            putchar(c);
            c=getchar;
        }

        while(c == ' ' && c != '.') //aca lo que hace es que cuando ve un blanco deja 3 blancos entre cada palabra
        {
            c=getchar();
        }
        
        putchar(' '); //esto lo que hace es dejar blancos entre palabra y palabra
        putchar(' ');
        putchar(' ');
    }
    
    return 0;
}

// me queda un bucle infinito PREGUNTAR A LA PROFE



/*RECURSIVIDAD*/

#include <stdio.h>

int producto(int a, int b)
{
    int i, acum = 0;

    for(i=0; i<b; i++)
    {
        acum = acum + a;
    }

    return acum;
}


int main()
{
    int a, b;
    printf("\nIngrese A: ");
    scanf("%d", &a);
    printf("\nIngrese B: ");
    scanf("%d", &b);
    printf("%d", producto(a, b));

}

//Suma de manera recursiva

int producto(int a, int b)
{
    for(b == 0 || a == 0)
    {
        return 0; //suma toodo por 0, que da 0, entoces suma los valores de "+a"
    }

    return producto(a, b-1) +a;
}


int main()
{
    int a, b;
    printf("\nIngrese A: ");
    scanf("%d", &a);
    printf("\nIngrese B: ");
    scanf("%d", &b);
    printf("%d", producto(a, b));
}


//Multiplicacion de manera recursiva

#include <stdio.h>

int producto(int a, int b)
{
    for(b == 0) //solo uso el "b" 
    {
        return 1; //sino siempre lo va a multiplicar por 0
    }

    return producto(a, b-1) *a;
}


int main()
{
    int a, b;
    printf("\nIngrese A: ");
    scanf("%d", &a);
    printf("\nIngrese B: ");
    scanf("%d", &b);
    printf("%d", producto(a, b));
}


//Con factoriales

#include <stdio.h>

int factorial(int a) //solo uso el "a" porque usamos solo 1 valor en la funcion, hacemos todas las operaciones por sí mismo 
{
    for(a == 0) 
    {
        return 1; //sino siempre lo va a multiplicar por 0
    }

    return factorial(a-1) *a;
}


int main()
{
    int a;
    printf("\nIngrese A: ");
    scanf("%d", &a);
    printf("%d", factorial(a));
}


//Dados 2 numeros calcular la division de 20/4 de manera recursiva

#include <stdio.h>

int division(int a, int b)
{
    if(a == 0)
    {
        return 0;
    }

    return division(a-1, b) +b;
}


int main()
{
    int a, b;
    printf("\nIngrese A: ");
    scanf("%d", &a);
    printf("\nIngrese B: ");
    scanf("%d", &b);
    printf("%d", division(a, b));
}



//Dados 2 numeros calcular la division de 20/4 de manera recursiva

#include <stdio.h>

int division(int a, int b)
{
    if(a == 0 || a < b) //la segunda condicion es para cuando tengo un numero que me queda un resultado en entero con coma (ej: 21/5)
    {
        return 0;
    }

    return division(a-b, b) +1;
}


int main()
{
    int a, b;
    printf("\nIngrese A: ");
    scanf("%d", &a);
    printf("\nIngrese B: ");
    scanf("%d", &b);
    printf("%d", division(a, b));
}


//Ingresar posicion y mostrar el numero que ocupa en una posicion previamente (secuencia de Fibonacci)

#include <stdio.h>

int calcular(int a)
{
    if(a == 1 || a == 2) 
    {
        return 1;
    }

    return calcular(a-1) + calcular(a-2);
}


int main()
{
    int a; //la posicion es "a" 
    printf("\nIngrese valor: ");
    scanf("%d", &a);
    printf("%d", calcular(a));
}



// 1) Ingresar un numero entero y mostrarlo recursivamente invertido
//    Ej: 4347 -> 7434 (hay que dividir el numero por 10, el resto de cada division va a ser el numero dado vuelta)

#include <stdio.h>

void invertido(int a)
{
    if(a == 0) /
    {
        return; //como es de tipo "void" no devuelve nada
    }
    
    printf("%d", a%10); //pongo eso para que me muestre el resto  del numero (que es el invertido)
    printf("%d", invertido(a/10));
}


int main()
{
    int a; 
    printf("\nIngrese valor: ");
    scanf("%d", &a);
    invertido(a);
}



// 2) Ingresar los N numeros enteros de un arreglo. Calcular la suma de sus elementos en forma recursiva. 
// El cargar y mostrar estan hechos de manera iterativa (como lo veniamos haciendo), lo unico recursivo es la funcion "suma"

#include <stdio.h>

void cargar(int vec[], int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        printf("\nIngrese los elementos: ");
        scanf("%d", &vec[i]);
    }
}


void mostrar(int vec[], int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        printf("%d", vec[i]);
    }
}


int suma(int vec[], int dim) 
{
    if(dim == 0)
    {
        return vec[0];
    }
    
    return suma(vec, dim-1)+vec[dim];
}


int main()
{
    int vec[30], dim; 
    printf("\nIngrese dimension: ");
    scanf("%d", &dim);
    cargar(vec, dim);
    mostrar(vec, dim);
    printf("\nLa suma de los elementos del arreglo es: %d", suma(vec, dim-1)); //le pongo "-1" porque porque si ingreso la dimension 8, en el 
    //arreglo va a ir de 0 a 7, pero si va hasta de 0 a 8 me va a saltar un error porque no hay nada en la posicion 8
}


// 3) Ingresar los NxN elementos de una matriz. Calcular el producto de los elementos de la diagonal principal recursivamente. 
// El producto de la diagonal principal es la multiplicacion de los elementos de la diagonal.

#include <stdio.h> 

void cargar(int mat[10][10], int dim)
{
    int i, j;
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            printf("fila %d columna %d\n ", i, j);
            scanf("%d", &mat[i][j]);
        }
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
    int mat[10][10], dim;
    printf("\nINgrese la dimension: ");
    scanf("%d", &dim);
    cargar(mat, dim);
    mostrar(mat, dim);
    printf("\nEl productode los elementos de la diagonal principal es: %d", diag_princ(mat, dim-1)); //si tengo una matriz de 3x3 en el codigo empieza en
    //0, entonces para nosotros es de 1 a 3 y para el codigo es de 0 a 2, por eso a ese 3 que ingresamos le restamos 1 para que el programa lo entienda
}



// 4) Ingresar un texto caractera  caracterr terminado en punto y mostrar el texto invertido en forma recursiva.

#include <stdio.h>

void invertir(int c)
{
    
    if(c == '.')
    {
        return; //el return va solo porque es una funcion de tipo "void"
        
    }
    
    c=getchar(); //guarda las letras
    invertir(c); //apila todas las letras
    putchar(c); //se desapila y muestra la frase 
}



int main()
{
    int c;
    printf("\nIngrese una frase: "); //ej: hola.
    c=getchar; //guardo la "h"
    invertir(c); //me quedo con la "h"
    putchar(c); //muestro la "h"
}
