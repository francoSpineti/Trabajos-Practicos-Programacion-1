#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#endif // PERSONA_H_INCLUDED

// DEFINE'S
#define MAX_INPUT_BUFFER 4096
#define OK 0
// DEFINE'S de funciones en las que se ingresan datos.
#define ERROR_INGRESAR_NOMBRE_POR_TECLADO_CON_INTENTOS -1
#define ERROR_INGRESAR_EDAD_POR_TECLADO_CON_INTENTOS -2
#define ERROR_INGRESAR_DNI_POR_TECLADO_CON_INTENTOS -3
// DEFINE'S de funciones que validan.
#define ERROR_VALIDAR_NOMBRE -4
#define ERROR_VALIDAR_EDAD -5
#define ERROR_VALIDAR_DNI -6

int val_ingresarNombrePorTecladoConIntentos(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_ingresarEdadPorTecladoConIntentos(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_ingresarDniPorTecladoConIntentos(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);
int val_validarEdad(char* buffer);
int val_validarDni(char* buffer);
void myFgets(char* buffer, int limite ,FILE* archivo);
