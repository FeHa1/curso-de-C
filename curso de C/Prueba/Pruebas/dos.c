/*
1. Generar los primeros cuatro números perfectos. Los números perfectos son aquellos números que son iguales
   a la suma de sus divisores positivos (por ejemplo: 6=1+2+3).

2. Ingresar pares de números hasta que los dos sean cero, y contar cuántos pares de números sean amigos. 
   Los números amigos son aquellos números positivos tales que la suma de los divisores de uno es igual al 
   otro número y viceversa.

Ejemplo:
- los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110, que suman 284;
- los divisores de 284 son 1, 2, 4, 71 y 142, que suman 220. 220 y 284 son amigos.
*/


// 1.
#include <stdio.h>

int main()
{
    int num = 3, acum = 0, cont = 0, i; // siempre hay que definir las variables aca, despues del 'int'.

    while (cont < 4) // se pone '4' porque es la cantidad de numeros primos que quiero mostrar cuando imprima.
    {
        for(i = 1; i < num; i++) // no pongo 0 en la variable 'i' porque si divido todos los numeros que pasan por ahi por 0 da 0 siempre.
        // el 'for' va con ';' porque es una funcion que recibe parametros diferentes.
        {
            if (num % i == 0)
            {
                acum = acum + i;
            }
        } 

        if (acum == num)
        {
            cont = cont + 1;
            printf("\nEl numero perfecto es %d", num); // el '\n' es para acomodar los datos que se imprimen para que no queden todos juntos, sino uno debajo del otro.

        }

        num ++;
        acum = 0;

    }

    return 0;
}



// 2. 
#include <stdio.h>

int main()
{
    int num1, num2, acum1 = 0, acum2 = 0, cont = 0, i; // siempre hay que definir las variables aca, despues del 'int'.
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese un numero: ");
    scanf("%d", &num2);

    while (num1 > 0 && num2 > 0)
    {
        for(i = 1; i < num1; i++) // no pongo 0 en la variable 'i' porque si divido todos los numeros que pasan por ahi por 0 da 0 siempre.
        // el 'for' va con ';' porque es una funcion que recibe parametros diferentes.
        {
            if (num1 % i == 0)
            {
                acum1 = acum1 + i;
            }
        } 

        for(i = 1; i < num2; i++) 
        {
            if (num2 % i == 0)
            {
                acum2 = acum2 + i;
            }
        } 

        if (acum1 == num2 && acum2 == num1)
        {
            cont = cont + 1;
            printf("\nLos numeros amigos son %d %d", num1, num2); // aca se ponen dos '%d' para cada uno de los 'num'
        }

        acum1 = 0;
        acum2 = 0;
        printf("\nIngrese un numero: ");
        scanf("%d", &num1);
        printf("\nIngrese un numero: ");
        scanf("%d", &num2);

    }

    return 0;
}



/*Ejemplo del ejercicio 2 pero ahora con funciones asi no se repiten*/

#include <stdio.h>

int divisores (int a)  // pongo el 'a' porque de todas maneras no hace falta definirla al lado del 'int' de abajo.*
// va 'int' adelante para que entienda que va a ser un numero entero
// y dentro del parametro tambien va 'int' porque hay que definir que va a ser cada tipo de dato.
{
    int i, acum = 0;   // hay que definir las variables antes de empezar, y tampoco defino 'a' por lo que aclare arriba*
    
    for(i = 1; i < a; i++) 
        {
            if (a % i == 0)
            {
                acum = acum + i;
            }
        } 
    return acum; 
}

int main()
{
    int num1, num2, b, c, i; // siempre hay que definir las variables aca, despues del 'int'.
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese un numero: ");
    scanf("%d", &num2);

    while (num1 > 0 && num2 > 0)
    {
        b = divisores(num1); //aca lo pongo en una variable porque 'divisores' ya tiene un valor, por ende lo dirijo con la variable 'b'
        c = divisores(num2); 
       

        if (b == num2 && c == num1)
        {
            printf("\nLos numeros amigos son %d %d", num1, num2); // aca se ponen dos '%d' para cada uno de los 'num'
        }

        printf("\nIngrese un numero: ");
        scanf("%d", &num1);
        printf("\nIngrese un numero: ");
        scanf("%d", &num2);

    }

    return 0;
}



/*Esto es un ejemplo de como usar los arreglos (los cuales vendrian a ser los 'def' en Python)*/

#include <stdio.h>

