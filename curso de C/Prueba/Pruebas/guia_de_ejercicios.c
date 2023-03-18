/* 1. Calcular el índice de masa corporal ingresando el peso de una persona en kilos y su
estatura en metros. Este índice se obtiene realizando el cociente entre el peso y el
cuadrado de la estatura.*/ 

#include <stdio.h> 

int main()
{
    float metros = 0, peso = 0, indice, multiplicacion; // pongo "float" para que me devuelva nueros con coma. 
    
    printf("\nIngrese el peso en kg: ");
    scanf("%f", &peso); // se usa "%f" porque estoy pidiendo numeros con coma
    
    printf("\nIngrese la estatura en mt: ");
    scanf("%f", &metros); // se usa "%f" porque estoy pidiendo numeros con coma
    
    
    multiplicacion = metros*metros; // esto se puede hacer en una sola linea
    indice = peso/multiplicacion; // esto se puede hacer en una sola linea
    
    printf("\nEl indice obtenido es: %f", indice); // aca se pone "%f" porque es un numero real (numero con coma o float)
                                                   // en otros ejemplos esta el "%d" porque devuelve enteros 
    
    return 0;
}


/* 2. Ingresar el día y la cotización del dólar durante un mes. Calcular y mostrar el día
donde hubo la mayor cotización.*/ 

#include <stdio.h> 

int main()
{
    int cont = 1, dolar = 0, mayor = 0, dia; 
    {
        while (cont <= 30) // le pongo "<=" porque el "cont" empieza en 1, entonces si justo el mayor valor lo pusieron en el primer dia a la hora de imprimir me pone dia 0 y no tiene logica.
        {
            printf("\nIngrese el valor del dolar del dia de hoy: ");
            scanf("%d", &dolar);

            if (mayor < dolar)
            {
                mayor = dolar;
                dia = cont; 

            }

            cont ++; 
        }

        printf("\nEl mayor valor que tomo el dolar fue del dia: %d", dia);
        printf("\nEl mayor numero que alcanzo el dolar fue de: %d", mayor);
    }
    
    return 0; 
}


/* 3. Se ingresan la cantidad de autos vendidos en los últimos 9 años. Calcular y mostrar:
a) El año que se vendieron la mayor cantidad de autos.
b) La cantidad total de autos vendidos*/ //aca hago un acumulador 


#include <stdio.h>

int main()
{
    int cont = 1, autos = 0, mayor = 0, acum = 0, year;
    
    for (cont = 1; cont <= 9; cont ++)            //while (cont <= 9)
    {
        printf("\n¿Cuantos autos se vendieron este año?: ");
        scanf("%d", &autos);
        
        if (mayor < autos) 
        {
            mayor = autos; // la asignacion siempre es hacia el de la izquierda
            year = cont;
        }
        
        //cont ++;
        acum += autos;
        
    }
    
    printf("\nEl año en el que se vendieron la mayor cantidad de autos fue: %d", year);
    printf("\nLa cantidad total de autos vendidos fue de: %d", acum);

    
    
    return 0;
}


/*
Ingresar diez números enteros y cargar un vector con aquellos números positivos. Si tiene elementos, mostrarlo; sino mostrar leyenda. 
Si tiene elementos:

a) Insertar el consecutivo de aquellos números pares.
b) Generar otro arreglo con los múltiplos de 3 pares y mostrarlo
c) Eliminar él o los elementos máximos y desplazar los elementos hacia izquierda.
*/ 

#include <stdio.h> 

void cargar(int vec[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("\nIngrese 10 numeros: ");
        scanf("%d", &vec[i]);
    }
}

void mostrar(int vec[])
{
    int i; 
    for (i = 0; i < 10; i++)
    {
        if (i > 0)
        {
            printf("\nLos numeros positivos son: %d", i);
        }
    }
}

void numPares(int vec[])
{
    int i, pares, n;
    for (i = 0; i < 10; i++)
    {
        printf("\nIntroduzca 10 numeros: ");
        scanf("%d", &n); 
        
        if (n % 2 == 0)
        {
            pares++;
        }
    }
    
    printf("\nLos numeros pares son: %d", pares);
    
}

void numMultTres(int vec[])
{
    int i, MulTres, num;
    for (i = 0; i < 10; i++)
    {
        printf("\nIntroduzca 10 numeros: ");
        scanf("%d", &num);
        
        if (num%3 == 0 && num%2 == 0)
        {
            MulTres++;
        }
        
    }
    printf("\nLos numeros divislbes por 3 son: %d", MulTres);
    
}





int main()
{
    cargar(vec);
    mostrar(vec);
    numPares(vec);
    numMultTres(vec);
    
    return 0;
}

/*NO SUPE COMO HACER LO DE LOS ELEMENTOS MAXIMOS*/

 






/*Se ingresan los datos de vuelos a distintas ciudades para obtener estadísticas. Para
ello se pide: Día de vuelo, nombre de la ciudad, capacidad del avión y cantidad de
pasajes vendidos. Estos datos se ingresan hasta que el día de vuelo sea cero.
 Mostrar los datos ingresados.
 Calcular y mostrar:
a) La ciudad y el día con la mayor cantidad de pasajes vendidos
b) El porcentaje de pasajes vendidos de cada ciudad.
c) Mostar las ciudades en forma ordenada de menor a mayor según la
cantidad de pasajes vendidos */
/*
#include <stdio.h> 

void porcentaje(float capa, float vendi)
{
    float p;
    p = vendi *100 /capa;
    printf(p);

    return ;
}



int main()
{
    float capa, vendi, p, dia;
    char ciudad[20];

    printf("Ingrese el dia donde tomo el vuelo: ");
    scanf("%d", &dia);

    while (dia != 0)
    {
        printf("\nIngrese la ciudad a donde quiera viajar: ");
        scanf("%s", &ciudad);
        printf("\nIngrese la cantidad de pasajes vendidos: ");
        scanf("%f", &vendi);
        printf("\nIngrese la capacidad del avion: ");
        scanf("%f", &capa);
        //por = porcentaje(capa, vendi);
        porcentaje(capa, vendi);
        //printf(por, "porcentaje %f"); // ver este que no sale
        printf("\nIngrese el dia donde tomo el vuelo: ");
        scanf("%d", &dia);
        
        //printf(porcentaje);

    }


    return 0;
}
*/

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

void cargar (int mat[10][10], int filas, int columnas)
{
    int i, j, num;
    
    for (i = 0; i < filas; i ++)
    {
        
        for (j = 0; j < columnas; j ++)
        {
            printf("Ingrese los numeros que va a tener la matriz: ");
            scanf("%d", &num);
            mat[i][j] = num;
            
        }
    }
}

void mayores (int mat[10][10], int filas, int  columnas)
{
    int i, j, mayor = 0;
    j = 1; // esto significa que va a quedarse en la columna dos, lo que va a ir recorriendo los numeros es "i".
           // ¨j = 1¨ porque los indices comienzan en la posicion 0.

    for (i = 0; i < filas; i ++) // uso un "for" solamente porque solo necestio recorrer las filas, la columna es igual a 2
    {
        if (mayor < mat[i][j])
        {
            mayor = mat[i][j];
        }
    }
    printf("\nEl mayor elemento de la segunda columna es: %d", mayor);

}

void multiplos (int mat [10][10], int filas, int columnas)
{
    int i, j, cont2 = 0, acum2 = 0;
    float promedio; // esta en float porque es una division y pueden haber numeros con coma

    for (i = 0; i < filas; i ++)
    {
        for (j = 0; j < columnas; j ++)
        {
            if (mat[i][j] % 5 == 0)
            {
                cont2 ++;
                acum2 += mat[i][j];
            }

        }
    }
    promedio = acum2/cont2; 
    printf("\nEste es el promedio de multiplos de 5: %f", promedio);
   
}

void sumatoria (int mat[10][10], int filas, int columnas)
{
    int i, j, sum1 = 0;
    i = 1; // esto significa que va a quedarse en la fila dos, lo que va a ir recorriendo los numeros es "j"
           // ¨i = 1¨ porque los indices comienzan en la posicion 0.

    for (j = 0; j < columnas; j ++) // uso un "for" solamente porque solo necestio recorrer las columnas, la fila es igual a 2     
    {
        sum1 += mat[i][j];
    }
    
    printf("\nLa suma de los elementos de la segunda fila es: %d", sum1);
       
}


void diagonal (int mat[10][10], int filas, int columnas)
{
    int i, j, sum2 = 0;

    for (i = 0; i < filas; i ++)
    {
        sum2 += mat[i][i]; // aca estamos diciendo que el numero de filas sea igual al numero de columnas
    }

    printf("\nLa suma de los elementos de la diagonal principal es: %d", sum2);

}


void minimo (int mat[10][10], int filas, int columnas)
{
    int i, j, menor = 0;

    for (i = 0; i < filas; i ++)
    {
        for (j = 0; j < columnas; j ++)
        {
            if (mat[i][j] < menor)
            {
                menor = mat[i][j]; // NO PASA POR ACA, REVISAR
                printf("\npaso");
            }
        }

        printf("\nEl menor elemento de cada fila de la matriz es: %d", menor);
    }
}


void diag_secu (int mat[10][10], int filas, int columnas)
{
    int i, j = 0;

    for (i = filas - 1; i >= 0; i --) // este es para que empiece en la ultima fila y vaya creciendo 
    {
        printf("\nLos valores de la diagonal secundaria son: %d", mat[i][j]);
        // pongo el printf aca adentro para que vaya imprimiendo cada uno de los valores, si lo pongo afuera solo me va a mostrar el ultimo 
        
        j += 1; // este es para que vaya aumentando el valor de la columna
                // lo incremento abajo porque los indices empiezan en 0
    }

 
}


void simetrica (int mat[10][10], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i ++)
    {
        for (j = 0; j < columnas; j ++)
        {
            if (i != j)
            {
                if (mat[i][j] == mat[j][i])
                {
                    printf("\nEsta matriz es simetrica, los valores son: %d", mat[i][j]);
                }

                else
                {
                    printf("\nEsta matriz no es simetrica.");
                }
            }    
        }
    }
}


void mostrar (int mat[10][10], int filas, int columnas)
{
    int i, j;
    
    for (i = 0; i < filas; i ++)
    {
        printf("\n");
        
        for (j = 0; j < columnas; j ++)
        {
            printf("%d \t", mat[i][j]);
            
        }
        
    }    
}


int main()
{
    int mat[10][10], filas, columnas;
    
    printf("Ingrese la cantidad de filas (menor a 10): ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas (menor a 10): ");
    scanf("%d", &columnas);
    cargar(mat, filas, columnas);
    mostrar(mat, filas, columnas);
    mayores(mat, filas, columnas);
    multiplos(mat, filas, columnas);
    sumatoria(mat, filas, columnas);
    minimo(mat, filas, columnas);

    if (filas = columnas) // esto es por las dudas que no sea cuadrada
    {
        diagonal(mat, filas, columnas);
    }   
    else
    {
        printf("\nNo se puede sacar la diagonal principal porque no es una matriz cuadrada");
    }
    
    
    
    if (filas = columnas) // esto es por las dudas que no sea cuadrada
    {
        diag_secu(mat, filas, columnas);
    }   
    else
    {
        printf("\nNo se puede sacar la diagonal secundaria porque no es una matriz cuadrada");
    }
    
    return 0;
}


/*
2. Cargar una matriz de n*n de números enteros y mostrar:
a) la matriz transpuesta
b) El promedio de los elementos de las dos diagonales (principal y secundaria)
c) Multiplicar la matriz por su transpuesta.
d) Determinar cuántos números primos hay en la matriz.
*/

