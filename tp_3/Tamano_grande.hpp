#ifndef _TAMANO_GRANDE_H_
#define _TAMANO_GRANDE_H_

#include "Tamano.hpp"
#include <iostream>

using namespace std;


class Tamano_grande : public Tamano{
public:
    Tamano_grande(){};
    virtual int obtener_metros_minimos();
    virtual string obtener_tamano();
    virtual bool entra_animal(int metros_disponibles);
    ~Tamano_grande(){};
};

#endif