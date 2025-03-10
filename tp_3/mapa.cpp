#include "mapa.hpp"

Mapa::Mapa(){
    mapa = new string* [MAX_FILAS];
    for(int i = 0; i < MAX_COLUMNAS; i++){
        mapa[i] = new string[MAX_COLUMNAS];
    }
    cantidad_animales = 5;
    animales = new struct animal_mapa[cantidad_animales];
}

void Mapa::cargar_animales(Caracteristicas_aleatorias* caracteristicas_aleatorias){
    struct coordenadas* aux = caracteristicas_aleatorias->vector_coordenadas(MAX_FILAS,MAX_COLUMNAS);
    for(int i = 0; i < cantidad_animales; i++){
        animales[i].coordenada = aux[i];
        animales[i].rescatado = false;
    }
}

void Mapa::cargar_mapa(){

    mapa[0][0] = CAMINO;
    mapa[0][1] = PRECIPICIO;
    mapa[0][2] = TIERRA;
    mapa[0][3] = TIERRA;
    mapa[0][4] = TIERRA;
    mapa[0][5] = TIERRA;
    mapa[0][6] = TIERRA;
    mapa[0][7] = TIERRA;
    mapa[1][0] = CAMINO;
    mapa[1][1] = TIERRA;
    mapa[1][2] = TIERRA;
    mapa[1][3] = TIERRA;
    mapa[1][4] = PRECIPICIO;
    mapa[1][5] = PRECIPICIO;
    mapa[1][6] = PRECIPICIO;
    mapa[1][7] = PRECIPICIO;
    mapa[2][0] = CAMINO;
    mapa[2][1] = CAMINO;
    mapa[2][2] = CAMINO;
    mapa[2][3] = CAMINO;
    mapa[2][4] = CAMINO;
    mapa[2][5] = TIERRA;
    mapa[2][6] = MONTANIA;
    mapa[2][7] = MONTANIA;
    mapa[3][0] = TIERRA;
    mapa[3][1] = TIERRA;
    mapa[3][2] = TIERRA;
    mapa[3][3] = TIERRA;
    mapa[3][4] = CAMINO;
    mapa[3][5] = TIERRA;
    mapa[3][6] = MONTANIA;
    mapa[3][7] = MONTANIA;
    mapa[4][0] = MONTANIA;
    mapa[4][1] = MONTANIA;
    mapa[4][2] = MONTANIA;
    mapa[4][3] = TIERRA;
    mapa[4][4] = CAMINO;
    mapa[4][5] = TIERRA;
    mapa[4][6] = MONTANIA;
    mapa[4][7] = MONTANIA;
    mapa[5][0] = TIERRA;
    mapa[5][1] = TIERRA;
    mapa[5][2] = TIERRA;
    mapa[5][3] = TIERRA;
    mapa[5][4] = CAMINO;
    mapa[5][5] = TIERRA;
    mapa[5][6] = MONTANIA;
    mapa[5][7] = MONTANIA;
    mapa[6][0] = TIERRA;
    mapa[6][1] = PRECIPICIO;
    mapa[6][2] = PRECIPICIO;
    mapa[6][3] = PRECIPICIO;
    mapa[6][4] = CAMINO;
    mapa[6][5] = TIERRA;
    mapa[6][6] = MONTANIA;
    mapa[6][7] = MONTANIA;
    mapa[7][0] = TIERRA;
    mapa[7][1] = TIERRA;
    mapa[7][2] = TIERRA;
    mapa[7][3] = TIERRA;
    mapa[7][4] = CAMINO;
    mapa[7][5] = CAMINO;
    mapa[7][6] = CAMINO;
    mapa[7][7] = CAMINO;
}

