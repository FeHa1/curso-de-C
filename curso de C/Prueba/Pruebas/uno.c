/*Ingresar numeros hasta que dicho numero sea cero. Calcular y mostrar:
a) La cantidad de numeros pares multiplos de 5.
b) La cantidad de numeros primos.
c) El promedio de aquellos numeros impares multiplos de 3.
*/

#include <stdio.h>

int main()
{
    int num, contador = 0, primos = 0, cont1 = 0, cont2 = 0, acum = 0, i; 
    // en python seria ----> num = int(input("Ingrese un numero: ")) 
    // pero en C es con 'printf' como en el siguiente ejemplo
    printf("ingrese un numero: "); 
    scanf("%d" , &num);  //el segundo parametro es el nombre de la variable, a la que se le coloca '&' para reservar espacio de memoria en la variable
   // el '"%d"' se utiliza cuando (en lenguaje python) un dato es "int", cuando es '"%f"' es float y '"%s"' es char.
    while (num != 0)  //los parentesis en C son obligatorios. Y en lugar de ':' para poner adentro del 'while' se usan solo las llaves.
    {
        if(num % 2 == 0 && num % 5 == 0) // el '&&' vendria a ser el 'and' de Python
        {
            contador ++; // vendria a ser el 'cont += 1' del Python. Pero cuando viene a ser 'cont += 2' ahi si que no se usa el 'cont ++' 
        }

        if(num % 2 != 0 && num % 3 == 0)
        {
            acum = acum + num;
            cont1 ++; //aca debo usar otro contador para que no se mezcle con el anterior
        }

        for(i = 1; i < num; i++) //es el 'for i in range(0, num)' del Python. Y tambien en lugar de ',' se ponen ';' para ir separando los datos (en este caso)
        {
            if(num % i == 0) 
            {
                cont2++; 
            }
        }
        if(cont2 == 1)
        {
            primos++;
        }
        cont2 = 0;
    
        printf("ingrese un numero: "); 
        scanf("%d" , &num);
    }

    printf("La cantidad de numeros pares multiplos de 5 es %d: ", contador); //el '%d' es porque a C hay que decirle si o si que tipo de datos va a mostrar.

    if (contador != 0)
    {
        printf("El promedio de los impares multiplo de 3 es %d:", acum/cont1);
    }

    else
    {
        printf("No se ingresaron impares multiplos de 3");
    }
    printf("la cantidad de primos es %d: ", primos);

} 



/*Ejemplos de funciones en C*/

#include <stdio.h>

/*
tipo Retorno int, char, float, double
nombre funcion (parametros)

parametros -> tipo nombre, tipo nombre2, tipo  nombre3

return valor 
*/


int sumaNros(int nro) // variable global 
{
  int i,  suma = 0;
  for(i=1; i<=nro; i++)
    {
      suma +=i;
    }

  return suma;
}

void mostrarResultado(int valor) // variable global
{
   printf("La suma es %d", valor);
}

int main() // esta es la variable local donde pongo todas las variables que voy a usar, las llamo aca
{
    int nro, resultado;
    printf("Ingrese un nro: ");
    scanf ("%d", &nro);
    resultado = sumaNros(nro);
    mostrarResultado(resultado);

    return 0;
}

/* Ejemplo de vectores en C*/

#include <stdio.h> 

void cargar (int arr[])
{
    int i; 
    for (i = 0, i < 10, i ++)
    {
        printf("\nIngrese un valor: ");
        scanf("%d", &arr[i]); // el arreglo toma el valor de "i"
    }
}

void mostrar(int vec[])
{
    int i;
    for (i = 0, i < 10, i ++)
    {
        printf("\nEl valor %d pertenece a la posicion %d", vec[i], i); // vec[i] es el la posicion en el arreglo que ocupa "i", 
                                                                       // e "i" es el numero en sí
    }
}

int main()
{
    int vec[10];
    cargar(vec);
    mostrar(vec);

    return 0;
}


/* Ejercicio de vectores para evaluar conocimientos*/

// Ingresar las edades de un curso y mostrar las mayores al promedio 

#include <stdio.h> 

void cargar (int arr[])
{
    int i; 
    for (i = 0, i < 10, i ++)
    {
        printf("\nIngrese un valor: ");
        scanf("%d", &arr[i]); // el arreglo toma el valor de "i"
    }
}

