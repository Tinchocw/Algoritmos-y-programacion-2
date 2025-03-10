#include "Cuidador.hpp"

#include <iostream>

using namespace std;

Cuidador::Cuidador(Refugio* puntero_a_refugio, Consola* puntero_a_consola){
    vector_animales = nullptr;
    cantidad_de_animales = 0;
    refugio = puntero_a_refugio;
    consola = puntero_a_consola;
}


void Cuidador::cargar_animales(){
    cantidad_de_animales = refugio->obtener_cantidad_animales();
    refugio->obtenener_animales_a_cuidar(vector_animales);
}


void Cuidador::cuidar_animales(){
    cargar_animales();
    int i = 0;
    string comando = "0";

    while(i < cantidad_de_animales && stoi(comando) != FINALIZAR_CUIDADOS){
        refugio->mostrar_animal_disponible(vector_animales[i]);
        consola->preguntar_comando_cuidados(comando);
        if (stoi(comando) == BANAR_INDIVIDUAL){
                refugio->banar_individualmente(vector_animales[i]);
                
            }
            else if (stoi(comando) == ALIMENTAR_INDIVIDUAL){
                refugio->alimentar_individualmente(vector_animales[i]);
                
            }
            else if (stoi(comando) == SALTEAR){
                cout<<"Animal salteado"<<endl;
                
            }
            else{
                cout<<"Saliendo del menu de cuidados!"<<endl;
            }
        i++;
    }
}

Cuidador::~Cuidador(){
    delete [] vector_animales;
}