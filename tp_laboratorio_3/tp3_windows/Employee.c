#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"
#include "Controller.h"


/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */

Employee* employee_new(void)
{
	 Employee* this = (Employee*) malloc(sizeof(Employee));

	    if( this != NULL)
	    {
	        this->id = 0;
	        strcpy(this->nombre, " ");
	        this->horasTrabajadas = 0;
	        this->sueldo = 0;
	    }

	    return this;
}

/** \brief Lllama a los set del empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	  Employee* this = NULL;
	    this = employee_new();
	    if(this == NULL || employee_setId(this,idStr) || employee_setNombre(this, nombreStr) || employee_setHorasTrabajadas(this,horasTrabajadasStr) ||employee_setSueldo(this,sueldoStr))
	    {
	        employee_delete(this);
	        this = NULL;
	    }
	    return this;
}

/**
 * \brief Cambia el nombre del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Puntero al nombre que se cambiar�
 * \return int (-1) ERROR y (0) OK
 */

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,128))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,128);
		}
	}
	return retorno;
}

/**
 * \brief Se obtiene el nombre del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,128);
	}
	return retorno;
}


/**
 * \brief Se cambiar� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se cargar� al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setId(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,1000))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/**
 * \brief Se cambiar�n las horas trabajadas del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas char* Puntero a la cantidad de horas trabajadas que se cargar� en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,1000))
		{
			retorno = 0;
			this->horasTrabajadas = atoi(horasTrabajadas);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendr�n las horas trabajadas del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int* Puntero a la cantidad de horas trabajadas que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/**
 * \brief Se cambiar� el sueldo del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param sueldo char* Puntero al sueldo que se cargar� en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		if(esNumerica(sueldo,10000))
		{
			retorno = 0;
			this->sueldo = atoi(sueldo);
		}
	}
	return retorno;
}


/**
 * \brief Se obtendr� el sueldo del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param sueldo int* Puntero al sueldo que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}


/**
 * \brief Busca un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

int employee_contadoridMax(LinkedList* pArrayListEmployee, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Employee* auxiliarEmployee;
	Employee* auxEmplo;

	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmplo = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmplo,&idAuxiliar);
			if(!flag)
			{
				auxiliarEmployee = ll_get(pArrayListEmployee,i);
				employee_getId(auxiliarEmployee,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}

int employee_Alta(LinkedList* pArrayListEmployee){

    int retorno = -1;
    Employee* this;
    int idAux;
    char id[1000];
    char nombre[128];
    char horas[1000];
    char sueldo[10000];
    int auxHoras;
    int auxSueldo;

  if(pArrayListEmployee !=NULL){

    this = employee_new();

    if(this !=NULL)
    {


        printf("Alta Empleado\n");

        if(!(utn_getNombre(nombre, 128,"Ingrese nombre: \n", "Valor incorrecto\n",2)) &&
           !(utn_getNumero(&auxHoras,"Ingrese horas trabajadas: \n", "Valor incorrecto\n",1, 1000,2)) &&
           !(utn_getNumero(&auxSueldo,"Ingrese sueldo: \n", "Valor incorrecto\n",1, 1000000,2)))
        {

        	if(ll_len(pArrayListEmployee) == 0)
        	{
        		idAux = 0;
        	}
        	else
        	{
        		employee_contadoridMax(pArrayListEmployee, &idAux);
        		idAux = idAux + 1;
        	}
        	sprintf(horas,"%d",auxHoras);
        	sprintf(sueldo,"%d",auxSueldo);
        	sprintf(id,"%d",idAux);
        	if(employee_newParametros(id,nombre,horas,sueldo) >= 0)
        	{
        		this = (Employee*)employee_newParametros(id,nombre,horas,sueldo);
        		ll_add(pArrayListEmployee,this);

        		retorno = 0;
        	}


     }
   }
    else{
    	printf("ERROR");
    }
  }

    return retorno;
}



/** \brief Busca el id de un empleado
 *
 * \param paux Employee*
 * \param id int
 * \param pArrayEmp LinkedList*
 * \return int
 *
 */

int employee_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int retorno=-1;
	int i;
	int idAux;
	Employee* empleadoAux;

	if(pArrayListEmployee != NULL && id >= 0 )
	{
		retorno = -2;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			empleadoAux = ll_get(pArrayListEmployee,i);
			employee_getId(empleadoAux, &idAux);

			if( idAux == id)
			{
				retorno = i;
				break;
			}

		}
		if(retorno==-2){

			printf(" \n No hay un empleado vinculado a este id\n ");

		}
	}
	return retorno;
}

/** \brief Obtiene a los empleados y lo muestra
 *
 * \param pEmp Employee*
 * \return void
 *
 */
