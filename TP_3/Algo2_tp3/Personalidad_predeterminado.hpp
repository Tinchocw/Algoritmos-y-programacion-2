#ifndef _PERSONALIDAD_PREDETERMINADO_H_
#define _PERSONALIDAD_PREDETERMINADO_H_

#include "Personalidad.hpp"

class Personalidad_predeterminado : public Personalidad{
public:
    Personalidad_predeterminado(){}
    virtual string obtener_personalidad();
    virtual int personalidad_hambre();
    virtual int personalidad_higiene();
    ~Personalidad_predeterminado(){};
};

#endif