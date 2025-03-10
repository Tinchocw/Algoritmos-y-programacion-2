#ifndef _TAMANO_GIGANTE_H_
#define _TAMANO_GIGANTE_H_

#include "Tamano.hpp"
#include <iostream>

using namespace std;


class Tamano_gigante : public Tamano{
public:
    Tamano_gigante(){};
    virtual int obtener_metros_minimos();
    virtual string obtener_tamano();
    virtual bool entra_animal(int metros_disponibles);
    ~Tamano_gigante(){};
};

#endif