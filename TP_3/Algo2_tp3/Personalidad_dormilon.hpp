#ifndef _PERSONALIDAD_DORMILON_H_
#define _PERSONALIDAD_DORMILON_H_

#include "Personalidad.hpp"

class Personalidad_dormilon : public Personalidad{
public:
    Personalidad_dormilon(){}
    virtual string obtener_personalidad(); 
    virtual int personalidad_hambre();
    virtual int personalidad_higiene();
    ~Personalidad_dormilon(){}
};

#endif