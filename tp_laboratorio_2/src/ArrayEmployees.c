#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define VACIO 0
#define OCUPADO 1


/** \brief inicializa todas el array en 0 que indica vacio.
 *
 * \param estructura de empleado.
 * \param cantidad de datos del sistema.
 * \return 0 (EXITO) y -1 (ERROR).
 *
 */

int initEmployees(eEmployee* empleado, int tam)
{
int retorno = -1;

 if(empleado!=NULL){
    for (int i=0 ; i< tam; i++)
    {
        empleado[i].isEmpty= VACIO;
        retorno = 0;
    }

 }

 return retorno;
}


/**
 * \brief Imprime los datos de un empleado
 * \param emp Puntero que se busca imprimir
 * \return 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimir(eEmployee* emp)
{
    int retorno=-1;
    if(emp != NULL && emp->isEmpty == OCUPADO)
    {
        retorno=0;
        printf("\nID: %d -NOMBRE: %s - APELLIDO: %s -SALARIO:  %.2f - SECTOR: %d",emp->id,emp->name,emp->lastname,emp->salary,emp->sector);
    }
    return retorno;
}

/**
 * \brief Imprime el array de un empleado
 * \param array de empleados a ser actualizado
 * \param tam del array de empleados
 * \return 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirArray(eEmployee* array,int tam)
{
    int respuesta = -1;
    int i;
    if(array != NULL && tam > 0)
    {
        respuesta = 0;
        for(i=0; i<tam; i++)
        {
            imprimir(&array[i]);
        }
    }
    return respuesta;
}



/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tam de la estrutura
 * \return el indice que se encuentra vacio.
 *
 */

int buscarLibre(eEmployee* empleado, int tam)
{
    int indice= -1;

    for (int i= 0 ; i<tam; i ++)
    {
        if (empleado[i].isEmpty== VACIO)
        {
            indice=i;
        }
    }
    return indice;
}

/** \brief busca el indice donde se encuentra un empleado por numero de id.
 *
 * \param la estructura empleado.
 * \param tam de la estructura.
 * \param id de los empledos.
 * \return el indice donde se encuentra ese id de empleado.
 *
 */

int findEmployeeById(eEmployee* empleado, int tam, int idAux)
{
    int indice= -1 ;

  if(empleado!=NULL && tam>0 && idAux >=0 ){
    for (int i=0 ; i<tam ; i++)
    {
        if ( empleado[i].id == idAux && empleado[i].isEmpty == OCUPADO)
        {
            indice=i;
            break;
        }
    }
  }
    return indice;
}

/** \brief alta de emleados, solicita ingreso de datos.
 *
 * \param la estructura empleado.
 * \param tam de la estructura.
 * \param recibe el indice donde cargar ese empleado.
 * \param id del empleado.
 * \return el empleado cargado en ese id
 *
 */
int addEmployees(eEmployee* emp,int tam, int indice, int* id)
{
			int retorno = -1;
			eEmployee empleado;
		    char nombreAux[NAME_LEN];
		    char apellidoAux[LASTNAME_LEN];
		    float salarioAux;
		    int sectorAux;
		    char salida;

		    do
		    {
		        if(emp != NULL && tam > 0 && indice < tam && indice >= 0 && id != NULL)
		        {
		        	if(utn_getNombre(nombreAux,NAME_LEN,"Ingrese nombre\n", "Valor incorrecto\n",2)==0 &&
		        	   utn_getNombre(apellidoAux,LASTNAME_LEN,"Ingrese apellido\n", "Valor incorrecto\n",2)==0 &&
					   utn_getNumeroFlotante(&salarioAux,"Ingrese sueldo\n", "Valor incorrecto\n",0, 10000,2)==0 &&
					   utn_getNumero(&sectorAux,"Ingrese sector\n", "Valor incorrecto\n",0, 10,2)==0){

		        			strncpy(empleado.name,nombreAux,NAME_LEN);
		            		strncpy(empleado.lastname,apellidoAux,LASTNAME_LEN);
							empleado.salary = salarioAux;
							empleado.sector = sectorAux;
							empleado.id = *id;
							empleado.isEmpty =OCUPADO;


		                imprimir(&empleado);
		                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
		                retorno = 0;
		            }
		        }

		     }while(salida!='s');

		            empleado.id = *id;
		  			empleado.isEmpty = OCUPADO;
					emp[indice] = empleado;
		            (*id)++;


		    return retorno;
}


