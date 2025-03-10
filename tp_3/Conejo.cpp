#include "Conejo.hpp"
#include <iostream>

using namespace std;

Conejo::Conejo(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida){
    alimentar();
    limpiar();
    this->nombre = nombre;
    this->edad = edad;
    personalidad_del_animal = personalidad_definida;
    tamano = tamano_definido;
}

string Conejo::obtener_especie(){
    return (S_CONEJO);
}

string Conejo::obtener_comida(){
    return(LECHUGA);
}

void Conejo::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = this->tamano->obtener_tamano();
	especie = CONEJO;
	personalidad = personalidad_del_animal->obtener_personalidad();
}


Conejo::~Conejo(){
    delete personalidad_del_animal;
    delete tamano;
}