#include <stdio.h>

void cargar (int mat[10][10], int filas, int columnas)
{
    int i, j, num;
    
    for (i = 0; i < filas; i ++)
    {
        
        for (j = 0; j < columnas; j ++)
        {
            printf("Ingrese los numeros que va a tener la matriz: ");
            scanf("%d", &num);
            mat[i][j] = num;
            
        }
    }
}

void trans (int mat[10][10], int filas, int columnas, int transpuesta[10][10])
{
    int i, j, t;

    for (i = 0; i < filas; i ++)
    {
        
        for (j = 0; j < columnas; j ++)
        {
            transpuesta[j][i] = mat[i][j]; // aca creo la matriz transpuesta, y hacemos que no se pierda la original
                                           // poniendo otra variable de matriz (en este caso "transpuesta[j][i]") 
        }
    }

}


void multiplicar (int mat[10][10], int filas, int columnas, int transpuesta[10][10]) // FALTA ESTE PORQUE NO DA (el "for j")
{
    int i, j, acum = 0, resu;

    for (i = 0; i < filas; i ++)
    {
        for (j = 0; j < columnas; j ++)
        {

            printf("paso");
            resu = mat[i][j]* transpuesta[j][i]; 
            acum += resu;
            printf(i, j);
            
        }
        printf(acum);
        
    }
}


void diagonales (int mat[10][10], int filas, int columnas)
{
    int i, j, sum1 = 0, cont1 = 0, k = 0, sum2 = 0, cont2 = 0; // la "k" juega el rol de la "j" pero para hacer todo en una misma funcion (para la de abajo)
    float prom1, prom2;

    for (i = 0; i < filas; i ++)
    {
        sum1 += mat[i][i]; // aca estamos diciendo que el numero de filas sea igual al numero de columnas
        cont1 += 1;
    }

    prom1 = sum1/cont1;
    printf("\nEl promedio de los elementos de la diagonal principal es: %f", prom1);


    for (i = filas - 1; i >= 0; i --) // este es para que empiece en la ultima fila y vaya creciendo 
    {
        sum2 += mat[i][k];
        cont2 += 1;
        k += 1; // este es para que vaya aumentando el valor de la columna
                // lo incremento abajo porque los indices empiezan en 0
    }

    prom2 = sum2/cont2;
    printf("\nEl promedio de los elementos de la diagonal secundaria es: %f", prom2);
}



void mostrar (int mat[10][10], int filas, int columnas)
{
    int i, j;
    
    for (i = 0; i < filas; i ++)
    {
        printf("\n");
        
        for (j = 0; j < columnas; j ++)
        {
            printf("%d \t", mat[i][j]);
            
        }
        
    }
}



int main()
{
    int mat[10][10], filas, columnas, transpuesta[10][10];
    
    printf("Ingrese la cantidad de filas (menor a 10): ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas (menor a 10): ");
    scanf("%d", &columnas);
    cargar(mat, filas, columnas);
    mostrar(mat, filas, columnas);
    trans(mat, filas, columnas, transpuesta); 
    printf("\nEsta es la matriz transpuesta:\n");
    mostrar(transpuesta, filas, columnas); // ese es para mostrrar la transpuesta
    diagonales(mat, filas, columnas);
    printf("\nEste es el resultado de la multiplicacion de la matriz y su transpuesta: ");
    multiplicar(mat, filas, columnas, transpuesta);

    return 0;
}




/*
AUTOEVALUACION MATRIZ

Desarrollar un programa en C (con funciones) que permita cargar una matriz de nxn elementos. Mostrarla. Determinar si es una matriz antisimétrica.
Una matriz antisimétrica es aquella matriz cuadrada que coincide con la opuesta de su traspuesta.
*/


#include <stdio.h>

void cargar(int mat[3][3], int filas, int columnas)
{
    int i, j, num;
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            printf("\nIngrese los numeros para una matriz de 9 numeros: ");
            scanf("%d", &num);
            mat[i][j] = num;
        }
    }
}



void anti_sim(int mat[3][3], int filas, int columnas)
{
    int i, j, cont;
    
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {   
            if (mat[i][j] == mat[j][i]*-1)                          
            {
                cont++;
            }
        }
    }

    if (cont == filas*columnas)
    {
        printf ("Es antisimetrica");
    }

    else
    {
        printf ("NO es antisimetrica");
    }
}



void mostrar(int mat[10][10], int filas, int columnas)
{
    int i, j;
    
    for (i = 0; i < filas; i ++)
    {
        printf("\n");
        
        for (j = 0; j < columnas; j ++)
        {
            printf("%d \t", mat[i][j]);
            
        }
    }
}



int main()
{
    int mat[3][3], filas, columnas;
    cargar(mat, filas, columnas);
    anti_sim(mat, filas, columnas);
    mostrar(mat, filas, columnas);
    
    return 0;
}

/* AUTOEVALUACION DE CARACTERES*/

/* 
Desarrollar un programa en C que permita leer un texto caracter a caracter terminado en punto.
a) Mostrar el texto con tres blancos de separación entre cada palabra.
b) Contar cuantas palabras comienzan con 'a' y terminan en 's'
c) Contar cuantas palabras hay con mas de 5 caracteres que contengan al menos 2 vocales 'a'
*/


#include <stdio.h>

int main()
{
    int c, cont_a = 0, cont_s = 0, aux_a, aux_s, cont_voc1 = 0, cont_voc2 = 0, cont_letra_a = 0, cont_letras = 0, cont = 0;
    printf("\nIngrese la frase: ");
    c = getchar();
    while(c != '.')
    {
        while(c == ' ' && c != '.')
        {
            c = getchar();
        }
        
        aux_a = c;
        cont_voc1 = 0;
       
        while(c != ' ' && c != '.') 
        {
            aux_s = c; 
            cont_voc1++;
            c = getchar();
        }
        
        while(c != ' ' && c != '.')
        {
            if(c == 'a')
            {
                cont_letra_a++;
            }

            cont++;
            c = getchar();
        }

        if(cont_letras > 5 && cont_letra_a > 2)
        {
            cont_voc2++;
        }

        if(aux_s == 's')
        {
            cont_s++;  
        }
        
        putchar(' '); 
        putchar(' '); // estos 3 "putchar" son para que entre cada palabra haya 3 espacion, es como si ocuparan un cierto lugar en la frase 
        putchar(' ');

        if(aux_a == 'a') 
        {
            cont_a++;
        }
        
        
    }

    printf("\nLas palabras que comienzan con A son %d y las que terminan con S son %d", cont_a, cont_s);
    printf("\nLas palabras que contienen mas de 5 caracteres y tienen mas de 2 A son: %d", cont_voc2);

    return 0;
}



/* AUTOEVALUACION DE RECURSIVIDAD */

/*
a) Dados dos números enteros A y B, calcule su potencia (AB) en forma recursiva.
b) Cargar una matriz de nxn elementos enteros. Mostrarla. Calcular la suma de los elementos de la
diagonal principal en forma recursiva.
*/








/* AUTOEVALUACION DE INSERTAR Y ELIMINAR LISTAS SIMPLEMENTE ENLAZADAS*/ 

/*
Mostrar dicha lista (la carga finaliza con 0 en el primer número ingresado).
Si la suma de los tres números del nodo es mayor a 20, insertar antes de cada nodo el doble de cada valor del nodo.
Generar una nueva lista con el promedio de cada nodo (es decir si el nodo contiene 3 4 5 se debe generar un nodo con 4).
Mostrar dicha lista.
*/


#include<stdio.h>
#include<stdlib.h>


Typedef struct lista
{
    int num1;
    int num2;
    int num3;
    struct lista *sig;

}nodo;


void cargar1(nodo *h)
{
    printf("\nIngrese un numero: ");
    scanf("%d", &h -> num1);
    if (h->num1==0)
    {
        h -> sig = NULL;
    }
    else
    {
        h->sig=(nodo*)malloc(sizeof(nodo));
        cargar1(h->sig);
    }
}


void cargar2(nodo *h)
{
    printf("\nIngrese un numero: ");
    scanf("%d", &h -> num2);
    if (h->num2==0)
    {
        h -> sig = NULL;
    }
    else
    {
        h->sig=(nodo*)malloc(sizeof(nodo));
        cargar2(h->sig);
    }
}


void cargar3(nodo *h)
{
    printf("\nIngrese un numero: ");
    scanf("%d", &h -> num3);
    if (h->num3==0)
    {
        h -> sig = NULL;
    }
    else
    {
        h->sig=(nodo*)malloc(sizeof(nodo));
        cargar3(h->sig);
    }
}


void mostrar1(nodo *h)
{
  if (h->sig != NULL)
  {
    printf("\nEl numero es: %d",h->num1);
    mostrar1(h->sig);
  }
}


void mostrar2(nodo *h)
{
  if (h->sig != NULL)
  {
    printf("\nEl numero es: %d",h->num2);
    mostrar2(h->sig);
  }
}


void mostrar3(nodo *h)
{
  if (h->sig != NULL)
  {
    printf("\nEl numero es: %d",h->num3);
    mostrar3(h->sig);
  }
}


void insertar(nodo *h)
{
    nodo *a = NULL;
    while(h -> sig != NULL)
    {
        if (h -> num1 + h -> num2 + h -> num3 > 20)
        {
            a = (nodo *)malloc(sizeof(nodo));
            a -> num1 *2;
            a -> num2 *2;
            a -> num3 *2;
            a -> sig = h;
            h = a;
        }
        
        return h;
    }
}


int main()
{
    nodo *p = NULL;
    p = (nodo *)malloc(sizeof(nodo));
    cargar1(p);
    mostrar1(p);
    
    cargar2(p);
    mostrar2(p);
    
    cargar3(p);
    mostrar3(p);
    
    p = insertar(p);
    printf("\nLos nodos con su doble quedan en: ")
    
    return 0;
}





