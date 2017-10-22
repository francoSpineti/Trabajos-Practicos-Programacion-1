#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
typedef struct{
    int idPelicula;
    int duracion;
    int flagEstado;
    int puntaje;
    char titulo[50];
    char genero[50];
    char descripcion[200];
    char linkImagen[300];
}Pelicula;
#endif // PELICULA_H_INCLUDED

#define PELICULA_LIBRE 0
#define PELICULA_OCUPADA 1
#define CANTIDAD_DE_PELICULAS 100

int pelicula_buscarIndicePorId(Pelicula* arrayPelicula,int longitud,int id);

int pelicula_inicializarArray(Pelicula* arrayPelicula,int longitud);

int pelicula_altaPelicula(Pelicula* pelicula,int longitud);

int pelicula_modificarPelicula(Pelicula* pelicula,int longitud);

int pelicula_borrarPelicula(Pelicula* pelicula,int longitud);

int pelicula_mostrarPelicula(Pelicula* arrayPelicula, int longitud);

void pelicula_generarPagina(char* archivoSalida, Pelicula* arrayPelicula, int longitud);
