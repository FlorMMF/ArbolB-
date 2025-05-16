/**
 * \file CapturaSegura.hpp
 *  contiene la definici&oacute;n de funciones para capturar enteros y dobles sin que den problemas los caracteres
 * \author Emily Beltran Zazueta
 * \author Mariana Mendoza Moreno
 * \date 23/03/2025
*/

#ifndef CAPTURASEGURA_HPP_INCLUDED
#define CAPTURASEGURA_HPP_INCLUDED

/** \brief Captura un double de manera segura sin aceptar caracteres
 *
 * \param solicitud[] const char mensaje que se imprimir� cuando haya u error
 * \param m double el numero que se quiere leer
 * \return double el numero cuando se capture exitosametne
 *
 */
double CapturarDouble(const char solicitud[], double m);

///*******************************************************************************************************************************

/** \brief Captura un entero de manera segura sin aceptar caracteres
 *
 * \param solicitud[] const char mensaje que se imprimir� cuando haya u error
 * \param m int el numero que se quiere leer
 * \return int el numero cuando se capture exitosametne
 *
 */
int Capturarentero(const char solicitud[], int m);

#endif // CAPTURASEGURA_HPP_INCLUDED
