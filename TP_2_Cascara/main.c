#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "funciones.h"

int main()
{
    char menos18[LONGITUD],mas18[LONGITUD], mas35[LONGITUD];
    char seguir='s';
    int opcion=0,i;
    EPersona arrayPersona[LONGITUD];
    iniciarPersona(arrayPersona);
    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("\n2- Borrar persona\n");
        printf("\n3- Imprimir lista ordenada por  nombre\n");
        printf("\n4- Imprimir grafico de edades\n\n");
        printf("\n5- Salir\n");

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                persona_altaPersona(arrayPersona,obtenerEspacioLibre(arrayPersona,LONGITUD));
                system("cls");
                break;
            case 2:
                persona_bajaPersona(arrayPersona);
                system("cls");
                break;
            case 3:
                listarPersonas(arrayPersona);
                system("cls");
                break;
            case 4:
                graficoEdad(arrayPersona,menos18,mas18, mas35);
                for(i=0; i<LONGITUD; i++)
                {
                    printf("%c \t %c \t %c \n", menos18[i], mas18[i], mas35[i]);
                }
                printf("\n <18 \t 19-35\t >35 \n \n");
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
