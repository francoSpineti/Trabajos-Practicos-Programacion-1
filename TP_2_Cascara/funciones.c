#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

int persona_altaPersona(EPersona* arrayPersona,int posicion)
{
    int retorno = -1;
    char bNombre[21];
    char bEdad[11];
    char bDni[10];
    int auxPosicion;

    if(arrayPersona != NULL && posicion >= 0)
    {
        if(val_ingresarNombrePorTecladoConIntentos(bNombre,"Ingrese Nombre : \n","ERROR : Nombre invalido.\n",2,21) == OK)
        {
            if(val_ingresarEdadPorTecladoConIntentos(bEdad,"Ingrese Edad : \n","ERROR : Edad invalida.\n",2,3) == OK)
            {
                if(val_ingresarDniPorTecladoConIntentos(bDni,"Ingrese Dni : \n","ERROR: Dni invalido.\n",2,9) == OK)
                {
                    auxPosicion = buscarPorDni(arrayPersona,atoi(bDni));
                    while(auxPosicion != -1)
                    {
                        printf("ERROR, dni existente. \n");
                       if(val_ingresarDniPorTecladoConIntentos(bDni,"Ingrese Dni : \n","ERROR: Dni invalido.\n",2,9) == OK)
                       {
                           auxPosicion = buscarPorDni(arrayPersona,atoi(bDni));
                       }
                    }
                        strncpy(arrayPersona[posicion].nombre,bNombre,51);
                        arrayPersona[posicion].edad = atoi(bEdad);
                        arrayPersona[posicion].dni = atoi(bDni);
                        arrayPersona[posicion].estado = OCUPADO;
                        retorno = OK;
                }
            }
        }
    }
    return retorno;
}

int persona_bajaPersona(EPersona* arrayPersona)
{
  int posicion;
  int retorno = -1;
  char bDni[9];

  if(arrayPersona != NULL)
  {
      if(val_ingresarDniPorTecladoConIntentos(bDni,"Ingrese Dni que desea eliminar : \n","ERROR: Dni invalido - no existe.\n",2,9) == OK)
      {
		  posicion = buscarPorDni(arrayPersona,atoi(bDni));
          if(posicion != -1)
          {
               arrayPersona[posicion].estado = LIBRE;
               arrayPersona[posicion].edad = 0;
               printf("se borro la persona. \n \n");
               retorno = OK;
		  }
      }
  }
   system("pause");
  return retorno;
}

void iniciarPersona(EPersona* arrayPersona)
{
    int i;
    EPersona aux;
    if(arrayPersona != NULL)
    {
        for(i=0; i < LONGITUD ; i++)
        {
            strcpy(aux.nombre,"");
            aux.dni = 0;
            aux.edad = 0;
            aux.estado = LIBRE;
            arrayPersona[i] = aux;
        }
    }
}

int obtenerEspacioLibre(EPersona arrayPersona[],int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == atoi(LIBRE))
            {
                return i;
            }
        }
    }
    return retorno;
}

int buscarPorDni(EPersona arrayPersona[],int dni)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && dni > 0)
    {
        for(i=0; i<LONGITUD; i++)
        {
            if(dni == arrayPersona[i].dni)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}

void listarPersonas(EPersona* arrayPersona)
{
    int i;
    printf("Nombres de las personas: \n\n");
    ordenarPersona(arrayPersona);
    for(i = 0; i < LONGITUD; i++)
    {
        if(arrayPersona[i].estado == OCUPADO)
        {
            printf("%s \n",arrayPersona[i].nombre);
        }
    }
    system("pause");
}

int buscarMenoresDe18(EPersona* arrayPersona)
{
   int i,cant = 0;
   for(i = 0; i < LONGITUD; i++)
   {
	    if(arrayPersona[i].edad <= 18 && arrayPersona[i].edad >=1)
	   {
		   cant++;
	   }
   }
   return cant;
}

int buscarMayoresDe35(EPersona* arrayPersona)
{
   int i,cant = 0;
   for(i = 0; i < LONGITUD; i++)
   {
	   if(arrayPersona[i].edad >= 35)
	   {
		   cant++;
	   }
   }
   return cant;
}

int buscarDe19A35(EPersona* arrayPersona)
{
   int i,cant = 0;
   for(i = 0; i < LONGITUD; i++)
   {
	   if(arrayPersona[i].edad >=19 && arrayPersona[i].edad < 35)
	   {
		   cant++;
	   }
   }
   return cant;
}

void ordenarPersona(EPersona* arrayPersona)
{
    int i, j;
    EPersona nombre;
    for(i=0; i<LONGITUD; i++)
    {
        for(j=i+1; j<LONGITUD; j++)
        {
            if(strcmp(arrayPersona[i].nombre, arrayPersona[j].nombre)== 1)
            {
                nombre = arrayPersona[i];
                arrayPersona[i]= arrayPersona[j];
                arrayPersona[j]= nombre;
            }
            else if(strcmp(arrayPersona[i].nombre, arrayPersona[j].nombre)== 0)
            {
                if(arrayPersona[i].dni>arrayPersona[j].dni)
                {
                    nombre= arrayPersona[i];
                    arrayPersona[i]= arrayPersona[j];
                    arrayPersona[j]= nombre;
                }
            }
        }
    }
}

void graficoEdad(EPersona* arrayPersona,char menos18[],char mas18[],char mas35[])
{
   int i,j, Men18, May35, Int19A35;
   char auxme18, auxma18, auxma35;

   Men18 = buscarMenoresDe18(arrayPersona);
   May35 = buscarMayoresDe35(arrayPersona);
   Int19A35 = buscarDe19A35(arrayPersona);

    for(i=0; i<Men18; i++)
    {
        menos18[i]='*';
    }

    for(i=Men18+1; i<LONGITUD;i++)
    {
        menos18[i]=' ';
    }



    for(i=0; i<Int19A35; i++)
    {
        mas18[i]='*';
    }

    for(i=Int19A35+1; i<LONGITUD;i++)
    {
        mas18[i]=' ';
    }


    for(i=0; i<May35; i++)
    {
        mas35[i]='*';
    }

    for(i=May35+1; i<LONGITUD;i++)
    {
        mas35[i]=' ';
    }

    for(i=0; i<LONGITUD; i++)
    {
        for(j=i+1; j<LONGITUD; j++)
        {
            if(menos18[i]=='*')
            {
                auxme18= menos18[i];
                menos18[i]= menos18[j];
                menos18[j]= auxme18;
            }
        }
    }
    for(i=0; i<LONGITUD; i++)
    {
        for(j=i+1; j<LONGITUD; j++)
        {
            if(mas18[i]=='*')
            {
                auxma18= mas18[i];
                mas18[i]= mas18[j];
                mas18[j]= auxma18;
            }
        }
    }

    for(i=0; i<LONGITUD; i++)
    {
        for(j=i+1; j<LONGITUD; j++)
        {
            if(mas35[i]=='*')
            {
                auxma35= mas35[i];
                mas35[i]= mas35[j];
                mas35[j]= auxma35;
            }
        }
    }
}
