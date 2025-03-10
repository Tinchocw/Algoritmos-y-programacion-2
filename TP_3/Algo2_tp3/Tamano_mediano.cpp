#include  "Tamano_mediano.hpp"


string Tamano_mediano::obtener_tamano(){
    return("mediano");
}


int Tamano_mediano::obtener_metros_minimos(){
    return (10);
}



bool Tamano_mediano::entra_animal(int metros_disponibles){
    return (metros_disponibles >= 10);
}