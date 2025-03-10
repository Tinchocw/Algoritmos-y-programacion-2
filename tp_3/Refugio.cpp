#include "Refugio.hpp"

#include "Caballo.hpp"
#include "Conejo.hpp"
#include "Erizo.hpp"
#include "Gato.hpp"
#include "Perro.hpp"
#include "Lagartija.hpp"
#include "Roedor.hpp"
#include "mapa.hpp"
#include "grafo.hpp"
#include "vehiculo.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Refugio::Refugio() : Animales(3){
    lector = new Lector_csv(ARCHIVO);
    cantidad_animales_descuidados = 0;
}

Animal* Refugio::buscar_animal(string nombre_buscado){
    Animal* animal_buscado = Animales.busqueda(Animales.obtener_raiz(), nombre_buscado);
    return(animal_buscado);
}

void Refugio::mostrar_animal_disponible(Animal* animal){
    if(animal != nullptr){
        animal->listar_informacion();
    }
}

void Refugio::listar_animales(){
    int tope_animales = Animales.obtener_cantidad_elementos();
    int i = 0;
    Animal* vector_aux[tope_animales];
    Animales.copiar_info_disponible(vector_aux); 
    while(i < tope_animales){
        mostrar_animal_disponible(vector_aux[i]);
        cout << "--------------------" << endl;
        i++; 
    }
}

void Refugio::banar_individualmente(Animal* animal){
    Animal* animal_a_banar = buscar_animal(animal->obtener_nombre());
    if (animal_a_banar != nullptr){
        animal_a_banar->limpiar();
    }
    else{
        cout << "Animal no encotrado! Intente nuevamente" << endl;
    }
}

void Refugio::alimentar_individualmente(Animal* animal){
    Animal* animal_a_alimentar = buscar_animal(animal->obtener_nombre()); 
    if (animal_a_alimentar != nullptr){
        animal_a_alimentar->alimentar();
        cout << "Felicidades, alimentaste al animal con su comida favorita, la cual es: " << animal_a_alimentar->obtener_comida() << endl;
    }
    else{
        cout << "Animal no encontrado! Intente nuevamente" << endl; 
    }
}

void Refugio::agregar_animal(char especie, string nombre, int edad, Tamano* tamano_animal, Personalidad* personalidad_animal){
    Animal* animal_rescatado;
    if(especie == CONEJO){
        animal_rescatado = new Conejo(nombre, edad, tamano_animal, personalidad_animal);  
    }else if(especie == PERRO){
        animal_rescatado = new Perro(nombre, edad, tamano_animal, personalidad_animal);  
    }else if(especie == GATO){
        animal_rescatado = new Gato(nombre, edad, tamano_animal, personalidad_animal);
    }else if(especie == CABALLO){
        animal_rescatado = new Caballo(nombre, edad, tamano_animal, personalidad_animal);
    }else if(especie == ROEDOR){
        animal_rescatado = new Roedor(nombre, edad, tamano_animal, personalidad_animal);
    }else if(especie == LAGARTIJA){
        animal_rescatado = new Lagartija(nombre, edad, tamano_animal, personalidad_animal);
    }else if(especie == ERIZO){
        animal_rescatado = new Erizo(nombre, edad, tamano_animal, personalidad_animal);
    }
    Animales.insertar(nombre, animal_rescatado);
}

void Refugio::mostrar_animales_habilitados(int metros_disponibles){
    int tope_animales = Animales.obtener_cantidad_elementos();
    Animal* vec_aux[tope_animales];
    Animales.copiar_info_disponible(vec_aux);

    arbolB<int, Animal*, Nodo<int, Animal*>> Animales_habilitados(3);
    int tope_animales_habilitados = 0;

    for(int i = 0; i < tope_animales; i++){
        if(vec_aux[i]->tiene_capacidad_disponible(metros_disponibles)){ 
            Animales_habilitados.insertar(vec_aux[i]->obtener_edad(), vec_aux[i]);
            tope_animales_habilitados++;
        }
    }
    
    Animal* vec_aux_habilitados[tope_animales_habilitados];
    Animales_habilitados.copiar_info_disponible(vec_aux_habilitados);

    for(int i = 0; i < tope_animales_habilitados; i++){
        mostrar_animal_disponible(vec_aux_habilitados[i]);
        cout<<endl;
    }
}

void Refugio::tramite_adopcion(string nombre_elegido, int metros_disponibles){
    Animal* animal_elegido = Animales.busqueda(Animales.obtener_raiz(), nombre_elegido);
    if(animal_elegido->tiene_capacidad_disponible(metros_disponibles)){
        Animales.eliminar(Animales.obtener_raiz(), nombre_elegido);
        cout << "¡Felicitaciones, adoptaste a: " << nombre_elegido << "!" << endl;
    }else{
        cout << "Ese animal no esta disponible para ser adoptado." << endl;
    }
}

bool Refugio::refugio_en_regla(){
    return (!(cantidad_animales_descuidados >= TOPE_ANIMALES_ESCAPARON));
}

void Refugio::abrir_refugio(){
    lector->cargar_animales(this);
}

void Refugio::cerrar_refugio(){
    int tope_animales_disponibles = Animales.obtener_cantidad_elementos();
    Animal* vector_animales_disponibles[tope_animales_disponibles];
    Animales.copiar_info_disponible(vector_animales_disponibles);


    lector->guardar_animales(vector_animales_disponibles, tope_animales_disponibles);


    int tope_animales_completo = Animales.obtener_cantidad_totales();
    Animal* vector_animales_completo[tope_animales_completo];
    Animales.copiar_info_completa(vector_animales_completo);
    
    for (int i = 0; i < tope_animales_completo; i++){
        delete vector_animales_completo[i];
    } //Con esta salvedad, no hay leaks pero BOCHA de warnings.
}

void Refugio::modificar_estado_animales(){
    int tope_animales = Animales.obtener_cantidad_elementos();
    cout<<tope_animales<<endl;
    Animal* vector_animales[tope_animales];
    Animales.copiar_info_disponible(vector_animales);

    for (int i = 0; i < tope_animales; i++){
        vector_animales[i]->incrementar_hambre();
        vector_animales[i]->incrementar_suciedad();
        if (vector_animales[i]->animal_descuidado()){
            Animales.eliminar(Animales.obtener_raiz(), vector_animales[i]->obtener_nombre());
            cantidad_animales_descuidados++;
        }
    }
}

int Refugio::obtener_cantidad_animales(){
    return (Animales.obtener_cantidad_elementos());
}

void Refugio::obtenener_animales_a_cuidar(Animal** &vector_animales){
    int tope_animales = Animales.obtener_cantidad_elementos();
    vector_animales = new Animal*[tope_animales];

    Animales.copiar_info_disponible(vector_animales);
}

Refugio::~Refugio(){
    delete lector;
}