/*
 * utn.c
 *
 *  Created on: 18 abr. 2020
 *      Author: otro
 */

#include <stdio.h>
#include "utn.h"

/**
 * \brief Solicita número a usuario
 * \param numero1 primer numero para sumar
 * \param numero2 segundo numero para sumar
 * \return Retorna el valor de la suma de los numeros
 *
 */
float suma(float numero1, float numero2)
{
    float resultadoSuma;
    resultadoSuma = numero1 + numero2;
    return resultadoSuma;
}
/**
 * \brief Solicita número a usuario
 * \param numero1 primer numero para restar
 * \param numero2 segundo numero para restar
 * \return Retorna el valor de la resta de los numeros
 *
 */

float resta(float numero1,float numero2)
{
    float resultadoResta;
    resultadoResta = numero1 - numero2;
    return resultadoResta;
}
/**
 * \brief Solicita número a usuario
 * \param numero1 primer numero para dividir
 * \param numero2 segundo numero para  dividir
 * \return Retorna el valor de la division de los numeros
 *
 */

float division(float numero1,float numero2)
{
    float resultadoDivision;
    resultadoDivision = numero1/numero2;
    return resultadoDivision;
}

/**
 * \brief Solicita número a usuario
 * \param numero1 primer numero para multiplicar
 * \param numero2 segundo numero para multiplicar
 * \return Retorna el valor de la multiplicacion de los numeros
 *
 */
float multiplicacion(float numero1,float numero2)
{
    float resultadoMultiplicacion;
    resultadoMultiplicacion = numero1 * numero2;
    return resultadoMultiplicacion;
}

/**
 * \brief Funcion encargada de calcula el factorial del numero ingresado
 * \param numero1 primer numero para factorial
 * \param i variable para que funcione el bucle for
 * \return Retorna el valor del factorial del numero
 *
 */

int factorial(int numero1)
{
    int resultadoFactorial = 1;
    int i;

    for(i=numero1; i>=1; i--)
    {
        resultadoFactorial = resultadoFactorial * i;
    }

    return resultadoFactorial;
}
