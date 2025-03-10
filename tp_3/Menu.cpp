#include <iostream>
#include "Menu.hpp"

using namespace std;

Menu::Menu(){
    consola = new Consola();
    refugio = new Refugio;
    mapa = new Mapa();
    grafo = new Grafo(mapa->obtener_dimensiones());
    vehiculo = new Vehiculo();
}

void Menu::inicializar_estructura(){
    refugio->abrir_refugio();
    mapa->cargar_mapa();
    mapa->traducir_mapa_a_grafo(grafo);
    grafo->calcular_caminos_minimos();
}

int Menu::pedir_comando(){
    unsigned int comando;
    cin >> comando;
    while (consola->comando_invalido(comando)){
        cout << "Error! El numero a ingresar es entre 1 y 6 como figura en el menu. Intenta de vuelta" << endl;
        cin >> comando;
    }
    return comando;
}

void Menu::elegir_animal(string &nombre){
    cout << "Ingrese el nombre del animal que quiere adoptar o S/s en caso de querer salir: " << endl;
    getline(cin >> ws, nombre);
    cout << endl;
    if(nombre != SALIR_MINUSCULA && nombre != SALIR_MAYUSCULA){
        if(refugio->buscar_animal(nombre) == NULL){
            cout << "El nombre no se encuentra en la lista. " << endl;
            cout << endl;
        }
    }
}

void Menu::cuidar_animales(){
    Cuidador* cuidador_de_animales = new Cuidador(refugio, consola);
    cuidador_de_animales->cuidar_animales();
    delete cuidador_de_animales;
}

void Menu::buscar_animal(){
    string nombre;
    consola->pedir_nombre_animal(nombre);
    Animal* buscado = refugio->buscar_animal(nombre);

    if(buscado == nullptr){
        cout << "Ese animal no se encuentra!" << endl;
    }
    else{
        refugio->mostrar_animal_disponible(buscado);
    }
}

void Menu::adoptar_animal(){
    int metros_disponibles = 0;
    consola->pedir_metros_disponibles(metros_disponibles);
    refugio->mostrar_animales_habilitados(metros_disponibles); 
    string comando;
    consola->preguntar_comando_adoptar(comando);
    if(stoi(comando) == 1){
        string nombre;
        consola->pedir_nombre_animal(nombre);
        refugio->tramite_adopcion(nombre, metros_disponibles);
    }else{
        cout << "Adopcion cancelada." << endl;
    }
}

void Menu::aumentar_combustible(){
    if(vehiculo->obtener_cantidad_combustible() < MAX_COMBUSTIBLE){
        string cantidad_a_agregar = " ";
        consola->pedir_combustible(vehiculo, cantidad_a_agregar);
        if(vehiculo->puede_aumentar_combustible(cantidad_a_agregar)){
            vehiculo->aumentar_combustible(cantidad_a_agregar);
            cout << "La cantidad de combustible ahora es: " << vehiculo->obtener_cantidad_combustible() << endl;
        }else{
            cout << "Te estas sobrepasando del tope de combustible!" << endl;
        }
    }else{
        cout << "El auto esta lleno de combustible! No hace falta que sea cargado." << endl;
    }
}