/*
a) Crear y mostrar la lista con numeros enteros.
b) Insertar en otra lista los numeros impares y mostrarla.
c) Eliminar todos los valores menores al promedio de la lista original en la lista de 
   numeros impares y mostrarla.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
    int num;
    struct lista *sig;
}nodol;


nodol *insertar_numeros(nodol *q)
{
    nodol *a = NULL;
    if (q -> num % 2 != 0)
    {
        a = (nodol *)malloc(sizeof(nodol));
        a = q -> sig;
        q = a;
    }
    return q;
}


void crearlista(nodol *q)
{
    printf("\nIngrese numeros hasta cortar con un 0: ");
    scanf("%d", &q -> num);
    
    if (q -> num == 0)
    {
        q -> sig = NULL;
    }
    else 
    {
        q -> sig = (nodol *)malloc(sizeof(nodol));
        crearlista(q -> sig);
    }
}


void mostrarlista(nodol *q)
{
    if (q -> sig != NULL)
    {
        printf("\nLos numeos enteros son: %d",q -> num);
        mostrarlista(q -> sig);
        
    }
}


int main()
{
    nodol *p = NULL;
    p = (nodol *)malloc(sizeof(nodol));
    crearlista(p);
    mostrarlista(p);
    p = insertar_numeros(p);
    
    
    return 0;
}





/*
Desarrollar un programa en C que permita cargar los datos en una multilista de la siguiente manera: 

a) En la lista principal se ingresan diferentes años, ordenados de menor a mayor y por cada año, el mes y cotización promedio del dolar durante ese mes. 
   La carga termina con 0 en ambos casos. Mostrar la mulitilista. 
   
b) Ingresar un el año actual, el mes actual y la cotización promedio del dolar e insertarlo en la multilista. 

c) Borrar de la multilista él o los meses donde le promedio de la cotización del dolar fue menor a 25 pesos. Mostrar la multilista.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct lista1
{
    int año;
    struct lista2 *l2;
    struct lista1 *sig1;
}nodo1;


typedef struct lista2
{
    int mes;
    float dolar;
    struct lista2 *sig2;
}nodo2;


void cargar_cotizacion(nodo2 *h)
{
    printf("\nINgrese el mes en formato numerico: ");
    scanf("%d", &h -> mes);
    printf("\nINgrese la cotizacion del dolar en ese mes: ");
    scanf("%f", &h -> dolar);
    
    if(h -> mes == 0)
    {
        h -> sig2 = NULL;
    }
    
    else
    {
        h -> sig2 = (nodo2*)malloc(sizeof(nodo2));
        
    }
    
    if(h -> dolar == 0)
    {
        h -> sig2 = NULL;
    }
    
    else
    {
        h -> sig2 = (nodo2*)malloc(sizeof(nodo2));
        
    }
}


void cargar(nodo1 *h)
{
    printf("\nIngrese año: ");
    scanf("%d", &h -> año);
    
    if(h -> año == 0)
    {
        h -> sig1 = NULL;
    }
    
    else
    {
        h -> l2 = (nodo2 *)malloc(sizeof(nodo2));
        cargar_cotizacion(h -> l2);
        h -> sig1 = (nodo1 *)malloc(sizeof(nodo1));
        cargar(h -> sig1);
        
        if(h -> año < h -> sig1)
        {
            h -> sig1 = h -> año;
        }
    }
}


void mostrar_cotizacion(nodo2 *h)
{
    if(h -> sig2 != NULL)
    {
        printf("%d", h -> año);
        mostrar_cotizacion(h -> sig2);
    }
}


void mostrar(nodo1 *h)
{
    if(h -> sig1 != NULL)
    {
        printf("%d", h -> año);
        mostrar_cotizacion(h -> l2);
        mostrar(h -> sig1);
    }
}


int main()
{
    nodo1 *p = NULL;
    p = (nodo1*)malloc(sizeof(nodo1);
    cargar(p);
    mostrar(p);
    
    return 0;
}



/*

Generar una nueva lista con el año de nacimiento y el índice de masa corporal. Este se calcula como peso/(altura*altura).
Insertar en esta lista despues de cada nodo donde el indice de masa corporal sea menor a 24, un nuevo nodo con el año de nacimiento y en el indice un 1.
Generar otra lista con año de nacimiento, peso y altura con aquellas personas que tienen sobrepeso. 
El índice de maso corporal debe ser mayor a 25 para tener sobrepreso.
Eliminar de la lista original aquellas personas que nacieron en 1960 y 1970 y no tiene sobrepeso.

Mostrar todas las listas en cada caso.

*/
#include <stdio.h>
#include <stdlib.h>


typedef struct list
{
    int nacimiento;
    float altura, peso;
    struct list *sig;
} nodo;


typedef struct lista2
{
    int nacimiento;
    float IMC; 
    
} nodo2;


nodo eliminar1(nodo *h)
{
    nodo *a = NULL;
    while(h -> sig != NULL)
    {
        if(h -> nacimiento = 1960 && h -> nacimiento = 1970)
        {
            a = h -> sig;
            free(h);
            h = a;
        }
        return h;
    }
}


nodo eliminar2(nodo *h)
{
    nodo *a = NULL;
    while(h -> sig != NULL)
    {
        if(h -> peso/(altura *altura) < 25)
        {
            a = h -> sig;
            free(h);
            h = a;
        }
        return h;
    }
}


void cargar(nodo *h)
{
    printf("\nIngrese el año de nacimiento: ");
    scanf("%d", &h -> nacimiento);
    
    printf("\nIngrese el peso: ");
    scanf("%f", &h -> peso);
    
    printf("\nIngrese la altura: ");
    scanf("%f", &h -> altura);
    
    if(h -> nacimiento == 0)
    {
        h -> sig = NULL;
    }
    else
    {
        h -> sig = (nodo*)malloc(sizeof(nodo));
        cargar(h -> sig);
    }
***********************************************************************
    if(h -> peso == 0 && h -> altura == 0)
    {
        h -> sig = NULL;
    }
    else
    {
        h->sig=(nodo*)malloc(sizeof(nodo));
        cargar(h->sig);
    }
    
    IMC = peso/(altura *altura);
**********************************************************************
}


void cargar2(nodo *h, nodo1 *m)
{
    while(h -> sig != NULL)
    {
        m -> nacimiento = h -> nacimiento;
        m -> IMC = h -> peso/(altura *altura);
        m -> sig; // camino 
        m -> m -> sig; // camino a la lista original
    }
    
}


void mostrar(nodo *h)
{
    if (h -> sig != NULL)
    {
        //printf("%d\n ",h -> );
      printf("n%f ",h -> IMC);
        
        mostrar(h->sig);
    }
    
}


int main()
{
    nodo *p = NULL;
    p = (nodo)malloc(sizeof(nodo));
    cargar(p);
    cargar2(p);
    mostrar(p);
    p = eliminar1(p);
    p = eliminar2(p);
    
    return 0;
}


SIN TERMINAR 



/* EJEMPLOS DEL PARCIAL */ 

/*
Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar;
 a)  Sumatoria de los elementos impares con dos hijos.
 b)  Máximo elemento impar del árbol 

 El ingreso de datos es 8 3 10 1 6 14 4 7 13
 a)     Sumatoria: 3
 b)     Maximo:13
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja)
{
    int numero;
    printf("ingrese numero\n");
    scanf("%d", &numero);
    while (numero != -1)
    {
        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
        return;
    if (*hoja == NULL)
    {
        //creo la hoja vacia
        (*hoja) = (treenode *)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else
    {
        if (numero > (*hoja)->dato)
        {
            insertar(&(*hoja)->der, elem);
        }
        else
        {
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}

void mostrar(treenode *hoja,int *sum,int *maxImp)
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq,sum,maxImp);
        printf("%d ", hoja->dato);
        mostrar(hoja->der,sum,maxImp);

        if(hoja->dato % 2 != 0 && hoja->der != NULL && hoja->izq != NULL )
        {
            *sum = *sum + hoja->dato;
        }
        if(hoja->dato > *maxImp && hoja->dato % 2 !=0)
        {
            *maxImp = hoja->dato;
        }
    }
    return;
}

int main()
{
    int sum=0,maxImp=0;

    printf("arboles\n");
    treenode *arbol = NULL;

    crear(&arbol);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");
    mostrar(arbol,&sum,&maxImp);

    printf("\nsumatoria elementos impares con dos hijo: %d\n",sum);
    printf("***************\n");
    printf("\nmaximo elemento impar del arbol: %d\n",maxImp);
    printf("***************\n");

    return 0;
}


/*
Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar;
 a)  Sumatoria de los elementos impares con dos hijos.
 b)  Máximo elemento impar del árbol 

 El ingreso de datos es 8 3 10 1 6 14 4 7 13
 a)     Sumatoria: 3
 b)     Maximo:13
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja)
{
    int numero;
    printf("ingrese numero\n");
    scanf("%d", &numero);
    while (numero != -1)
    {
        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
    {
        return;
    }
        
    if (*hoja == NULL)
    {
        //creo la hoja vacia
        (*hoja) = (treenode *)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else
    {
        if (numero > (*hoja)->dato)
        {
            insertar(&(*hoja)->der, elem);
        }
        else
        {
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}

void mostrar(treenode *hoja,int *sum,int *maxImp)
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq,sum,maxImp);
        printf("%d ", hoja->dato);
        mostrar(hoja->der,sum,maxImp);

        if(hoja->dato % 2 != 0 && hoja->der != NULL && hoja->izq != NULL )
        {
            *sum = *sum + hoja->dato;
        }
        if(hoja->dato > *maxImp && hoja->dato % 2 !=0)
        {
            *maxImp = hoja->dato;
        }
    }
    return;
}

int main()
{
    int sum=0,maxImp=0;

    printf("arboles\n");
    treenode *arbol = NULL;

    crear(&arbol);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");
    mostrar(arbol,&sum,&maxImp);

    printf("\nsumatoria elementos impares con dos hijo: %d\n",sum);
    printf("***************\n");
    printf("\nmaximo elemento impar del arbol: %d\n",maxImp);
    printf("***************\n");

    return 0;
}



/*
num: numero entero.
siguiente: puntero al próximo elemento de la pila.
El ingreso de datos termina con -1.
Escribir una función que permita calcular la sumatoria de números múltiplos del primer elemento ingresado en la pila. 
Si no hubiera ningún número mostrar una leyenda.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiponodo
{
    int dato;
    struct tiponodo *siguiente;
} nodo;

void calculomul(nodo aux, int primero, int *sum, int *pase)
{
    if (aux.dato % primero == 0)
    {
        *pase = *pase + 1;
        *sum = *sum + aux.dato;
    }
}

void mostrar(nodo aux, int primero, int *sum, int *pase)
{
    calculomul(aux, primero, sum, pase);
    printf("%d\n", aux.dato);
}

nodo *crear_nodo(int dato)
{
    nodo *u;
    u = (nodo *)malloc(sizeof(nodo));
    u->dato = dato;
    u->siguiente = NULL;
    return u;
}

void apilar(nodo **p, nodo *u)
{
    u->siguiente = *p;
    *p = u;
}

nodo desapilar(nodo **p)
{
    nodo *aux;
    nodo datos;
    datos = **p;
    aux = *p;
    *p = (*p)->siguiente;
    free(aux);
    return datos;
}

int main()
{

    int i, num, primero, sum = 0, pase = 0;
    nodo *p = NULL;

    printf("Ingrese un numero \n");
    scanf("%d", &num);
    primero = num;
    while (num != -1)
    {
        apilar(&p, crear_nodo(num));
        printf("Ingrese un numero \n");
        scanf("%d", &num);
    }
    printf("\nVamos a desapilar todo\n");
    while (p != NULL)
    {
        mostrar(desapilar(&p), primero, &sum, &pase);
    }
    if (pase > 1)
    {
        printf("primer valor ingresado:  %d\n", primero);
        printf("\nla suma de nums multiplos al primer num: %d\n", sum);
    }
    if(pase==1)
    {
        printf("primer valor ingresado:  %d\n", primero);
        printf("\n no hay nums multiplos del primer numero....");
    }
    return 0;
}


/*
num: numero entero.
siguiente: puntero al próximo elemento de la cola.
El ingreso de datos termina con -1.
Escribir una función que permita calcular la sumatoria de los números menores al último elemento ingresado en la cola.
Si no hubiera ningún número, mostrar una leyenda.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tiponodo
{
    int dato;
    struct tiponodo *siguiente;
} nodo;

void sumamenoresultimo(nodo aux,int ultimo, int *suma,int *pase)
{
    if(aux.dato<ultimo)
    {
        *pase = 1;
        *suma = *suma + aux.dato;
    }
}

void mostrar(nodo aux,int ultimo,int *suma,int *pase)
{
    sumamenoresultimo(aux,ultimo,suma,pase);
    printf("%d \n", aux.dato);
}

nodo *crear_nodo(int dato)
{
    nodo *u;
    u = (nodo *)malloc(sizeof(nodo));
    u->dato = dato;
    u->siguiente = NULL;
    return u;
}

void acolar(nodo **p, nodo **u, nodo *q)
{
    if (*p == NULL)
        *p = *u = q; 
    else
    {
        (*u)->siguiente = q;
        (*u) = q;
    }
}

nodo desacolar(nodo **inicio)
{
    nodo *aux;
    nodo datos;
    datos = **inicio;
    aux = *inicio;
    *inicio = (*inicio)->siguiente;
    free(aux);
    return datos;
}

int main()
{
    int i, num,ultimo,suma=0,pase=0;
    nodo *p = NULL;
    nodo *u = NULL;

    printf("Ingrese un numero");
    scanf("%d", &num);

    while(num != -1)
    {
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese un numero");
        scanf("%d", &num);
        if(num!=-1)
        {
            ultimo = num;
        }
        
    }
    printf("\nVamos a desacolar todo\n");
    while (p != NULL)
    {
        mostrar(desacolar(&p),ultimo,&suma,&pase);
    }
    printf("ultimo %d\n",ultimo);
    if(pase==1)
    {
        printf("suma nums menores que el ultimo num: %d\n",suma);
    }
    else
    {
        printf("no existe suma de nums menores que el ultimo num");
    }
    return 0;
}
*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
1. Generar los primeros cuatro números abundantes.
Un número abundante es todo número natural que cumple que, la suma de sus divisores propios es mayor que el propio número.
Por ejemplo, 12 es abundante ya que sus divisores son 1, 2, 3, 4 y 6 y se cumple que 1+2+3+4+6=16, que es mayor que el propio 12.
*/

