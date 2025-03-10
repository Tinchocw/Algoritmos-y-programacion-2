#include "Erizo.hpp"
#include <iostream>

using namespace std;

Erizo::Erizo(string nombre, int edad, int tamano, string personalidad){
    alimentar();
    limpiar();
    definir_personalidad(personalidad);
    definir_edad(edad);
    definir_tamano(tamano);
    nombrar_animal(nombre);
}

string Erizo::obtener_especie(){
    return (S_ERIZO);
}

string Erizo::obtener_comida(){
    return(INSECTOS);
}

void Erizo::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = convertir_int_a_string();
	especie = ERIZO;
	personalidad = this->personalidad;
}