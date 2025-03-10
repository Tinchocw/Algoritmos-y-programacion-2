#ifndef COLA_HPP
#define COLA_HPP

#include "nodoCola.hpp"

template <typename Dato, class nodoCola>

class cola{
private:
    nodoCola* primero_en_cola;
    nodoCola* ultimo_en_cola;
    int elementos_en_cola;

public:
    cola(){
        primero_en_cola = nullptr;
        ultimo_en_cola = nullptr;
        elementos_en_cola = 0;
    }

    /*
     * PRE: -
     * POST: Carga un elemento a la cola.
     */
    void alta(Dato dato){
        if (elementos_en_cola == 0){
            primero_en_cola = new nodoCola(dato);
            ultimo_en_cola = primero_en_cola;
            elementos_en_cola++;
        }
        else{
            nodoCola* nuevo_nodo = new nodoCola(dato);
            ultimo_en_cola->cambiar_nodo_trasero(nuevo_nodo);
            ultimo_en_cola = nuevo_nodo;
            elementos_en_cola++;
        }
    }

    /*
     * PRE: -
     * POST: Elimina un elemento de la cola y luego lo devuelve.
     */
    Dato baja(){
        Dato dato = primero_en_cola->obtener_dato();
        nodoCola* nuevo_cabeza_cola = primero_en_cola->obtener_nodo_trasero();

        delete primero_en_cola;
        elementos_en_cola--;
        primero_en_cola = nuevo_cabeza_cola;

        return (dato);     
    }

    /*
     * PRE:
     * POST: Devuelve la cantidad de elementos de la cola.
     */
    int obtener_cantidad_elementos(){
        return (elementos_en_cola);
    }

    ~cola(){
        while (elementos_en_cola > 0){
            baja();
        }
    }
};



#endif