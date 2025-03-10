#include "Caballo.hpp"
#include <iostream>

using namespace std;

Caballo::Caballo(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida){
    alimentar();
    limpiar();
    this->nombre = nombre;
    this->edad = edad;
    personalidad_del_animal = personalidad_definida;
    tamano = tamano_definido;
}

string Caballo::obtener_especie(){
    return(S_CABALLO);
}

string Caballo::obtener_comida(){
    return(HUESOS);
}

void Caballo::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = this->tamano->obtener_tamano();
	especie = CABALLO;
	personalidad = personalidad_del_animal->obtener_personalidad();
}


Caballo::~Caballo(){
    delete personalidad_del_animal;
    delete tamano;
}