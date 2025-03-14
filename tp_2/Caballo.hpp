#ifndef _CABALLO_H_
#define _CABALLO_H_

#include "Animal.hpp"

class Caballo: public Animal{
public:

	/*
     * PRE: -
     * POST: Crea objeto Caballo con todas sus caracteristicas. 
     */
	Caballo(string nombre, int edad, int tamano, string personalidad);
	
	virtual string obtener_especie();
	virtual string obtener_comida();
	virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
};

#endif