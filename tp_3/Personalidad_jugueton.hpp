#ifndef _PERSONALIDAD_JUGUETON_H
#define _PERSONALIDAD_JUGUETON_H

#include "Personalidad.hpp"

class Personalidad_jugueton : public Personalidad{
public:
    Personalidad_jugueton(){}
    virtual string obtener_personalidad();
    virtual int personalidad_hambre();
    virtual int personalidad_higiene();
    ~Personalidad_jugueton(){}
};

#endif