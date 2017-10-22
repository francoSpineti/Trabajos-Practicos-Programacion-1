#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

#endif // VALIDAR_H_INCLUDED

int val_getID(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getTitulo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getGenero(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getPuntaje(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getDuracion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getLink(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

// *********************************** VALIDACIONES

int val_validarTitulo(char* buffer);
int val_validarGenero(char* buffer);
int val_validarDescripcion(char* buffer);
int val_validarPuntaje(char* buffer);
int val_validarID(char* buffer);
int val_validarDuracion(char* buffer);
int val_validarLink(char* buffer);

