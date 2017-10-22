#include <stdio.h>
#include <stdlib.h>
#include "Pelicula.h"

int main()
{
    Pelicula arrayPelicula[CANTIDAD_DE_PELICULAS];
    char seguir='s';
    int opcion=0;
    pelicula_inicializarArray(arrayPelicula,CANTIDAD_DE_PELICULAS);

    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n \n");
        scanf("%d",&opcion);
        if(opcion > 5)
        {
            printf("\nERROR: La opcion no existe. \n \n");
            system("pause");
            system("cls");
        }
        else{
        switch(opcion)
        {
            case 1:
                pelicula_altaPelicula(arrayPelicula,CANTIDAD_DE_PELICULAS);
                system("pause");
                printf("\nSe creo una nueva pelicula. \n \n");
                system("cls");
                break;
            case 2:
                pelicula_mostrarPelicula(arrayPelicula,CANTIDAD_DE_PELICULAS);
                pelicula_borrarPelicula(arrayPelicula,CANTIDAD_DE_PELICULAS);
                printf("\nSe borro la pelicula seleccionada. \n\n");
                system("pause");
                system("cls");
                break;
            case 3:
                pelicula_mostrarPelicula(arrayPelicula,CANTIDAD_DE_PELICULAS);
                pelicula_modificarPelicula(arrayPelicula,CANTIDAD_DE_PELICULAS);
                printf("\nSe modifico la pelicula seleccionada. \n \n");
                system("pause");
                system("cls");
               break;
            case 4:
                pelicula_generarPagina("salida.html", arrayPelicula, CANTIDAD_DE_PELICULAS);
                printf("\nSe genero un archivo HTML en la carpeta del proyecto. \n\n");
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }
      }
    }
    return 0;
}
