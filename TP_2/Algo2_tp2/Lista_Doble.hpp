#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

using namespace std;

template <typename Dato>

class Nodo {
private:
    Dato dato_almacenado;
    Nodo* nodo_enlazado_detras;
    Nodo* nodo_enlazado_delante;
public:

    /*
     * PRE: -
     * POST: Crea un nodo al que se le asigna un dato recibido por parametro a su atributo dato_almacenado. Inicializa los punteros
     * nodo_enlazado_delante y nodo_enlazado_detras.
     */
    Nodo(Dato dato){
        dato_almacenado = dato;
        nodo_enlazado_delante = nullptr;
        nodo_enlazado_detras = nullptr;
    }

    /*
     * PRE: -
     * POST: Devuelve el dato almacenado.
     */
    Dato obtener_dato(){
        return (dato_almacenado);
    }

    /*
     * PRE: -
     * POST: Devuelve el nodo enlazado delante.
     */
    Nodo* obtener_nodo_enlazado_delante(){
        return (nodo_enlazado_delante); 
    }

    /*
     * PRE: -
     * POST: Devuelve el nodo enlazado detras.
     */
    Nodo* obtener_nodo_enlazado_detras(){
        return (nodo_enlazado_detras); 
    }

    /*
     * PRE: -
     * POST: Asigna al nodo enlazado delante un puntero nodo.
     */
    void cambiar_nodo_enlazado_delante(Nodo* puntero_nodo){
        nodo_enlazado_delante = puntero_nodo;
    }

    /*
     * PRE: -
     * POST: Asigna al nodo enlazado detras un puntero nodo.
     */
    void cambiar_nodo_enlazado_detras(Nodo* puntero_nodo){
        nodo_enlazado_detras = puntero_nodo;
    }
};


template <typename Dato, class Nodo>

class Lista_Doble {
private:
    Nodo* primer_elemento;
    Nodo* ultimo_elemento;
    Nodo* iterador;
    int cantidad_elementos;
private:

    /*
     * PRE: -
     * POST: Devuelve un puntero nodo_auxiliar.
     */
    Nodo* obtener_nodo(int index){
        Nodo* nodo_auxiliar = primer_elemento;
        for (int i = 1; i < index; i++){
            nodo_auxiliar = nodo_auxiliar->obtener_nodo_enlazado_delante();
        }
        return nodo_auxiliar;
    }
    
    
    /*
     * PRE: -
     * POST: Carga al principio de la lista un nuevo nodo. Su cantidad de elementos incrementa.
     */
    void cargar_inicio(Dato dato){
        Nodo* nuevo_nodo = new Nodo(dato);
        primer_elemento->cambiar_nodo_enlazado_detras(nuevo_nodo);
        nuevo_nodo->cambiar_nodo_enlazado_delante(primer_elemento);

        primer_elemento = nuevo_nodo;

        cantidad_elementos++;
    }
    
    /*
     * PRE: -
     * POST: ELimina de la lista su ultimo elemento. Su cantidad de elementos decrece.
     */
    void eliminar_final(){
        Nodo* nodo_auxiliar = ultimo_elemento->obtener_nodo_enlazado_detras();
    
        delete ultimo_elemento;

        cantidad_elementos--;
        ultimo_elemento = nodo_auxiliar;
    }

    /*
     * PRE: -
     * POST: ELimina de la lista su primer elemento. Su cantidad de elementos decrece.
     */
    void eliminar_inicio(){
        Nodo* nodo_auxiliar = primer_elemento->obtener_nodo_enlazado_delante();
    
        delete primer_elemento;

        cantidad_elementos--;
        primer_elemento = nodo_auxiliar;
    }
public:

    /*
     * PRE: -
     * POST: Crea una lista doble con cero elementos.
     */
    Lista_Doble(){
        cantidad_elementos = 0;
    }

    /*
     * PRE: -
     * POST: Crea una lista doble con un elemento.
     */
    Lista_Doble(Dato dato_inicial){
        primer_elemento = new Nodo(dato_inicial);
        ultimo_elemento = primer_elemento;
    
        iterador = primer_elemento;

        cantidad_elementos = 1;
    }


    /*
     * PRE: -
     * POST: Carga al final de la lista un nuevo nodo. Su cantidad de elementos incrementa.
     */
    void cargar_final(Dato dato){
        Nodo* nuevo_nodo = new Nodo(dato);
        ultimo_elemento->cambiar_nodo_enlazado_delante(nuevo_nodo);
        nuevo_nodo->cambiar_nodo_enlazado_detras(ultimo_elemento);

        ultimo_elemento = nuevo_nodo;
    
        cantidad_elementos++;   
    }

