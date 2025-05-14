#ifndef ARBOLB_HPP_INCLUDED
#define ARBOLB_HPP_INCLUDED

template <typename T, int grado = 5>

class ArbolB{
public:

    /** \brief Constructor de la clase
     *
     *
     */
    ArbolB();

    /** \brief Constructor de copias de la clase
     *
     * \param ArbolB<T const
     * \param aB grado>&
     *
     */
    ArbolB(const ArbolB<T,grado> & aB);

    /** \brief Destructor de la clase
     *
     *
     */
    ~ArbolB();

    /** \brief Operador igual para copiar un &aacute;rbol B
     *
     * \param const ArbolB<T, grado> & aB
     * \return ArbolB
     *
     */
    ArbolB & operator= (const ArbolB<T, grado> & aB);

    /** \brief Agrega un valor al Arbol B
     *
     * \param valor T
     * \return void
     *
     */
    void Agregar(T valor);

    /** \brief Elimina un elemento del &aacute;rbol B
     *
     * \param valor T
     * \return void
     *
     */
    void Eliminar(T valor);
    /** \brief Vacia todos los elementos del &aacute;rbol
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief Imprime por niveles el &aacute;rbol b
     *
     * \return void
     *
     */
    void ImprimirNivel()const;

    /** \brief Busca un elemento en el &aacute;rbol
     *
     * \param valor T, el valor que va a buscar
     * \return bool, true si esta y false si no
     *
     */
    bool Buscar(T valor)const;

    /** \brief M&eacute;todo para obtener la cantidad de elementos que tiene el &aacute;rbol
     *
     * \return int
     *
     */
    int ObtenerNumClaves()const;

    /** \brief Imprime del valor m&aacute;s chico al m&aacute;s grande
     *
     * \return nada
     *
     */
    void ImprimirAsc()const;
    /** \brief Imprime del valor m&aacute;s grande al m&aacute;s chico
     *
     * \return nada
     *
     */
    void ImprimirDes()const;
    void ImprimirHojas() const;
private:

    struct Nodo{
        T clave[grado];
        Nodo * hijo[grado+1];
        Nodo * siguiente;
        bool esHoja;
        int cantValores;
        Nodo():siguiente(nullptr), esHoja(false), cantValores(0){
            for(int i = 0; i <= grado; ++i){
                hijo[i] = nullptr;
            }
        }
        void ImprimirNodo() const;
        Nodo * copiarRama(Nodo * subraiz);
    };
    int cantClaves;
    Nodo * raiz;

    /** \brief Agrega un valor en cierto nodo en especifico
     *
     * \param clave T
     * \param subraiz Nodo *&
     * \return void
     *
     */
    void Agregar(T clave, Nodo *& subraiz);
    /** \brief M&eacute;todo para vaciar el &aacute;rbol
     *
     * \param Nodo *& nodo
     * \return void
     *
     */
    void Vaciar (Nodo *& nodo);
    /** \brief Divide un nodo cuando excede el n&uacute;mero m&aacute;ximo de claves permitidas.
     *
     * \param subraiz Nodo*&, Referencia al nodo que ser&aacute; dividido.
     * \return void
     *
    */
    void Split(Nodo *& subraiz);

    void SplitInter(Nodo *& subraiz);
    /** \brief Encuentra el nodo padre de un nodo dado en el &aacute;rbol.
     *
     * \param actual Nodo*, Nodo desde el cual comienza la b&uacute;squeda.
     * \param hijo Nodo*, Nodo cuyo padre se est&aacute; buscando.
     * \return Nodo*, El nodo padre, o `nullptr` si el nodo es la ra&iacute;z.
     *
    */
    Nodo* BuscarPadre(Nodo* actual, Nodo* hijo);
    /** \brief Inserta una clave en el nodo padre y reorganiza los hijos adecuadamente.
     *
     * \param clave T, Clave que se promociona al nodo padre.
     * \param izq Nodo*, Nodo izquierdo resultante de la divisi&oacute;n.
     * \param der Nodo*, Nodo derecho resultante de la divisi&oacute;n.
     * \param padre Nodo*, Nodo padre al que se a&ntildeadir&aacute; la clave promovida.
     * \return void
     *
     */
    void AgregarPadre(T clave, Nodo* izq, Nodo* der, Nodo* padre);
    /** \brief M&eacute;todo que imprime por niveles un &aacute;rbol B
     *
     * \param subraiz Nodo*
     * \return void
     *
     */
    void ImprimirNivel(Nodo * subraiz)const;
    /** \brief Busca el nodo con el mayor valor
     *
     * \param subraiz Nodo *
     * \return Nodo*, el nodo en que se encuentra el valor mayor
     *
     */
    Nodo * BuscarDirMayor(Nodo * subraiz)const;
    /** \brief Imprime de menor a mayor los valores del &aacute;rbol
     *
     * \param subraiz Nodo*
     * \return void
     *
     */
    void ImprimirAsc(Nodo * subraiz)const;
    /** \brief Imprime de mayor a menor los valores del &aacute;rbol
     *
     * \param subraiz Nodo*
     * \return void
     *
     */
    void ImprimirDes(Nodo * subraiz)const;
    /** \brief Elimina un valor de un nodo hoja.
     *
     * \param nodo Nodo*, Nodo hoja del cual se eliminar&aacute; el valor.
     * \param posicion int, &iacute;ndice en el nodo donde se encuentra la clave a eliminar.
     * \return void
     *
    */
    void EliminarHoja(Nodo* nodo, int posicion);
    /** \brief Redistribuye claves entre nodos hermanos para mantener balance.
     *
     * \param nodo Nodo*, Nodo que necesita redistribuci&oacute;n.
     * \param padre Nodo*, Nodo padre que contiene el enlace entre los nodos hermanos.
     * \return void
     *
    */
    void Redistribuir(Nodo* nodo, Nodo* padre, int posPadre);
    /** \brief Fusiona dos nodos cuando la redistribuci&oacute;n no es posible.
     *
     * \param nodo Nodo*, Nodo que ser&aacute; fusionado con su hermano.
     * \param padre Nodo*, Nodo padre que contiene el enlace entre los nodos hermanos.
     * \param posPadre int, &iacute;ndice en el padre donde se encuentra el enlace con el nodo.
     * \return void
     *
    */
    void Fusionar(Nodo* nodo, Nodo* padre, int posPadre, T valor);

    int BuscarPosPadre(Nodo*  Hijo, Nodo* padre);


};
#include "ArbolB.tpp"

#endif // ARBOLB_HPP_INCLUDED