/** \brief modifica datos de un empleado.
 *
  * \param la estructura empleado.
 * \param tamaño de la estructura.
 * \return 0 (EXITO) y -1 (ERROR).
 *
 */

int modifyEmployee (eEmployee* empleado, int tam)
{
	int idAux;
    int indice;
    int option;
    char nombreAux[NAME_LEN];
    char apellidoAux[LASTNAME_LEN];
    float salarioAux;
    int sectorAux;
    char salida;
    int retorno = -1;

    if(empleado!=NULL){
    do{
    printf("\n MODIFICACION \n");

    imprimirArray(empleado,tam);

    utn_getNumero(&idAux,"Ingrese id: \n", "Valor incorrecto\n",0, tam,2);


    indice = findEmployeeById(empleado, tam, idAux);
    if( indice == -1)
    {
        printf("\n\nERROR, No hay empleado con ese ID");
        break;
    }
    else
    {
        printf("\n MODIFICACION  \n");

        imprimir(&empleado[indice]);
        printf(" \n\n");


    	utn_getNumero(&option," 1- Modificar nombre\n"
    						  " 2- Modificar apellido\n"
    		    			  " 3- Modificar Sueldo\n"
    		    			  " 4- Modificar Sector \n"
    						  " 5- Salir \n",
    		    	          "Opción inválida\n",
    		    	       	   1,5,2);

        switch (option)
        {

        case 1:

        		utn_getNombre(nombreAux, NAME_LEN,"Ingrese nombre\n", "Valor incorrecto\n",2);
        		utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
        		if(salida=='s'){

                  strncpy(empleado[indice].name,nombreAux,LASTNAME_LEN);
                  printf("\nModificacion Realizada\n\n");
                  retorno = 0;
                  break;
        		}
        	break;
        case 2:
                utn_getNombre(apellidoAux,LASTNAME_LEN,"Ingrese apellido: \n", "Valor incorrecto\n",2);
                utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
                if(salida=='s'){
                strncpy(empleado[indice].lastname,apellidoAux,LASTNAME_LEN);
                printf("\nModificacion Realizada\n\n");
                retorno = 0;
                break;
                }
          break;

        case 3:
        	utn_getNumeroFlotante(&salarioAux,"Ingrese sueldo\n", "Valor incorrecto\n",1, 1000000,2);
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){

        	empleado[indice].salary = salarioAux;
			printf("\nModificacion Realizada\n\n");
			retorno = 0;
				break;
            }
            break;
        case 4:
        		utn_getNumero(&sectorAux,"Ingrese sector\n", "Valor incorrecto\n",1, 10,2);
                utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
                if(salida=='s'){

        		empleado[indice].sector = sectorAux;
        		printf("\nModificacion Realizada\n\n");
        		retorno = 0;
              	  break;
                }
            break;
       }


  	  	  }

      }while(option != 5);

  }
   return retorno;
}

/** \brief dada de baja un empleado solicitando  numero de id-
 *
 * \param estructura empleado.
 * \param tamaño de empleado.
 * \return 0 (EXITO) y -1 (ERROR).
 *
 */

int removeEmployee (eEmployee* empleado, int tam)
{
	int retorno = -1;
    int idAux;
    int indice;

    if(empleado!=NULL){

    printf("\n ******  BAJA DE empleado  ****** \n");

    imprimirArray(empleado,tam);


    if(!utn_getNumero(&idAux,"\n Ingrese ID del empleado a dar de BAJA : ", "Valor incorrecto\n",0, tam,2)){

      indice = findEmployeeById(empleado, tam, idAux);
      if( indice == -1)
          {
              printf("\n ERROR, No hay empleado con ese ID ");

          }
          else
          {

              printf(" \n\n");
              empleado[indice].isEmpty = VACIO;
              retorno = 0;
              printf(" \n\n Baja efectuada \n\n");

          }
    }


  }

    return retorno;
}
/** \brief realiza un informe sobre datos ordenamiento y suma de sueldos.
 *
 * \param la estructura empleado.
 * \param el tamaño de la estructura.
 * \return 0 (EXITO) y -1 (ERROR).
 *
 */