void cargar(int a[], int n) // se usan dos int porque hay que declarar cada uno de los datos ingresados
// se utiliza 'void' como el 'def'. Tambien se pueden usar otros pero no sirven para este ejemplo
{
    int i; 
    for (i = 0; i < n; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &a[i]);
    }
}    

void mostrar(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEl valor es: %d",a[i]);
    }
}

int main()
{
    int vec[30], dim; // el 'dim' es para que el usuario ingrese la cantidad de elementos que va a ingresar en el arreglo
    // y el 'vec' es para la cantidad de lugares que guardo por las dudas de que quieran ingresarse esa suma de numeros, 
    // aunque no es necesario que se ingresen 30 si o si, es solo el maximo de numeros que le permito ingresar.
    
    printf("Ingrese la dimension: ");
    scanf("%d", &dim);
    cargar(vec, dim);
    mostrar(vec,dim);
    
    return 0;
}





/* Esto es otro ejemplo de los arreglos */

#include <stdio.h> 

int cargar (int vec[])
{
    int i, num, j = 0;
    for (i = 0; i < 10; i++) // aca pongo 10 porque son solo 10 los que quiero cargar
    {
        scanf("%d", &num);
        if (num%2 == 0)
        {
            vec[j] = num; // le pongo 'j = 0' para que el primer numero que se ingresa quede en la primera posicion del arreglo 
            j++;
        }
    }
    return j; // devolvemos 'j' ya que es la dimension
}

void mostrar (int vec[], int dim)
{
    int i;
    for (i = 0; i < dim; i++) // ahora quiero que el valor de 'i' sea comparado con la dimension que le pase, por eso saque el10 que iba antes
    {
        printf("%d", vec[i]);
    }
    
}



int main()
{
    int vec[20], dim;
    dim = cargar(vec);
    printf("\nLa dimension del arreglo es %d");
    mostrar(vec, dim); 
    
    return 0;
}



/* Aca vemos un ejemplo de como podemos hacer operaciones sin funciones, en este caso, ordenar un arreglo de menor a mayor */

#include <stdio.h> 

int cargar (int vec[])
{
    int i, num, j = 0;
    for (i = 0; i < 10; i++) // aca pongo 10 porque son solo 10 los que quiero cargar
    {
        scanf("%d", &num);
        if (num%2 == 0)
        {
            vec[j] = num; // le pongo 'j = 0' para que el primer numero que se ingresa quede en la primera posicion del arreglo 
            j++;
        }
    }
    return j; // devolvemos 'j' ya que es la dimension
}


void ordenar(int vec[], int dim)
{
    int i, j, aux;
    for (i = 0; i < dim; i++)
    {
        for (j = i + 1; j < dim; j++)
        {
            if (vec[i] < vec[j]) // aca lo estoy ordenando de mayor a menor, en caso de querer hacerlo al revez cambio el '<' por '>'.
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }   
        }
    }
}



void mostrar (int vec[], int dim)
{
    int i;
    for (i = 0; i < dim; i++) // ahora quiero que el valor de 'i' sea comparado con la dimension que le pase, por eso saque el10 que iba antes
    {
        printf("\n%d", vec[i]);
    }
    
}


 
int main()
{
    int vec[20], dim;
    dim = cargar(vec);
    printf("\nLa dimension del arreglo es %d", dim);
    mostrar(vec, dim); 
    ordenar(vec, dim);
    mostrar(vec, dim); // lo pongo de vuelta al mostrar para ver como me lo ordeno la variable 'ordenar'
    
    return 0;
}



/*Este me devuelve todos los numeros del arreglo con posicion y todo*/

#include <stdio.h>

void cargar (int a[],int dim)
{
    int i;
    
    for (i=0;i<dim;i++)
    {
        printf("\nIngrese los valor: ");
        scanf("%d",&a[i]);
    }
    
    return;
}


void mostrar (int a[],int dim)
{
    int i;
    
    for (i=0;i<dim;i++)
    {
        printf("\n %d %d",i, a[i]);
    }
    
    return;
}


int main()
{
    int vec[40],dim;
    
    printf("ingrese cantidad de valores del arreglo: ");
    scanf("%d",&dim);
    cargar(vec,dim);
    mostrar(vec,dim);
    
    return 0;
}
    


/*Esto es un ejemplo de como devolver numeros pares en un arreglo, con posicion y todo*/

#include <stdio.h>

