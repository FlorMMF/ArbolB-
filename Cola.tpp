#include <iostream>

template <typename Tipo>
Cola<Tipo>::Cola() : numElem(0) , ultimo(nullptr) {


}

template <typename Tipo>
Cola<Tipo>::Cola(const Cola &c) : numElem(0) , ultimo(nullptr){
    *this = c;
}

template <typename Tipo>
Cola<Tipo>::~Cola(){
    Vaciar();
}

template <typename Tipo>
Cola<Tipo> & Cola<Tipo>::operator= (const Cola<Tipo> &v){
    if (this == &v) return *this;
    this ->Vaciar();
    Elemento *aux = v.primero;

    for(int i =0; i < v.numElem ; ++i){
        Encolar(aux -> valor);
        aux = aux -> siguiente;
    }


    return *this;

}

//Encolar
template <typename Tipo>
void Cola<Tipo>::Encolar(Tipo valor){

    Elemento * nuevo = new Elemento;
    nuevo -> valor = valor;
    if(!EstaVacia()){
        nuevo -> siguiente = ultimo -> siguiente;
        ultimo -> siguiente = nuevo;

    }else{
        nuevo -> siguiente = nuevo;
    }
    ultimo = nuevo;
    //ultimo -> siguiente = primero;
    ++ numElem;

}
//Desencolar
template <typename Tipo>
void Cola<Tipo>::Desencolar(){
    if(EstaVacia())throw("La cola esta vacia");
    Elemento * porBorrar  = ultimo -> siguiente;

    if(numElem == 1) ultimo = nullptr;
    else ultimo -> siguiente = porBorrar -> siguiente;
    delete porBorrar;

    --numElem;
}
//Conocer primero de la cola
template <typename Tipo>
Tipo Cola<Tipo>::ObtenerPrimero(){
    if(EstaVacia())throw "La cola esta vacia";
    return ultimo -> siguiente -> valor;
}
//Conocer el ultimo de la cola
template <typename Tipo>
Tipo Cola<Tipo>::ObtenerUltimo(){
    if(EstaVacia())throw "La cola esta vacia";
    return ultimo -> valor;
}
//Conocer el numero de elementos
template <typename Tipo>
int Cola<Tipo>::CantidadElementos(){
    return numElem;
}
//Conocer si est� vac�a
template <typename Tipo>
bool Cola<Tipo>::EstaVacia() const{
    return numElem == 0;
}
//Vaciar
template <typename Tipo>
void Cola<Tipo>::Vaciar(){
    while(!EstaVacia()) Desencolar();
}
//imprimir
template <typename Tipo>
void Cola<Tipo>::imprimir() const{
    if(EstaVacia())return;
    Elemento *aux = ultimo -> siguiente;
    int i = 0;
    while(i != (numElem)){
        std::cout << aux -> valor <<  ", ";
        aux = aux -> siguiente;
        ++i;
    }

    std::cout << std::endl;
}
