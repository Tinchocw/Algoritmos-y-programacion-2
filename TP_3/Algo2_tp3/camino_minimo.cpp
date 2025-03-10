#include "camino_minimo.hpp"

Camino_minimo::Camino_minimo(int cantidad_vertices){
    this-> cantidad_vertices = cantidad_vertices;
}

int ** Camino_minimo::crear_matriz_caminos(){
    int ** caminos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        caminos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Camino_minimo::crear_matriz_costos(int** matriz_adyacencia){

    int ** costos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        costos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            costos[i][j] = matriz_adyacencia[i][j];
        }
    }
    return costos;
}

void Camino_minimo::calcular_matrices(int** matriz_adyacencia) {

    matriz_pesos = crear_matriz_costos(matriz_adyacencia);
    matriz_caminos = crear_matriz_caminos();

    for (int verticeIntermedio = 0; verticeIntermedio < cantidad_vertices; verticeIntermedio++) {

        for (int origen = 0; origen < cantidad_vertices; origen++){

            for (int destino = 0; destino < cantidad_vertices; destino++) {

                int costo = matriz_pesos[origen][verticeIntermedio] + matriz_pesos[verticeIntermedio][destino];

                if (matriz_pesos[origen][destino] > costo) {
                    matriz_pesos[origen][destino] = costo;
                    matriz_caminos[origen][destino] = matriz_caminos[origen][verticeIntermedio];
                } else if (matriz_pesos[origen][destino] == INFINITO){
                    matriz_caminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }

            }
        }
    }
}

void Camino_minimo::liberar_matrices() {
    if(matriz_pesos != nullptr && matriz_caminos != nullptr){
        for(int i = 0; i < cantidad_vertices; i++){
            delete[] matriz_pesos[i];
            delete[] matriz_caminos[i];
        }
        delete[] matriz_pesos;
        delete[] matriz_caminos;

        matriz_pesos = nullptr;
        matriz_caminos = nullptr;
    }
}

void Camino_minimo::cargar_camino_minimo(int origen,int destino, cola<int, nodoCola<int>>*& vertices){
    if (matriz_caminos[origen][destino] == origen) {
        return;
    }
    if(matriz_caminos[origen][destino] == destino) {
        return;
    }
    vertices->alta(matriz_caminos[origen][destino]);
    cargar_camino_minimo(matriz_caminos[origen][destino],destino,vertices);
}

int Camino_minimo::costo(int fila, int columna){
    return(matriz_pesos[fila][columna]);
}

Camino_minimo::~Camino_minimo(){
    liberar_matrices();
}