int employee_mostrar(Employee* pEmp)
{
	int retorno = -1;
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(pEmp !=NULL)
    {
        if(!employee_getId(pEmp,&id) && !employee_getNombre(pEmp,nombre) && !employee_getHorasTrabajadas(pEmp,&horas) && !employee_getSueldo(pEmp,&sueldo))
        {
            printf("%5d %8s %6d %8d\n",id,nombre,horas,sueldo);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Modifica los datos a elegir por parte del usuario segun su id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_modificar(LinkedList* pArrayListEmployee){

    int retorno = -1;
    Employee* pEmp;
    int id;
    int idAux;
    int indice;
    char seguir;
    char nombre[128];
    char horas [1000];
    int auxHoras;
    char sueldo[10000];
    int auxSueldo;


    if(pArrayListEmployee !=NULL)
    {


        printf("Modificar Empleado\n");



        controller_ListEmployee(pArrayListEmployee);
        if(ll_len(pArrayListEmployee) == 0)
          {
                idAux = 0;
          }
          else
          {
                employee_contadoridMax(pArrayListEmployee, &idAux);
                idAux = idAux + 1;
          }

        if(!utn_getNumero(&id,"Ingrese el ID que desea editar:  \n","ID inv�lido\n",0,idAux, 2))
        {

        indice = employee_buscarPorId(pArrayListEmployee,id);//busca el indice

        pEmp = (Employee*)ll_get(pArrayListEmployee,indice);//guarda el empleado con el indice especificado en pEmp

        		if(pEmp == NULL)
				{
					printf("\n");
				}
				else
				{


					printf("Empleado\n");

					printf("   Id   Nombre   Horas   Sueldo\n");

					employee_mostrar(pEmp);
					printf("\n");

					seguir = validarSeguir();

					if(seguir == 'S'  || seguir == 's'){
						if(!(utn_getNombre(nombre,128,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
						   !(utn_getNumero(&auxHoras,"Ingrese horas trabajadas\n", "Valor incorrecto\n",1, 1000,2)) &&
						   !(utn_getNumero(&auxSueldo,"Ingrese sueldo\n", "Valor incorrecto\n",1, 10000,2)))
						{
							retorno = 0;

							employee_setNombre(pEmp,nombre);
							sprintf(horas,"%d",auxHoras);
							employee_setHorasTrabajadas(pEmp,horas);
							sprintf(sueldo,"%d",auxSueldo);
							employee_setSueldo(pEmp,sueldo);
						}

					}else
	                {
	                    retorno = 0;
	                    printf("\n");
	                    printf(" Modificacion cancelada\n");
	                }

				}




        }
    }

    return retorno;

}


/** \brief Libera memoria
 *
 * \param emp Employee*
 * \return int
 *
 */
int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;

}


/** \brief Da de baja a un empleado segun su id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_baja(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    int idAux;
    int indice;
    char seguir;



        printf("Baja Empleado\n");


    if(pArrayListEmployee != NULL){
        controller_ListEmployee(pArrayListEmployee);

        if(ll_len(pArrayListEmployee) == 0)
         {
                  idAux = 0;
         }
         else
         {
        	 	 employee_contadoridMax(pArrayListEmployee, &idAux);
                   idAux = idAux + 1;
         }

        if(!utn_getNumero(&id,"Ingrese el ID que desea editar\n","ID inv�lido\n",0,idAux, 2))
        {

			indice = employee_buscarPorId(pArrayListEmployee,id);

			if(indice == -2)
			{
				printf("\n");
			}
			else
			{


				printf("Empleado\n");

				printf("   Id   Nombre   Horas   Sueldo\n");
				employee_mostrar((Employee*)ll_get(pArrayListEmployee,indice));

				printf("\n");

				seguir = validarSeguir();

				if(seguir == 'S'  || seguir == 's')
				{
					ll_remove(pArrayListEmployee,indice);

					printf("\n");

					printf(" Empleado eliminado con exito\n");
					 retorno = 0;
				}
				else
				{
					printf("\n");
					printf(" Baja cancelada\n");
				}

			}
        }
    }
    else{
    	printf("Error");
    }

    return retorno;
}




/** \brief Base a tomar para un ordenamiento de empleados por nombre.
 *
 * \param thisA void*
 * \param thisB void*
 * \return int
 *
 */
int employee_sortByName(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreA[128];
    char nombreB[128];

   employee_getNombre(thisA,nombreA);
   employee_getNombre(thisB,nombreB);

   if(strncmp(nombreA,nombreB,128)>0)
   {
    retorno = 1;
   }
   else if(strncmp(nombreA,nombreB,128)< 0)
   {
    retorno = -1;
   }
    return retorno;
}