#include <stdio.h>
int main() 
{
    int num=1, cont=0, acum=0, i;
    // no va ningun "printf" porque el enunciado dice generar (osea que el programa solo va a ir recorriendo desde el numero
    // que le dijimos que empiece), y no, ingresar
    while(cont < 4)
    {
        for (i=1;i<num;i++)
        {
            if (num%i==0)
            {
                acum=acum+i;
            }
        }
        
        if (acum > num)
        {
            cont++;
            printf("\neste numero es abundante %d",num);
        }
        
        acum=0; // lo pongo en 0 porque sino me viene el otro numero y se queda con los valores del anterior numero que paso
        num++;
        
    }
    
    return 0;
}


/* Ingresar números hasta leer un cero. Se pide informar la cantidad de números malvados leídos.
Un Número malvado es todo número natural cuya expresión en base 2 (binaria) contiene un número par de unos. 
Por ejemplo 12 , y 15 son números malvados ya que 12=11002 y 15=11112.*/

#include <stdio.h>

int main() 
{
    int num, cont=0, acum=0, i, cont1=0, num1;
    
    printf("\ningrese un numero");
    scanf("%d",&num);
    
    while(num >0)
    {
        num1=num;while (num>0)
        {
            if (num%2==1)
            {
                cont++;
            }
            num=num/2;
        }
        
        printf("\n cantidad de unos %d",cont);
        if (cont%2==0)
        {
            printf("\n este numero es malvado %d", num1);
            cont1++;
        }
        
        printf("\ningrese un numero");
        scanf("%d",&num);
        cont=0; // lo tengo que blanquear para que cuando se ingresa otro numero no quede guardado el valor anterior
        
    }
    printf("\n la cantidad de numeros malvados es %d",cont1);
    
    return 0;
}



/*
Ingresar números enteros y cargar un vector con los primero 10 números positivos o hasta que se lea un cero. Si el vector no tiene elementos, mostrar una leyenda, caso contrario mostrarlo y realizar las siguientes operaciones;

a) Insertar el opuesto antes de aquellos números pares menores al promedio.
b) Ordenar el vector de mayor a menor y mostrarlo.
*/


#include <stdio.h>

int cargar(int a[])
{
    int num, i = 0;
    
    printf("\nIngrese los valores del arreglo: ");
    scanf("%d", &num);
    
    while (i < 10 && num != 0)
    {
        if (num%2 == 0)
        {
            a[i] = num;
            i++;
        }
        
        printf("\n ingrese valor: ");
        scanf("%d",&num);
    }
    
    return i;
}


void mostrar(int a[], int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("\n %d %d",i, a[i]);
    }
    
    return;
}


int promedio(int a[], int dim)
{
    int acum = 0, i;
    for(i = 0; i < dim; i++)
    {
        acum = acum + a[i];
    }
    
    return acum/dim; // no pongo "return 0" porque tengo que sacar el promedio y si pongo 0 el programa asume que el promedio es 0, por 
                     //ende se sigue ejecutando
    
    /*promedio = acum/dim;  ** es lo mismo
    return promedio;*/
}


void desplazar(int a[], int dim, int pos)
{
    int i;
    for(i = dim; i >= pos; i--) //
    {
        a[i] = a[i-1]; 
    }
}


int insertar(int a[], int dim; int prom)
{
    int i;
    for(i = 0; i < dim; i++)
    {
        if(a[i] < prom && a[i]%2 == 0) 
            {
                desplazar(a, dim, pos); //llamo a otra funcion 
                a[i+1] = -a[i]; //o tambien "a[i] * (-1)" para que sea el opuesto
                dim++; //le sumo a la diemnsion porque quiero que los valores se muevan cada vez que la condicion se cumpla
                i++; //esto es para que se mueva el "i" porque sino sale error de compilacion, NO ES UNA BUENA PRACTICA pero 
                     //la profe lo dio asi y dijo que en realidad hay que hacer un "while"
            }
    }
    
    return dim; 
}


int main()
{
    int a[20], dim, i = 0, prom; //el "a[20]" es para guardar la cantidad de lugres que quiero para que me sobre, no lo voy a usar 
                                 //porque total son solo 10 elementos los que me pide
    dim = cargar(a);
    printf("\nLos numeros pares son: ");
    if (dim != 0)
    {
        mostrar(a, dim);
        prom = promedio(a, dim); // guardo el resultado de lo que retorne en la funcion "promedio" en una variable "prom", que es lo mismo
                                 //que puse como ejemplo en la funcion promedio **
        printf("\nEl promedio es: %d", prom);
        printf("\nEl arreglo con insercion es: ");
        insertar(a, dim);
    }
    
    return 0;
}


/*Trate de arreglarlo pero la profe lo hizo muy distinto */
    

/*
Determinar si es una matriz antisimétrica. Si lo es calcular el promedio de 
los elementos de la diagonal secundaria, sino calcular el promedio de los
elementos de la diagonal principal.
*/

#include <stdio.h>

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


void diagonal(int a[][10], int dim)
{
    int i, j, cont1=0, cont2=0, acum1=0, acum2=0;
    float prom1, prom2; 
    
    for (i = 0; i < dim; i ++)
    {
        for (j = 0; j < dim; j ++)
        {
            if (a[i][j] == a[j][i])
            {
                for (i = 0; i < dim; i ++)
                {
                    acum1 += a[i][i]; 
                    cont1 += 1;
                }
                prom1 = acum1/cont1;
                printf("\nEl promedio de los elementos de la diagonal principal es: %f", prom1);
            }

            else
            {
                for (i = dim - 1; i >= 0; i --)  
                {
                    acum2 += a[i][j];
                    cont2 += 1;
                    j++; 
                }
                prom2 = acum2/cont2;
                printf("\nEl promedio de los elementos de la diagonal secundaria es: %f", prom2);
            }
               
        }
    }
}


int main() 
{
   int a[10][10],dim;
    printf("ingrese dimension de la matriz menor a 10 filas: ");
    scanf("%d",&dim); 
   cargar(a,dim);
   mostrar(a,dim);
   diagonal(a, dim);
    
    return 0;
}

// LA MAYORIA ESTA MAL 



/*
Desarrollar un programa en C que permita leer un texto carácter a carácter terminado en punto. Por fin de proceso
a) Mostrar el texto con tres blancos de separación después de cada palabra que finaliza en s y tiene al menos 2 vocales.
b) Contar cuantas palabras de mas de 4 caracteres empiezan y terminan con la misma letra.
*/



#include <stdio.h>

int main() 
{
    int c, ultimo, primero, cont = 0, contVoc = 0; 
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        primero = c;
        while (c != '.' && c != ' ')
        {
            ultimo = c;
            putchar(c);
            c = getchar();
        }
        putchar(c);
        
        
        if(primero == ultimo)
        {
            cont++;
        }
        
        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
            
            if(ultimo == 's' && c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                contVoc++;
                
            }
            
            if(contVoc == 2) 
            {
                putchar(' ');
                putchar(' ');
                putchar(' ');
            }
        }
    }
    

    printf("\nLa cantidad de palabras que empiezan y terminan con la misma letra son: %d", cont);
    
    return 0;
}

/*PARA QUE VAYA QUEDANDO GUARDADO, NO ESTA TERMINADO por el tema de los blancos */


/*Cargar una matriz de nxn elementos enteros. Mostrarla. Calcular el producto de los elementos de la
diagonal principal en forma recursiva.*/

#include <stdio.h> 

int producto(int a[10][10], int dim)
{
    if(dim<0) //va a cortar cuando, a medida que va disminuyendo, sea menor que 0
    {
        return 1; //retorno 1 porque sino me termina multiplicando con 0 y siempre va a devolver 0
    }
    
    return producto(a, dim-1)*a[dim][dim];
}

