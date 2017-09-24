#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

/** \brief Funcion que pide Nombre por consola y le podemos dar la cantidad de intentos que deseemos.
 *
 * \param destino
 * \param mensaje
 * \param mensajeError
 * \param intentos
 * \param limite
 * \return 0(OK) / -1(ERROR)
 *
 */
int val_ingresarNombrePorTecladoConIntentos(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = ERROR_INGRESAR_NOMBRE_POR_TECLADO_CON_INTENTOS;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarNombre(buffer) == ERROR_VALIDAR_NOMBRE)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = OK;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Funcion que pide Edad por consola y le podemos dar la cantidad de intentos que deseemos.
 *
 * \param destino
 * \param mensaje
 * \param mensajeError
 * \param intentos
 * \param limite
 * \return 0(OK) / -2(ERROR)
 *
 */
int val_ingresarEdadPorTecladoConIntentos(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = ERROR_INGRESAR_EDAD_POR_TECLADO_CON_INTENTOS;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarEdad(buffer) == ERROR_VALIDAR_EDAD)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = OK;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Funcion que pide DNI por consola y le podemos dar la cantidad de intentos que deseemos.
 *
 * \param destino
 * \param mensaje
 * \param mensajeError
 * \param intentos
 * \param limite
 * \return 0(OK) / -3(ERROR)
 *
 */
int val_ingresarDniPorTecladoConIntentos(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = ERROR_INGRESAR_DNI_POR_TECLADO_CON_INTENTOS;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarDni(buffer) == ERROR_VALIDAR_DNI)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = OK;
                break;
            }
        }
    }
    return retorno;
}

// ********************************      VALIDACIONES     *************************************************************

/** \brief Funcion que valida nombres.
 *
 * \param buffer
 * \return 0(OK) / -4(ERROR)
 */
int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = OK;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'ñ' || buffer[i] > 'Ñ'))
        {
            retorno = ERROR_VALIDAR_NOMBRE;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Funcion que valida la edad ingresada (numeros enteros) .
 *
 * \param buffer
 * \return 0(OK) / -5(ERROR)
 */
int val_validarEdad(char* buffer)
{
    int i=0;
    int retorno = OK;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = ERROR_VALIDAR_EDAD;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Funcion que valida DNI.
 *
 * \param buffer
 * \return 0(OK) / -6(ERROR)
 */
int val_validarDni(char* buffer)
{
    int i=0;
    int retorno = OK;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = ERROR_VALIDAR_DNI;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief fgets Personalizado
 *
 * \param buffer
 * \param limite
 * \param archivo
 *
 */
void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fflush(stdin);
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}
