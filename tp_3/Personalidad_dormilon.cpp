#include <iostream>
#include "Personalidad_dormilon.hpp"

using namespace std;


string Personalidad_dormilon::obtener_personalidad(){
    return ("dormilon");
}


int Personalidad_dormilon::personalidad_hambre(){
    return (SUMA_HAMBRE * 0.5);
}


int Personalidad_dormilon::personalidad_higiene(){
    return (SUMA_SUCIEDAD * 1);
}