void Menu::ejecutar_comandos(bool &fin_de_ordenes, int comando){
    if(refugio->refugio_en_regla()){
        if(comando == OPCION_LISTAR_ANIMALES){
            cout << "Elegiste la opcion N º " << OPCION_LISTAR_ANIMALES << ": LISTAR ANIMALES." << endl;
            cout << "==========================================" << endl;
            (*refugio).listar_animales();
        } else if(comando == OPCION_RESCATAR_ANIMAL){
            cout << "Elegiste la opcion N º " << OPCION_RESCATAR_ANIMAL << ": RESCATAR ANIMAL." << endl;
            cout << "==========================================" << endl;
            rescatar_animal();
        } else if(comando == OPCION_BUSCAR_ANIMAL){
            cout << "Elegiste la opcion N º " << OPCION_BUSCAR_ANIMAL << ": BUSCAR ANIMAL." << endl;
            cout << "==========================================" << endl;
            buscar_animal();
        } else if(comando == OPCION_CUIDAR_ANIMALES){
            cout << "Elegiste la opcion N º " << OPCION_CUIDAR_ANIMALES << ": CUIDAR ANIMALES." << endl;
            cout << "==========================================" << endl;
            cuidar_animales();
        } else if(comando == OPCION_ADOPTAR_ANIMAL){
            cout << "Elegiste la opcion N º " << OPCION_ADOPTAR_ANIMAL << ": ADOPTAR ANIMAL." << endl;
            cout << "==========================================" << endl;
            adoptar_animal();
        } else if(comando == OPCION_CARGAR_COMBUSTIBLE){
            cout << "Elegiste la opcion N º " << OPCION_CARGAR_COMBUSTIBLE << ": CARGAR COMBUSTIBLE." << endl;
            cout << "==========================================" << endl;
            aumentar_combustible();
        } else if(comando == OPCION_GUARDAR_SALIR){
            cout << "Elegiste la opcion N º " << OPCION_GUARDAR_SALIR << ": GUARDAR Y SALIR." << endl;
            cout << "==========================================" << endl;
            refugio->cerrar_refugio();
            fin_de_ordenes = true;
        }
        if(!fin_de_ordenes){
            vehiculo->aumentar_combustible(AUMENTO_COMBUSTIBLE);
            refugio->modificar_estado_animales();
        }
    }else{
        cout<<"ESCAPARON MUCHOS ANIMALES :("<<endl;
        fin_de_ordenes = true;
    }
    
}

void Menu::siguiente_accion(bool &fin_de_ordenes){
    consola->imprimir_opciones();
    string comando;
    consola->pedir_comando(comando);
    ejecutar_comandos(fin_de_ordenes, stoi(comando));
}

void Menu::validar_nombre(string& nombre){
    while(refugio->buscar_animal(nombre) != NULL){
        consola->denegar_nombre(nombre);
    }
}

void Menu::rescatar_animal(){
    int fila = 0;
    int columna = 0;
    int origen = 0;
    int destino = 0;
    string nombre;

    Caracteristicas_aleatorias caracteristicas_aleatorias;

    vehiculo->reiniciar_posicion();
    mapa->cargar_mapa();
    mapa->cargar_elementos(&caracteristicas_aleatorias);


    string comando = "";
    while(comando != VOLVER_MENU_RESCATE && !mapa->estan_todos_rescatados()){

        mapa->mostrar_mapa(vehiculo->obtener_posicion());
        consola->confirmar_posicion_animal(mapa,fila,columna);
        mapa->traducir_coordenada_a_grafo(vehiculo,fila,columna,origen,destino);

        if(vehiculo->puede_llegar(grafo->peso_minimo(origen,destino))){
            if(mapa->esta_rescatado(fila,columna)){
                consola->mostrar_mensaje_denegado();
            }else{
                cola<int, nodoCola<int>>* cola_vertices = new cola<int, nodoCola<int>>();
                cola<struct coordenadas, nodoCola<struct coordenadas>>* cola_coordenadas = new cola<struct coordenadas, nodoCola<struct coordenadas>>();
                
                grafo->calcular_camino_minimo(origen,destino,cola_vertices);
                mapa->traducir_camino_minimo(cola_vertices,cola_coordenadas);
                consola->mostrar_mensaje_rescatado(nombre,fila,columna,vehiculo,cola_coordenadas);
                validar_nombre(nombre);
                
                vehiculo->cambiar_posicion(fila,columna);
                refugio->agregar_animal(mapa->obtener_elemento(fila,columna)[0],nombre,caracteristicas_aleatorias.edad_aleatoria(EDAD_LIMITE),
                                caracteristicas_aleatorias.tamanio_aleatorio(), caracteristicas_aleatorias.personalidad_aleatoria());
                mapa->concluir_rescate(fila,columna);

                delete cola_vertices;
                delete cola_coordenadas;
                vehiculo->disminuir_combustible(grafo->peso_minimo(origen,destino));
            }
        }else{
            consola->desistir_rescate();
        }
        consola->pedir_comando_rescatado(comando);   
    }
}

Menu::~Menu(){
    delete consola;
    delete vehiculo;
    delete refugio;
    delete grafo;
    delete mapa;
}
