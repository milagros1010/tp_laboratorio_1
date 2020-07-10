#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 1000
#define VACIO 1
#define OCUPADO 0

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf (stdout, NULL);
	 eEmployee empleados[TAM];

	    int id = 0;
	    int option;
	    int bandera=0;
	    int indice;



	    if(initEmployees(empleados,TAM)==0){

	    	printf("Iniciado correctamente\n");
	    }


	    do
	    {
	    	utn_getNumero(&option," 1- Alta\n"
	    						 " 2- Modificar\n"
	    						 " 3- Baja\n"
	    						 " 4- Informes \n"
	    						 " 5- Salir\n\n",
	    	        			 "Opción inválida\n",
	    	       				  1,5,2);

	        switch(option)
	        {
	        case 1:
	        	indice = buscarLibre(empleados,TAM);
	        	if(indice >=0)
	        	{
	        			if(addEmployees(empleados,TAM,indice,&id)==0){
							printf("Empleado dado de alta\n");
							bandera=1;
						}else
						{
							printf("Error. No dado de alta\n");
						}
	        	}
	        	else{
	        		printf("No hay espacio\n");
	        	}
	            break;
	        case 2:

	            if ( bandera==0 )
	            {
	                printf("\nPrimero ingrese ALTA de empleado.  \n\n");
	            }
	            else
	            {
	               if(modifyEmployee(empleados,TAM)==0){
	            	   printf("Modificacion terminada con exito");
	               }
	               else{
	            	   printf("Error");
	               }
	            }

	            break;
	        case 3:

	            if ( bandera==0 )
	            {
	                printf("\nNo se ingresaron datos!.   Ingrese ALTA de empleado.  \n\n");
	            }
	            else
	            {
	                if(removeEmployee (empleados,TAM)==0){
	                	printf("Elliminado con exito\n");
	                }
	                else{
	                	printf("Error\n");
	                }
	            }

	            break;
	        case 4:

	            if ( bandera==0 )
	            {
	                printf("\nNo se ingresaron datos!.  Ingrese  ALTA de empleado. \n\n");
	            }
	            else
	            {
	                if(sortEmployees(empleados,TAM)==0){
	                	printf("Informes realizados con exito\n");
	                }
	                else{
	                	printf("Error\n");
	                }
	            }

	            break;

	        }

	    }
	    while(option!=5);

	    return EXIT_SUCCESS;
}
