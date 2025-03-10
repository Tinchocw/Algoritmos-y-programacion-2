#include <iostream>
#include "Roedor.hpp"

using namespace std;

Roedor::Roedor(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida){
	alimentar();
    higiene = 100;
    this->nombre = nombre;
    this->edad = edad;
    personalidad_del_animal = personalidad_definida;
    tamano = tamano_definido;
}


void Roedor::limpiar(){
    cout<<"Los roedores no necesitan bañarse! Squick squick"<<endl;
}


void Roedor::incrementar_suciedad(){
    //personalidad vacío
}


string Roedor::obtener_especie(){
    return (S_ROEDOR);
}

string Roedor::obtener_comida(){
	return(QUESO);
}

void Roedor::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = this->tamano->obtener_tamano(); 
	especie = ROEDOR;
	personalidad = personalidad_del_animal->obtener_personalidad();
}


Roedor::~Roedor(){
    delete personalidad_del_animal;
    delete tamano;
}