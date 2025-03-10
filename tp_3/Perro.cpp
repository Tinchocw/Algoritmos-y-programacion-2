#include "Perro.hpp"
#include <iostream>

using namespace std;

Perro::Perro(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida){
    alimentar();
    limpiar();
    this->nombre = nombre;
    this->edad = edad;
    personalidad_del_animal = personalidad_definida;
    tamano = tamano_definido;
}

string Perro::obtener_especie(){
    return(S_PERRO);
}

string Perro::obtener_comida(){
    return(HUESOS);
}

void Perro::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = this->tamano->obtener_tamano();
	especie = PERRO;
	personalidad = personalidad_del_animal->obtener_personalidad();
}


Perro::~Perro(){
    delete personalidad_del_animal;
    delete tamano;
}