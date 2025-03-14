#ifndef _GATO_H_
#define _GATO_H_

#include "Animal.hpp"

class Gato: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Gato con todas sus caracteristicas.
     */
    Gato(string nombre, int edad, int tamano, string personalidad);

    virtual void incrementar_suciedad();
    virtual string obtener_comida();
    virtual string obtener_especie();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
};


#endif