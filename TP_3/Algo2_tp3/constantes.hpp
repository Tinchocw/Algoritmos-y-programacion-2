#ifndef __CONSTANTES_H_
#define __CONSTANTES_H_

#include <iostream>
using namespace std;

//MENU......................................

enum Opciones_menu{
    OPCION_LISTAR_ANIMALES = 1,
    OPCION_RESCATAR_ANIMAL,
    OPCION_BUSCAR_ANIMAL,
    OPCION_CUIDAR_ANIMALES,
    OPCION_ADOPTAR_ANIMAL,
    OPCION_CARGAR_COMBUSTIBLE,
    OPCION_GUARDAR_SALIR
};

enum Opciones_cuidados{
    ELEGIR_INDIVIDUALMENTE = 1,
    REGRESAR_INICIO
};

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 7;
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

const int MAX_PREGUNTA_INDIVIDUAL = 4;

const string SALIR_MINUSCULA = "s";
const string SALIR_MAYUSCULA = "S";
const string VOLVER_MENU_RESCATE = "2";

const string AUMENTO_COMBUSTIBLE = "5";

//CONSOLA...................................

enum Opciones_pregunta_individual{
    BANAR_INDIVIDUAL = 1,
    ALIMENTAR_INDIVIDUAL,
    SALTEAR,
    FINALIZAR_CUIDADOS
};

//REFUGIO...................................

const string ARCHIVO = "animales.csv";

const int LIM_DIMINUTO = 2;
const int LIM_PEQUENO = 9;
const int LIM_MEDIANO = 10;
const int LIM_GRANDE = 20;
const int LIM_GIGANTE = 50;

const int TOPE_ANIMALES_ESCAPARON = 3;

//ANIMAL....................................

const char CONEJO = 'O';
const char CABALLO = 'C';
const char ERIZO = 'E';
const char GATO = 'G';
const char PERRO = 'P';
const char ROEDOR = 'R';
const char LAGARTIJA = 'L';

const string S_GATO = "Gato";
const string S_ROEDOR = "Roedor";
const string S_LAGARTIJA = "Lagartija";
const string S_CABALLO = "Caballo";
const string S_CONEJO = "Conejo";
const string S_ERIZO = "Erizo";
const string S_PERRO = "Perro";

const string INSECTOS = "Insectos";
const string MANZANAS = "Manzanas";
const string LECHUGA = "Lechuga";
const string ATUN = "Atún";
const string HUESOS = "Huesos";
const string QUESO = "Queso";

const int MAX_HIGIENE = 100;
const int MIN_HIGIENE = 0;
const int MIN_HAMBRE = 0;
const int MAX_HAMBRE = 100;

//CARACTERISTICAS_ALEATORIAS Y MAPA.........

const int CANTIDAD_TAMANIOS = 5;
const int CANTIDAD_ESPECIES = 7;
const int CANTIDAD_PERSONALIDADES = 4;
const int EDAD_LIMITE = 25;
struct coordenadas{
	int fila;
	int columna;
};

//MAPA.......................................

#define MAX_FILAS 8
#define MAX_COLUMNAS 8

string const MONTANIA = "MONTANIA";
string const PRECIPICIO = "PRECIPICIO";
string const CAMINO = "CAMINO";
string const TIERRA = "TIERRA";
string const AUTO = "A";

int const MONTANIA_VALOR = 5;
int const PRECIPICIO_VALOR = 40;
int const CAMINO_VALOR = 1;
int const TIERRA_VALOR = 2;

const string TILDE = "\u2705";

struct animal_mapa{
	struct coordenadas coordenada;
	bool rescatado;
};

//CAMINO_MINIMO.....................

const int INFINITO = 99999;
const int POSICION_NO_ENCONTRADA = -1;

//LECTOR_CSV........................

const char DELIMITADOR = ',';

//VEHICULO..........................

const int FILA_INICIO = 0;
const int COLUMNA_INICIO = 0;
const int MAX_COMBUSTIBLE = 100;
const int MIN_COMBUSTIBLE = 0;

#endif