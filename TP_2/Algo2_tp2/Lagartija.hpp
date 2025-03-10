#ifndef _LAGARTIJA_H_
#define _LAGARTIJA_H_

#include "Animal.hpp"

class Lagartija: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Lagartija con todas sus caracteristicas. 
     */
	Lagartija(string nombre, int edad, int tamano, string personalidad);

    virtual string obtener_especie();
    virtual string obtener_comida();
    virtual void incrementar_suciedad();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
};

#endif