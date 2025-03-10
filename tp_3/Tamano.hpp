#ifndef _TAMANO_H_
#define _TAMANO_H_

#include <iostream>

using namespace std;

const string S_PEQUENO = "pequeño";
const string S_DIMINUTO = "diminuto";
const string S_MEDIANO = "mediano";
const string S_GRANDE = "grande";
const string S_GIGANTE = "gigante";


const int MENOR_TAMANO = 1;
const int DIMINUTO = 2;
const int PEQUENO = 9;
const int MEDIANO = 10;
const int GRANDE = 20;
const int GIGANTE = 50;

class Tamano{

public:

    Tamano(){};

    /*
     * PRE: -
     * POST: Devuelve los metros minimos del animal.
     */
    virtual int obtener_metros_minimos() = 0;

    /*
     * PRE: -
     * POST: Devuelve el tamaño del animal.
     */
    virtual string obtener_tamano() = 0;

    /*
     * PRE: metros_disponibles mayores o iguales al valor que necesite cada animal.
     * POST: Devuelve TRUE en caso de que los metros ingresados esten dentro del rango, FALSE en caso contrario.
     */
    virtual bool entra_animal(int metros_disponibles) = 0;

    virtual ~Tamano(){};
};


#endif