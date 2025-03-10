#ifndef _TAMANO_MEDIANO_H_
#define _TAMANO_MEDIANO_H_

#include "Tamano.hpp"
#include <iostream>

using namespace std;


class Tamano_mediano : public Tamano{
public:
    Tamano_mediano(){};
    virtual int obtener_metros_minimos();
    virtual string obtener_tamano();
    virtual bool entra_animal(int metros_disponibles);
    ~Tamano_mediano(){};
};

#endif