#include <iostream>
#include "Personalidad_sociable.hpp"

using namespace std;


string Personalidad_sociable::obtener_personalidad(){
    return ("sociable");
}


int Personalidad_sociable::personalidad_higiene(){
    return (SUMA_HAMBRE * 0.5);
}


int Personalidad_sociable::personalidad_hambre(){
    return (SUMA_SUCIEDAD * 1);
}