int cargar (int a[])
{
    int i=0, num;
    printf("\nIngrese numeros y cortar en 0: ");
    scanf("%d",&num);
    
    while (num > 0)
    {
        if (num%2==0)
        {
            a[i]=num;
            i++;
        }
        printf("\nIngrese numeros y cortar en 0: ");
        scanf("%d",&num);
    }
    
    return i;
    
}

void mostrar (int a[],int dim)
{
    int i;
    for (i=0;i<dim;i++)
    {
        printf("\n %d %d",i, a[i]);
    }
    
    //return;
}

int main()
{
    int vec[100], dim;
    dim=cargar(vec);
    mostrar(vec,dim);
    
    return 0;
}



/*Esto es un ejemplo de como agregar valores a un arreglo, mas especificamente a la mitad del arreglo, siempre y cuando estemos 
hablando de valores pares (dado que esa es la condicion del ejemplo, no es porque siempre sea asi)*/

/*Ingresar numeros hasta que se ingrese un cero y devolver los valores pares del arreglo*/

#include <stdio.h>

int cargar (int a[]) //el cargar lo hago de tipo "int" para que me devuelva los elementos pares del arreglo, como lo dice en la consigna
{
    int i=0, num;
    
    printf("\n ingrese valor: ");
    scanf("%d",&num);
    while (num > 0)
    {
        if (num%2==0)
        {
            a[i]=num;
            i++;
        }
        
        printf("\n ingrese valor: ");
        scanf("%d",&num);
    }
    
    return i; //retorno algo porque es una variable de tipo "int" 
}

void mostrar (int a[],int dim)
{
    int i;
    for (i=0;i<dim;i++)
    {
        printf("\n %d %d",i, a[i]); //esto es para que se muestre la posicion en el arreglo y el valor en cada cajita
    }
    
    return;
}

void insertar(int a[],int dim)
{
    int i;
    for (i=dim; i>dim/2; i--) //se decrementa porque va desde el ultimo valor de la matriz hasta el primero
    {
        a[i]=a[i-1];
    }
    
    a[dim/2]=0; //esto lo que va a hacer es insertar un 0 en la mitad del arreglo nuevo
    
    return;
    
}

int main()
{
    int vec[100], dim;
    dim=cargar(vec);
    mostrar(vec,dim);
    insertar(vec,dim);
    printf("\n el arreglo con insercion es: ");
    mostrar(vec,dim+1); //este mostrar es para el arreglo con la insercion, por eso es "dim+1", es el arreglo mas 1 lugar para 
                        //agregar el numero
    
    return 0;
}



/*Esto es un ejemplo de como agregar valores a un arreglo*/

/*Ingresar numeros hasta que se ingrese un cero y devolver los valores pares del arreglo*/

#include <stdio.h>

int cargar (int a[]) //el cargar lo hago de tipo "int" para que me devuelva los elementos pares del arreglo, como lo dice en la consigna
{
    int i=0, num;
    
    printf("\n ingrese valor: ");
    scanf("%d",&num);
    while (num > 0)
    {
        if (num%2==0)
        {
            a[i]=num;
            i++;
        }
        
        printf("\n ingrese valor: ");
        scanf("%d",&num);
    }
    
    return i; //retorno algo porque es una variable de tipo "int" 
}

void mostrar (int a[],int dim)
{
    int i;
    for (i=0;i<dim;i++)
    {
        printf("\n %d %d",i, a[i]);
    }
    
    return;
}

void insertar(int a[],int dim)
{
    int i;
    for (i=dim; i>0; i--) //el "i>0" es para que inserte un numero al principio del arreglo
    {
        a[i]=a[i-1];
    }
    
    //a[0]=1000; //esto era un ejemplo para mostrar que la posicion 0 tome el valor de 1000, pero si lo comento para que no lo tome, 
                 //va a tomar el primer valor ingresado y lo va a repetir en la posicion 0 y 1, ya que tiene que ir si o si algo porque 
                 //los estoy moviendo una posicion a todos los numeros
    return;
    
}

int main()
{
    int vec[100], dim;
    dim=cargar(vec);
    mostrar(vec,dim);
    insertar(vec,dim);
    printf("\n el arreglo con insercion es: ");
    mostrar(vec,dim+1); //este mostrar es para el arreglo con la insercion, por eso es "dim+1", es el arreglo mas 1 lugar para agregar el numero
    
    return 0;
}



/*Ejemplo de arreglos ordenados de mayor a menor con la condicion de que sean pares*/

#include <stdio.h>

