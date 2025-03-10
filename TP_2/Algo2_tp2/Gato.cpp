#include "Gato.hpp"
#include <iostream>

using namespace std;

Gato::Gato(string nombre, int edad, int tamano, string personalidad){
    alimentar();
    limpiar();
    definir_personalidad(personalidad);
    definir_edad(edad);
    definir_tamano(tamano);
    nombrar_animal(nombre);
}


void Gato::incrementar_suciedad(){
    //No pongo nada así justamente no incrementa ni disminuye nunca.
    //Si quieren cambienlo por un = 100 pero es indiferente.
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
	tamano = convertir_int_a_string();
	especie = GATO;
	personalidad = this->personalidad;
}