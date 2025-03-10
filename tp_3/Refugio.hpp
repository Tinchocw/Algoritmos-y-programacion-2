#ifndef _REFUGIO_HPP_
#define _REFUGIO_HPP_

#include "Animal.hpp"
#include "arbolB.hpp"
#include "Lector_csv.hpp"
#include "constantes.hpp"

class Lector_csv;
class Cuidador;


class Refugio{
private:
    
    arbolB<string, Animal*, Nodo<string, Animal*>> Animales;
    Lector_csv* lector;

    int cantidad_animales_descuidados;
    
    /*
     * PRE: -
     * POST: Crea vector animales con su informacion.
     */
    void obtenener_animales_a_cuidar(Animal** &vector_animales);

    /*
     * PRE: La lista no tiene que estar vacia.
     * POST: Elimina de la lista al animal con el nombre ingresado por el usuario.
     */
    void eliminar_animal(string nombre);

    /*
     * PRE: -
     * POST: Devuelve cantidad total de animales que se encuentran en el arbol.
     */
    int obtener_cantidad_animales();

    /*
     * PRE: -
     * POST: Maximiza al 100% la higiene del animal que se encuentra en la posicion recibida por parametro. En caso de que
     * el animal no requiera ducha, imprime por pantalla que ese animal no necesita baño.
     */
    void banar_individualmente(Animal* animal);

    /*
     * PRE: Recibe un animal que esta en el arbol y no esta eliminado
     * POST: Minimiza al 0% el hambre del animal que se encuentra en la posicion recibida por parametro. Imprime por pantalla
     * su nombre y alimento.
     */
    void alimentar_individualmente(Animal* animal);



public:

    /*
     * PRE: -
     * POST: Crea objeto Refugio con cantidad de animales igual a 0.
     */
    Refugio();


    /*
     * PRE: La lista tiene al menos un animal.
     * POST: Imprime por pantalla todos los animales de la lista enumerados junto con su nombre, especie, edad, tamaño y personalidad.
     */
    void listar_animales();

    /*
     * PRE: -
     * POST: Lista la informacion del animal por pantalla.
     */
    void mostrar_animal_disponible(Animal* animal);

    /*
     * PRE: -
     * POST: Devuelve por pantalla el puntero a animal que tiene el nombre buscado en caso de que el nombre del animal se encuentre
     * en el arbol. Caso contrario devuelve un nullptr.
     */
    Animal* buscar_animal(string nombre_buscado); 

    /*
     * PRE: -
     * POST: Guarda un puntero animal en la lista.
     */
    void agregar_animal(char especie, string nombre, int edad, Tamano* tamano_animal, Personalidad* personalidad_animal);
    
    /*
     * PRE: -
     * POST: Si nombre_elegido se encuentra en el arbol y el tamaño corresponde a metros_disponibles entonces se elimina al animal
     * que cumple con dichas caracteristicas del arbol.
     */
    void tramite_adopcion(string nombre_elegido, int metros_disponibles);

    /*
     * PRE: -
     * POST: Muestra los animales que tienen el tamaño correspondiente a metros_disponibles.
     */
    void mostrar_animales_habilitados(int metros_disponibles);

    /*
     * PRE: 
     * POST: Devuelve TRUE si la cantidad de animales que se escaparon es mayor o igual a 3. En caso contrario devuelve FALSE.
     */
    bool refugio_en_regla();

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
     * PRE: 
     * POST: Modifica el status de los animales incrementando su hambre y suciedad. En caso de que el hambre o limpieza del animal
     * lleguen a 100 y 0 respectivamente se lo elimina del arbol.
     */
    void modificar_estado_animales();

    /*
     * PRE: -
     * POST: -
     */
    ~Refugio();


friend class Cuidador;
};

#endif