int cargar (int a[])
{
    int i=0,num;
    printf("\n ingrese valor: ");
    scanf("%d",&num);
    while (num > 0)
    {
        if (num%2==0)
        {
            a[i]=num;
            i++;
        }
        printf("\n ingrese valor: ");
        scanf("%d",&num);
    }
    
    return i;
}


void mostrar (int a[],int dim)
{
    int i;
    for (i=0;i<dim;i++)
    {
        printf("\n %d %d",i, a[i]);
    }
    
    return;
}


void insertar(int a[],int dim)
{
    int i;
    for (i=dim; i>0;i--)
    {
        a[i]=a[i-1];
    }
    
    a[0]=1000; //esto era un ejemplo para mostrar que la posicion 0 tome el valor de 1000, pero si lo comento para que no lo tome, 
                //va a tomar el primer valor ingresado y lo va a repetir en la posicion 0 y 1, ya que tiene que ir si o si algo porque 
                //los estoy moviendo una posicion a todos los numeros
    return;
}


void ordenar(int a[],int dim)
{
    int i,j,aux;
    for(i=0;i<dim;i++)
    {
        for(j=i+1;j<dim;j++)
        {
            if(a[i]<a[j]) // esto hace que se acomode de mayor a menor
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
    
    return;
}


int main()
{
    int vec[100],dim;dim=cargar(vec);
    mostrar(vec,dim);
    insertar(vec,dim);
    printf("\n el arreglo con insercion es: ");
    mostrar(vec,dim+1);
    ordenar(vec,dim+1);
    printf("\n el arreglo ordenado: ");
    mostrar(vec,dim+1);
    
    return 0;
}
        


/*Ejemplo de arreglos ordenados de menor a mayor, siempre y cuando sean pares*/

#include <stdio.h>

int cargar (int a[])
{
    int i = 0, num;
    printf("\n ingrese valor: ");
    scanf("%d",&num);
    while (num > 0)
    {
        if (num%2==0)
        {
            a[i]=num;
            i++;
        }
        printf("\n ingrese valor: ");
        scanf("%d",&num);
    }
    
    return i;
}


void mostrar (int a[],int dim)
{
    int i;
    for (i=0;i<dim;i++)
    {
        printf("\n %d %d",i, a[i]);
    }
    
    return;
}


void insertar(int a[],int dim)
{
    int i;
    for (i=dim; i>0;i--)
    {
        a[i]=a[i-1];
    }
    
    a[0]=1000;
    return;
}


void ordenar(int a[],int dim)
{
    int i,j,aux;
    for(i=0;i<dim;i++)
    {
        for(j=i+1;j<dim;j++)
        {
            if(a[i]>a[j]) //esto hace que se acomode de menor a mayor
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
    
    return;
}


int main()
{
    int vec[100],dim;dim=cargar(vec);
    mostrar(vec,dim);
    insertar(vec,dim);
    printf("\n el arreglo con insercion es: ");
    mostrar(vec,dim+1);
    ordenar(vec,dim+1);
    printf("\n el arreglo ordenado: ");
    mostrar(vec,dim+1);
    
    return 0;
}
        
/*******************************************************************************************************************************************/

//metodo de burbija: para ordenar de mayor a menor los numeros de un arreglo.

void ordenar (int vec[], int dim)
{
    int i, j; 
    for(i=0; i<dim; i++)
    {
        for(j=i+1; j<dim; j++)
        {
            if(vec[i] > vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j]; 
                vec[j]=aux;
            }
        }
    }
}


//matrices (ejemplos de clase)

/* Cargar una matriz de n*n de números enteros. Mostrar:
a) la sumatoria de los elementos de la 2º fila. */

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

void mayores(int mat[10][10], int dim)
{
    int i, j; 

    for(i=0; i<dim; i++)
    {
        if(mat[i][1] > mayor) //le pongo 1 porque quiero los valores de la segunda fila (si buscase la primera seria 0)
        {
            mayor=mat[i][1];
        }
    }

    printf("\nEl mayor valor de la segunda fila es: %d", mayor);
}

void mostrar(int mat[10][10], dim)
{
    int i, j; 
    
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            printf("\nLos valores de la matriz son: %d", mat[i][j]);
        }
    }
}

int main()
{
    int mat[10][10], dim; 
    printf("\nIngrese la dimension de la matriz: ");
    scanf("%d", &dim);
    cargar(mat, dim);
    mostrar(mat, dim);
    mayores(mat, dim);

    return 0;
}


/* LO VOY GUARDADNO ACA POR AHORA PERO DESPUES LO TENGO QUE PONER EN LA CARPETA DE LA GUIA DE EJERCICIOS
/*
Cargar una matriz de n*n de números enteros y mostrar:
a) la matriz transpuesta
b) El promedio de los elementos de las dos diagonales (principal y secundaria)
c) Multiplicar la matriz por su transpuesta.
d) Determinar cuántos números primos hay en la matriz.
*/

// a)
/*
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


void trans(int mat[10][10], int dim)
{
    int i, j;
    for()
    
    mat[i][j] = mat[j][i];
}


void mostrar(int mat[10][10], dim)
{
    int i, j; 
    
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            printf("\nLos valores de la matriz son: %d", mat[i][j]);
        }
    }
}


int main()
{
    int mat[10][10], dim; 
    printf("\nIngrese la dimension de la matriz: ");
    scanf("%d", &dim);
    cargar(mat, dim);
    mostrar(mat, dim);
    
    return 0;
}

*/

/*
Cargar una matriz de n*n de números enteros. Mostrar:
a) si la matriz es simétrica.
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


void simetrica(int mat[10][10], int dim)
{
    int i, j, cont=0;
    
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            if(mat[i][j] == mat[j][i])
            {
                cont++;
            }
        }
    }
    
    if(cont =dim*dim)
    {
        printf("\nLa matriz es simetrica.");
    }
    
    else
    {
        printf("\nLa matriz no es simetrica.");
    }
}


void mostrar(int mat[10][10], int dim)
{
    int i, j; 
    
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            printf("\nLos valores de la matriz son: %d", mat[i][j]);
        }
    }
}


int main()
{
    int mat[10][10], dim; 
    printf("\nIngrese la dimension de la matriz: ");
    scanf("%d", &dim);
    cargar(mat, dim);
    mostrar(mat, dim);
    simetrica(mat, dim);
    
    return 0;
}


//punteros (ejemplos de clase)

//Contamos la cantidad de "a" que hay

#include <stdio.h> 

int main()
{
    int c, cont=0;
    
    printf("\nIngrese la frase: ");
    c=getchar(); 
    while(c != '.')
    {
        putchar(c); // esto lo que va a hacer es devolverme la letra en la cual se asigno "c", y se necesita esta funcion porque "getchar()" 
                    // no devuelve la letra sino el valor numerico 
        if(c=='a')
        {
            cont++;
            c=getchar();
        }
    }

    printf("\nLa cantidad de A es: %d", cont); 
}



//Contamos las palabras que 

#include <stdio.h>

int main()
{
    int c, cont=0;
    
    printf("\nIngrese la frase: ");
    c=getchar(); 
    while(c != '.')
    {
        while(c != '.' && c == ' ')
        {
            aux=c;
            c=getchar; 
        }
        if(c=='a')
        {
            cont++;
        }

        c=getchar();
    }

    printf("\nLa cantidad de A es: %d", cont); 
}



/*
Desarrollar un algoritmo y luego codificarlo en C para cada problema.
1. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras
tienen más de 3 letras.
*/


#include <stdio.h>

int main()
{
    int c, cont1=0, cont2=0; 
    
    printf("\nIngrese la frase: ");
    c=getchar();    
    
    while(c != '.')
    {
        while(c != '.' && c != ' ')
        {
            cont1++;
            
            if(cont1 > 3)
            {
                cont2++;
            }
            
            c=getchar();
        }
        
        cont1=0; //lo pongo en 0 cosa de que cuando sale de una palabra vuelva a contar cuantas letras cumplen la condicion en la nueva palabra
        
    
        if(c != '.')
        {
            c=getchar();
        }
    }
    
   
    printf("Las palabras con mas de 3 letras son: %d", cont2);
}



//2. Leer un texto caracter a caracter, terminado en PUNTO. Mostrar el texto con un
//   blanco y eliminando las palabras de 1 letra.

#include <stdio.h>

int main ()
{
    int c, cont=0;
    
    printf("\nIngrese la frase: ");
    c=getchar();

    while(c != '.')
    {
        while(c != '.' && c == ' ')
        {
            cont++;
            
            if(cont > 2)
            {
                putchar(c);
            }
            
            c=getchar();
        }
        
        cont=0; //lo pongo en 0 cosa de que cuando sale de una palabra vuelva a contar cuantas letras cumplen la condicion en la nueva palabra
        
        if(c != '.')
        {
            c=getchar();
        }
        
        putchar(' ');
        c=getchar();
    }

    putchar(c); 
}

//FALTAAAAAAA PREGUNTAR A LA PROFE POR PRONTO