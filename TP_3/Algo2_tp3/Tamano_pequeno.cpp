#include  "Tamano_pequeno.hpp"


string Tamano_pequeno::obtener_tamano(){
    return("pequeño");
}


int Tamano_pequeno::obtener_metros_minimos(){
    return (2);
}


bool Tamano_pequeno::entra_animal(int metros_disponibles){
    return (metros_disponibles >= 2);
}