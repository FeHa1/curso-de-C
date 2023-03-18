/*
Desarrollar un programa en C (con funciones) que permita cargar una matriz de nxn elementos. Mostrarla. Determinar si es una matriz antisimétrica.

Una matriz antisimétrica es aquella matriz cuadrada que coincide con la opuesta de su traspuesta.

Ejemplo de matriz antisimétrica:
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
        }
    }
}



void anti_sim(int mat[3][3], int filas, int columnas)
{
    int i, j, neg, cont;
    
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i != j)
            {
                if (mat[i][j] == mat[j][i]*-1)
                {
                    cont++
                    
                }
            }
        }
    }

    printf("\nEsta matriz es antisimetrica, los valores son: %d", neg);
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
    cargar(mat, filas, columnas);
    anti_sim(mat, filas, columnas);
    mostrar(mat, filas, columnas);
    
    return 0;
}