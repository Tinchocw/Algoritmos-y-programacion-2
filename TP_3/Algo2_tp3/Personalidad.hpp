#ifndef _PERSONALIDAD_H_
#define _PERSONALIDAD_H_

#include <iostream>

using namespace std;

static const string DORMILON = "dormilon";
static const string JUGUETON = "jugueton";
static const string SOCIABLE = "sociable";
static const string TRAVIESO = "travieso";

const int SUMA_HAMBRE = 10;
const int SUMA_SUCIEDAD = 10;

class Personalidad{

public:

    Personalidad(){};

    /*
     * PRE: -
     * POST: Devuelve la personalidad del animal.
     */
    virtual string obtener_personalidad() = 0;

    /*
     * PRE:
     * POST: Modifica la higiene del animal dependiendo de su personalidad.
     */
    virtual int personalidad_higiene() = 0;

    /*
     * PRE:
     * POST: Modifica el hambre del animal dependiendo de su personalidad.
     */
    virtual int personalidad_hambre() = 0;

    /*
     * PRE:
     * POST:
     */
    virtual ~Personalidad(){};
};

#endif