#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>
/*
 * Controller.c
 *
 *  Created on: 2 jul. 2020
 *      Author: otro
 */





/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
		    {
		        pFile = fopen(path, "r");

		        if(pFile != NULL)
		        {

		            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
		            {
		                printf(" Carga en modo texto exitosa\n");
		                retorno = 0;
		            }
		            else
		            {
		                printf("error al cargar el archivo .csv\n");
		            }
		        }
		        else
		        {
		            printf(" El archivo no se pudo abrir correctamente\n");
		        }

		        fclose(pFile);
		    }

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	    FILE* pFile;

	        pFile = fopen(path,"rb");

	        if(pFile !=NULL)
	        {
	            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
	            {
	                printf(" Carga en modo binario exitosa\n");
	                retorno = 0;
	            }
	            else
	            {
	                printf("error al cargar el archivo .bin\n");
	            }

	        fclose(pFile);
	    }

	    return retorno;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista del tipo LinkedList* donde será añadido el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	  int retorno = -1;
	    if(!employee_Alta(pArrayListEmployee))
	    {

	        printf("Alta exitosa \n");

	        retorno = 0;
	    }
	    else
	    {
	        printf("Error empleado no dado de alta\n");
	    }
	    return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* Puntero a la lista del tipo LinkedList* donde será modificado el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	int retorno = -1;
	    if(!employee_modificar(pArrayListEmployee))
	    {

	        printf(" EL empleado fue modificado\n");

	        retorno = 0;
	    }
	    else
	    {

	        printf("no modificado \n");

	    }
	    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser actualizada
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =- 1;

	    if(pArrayListEmployee != NULL)
	    {

	        if(!employee_baja(pArrayListEmployee))
	        {
	            printf("Empleado borrado\n");
	            retorno=0;
	        }
	        else
	        {
	            printf("Empleado no borrado\n");
	        }
	    }
	    return retorno;
}


/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser impresa
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
     	int retorno=-1;
		int i;
		Employee* empleadoAux;
		empleadoAux = employee_new();

		if(pArrayListEmployee != NULL)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				empleadoAux = ll_get(pArrayListEmployee,i);
				employee_mostrar(empleadoAux);
			}
			retorno=0;

		}
		return retorno;
}

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int opcion;

		if(pArrayListEmployee != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese 0 para ordenar descendente y 1 para ascendente\n","Valor inválido\n",0,1,2))
			{
				printf("cargando lista \n");
				if(ll_sort(pArrayListEmployee,employee_sortByName,opcion)==0)
				{
					printf("ordenado correctamente\n");

					controller_ListEmployee(pArrayListEmployee);
					retorno = 0;
				}
			}
		}

		return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
		int i;
		FILE* pFile;
		int auxiId;
		char auxNombre[128];
		int auxHoras;
		int auxSueldo;
		Employee* empleadoAux;

		if(pArrayListEmployee != NULL && path != NULL)
		{

			pFile = fopen(path,"w");
			if(pFile != NULL)
			{
				retorno=0;
				for(i=0;i<ll_len(pArrayListEmployee);i++)
				{
					empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
					if(empleadoAux != NULL)
					{
						if(!employee_getId(empleadoAux,&auxiId) &&
						   !employee_getNombre(empleadoAux,auxNombre) &&
						   !employee_getHorasTrabajadas(empleadoAux,&auxHoras) &&
						   !employee_getSueldo(empleadoAux,&auxSueldo))
						{
							fprintf(pFile,"%d,%s,%d,%d\n",auxiId,auxNombre,auxHoras,auxSueldo);
						}
					}

				}
				fclose(pFile);
				printf("Archivo guardado correctamente\n");

			}
		}
		return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.dat (modo binario).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

	int retorno = -1;
	    FILE* pFile;
	    Employee* empleadoAux;

	    if(path !=NULL && pArrayListEmployee !=NULL)
	    {
	        pFile = fopen(path,"wb");

	        if(pFile !=NULL)
	        {
	            for(int i=0; i<ll_len(pArrayListEmployee); i++)
	            {
	                empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);

	                if(empleadoAux !=NULL)
	                {
	                    fwrite(empleadoAux,sizeof(Employee),1,pFile);
	                }
	            }

	            printf(" Empleados cargados en modo binario con exito\n");
	            retorno = 0;
	        }
	        else
	        {
	            printf(" Hubo un error al guardar el archivo .bin\n");
	        }

	        fclose(pFile);
	    }

	    return retorno;
}

