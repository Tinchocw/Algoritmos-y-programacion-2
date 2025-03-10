#include "Animal.hpp"
#include <iostream>

void Animal::definir_personalidad(string personalidad){
	this->personalidad = personalidad;
}

void Animal::nombrar_animal(string nombre){
	this->nombre = nombre;
}

void Animal::definir_edad(int edad){
	this->edad = edad;
}

void Animal::definir_tamano(int tamano){
	this->tamano = tamano;
}

void Animal::limpiar(){
	higiene = MAX_HIGIENE;
}

void Animal::alimentar(){
	hambre = MIN_HAMBRE;
}

void Animal::incrementar_hambre(){
	if (hambre < MAX_HAMBRE){
		if (personalidad == DORMILON){
			hambre += SUMA_HAMBRE_DORMILON;
		}
		else if (personalidad == JUGUETON){
			hambre += SUMA_HAMBRE_JUGUETON;
		}
		else{
			hambre += SUMA_HAMBRE;
		}
	}
}

void Animal::incrementar_suciedad(){
	if (higiene > MIN_HIGIENE){
		if (personalidad == SOCIABLE){
			higiene -= SUMA_SUCIEDAD_SOCIABLE;
		}
		else if (personalidad == TRAVIESO){
			higiene -= SUMA_SUCIEDAD_TRAVIESO;
		}
		else{
			higiene -= SUMA_SUCIEDAD;
		}
	}
}

string Animal::obtener_nombre(){
	return(nombre);
}

bool Animal::tiene_tamano_deseado(int tamano_deseado){
	return(tamano_deseado >= tamano);
}

string Animal::convertir_int_a_string(){
	string tamano_s = " ";
    if(tamano == DIMINUTO){
        tamano_s = S_DIMINUTO;
    }
    else if(tamano == PEQUENO){
        tamano_s = S_PEQUENO;
    }
    else if(tamano == MEDIANO){
        tamano_s = S_MEDIANO;
    }
    else if(tamano == GRANDE){
        tamano_s = S_GRANDE;
    }
    else if(tamano == GIGANTE){
        tamano_s = S_GIGANTE;
    }
    return tamano_s;
}

void Animal::listar_informacion(){
	string especie = obtener_especie();
	cout << " > Nombre: " << nombre << endl;
	cout << " > Especie: " << especie << endl;
	cout << " > Edad: " << edad << endl;
	cout << " > Tamaño: " << convertir_int_a_string() << endl;
	cout << " > Personalidad: " << personalidad << endl;
	cout << " > Hambre: " << hambre << "%" << endl;
	cout << " > Higiene: " << higiene << "%" << endl;
}

Animal::~Animal(){

}