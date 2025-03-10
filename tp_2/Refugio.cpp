#include "Refugio.hpp"
#include "Caballo.hpp"
#include "Conejo.hpp"
#include "Erizo.hpp"
#include "Gato.hpp"
#include "Perro.hpp"
#include "Lagartija.hpp"
#include "Roedor.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Refugio::Refugio(){
    cantidad_animales = 0;
}

void Refugio::listar_animales(){
    Animales.iterador_inicio();
    for (int i = 1; i <= Animales.tamano_lista(); i++){
        cout << "ANIMAL Nº " << i << endl;
        Animales.consultar_iterador()->listar_informacion();
        Animales.iterador_adelante();
        cout << "==========================================" << endl;
    }
}

bool Refugio::esta_animal(string nombre){
    bool animal_encontrado = false;
    int i = 1;
    Animales.iterador_inicio();
    while(i <= Animales.tamano_lista() && !animal_encontrado){
        
        if(Animales.consultar_iterador()->obtener_nombre() == nombre){
            animal_encontrado = true;
        }
        Animales.iterador_adelante();
        i++;
    }
    return animal_encontrado;
}

void Refugio::mostrar_animal_buscado(string nombre){
    bool encontrado = false;
    int i = 1;
    Animales.iterador_inicio();
    while(i <= Animales.tamano_lista() && !encontrado){
        if(Animales.consultar_iterador()->obtener_nombre() == nombre){
            encontrado = true;
            Animales.consultar_iterador()->listar_informacion();
        }
        Animales.iterador_adelante();
        i++;
    }
}

int Refugio::convertir_string_a_int(string tamano_s){
    int tamano = 0;
    if(tamano_s == S_DIMINUTO){
        tamano = LIM_DIMINUTO;
    }else if(tamano_s == S_PEQUENO){
        tamano = LIM_PEQUENO;
    }else if (tamano_s == S_MEDIANO){
        tamano = LIM_MEDIANO;
    }else if(tamano_s == S_GRANDE){
        tamano = LIM_GRANDE;
    }else if(tamano_s == S_GIGANTE){
        tamano = LIM_GIGANTE;
    }
    return tamano;
}

void Refugio::rescatar_animal(char especie, string nombre, int edad, string tamano, string personalidad){
    Animal* animal_rescatado;
    int nuevo_tamano = convertir_string_a_int(tamano);
    if(especie == CONEJO){
        animal_rescatado = new Conejo(nombre, edad, nuevo_tamano, personalidad);  
    }else if(especie == PERRO){
        animal_rescatado = new Perro(nombre, edad, nuevo_tamano, personalidad);  
    }else if(especie == GATO){
        animal_rescatado = new Gato(nombre, edad, nuevo_tamano, personalidad);
    }else if(especie == CABALLO){
        animal_rescatado = new Caballo(nombre, edad, nuevo_tamano, personalidad);
    }else if(especie == ROEDOR){
        animal_rescatado = new Roedor(nombre, edad, nuevo_tamano, personalidad);
    }else if(especie == LAGARTIJA){
        animal_rescatado = new Lagartija(nombre, edad, nuevo_tamano, personalidad);
    }else if(especie == ERIZO){
        animal_rescatado = new Erizo(nombre, edad, nuevo_tamano, personalidad);
    }
    cantidad_animales++;
    Animales.cargar(animal_rescatado, cantidad_animales);
}

void Refugio::mostrar_animales_habilitados(int tamano){
    cout << "==========================================" << endl;
    cout << "Los animales habilitados son: " << endl;
    cout << endl;
    
    Animales.iterador_inicio();
    for(int i = 1; i <= Animales.tamano_lista(); i++){
        if(Animales.consultar_iterador()->tiene_tamano_deseado(tamano)){
            cout << "ANIMAL Nº " << i << endl;
            Animales.consultar_iterador()->listar_informacion();
            cout << "==========================================" << endl; 
        }
        Animales.iterador_adelante();
    }
    cout << "==========================================" << endl;

}

