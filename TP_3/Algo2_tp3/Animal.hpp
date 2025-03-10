#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>

#include "constantes.hpp"

#include "Tamano_diminuto.hpp"
#include "Tamano_pequeno.hpp"
#include "Tamano_mediano.hpp"
#include "Tamano_grande.hpp"
#include "Tamano_gigante.hpp"

#include "Personalidad_dormilon.hpp"
#include "Personalidad_jugueton.hpp"
#include "Personalidad_sociable.hpp"
#include "Personalidad_travieso.hpp"
#include "Personalidad_predeterminado.hpp"

using namespace std;

class Animal{
protected:
    string nombre;
    int edad;
    Tamano* tamano;
    int hambre;
    int higiene;
    Personalidad* personalidad_del_animal;
    
public:

    /*
     * PRE: -
     * POST: Imprime por pantalla los animales junto con su nombre, especie, edad, tamaño y personalidad.
     */
    void listar_informacion();

    /*
     * PRE: 
     * POST: Devuelve el nombre de cada animal.
     */
    string obtener_nombre();

    /*
     * PRE: 
     * POST: Devuelve la edad.
     */
    int obtener_edad();

    /*
     * PRE: 
     * POST: Devuelve la especie de cada animal.
     */
    virtual string obtener_especie() = 0;

    /*
     * PRE: 
     * POST: Asigna las caracteristicas (nombre, edad, tamaño, especie y personalidad) a cada animal.
     */
    virtual void completar_informacion(string &nombre, string &edad, string &tamano, string &especie, string &personalidad) = 0;

    /*
     * PRE: 
     * POST: Devuelve la comida con la que se alimenta cada animal.
     */
    virtual string obtener_comida() = 0;

    /*
     * PRE: 
     * POST: Disminuye la higiene de cada animal dependiendo de su personalidad.
     */
    virtual void incrementar_suciedad();

    /*
     * PRE: 
     * POST: Incrementa el hambre de cada animal dependiendo de su personalidad.
     */
    void incrementar_hambre();

    /*
     * PRE: 
     * POST: Maximiza la higiene del animal al 100, en caso de que el animal necesite baño.
     */
    virtual void limpiar();

    /*
     * PRE: 
     * POST: Disminuye el hambre del animal a 0.
     */
    void alimentar();

    /*
     * PRE: 
     * POST: Devuelve TRUE si metros_disponibles es mayor al tamaño del animal. FALSE en caso contrario.
     */
    bool tiene_capacidad_disponible(int metros_disponibles);

    /*
     * PRE: 
     * POST: Devuelve TRUE si el animal se encuentra con hambre igual a 100 o higiene igual a 0. FALSE en caso contrario.
     */
    bool animal_descuidado();

    virtual ~Animal();
};

#endif