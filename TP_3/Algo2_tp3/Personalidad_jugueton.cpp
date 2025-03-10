#include <iostream>
#include "Personalidad_jugueton.hpp"

using namespace std;


string Personalidad_jugueton::obtener_personalidad(){
    return ("jugueton");
}


int Personalidad_jugueton::personalidad_hambre(){
    return (SUMA_HAMBRE * 2);
}


int Personalidad_jugueton::personalidad_higiene(){
    return (SUMA_SUCIEDAD * 1);
}
