#include "grafo.hpp"


Grafo::Grafo(int cantidad_vertices) : camino_minimo(cantidad_vertices){
    this->cantidad_vertices = cantidad_vertices;
    matriz_adyacencia = new int *[this->cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        matriz_adyacencia[i] = new int[cantidad_vertices];
    }
    llenar_matriz();
} 

void Grafo::agregar_camino(int origen, int destino, int peso){
    matriz_adyacencia[origen][destino] = peso;

}

void Grafo::llenar_matriz(){
    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            if(i == j){
                matriz_adyacencia[i][j] = 0;
            }else{
                matriz_adyacencia[i][j] = INFINITO;
            }
        }
    }
}

void Grafo::mostrar_matriz_adyacencia(){
    for(int i = 0; i < cantidad_vertices; i++){
        cout << i+1 << " | ";
        for(int j = 0; j < cantidad_vertices; j++){
           if(matriz_adyacencia[i][j] == INFINITO){
               cout << "- ";
            }else{
                cout << matriz_adyacencia[i][j] << " ";
            } 
        }
        cout << endl;
    }
}

void Grafo::liberar_matriz(){
    if(matriz_adyacencia != nullptr){
        for(int i = 0; i < cantidad_vertices; i++){
            delete[] matriz_adyacencia[i];
        }
        delete[] matriz_adyacencia;
        matriz_adyacencia = nullptr;
    }
}

void Grafo::calcular_camino_minimo(int origen, int destino, cola<int, nodoCola<int>>*& vertices){
    camino_minimo.cargar_camino_minimo(origen, destino, vertices);
}

int Grafo::peso_minimo(int origen, int destino){
    return(camino_minimo.costo(origen,destino));
}

void Grafo::calcular_caminos_minimos(){
    camino_minimo.calcular_matrices(matriz_adyacencia);
}

Grafo::~Grafo(){
    liberar_matriz();
}