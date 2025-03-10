#ifndef CONSOLA_HPP_
#define CONSOLA_HPP_

#include <iostream>
#include "Menu.hpp"
#include "mapa.hpp"
#include "grafo.hpp"
#include "vehiculo.hpp"
#include "constantes.hpp"

class Menu;
class Cuidador;

class Consola{
private:

    /*
     * PRE: -
     * POST: Muestra por pantalla las opciones validas del menu para el usuario.
     */
    void imprimir_opciones();

    /*
     * PRE: La opcion debe ser mayor o igual a 1 y menor o igual a 6.
     * POST: Devuelve TRUE en caso de que la opcion este dentro del rango, FALSE en caso contrario.
     */
    bool comando_invalido(int comando);

    /*
     * PRE: -
     * POST: Le pide al usuario un ingreso valido de alguna de las opciones del menu.
     */
    void pedir_comando(string &opcion);

    /*
     * PRE: -
     * POST: Le pide al usuario un ingreso de su disponibilidad de metros cuadrados.
     */
    void pedir_metros_disponibles(int& metros_disponibles);

    /*
     * PRE: -
     * POST: Pide al usuario el nombre del animal por rescatar.
     */
    void pedir_nombre_animal(string& nombre);

    /*
     * PRE: -
     * POST: Imprime las opciones validas del submenu de la funcion de cuidar para el usuario. 
     */
    void imprimir_submenu_cuidados();

    /*
     * PRE: -
     * POST: Imprime las opciones validas del submenu de la funcion de adoptar para el usuario. 
     */
    void imprimir_submenu_adoptar();

    /*
     * PRE: -
     * POST: Le pide al usuario un ingreso valido de alguna de las opciones del submenu de la funcion de adoptar.
     */
    void preguntar_comando_adoptar(string &comando);

    /*
     * PRE: -
     * POST: Le pide al usuario un ingreso valido de alguna de las opciones del submenu de la funcion de cuidar.
     */
    void preguntar_comando_cuidados(string &comando);

     /*
      * PRE: La opcion debe ser mayor o igual a 1 y menor o igual a 3.
      * POST: Devuelve TRUE en caso de que la opcion este dentro del rango, FALSE en caso contrario.
      */
    bool es_opcion_individual_valida(int opcion);

    /*
     * PRE: -
     * POST: Le pide al usuario el ingreso de dos numeros enteros.
     */
    void pedir_posicion(int& fila, int& columna);

    /*
     * PRE: fila y columna mayor o igual a cero y menor o igual a MAX_FILAS y MAX_COLUMNAS.
     * POST: Devuelve true si fila y columna respetan el rango maximo y minimo del mapa. En caso contrario devuelve false.
     */
    bool es_posicion_valida(int fila, int columna);

    /*
     * PRE: -
     * POST: Pide posicion valida hasta recibir una que este dentro del rango pedido. La guarda.
     */
    void validar_posicion(int& fila,int& columna);

    /*
     * PRE: mapa con sus animales cargados.
     * POST: Pide posicion del animal, en caso de que no haya un animal en esa posicion, la
     * vuelve a pedir.
     */
    void confirmar_posicion_animal(Mapa* mapa,int& fila,int& columna);

    /*
     * PRE: -
     * POST: Muestra por pantalla el camino minimo desde el vehiculo hasta el animal y luego
     * pide el nombre del animal.
     */
    void mostrar_mensaje_rescatado(string& nombre, int fila, int columna, Vehiculo* vehiculo,cola<struct coordenadas, nodoCola<struct coordenadas>>* cola_coordenadas);

    /*
     * PRE: -
     * POST: Imprime por pantalla que el animal no puede ser rescatado.
     */
    void desistir_rescate();

    /*
     * PRE: -
     * POST: Imprime las opciones validas del submenu de la funcion de rescate para el usuario. 
     */
    void imprimir_submenu_rescatar();

    /*
     * PRE: -
     * POST: Le pide al usuario un ingreso valido de alguna de las opciones del submenu de la funcion de rescatar.
     */
    void pedir_comando_rescatado(string& comando);

    /*
     * PRE: opcion tiene que ser igual a 1 o 2.
     * POST: Chequea que la variable ingresada cumpla con las opciones ofrecidas del submenu de rescate.
     */
    bool es_opcion_rescatar_valida(int opcion);

    /*
     * PRE: vector coordenadas no vacio.
     * POST: Muestra por pantalla el camino minimo mediante sus coordenadas del mapa.
     */
    void imprimir_camino_minimo(struct coordenadas* camino_minimo, int tope);

    /*
     * PRE: -
     * POST: Muestra por pantalla que ese animal ya fue rescatado.
     */
    void mostrar_mensaje_denegado();

    /*
     * PRE: -
     * POST: Muestra por pantalla que ese nombre no es valido y pide y guarda otro.
     */
    void denegar_nombre(string& nombre);

    /*
     * PRE: combustible_ingresado mayor a 0 y mayor o igual a MAX_COMBUSTIBLE.
     * POST: Devuelve TRUE en caso de que el combustible ingresado se encuentre dentro del rango,
     * FALSE en caso contrario.
     */
    bool es_combustible_valido(int combustible_ingresado);

    /*
     * PRE: -
     * POST: Pide combustible valido por pantalla, de no serlo lo vuelve a pedir y lo guarda.
     */
    void pedir_combustible(Vehiculo* vehiculo, string& cantidad_a_agregar);

    /*
     * PRE: cola_coordenadas no vacia.
     * POST: Muestra el camino minimo por pantalla en forma de coordenadas desde la posicion del 
     * vehiculo hasta la del animal rescatado.
     */
    void mostrar_camino_minimo(int fila,int columna,Vehiculo* vehiculo,cola<struct coordenadas, nodoCola<struct coordenadas>>* cola_coordenadas);

public:
    Consola();
    ~Consola();


friend class Menu;
friend class Cuidador;
};

#endif