#include "Gato.hpp"
#include <iostream>

using namespace std;

Gato::Gato(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida){
    alimentar();
    higiene = 100;
    this->nombre = nombre;
    this->edad = edad;
    personalidad_del_animal = personalidad_definida;
    tamano = tamano_definido;
}

void Gato::incrementar_suciedad(){
    //No pongo nada así justamente no incrementa ni disminuye nunca.
}


void Gato::limpiar(){
    cout<<"Los gatos no necesitan limpiarse! Miaw"<<endl;
}
    

string Gato::obtener_especie(){
    return (S_GATO);
}

string Gato::obtener_comida(){
    return(ATUN);
}

void Gato::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = this->tamano->obtener_tamano();
    especie = GATO;
	personalidad = personalidad_del_animal->obtener_personalidad();
}


Gato::~Gato(){
    delete personalidad_del_animal;
    delete tamano;
}