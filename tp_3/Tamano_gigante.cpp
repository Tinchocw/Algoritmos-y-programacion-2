#include  "Tamano_gigante.hpp"


string Tamano_gigante::obtener_tamano(){
    return("gigante");
}


int Tamano_gigante::obtener_metros_minimos(){
    return (50);
}


bool Tamano_gigante::entra_animal(int metros_disponibles){
    return (metros_disponibles >= 50);
}