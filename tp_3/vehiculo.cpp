#include "vehiculo.hpp"

Vehiculo::Vehiculo(){
	posicion.fila = FILA_INICIO;
	posicion.columna = COLUMNA_INICIO;
	cantidad_combustible = MAX_COMBUSTIBLE;
}

bool Vehiculo::puede_aumentar_combustible(string cantidad_a_agregar){
	return((cantidad_combustible + stoi(cantidad_a_agregar)) <= MAX_COMBUSTIBLE);
}

void Vehiculo::aumentar_combustible(string cantidad_a_agregar){
	if(puede_aumentar_combustible(cantidad_a_agregar)){
		cantidad_combustible += (stoi(cantidad_a_agregar));
	}
}

void Vehiculo::disminuir_combustible(int cantidad_perdida){
	if((cantidad_combustible - cantidad_perdida) >= MIN_COMBUSTIBLE){
		cantidad_combustible -= cantidad_perdida;
	}
}

int Vehiculo::obtener_cantidad_combustible(){
	return cantidad_combustible;
}

struct coordenadas Vehiculo::obtener_posicion(){
	return posicion;
}

bool Vehiculo::puede_llegar(int combustible_necesario){
	return(cantidad_combustible - combustible_necesario >= MIN_COMBUSTIBLE);
}

void Vehiculo::cambiar_posicion(int fila, int columna){
	posicion.fila = fila;
	posicion.columna = columna;
}

void Vehiculo::reiniciar_posicion(){
	posicion.fila = FILA_INICIO;
	posicion.columna = COLUMNA_INICIO;
}

Vehiculo::~Vehiculo(){

}