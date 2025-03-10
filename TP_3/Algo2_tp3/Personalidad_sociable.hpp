#ifndef _PERSONALIDAD_SOCIABLE_H
#define _PERSONALIDAD_SOCIABLE_H

#include "Personalidad.hpp"

class Personalidad_sociable : public Personalidad{
public:
    Personalidad_sociable(){}
    virtual string obtener_personalidad();
    virtual int personalidad_higiene();
    virtual int personalidad_hambre();
    ~Personalidad_sociable(){}
};

#endif