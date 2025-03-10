#include <iostream>
#include "Consola.hpp"

using namespace std;

Consola::Consola(){    
}

void Consola::imprimir_opciones(){
    cout << "================== MENU ==================" << endl;
    cout << " > 1. Listar animales" << endl;
    cout << " > 2. Rescatar animales" << endl;
    cout << " > 3. Buscar animal" << endl;
    cout << " > 4. Cuidar animal" << endl;
    cout << " > 5. Adoptar animal" << endl;
    cout << " > 6. Cargar combustible" << endl;
    cout << " > 7. Guardar y salir" << endl;
    cout << "==========================================" << endl;
}

bool Consola::comando_invalido(int comando){
    return((comando < OPCION_MINIMA) || (comando > OPCION_MAXIMA));
}

void Consola::pedir_comando(string &comando){
    cout << "Ingrese el comando deseado: ";
    getline(cin >> ws, comando);
    while(comando_invalido(stoi(comando))){
        cout << "Ese comando no es valido! " << endl;
        cout << "Ingrese el comando deseado valido: ";
        getline(cin >> ws, comando);
    }
}

void Consola::pedir_nombre_animal(string& nombre){
    cout << endl << "Ingrese el NOMBRE del animal: " << endl;
    getline(cin >> ws, nombre);
}

void Consola::pedir_metros_disponibles(int &metros_disponibles){
    string respuesta;
    cout << "Ingrese el espacio disponible para el animal (en metros cuadrados): ";
    getline(cin >> ws, respuesta);
    metros_disponibles = stoi(respuesta);
}

void Consola::imprimir_submenu_adoptar(){
    cout << " > 1. Adoptar un animal" << endl;
    cout << " > 2. Cancelar opcion" << endl;
}

void Consola::preguntar_comando_adoptar(string &comando){
    cout << "Que desea hacer?" << endl;
    imprimir_submenu_adoptar();
    getline(cin >> ws, comando);
    while(stoi(comando) <= MIN_PREGUNTA_INDIVIDUAL && stoi(comando) >= (MAX_PREGUNTA_INDIVIDUAL-1)){
        cout << endl << "Esa opcion es invalida. Ingrese nuevamente:" << endl << endl;
        imprimir_submenu_adoptar();
        getline(cin >> ws, comando);
    }
}

bool Consola::es_opcion_individual_valida(int opcion){
    return(opcion >= MIN_PREGUNTA_INDIVIDUAL && opcion <= MAX_PREGUNTA_INDIVIDUAL); 
}

void Consola::imprimir_submenu_cuidados(){
    cout << " > 1. Bañar a un animal" << endl;
    cout << " > 2. Alimentar a un animal" << endl;
    cout << " > 3. Saltear" << endl;
    cout << " > 4. Finalizar cuidados" << endl;
}

void Consola::preguntar_comando_cuidados(string &comando){
    cout << "Que desea hacer?" << endl;
    imprimir_submenu_cuidados();
    getline(cin >> ws, comando);
    while(!es_opcion_individual_valida(stoi(comando))){
        cout << endl << "Esa opcion es invalida. Ingrese nuevamente:" << endl << endl;
        imprimir_submenu_cuidados();
        getline(cin >> ws, comando);
    }
}

void Consola::pedir_posicion(int& fila, int& columna){
    cout << "Ingrese la posición del animal que quiere rescatar" << endl;
    cout << "Fila: ";
    cin >> fila;
    cout << "Columna: ";
    cin >> columna;
    cout << endl;
}

bool Consola::es_posicion_valida(int fila, int columna){
    return((fila >= 0 && fila < MAX_FILAS) && (columna >= 0 && columna < MAX_COLUMNAS));
}

void Consola:: validar_posicion(int& fila,int& columna){
    while(!es_posicion_valida(fila,columna)){
        cout << "Esa posición no es valida. Ingresa otra" << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        cout << endl;
    }
}

void Consola::confirmar_posicion_animal(Mapa* mapa,int& fila,int& columna){
        pedir_posicion(fila,columna);
        validar_posicion(fila,columna);
    while(!mapa->hay_especie_en_posicion(fila, columna)){
        cout << "No hay un animal en esa posición" << endl;
        pedir_posicion(fila,columna);
        validar_posicion(fila,columna);
    }
}

void Consola::denegar_nombre(string& nombre){
    cout << "Ese nombre no es valido. Ingresa otro nombre" << endl;
    getline(cin >> ws,nombre);
}

void Consola::mostrar_camino_minimo(int fila,int columna,Vehiculo* vehiculo,cola<struct coordenadas, nodoCola<struct coordenadas>>* cola_coordenadas){
    cout << "[" << vehiculo->obtener_posicion().fila << "," << vehiculo->obtener_posicion().columna << "] ";
    while(cola_coordenadas->obtener_cantidad_elementos() > 0){
        struct coordenadas coordenada_actual = cola_coordenadas->baja();
        cout << "[" << coordenada_actual.fila << "," << coordenada_actual.columna << "] ";
    }
    cout << "[" << fila << "," << columna << "] ";
    cout << endl;
}

void Consola::mostrar_mensaje_rescatado(string& nombre, int fila, int columna, Vehiculo* vehiculo,cola<struct coordenadas, nodoCola<struct coordenadas>>* cola_coordenadas){
    cout << "Pudiste llegar a destino." << endl;
    cout << "Su camino fue: " << endl;
    mostrar_camino_minimo(fila,columna,vehiculo,cola_coordenadas);
    pedir_nombre_animal(nombre);
}

void Consola::desistir_rescate(){
    cout << "No es posible rescatar al animal" << endl;
}

bool Consola::es_opcion_rescatar_valida(int opcion){
    return(opcion == 1 || opcion == 2);
}

void Consola::imprimir_submenu_rescatar(){
    cout << "Que desea hacer:" << endl;
    cout << "1. Seguir resacatando" << endl;
    cout << "2. Volver al menu" << endl;
}

void Consola::pedir_comando_rescatado(string& comando){
    imprimir_submenu_rescatar();
    getline(cin >> ws, comando);
    while(!es_opcion_rescatar_valida(stoi(comando))){
        cout << endl << "Esa opcion es invalida. Ingrese nuevamente:" << endl << endl;
        imprimir_submenu_rescatar();
        getline(cin >> ws, comando);
    }
}

void Consola::imprimir_camino_minimo(struct coordenadas* camino_minimo, int tope){
    for(int i = 0; i < tope; i++){
        cout << "[" << camino_minimo[i].fila << "," << camino_minimo[i].columna << "] , ";
    }
}

void Consola::mostrar_mensaje_denegado(){
    cout << "Ese animal ya fue rescatado." << endl;
}

bool Consola::es_combustible_valido(int combustible_ingresado){
    return(combustible_ingresado > 0 && combustible_ingresado <= 100);
}

void Consola::pedir_combustible(Vehiculo* vehiculo, string& cantidad_a_agregar){
    cout << "Su cantidad actual de combustible es: " << vehiculo->obtener_cantidad_combustible() << endl;
    cout << "Cuanto combustible desea agregar?" << endl;
    getline(cin >> ws, cantidad_a_agregar);
    while(!es_combustible_valido(stoi(cantidad_a_agregar))){
        cout << "Esa cantidad es invalida. Ingrese nuevamente: " << endl;
        getline(cin >> ws, cantidad_a_agregar);
    }
}

Consola::~Consola(){

}