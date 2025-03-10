#include "Lagartija.hpp"
#include <iostream>

using namespace std;

Lagartija::Lagartija(string nombre, int edad, int tamano, string personalidad){
    alimentar();
    limpiar();
    definir_personalidad(personalidad);
    definir_edad(edad);
    definir_tamano(tamano);
    nombrar_animal(nombre);
}

string Lagartija::obtener_especie(){
    return (S_LAGARTIJA);
}


void Lagartija::incrementar_suciedad(){
    //No pongo nada así justamente no incrementa ni disminuye nunca.
    //Si quieren cambienlo por un = 100 pero es indiferente.
}

string Lagartija::obtener_comida(){
    return(INSECTOS);
}

void Lagartija::completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad){
	nombre = this->nombre;
	edad = to_string(this->edad);
	tamano = convertir_int_a_string();
	especie = LAGARTIJA;
	personalidad = this->personalidad;
}