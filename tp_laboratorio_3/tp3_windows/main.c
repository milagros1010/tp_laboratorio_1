#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf (stdout, NULL);
    int option = 0;

    int cargado = 0;
        LinkedList* listaEmpleados = ll_newLinkedList();

        do{
            	utn_getNumero(&option,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
            						  "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
            						  "3. Alta de empleado\n"
            						  "4. Modificar datos de empleado\n"
            						  "5. Baja de empleado\n"
            						  "6. Listar empleados\n"
            						  "7. Ordenar empleados\n"
            						  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
            						  "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
            						  "10. Salir\n",
        							  "Opci�n inv�lida\n",
        							  1,10,2);
                switch(option)
                {
                    case 1:
                    	if(cargado == 0)
                    	{
    						controller_loadFromText("data.csv",listaEmpleados);
    						cargado = 1;
                     	}
                    	else
                    	{
                    		printf("Archivo ya cargado\n");
                    	}
                        break;
                    case 2:
                    	if(cargado == 0)
                    	{
    						controller_loadFromBinary("data.dat",listaEmpleados);
    						cargado = 1;
                        }
                    	else
    					{
    						printf("Archivo ya cargado\n");
    					}
                        break;
                    case 3:
                    	if(cargado == 1){
                    	controller_addEmployee(listaEmpleados);
                    	}
                    	else{
                    		printf("Primero cargue un archivo");
                    	}
                    	break;
                    case 4:
                    	if(cargado == 1){
                    	controller_editEmployee(listaEmpleados);
                    	}
                    	else{
                    	   printf("Primero cargue un archivo");
                    	}
                        break;
                    case 5:
                    	if(cargado == 1){
                    	controller_removeEmployee(listaEmpleados);
                    	}
                    	else{
                    		printf("Primero cargue un archivo");
                    	}
                        break;
                    case 6:
                    	if(cargado == 1){
                    	controller_ListEmployee(listaEmpleados);
                    	}
                    	else{
                    		printf("Primero cargue un archivo");
                    	}
                        break;
                    case 7:
                    	if(cargado == 1){
                    	controller_sortEmployee(listaEmpleados);
                    	}
                    	else{
                    		printf("Primero cargue un archivo");
                    	}
                        break;
                    case 8:
                    	if(cargado == 1){
                    	controller_saveAsText("data.csv",listaEmpleados);
                    	}
                    	else{
                    		printf("Primero cargue un archivo");
                    	}
                        break;
                    case 9:
                    	if(cargado == 1){
                    	controller_saveAsBinary("data.dat",listaEmpleados);
                    	}
                    	else{
                    		printf("Primero cargue un archivo");
                    	}
                        break;

                }
            }while(option != 10);
    return 0;
}
