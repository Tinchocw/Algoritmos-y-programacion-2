#include "Conejo.hpp"
#include <iostream>

using namespace std;

Conejo::Conejo(string nombre, int edad, int tamano, string personalidad){
    alimentar();
    limpiar();
    definir_personalidad(personalidad);
    definir_edad(edad);
    definir_tamano(tamano);
    nombrar_animal(nombre);
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
	tamano = convertir_int_a_string();
	especie = CONEJO;
	personalidad = this->personalidad;
}