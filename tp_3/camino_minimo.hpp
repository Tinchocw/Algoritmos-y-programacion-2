#ifndef _CAMINO_MINIMO_H
#define _CAMINO_MINIMO_H

#include <iostream>
#include "cola.hpp" 
#include "constantes.hpp"

using namespace std;

class Camino_minimo{
    private:
        int** matriz_caminos;
        int** matriz_pesos;
        int cantidad_vertices;
    
    public:
        
        Camino_minimo(int cantidad_vertices);

        /*
         * PRE: -
         * POST: Calcula las matrices de costos y caminos.
         */
        void calcular_matrices(int** matriz_adyacencia);

        /*
         * PRE: La fila y columna deben estar dentro del rango de la matriz de pesos.
         * POST: Devuelve el costo de la matriz pesos de la coordenada pasada por parametro.
         */
        int costo(int fila, int columna);

        /*
         * PRE: Tiene que estar la matriz de caminos cargada previamente.
         * POST: Carga una cola con el camino minimo entre origen y destino.
         */
        void cargar_camino_minimo(int origen,int destino, cola<int, nodoCola<int>>*& vertices);

        ~Camino_minimo();
    
    private:
        
        /*
         * PRE: -
         * POST: Carga la matriz caminos.
         */
        int** crear_matriz_caminos();

        /*
         * PRE: Matriz de adyacencia bien cargada.
         * POST: Carga la matriz pesos inicializandola con los valores de la matriz de adyacencia.
         */
        int** crear_matriz_costos(int** matriz_adyacencia);
        
        /*
         * PRE: -
         * POST: Libera la memoria de la matriz de pesos y la de caminos.
         */
        void liberar_matrices();

};


#endif