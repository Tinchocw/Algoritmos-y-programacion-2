#ifndef _PERRO_H_
#define _PERRO_H_

#include "Animal.hpp"

class Perro: public Animal{
public:

    /*
     * PRE: -
     * POST: Crea objeto Perro con todas sus caracteristicas. 
     */
    Perro(string nombre, int edad, Tamano* tamano_definido, Personalidad* personalidad_definidapersonalidad);

    virtual string obtener_especie();
    virtual string obtener_comida();
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad);
    ~Perro();
};


#endif