void Mapa::mostrar_mapa(coordenadas posicion_vehiculo){
    cout << endl;
    cout << "    0 1 2 3 4 5 6 7" << endl;
    cout << "    ===============" << endl;
    for(int i = 0; i < MAX_FILAS; i++){
        cout << i << " | ";
        for(int j = 0; j < MAX_COLUMNAS; j++){
            if(i == posicion_vehiculo.fila && j == posicion_vehiculo.columna){
                cout << AUTO << " ";
            }else if(mapa[i][j] == CAMINO){
                cout  << BGND_LIGHT_GRAY_246 << "- " << END_COLOR;
            }else if(mapa[i][j] == MONTANIA){
                cout  << BGND_BROWN_94 << "- " << END_COLOR;
            }else if(mapa[i][j] == PRECIPICIO){
                cout  << BGND_BLACK_16 << "- " << END_COLOR;
            }else if(mapa[i][j] == TIERRA){
                cout  << BGND_BROWN_136 << "- " << END_COLOR;
            }else if (esta_rescatado(i,j)){
                cout << TILDE;

            }else{
                cout << mapa[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool Mapa::esta_en_mapa(int fila,int columna){
    return((fila >= 0 && fila < MAX_FILAS) && (columna >= 0 && columna < MAX_COLUMNAS));
}

int Mapa::obtener_dimensiones(){
    return(MAX_FILAS * MAX_COLUMNAS);
}

int Mapa::valor_camino(int fila, int columna){
    int valor = 0;
    if(mapa[fila][columna] == CAMINO){
        valor = CAMINO_VALOR;
    }else if(mapa[fila][columna] == TIERRA){
        valor = TIERRA_VALOR;
    }else if(mapa[fila][columna] == MONTANIA){
        valor = MONTANIA_VALOR;
    }else if(mapa[fila][columna] == PRECIPICIO){
        valor = PRECIPICIO_VALOR;
    }
    return valor;
}

void Mapa::traducir_mapa_a_grafo(Grafo* grafo){

    int n = 0;
    int m = MAX_COLUMNAS;

    for(int i = 0; i < MAX_FILAS; i++){
        n = i * MAX_COLUMNAS;
        for(int j = 0; j < MAX_COLUMNAS; j++){
            
            if(esta_en_mapa(i,j+1)){ //derecha
                grafo->agregar_camino(j+n,j+(n+1),valor_camino(i,j+1));
                /*
                fila matriz -> columna actual del mapa + (cantidad columnas x fila actual)
                columna matriz -> columna actual del mapa + (cantidad columnas x fila actual) + 1
                */
            }
            if(esta_en_mapa(i,j-1)){ //izquierda
                grafo->agregar_camino(j+n,j+(n-1),valor_camino(i,j-1));
                /*
                fila matriz -> columna actual del mapa + (cantidad columnas x fila actual)
                columna matriz -> columna actual del mapa + (cantidad columnas x fila actual) -1 
                */
            }
            if(esta_en_mapa(i-1,j)){ //arriba
                grafo->agregar_camino(j+n,j+n-m,valor_camino(i-1,j));
                /*
                fila matriz -> columna actual del mapa + (cantidad columnas x fila actual)
                columna matriz -> columna actual del mapa + (cantidad columnas x fila actual) - cantidad columnas
                */
            }
            if(esta_en_mapa(i+1,j)){ //abajo
                grafo->agregar_camino(j+n,j+n+m,valor_camino(i+1,j));
                /*
                fila matriz -> columna actual del mapa + (cantidad columnas x fila actual)
                columna matriz -> columna actual del mapa + (cantidad columnas x fila actual) + cantidad columnas
                */
            }
        }
    }
}

void Mapa::traducir_coordenada_a_grafo(Vehiculo* vehiculo,int fila,int columna,int& origen,int& destino){
    origen = vehiculo->obtener_posicion().columna +(vehiculo->obtener_posicion().fila * MAX_FILAS);
    destino = columna + (fila * MAX_FILAS); 
}
struct coordenadas Mapa::traducir_vertice_a_coordenada(int posicion){
    struct coordenadas aux;
    aux.fila = posicion / MAX_FILAS;
    aux.columna = posicion - (aux.fila * MAX_COLUMNAS);
    return(aux);
}

void Mapa::traducir_camino_minimo(cola<int, nodoCola<int>>* vertices,cola<struct coordenadas, nodoCola<struct coordenadas>>*& coordenadas){
    while(vertices->obtener_cantidad_elementos() > 0){
        struct coordenadas coordenada = traducir_vertice_a_coordenada(vertices->baja());
        coordenadas->alta(coordenada);
    }
}

void Mapa::ubicar_animal_aleatorio(struct coordenadas coordenada_aleatoria,string especie_aleatoria){
    mapa[coordenada_aleatoria.fila][coordenada_aleatoria.columna] = especie_aleatoria;
}   

void Mapa::cargar_elementos(Caracteristicas_aleatorias* caracteristicas_aleatorias){
    cargar_animales(caracteristicas_aleatorias);
    for(int i = 0; i < cantidad_animales; i++){
        ubicar_animal_aleatorio(animales[i].coordenada,caracteristicas_aleatorias->especie_aleatoria());
    }
}

bool Mapa::hay_especie_en_posicion(int fila,int columna){
    bool esta = false;
    int i = 0;
    while(!esta && i < cantidad_animales){
        if(fila == animales[i].coordenada.fila && columna == animales[i].coordenada.columna){
            esta = true;
        }
        i++;
    }
    return(esta);
}

string Mapa::obtener_elemento(int fila, int columna){
    return(mapa[fila][columna]);
}

void Mapa::concluir_rescate(int fila,int columna){
    for(int i = 0; i < cantidad_animales; i++){
        if(animales[i].coordenada.fila == fila && animales[i].coordenada.columna == columna){
            animales[i].rescatado = true;
        }
    }
}

bool Mapa::esta_rescatado(int fila,int columna){
    bool rescatado = false;
    for(int i = 0; i < cantidad_animales; i++){
        if(animales[i].coordenada.fila == fila && animales[i].coordenada.columna == columna){
            if(animales[i].rescatado == true){
                rescatado = true;
            }
        }
    }
    return(rescatado);
}

bool Mapa::estan_todos_rescatados(){
    bool estan_rescatados = true;
    int i = 0;
    while(estan_rescatados && i < cantidad_animales){
        if(animales[i].rescatado == false){
            estan_rescatados = false;
        }
        i++;
    }
    return(estan_rescatados);
}

Mapa::~Mapa(){
    for(int i = 0; i < MAX_FILAS; i++){
        delete[] mapa[i];
    }
    delete[] mapa;
    mapa = nullptr;
    
    delete [] animales;
}
