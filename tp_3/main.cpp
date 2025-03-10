#include <iostream>
#include "mapa.hpp"
#include "grafo.hpp"
#include "Refugio.hpp"
#include "Animal.hpp"
#include "vehiculo.hpp"
#include "Menu.hpp"
#include "constantes.hpp"
#include "cola.hpp"
#include "arbolB.hpp"

using namespace std;

int main(){
    srand((unsigned)time(NULL));

    bool fin_de_ordenes = false;

    Menu* menu = new Menu();
    menu->inicializar_estructura();
    
    while(!fin_de_ordenes){
        menu->siguiente_accion(fin_de_ordenes);
    }

    delete menu;
    return 0;
}
