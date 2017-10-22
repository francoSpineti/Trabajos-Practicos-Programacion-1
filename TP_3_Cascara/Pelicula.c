#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pelicula.h"
#include "Validar.h"

// ****************** FUNCIONES ESTATICAS ***********************************
static int idAutoincrementable = 0;
static int pelicula_generarIDAutoincrementable(Pelicula* arrayPelicula,int longitud);
static int pelicula_buscarPosicionLibre(Pelicula* arrayPelicula,int longitud);

/** \brief genera un Id que se va incrementando de a 1.
 *
 * @param longitud
 * @param arrayPelicula
 * @return retorna el id +1.
 */
static int pelicula_generarIDAutoincrementable(Pelicula* arrayPelicula,int longitud)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/** \brief me devuelve el index del primer item vacio de la array, si esta todo ocupado devuelve -1, si hay una posicion libre devuelve i.
 *
 * \param arrayPelicula
 * \param longitud
 * \return -1 error / la posicion del array
 */
static int pelicula_buscarPosicionLibre(Pelicula* arrayPelicula,int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPelicula != NULL && longitud >= 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPelicula[i].flagEstado == PELICULA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}
// **********************************************************     FIN FUNCIONES ESTATICAS    *******************************************************************************************
/** \brief funcion que retorna el indice del array por el ID, verifica si EXISTE O NO el indice.
 *
 * @param arrayPelicula
 * @param longitud
 * @param id
 * @return retorna el indice del array
 */
