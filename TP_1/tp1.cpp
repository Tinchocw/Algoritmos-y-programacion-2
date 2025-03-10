#include "funciones.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    Libro** libros = new Libro*[TOPE_INICIAL];
    Biblioteca* biblioteca = new Biblioteca;
    biblioteca -> libros = libros;
    int tope_inicial = 0;
    int opcion = 0;
    cargar_biblioteca(biblioteca,tope_inicial);
    

    mostrar_menu();
    opcion = pedir_opcion();
    chequear_opcion_seleccionada(opcion);

    while(opcion != SALIR){
        procesar_opcion(opcion,biblioteca,tope_inicial);

        mostrar_menu();
        opcion = pedir_opcion();
        chequear_opcion_seleccionada(opcion);
        system("clear");
    }
    reescribir_archivo(biblioteca);
    eliminar_biblioteca(biblioteca);

    return 0;
}