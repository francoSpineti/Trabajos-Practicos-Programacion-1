#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float x,y,z,w;
    float resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("\n2- Ingresar 2do operando (B=y)\n");
        printf("\n3- Calcular la suma (A+B)\n");
        printf("\n4- Calcular la resta (A-B)\n");
        printf("\n5- Calcular la division (A/B)\n");
        printf("\n6- Calcular la multiplicacion (A*B)\n");
        printf("\n7- Calcular el factorial (A!)\n");
        printf("\n8- Calcular todas las operacione\n");
        printf("\n9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\n Ingrese el primer numero : \n");
				scanf("%f",&x);
                break;
            case 2:
                printf("\n Ingrese el primer numero : \n");
				scanf("%f",&y);
                break;
            case 3:
                calcularSuma(x,y,&resultadoSuma);
                printf("La suma es : %.2f \n",resultadoSuma);
                break;
            case 4:
                calcularResta(x,y,&resultadoResta);
                printf("La resta es : %.2f \n",resultadoResta);
                break;
            case 5:
                calcularDivision(x,y,&resultadoDivision);
                printf("La division es : %.2f \n",resultadoDivision);
                break;
            case 6:
                calcularMultiplicacion(x,y,&resultadoMultiplicacion);
                printf("La multiplicacion es : %.2f \n",resultadoMultiplicacion);
                break;
            case 7:
                z = calcularFactorialDelPrimerNumeroIngresado(x);
                printf("El factorial del primer numero es : %.2f \n",z);
                w = calcularFactorialDelSegundoNumeroIngresado(y);
                printf("El factorial del segundo numero es : %.2f \n",w);
                break;
            case 8:
                mostrarTodasLasOperaciones(x,y,&resultadoSuma,&resultadoResta,&resultadoDivision,&resultadoMultiplicacion);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
