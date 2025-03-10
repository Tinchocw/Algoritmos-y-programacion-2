#ifndef _CONEJO_H_
#define _CONEJO_H_

#include "Animal.hpp"

class Conejo: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Conejo con todas sus caracteristicas.
     */
	Conejo(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida);
    
    virtual string obtener_especie();
    virtual string obtener_comida();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
    virtual ~Conejo();
};

#endif