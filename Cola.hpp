#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED
template <typename Tipo>
class Cola{
public:
    //Constructor por default
    /** \brief Constructor de la clase
     */
    Cola();
    //Constructor de copias
    /** \brief Constructor de la clase para copiar otros objetos de la clase
     *
     * \param c const Cola&
     *
     */
    Cola(const Cola &c);
    //Operador =
    /** \brief M&eacute;todo del operador = para copiar objetos de la clase a otros objetos
     *
     * \param const Cola &v, el objeto de la clase que va a copiar
     */
    Cola & operator= (const Cola &v);
    //Destructor
    /** \brief Destructor de la clase
     *
     *
     */
    ~Cola();
    //Encolar
    /** \brief M&eacute;todo para a&ntilde; adir cosas de Tipo dentro de la cola
     *
     * \param valor Tipo, el valor que se va a a&ntilde; adir a la cola
     * \return void
     *
     */
    void Encolar(Tipo valor);
    //Desencolar
    /** \brief M&eacute;todo para desencolar el primero valor de la cola
     *
     * \return void
     *
     */
    void Desencolar();
    //Conocer primer valor de la cola
    /** \brief M&eacute;todo para obtener el primer valor de la cola
     *
     * \return Tipo, el valor que se quiere obtener
     *
     */
    Tipo ObtenerPrimero();
    //Conocer el ultimo de la cola
    /** \brief M&eacute;todo para obtener el ultimo valor de la cola
     *
     * \return Tipo, el valor que se quiere obtener
     *
     */  Tipo ObtenerUltimo();
    //Conocer el numero de elementos
    /** \brief M&eacute;todo para conocer la cantidad de elementos que tiene la cola
     *
     * \return int cantidad de elementos de la cola
     *
     */
    int CantidadElementos();
    //Conocer si est&aacute; vac&iacute;a
    /** \brief M&eacute;todo para conocer si la cola esta vac&iacute;a o no
     *
     * \return bool
     *
     */
    bool EstaVacia() const;
    //Vaciar
    /** \brief M&eacute;todo que vac&iacute;a la cola
     *
     * \return void
     *
     */
    void Vaciar();
    //imprimir
    /** \brief M&eacute;todo que imprime los valores de la cola
     *
     * \return void
     *
     */
    void imprimir() const;
private:
    int numElem;
    struct Elemento{
        Tipo valor;
        Elemento *siguiente;

    }*ultimo;
};

#include "Cola.tpp"

#endif // COLA_HPP_INCLUDED
