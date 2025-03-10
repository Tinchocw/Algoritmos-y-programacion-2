#include <iostream>
#include "Personalidad_travieso.hpp"

using namespace std;


string Personalidad_travieso::obtener_personalidad(){
    return ("travieso");
}


int Personalidad_travieso::personalidad_higiene(){
    return (SUMA_HAMBRE * 2);
}


int Personalidad_travieso::personalidad_hambre(){
    return (SUMA_SUCIEDAD * 1);
}