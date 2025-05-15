#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "ArbolB.hpp"
#include "CapturaSegura.hpp"
using namespace std;
enum{SALIR,AGREGAR,ELIMINAR,NIVELES,ASC,DES,BUSCAR};

int main()
{
    int op;
    int cant;
    int num,valor;
//    srand(time(NULL));
//    int v;
    try{

        ArbolB<int, 5> arbol, arbol2, ar;
        ArbolB<double,5> ad;
        ArbolB<char,5> ac;
        ArbolB<string,5> as;



///*****************************************MAIN PRUEBAS********************************************
//
//        cout << "=== Prueba de Inserci\242n ===" << endl;
//        int valores[] = {10, 20, 5, 6, 15, 30, 25, 35, 3, 7, 12, 17, 22, 27, 32,8,9,11,16,18,2,1,0};
//        for (int val : valores) {
//            cout << "Agregando: " << val << endl;
//            arbol.Agregar(val);
//        }
//        cout << "Claves en el \240rbol: " << arbol.ObtenerNumClaves() << endl;
//
//        cout << "\n=== Imprimir en nivel ===" << endl;
//        arbol.ImprimirNivel();
//
//        cout << "\n=== Imprimir en por orden ascendente ===" << endl;
//        arbol.ImprimirAsc();
//        cout << endl;
//
//        cout << "\n=== Imprimir en por orden descendente ===" << endl;
//        arbol.ImprimirDes();
//        cout << endl;
//        cout<<"Buscando valor: " <<boolalpha<< arbol.Buscar(10)<<endl;
//
////        cout << "\n=== Prueba de Eliminaci\242n ===" << endl;
////        int eliminarValores[] = {6,10, 12, 20};
////        for (int val : eliminarValores) {
////            cout << "Eliminando: " << val << endl;
////            arbol.Eliminar(val);
////            arbol.ImprimirNivel();
////            cout << "Claves en el \240rbol: " << arbol.ObtenerNumClaves() << endl;
////            cout << endl;
////        }
//
//        cout << "\n=== Copiar un \240rbol ===" << endl;
//        arbol2 = arbol;
//        arbol2.ImprimirNivel();
//
//        cout << "\n=== Prueba de Vaciar \265rbol ===" << endl;
//        arbol.Vaciar();
//        cout << "Claves despu\202s de vaciar: " << arbol.ObtenerNumClaves() << endl;

///****************************Intro el proyecto****************************
        cout << "~~~~~PROYECTO DE ESTRUCTURA DE DATOS~~~~~" << endl;
        cout << "\t\tARBOL B+ \n" << endl;
        cout << "\t\tEquipo:" << endl;
        cout << "\tBeltran Zazueta Emily Margarita\n\tMachado Felix Flor Maria\n\tMendoza Moreno Mariana\n\tPeregrina Cazares Elias" << endl;
        cout << "\t\t 16/05/2025" << endl;

        ///*Inserci�n de datos rand
        system("pause");
        system("cls");

///***************************pruebas rand************************
//
//        for(int i=0;i<10;++i){
//            v=rand()%100+1;
//            arbol.Agregar(v);
//        }
//        arbol.ImprimirNivel();


///****************************************IDEA 1 MAIN (INT)***************************************

        do{

                cout <<endl<< "-----MENU-----" << endl;
                cout << "\n>INSERTAR Y BORRAR" << endl;
                cout << "*Agregar [" <<AGREGAR << "] " <<endl;
                cout << "*Eliminar [" << ELIMINAR << "] " << endl;
                cout << "\n>TIPOS DE IMPRESION" << endl;
                cout << "*Por niveles ["<<NIVELES<<"] " << endl;
                cout << "*Ascendentemente [" << ASC << "] "<< endl;
                cout << "*Descendentemente [" << DES <<"] "<< endl;
                cout << "\n>BUSCAR" << endl;
                cout << "*Buscar [" << BUSCAR << "] " << endl;
                cout << "*Salir [" << SALIR <<"] "<< endl;
            do{
                cout << endl ;
                op=Capturarentero("Ingresar opci\242n ",op);
                if(op<0 || op>6) throw "Opcion ingresada fuera de rango";
            }while(op<0 || op>6);

            switch(op){
                case(AGREGAR):
                    system("cls");
                    cout << "Cuantos datos desea ingresar? ";
                    cin >> cant;

                    for(int i=1; i <= cant;++i){
                        cout << "Dato a ingresar [" << i << "]: ";
                        cin >> num;
                        arbol.Agregar(num);
                    }
                    break;
                case(ELIMINAR):
                    system("cls");
                    cout << "Que dato desea eliminar? ";
                    cin >> num;
                    arbol.Eliminar(num);
                    system("pause");
                    system("cls");

                    break;

                case(NIVELES):
                    system("cls");
                    cout << "~~~IMPRESI\340N POR NIVELES~~~" << endl;
                    arbol.ImprimirNivel();
                    cout << endl;
                    system("pause");
                    system("cls");

                    break;
                case(ASC):
                    system("cls");
                    cout << "~~~IMPRESI\340N ASCENDENTEMENTE~~~" << endl;
                    arbol.ImprimirAsc();
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                case(DES):
                    system("cls");
                    cout << "~~~IMPRESI\340N DESCENDENTEMENTE~~~" << endl;
                    arbol.ImprimirDes();
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                case(BUSCAR):
                    system("cls");
                    cout << "~~~BUSQUEDA DE DATOS~~~" << endl;
                    cout << "Ingrese dato a buscar: ";
                    cin >> valor;
                    cout << "Resultado de busqueda: ";
                    cout <<boolalpha<< arbol.Buscar(valor) ;
                    cout << endl;
                    system("pause");
                    system("cls");

                    break;
                case(SALIR):
                    cout << "\n\nSaliendo...";
                    break;

                default:
                    cout << "ERROR DE OPCION" << endl;
            }

        }while(op!=0);

///****************************************IDEA 2 MAIN(DOUBLE)***************************************
//    do{
//
//                cout <<endl<< "-----MENU-----" << endl;
//                cout << "\n>INSERTAR Y BORRAR" << endl;
//                cout << "*Agregar [" <<AGREGAR << "] " <<endl;
//                cout << "*Eliminar [" << ELIMINAR << "] " << endl;
//                cout << "\n>TIPOS DE IMPRESION" << endl;
//                cout << "*Por niveles ["<<NIVELES<<"] " << endl;
//                cout << "*Ascendentemente [" << ASC << "] "<< endl;
//                cout << "*Descendentemente [" << DES <<"] "<< endl;
//                cout << "\n>BUSCAR" << endl;
//                cout << "*Buscar [" << BUSCAR << "] " << endl;
//                cout << "*Salir [" << SALIR <<"] "<< endl;
//            do{
//                cout << endl ;
//                op=Capturarentero("Ingresar opci\242n ",op);
//                if(op<0 || op>6) throw "Opcion ingresada fuera de rango";
//            }while(op<0 || op>6);
//
//            switch(op){
//                case(AGREGAR):
//                    system("cls");
//                    cout << "Cuantos datos desea ingresar? ";
//                    cin >> cant;
//
//                    for(int i=1; i <= cant;++i){
//                        cout << "Dato a ingresar [" << i << "]: ";
//                        cin >> num;
//                        ad.Agregar(num);
//                    }
//                    break;
//                case(ELIMINAR):
//                    system("cls");
//                    cout << "Que dato desea eliminar? ";
//                    cin >> num;
//                    ad.Eliminar(num);
//                    system("pause");
//                    system("cls");
//
//                    break;
//
//                case(NIVELES):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N POR NIVELES~~~" << endl;
//                    ad.ImprimirNivel();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//
//                    break;
//                case(ASC):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N ASCENDENTEMENTE~~~" << endl;
//                    ad.ImprimirAsc();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//                    break;
//                case(DES):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N DESCENDENTEMENTE~~~" << endl;
//                    ad.ImprimirDes();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//                    break;
//                case(BUSCAR):
//                    system("cls");
//                    cout << "~~~BUSQUEDA DE DATOS~~~" << endl;
//                    cout << "Ingrese dato a buscar: ";
//                    cin >> valor;
//                    cout << "Resultado de busqueda: ";
//                    cout <<boolalpha<< ad.Buscar(valor) ;
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//
//                    break;
//                case(SALIR):
//                    cout << "\n\nSaliendo...";
//                    break;
//
//                default:
//                    cout << "ERROR DE OPCION" << endl;
//            }
//
//        }while(op!=0);

///****************************************IDEA 3 MAIN(CHAR)***************************************
//    do{
//
//                cout <<endl<< "-----MENU-----" << endl;
//                cout << "\n>INSERTAR Y BORRAR" << endl;
//                cout << "*Agregar [" <<AGREGAR << "] " <<endl;
//                cout << "*Eliminar [" << ELIMINAR << "] " << endl;
//                cout << "\n>TIPOS DE IMPRESION" << endl;
//                cout << "*Por niveles ["<<NIVELES<<"] " << endl;
//                cout << "*Ascendentemente [" << ASC << "] "<< endl;
//                cout << "*Descendentemente [" << DES <<"] "<< endl;
//                cout << "\n>BUSCAR" << endl;
//                cout << "*Buscar [" << BUSCAR << "] " << endl;
//                cout << "*Salir [" << SALIR <<"] "<< endl;
//            do{
//                cout << endl ;
//                op=Capturarentero("Ingresar opci\242n ",op);
//                if(op<0 || op>6) throw "Opcion ingresada fuera de rango";
//            }while(op<0 || op>6);
//
//            switch(op){
//                case(AGREGAR):
//                    system("cls");
//                    cout << "Cuantos datos desea ingresar? ";
//                    cin >> cant;
//
//                    for(int i=1; i <= cant;++i){
//                        cout << "Dato a ingresar [" << i << "]: ";
//                        cin >> num;
//                        ac.Agregar(num);
//                    }
//                    break;
//                case(ELIMINAR):
//                    system("cls");
//                    cout << "Que dato desea eliminar? ";
//                    cin >> num;
//                    ac.Eliminar(num);
//                    system("pause");
//                    system("cls");
//
//                    break;
//
//                case(NIVELES):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N POR NIVELES~~~" << endl;
//                    ac.ImprimirNivel();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//
//                    break;
//                case(ASC):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N ASCENDENTEMENTE~~~" << endl;
//                    ac.ImprimirAsc();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//                    break;
//                case(DES):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N DESCENDENTEMENTE~~~" << endl;
//                    ac.ImprimirDes();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//                    break;
//                case(BUSCAR):
//                    system("cls");
//                    cout << "~~~BUSQUEDA DE DATOS~~~" << endl;
//                    cout << "Ingrese dato a buscar: ";
//                    cin >> valor;
//                    cout << "Resultado de busqueda: ";
//                    cout <<boolalpha<< ac.Buscar(valor) ;
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//
//                    break;
//                case(SALIR):
//                    cout << "\n\nSaliendo...";
//                    break;
//
//                default:
//                    cout << "ERROR DE OPCION" << endl;
//            }
//
//        }while(op!=0);


///****************************************IDEA 2 MAIN(DOUBLE)***************************************
//    do{
//
//                cout <<endl<< "-----MENU-----" << endl;
//                cout << "\n>INSERTAR Y BORRAR" << endl;
//                cout << "*Agregar [" <<AGREGAR << "] " <<endl;
//                cout << "*Eliminar [" << ELIMINAR << "] " << endl;
//                cout << "\n>TIPOS DE IMPRESION" << endl;
//                cout << "*Por niveles ["<<NIVELES<<"] " << endl;
//                cout << "*Ascendentemente [" << ASC << "] "<< endl;
//                cout << "*Descendentemente [" << DES <<"] "<< endl;
//                cout << "\n>BUSCAR" << endl;
//                cout << "*Buscar [" << BUSCAR << "] " << endl;
//                cout << "*Salir [" << SALIR <<"] "<< endl;
//            do{
//                cout << endl ;
//                op=Capturarentero("Ingresar opci\242n ",op);
//                if(op<0 || op>6) throw "Opcion ingresada fuera de rango";
//            }while(op<0 || op>6);
//
//            switch(op){
//                case(AGREGAR):
//                    system("cls");
//                    cout << "Cuantos datos desea ingresar? ";
//                    cin >> cant;
//
//                    for(int i=1; i <= cant;++i){
//                        cout << "Dato a ingresar [" << i << "]: ";
//                        cin >> num;
//                        as.Agregar(num);
//                    }
//                    break;
//                case(ELIMINAR):
//                    system("cls");
//                    cout << "Que dato desea eliminar? ";
//                    cin >> num;
//                    as.Eliminar(num);
//                    system("pause");
//                    system("cls");
//
//                    break;
//
//                case(NIVELES):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N POR NIVELES~~~" << endl;
//                    as.ImprimirNivel();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//
//                    break;
//                case(ASC):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N ASCENDENTEMENTE~~~" << endl;
//                    as.ImprimirAsc();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//                    break;
//                case(DES):
//                    system("cls");
//                    cout << "~~~IMPRESI\340N DESCENDENTEMENTE~~~" << endl;
//                    as.ImprimirDes();
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//                    break;
//                case(BUSCAR):
//                    system("cls");
//                    cout << "~~~BUSQUEDA DE DATOS~~~" << endl;
//                    cout << "Ingrese dato a buscar: ";
//                    cin >> valor;
//                    cout << "Resultado de busqueda: ";
//                    cout <<boolalpha<< as.Buscar(valor) ;
//                    cout << endl;
//                    system("pause");
//                    system("cls");
//
//                    break;
//                case(SALIR):
//                    cout << "\n\nSaliendo...";
//                    break;
//
//                default:
//                    cout << "ERROR DE OPCION" << endl;
//            }
//
//        }while(op!=0);

    } catch (const char* mensaje) {
        cerr << mensaje << endl;
    }

    return 0;
}