void cargar(int a[10][10], int dim)
{
    int i, j;
    for(i=0; i<dim; i++)
    {
        for(j=0; j<dim; j++)
        {
            printf("fila %d columna %d\n ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void mostrar(int a[10][10],int dim)
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

int main()
{
    int a[10][10], dim;
    printf("\nIngrese dimension de la matriz menor a 10 filas: ");
    scanf("%d", &dim);
    cargar(a, dim);
    mostrar(a, dim);
    printf("\nEl producto es: %d", producto(a, dim-1));
    
    return 0;
}



/*
5. Escribir un programa efectúe las siguientes operaciones:
a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y mostrarlo.
b) Declarar un puntero a float.
c) Asignar al puntero la dirección del arreglo.
d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada posición.
*/

#include <stdio.h>

void cargar(float vec[], float dim)
{
    int i;
    float *p;
    p = &vec[0];
    for(i=0; i<dim; i++)
    {
        printf("\nIngrese el valor: ");
        scanf("%f", (p+i)); //el "i" le suma y lo va guardadno en el arreglo
    }
    
    return;
}


void mostrar(float vec[], float dim)
{
    int i;
    float *p;
    p = &vec[0];
    for(i=0; i<dim; i++)
    {
        printf("\nLos valores son: %f", *(p+i)); //con el asterisco lo muestro desde la posicion que apunta "p" mas la cantidad de bytes
        printf("\nLa direccion de memoria es: %p", (p+i)); 
    }
    
    return;
}


int main()
{
    float vec[15], *p, dim;
    printf("\nIngrese la dimension del arreglo: ");
    scanf("%f", &dim);
    cargar(vec, dim);
    mostrar(vec, dim);
    
    
    return 0;
}



/*
Crear una lista simplemente enlazada con el número de legajo, nombre y apellido y cantidad de materias aprobadas de 
los alumnos de una facultad. La carga de datos finaliza cuando el número de legajo es igual a cero.

Mostrar la lista.
Mostrar cuántos alumnos tiene más de 10 materias aprobadas.
Generar una nueva lista con aquellos alumnos que tiene menos de 3 materias aprobadas.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct alumnos
{
    int legajo, mat_aprob;
    char nombre_apellido[30];
    struct alumnos *sig;
}nodo;


void crear(nodo *h)
{
    printf("\nIngrese el legajo: ");
    scanf("%d", &h->legajo);
    
    if(h->legajo == 0)
    {
        h->sig=NULL;
    }
    else
    {
        printf("\nIngrese su nombre y apellido: ");
        scanf("%s", h->nombre_apellido);
        printf("\nIngrese las materias aprobadas: ");
        scanf("%d", &h->mat_aprob);
        h->sig = (nodo*)malloc(sizeof(nodo)); 
        crear(h->sig);
    }
    
}


void mostrar(nodo *h)
{
    while(h->sig!=NULL)
    {
        printf("\nEl alumno: %s",h->nombre_apellido);
        printf("\nTiene %d materias aprobadas",h->mat_aprob);
        h=h->sig;
    }
}


void generar(nodo *h, nodo *a)
{
    while(h->sig != NULL)
    {
        if(h->mat_aprob < 3)
        {
            a->legajo=h->legajo; 
            a->mat_aprob=h->mat_aprob; 
            a->sig=(nodo *)malloc(sizeof(nodo)); 
            a=a->sig; 
        }
        
        h=h->sig;
    }
    
    a->sig=NULL;
}


int main()
{
    nodo *p=NULL;
    nodo *q=NULL;
    p=(nodo*)malloc(sizeof(nodo));
    q=(nodo *)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);
    generar(p, q);
    printf("\nEl alumno %s tiene: ", p -> nombre_apellido);
    mostrar(q);
    
    return 0;
}




/*
Desarrollar un programa en C que permita crear una lista simplemente enlazada con la siguiente estructura:

Mostrar dicha lista (la carga finaliza con 0 en el primer número ingresado).
Si la suma de los tres números del nodo es mayor a 20, insertar antes de cada nodo el doble de cada valor del nodo.
Si la suma de los tres números es igual a 20, eliminar dicho nodo.
Generar una nueva lista con aquellos nodos eliminados. Mostrar dicha lista.
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


void crear(nodo *h)
{
    printf("Ingrese el primer numero: ");
    scanf("%d",&h->num1);
    if (h->num1==0)
    {
        h->sig=NULL;
    }

    else
	{
	    printf("ingrese el segundo numero: ");
		scanf("%d",&h->num2);
		printf("ingrese el tercer numero: ");
		scanf("%d",&h->num3);
        h->sig=(nodo*)malloc(sizeof(nodo));
        crear(h->sig);
	}
	
	return;
}


void mostrar(nodo *h)
{
    if (h->sig !=NULL)
	{
	    printf("%d \n", h->num1);
		printf("%d \n", h->num2);
        printf("%d \n", h->num3);
        mostrar(h->sig);
	}
	
	return;
}


void insertar(nodo *h)
{
    nodo *aux = NULL;
    while(h->sig != NULL)
    {
        if(h->num1 + h->num2 + h->num3 > 20)
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux-> num1 = (h->num1) *2; 
            aux-> num2 = (h->num2) *2; 
            aux-> num3 = (h->num3) *2; 
            aux->sig = h->sig;
            h = h->sig;
        }
        
        h = h->sig;
    }
    
    return;
}

/*
void generar(nodo *h, nodo *t) //genero otra lista
{
    while(h->sig != NULL)
    {
        if(h->num1 + h->num2 + h->num3 == 20)
        {
          t->num = h->num;
          t->sig = (nodo *)malloc(sizeof(nodo));
          t = t->sig;
        }
    
        h = h->sig;
    }

  t->sig = NULL;
}
*/

int main()
{
    nodo *p;
    nodo *q;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);
    insertar(p);
    
    printf("\nLa lista nueva con los nodos eliminados: ");
    generar(p, q);
    mostrar(q);

    return 0;
}




/*ENTREGABLE SIN TERMINAR PERO QUE POR AHI VA*/


/*
a)	Crear y mostrar la lista con números enteros. Termina con num=-2.
b)	Insertar en otra lista los números impares. Mostrarla.
c)	Eliminar todos los valores menores al promedio de la lista original. Mostrarla
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int num;
	struct lista *sig;
}nodo;


void crear (nodo *h)
{
    printf("\nIngrese numeros hasta que termine en -2: ");
    scanf("%d",&h->num);

    if (h->num==-2) 
    {
        h->sig=NULL;
    }
        
    else
	{
        h->sig=(nodo*)malloc(sizeof(nodo));
        crear(h->sig);
	}
	return;
}


void mostrar (nodo *h)
{
    if (h->sig !=NULL)
	{
        printf ("%d\n", h->num);
        mostrar (h->sig);
	}
	return;
}


void generar(nodo *h, nodo *t)
{
    while(h->sig != NULL)
    {
        if(h->num%2 != 0)
        {
            t->num = h->num;
            t->sig = (nodo*)malloc(sizeof(nodo));
            t = t->sig;
        }
        
        h = h->sig;
    }
    
    t->sig = NULL;
}


int promedio(nodo *h)
{
    float suma = 0, cont = 0, prom;
    
    while(h->sig != NULL)
    {
        suma += h->num;
        cont++; 
        h = h->sig;
    }
    prom = suma/cont; 
    
    return prom;
}


nodo* eliminar1(nodo* h, float prom) 
{
    nodo *aux;
    
    while(h->num < prom)
    {
        aux=h->sig;
        free(h);
        h=aux;
    }
    
    return h;
}


void eliminar2(nodo* h, float prom) 
{
    nodo *aux;
    while(h->sig!=NULL && h->sig->sig!=NULL)
    {
        if(h->sig->num < prom)
        {
            aux=h->sig->sig;
            free(h->sig);
            h->sig=aux;
        }
        
        else
        {
            h=h->sig;
        }
    }
}


int main()
{
    nodo *p=NULL;
    nodo *q=NULL;
    float prom;
    p = (nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("Los valores sin eliminar son: \n");
    mostrar(p);
    generar(p, q);
    prom = promedio(p);
    p = eliminar1(p, prom);
    eliminar2(p, prom);
    printf("La lista con eliminacion es: \n");
    mostrar(p);
    printf("Los numeros impares son: \n");
    mostrar(q);
    

    return 0;
}


/*
a) Crear y mostrar la lista. Termina con num = 1000.
b) Generar otra lista con aquellos numeros multiplos de 3. Mostrarla. 
c) Si la suma de nodos concecutivos de la lista original es mayor a 20 agregar adelante el primer nodo (que se suma) un nodo con num = 0. 
   Si la suma de nodos consecutivos es menor a 10 eliminar el segundo nodo que se suma.
   Mostrar la lista.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int num;
	struct lista *sig;
}nodo;


void crear (nodo *h)
{
    printf("\nIngresar valores, corta en 1000: "); 
    scanf("%d",&h->num);

    if (h->num==0) //en este caso lo dejo en 0 solo para no poner 1000 siempre que lo pruebo
    {
        h->sig=NULL;
    }
        
    else
	{
        h->sig=(nodo*)malloc(sizeof(nodo));
        crear (h->sig);
	}
	
	return;
}


void mostrar (nodo *h)
{
    if (h->sig !=NULL)
	{
        printf ("%d\n", h->num);
        mostrar (h->sig);
	}
	
	return;
}


void generar(nodo *h, nodo *t)
{
    while(h->sig != NULL)
    {
        if(h->num%3 == 0)
        {
            t->num = h->num;
            t->sig = (nodo*)malloc(sizeof(nodo));
            t = t->sig;
        }
        
        h = h->sig;
    }
    
    t->sig = NULL;
}


int suma(nodo *h)
{
    int sum = 0;
    while(h->sig != NULL)
    {
        sum += h->num;
        h = h->sig;
    }
    
    return sum;
}


nodo* insertar1(nodo *h, int sum)  
{
    nodo *aux;
    if( h->num +h->sig->num > 20)
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num=0;
        aux->sig=h;
        h=aux;
    }
    
    return h;
}


void insertar2 (nodo *h, int sum) 
{
    nodo *aux;
    while(h->sig!=NULL)
    {
        if( h->num +h->sig->num > 20) 
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=0;
            aux->sig=h->sig;
            h->sig=aux;
			h=h->sig; //se pone esto para que camine porque si inserte un numero y lo comparo con el siguiente, como en "h->sig=aux" me queda 
                      //loop infinito insertando 0 a cada rato, lo que hago es pararme en el siguiente a donde se inserto 0 y volverlo "h" 
                      //para que siga comparando  
        }
        
        h=h->sig;
    }
}


void eliminar2(nodo* h, int sum) 
{
    nodo *aux;
    while(h->sig!=NULL && h->sig->sig!=NULL)
    {
        if(h->num + h->sig->num < 10)
        {
            aux=h->sig->sig;
            free(h->sig);
            h->sig=aux;
        }
        
        else
        {
            h=h->sig;
        }
    }
}


int main()
{
    nodo *p=NULL;
    nodo *q=NULL;
    int sum;
    p=(nodo*)malloc(sizeof(nodo));
    q=(nodo*)malloc(sizeof(nodo));
    crear(p);
    printf("Lista sin insertar ni eliminar:\n ");
    mostrar(p);
    generar(p, q);
	printf("la lista nueva es");
	mostrar(q);
   // sum = suma(p);
    p=insertar1(p, sum);
    insertar2(p, sum);
    
    eliminar2(p, sum);
    printf("Lista con insertar y eliminar:\n ");
    mostrar(p);
    //printf("Nueva lista con nodos eliminados:\n ");
	//mostrar(q);

    return 0;
}


//PRIMER PARCIAL DE PROGRAMACAION 
/*
La cadena de hoteles Hilton tiene establecimientos en todo el mundo. Para conocer las ganancias, se ingresa:
-código de país
-numero de establecimiento
-recaudación mensual (en millones de dólares) en una lista simplemente enlazada.
El ingreso de datos termina con el código de país igual a cero.


Mostrar la lista.
Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.
Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
Ingresar un nuevo hotel con el código de país y la recaudación mensual e Insertarlas en orden en la lista.
*/                        //  (la suma)     // (menor a mayor por codigo de pais)



#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
  int cod;
  int est;
  int rec;
  struct lista *sig;
}nodo;


void crear (nodo *h)
{
  printf("\nIngrese el codigo del pais: ");
  scanf("%d", &h->cod);

  if (h->cod==0)
  {
    h->sig=NULL;
  }

  else
  {
    printf("\nNumero de establecimiento: ");
    scanf("%d", &h->est);
    printf("\nRecaudacion: ");
    scanf("%d", &h->rec);
    h->sig=(nodo*)malloc(sizeof(nodo));
    crear (h->sig);
  }

  return;
}


void mostrar (nodo *h)
{
  if (h->sig !=NULL)
  {
    printf ("%d\n", h->cod);
    printf ("%d\n", h->est);
    printf ("%d\n", h->rec);
    mostrar (h->sig);
  }

  return;
}


int suma_rec(nodo *h)
{
  int suma = 0;
  while(h->sig != NULL)
  {
    suma += h->rec;
    h = h->sig;
  }

  return suma;
}


float promedio(nodo *h)
{
  float prom = 0, suma = 0, cont = 0;
  
  while(h->sig != NULL)
  {
    suma += h->rec; 
    cont++;
    h = h->sig;
  }
  prom = suma/cont;
  
  return prom;
}


//Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.

void insertar2 (nodo *h, int suma)
{
  nodo *aux;
  
  while(h->sig != NULL) //este lo dejo asi porque lo unico que hace es recorrer todo, no afecta, yo lo habia hecho mal: while(h->sig == NULL)
  {
    if(h->sig == NULL) //aca esta la condicion que marca que si es el ultimo, este esta bien asi, si afecta este "if"
    {
      aux=(nodo *)malloc(sizeof(nodo));
      aux->cod=100;
      aux->est=0;
      aux->rec=suma;
      aux->sig=h->sig;
      h->sig=aux;
    }

    h=h->sig;
  }
}


//Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.

nodo* eliminar1(nodo* h, float prom)
{
  nodo *aux;
  
  while(h->rec < prom)//condicion de eliminacion
  {
    aux=h->sig;
    free(h);
    h=aux;
  }

  return h;
}


//Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.

void eliminar2(nodo* h, float prom)
{
  nodo *aux;

  while(h->sig!=NULL && h->sig->sig!=NULL)
  {
    if(h->sig->rec < prom)//condicion de eliminacion
    {
      aux=h->sig->sig;
      free(h->sig);
      h->sig=aux;
    }

    else
    {
      h=h->sig;
    }
  }
}


int main()
{
  nodo *p=NULL;
  float prom;
  int suma;
  p=(nodo*)malloc(sizeof(nodo));
  crear(p);
  printf("\nLa lista sin insercion ni eliminacion es: \n");
  mostrar(p);
  suma=suma_rec(p);
  prom=promedio(p);
  insertar2(p, suma);
  printf("\nLa lista con insercion es: \n");
  p=eliminar1(p, prom);
  eliminar2(p, prom);
  printf("\nLa lista con eliminacion es: \n");
  mostrar(p);

  return 0;

}


/*
Desarrollar un programa en C que permita cargar los datos en una multilista de la siguiente manera:
-en la lista principal se ingresan diferentes años
-ordenados de menor a mayor y por cada año, el mes y cotización promedio del dolar durante ese mes. 
La carga termina con 0 en ambos casos. Mostrar la mulitilista. 
Ingresar el año actual, el mes actual y la cotización promedio del dolar e insertarlo en la multilista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista1
{
     int anio;
     struct lista2 *m;
     struct lista1 *sig;
}nodoa;


typedef struct lista2
{
     int mes;
     int cot;
     struct lista2 *sig;
     
}nodom;


void crearmes(nodom *h)
{
    printf("\nIngrese el mes: ");
	scanf("%d",&h->mes);
	if (h->mes==0)
	{
		h->sig=NULL;
	}
	
	else
	{
	    printf("\nIngrese el valor del dolar: ");
		scanf("%d",&h->cot);
		h->sig=(nodom *)malloc(sizeof(nodom));
		crearmes(h->sig);
	}
}


void mostrarmes(nodom *h)
{
   if(h->sig!=NULL)
   {
		printf("\nEl mes es: %d", h->mes);
	    printf("\nEl valor del dolar es: %d", h->cot);
		mostrarmes(h->sig);
		
	}
}


void mostraranio(nodoa *h)
{
	if(h->sig!=NULL)
	{
		printf("\nEl año es: %d", h->anio);
		mostrarmes(h->m);
		mostraranio(h->sig);
	}
}


void crearanio(nodoa *h)
{
    printf("\nIngrese el año: ");
	scanf("%d",&h->anio);
	
	if (h->anio ==0)
	{
		h->sig=NULL;
	}
	
	else
	{
		h->m=(nodom *)malloc(sizeof(nodom));
		crearmes(h->m);
		h->sig=(nodoa *)malloc(sizeof(nodoa));
		crearanio(h->sig);
	}
}


void insertar(nodoa *h) //este inserta un elemento cuando ya se termino de insertar, el valor de éste ya esta preestablecido para cuando se imprima 
{
	nodoa *aux=NULL;
	while(h->sig!=NULL && h->sig->sig!=NULL)
	{
		h=h->sig;
	}
	
	aux=(nodoa *)malloc(sizeof(nodoa));
	aux->anio=2021;
	aux->m=(nodom *)malloc(sizeof(nodom));
	crearmes(aux->m);
	
	aux->sig=h->sig;
	h->sig=aux;
	
}


int main() 
{
    nodoa *p=NULL;
	p = (nodoa *)malloc(sizeof(nodoa));
	crearanio(p);
	mostraranio(p);
	insertar(p);
	mostraranio(p);
	
    return 0;
}



//EJERCICIO DE COLAS DE LA GUIA 
/*El promedio de aquellos números divisores del último número ingresado a la cola*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int ultimo, int *cont, int *acum)
{
  	printf("%d \n", aux.dato);
  	
  	if(ultimo % aux.dato == 0)
  	{
  	    *cont = *cont + 1;
  	    *acum = *acum + aux.dato;
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
    int i,num, ultimo, cont = 0, acum = 0, promedio;
    nodo* p=NULL;
    nodo* u=NULL;

    for(i=0; i<CANT; i++)
    {
        printf("Ingrese un numero");
        scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
    }
    ultimo = num;

    printf("\nVamos a desacolar todo:\n");
    
    while(p!=NULL)
    {
    	mostrar(desacolar(&p), ultimo, &cont, &acum);
    }
    
    if(cont != 0)
    {
        promedio = acum/cont;
        printf("\nEl promedio es: %d", promedio);
    }
    
    return 0;
}



/*
Desarrollar un programa en C que permita cargar un pila de n números enteros. Calcular y mostrar ( en una función no en el programa principal)
en el promedio de los cuatro primeros números ingresados a la pila. Si no los hubiera, mostrar un cartel aclaratorio.
*/
//PILAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 6


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *num, int *acum)
{
    if(*num <= 4)
    {
        printf("%d \n", aux.dato);
        *acum = *acum + aux.dato;
    }
    
    *num = *num - 1;
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
    int i, num, acum = 0;
    float promedio;
    nodo* p=NULL;

    for(i=0; i<CANT; i++)
    {
       	printf("\nIngrese un numero: ");
       	scanf("%d",&num);
       	apilar(&p, crear_nodo(num));
    }

    printf("\nVamos a desapilar todo: \n");
    
    num = CANT;
    
    if(num >= 4)
    {
        while(p!=NULL)
        {
    	    mostrar(desapilar(&p), &num, &acum);
        }
        
        promedio = acum/4;
        printf("\nEl promedio es: %f", promedio);
    }

    return 0;
}



/*
Desarrollar un programa en C que permita cargar una cola de n números enteros. Calcular y mostrar (en una función y no en el programa principal) 
la sumatoria de los elementos en posición par de la cola. (se considera que el primer que entra está en la posición uno y así sucesivamente).
*/
//COLAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 6

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *num, int *acum)
{
    if(*num % 2 == 0)
    {
        printf("%d \n", aux.dato);
        *acum = *acum + aux.dato;
    }
    
    *num = *num + 1;
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

    int i,num, acum = 0;
    nodo* p=NULL;
    nodo* u=NULL;

    for(i=0; i<CANT; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
    }

    num = 1;
    
    while(p!=NULL)
    {
        mostrar(desacolar(&p), &acum, &num);
    }
    
    printf("\nLa suma de los numeros en las posiciones pares es: %d", acum);


    
    return 0;
}



