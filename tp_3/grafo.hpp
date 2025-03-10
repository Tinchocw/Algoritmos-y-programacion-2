#ifndef __GRAFO_HPP_
#define __GRAFO_HPP_
#include <iostream>
#include "camino_minimo.hpp"

using namespace std;

class Grafo{
    private:

        int** matriz_adyacencia;
        int cantidad_vertices;
        Camino_minimo camino_minimo;
        
        /*
         * PRE: -
         * POST: Inicializa la matriz con su diagonal en 0 y las demas posiciones con infinito.
         */
        void llenar_matriz();

        /*
         * PRE: -
         * POST: Libera la memoria de la matriz de adyacencia.
         */
        void liberar_matriz();

    public:

        Grafo(int cantidad_vertices);

        /*
         * PRE: -
         * POST: Muestra por pantalla la matriz de adyacencia.
         */
        void mostrar_matriz_adyacencia();

        /*
         * PRE: El peso es un valor positivo.
         * POST: Ajusta la matriz de adyacencia con el peso ingresado.
         */
        void agregar_camino(int origen, int destino, int peso);

        /*
         * PRE: -
         * POST: Devuelve la cantidad de vertices.
         */
        int obtener_cantidad_vertices();
        
        /*
         * PRE: Caminos minimos previamente calculados.
         * POST: Muestra el camino minimo por pantalla.
         */
        void calcular_camino_minimo(int origen, int destino, cola<int, nodoCola<int>>*& vertices);
        
        /*
         * PRE: Caminos minimos previamente calculados.
         * POST: Devuelve el peso del camino minimo previamente calculado.
         */
        int peso_minimo(int origen, int destino);

        /*
         * PRE: -
         * POST: Calcula las matrices de costos y caminos.
         */
        void calcular_caminos_minimos();

        ~Grafo();

};


#endif