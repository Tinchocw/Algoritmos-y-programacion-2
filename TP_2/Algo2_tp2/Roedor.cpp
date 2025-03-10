#include <iostream>
#include "Roedor.hpp"

using namespace std;

Roedor::Roedor(string nombre, int edad, int tamano, string personalidad){
	alimentar();
	limpiar();
	definir_personalidad(personalidad);
	definir_edad(edad);
	definir_tamano(tamano);
	nombrar_animal(nombre);
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
	tamano = convertir_int_a_string(); 
	especie = ROEDOR;
	personalidad = this->personalidad;
}