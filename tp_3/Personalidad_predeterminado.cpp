#include <iostream>
#include "Personalidad_predeterminado.hpp"

using namespace std;


string Personalidad_predeterminado::obtener_personalidad(){
    return ("normal");
}


int Personalidad_predeterminado::personalidad_higiene(){
    return (SUMA_HAMBRE);
}


int Personalidad_predeterminado::personalidad_hambre(){
    return (SUMA_SUCIEDAD);
}