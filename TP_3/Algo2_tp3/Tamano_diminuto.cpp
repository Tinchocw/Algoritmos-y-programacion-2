#include  "Tamano_diminuto.hpp"


string Tamano_diminuto::obtener_tamano(){
    return("diminuto");
}


int Tamano_diminuto::obtener_metros_minimos(){
    return (1);
}


bool Tamano_diminuto::entra_animal(int metros_disponibles){
    return (metros_disponibles >= 1);
}