#ifndef _CARACTERISTICAS_ALEATORIAS_H_
#define _CARACTERISTICAS_ALEATORIAS_H_

#include <iostream>
#include "Tamano.hpp"
#include "Personalidad.hpp"
#include "constantes.hpp"
using namespace std;


class Caracteristicas_aleatorias{
    private:
    
        int cantidad_personalidades;
        int cantidad_tamanios;
        struct coordenadas* coordenadas;
        int cantidad_coordenadas;
        int edad;
        string* especies;
        int cantidad_especies;

    public:

        Caracteristicas_aleatorias();
        
        /*
         * PRE: -
         * POST: Devuelve un puntero a un tamanio dependiendo del numero aleatorio salido.
         */
        Tamano* tamanio_aleatorio();

        /*
         * PRE: -
         * POST: Devuelve un puntero a una personalidad dependiendo del numero aleatorio salido.
         */
        Personalidad* personalidad_aleatoria();

        /*
         * PRE: Vector especies previamente cargado.
         * POST: Devuelve al tipo de especie que se encuentra en la posicion del vector asignada por el
         * numero aleatorio.
         */        
        string especie_aleatoria();

        /*
         * PRE: limite_fila y limite_columnas mayor o iguales a 0 y menor o iguales a MAX_FILAS y MAX_COLUMNAS.
         * POST: Devuelve una coordenada generada aleatoriamente.
         */
        struct coordenadas coordenada_aleatoria(int limite_fila,int limite_columnas);

        /*
         * PRE: -
         * POST: Devuelve true en caso de que la coordenada de vector coordenadas sea igual a la coordenada pasada
         * por parametro; FALSE en caso contrario.
         */
        bool esta_repetido(int tope,struct coordenadas coordenada);

        /*
         * PRE: limite_fila y limite_columnas mayor o iguales a 0 y menor o iguales a MAX_FILAS y MAX_COLUMNAS.
         * POST: Genera y devuelve un vector con coordenadas aleatorias distintas.
         */
        struct coordenadas* vector_coordenadas(int limite_filas,int limite_columnas);

        /*
         * PRE: edad_limite menor o igual a MAX_EDAD.
         * POST: Devuelve una edad aleatoria.
         */
        int edad_aleatoria(int edad_limite);
        
        ~Caracteristicas_aleatorias();

    private:

        /*
         * PRE: -
         * POST: Devuelve una posicion aleatoria.
         */
        int posicion_aleatoria(int limite);

        /*
         * PRE: -
         * POST: Crea vector especies y struct de coordenadas, asigna topes cantidad_especies, cantidad_personalidades,
         * cantidad_tamanios y cantidad_coordenadas.
         */
        void cargar_caracteristicas();

};


#endif