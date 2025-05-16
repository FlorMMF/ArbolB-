#include "Cola.hpp"
#include <iostream>
using namespace std;

//Métodos públicos

template <typename T, int grado>
ArbolB<T, grado>::ArbolB() : cantClaves(0){
    if (grado < 3 || grado > 8) throw "No es posible crear un \240rbol del grado elegido";
    raiz = new Nodo();
}

template <typename T, int grado>
ArbolB<T, grado>::~ArbolB(){
    Vaciar();
}

template <typename T, int grado>
ArbolB<T, grado>::ArbolB(const ArbolB<T,grado> & aB){
    *this = aB;
}

template <typename T, int grado>
ArbolB<T, grado> & ArbolB<T, grado>::operator= (const ArbolB<T, grado> & aB){
    if(this == &aB) return *this;
    raiz = raiz -> copiarRama(aB.raiz);
    cantClaves = aB.cantClaves;
    return *this;
}

template <typename T, int grado>
void ArbolB<T, grado>::Agregar(T valor){
    if (cantClaves == 0){
        raiz->clave[0] = valor;
        raiz->cantValores++;
        raiz->esHoja = true;
        cantClaves++;
    }else{

        Agregar(valor, raiz);
    }
}

template <typename T, int grado>
void ArbolB<T, grado>::Eliminar(T valor){
    if (!raiz) throw "Error: Intentando eliminar en un \240rbol vac\241o.";

    //Se desciende hasta encontrar el nodo hoja que tiene el valor que se busca
    Nodo* hoja = raiz;
    while (!hoja->esHoja){
        int i = 0;
        while (i < hoja->cantValores && valor >= hoja->clave[i]) i++;
        hoja = hoja->hijo[i];
    }

    //Se busca la posicion de la clave en la hoja que encontramos
    int posicion = -1;
    for (int i = 0; i < hoja->cantValores; ++i){
        if(hoja->clave[i] ==valor){
            posicion = i;
            break;
        }
    }

    //si no encontramos la clave en la hoja la clave no existe
    if (posicion == -1) throw "Error: el valor no se ha encontrado en la hoja.";
    
    Nodo* padre = BuscarPadre(raiz, hoja);
    int posPadre = BuscarPosPadre(hoja, padre);
    //verificación para ver si se elimina
    bool actualizar = (posicion == 0 && hoja->cantValores > 1);
    T reemplazo;
    if (actualizar){
        reemplazo = hoja->clave[1];
    }
    
    
    for (int i = posicion; i < hoja->cantValores - 1; ++i){
            hoja->clave[i] = hoja->clave[i + 1];
        }
        hoja->cantValores--;
        
    if (actualizar){
        if (padre){
            ActualizarAncestro(raiz, valor, reemplazo);
        }else if (padre) {
            padre->clave[posPadre] = reemplazo;
        }
    }


    //Si queda por debajo del minimo permitido se distribuye o fusiona
    if (hoja->cantValores < (grado - 1) / 2 && hoja != raiz){

        if(padre -> hijo[0] == hoja){

            if(padre -> hijo[1] -> cantValores <= ( (grado- 1) / 2 )){

                Fusionar(hoja, padre, posPadre, valor, posicion);
            }else{
                Redistribuir(hoja, padre, posPadre);
            }
        }else if(padre -> hijo[padre -> cantValores] == hoja){

            if(padre -> hijo[posPadre] -> cantValores <= ( (grado - 1) / 2 )){
                Fusionar(hoja, padre, posPadre, valor, posicion);
            }else{
                Redistribuir(hoja, padre, posPadre);
            }
        }else{

            if(padre -> hijo[posPadre] -> cantValores > ( (grado - 1) / 2 ) || padre -> hijo[posPadre + 2] -> cantValores > ( (grado - 1) / 2 )){

                Redistribuir(hoja, padre, posPadre);
            }else{

                Fusionar(hoja, padre, posPadre, valor, posicion);
            }

        }

    }

    //Si la raíz está vacia y por alguna razon no tiene hijos, entonces el arbol queda vacio
    if (raiz->cantValores == 0 && !raiz->hijo[0]){
        delete raiz;
        raiz = nullptr;
    }
    cantClaves--;
}

