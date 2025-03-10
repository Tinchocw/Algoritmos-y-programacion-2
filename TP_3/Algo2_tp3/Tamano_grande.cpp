#include  "Tamano_grande.hpp"


string Tamano_grande::obtener_tamano(){
    return("grande");
}


int Tamano_grande::obtener_metros_minimos(){
    return (20);
}



bool Tamano_grande::entra_animal(int metros_disponibles){
    return (metros_disponibles >= 20);
}