void Refugio::modificar_estado_animales(){
    Animales.iterador_inicio();
    for (int i = 1; i <= Animales.tamano_lista(); i++){
        Animales.consultar_iterador()->incrementar_hambre();
        Animales.consultar_iterador()->incrementar_suciedad();
        Animales.iterador_adelante();
    }   
}

void Refugio::eliminar_animal(string nombre){
    bool eliminado = false;
    int i = 1;
    Animales.iterador_inicio();
    while(i <= Animales.tamano_lista() && !eliminado){
        if(Animales.consultar_iterador()->obtener_nombre() == nombre){
            delete Animales.consultar_iterador();
            Animales.eliminar(i);
            cantidad_animales--; 
            eliminado = true;
        }
        Animales.iterador_adelante();
        i++;
    }
}

void Refugio::abrir_refugio(){
    ifstream archivo_refugio_r(ARCHIVO);

    if(!archivo_refugio_r.is_open()){
        cout << "No se encontro un archivo con nombre \"" << ARCHIVO << "\", se va a crear el archivo" << endl;
        archivo_refugio_r.open(ARCHIVO, ios::out);
        archivo_refugio_r.close();
        archivo_refugio_r.open(ARCHIVO, ios::in);
    }

    string linea = " ";

    while(getline(archivo_refugio_r, linea)){
        string nombre, edad, tamano, especie, personalidad;
        stringstream stream(linea);

        getline(stream, nombre, DELIMITADOR);
        getline(stream, edad, DELIMITADOR);
        getline(stream, tamano, DELIMITADOR);
        getline(stream, especie, DELIMITADOR);
        getline(stream, personalidad);
        rescatar_animal(especie[0], nombre, stoi(edad), tamano, personalidad);
    }

    archivo_refugio_r.close();
}

void Refugio::cerrar_refugio(){

    ofstream archivo_refugio_w(ARCHIVO);

    Animales.iterador_inicio();
    for (int i = 0; i < Animales.tamano_lista(); i++){
        string nombre, edad, tamano, especie, personalidad;
        Animales.consultar_iterador()->completar_informacion(nombre, edad, tamano, especie, personalidad);
        archivo_refugio_w << nombre << ',' << edad << ',' << tamano << ',' << especie << ',' << personalidad << endl;
        Animales.iterador_adelante();
    }
    archivo_refugio_w.close();
}

void Refugio::mostrar_un_animal(int index){
    Animales.consultar(index)->listar_informacion();
}

void Refugio::banar_individualmente(int index){
    string animal = Animales.consultar(index)->obtener_especie();
    if(animal == S_GATO || animal == S_ROEDOR || animal == S_LAGARTIJA){
        cout << "Este animal no requiere baño" << endl; 
    } else{
        Animales.consultar(index)->limpiar();
    }
}

void Refugio::alimentar_individualmente(int index){
    Animales.consultar(index)->alimentar();
    cout << "El nombre del animal que alimentaste es: " << Animales.consultar(index)->obtener_nombre() << endl;
    cout << "Y su alimento es: " << Animales.consultar(index)->obtener_comida() << endl;
}

void Refugio::alimentar_todos(){
    Animales.iterador_inicio();
    for(int i = 1; i <= Animales.tamano_lista(); i++){
        Animales.consultar_iterador()->alimentar();
        Animales.iterador_adelante();
    }
}

void Refugio::banar_todos(){
    Animales.iterador_inicio();
    for(int i = 1; i <= Animales.tamano_lista(); i++){
        Animales.consultar_iterador()->limpiar();
        Animales.iterador_adelante();
    }
}

int Refugio::obtener_cantidad_animales(){
    return(cantidad_animales);
}

Refugio::~Refugio(){
    Animales.iterador_inicio();
    for (int i = 0; i < cantidad_animales; i++){
        delete Animales.consultar_iterador();
        Animales.iterador_adelante();
    }
}