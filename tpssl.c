
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CENTINELA '#'

char alfabeto[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', 'F'};

int tablaAFD[][12] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 3},
        {3, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, 3},
    };

    int estadoDeAceptacion[] = {0, 0, 1, 1, 0};

int main(){
    int estadoInicial = 0;

    char cadena[100];
    printf("Ingresar cadena\n");
    scanf("%s", cadena);
    char caracter;
    int estadoActual = estadoInicial;
    char palabra[50];
    int i, j, k, posicionDelCaracter;
    i = j = k = posicionDelCaracter = 0;

    printf("Cadenas validas:\n");

    while((caracter = cadena[i]) != '\0')
    {
        //printf("caracter %c \n", caracter);
        if(caracter != CENTINELA)
        {
            posicionDelCaracter = -1;
            for(j = 0; j < 12; j++)
            {
                if(alfabeto[j] == caracter)
                {
                    posicionDelCaracter = j;

                }
            }
            //printf("%d \n", posicionDelCaracter);

            if(posicionDelCaracter != -1)
            {
                //printf("%d \n", tablaAFD[estadoActual][posicionDelCaracter]);
                if(tablaAFD[estadoActual][posicionDelCaracter] != -1)
                {
                    estadoActual = tablaAFD[estadoActual][posicionDelCaracter];
                    palabra[k] = caracter;
                    k++;
                }

            }

        }
        else
        {
            if(estadoDeAceptacion[estadoActual])
            {
            	palabra[k]='\0';
                printf("%s \n", palabra);
            }
            estadoActual = estadoInicial;
            k = 0;
        }

        i++;
    }
    
    if(estadoDeAceptacion[estadoActual])
    {
    	palabra[k]='\0';
        printf("%s \n", palabra);
    }

    return 0;
}
