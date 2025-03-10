#ifndef _REFUGIO_H_
#define _REFUGIO_H_

#include "Animal.hpp"
#include "Lista_Doble.hpp"

const char DELIMITADOR = ',';
const string ARCHIVO = "animales.csv";

const int LIM_DIMINUTO = 2;
const int LIM_PEQUENO = 9;
const int LIM_MEDIANO = 10;
const int LIM_GRANDE = 20;
const int LIM_GIGANTE = 50;

class Refugio{
private:
    Lista_Doble<Animal*, Nodo<Animal*>> Animales;
    int cantidad_animales;

    /*
     * PRE: -
     * POST: Convierte el tamaño recibido en string a entero. Si el tamaño es invalido devuelve 0.
     */
    int convertir_string_a_int(string tamano_leido);

public:

    /*
     * PRE: -
     * POST: Crea objeto Refugio con cantidad de animales igual a 0.
     */
    Refugio();

    /*
     * PRE: -
     * POST: Imprime por pantalla los animales con su informacion que cumplen con el tamaño ingresado.
     */
    void mostrar_animales_habilitados(int tamano); //Tiene que ser privada ? 

    /*
     * PRE: La lista no tiene que estar vacia.
     * POST: Elimina de la lista al animal con el nombre ingresado por el usuario.
     */
    void eliminar_animal(string nombre);

    /*
     * PRE: La lista tiene al menos un animal.
     * POST: Imprime por pantalla todos los animales de la lista enumerados junto con su nombre, especie, edad, tamaño y personalidad.
     */
    void listar_animales();

    /*
     * PRE: -
     * POST: Guarda un puntero animal en la lista.
     */
    void rescatar_animal(char especie, string nombre, int edad, string tamano, string personalidad);

    /*
     * PRE: -
     * POST: Recibe al animal buscado y muestra por pantalla toda su informacion.
     */
    void mostrar_animal_buscado(string nombre);

    /*
     * PRE: -
     * POST: Imprime por pantalla la informacion del animal que se encuentra en la posicion recibida por parametro.
     */
    void mostrar_un_animal(int index);

    /*
     * PRE: -
     * POST: Maximiza al 100% la higiene del animal que se encuentra en la posicion recibida por parametro. En caso de que
     * el animal no requiera ducha, imprime por pantalla que ese animal no necesita baño.
     */
    void banar_individualmente(int index);

    /*
     * PRE: -
     * POST: Minimiza al 0% el hambre del animal que se encuentra en la posicion recibida por parametro. Imprime por pantalla
     * su nombre y alimento.
     */
    void alimentar_individualmente(int index);

    /*
     * PRE: -
     * POST: Deja el hambre de todos los animales de la lista en 0.
     */
    void alimentar_todos();

    /*
     * PRE: -
     * POST: Deja la higiene de todos los animales de la lista en 100%.
     */
    void banar_todos();

    /*
     * PRE: -
     * POST: Devuelve la cantidad de animales que hay en la lista.
     */
    int obtener_cantidad_animales();

    /*
     * PRE: -
     * POST: Busca el nombre del animal ingresado por el usuario. Devuelve TRUE en caso de que el nombre
     * sea encontrado, FALSE en caso contrario.
     */
    bool esta_animal(string nombre);

    /*
     * PRE: -
     * POST: Modifica el hambre y suciedad de los animales dependiendo de sus personalidades.
     */
    void modificar_estado_animales();
    
    /*
     * PRE: El archivo ingresado debe ser csv para su correcto funcionamiento.
     * POST: Carga la lista animales con la informacion del archivo.
     */
    void abrir_refugio();

    /*
     * PRE: -
     * POST: Guarda los animales con sus modificaciones en el archivo refugio.
     */
    void cerrar_refugio();

    /*
     * PRE: -
     * POST: -
     */
    ~Refugio();
};

#endif