//ENTREGABLE DE ARBOLES BINARIOS 

/*
Desarrollar un programa en C que permita ingresar números en un árbol binario de búsqueda. Mostrarlo en preorden, en orden y en postorden. 
Calcular y mostrar (en una función y no en el programa principal):

-El valor máximo múltiplo de la raíz.
-La cantidad de nodos hojas divisores de la raíz.
-La sumatoria de aquellos nodos pares con un hijo.
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


void insertar (treenode **hoja, int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *maximo, int *cont_div, int *cont_sum)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, maximo, cont_div, cont_sum);
        printf("%d ",hoja->dato); 
        
        if(hoja->dato > *maximo && hoja->dato % raiz == 0) //-El valor máximo múltiplo de la raíz.
        {
            *maximo = hoja->dato;
        }
        if((raiz % hoja->dato == 0) && (hoja->izq==NULL && hoja->der==NULL)) //-La cantidad de nodos hojas divisores de la raíz.
        {
            *cont_div = *cont_div + 1;
        }
        if((hoja->izq!=NULL && hoja->der==NULL) || (hoja->izq==NULL && hoja->der!=NULL) && (hoja->dato%2 == 0)) //-La sumatoria de aquellos nodos pares con un hijo.
        {
            *cont_sum = *cont_sum + 1;
        }
        mostrar(hoja->der, raiz, maximo, cont_div, cont_sum);

    }
    
    return;
}


int main ()
{
    int raiz, maximo = 0, cont_div = 0, cont_sum = 0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &maximo, &cont_div, &cont_sum);
    printf("\nLa cantidad de nodos mayores y divisible por la raiz es: %d", maximo);
    printf("\nLa cantidad de nodos divisores de la raiz es: %d", cont_div);
    printf("\nLa cantidad de nodos pares con un hijo es: %d", cont_sum);


    return 0;
}


/*REPASO PARA SEGUNDO PARCIAL*/

/*
Crear una pila con la siguiente información:
-num: numero entero.
-siguiente: puntero al próximo elemento de la pila.
Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda
*/
//PILAS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *num, int *acum, int primero, int *cont)
{
    if(primero < aux.dato)
    {
        *acum = *acum + aux.dato;
        *cont = *cont + 1;
    }
    
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
    int i, num, primero = 0, acum = 0, cont = 0;
    nodo* p=NULL;

    for(i=0; i<CANT; i++)
    {
       	printf("Ingrese un numero: \n");
       	scanf("%d", &num);
       	if(i == 0)
       	{
       	    primero = num; 
       	}
       	apilar(&p, crear_nodo(num));
    }


    printf("\nVamos a desapilar todo: \n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), &num, &acum, primero, &cont);
    }
    
    printf("\nSi los numeros son mayores al primero la suma es: %d", acum);
    
    if(cont==0)
    {
      printf("\nNo hay ningun numero.\n"); 
    }

    return 0;
}


/*REPASO PARA SEGUNDO PARCIAL*/

/*
Crear una cola con la siguiente información:
-num: numero entero.
-siguiente: puntero al próximo elemento de la cola.
Desarrollar una función que permita mostrar el promedio de tres primeros
números ingresados a la cola. Si no hubiese tres números, mostrar una leyenda y
no calcular el promedio. 
*/
//COLAS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5

typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *num, int *acum, int *cont)
{
    if(*cont < 3)
    {
        *acum = *acum + aux.dato;
        *cont = *cont + 1;
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
    int i,num, acum = 0, cont = 0, promedio = 0;
    nodo* p=NULL;
    nodo* u=NULL;

    for(i=0; i<CANT; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
    }

    printf("\nVamos a desacolar todo\n");
    
    while(p!=NULL)
    {
        mostrar(desacolar(&p), &num, &acum, &cont);
    }
    
    promedio = acum/3;
    
    
    printf("\nEl promedio de los primeros 3 numeros es: %d", promedio);
    
    if(cont == 2)
    {
        printf("\nNo hay numeros para calcular");
    }
	
    return 0;
}


/*REPASO PARA SEGUNDO PARCIAL*/

/*
a) Buscar el mayor elemento del árbol divisor de la raíz
b) Cantidad de nodos hojas impares.
*/
//ARBOL BINARIO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja,int elem)
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


void crear (treenode **hoja, int *raiz)
{
    int numero; 
    
    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *mayor, int *cont_imp)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, mayor, cont_imp);
        printf("%d ",hoja->dato);
        if(hoja->dato > *mayor && raiz % hoja->dato == 0 && hoja->dato != raiz) //Buscar el mayor elemento del árbol divisor de la raíz
        {
            *mayor = hoja->dato;
        }
        if(hoja->dato % 2 != 0 && (hoja->izq == NULL && hoja->der == NULL)) //Cantidad de nodos hojas impares
        {
            *cont_imp = *cont_imp + 1; 
        }
        mostrar(hoja->der, raiz, mayor, cont_imp);
    }
    return;
}


