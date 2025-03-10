#include "Animal.hpp"


using namespace std;

void Animal::limpiar(){
	higiene = MAX_HIGIENE;
}

void Animal::alimentar(){
	hambre = MIN_HAMBRE;
}

void Animal::incrementar_hambre(){
	if (hambre < MAX_HAMBRE){
		hambre += personalidad_del_animal->personalidad_hambre();
	}
}

void Animal::incrementar_suciedad(){
	if (higiene > MIN_HIGIENE){
		higiene -= personalidad_del_animal->personalidad_higiene();
	}
}

string Animal::obtener_nombre(){
	return(nombre);
}

void Animal::listar_informacion(){
	string especie = obtener_especie();
	cout << " > Nombre: " << nombre << endl;
	cout << " > Especie: " << especie << endl;
	cout << " > Edad: " << edad << endl;
	cout << " > Tamaño: " << tamano->obtener_tamano() << endl;
	cout << " > Personalidad: " << personalidad_del_animal->obtener_personalidad()<< endl;
	cout << " > Hambre: " << hambre << "%" << endl;
	cout << " > Higiene: " << higiene << "%" << endl;
}

bool Animal::tiene_capacidad_disponible(int metros_disponibles){
	return(tamano->entra_animal(metros_disponibles));
}

int Animal::obtener_edad(){
	return(edad);
}

bool Animal::animal_descuidado(){
	return (hambre >= MAX_HAMBRE || higiene <= MIN_HIGIENE);
}

Animal::~Animal(){
}