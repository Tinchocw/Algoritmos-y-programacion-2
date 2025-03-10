#ifndef MENU_HPP
#define MENU_HPP

#include "Refugio.hpp"
#include "Consola.hpp"
#include "Cuidador.hpp"
#include "mapa.hpp"
#include "grafo.hpp"
#include "vehiculo.hpp"
#include "caracteristicas_aleatorias.hpp"
#include "constantes.hpp"

class Consola;

class Menu{
private:
    Consola* consola;
    Vehiculo* vehiculo;
    Mapa* mapa;
    Grafo* grafo;
    Refugio* refugio;

    /*
     * PRE: -
     * POST: Pide un comando valido al usuario y lo devuelve.
     */
    int pedir_comando();

    /*
     * PRE: -
     * POST: Pide por pantalla que se ingrese el nombre de un animal o una S/s en caso de que quiera salir. Si ingresa
     * un nombre, valida que no haya un nombre igual. EN caso de que haya, le avisa que el nombre ya se encuentra en la lista.
     */
    void elegir_animal(string &nombre);

    /*
     * PRE: -
     * POST: Crea clase Cuidador. Muestra los animales disponibles del vector animales. Pregunta si desea bañar o alimentar
     * individualmente o saltear. Realiza la accion elegida.
     */
    void cuidar_animales();

    /*
     * PRE: -
     * POST: Pide el nombre del animal y lo busca en refugio. En caso de no encontrarlo muestra por pantalla que el animal
     * no se encuentra y en caso contrario lo muestra por pantalla.
     */
    void buscar_animal();

    /*
     * PRE: -
     * POST: Pide el tamaño disponible, muestra lo animales que cumplen con ese espacio y pregunta a cual quiere (o no) adoptar.
     * En caso de que no quiera hacerlo muestra por pantalla que la adopcion fue cancelada; sino lo adopta.
     */
    void adoptar_animal();

    /*
     * PRE: -
     * POST: Ejecuta la accion del menu en base a la opcion ingresada por el usuario. Modifica el estado de los animales al 
     * concretar cada accion y aumenta el combustible.
     */
    void ejecutar_comandos(bool &fin_de_ordenes, int comando);

    /*
     * PRE: -
     * POST: Si el combustible actual es menor a MAX_COMBUSTIBLE, pide al usuario que ingrese mas cantidad. EN caso de que no
     * sobrepase el limite, lo agrega. Caso contrario muestra por pantalla que esta al tope.
     */
    void aumentar_combustible();

    /*
     * PRE: -
     * POST: Carga al mapa con 5 animales aleatorios. En caso de rescatarlos, se eliminan del mapa y se agregan al refugio.
     * Por cada animal por rescatar se chequea que el combustible sea suficiente para recorrer el camino minimo desde el auto
     * hasta la posicion del animal. En caso contrario avisa que no se puede rescatar.
     */
    void rescatar_animal();

public:

    /*
     * PRE: -
     * POST: Muestra el menu y pide opcion valida al usuario para luego ejecutarla.
     */
    void siguiente_accion(bool &fin_de_ordenes);

    /*
     * PRE: -
     * POST: Carga el mapa, lo traduce a grafo y calcula los caminos minimos.
     */
    void inicializar_estructura();

    /*
     * PRE: -
     * POST: Si el nombre ingresado ya se encuentra registrado en refugio, lo denega.
     */
    void validar_nombre(string& nombre);

    Menu();
    ~Menu();
};


#endif