int main ()
{
    int raiz, mayor = 0, cont_imp = 0;
    
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &mayor, &cont_imp);
    printf("\nEl mayor elemento divisor de la raiz es: %d", mayor);
    printf("\nLa cantidad de nodos hojas impares es: %d", cont_imp);


    return 0;
}


/*
a) Cantidad de los elementos pares con un hijo.
b) Mínimo elemento impar del árbol. 
*/
//ARBOL BINARIO 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int *minimo, int *cont_pares)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, minimo, cont_pares);
        printf("%d ", hoja->dato);
        if(hoja->dato < *minimo && hoja->dato % 2 != 0 && hoja->dato % 3 == 0) //Mínimo elemento impar del árbol.
        {
            *minimo = hoja->dato;
        }
        if(hoja->dato % 2 == 0 && (hoja->izq == NULL && hoja->der != NULL || hoja->izq != NULL && hoja->der == NULL)) //Cantidad de los elementos pares con un hijo.
        {
            *cont_pares = *cont_pares + 1;
        }
        mostrar(hoja->der, minimo, cont_pares); 
    }
    
    return;
}


int main ()
{
    int numero, minimo = 100000, cont_pares = 0;
    
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, &minimo, &cont_pares);
    printf("\nEl minimo elemento impar del arbol es: %d", minimo);
    printf("\nLos elementos pares con un hijo son: %d", cont_pares);


    return 0;
}



/*
Escribir la función necesaria para calcular la cantidad de elementos múltiplos del
último número ingresado a la pila. Si no hubiera ningún número mostrar una
leyenda.
*/
//PILAS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cant_mult, int ultimo)
{
    if(aux.dato % ultimo == 0 && ultimo != aux.dato)
    {
        *cant_mult = *cant_mult + 1;
    }
    
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
   int i,num, cant_mult = 0, ultimo = 0;
   nodo* p=NULL;

    for(i=0; i<CANT; i++)
    {
       	printf("Ingrese un numero: \n");
       	scanf("%d",&num);
       	apilar(&p, crear_nodo(num));
    }
    
    ultimo = num; 

    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
        mostrar(desapilar(&p), &cant_mult, ultimo);
    }
    
    printf("\nLa cantidad de numeros multiplos del ultimo elemento es: %d", cant_mult);
    if(cant_mult == 0)
    {
        printf("\nNo tiene multiplos.");
    }
    
   return 0;
}




/*
El promedio de aquellos números divisores del último número ingresado a la cola
*/
//COLAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int ultimo, int *acum, int *cont)
{
    if(ultimo % aux.dato == 0 && aux.dato != ultimo)
    {
        *acum = *acum + aux.dato;
        *cont = *cont + 1;
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
    int i,num, ultimo = 0, acum = 0, cont = 0;
    float promedio = 0;
    nodo* p=NULL;
    nodo* u=NULL;

    for(i=0; i<CANT; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
    }

    ultimo = num;

    printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
    {
    	mostrar(desacolar(&p), ultimo, &acum, &cont);
    }	
    
    promedio = acum/cont;
    printf("\nEl promedio de los numeros es: %f", promedio);
    
    return 0;
}



/*
La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
*/
//PILAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int primero, int *acum)
{
    if(aux.dato % primero == 0 && aux.dato != primero) //siempre que dice multiplo aux.dato va a la izquiera, y cuando dice divisor va a la derecha
    {
        *acum = *acum + aux.dato;
    }
    
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


   int i,num, primero = 0, acum = 0;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
       	printf("Ingrese un numero \n");
       	scanf("%d",&num);
       	if(i==0)
       	{
       	    primero = num;
       	}
       	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), primero, &acum);
   }
   
   printf("\nLos numeros multiplos por el primero elemento suman: %d", acum);

   return 0;
}



/*
El número mínimo y su posición en la pila
*/
//PILAS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *minimo, int *pos, int *posicion, int *x)
{
    if(aux.dato < *minimo)
    {
        *minimo = aux.dato;
        *posicion = *x;
    }
    
    *x = *x - 1; 
    
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
   int i,num, minimo, pos = 0, posicion = 0, x;
   nodo* p=NULL;

   for(i=0; i<CANT; i++)
   {
       	printf("Ingrese un numero \n");
       	scanf("%d",&num);
       	if(i==0)
       	{
       	    minimo = num;
       	}
       	apilar(&p, crear_nodo(num));
   }


    printf("\nVamos a desapilar todo\n");
    
    x = CANT;
    
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), &minimo, &pos, &posicion, &x);
   }
   
   printf("\nEl minimo elemento es: %d", minimo);
   printf("\nSu posicion es: %d", posicion);


   return 0;
}


/*
La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
*/
//PILAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int primero, int *acum, int *cont, int *num)
{
    if(aux.dato % primero == 0 && primero != aux.dato)
    {
        *acum = *acum + aux.dato;
        *cont = *cont + 1;
    }
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
    int i,num, primero = 0, acum = 0, cont = 0;
    nodo* p=NULL;
    
    for(i=0; i<CANT; i++)
    {
   	    printf("Ingrese un numero \n");
   	    scanf("%d",&num);
   	    if(i==1)
   	    {
   	        primero = num;
   	    }
   	    
   	    apilar(&p, crear_nodo(num));
    }


    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), primero, &acum, &cont, &num);
    }
    
    printf("\nLa sumatoria de los numeros multiplos del primer elemento es: %d", acum);
    printf("\nLa cantidad de numeros multiplos: %d", cont);
    


   return 0;
}



/*
Diseñar una función que, dado un árbol binario de búsqueda, calcule la cantidad de
nodos impares con dos hijos.
*/
//ARBOL BINARIO 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja, int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *cont)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, cont);
        printf("%d ",hoja->dato);
        if(hoja->dato % 2 != 0 && (hoja->izq != NULL && hoja->der != NULL)) //calcule la cantidad de nodos impares con dos hijos.
        {
            *cont = *cont + 1;
        }
        mostrar(hoja->der, raiz, cont);
    }
    
    return;
}


int main ()
{
    int raiz, cont = 0;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &cont);
    
    printf("\nLa cantidad de nodo impares con dos hijos es: %d", cont);

    return 0;
}



/*
El valor máximo múltiplo de la raíz.
La cantidad de nodos hojas divisores de la raíz.
La sumatoria de aquellos nodos pares con un hijo.
*/
//ARBOL BINARIO


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja, int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *maximo, int *cont_div, int *acum)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, maximo, cont_div, acum);
        printf("%d ",hoja->dato); 
        if((hoja->dato > *maximo) && (hoja->dato % *maximo == 0) && (hoja->dato != raiz)) //El valor máximo múltiplo de la raíz.
        {
            *maximo = hoja->dato;
        }
        if((raiz % hoja->dato == 0) && (hoja->izq == NULL && hoja->der == NULL)) //La cantidad de nodos hojas divisores de la raíz.
        {
            *cont_div = *cont_div + 1; 
        }
        if((hoja->dato % 2 == 0) && (hoja->izq != NULL && hoja->der == NULL || hoja->izq == NULL && hoja->der != NULL)) //La sumatoria de aquellos nodos pares con un hijo.
        {
            *acum = *acum + hoja->dato;
        }
        mostrar(hoja->der, raiz, maximo, cont_div, acum);
    }
    
    return;
}


int main ()
{
    int raiz, maximo, cont_div = 0, acum = 0;
    
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    
    maximo = raiz;
    mostrar (arbol, raiz, &maximo, &cont_div, &acum);
    
    if(maximo == raiz)
    {
        printf("\nNo hay elemento");
    }
    
    else
    {
        printf("\nEl valor maximo multiplo de la raiz es: %d", maximo);
    }
    
    printf("\nLa cantidad de nodos hojas divisores de la raiz son: %d", cont_div);
    printf("\nEl valor maximo numero de la raiz es: %d", acum);

    return 0;
}


/*
El número mínimo y su posición en la COLA
*/
//COLAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *minimo, int *pos, int *posicion, int *x)
{
    if(aux.dato < *minimo)
    {
        *minimo = aux.dato;
        *posicion = *x;
    }
    
    *x = *x + 1; 
    
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

   int i,num, minimo, pos = 0, posicion = 0, x = 0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
       if(i == 0)
       {
           minimo = num;
       }
        acolar(&p, &u, crear_nodo(num));

   }


   while(p!=NULL)
   {
    	mostrar(desacolar(&p), &minimo, &pos, &posicion, &x);
   }
   
   printf("\nEl minimo elemento es: %d", minimo);
   printf("\nSu posicion es: %d", posicion);
   
   return 0;
}



/*REPASO PARA EL RECUPERATORIO DEL SEGUNDO PARCIAL*/
/* 
Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar;
a) Sumatoria de los elementos pares con dos hijos.
b) Mínimo elemento par divisor de la raíz del árbol.
*/
//ARBOL BINARIO 

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

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void mostrar (treenode *hoja, int raiz, int *acum, int *minimo)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, acum, minimo);
        printf("%d ",hoja->dato);
        if((hoja->dato % 2 == 0) && (hoja->izq != NULL && hoja->der != NULL)) //Sumatoria de los elementos pares con dos hijos.
        {
            *acum = *acum + hoja->dato;
        }
        if(hoja->dato < *minimo && hoja->dato % 2 == 0 && raiz % hoja->dato == 0) //Mínimo elemento par divisor de la raíz del árbol 
        {
            *minimo = hoja->dato;
        }
        mostrar(hoja->der, raiz, acum, minimo);
    }
    return;
}
//8,3,10,1,6,14,4,7,13

int main ()
{
    int raiz, acum=0, minimo;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    minimo = raiz;
    mostrar (arbol, raiz, &acum, &minimo);
    
    printf("\nLa sumatoria de los elementos pares con dos hijos es: %d", acum);
    printf("\nEl minimos elemento par divisor de la raiz es: %d", minimo);


    return 0;
}


