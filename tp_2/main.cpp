#include "Refugio.hpp"
#include "menus.hpp"
#include <iostream>

int main(){
    
    Refugio* refugio = new Refugio();
    bool fin_de_ordenes = false;

    refugio->abrir_refugio();

    while(!fin_de_ordenes){
        siguiente_accion(refugio, fin_de_ordenes);
    }

    delete refugio;
    return 0;
}
