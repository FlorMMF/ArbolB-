#include <iostream>
#include "ArbolB.hpp"
using namespace std;

int main()
{
    try{
        ArbolB<int, 5> arbol, arbol2, ar;



        cout << "=== Prueba de Inserci\242n ===" << endl;
        int valores[] = {2,4,6,8,10,5,15,20,25,7,14,21,28,35,11,22,33,44,55};
        for (int val : valores) {
            cout << "Agregando: " << val << endl;
            arbol.Agregar(val);
        }
        cout << "Claves en el \240rbol: " << arbol.ObtenerNumClaves() << endl;

        cout << "\n=== Imprimir en nivel ===" << endl;
        arbol.ImprimirNivel();

        cout << "\n=== Imprimir en por orden ascendente ===" << endl;
        arbol.ImprimirAsc();
        cout << endl;

        cout << "\n=== Imprimir en por orden descendente ===" << endl;
        arbol.ImprimirDes();
        cout << endl;
        cout<<"Buscando valor: " <<boolalpha<< arbol.Buscar(10)<<endl;

//        cout << "\n=== Prueba de Eliminaci\242n ===" << endl;
//        int eliminarValores[] = {6,10, 12, 20};
//        for (int val : eliminarValores) {
//            cout << "Eliminando: " << val << endl;
//            arbol.Eliminar(val);
//            arbol.ImprimirNivel();
//            cout << "Claves en el \240rbol: " << arbol.ObtenerNumClaves() << endl;
//            cout << endl;
//        }

        cout << "\n=== Copiar un \240rbol ===" << endl;
        arbol2 = arbol;
        arbol2.ImprimirNivel();

        cout << "\n=== Prueba de Vaciar \265rbol ===" << endl;
        arbol.Vaciar();
        cout << "Claves despu\202s de vaciar: " << arbol.ObtenerNumClaves() << endl;


    } catch (const char* mensaje) {
        cerr << mensaje << endl;
    }

    return 0;
}
