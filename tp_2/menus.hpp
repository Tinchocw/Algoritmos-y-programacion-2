#ifndef MENU_HPP
#define MENU_HPP

#include "Refugio.hpp"

enum Opciones_menu{
    OPCION_LISTAR_ANIMALES = 1,
    OPCION_RESCATAR_ANIMAL,
    OPCION_BUSCAR_ANIMAL,
    OPCION_CUIDAR_ANIMALES,
    OPCION_ADOPTAR_ANIMAL,
    OPCION_GUARDAR_SALIR
};

enum Opciones_submenu{
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_TODOS,
    BANAR_TODOS,
    REGRESAR_INICIO
};

enum Opciones_pregunta_individual{
    BANAR_INDIVIDUAL = 1,
    ALIMENTAR_INDIVIDUAL,
    SALTEAR
};

const int OPCION_MINIMA = 0;
const int OPCION_MAXIMA = 6;
const int REINGRESAR_ANIMAL = 1;
const int VOLVER_MENU = 2;
const int EDAD_MINIMA = 0;
const int EDAD_MAXIMA = 100;
const int NUM_DIMINUTO = 2;
const int NUM_PEQUENO = 9;
const int NUM_MEDIANO = 10;
const int NUM_GRANDE = 20;
const int NUM_GIGANTE = 50;
const int MIN_SUBMENU = 1;
const int MAX_SUBMENU = 4;
const int MIN_PREGUNTA_INDIVIDUAL = 1;
const int MAX_PREGUNTA_INDIVIDUAL = 3;

const string SALIR_MINUSCULA = "s";
const string SALIR_MAYUSCULA = "S";

/*
 * PRE: 
 * POST: Muestra el menu y pide opcion valida al usuario para luego ejecutarla.
 */
void siguiente_accion(Refugio* refugio, bool &fin_de_ordenes);


#endif


