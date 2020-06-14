/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);


	int opcion;
	int flagA = 0;
	int flagB = 0;
	int flagC = 0;
	int resultadoFactorialUno = 0;
	int resultadoFactorialDos = 0;
	float numero1 = 0;
	float numero2 = 0;
	float resultadoSuma = 0;
	float resultadoResta = 0;
	float resultadoDivision = 0;
	float resultadoMultiplicacion = 0;


	    do{
	    system("cls");
	    printf("MENU");
	    printf("\n 1.Ingrese primer operando (A=%.2f)",numero1);
	    printf("\n 2.Ingrese segundo operando (B=%.2f)",numero2);
	    printf("\n 3.Calcular todas las operaciones");
	    printf("\n 4.Mostrar todos los resultados");
	    printf("\n 5.Salir");
	    printf("\n Seleccionar opcion\n");
	    scanf("%d",&opcion);


	         switch(opcion)
	        {
	            case 1:
	            printf("Ingrese el primer operando (A=X)");
	            scanf("%f",&numero1);
	            flagA =1;


	            break;

	            case 2:
	            printf("Ingrese segundo operando(B=Y)");
	            scanf("%f",&numero2);
	            flagB=1;
	            break;

	            case 3:

	                flagC=1;

	                if(flagA==1 && flagB==1)
	                {
	                resultadoSuma = suma(numero1,numero2);
	                resultadoResta = resta(numero1,numero2);
	                resultadoDivision = division(numero1,numero2);
	                resultadoMultiplicacion = multiplicacion(numero1,numero2);
	                resultadoFactorialUno = factorial(numero1);
	                resultadoFactorialDos = factorial(numero2);

	            system("cls");
	            printf("\nCalculando..");
	            system("pause");

	                }
	                else
	                {
	                printf("\n Error falta un operando\n" );
	                system("cls");
	                }
	            break;



	            case 4:

	            if(flagC==1){

	            system("cls");
	            printf("\nEl resultado de A+B es: %.2f\n",resultadoSuma);
	            printf("\nEl resultado de A-B es: %.2f\n",resultadoResta);
	                if(numero2==0)
	                {
	                    printf("\nError no se puede dividir por 0");
	                }
	                else
	                {
	                    printf("\nEl resultado de A/B es: %.2f\n",resultadoDivision);
	                }
	            printf("\nEl resultado de A*B es: %.2f\n",resultadoMultiplicacion);
	            printf("\nEl factorial de A es: %d\n",resultadoFactorialUno);
	            printf("\nEl factorial de B es: %d\n",resultadoFactorialDos);
	            system("pause");
	            numero1=0;
	            numero2=0;
	            flagA=0;
	            flagB=0;
	            }
	            else{

	                printf("Error.Primero ingrese la opcion 3");

	            }
	            flagC=0;
	            break;

	            case 5:
	            system("cls");
	            printf("SALIR\n");
	            system("pause");
	            break;


	            default:
	            printf("Error ingrese una opcion valida!\n");
	            system("pause");
	            break;

	    }



	            //__fpurge(stdin); limpia el buffer linux

	        getch();
	     } while(opcion!=5);

	return EXIT_SUCCESS;
}
