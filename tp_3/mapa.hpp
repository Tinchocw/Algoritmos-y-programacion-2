#ifndef _MAPA_H
#define _MAPA_H

#include <iostream>
#include "grafo.hpp"
#include "caracteristicas_aleatorias.hpp"
#include "vehiculo.hpp"
#include "colors.h"
#include "constantes.hpp"

using namespace std;
class Mapa{

        private:

                string** mapa;
                struct animal_mapa* animales;
                int cantidad_animales;

        public:

                Mapa();

                /*
                 * PRE: Los tipos de casillero son MONTANIA, CAMINO, TIERRA y PRECIPICIO.
                 * POST: Carga el mapa con los costos dependiendo de cada casillero.
                 */
                void cargar_mapa();

                /*
                 * PRE: Mapa previamente cargado.
                 * POST: Muestra el mapa con sus casilleros por color y el vehiculo por pantalla.
                 */
                void mostrar_mapa(coordenadas posicion_vehiculo);

                /*
                 * PRE: -
                 * POST: Devuelve las dimensiones multiplicadas entre si.
                 */
                int obtener_dimensiones();

                /*
                 * PRE: Matriz de adyacencia previamente inicializada.
                 * POST: Traduce el mapa a grafo con sus respectivos pesos, aristas y vertices.
                 */
                void traducir_mapa_a_grafo(Grafo* grafo);
                
                /*
                 * PRE: -
                 * POST: Traduce las coordenada del mapa de donde se encuentra el vehiculo y las coordenadas proximas a
                 * donde se va a mover; traduciendolas en vertices del grafo.
                 */
                void traducir_coordenada_a_grafo(Vehiculo* vehiculo, int fila, int columna, int& origen, int& destino);

                /*
                 * PRE: -
                 * POST: Ubica al vector especies con su posicion y tipo aleatorio en el mapa.
                 */                
                void cargar_elementos(Caracteristicas_aleatorias* caracteristicas_aleatorias);

                /*
                 * PRE: -
                 * POST: Devuelve TRUE en caso de que ya se encuentre una especie ubicada en la posicion aleatoria,
                 * FALSE en caso contrario.
                 */
                bool hay_especie_en_posicion(int fila, int columna);

                /*
                 * PRE: -
                 * POST: Devuelve el elemento del mapa que se encuentra en la posicion pasada por parametro.
                 */
                string obtener_elemento(int fila, int columna);

                /*
                 * PRE: -
                 * POST: Convierte el bool rescatado en true en caso de que la fila y columna recibida por parametro
                 * sea igual a la fila y columna de un animal del vector.
                 */     
                void concluir_rescate(int fila, int columna);

                /*
                 * PRE: -
                 * POST: Devuelve TRUEr en caso de que la fila y columna recibida por parametro
                 * sea igual a la fila y columna de un animal del vector y si ya fue rescatado. En caso contrario
                 * queda en FALSE.
                 */
                bool esta_rescatado(int fila, int columna);

                /*
                 * PRE: -
                 * POST: Traduce al vertice recibido por parametro en coordenadas.
                 */
                struct coordenadas traducir_vertice_a_coordenada(int posicion);
                
                /*
                 * PRE: -
                 * POST: Traduce la cola de vertices en una cola de coordenadas
                 */
                void traducir_camino_minimo(cola<int, nodoCola<int>>* vertices,cola<struct coordenadas, nodoCola<struct coordenadas>>*& coordenadas);
                
                /*
                 * PRE: El vector de animales tiene que estar previamente cargado.
                 * POST: Retorna TRUE cuando todos los animales se encuentran rescatados, FALSE en caso contrario.
                 */
                bool estan_todos_rescatados();

                ~Mapa();

        private:

                /*
                 * PRE: La fila debe ser mayor igual a 0 y menor a MAX_FILAS. La columna debe ser mayor o igual a 0 y menor a MAX_COLUMNAS.
                 * POST: Devuelve TRUE en caso de que la fila y columna se encuentre dentro del rango, FALSE en caso contrario.
                 */
                bool esta_en_mapa(int fila, int columna);

                /*
                 * PRE: -
                 * POST: Ubica una especie aleatoria en el mapa.
                 */
                void ubicar_animal_aleatorio(struct coordenadas coordenada_aleatoria, string especie_aleatoria);

                /*
                 * PRE: EL valor de CAMINO es igual a 1, el MONTANIA 5, el de PRECIPICIO 40 y el de TIERRA 2. 
                 * POST: Asigna y devuelve el valor de los casilleros dependiendo de su tipo.
                 */
                int valor_camino(int fila, int columna);

                /*
                 * PRE: - 
                 * POST: Carga coordenadas de los animales en vector.
                 */
                void cargar_animales(Caracteristicas_aleatorias* caracteristicas_aleatorias);
};

#endif