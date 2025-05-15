/**
 * \file CapturaSegura.cpp
 *  contiene la implementaci&oacute;n de funciones para capturar enteros y dobles sin que den problemas los caracteres
 * \author Emily Beltran Zazueta
 * \author Mariana Mendoza Moreno
 * \date 23/03/2025
*/

#include<iostream>
#include<limits>

//double CapturarDouble(const char solicitud[], double m)
//{
//    double num;
//    std::cout<<solicitud;
//    std::cin>>num;
//    while (std::cin.fail()){
//        std::cout<<"Error: no es un numero"<<std::endl;
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<double>::max(),'\n');
//        std::cout<<solicitud;
//        std::cin>> num;
//    }
//    return num;
//}


//****************************************************************************

int Capturarentero(const char solicitud[], int m)
{
    int num;
    std::cout<<solicitud;
    std::cin>>num;
    while (std::cin.fail()){
        std::cout<<"Error: no es un numero"<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout<<solicitud;
        std::cin>> num;
    }
    return num;
}
