#include <iostream>
#include "Caballo.hpp"

using namespace std;

Caballo::Caballo(string nombre, int edad, int tamano, string personalidad){
	alimentar();
	limpiar();
	definir_personalidad(personalidad);
	definir_edad(edad);
	definir_tamano(tamano);
	nombrar_animal(nombre);
}

string Caballo::obtener_especie(){
    return (S_CABALLO);
}

string Caballo::obtener_comida(){
	return(MANZANAS);
}

void Caballo::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = convertir_int_a_string();
	especie = CABALLO;
	personalidad = this->personalidad;
}