/*
a) la sumatoria de los elementos de la cola múltiplos del último número ingresado en la cola, si no hubiese ninguno mostrar una leyenda.
b) el promedio de aquellos valores múltiplos de 5. Si no los hay, mostrar una leyenda.
*/
//COLAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *ultimo, int *acum, int *cont, float *acum_p, float *cont_p)
{
    if(aux.dato % *ultimo == 0 && aux.dato != *ultimo)
    {
        *acum = *acum + aux.dato;
        *cont = *cont + 1;
    }
    
    if(aux.dato % 5 == 0)
    {
        *acum_p = *acum_p + aux.dato;
        *cont_p = *cont_p + 1;
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
    int i,num, ultimo, acum = 0, cont = 0;
    float acum_p = 0, cont_p = 0;
    nodo* p=NULL;
    nodo* u=NULL;
    
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    
    while(num != -1)
    {
        ultimo = num;
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }
    
    printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
    {
    	mostrar(desacolar(&p), &ultimo, &acum, &cont, &acum_p, &cont_p);
    }
    
    if(cont == 0)
    {
        printf("\nNo hay elementos multiplos del ultimo.");
    }
    
    else
    {
        printf("\nLa sumatoria de los multiplos del ultimo es: %d", acum);
    }
    
    if(cont_p == 0)
    {
        printf("\nNo hay elementos multiplos de 5.");
    }
    
    else
    {
        printf("\nEl promedio de los multiplos de 5 es: %f", acum_p/cont_p);
    }
    
    return 0;
}



/*
a) Los dos elementos mas grandes de la pila y su posición.
b) La cantidad de elementos menores al segundo elemento ingresado a la pila. Si no lo hay, mostrar una leyenda
*/
//PILAS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *maximo1, int *maximo2, int *minimo, int *pos1, int *pos2, int *x, int *cant_ele)
{
    if(aux.dato > *maximo1) //Los dos elementos mas grandes de la pila y su posición.
    {
        *maximo1 = aux.dato;
        *pos1 = *x;
    }
    
    if(aux.dato > *maximo2 && aux.dato != *maximo1)
    {
        *maximo2 = aux.dato;
        *pos2 = *x;
    }
    
    if(aux.dato < *minimo && aux.dato != *minimo) //La cantidad de elementos menores al segundo elemento ingresado a la pila. Si no lo hay, mostrar una leyenda
    {
        *cant_ele = *cant_ele + 1;
    }
    
    *x = *x - 1;
    
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
    int i,num, maximo1 = 0, maximo2 = 0, minimo, pos1 = 0, pos2 = 0, x, cont_pos = 0, cant_ele = 0;
    nodo* p=NULL;

    printf("Ingrese un numero: \n");
   	scanf("%d",&num);
   	
   	maximo1 = num;
   	
    while(num != -1)
    {
        cont_pos = cont_pos + 1;
        if(cont_pos == 2)
       	{
       	    minimo = num;
       	}
        apilar(&p, crear_nodo(num));
       	printf("Ingrese un numero: \n");
       	scanf("%d", &num);
       	
    }

    x = cont_pos;
    
    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), &maximo1, &maximo2, &minimo, &pos1, &pos2, &x, &cant_ele);
    }
    
    printf("\nEl primero maximo es: %d", maximo1);
    printf("\nSe encunetra en la posicion: %d", pos1);
    printf("\nEl segundo maximo es: %d", maximo2);
    printf("\nSe encunetra en la posicion: %d", pos2);
    
    if(cant_ele == 0)
    {
        printf("\nNo hay elementos menores al segundo numero.");
    }
    else
    {
        printf("\nHay %d elementos menores al segundo elemento", cant_ele);
    }
   
    return 0;
}



/*
Diseñar una función que, dado un árbol binario de búsqueda, calcule el promedio de
aquellos nodos múltiplos de la raíz.
*/
//ARBOL BINARIO 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *cont, int *acum)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, cont, acum);
        printf("%d ",hoja->dato);
        if(hoja->dato % raiz == 0 && hoja->dato != raiz) //calcule el promedio de aquellos nodos múltiplos de la raíz.
        {
            *acum = *acum + hoja->dato;
            *cont = *cont + 1;
        }
        mostrar(hoja->der, raiz, cont, acum);
    }
    
    return;
}


int main ()
{
    int raiz, cont = 0, acum = 0;
    float promedio = 0;
    
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &cont, &acum);
    
    promedio = acum/cont;
    printf("\nEl promedio de los multiplos de la raiz es: %f", promedio);


    return 0;
}



/*
a) Calcule la cantidad de nodos hojas divisores de la raíz.
b) Calcule la cantidad de nodos impares con dos hijos.
*/
//ARBOL BINARIO 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *cont1, int *cont2)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, cont1, cont2);
        printf("%d ",hoja->dato);
        if((raiz % hoja->dato == 0) && (hoja->izq == NULL && hoja->der == NULL) && (hoja->dato != raiz)) //Calcule la cantidad de nodos hojas divisores de la raíz.
        {
            *cont1 = *cont1 + 1;
        }
        if((hoja->dato % 2 != 0) && (hoja->izq != NULL && hoja->der != NULL)) //Calcule la cantidad de nodos impares con dos hijos.
        {
            *cont2 = *cont2 + 1;
        }
        mostrar(hoja->der, raiz, cont1, cont2);
    }
    
    return;
}


int main ()
{
    int raiz, cont1 = 0, cont2 = 0;
    
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &cont1, &cont2);
    
    printf("\nLa cantidad de nodos hojas divisores de la raiz es: %d", cont1);
    printf("\nLa cantidad de nodos impares con dos hijos es: %d", cont2);
    
    return 0;
}



/*
a) Buscar el menor elemento del arbol divisor par de la raiz
b) Cantidad de nodos hojas multiplos de la raiz
*/
//ARBOL BINARIO 


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
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


void crear (treenode **hoja, int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja, int raiz, int *menor, int *cant_mult)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, menor, cant_mult);
        printf("%d ",hoja->dato);
        if(hoja->dato < *menor && hoja->dato % 2 == 0 && raiz % hoja->dato == 0) //Buscar el menor elemento del arbol divisor par de la raiz
        {
            *menor = hoja->dato;
        }
        if(hoja->dato % raiz == 0 && (hoja->izq == NULL && hoja->der == NULL)) //Cantidad de nodos hojas multiplos de la raiz
        {
            *cant_mult = *cant_mult + 1;
        }
        mostrar(hoja->der, raiz, menor, cant_mult);
    }
    
    return;
}
//8 3 10 1 6 15 4 7 13 

int main ()
{
    int raiz, menor, cant_mult = 0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    menor = raiz;
    mostrar (arbol, raiz, &menor, &cant_mult);

    printf("\nEl menor elemento divisor de la raiz es: %d", menor);
    printf("\nLa cantidad de nodos multiplos de la raiz es: %d", cant_mult);

    return 0;
}



/*
a) La sumatoria de numeros multiplos del ultimo elemento ingresado en la pila. Si no hubiera ningun numero mostrar una leyenda.
a) El valor minimo impar de la pila y su posicion. Si no lo hubiese mostrar una leyenda. 
*/
//PILAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int *acum, int ultimo, int *minimo, int *pos, int *x, int *cont_min)
{
    if(aux.dato % ultimo == 0 && aux.dato != ultimo)
    {
        *acum = *acum + aux.dato;
    }
    
    if(aux.dato < *minimo && aux.dato % 2 != 0 && aux.dato != *minimo)
    {
        *minimo = aux.dato;
        *cont_min = *cont_min + 1;
        *pos = *x;
    }
    
    *x = *x - 1;
    
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
    int i,num, ultimo, acum = 0, minimo, pos = 0, x, cont = 0, cont_min;
    nodo* p=NULL;
    
    printf("Ingrese un numero \n");
    scanf("%d",&num);

    while(num != -1)
    {
        cont = cont + 1;
        ultimo = num;
        apilar(&p, crear_nodo(num));
        minimo = num;
       	printf("Ingrese un numero \n");
       	scanf("%d",&num);
    }

    x = cont;

    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p), &acum, ultimo, &minimo, &pos, &x, &cont_min);
    }

    if(acum == 0)
    {
        printf("\nNo hay valores multiplos del ultimo.");
    }
    else
    {
        printf("\nLa suma de los elementos multiplos del ultimo es: %d", acum);
    }
    
    if(cont_min == 0)
    {
        printf("\nNo hay elementos minimo impar.");
    }
    else
    {
        printf("\nEl minimo elmento impar es %d y se encuentra en la posicion %d de la pila.", minimo, pos);
    }
    
    return 0;
}





/*
a) El promedio de los numeros mayores al tercer elemento ingresado en la cola. Si no hubiera ningun numero, mostrar una leyenda. 
b) La sumatoria de los dos elementos minimos de la cola.
*/
//COLAS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int tercero, float *acum_may, float *cont_may, int *minimo1, int *minimo2)
{
    if(aux.dato > tercero && aux.dato != tercero)
    {
        *acum_may = *acum_may + aux.dato;
        *cont_may = *cont_may + 1;
    }
    if(aux.dato < *minimo1) // && aux.dato != *minimo1)
    {
        *minimo1 = aux.dato;
    }
    if(aux.dato < *minimo2 && aux.dato != *minimo1)
    {
        *minimo2 = aux.dato;
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
    *p = *u = q; 
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
    int i,num, cont = 0, tercero = 0, minimo1, minimo2;
    float acum_may = 0, cont_may = 0;
    nodo* p=NULL;
    nodo* u=NULL;
    
    printf("Ingrese un numero");
    scanf("%d",&num);
    minimo1 = num;
    
    while(num != -1)
    {
        cont++;
        if(cont == 3)
        {
            tercero = num;
        }
        
        minimo2 = num;
        acolar(&p, &u, crear_nodo(num));
        printf("Ingrese un numero");
        scanf("%d",&num);
    }


    printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
    {
    	mostrar(desacolar(&p), tercero, &acum_may, &cont_may, &minimo1, &minimo2);
    }
    
    if(cont_may == 0)
    {
        printf("\nNo hay elementos mayores al tercer elemento.");
    }
    else
    {
        printf("\nEl promedio de los mayores al tercer elemento es: %f", acum_may/cont_may);
    }
    
    printf("\nLa sumatoria de los dos elementos menores es: %d", minimo1+minimo2);
    printf("\n%d", minimo1);
    printf("\n%d", minimo2);
    
    return 0;
}



/*REPASO PARA EL RECUPERATORIO DEL PRIMER PARCIAL*/

/*
Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).
Generar una lista nueva con el promedio de ambos números.
Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.
Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
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
    float promedio;
    struct lista2 *sig2;
}nodo2;


void crear (nodo *p)
{
    printf("\nIngrese el primer elemento: ");
    scanf("%d", &p->num1);
    printf("\nIngrese el primer elemento: ");
    scanf("%d", &p->num2);

    if (p->num1==0 && p->num2==0)
        p->sig=NULL;
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
        printf ("El primer elemento es: %d\n", p->num1);
        printf ("El segundo elemento es: %d\n", p->num2);
        mostrar (p->sig);
	}
	
	return;
}


void generar(nodo *p, nodo2 *q)
{
    while(p->sig!=NULL)
    {
        q->promedio = (p->num1 + p->num2) / 2;
        q->sig2 = (nodo2*)malloc(sizeof(nodo2));
        q=q->sig2;
        p=p->sig;
    }
    
    q->sig2=NULL;
}

void mostrar2 (nodo2 *q)
{
    if (q->sig2 !=NULL)
	{
        printf("\nEL promedio es: %f", q->promedio);
        mostrar (q->sig2);
	}
	
	return;
}


nodo* insertar1(nodo *p)
{
    nodo *aux;
    if((p->num1 + p->num2) > 15)
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num1=(p->num1)/2;
        aux->num2=(p->num2)/2;
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
        if((p->num1 + p->num2) > 15)
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num1=(p->num1)/2;
            aux->num2=(p->num2)/2;
            aux->sig=p->sig;
            p->sig=aux;

        }
        p=p->sig;
    }
}


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
        if(p->num1 % p->num2 == 0)//condicion de eliminacion
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
    p=(nodo*)malloc(sizeof(nodo));
    q=(nodo2*)malloc(sizeof(nodo2));
    crear(p);
    mostrar(p);
    generar(p, q);
    printf("\nLa lista con los valores sumados es: \n");
    p=insertar1(p);
    insertar2(p);
    printf("\nLa lista con insercion es: \n");
    mostrar(p);
    p=eliminar1(p);
    eliminar2(p);
    printf("\nLa lista con eliminacion es: \n");
    mostrar(p);

    return 0;
}

//va queriendo 























