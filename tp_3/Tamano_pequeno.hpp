#ifndef _TAMANO_PEQUENO_H_
#define _TAMANO_PEQUENO_H_

#include "Tamano.hpp"
#include <iostream>

using namespace std;


class Tamano_pequeno : public Tamano{
public:
    Tamano_pequeno(){};
    virtual int obtener_metros_minimos();
    virtual string obtener_tamano();
    virtual bool entra_animal(int metros_disponibles);
    ~Tamano_pequeno(){};
};

#endif