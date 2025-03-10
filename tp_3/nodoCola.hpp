#ifndef NODO_COLA_HPP
#define NODO_COLA_HPP

template <typename Dato>

class nodoCola{
private:
    Dato dato_almacenado;
    nodoCola* nodo_trasero;
public:
    nodoCola(Dato dato){
        dato_almacenado = dato;
        nodo_trasero = nullptr;
    }

    /*
     * PRE:
     * POST: Devuelve el dato almacenado.
     */
    Dato obtener_dato(){
        return (dato_almacenado);
    }

    /*
     * PRE: -
     * POST: Devuelve el nodo trasero.
     */
    nodoCola* obtener_nodo_trasero(){
        return (nodo_trasero);
    }

    /*
     * PRE: -
     * POST: El nodo trasero pasa a valer puntero nodo.
     */
    void cambiar_nodo_trasero(nodoCola* nodo){
        nodo_trasero = nodo;
    }
};

#endif