int pelicula_buscarIndicePorId(Pelicula* arrayPelicula,int longitud,int id)
{
    int i;
    int retorno = -1;
    if(arrayPelicula != NULL && longitud >= 0 && id >= 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPelicula[i].flagEstado == PELICULA_OCUPADA)
            {
                if(id == arrayPelicula[i].idPelicula)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief  inicializamos el array, que todos los flags esten libres.
 *
 * \param longitud
 * \param arrayPelicula
 * \return 0 = ok
 */
int pelicula_inicializarArray(Pelicula* arrayPelicula,int longitud)
{
    int i;
    for(i=0; i < longitud; i++)
    {
        arrayPelicula[i].flagEstado = PELICULA_LIBRE;
    }
    return 0;
}

/** \brief Damos de alta una nueva pelicula.
 *
 * @param longitud
 * @param arrayPelicula
 * @return 0 ok / -1 error
 */
int pelicula_altaPelicula(Pelicula* arrayPelicula,int longitud)
{
    int indexVacio = pelicula_buscarPosicionLibre(arrayPelicula,longitud);
    int idNuevo;
    int retorno = -1;
    char bTitulo[50];
    char bGenero[50];
    char bDescripcion[200];
    char bPuntaje[3];
    char bDuracion[3];
    char bLink[300];

    if(arrayPelicula != NULL && indexVacio >=0 && longitud >= 0)
    {
        if(val_getTitulo(bTitulo,"Ingrese titulo de la pelicula: \n","ERROR: Pelicula invalida.\n \n",2,50)== 0)
        {
            if(val_getGenero(bGenero,"Ingrese el genero de la pelicula: \n","ERROR: Genero invalido. \n \n",2,50)== 0)
            {
                if(val_getDescripcion(bDescripcion,"Ingrese una descripcion de la pelicula: \n","ERROR: Descripcion invalida. \n \n",2,200)== 0)
                {
                    if(val_getDuracion(bDuracion,"Ingrese cuantas horas dura la pelicula : \n","ERROR: Duracion invalida. \n \n",2,6)== 0)
                    {
                        if(val_getPuntaje(bPuntaje,"Ingrese un puntaje sobre la pelicula (De 1 a 10): \n","ERROR: Puntaje invalido. \n \n",2,3)== 0)
                        {
                            if(val_getLink(bLink,"Ingrese Link de la Imagen: \n","ERROR: Link invalido. \n \n",2,300)== 0)
                            {
                                idNuevo = pelicula_generarIDAutoincrementable(arrayPelicula,longitud);
                                arrayPelicula[indexVacio].flagEstado = PELICULA_OCUPADA;
                                arrayPelicula[indexVacio].idPelicula = idNuevo;
                                strncpy(arrayPelicula[indexVacio].titulo,bTitulo,50);
                                strncpy(arrayPelicula[indexVacio].genero,bGenero,50);
                                strncpy(arrayPelicula[indexVacio].descripcion,bDescripcion,50);
                                arrayPelicula[indexVacio].duracion = atoi(bDuracion);
                                arrayPelicula[indexVacio].puntaje = atoi(bPuntaje);
                                strncpy(arrayPelicula[indexVacio].linkImagen,bLink,300);
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Modificamos los datos de una pelicula
 *
 * @param longitud
 * @param arrayPelicula
 * @return 0 ok / -1 error
 */
int pelicula_modificarPelicula(Pelicula* arrayPelicula,int longitud)
{
    int index;
    int retorno = -1;
    char bTitulo[50];
    char bGenero[50];
    char bDescripcion[200];
    char bPuntaje[50];
    char bDuracion[3];
    char bID[4];

    if(arrayPelicula != NULL && longitud >= 0)
    {
        if(val_getID(bID,"Ingrese el Id de la pelicula a modificar: \n","ERROR: ID no valido o no existe. \n \n",2,4)==0)
        {
            index = pelicula_buscarIndicePorId(arrayPelicula,longitud,atoi(bID));

            if(index != -1)
            {
                if(val_getTitulo(bTitulo,"Ingrese titulo de la pelicula a modificar: \n","ERROR: Pelicula invalida.\n \n",2,50)== 0)
                {
                    if(val_getGenero(bGenero,"Ingrese el genero de la pelicula a modificar: \n","ERROR: Genero invalido. \n \n",2,50)== 0)
                    {
                        if(val_getDescripcion(bDescripcion,"Ingrese una descripcion de la pelicula a modificar: \n","ERROR: Descripcion invalida. \n \n",2,200)== 0)
                        {
                            if(val_getDuracion(bDuracion,"Ingrese la duracion de la pelicula a modificar: \n","ERROR: Duracion invalida. \n \n",2,6)== 0)
                            {
                                if(val_getPuntaje(bPuntaje,"Ingrese un puntaje sobre la pelicula a modificar (De 1 a 10): \n","ERROR: Puntaje invalido. \n \n",2,3)== 0)
                                {
                                        arrayPelicula[index].flagEstado = PELICULA_OCUPADA;
                                        strncpy(arrayPelicula[index].titulo,bTitulo,50);
                                        strncpy(arrayPelicula[index].genero,bGenero,50);
                                        strncpy(arrayPelicula[index].descripcion,bDescripcion,50);
                                        arrayPelicula[index].duracion = atoi(bDuracion);
                                        arrayPelicula[index].puntaje = atoi(bPuntaje);
                                        retorno = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Elimina una Pelicula por el ID ingresado.
 *
 * @param arrayPelicula
 * @param longitud
 * @return -1 si da error la funcion / 0 si esta todo ok.
 */
int pelicula_borrarPelicula(Pelicula* arrayPelicula,int longitud)
{
    int index;
    int retorno = -1;
    char bID[4];

    if(arrayPelicula != NULL && longitud >= 0)
    {
        if(val_getID(bID,"Ingrese el ID de la pelicula a Eliminar: \n","ERROR : ID no valido. \n\n",2,4)== 0)
        {
            index = pelicula_buscarIndicePorId(arrayPelicula,longitud,atoi(bID));
            if(index != -1)
            {
                arrayPelicula[index].flagEstado = PELICULA_LIBRE;
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief muestra la lista de las peliculas cargadas.
 *
 * @param arrayPelicula
 * @param longitud
 * @return -1 si da error la funcion / 0 si esta todo ok.
 */
int pelicula_mostrarPelicula(Pelicula* arrayPelicula, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPelicula != NULL && longitud >= 0)
    {
        for(i=0; i < longitud ; i++)
        {
            if(arrayPelicula[i].flagEstado == PELICULA_OCUPADA)
            {
                printf("\n \n \n ID: %d \n - Titulo: %s \n - Genero: %s \n - Descripcion: %s \n - Duracion: %d \n - Puntaje: %d \n\n\n",arrayPelicula[i].idPelicula,
                       arrayPelicula[i].titulo,
                       arrayPelicula[i].genero,
                       arrayPelicula[i].descripcion,
                       arrayPelicula[i].duracion,
                       arrayPelicula[i].puntaje);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Genera un HTML con una imagen y los datos de la pelicula que se dio de alta.
 *
 * @param archivoSalida
 * @param arrayPelicula
 * @param longitud
 */
void pelicula_generarPagina(char* archivoSalida, Pelicula* arrayPelicula, int longitud)
{
    FILE* fArchivo;
    int i;

    char buffer[403] = "<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
                       "<meta name='viewport' content='width=device-width, initial-scale=1'>\n<title>Lista peliculas</title>\n"
                       "<link href='css/bootstrap.min.css' rel='stylesheet'>\n<link href='css/custom.css' rel='stylesheet'>"
                       "</head>\n<body>\n<div class='container'>\n<div class='row'>";
    char duracion[3];
    char puntaje[3];

    if(arrayPelicula != NULL && longitud >= 0)
    {
        fArchivo = fopen(archivoSalida, "w");
        fprintf(fArchivo, buffer);

        for(i=0; i < longitud ; i++)
        {
            if(arrayPelicula[i].flagEstado == PELICULA_OCUPADA)
            {
                fprintf(fArchivo, "%s", "\n<article class='col-md-4 article-intro'>"
                        "\n<a href='#'>"
                        "\n<img class='img-responsive img-rounded' src='");
                fprintf(fArchivo, arrayPelicula[i].linkImagen);
                fprintf(fArchivo, "%s", "'"
                        "alt=''>"
                        "\n</a>"
                        "\n<h3>"
                        "\n<a href='#'>");
                fprintf(fArchivo,arrayPelicula[i].titulo);
                fprintf(fArchivo, "%s", "</a>"
                        "\n</h3>"
                        "\n<ul>"
                        "\n<li>Genero:");
                fprintf(fArchivo,arrayPelicula[i].genero);
                fprintf(fArchivo,"%s", "</li>"
                        "\n<li>Puntaje:");
                fprintf(fArchivo,itoa(arrayPelicula[i].puntaje,puntaje,10));
                fprintf(fArchivo,"%s", "</li>"
                        "\n<li>Duracion:");
                fprintf(fArchivo,itoa(arrayPelicula[i].duracion,duracion,10));
                fprintf(fArchivo,"%s","</li>"
                        "\n</ul>"
                        "\n<p>");
                fprintf(fArchivo,arrayPelicula[i].descripcion);
                fprintf(fArchivo,"%s","</p>"
                        "\n</article>");
            }
        }
        fprintf(fArchivo, "%s", "\n</div>"
                "\n</div>"
                "\n<script src='js/jquery-1.11.3.min.js'></script>"
                "\n<script src='js/bootstrap.min.js'></script>"
                "\n<script src='js/ie10-viewport-bug-workaround.js'></script>"
                "\n<script src='js/holder.min.js'></script>"
                "\n</body>"
                "\n</html>");
    }
    fclose(fArchivo);
}
