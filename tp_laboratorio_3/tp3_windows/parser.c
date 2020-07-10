#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  (0) OK
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleadoAux;
	    char auxId[1024];
	    char auxNombre[1024];
	    char auxHorasTrabajadas[1024];
	    char auxSalario[1024];
	    int bandera = 1;
	    int retorno = -1;

	    while(!feof(pFile))
	    {
	        if(bandera)
	        {
	            fscanf(pFile,"%s\n", auxId);
	            bandera = 0;
	        }
	        else if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSalario)==4)//develve la cant de datos leidos
	        {
	            empleadoAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSalario);
	            if(empleadoAux != NULL)
	            {
	                ll_add(pArrayListEmployee, empleadoAux);
	                retorno = 0;
	            }
	        }
	        else
	        {
	            break;
	        }
	    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  (0) OK
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleadoAux;
	    int retorno = -1;
	    int cantLineas;
	    do
	    {
	        empleadoAux = employee_new();

	        cantLineas = fread(empleadoAux, sizeof(Employee), 1, pFile);//cantidad de lineas leidas
	        if(empleadoAux != NULL && cantLineas == 1)
	        {
	            ll_add(pArrayListEmployee, empleadoAux);
	            retorno = 0;
	        }
	    }while(!feof(pFile));

	    return retorno;
}