int sortEmployees(eEmployee* empleado, int tam)
{

    int option;
    int opcionOrd;
    int retorno = -1;

    if(empleado!=NULL){

    utn_getNumero(&option, "\nINFOMES\n\n"
    		        "1. Ordenar alfabeticamente por Apellido y Sector.\n"
    		        "2. Total y promedio de los salarios, y cuantos empleado superan el salario promedio.\n"
    		        "\n Ingrese una opcion :  ",
        		    "Opción inválida\n",
        		    	   1,2,2);


    switch(option)
    {
    case 1:

        utn_getNumero(&opcionOrd, "\n1.Ordenar por apellido"
                		          "\n2.Ordenar por sector"
            		           "\n\nIngrese una opcion:  ",
                		       "Opción inválida\n",
                		    	   1,2,2);
            switch (opcionOrd)
            {
            case 1:
                ordenarPorApellido(empleado, tam);
                retorno = 0;
                break;
            case 2:
                ordenarPorSector(empleado,tam);
                retorno = 0;

                break;
            }


        break;
    case 2:
        salariosempleado(empleado, tam);
        retorno =0;
        break;
    }

   }

    return retorno;
}


/** \brief ordena de forma ascendete los apellido
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */
void ordenarPorApellido(eEmployee* empleado, int tam )
{
    eEmployee auxEmpleado;


 if(empleado!=NULL){
    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( strncmp(empleado[j].lastname,empleado[i].lastname,LASTNAME_LEN )<0 && empleado[j].isEmpty==OCUPADO && empleado[i].isEmpty==OCUPADO)
            {


                auxEmpleado=empleado[i];
                empleado[i]=empleado[j];
                empleado[j]=auxEmpleado;
            }
            else if (strncmp(empleado[j].lastname,empleado[i].lastname,LASTNAME_LEN)== 0 && empleado[i].isEmpty==OCUPADO && empleado[j].isEmpty==OCUPADO)
            {
                if (strncmp(empleado[j].name,empleado[i].name,NAME_LEN)>0)
                {
                    auxEmpleado=empleado[i];
                    empleado[i]=empleado[j];
                    empleado[j]=auxEmpleado;
                }
            }
        }
    }


    printf("\n\n El orden de empleado por APELLIDO fue efecuado.\n\n");


    imprimirArray(empleado,tam);

 }

}


/** \brief ordena por sector de manera alfabetica ascendente y sin son iguales los ordena por apellido.
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarPorSector(eEmployee* empleado , int tam )

{
    eEmployee auxEmpleado;


  if(empleado!=NULL){
    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( (empleado[j].sector < empleado[i].sector) && empleado[j].isEmpty==OCUPADO && empleado[i].isEmpty==OCUPADO)
            {


                auxEmpleado=empleado[i];
                empleado[i]=empleado[j];
                empleado[j]=auxEmpleado;
            }
            else if ((empleado[j].sector == empleado[i].sector) && empleado[i].isEmpty==OCUPADO && empleado[j].isEmpty==OCUPADO)
            {
                if (strncmp(empleado[j].lastname,empleado[i].lastname,LASTNAME_LEN)<0)
                {
                    auxEmpleado=empleado[i];
                    empleado[i]=empleado[j];
                    empleado[j]=auxEmpleado;
                }
            }
        }
    }


    printf("\n\n El orden de empleado por SECTOR fue efecuado.\n");


    	imprimirArray(empleado,tam);
  }
}


/** \brief calculos del salario de los empleados.
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */

void salariosempleado(eEmployee* empleado , int tam)
{


    float totalSalary=0;
    int totalempleado=0;
    float promedioSalary=0;
    int contadordeSalaryMayoralamedia=0;

  if(empleado!=NULL){
    for (int i=0; i<tam ; i++)
    {
        if (empleado[i].isEmpty==OCUPADO)
        {
            totalSalary= empleado[i].salary + totalSalary;
            totalempleado++;

        }

    }

    promedioSalary= totalSalary/totalempleado;


    for (int i=0; i<tam ; i++)
    {
        if (empleado[i].salary >= promedioSalary  && empleado[i].isEmpty== OCUPADO)

        {
            contadordeSalaryMayoralamedia++;
        }
    }


    printf("\n - El total de salarios es : %.2f\n", totalSalary );
    printf("\n - EL promedios de salario es de :  %.2f\n", promedioSalary);
    printf("\n - empleado que superan o igualan el salario promedio : %d\n\n", contadordeSalaryMayoralamedia);

  }

}