template <typename T, int grado>
void ArbolB<T, grado>::Vaciar(){
    Vaciar(raiz);
    raiz = nullptr;
    cantClaves = 0;
}

template <typename T, int grado>
void ArbolB<T, grado>::ImprimirNivel() const{
    ImprimirNivel(raiz);
}

template <typename T, int grado>
bool ArbolB<T, grado>::Buscar(T valor)const {
    Nodo* aux = raiz;

    while (aux) {
        int i = 0;
        while (i < aux->cantValores && valor > aux->clave[i]) {
            i++;
        }
        if (i < aux->cantValores && valor == aux->clave[i]) {
            return true;
        }
        aux = aux->hijo[i];
    }

    return false;
}

template <typename T, int grado>
int ArbolB<T, grado>:: ObtenerNumClaves()const{
    return cantClaves;
}

template <typename T, int grado>
void ArbolB<T, grado>:: ImprimirAsc()const{
    ImprimirAsc(raiz);
    std::cout<<"\b\b ";

}

template <typename T, int grado>
void ArbolB<T, grado>:: ImprimirDes()const{
    ImprimirDes(raiz);
    std::cout<<"\b\b ";

}
///Métodos privados *********************************************************************************************

template <typename T, int grado>
void ArbolB<T, grado>::Agregar(T valor, Nodo*& subraiz){

    if(subraiz->esHoja){
        //Se inserta un nodo hojaxx|
        int i;
        for (i = subraiz->cantValores - 1; i >= 0 && subraiz->clave[i] > valor; --i){
            subraiz->clave[i + 1] = subraiz->clave[i];

        }
        subraiz->clave[i + 1] = valor;
        subraiz->cantValores++;

        //Si el nodo hoja está lleno esntonces se divide
        if (subraiz->cantValores == grado){
            Split(subraiz);
            //por que sumaba la cantidad de claves cuando se divide? si lo va a hacer despues
            //cantClaves++;
        }
        cantClaves++;
    }else{
        //Si no se baja por el árbol de forma recursiva
        int i = 0;
        while (i < subraiz->cantValores && valor > subraiz->clave[i]) i++;
        Agregar(valor, subraiz->hijo[i]);
    }

}
template <typename T, int grado>
typename ArbolB<T, grado>::Nodo* ArbolB<T, grado>::BuscarPadre(Nodo* actual, Nodo* hijo){
    if (!actual || actual == hijo) return nullptr;

    for (int i = 0; i <= actual->cantValores; ++i){
        if (actual->hijo[i] == hijo) return actual;
        if (actual->hijo[i]){
            Nodo* resultado = BuscarPadre(actual->hijo[i], hijo);
            if (resultado) return resultado;
        }
    }
    return nullptr;
}

template <typename T, int grado>
void ArbolB<T, grado>::AgregarPadre(T clave, Nodo* izq, Nodo* der, Nodo* padre){
    int i;
    for (i = padre->cantValores - 1; i >= 0 && padre->clave[i] > clave; --i){
        padre->clave[i + 1] = padre->clave[i];
        padre->hijo[i + 2] = padre->hijo[i + 1];
    }

    padre->clave[i + 1] = clave;
    padre->hijo[i + 1] = izq;
    padre->hijo[i + 2] = der;
    ++(padre->cantValores);

    if (padre->cantValores == grado){
        Split(padre);
    }
}

