#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
#include <string>

using namespace std;

const int MENOR_VALIDO = 0;
const int MAYOR_VALIDO = 9;
const int MAYOR_PUNTAJE = 100;
const int MENOR_PUNTAJE = 0;
const int ERROR = -1;
const int TOPE_INICIAL = 20;
const int MAX_LIBROS = 10;
const int MAX_GENEROS = 5;
const int MAX_PEORES_LIBROS = 3;
const string ARCHIVO = "libros.csv";
const int SALIR = 8;

const string AVENTURA = "A";
const string CIENCIA_FICCION = "C";
const string DIDACTICA = "D";
const string POLICIACA = "P";
const string ROMANCE = "R";
const string TERROR = "T";


struct Libro{
    string titulo;
    string genero;
    int puntaje;
};

struct Biblioteca{
    Libro** libros;
    int cantidad_libros;
};

struct Libro_2{
    string genero;
    int apariciones;
    int puntaje_total;
};

struct Libro_3{
    string genero;
    int promedio;
};


/*
Pre: - 
Post: Muestra por pantalla el menu de opciones.
*/
void mostrar_menu();
/*
Pre: El valor ingresado debe ser un número entero
Post: Le solicita al usuario que ingrese el número de la opción que desea seleccionar.
*/
int pedir_opcion();
/*
Pre: Recibe la opción elegida precargada.
Post: Verifica que numero se encuentre en un rango valido,(entre 0 y 10 inclusives).
*/
void chequear_opcion_seleccionada(int& numero);
/*
Pre: La opcion es valida.
Post: Realiza la opcion indicada.
*/
void procesar_opcion(int& opcion, Biblioteca* biblioteca,int tope_inicial);

/*
Pre: El archivo es valido.
Post: Carga los libros del archivo en un vector dínamico.
*/
void cargar_biblioteca(Biblioteca* biblioteca,int& tope_inicial);


/*
Pre: El vector es valido.
Post: Muestra por pantalla todos los libros pertenecientes a la biblioteca.
*/
void listar_libros(Biblioteca* biblioteca);
/*
Pre: El titulo y el genero debe ser una concatención de caracteres y el puntaje debe ser un entero.
Post: Agrega un nuevo libro al vector solicitado por el usuario.
*/
void agregar_nuevo_libro(Biblioteca* biblioteca,int& tope_inicial);
/*
Pre: El puntaje del valor ingresado debe ser un entero, y el titulo debe ser una concatenación de caracteres.
Post: Segun el libro seleccionado se le modifica el puntaje por el ususario.
*/
void editar_puntaje_segun_titulo(Biblioteca* biblioteca);
/*
Pre: Tiene que ser una biblioteca valida.
Post:Muestra por pantalla e libro con mayor puntaje, en el caso de empate muestra todos los que comparten ese puntaje.
*/
void mostrar_libro_favorito(Biblioteca* biblioteca);
/*
Pre:  Tiene que ser una biblioteca valida.
Post: Muestra por pantalla los tres libros con menor puntaje, si hay un empate aquellos que tengan el mismo puntaje se ordenan
      nuevamente por orden alfabético.
*/
void mostrar_peores_libros(Biblioteca* biblioteca);
/*
Pre:  Tiene que ser una biblioteca valida.
Post: Se muestra por pantalla el género que aparezca más veces, si hay un empate se muestran todos aquellos que tengan mayor cantidad
      de apariciones.
*/
void mostrar_genero_mas_leido(Biblioteca* biblioteca);
/*
Pre:  Tiene que ser una biblioteca valida.
Post: Muestra por pantalla el genero con el mayor promedio, en caso de empate muestra todos los que comparten el promedio más alto.
*/
void mostrar_generos_favoritos(Biblioteca* biblioteca);
/*
Pre: Recibe una estructura biblioteca valida.
Post: Escribe la información de la biblioteca en un archivo nuevo.
*/
void reescribir_archivo(Biblioteca* biblioteca);


/*
Pre: -
Post: Elimina la biblioteca.
*/
void eliminar_biblioteca(Biblioteca* biblioteca);



#endif