    /*
     * PRE: Lista no llena.
     * POST: Carga elementos a la lista en el inicio o final dependiendo de la posicion pasada por parametro. 
     * Incrementa cantidad de elementos.
     */
    void cargar(Dato dato, int index_carga){
        if (cantidad_elementos == 0 && index_carga == 1){
            primer_elemento = new Nodo(dato);
            ultimo_elemento = primer_elemento;
    
            iterador = primer_elemento;
            cantidad_elementos = 1;
        }
        else if (index_carga == 1){
            cargar_inicio(dato);
        }
        else if (index_carga == (cantidad_elementos +1)){
            cargar_final(dato);
        }
        else if (index_carga <= (cantidad_elementos)){
            Nodo* nuevo_nodo = new Nodo(dato);
            Nodo* nodo_anterior = obtener_nodo(index_carga -1);
        
            nuevo_nodo->cambiar_nodo_enlazado_delante(nodo_anterior->obtener_nodo_enlazado_delante());
            nuevo_nodo->cambiar_nodo_enlazado_detras(nodo_anterior);
            nodo_anterior->cambiar_nodo_enlazado_delante(nuevo_nodo);
            cantidad_elementos++;
        }
    }

    /*
     * PRE: Lista no vacia.
     * POST: Elimina elementos a la lista dependiendo de la posicion pasada por parametro. Decrece cantidad de elementos.
     */
    void eliminar(int index_eliminar){
            if (index_eliminar == 1){
            eliminar_inicio();
        }
        else if (index_eliminar == (cantidad_elementos)){
            eliminar_final();
        }
        else if (index_eliminar <= (cantidad_elementos)){
            Nodo* nodo_buscado = obtener_nodo(index_eliminar);
            Nodo* nodo_siguiente = nodo_buscado->obtener_nodo_enlazado_delante();
            Nodo* nodo_anterior = nodo_buscado->obtener_nodo_enlazado_detras();

            nodo_siguiente->cambiar_nodo_enlazado_detras(nodo_anterior);        
            nodo_anterior->cambiar_nodo_enlazado_delante(nodo_siguiente);

            delete nodo_buscado;
            cantidad_elementos--;
        }
    }

    /*
     * PRE: Lista no vacia
     * POST: Devuelve el dato de la lista en la posicion pasada por parametro.
     */
    Dato consultar(int index_consulta){
        if (index_consulta == 1){
            return (primer_elemento->obtener_dato());
        }
        else if (index_consulta == cantidad_elementos){
            return (ultimo_elemento->obtener_dato());
        }
        else{
            Nodo* nodo_buscado = obtener_nodo(index_consulta);
            return (nodo_buscado->obtener_dato());
        }
    }

    /*
     * PRE: -
     * POST: Devuelve la cantidad de elementos que hay en la lista.
     */
    int tamano_lista(){
        return (cantidad_elementos);
    }
    
    /*
     * PRE: Lista no vacia y con un solo elemento.
     * POST: Devuelve al ultimo (y unico) elemento de la lista.
     */
    bool elemento_unico(){
        return (ultimo_elemento->obtener_nodo_enlazado_detras() == nullptr);
    }


    /*
     * PRE: -
     * POST: Devuelve el iterador en el primer elemento de la lista.
     */
    void iterador_inicio(){
        iterador = primer_elemento;
    }
    
    /*
     * PRE: -
     * POST: Devuelve el iterador en el ultimo elemento de la lista.
     */
    void iterador_final(){
        iterador = ultimo_elemento;
    }

    /*
     * PRE: -
     * POST: Devuelve el iterador en el nodo enlazado delante.
     */
    void iterador_adelante(){
        iterador = iterador->obtener_nodo_enlazado_delante();
    }

    /*
     * PRE: -
     * POST: Devuelve el iterador en el nodo enlazado detras.
     */
    void iterador_atras(){
        iterador = iterador->obtener_nodo_enlazado_detras();
    }

    /*
     * PRE: -
     * POST: Devuelve la posicion en donde se encuentra el iterador.
     */
    Dato consultar_iterador(){
        return (iterador->obtener_dato());
    }

    /*
     * PRE: -
     * POST: -
     */
    ~Lista_Doble(){
        if (cantidad_elementos != 0){
            while (!(elemento_unico())){
                eliminar_final();
            }
            delete primer_elemento;
        }
    }
};

#endif