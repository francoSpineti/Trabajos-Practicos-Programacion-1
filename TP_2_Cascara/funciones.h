#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define OCUPADO 1
#define LIBRE 0
#define LONGITUD 20

typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int longitud);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona arrayPersona[],int dni);

/**
 * Funcion que da de alta a una persona.
 * @param arrayPersona se le pasa como parametro
 * @param posicion se le pasa como parametro
 * @return si esta bien la funcion retorna OK(0), si esta mal  -1
 */
int persona_altaPersona(EPersona* arrayPersona,int posicion);

/**
 * Funcion que elimina una persona
 * @param arrayPersona se le pasa como parametro
 * \return  si esta bien la funcion retorna OK(0), si esta mal  -1
 */
int persona_bajaPersona(EPersona* arrayPersona);

/**
 * Funcion que busca en el array de persona todas las edades que sean menores de 18.
 * @param le pasa por parametro el arrayPersona.
 * @return todas las personas menores a 18.
 */
int buscarMenoresDe18(EPersona* arrayPersona);

/**
 * Funcion que busca en el array de persona todas las edades que sean mayores de 35.
 * @param le pasa por parametro el arrayPersona.
 * @return todas las personas mayores a 35.
 */
int buscarMayoresDe35(EPersona* arrayPersona);

/**
 * Funcion que busca en el array de persona todas las edades que sean mayores de 19 y menores de 35.
 * @param le pasa por parametro el arrayPersona.
 * @return todas las personas mayores a 35 y mayores a 19.
 */
int buscarDe19A35(EPersona* arrayPersona);


/**
 * Funcion que inicializa el array con todos los estados libres.
 * @param arrayPersona se le pasa como parametro
 * @param longitud se le pasa como parametro
 */
void iniciarPersona(EPersona* arrayPersona);

/**
 * Funcion que recorre el arrayPersona que le pasamos por parametro y lista todas las personas que tengan el estado OCUPADO
 * @param arrayPersona se le pasa como parametro
 */
void listarPersonas(EPersona* arrayPersona);

/**
 * Funcion que muestra un grafico por consola con las diferentes edades
 * @param arrayPersona se le pasa como parametro
 * @param char menos18[]
 * @param char mas18[]
 * @param char mas35[]
 */
void graficoEdad(EPersona* arrayPersona,char menos18[],char mas18[],char mas35[]);

/**
 * Funcion que ordena alfabeticamente los nombres que estan agregados en el array.
 * @param arrayPersona se le pasa como parametro
 */
void ordenarPersona(EPersona* arrayPersona);

#endif // FUNCIONES_H_INCLUDED