void mostrar(int vec[])
{
    int i;
    for (i = 0, i < 10, i ++)
    {
        printf("\nEl valor %d pertenece a la posicion %d", vec[i], i); // vec[i] es el la posicion en el arreglo que ocupa "i", 
                                                                       // e "i" es el numero en sí
    }
}

float promedioEdades(vec[]) // es float porque me va a devolver numeros con coma ya que quiero sacar un promedio
{
    int suma = 0, cont; // aca se pone numero sin coma porque solo estoy sumando, y prefiero sumar numeros sin coma
    // se recomienda que las variables ("suma" en este caso) se inicializen en 0 para que el C no le asigne una por sí mismo que puede quedar como un valor fijo sin querer

    for (cont = 0; cont < 10; cont ++) 
    {
        suma += vec[cont]; 
    }

    return suma/10; // con esto saco el promedio de una y no lo tengo que hacer en otra funcion
}

void mostrarMayores(int vec[], float promedio)
{
    int i;
    for (i = 0, i < 10, i ++)
    {
        if (vec[i] > promedio)
        {
            printf("\nEl valor %d pertenece a la posicion %d", vec[i], i);
        }
    }
}

int main()
{
    int vec[10];
    float promedio; 
    cargar(vec);
    //mostrar(vec); lo comento solo para que no se muestren tantos numeros
    promedio = promedioEdades(vec);
    printf("%f", promedio);
    mostrarMayores(vec, promedio);

    return 0;
}




/*--------------------------------------------------------------------------------------------------------------------------------*/

/*Introducir numeros enteros hasta ingresar un 0 o un numero negativo, calcular el promedio de los numeros primos*/

#include <stdio.h>

int main()
{
    int prim=0, acum=0, cont=0, num, i;

    printf("Ingrese numeros: ");
    scanf("%d", &num);

    while(num>0)
    {
        for(i=2; i<num; i++) //pongo 2 porque ya se que el 1 es divisor de todos, entonces epiezo directamente en el 2
        {
            if(num % i == 0)
            {
                cont++;
            }
        }

        if(cont == 0)
        {
            acum = acum + num;
            prim++;
        }

        cont=0;

        printf("Ingrese numeros: ");
        scanf("%d", &num);
    }

    printf("El promedio es %d", acum/prim);
}



/*Generar los 4 primeros numeros perfectos*/
// 6 = 1 + 2 + 3

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






#include <stdio.h> 

int cargar(int a[])
{
    int i=0, num;

    printf("Ingrese valor: ");
    scanf("%d", &num);

    while(num != 0)
    {
        if(num%2 == 0)
        {
            a[i] = num;
            i++;
        }

        printf("Ingrese valor: ");
        scanf("%d", &num);
    }

    return i;
}

void mostrar(int a[], int d)
{

}


int main()
{
    int vec[30];

    cargar(vec[]);

    return 0;
}



/*
Ingresar numeros enteros hasta ingresar un 0 y cargar un arreglo con aquellos numeros impares multiplos de 3. Mostrarlo.
Si no tiene elementos mostrar un cartel. 
Si lo tuviese, insertar luego de cada elemento negativo su consecuente. 
Mostrar el arreglo.
*/


#include <stdio.h>

int cargar(int vec[])
{
    int i, num;
    
    printf("\nIngrese los datos del vector: ");
    scanf("%d", &num);
        
    while(num != 0)
    {
        if(num%2 != 0 && num%3 == 0)
        {
            vec[i] = num;
            i++;
        }
        
        else
        {
            printf("\nNo tiene numero impares multiplos de 3.");
        }
        
        if(num < 0)
        {
            vec[i] = num + 1;
            i++;
        }
        
        
        printf("\nIngrese los datos del vector: ");
        scanf("%d", &num);
    }
    
    return i;
}


void mostrar(int vec[])
{
    int i, num;
    
    for(i=0; i<num; i++)
    {
        printf("\nLos valores son: %d", vec[i]);    
    }
}


int main()
{
    int vec[30], i, num;
    printf("\nIngrese los datos del vector: ");
    scanf("%d", &vec[i]);
    cargar(vec[30]);
    printf("\nLa lista con los numeros impares divisibles por 3 es: ");
    mostrar(vec[30]);
    
    return 0;
}




