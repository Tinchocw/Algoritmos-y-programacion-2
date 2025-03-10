#ifndef _ERIZO_H_
#define _ERIZO_H_

#include "Animal.hpp"

class Erizo: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Erizo con todas sus caracteristicas.
     */
    Erizo(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definida);

    virtual string obtener_especie();
    virtual string obtener_comida();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
    ~Erizo();
};


#endif