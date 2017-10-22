#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"
#define MAX_INPUT_BUFFER 4096
#define esBlanco(x) ((x) == ' ' || (x) == '\t'? 1:0)

/** \brief fgets personalizado
 *
 * @param buffer
 * @param limite
 * @param archivo
 */
void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fflush(stdin);
    fgets(buffer, limite,archivo);
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

/** \brief pide titulo de la pelicula por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el titulo. / -1 si tiene un ERROR.
 */
int val_getTitulo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarTitulo(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide genero de la pelicula por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el genero. / -1 si tiene un ERROR.
 */
int val_getGenero(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarGenero(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide descripcion de la pelicula por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la descripcion. / -1 si tiene un ERROR.
 */
int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarDescripcion(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide id por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la id. / -1 si tiene un ERROR.
 */
int val_getID(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarID(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide cuit por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la edad. / -1 si tiene un ERROR.
 */
int val_getPuntaje(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);
            if(val_validarPuntaje(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide cuit por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente la edad. / -1 si tiene un ERROR.
 */
int val_getDuracion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarDuracion(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide link de la imagen de la pelicula por consola.
 *
 * @param   destino
 * @param   mensaje
 * @param   mensajeError
 * @param   intentos
 * @param   limite
 * @return  0 si valido correctamente el titulo. / -1 si tiene un ERROR.
 */
int val_getLink(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarLink(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

// ******************************************* VALIDACIONES **************************************************

/** \brief valida el titulo de la pelicula.
 *
 * @param buffer
 * @return 0 OK / -1 si el titulo esta mal ingresado.
 */
int val_validarTitulo(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (esBlanco(buffer[i]) == 0) && (buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/** \brief valida el genero de la pelicula.
 *
 * @param buffer
 * @return 0 OK / -1 si el genero esta mal ingresado.
 */
int val_validarGenero(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/** \brief valida la descripcion de la pelicula.
 *
 * @param buffer
 * @return 0 OK / -1 si la descripcion esta mal ingresado.
 */
int val_validarDescripcion(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (esBlanco(buffer[i]) == 0) && (buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/** \brief valida un ID.
 *
 * @param buffer
 * @return 0 OK / -1 si la edad esta mal ingresada.
 */
int val_validarID(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/** \brief valida el puntaje.
 *
 * @param buffer
 * @return 0 OK / -1 si el puntaje esta mal ingresada.
 */
int val_validarPuntaje(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n') &&  buffer[0] == 0)
            {
                retorno = -1;
                break;
            }
            if(i == 1 && buffer[0] == 1 &&  buffer[i]== 0)
                retorno = 0;
            else if(i == 1)
                retorno = -1;

            i++;
        }
    }
    return retorno;
}

/** \brief valida la duracion.
 *
 * @param buffer
 * @return 0 OK / -1 si la duracion esta mal ingresada.
 */
int val_validarDuracion(char* buffer)
{
    int i=0;
    int retorno = 0;
    if(strcmp(buffer, "") == 0)
    {
        retorno = -1;
    }
    else
    {
        while(buffer[i] != '\0')
        {
            if((buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/** \brief valida el link de la imagen
 *
 * @param buffer
 * @return  0 OK / -1 si el link esta mal ingresado.
 */
int val_validarLink(char* buffer)
{
   int i=0, retorno = 0;

   if(strcmp(buffer, "") == 0)
   {
       retorno = -1;
   }
   else
   {
       while(buffer[i] != '\0')
       {
          // if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < '0' || buffer[i] > '9')&& (buffer[i] != '\n')&& (buffer[i] < 33 || buffer[i] > 46))
           if(buffer[i] < 33 || buffer[i] > 122)
           {
               retorno = -1;
               break;
           }
           i++;
       }
   }
   return retorno;
}
