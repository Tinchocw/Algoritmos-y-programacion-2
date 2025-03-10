#include "Perro.hpp"
#include <iostream>

using namespace std;

Perro::Perro(string nombre, int edad, int tamano, string personalidad){
    alimentar();
    limpiar();
    definir_personalidad(personalidad);
    definir_edad(edad);
    definir_tamano(tamano);
    nombrar_animal(nombre);
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
	tamano = convertir_int_a_string();
	especie = PERRO;
	personalidad = this->personalidad;
}