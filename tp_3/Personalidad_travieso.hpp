#ifndef _PERSONALIDAD_TRAVIESO_H
#define _PERSONALIDAD_TRAVIESO_H

#include "Personalidad.hpp"

class Personalidad_travieso : public Personalidad{
public:
    Personalidad_travieso(){}
    virtual string obtener_personalidad();
    virtual int personalidad_higiene();
    virtual int personalidad_hambre();
    ~Personalidad_travieso(){}
};

#endif