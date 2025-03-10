#include "Lagartija.hpp"
#include <iostream>

using namespace std;

Lagartija::Lagartija(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida){
    alimentar();
    higiene = 100;
    this->nombre = nombre;
    this->edad = edad;
    personalidad_del_animal = personalidad_definida;
    tamano = tamano_definido;
}

string Lagartija::obtener_especie(){
    return (S_LAGARTIJA);
}


void Lagartija::limpiar(){
    cout<<"Las lagartijas no necesitan bañarse! Pst pst"<<endl;
}


void Lagartija::incrementar_suciedad(){
    //No pongo nada así justamente no incrementa ni disminuye nunca.
}

string Lagartija::obtener_comida(){
    return(INSECTOS);
}

void Lagartija::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = this->tamano->obtener_tamano();
	especie = LAGARTIJA;
	personalidad = personalidad_del_animal->obtener_personalidad();
}


Lagartija::~Lagartija(){
    delete personalidad_del_animal;
    delete tamano;
}