#ifndef _ROEDOR_H_
#define _ROEDOR_H_

#include "Animal.hpp"

class Roedor: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Roedor con todas sus caracteristicas. 
     */
	Roedor(string nombre, int edad, int tamano, string personalidad);

    virtual string obtener_especie();
    virtual string obtener_comida();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
};

#endif