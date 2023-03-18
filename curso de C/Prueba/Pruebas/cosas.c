
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
    int i, j, cont = 0;

    for (i = 0; i < filas; i ++)
    {
        for (j = 0; j < columnas; j ++)
        {
            
            if (mat[i][j] == mat[j][i])
            {
                cont += 1;
            }    
        }
    }
    if (cont == filas * columnas)
    {
        printf("\nEsta matriz es simetrica");
    }
    else
    {
        printf("\nEsta matriz no es simetrica.");
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
    simetrica(mat, filas, columnas);

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
    //simetrica(mat, filas, columnas);
    
    return 0;
}

