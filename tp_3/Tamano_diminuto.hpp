#ifndef _TAMANO_DIMINUTO_H_
#define _TAMANO_DIMINUTO_H_

#include "Tamano.hpp"
#include <iostream>

using namespace std;


class Tamano_diminuto : public Tamano{
public:
    Tamano_diminuto(){};
    virtual int obtener_metros_minimos();
    virtual string obtener_tamano();
    virtual bool entra_animal(int metros_disponibles);
    ~Tamano_diminuto(){};
};

#endif