template <typename T, int grado>
void ArbolB<T, grado>::Split(Nodo*& subraiz){
    int medio = grado / 2;
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->esHoja = subraiz->esHoja;
    T clavePromovida = subraiz->clave[medio];

   //se mueven los valores
   if(!subraiz->esHoja){
        for (int i = 0; i < subraiz->cantValores-medio-1; ++i){
            nuevoNodo->clave[i] = subraiz->clave[i+medio+1];
        }

        //se recorren los hijos

            for(int i=0;i<=subraiz->cantValores-(medio); ++i){
                nuevoNodo->hijo[i]=subraiz->hijo[i+medio+1];
                subraiz->hijo[i+medio+1]=nullptr;
            }
            //deberia haber alguna proteccion de los punteros siguente??

            nuevoNodo->cantValores = (subraiz->cantValores - medio)-1;
            subraiz->cantValores = medio;
    }else{
        for (int i = medio; i < subraiz->cantValores; ++i){
            nuevoNodo->clave[i - medio] = subraiz->clave[i];
        }
        //Se enlazan los nodos hoja
        nuevoNodo->siguiente = subraiz->siguiente;
        subraiz->siguiente = nuevoNodo;

            nuevoNodo->cantValores = subraiz->cantValores - medio;
            subraiz->cantValores = medio;
    }

    if (subraiz == raiz){
        //Si es la raiz pues se crea un nuevo nodo raiz
        Nodo* nuevaRaiz = new Nodo();
        nuevaRaiz->clave[0] = clavePromovida;
        nuevaRaiz->hijo[0] = subraiz;
        nuevaRaiz->hijo[1] = nuevoNodo;
        nuevaRaiz->cantValores = 1;
        raiz = nuevaRaiz;
    }else {
        //Si no es la raíz, se sube la clave promovida :p
        Nodo* padre = BuscarPadre(raiz, subraiz);
        AgregarPadre(clavePromovida, subraiz, nuevoNodo, padre);
    }
}

template <typename T, int grado>
void ArbolB<T, grado>::ImprimirNivel(Nodo* subraiz) const{
    Cola<Nodo*> cola;
    if (subraiz != nullptr){
        cola.Encolar(subraiz);
        while (!cola.EstaVacia()){
            int nivelTam=cola.CantidadElementos();

            for(int i=0; i<nivelTam; ++i){
                Nodo* actual = cola.ObtenerPrimero();

                actual->ImprimirNodo();
                cola.Desencolar();

                if(!actual->esHoja){
                    for (int i = 0; i <= actual->cantValores; ++i){
                        if (actual->hijo[i] != nullptr){
                            cola.Encolar(actual->hijo[i]);
                        }
                    }


                }
            }

            std::cout << std::endl;
        }

    }

}

template <typename T, int grado>
void ArbolB<T, grado>::Vaciar(Nodo*& nodo){
    if(cantClaves == 0)return;
    if (nodo != nullptr){
        for (int i = 0; i <= nodo->cantValores; ++i){
            Vaciar(nodo->hijo[i]);
        }

        delete nodo;
        nodo = nullptr;

    }
    cantClaves = 0;
}

template <typename T, int grado>
void ArbolB<T, grado>::Nodo::ImprimirNodo() const{
    std::cout << '[';
    for (int i = 0; i < cantValores; ++i){
        std::cout << clave[i] << ", ";
    }
    std::cout <<"\b\b] ";
}

template <typename T, int grado>
void ArbolB<T, grado>::ImprimirHojas() const {
    Nodo* hoja = raiz;
    while (!hoja->esHoja) {
        hoja = hoja->hijo[0];  // Descender hasta la primera hoja
    }

    // Recorrer todas las hojas
    std::cout << "Nodos hoja: ";
    while (hoja) {
        std::cout << "[";
        for (int i = 0; i < hoja->cantValores; ++i) {
            std::cout << hoja->clave[i] << (i < hoja->cantValores - 1 ? ", " : "");
        }
        std::cout << "] -> ";
        hoja = hoja->siguiente;
    }
    std::cout << "NULL\n";
}

