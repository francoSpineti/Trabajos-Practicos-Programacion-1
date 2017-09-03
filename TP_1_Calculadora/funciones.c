#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

/** \brief Esta funcion calcula la suma de dos variables flotantes
 *
 * \param a (de tipo float)
 * \param b (de tipo float)
 * \param resultadoSuma (puntero)
 * \return retorna el resultado de a+b a traves del puntero *resultadoSuma
 *
 */
void calcularSuma(float a, float b,float*resultadoSuma){
    *resultadoSuma = a + b;
}

/** \brief Esta funcion calcula la resta de dos variables flotantes
 *
 * \param a (de tipo float)
 * \param b (de tipo float)
 * \param resultadoSuma (puntero)
 * \return retorna el resultado de a+b a traves del puntero *resultadoResta
 *
 */
void calcularResta(float a, float b,float*resultadoResta){
    *resultadoResta = a-b;
}

/** \brief Esta funcion multiplicacion la suma de dos variables flotantes
 *
 * \param a (de tipo float)
 * \param b (de tipo float)
 * \param resultadoSuma (puntero)
 * \return retorna el resultado de a+b a traves del puntero *resultadoMultiplicacion
 *
 */
void calcularMultiplicacion(float a, float b,float*resultadoMultiplicacion){
    *resultadoMultiplicacion = a*b;
}

/** \brief Esta funcion calcula la division de dos variables flotantes
 *
 * \param a (de tipo float)
 * \param b (de tipo float)
 * \param resultadoSuma (puntero)
 * \return retorna el resultado de a+b a traves del puntero *resultadoDivision
 *
 */
void calcularDivision(float a, float b,float*resultadoDivision){
    while(b == 0){
      printf("ERROR, Reingrese el numero  : \n");
      scanf("%f",&b);
    }
    *resultadoDivision = a/b;
}

/** \brief En esta funcion se calcula el factorial del primer numero que vamos a ingresar
 *
 * \param a (float)
 * \return retorna el valor del factoreo a traves de una variable float
 *
 */
float calcularFactorialDelPrimerNumeroIngresado(float a){
   float respuesta;
   if(a == 1 || a == 0){
        return 1;
   }
   respuesta = a*calcularFactorialDelPrimerNumeroIngresado(a-1);
   return respuesta;
}

/** \brief En esta funcion se calcula el factorial del segundo numero que vamos a ingresar
 *
 * \param b (float)
 * \return retorna el valor del factoreo a traves de una variable float
 *
 */
float calcularFactorialDelSegundoNumeroIngresado(float b){
   float respuesta;
   if(b == 1 || b == 0){
        return 1;
   }
   respuesta = b*calcularFactorialDelPrimerNumeroIngresado(b-1);
   return respuesta;
}

/** \brief En esta funcion se muestran todas los resultados de las operaciones echas anteriormente a travez de punteros.
 *
 * \param a (float)
 * \param b (float)
 * \param resultadoSuma (puntero float)
 * \param resultadoResta (puntero float)
 * \param resultadoMultiplicacion (puntero float)
 * \param resultadoDivision (puntero float)
 * \return
 *
 */
void mostrarTodasLasOperaciones(float a, float b, float*resultadoSuma,float*resultadoResta,float*resultadoMultiplicacion,float*resultadoDivision){
    *resultadoSuma = a + b;
    *resultadoResta = a-b;
    *resultadoMultiplicacion = a*b;
    *resultadoDivision = a/b;
    printf("\nel primer numero ingresado fue : %.2f \n",a);
    printf("el segundo numero ingresado fue : %.2f \n",b);
    printf("La suma es : %.2f \n",*resultadoSuma);
    printf("La resta es : %.2f \n",*resultadoResta);
    printf("La division es : %.2f \n",*resultadoDivision);
    printf("La multiplicacion es : %.2f \n",*resultadoMultiplicacion);
}
