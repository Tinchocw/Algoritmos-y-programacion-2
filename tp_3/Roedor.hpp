#ifndef _ROEDOR_H_
#define _ROEDOR_H_

#include "Animal.hpp"

class Roedor: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Roedor con todas sus caracteristicas. 
     */
	Roedor(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida);
    virtual string obtener_especie();
    virtual string obtener_comida();
    virtual void incrementar_suciedad();
    virtual void limpiar();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
    ~Roedor();
};

#endif