template <typename T, int grado>
typename ArbolB<T, grado>::Nodo * ArbolB<T, grado>::Nodo::copiarRama(Nodo * subraiz){
    if(subraiz == nullptr) return nullptr;
    Nodo * copia = new Nodo();
    for (int i = 0; i < subraiz -> cantValores; ++i){
        copia -> clave[i] = subraiz -> clave[i];
        ++(copia -> cantValores);
    }
    if(subraiz -> hijo[0] != nullptr){
        for (int i = 0 ; i <= subraiz -> cantValores; ++i){
            if(subraiz -> hijo[i] != nullptr){
                copia -> hijo[i] = copiarRama(subraiz -> hijo[i]);
            }
        }
    }

    return copia;

}

template <typename T, int grado>
typename ArbolB<T, grado>::Nodo* ArbolB<T, grado>::BuscarDirMayor(Nodo* subraiz) const{
    if (!subraiz){
        throw "Error: Nodo inv\240lido en BuscarDirMayor()";
    }
    while (subraiz->hijo[subraiz->cantValores] != nullptr){
        subraiz = subraiz->hijo[subraiz->cantValores];
    }
    if (subraiz->cantValores == 0){
        throw "Error cr\241tico: El nodo de reemplazo est\240 vac\241o.";
    }
    return subraiz;
}


template <typename T, int grado>
void ArbolB<T, grado>:: ImprimirAsc(Nodo * subraiz)const{
    if(subraiz != nullptr){


        Nodo* hoja = subraiz;
        while (!hoja->esHoja && hoja->hijo[hoja->cantValores] != nullptr){
            hoja = hoja->hijo[0];
        }

        ///********
        while(hoja != nullptr){
            for(int i =0;i < hoja->cantValores; ++i){
                std::cout << hoja->clave[i] << ", ";
            }
            hoja = hoja->siguiente;
        }
        ///****


    }


}

template <typename T, int grado>
void ArbolB<T, grado>:: ImprimirDes(Nodo * subraiz)const{
    if(subraiz!= nullptr){
        ///***
        if(!subraiz->esHoja){
            for(int i = subraiz->cantValores; i >= 0;--i){
                ImprimirDes(subraiz->hijo[i]);
            }
        }else{
            for(int i = subraiz->cantValores - 1; i >= 0; --i){
                std::cout << subraiz->clave[i] << ", ";
            }
        }

   }


}

template <typename T, int grado>
void ArbolB<T, grado>::EliminarHoja(Nodo* nodo, int posicion){
    for (int i = posicion; i < nodo->cantValores - 1; ++i){
        nodo->clave[i] = nodo->clave[i + 1];
    }
    --(nodo->cantValores);
    if (nodo->cantValores >= (grado - 1) / 2 || nodo == raiz) return;
    Nodo* padre = BuscarPadre(raiz, nodo);
    Redistribuir(nodo, padre);
}

template <typename T, int grado>
void ArbolB<T, grado>::Redistribuir(Nodo* nodo, Nodo* padre, int posPadre) {
    if (!nodo || !padre) {
        throw "Error: Nodo o padre inv\240lidos";
    }
    // Intentar redistribuir con el hermano izquierdo
    if (posPadre > 0) {
            //nuestro nodo es la posicion del padre+1 tal que su hermano derecho esta en la posicion del padre
        Nodo* hermanoIzq = padre->hijo[posPadre];

        if (hermanoIzq->cantValores > (grado - 1) / 2) {
            // Tomamos la última clave del hermano izquierdo y la movemos al nodo
            for (int i = nodo->cantValores; i > 0; --i) {
                nodo->clave[i] = nodo->clave[i - 1];
            }

            //actualizamos la primera clave
            nodo->clave[0] = hermanoIzq->clave[hermanoIzq->cantValores];

            //actualizamos la clave del padre
            padre->clave[posPadre] = nodo->clave[0];

            //aumentamos y reducimos los indices donde corresponde
            hermanoIzq->cantValores--;
            nodo->cantValores++;
            return;
        }
    }

    // Intentar redistribuir con el hermano derecho
    if (posPadre < padre->cantValores) {
            //nuestro nodo es el hijoizq del padre tal que es la posicion del padre+1, el hermano derecho de este indice la posicion del padre+2
        Nodo* hermanoDer = padre->hijo[posPadre + 2];

        if (hermanoDer->cantValores > (grado - 1) / 2) {
            //vamos a tomar el primer indice del hermano izq que tiene una copia almacenada en la clave del padre +1
            nodo->clave[nodo->cantValores] = padre->clave[posPadre+1];

            //actualizamos las claves del padre a la derecha como nos vamos a robar la primera clave va a ser la segunda
            padre->clave[posPadre+1] = hermanoDer->clave[1];

            //reacomodamos las claves del hermano
            for (int i = 0; i < hermanoDer->cantValores - 1; ++i) {
                hermanoDer->clave[i] = hermanoDer->clave[i + 1];
            }

            //aumentamos y reducimos los indices donde corresponde
            hermanoDer->cantValores--;
            nodo->cantValores++;
            return;
        }
    }
}


template <typename T, int grado>
void ArbolB<T, grado>::Fusionar(Nodo* nodo, Nodo* padre, int posPadre, T valor, int posicion){
    Nodo* hermano = (nodo == padre -> hijo[0]) ? padre->hijo[1] : padre->hijo[posPadre];

    if(nodo == padre -> hijo[0]){
    //si el nodo es el primero y por lo tanto el hermano es el derecho y no el izquierdo
        for (int i = 0; i < hermano->cantValores; ++i){
            nodo->clave[nodo->cantValores] = hermano->clave[i];
            nodo->cantValores++;

        }

        //Si son nodos hojas se mantiene el enlace entre ellos
        if (nodo->esHoja){
            nodo->siguiente = hermano->siguiente;
        }


         //Se actualiza el nodo padre eliminando la clave que se acaba de fusionar
        for (int i = posPadre; i < padre->cantValores - 1; ++i){
            padre->clave[i] = padre->clave[i + 1];

        }
        for (int i = 1; i < padre->cantValores; ++i){

            padre->hijo[i ] = padre->hijo[i + 1];
        }

        padre->cantValores--;
        delete hermano;

    }else{

        //se elimina el valor del nodo
        //si el valor que esta en el nodo es el mismo del padre se reemplaza primero
        for(int i = 0; i < nodo->cantValores; ++i){
            hermano->clave[hermano->cantValores] = nodo->clave[i];
            hermano->cantValores++;
        }
            //Si son nodos hojas se mantiene el enlace entre ellos
        if (nodo->esHoja){
            hermano->siguiente = nodo->siguiente;
        }
        //Se actualiza el nodo padre eliminando la clave que se acaba de fusionar
        for (int i = posPadre; i < padre->cantValores - 1; ++i){
            padre->clave[i] = padre->clave[i + 1];
            padre->hijo[i + 1] = padre->hijo[i + 2];
        }
        for (int i = posPadre; i < padre->cantValores; ++i){

            padre->hijo[i ] = padre->hijo[i ];
        }

        padre->cantValores--;
        delete nodo;

   }

    ActualizarAncestro(padre,valor, nodo -> clave[posicion]);
}

template <typename T, int grado>
int ArbolB<T, grado>::BuscarPosPadre(Nodo*  Hijo, Nodo* padre){
    int posPadre = -1;

    for (int i = 0; i <= padre->cantValores; ++i) {
        if (padre->hijo[i] == Hijo) {
            posPadre = i;
                break;
        }
    }

    if (posPadre == -1) {
        throw "Error: No se pudo encontrar la posici\243n del nodo en su padre.";
    }else return posPadre -1;

}


template <typename T, int grado>
void ArbolB<T, grado>:: ActualizarAncestro(Nodo * nodo, T valor, T reemplazo){
    if (!nodo) return;

    for (int i = 0; i < nodo->cantValores; ++i){
        if (nodo->clave[i] == valor){
            nodo->clave[i] = reemplazo;
            return;
        }
    }

    if (!nodo->esHoja){
        for (int i = 0; i <= nodo->cantValores; ++i){
            ActualizarAncestro(nodo->hijo[i], valor, reemplazo);
        }
    }
}
