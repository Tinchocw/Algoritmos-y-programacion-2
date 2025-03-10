#ifndef _LECTOR_CSV_H_
#define _LECTOR_CSV_H_

#include <iostream>
#include "Animal.hpp"
#include "Refugio.hpp"
#include "constantes.hpp"

using namespace std;

class Refugio; 

class Lector_csv{
private:

    string nombre_archivo;

    /*
     * PRE: -
     * POST: Declara el personalidad del animal dependiendo de la personalidad recibida por parametro.
     */
    void definir_personalidad(string personalidad, Personalidad* &personalidad_del_animal);

    /*
     * PRE:
     * POST: Declara el tamaño del animal dependiendo del tamaño recibido por parametro.
     */
    void definir_tamano(string tamano_s, Tamano* &tamano);

public:

    Lector_csv(string archivo);

    /*
     * PRE: -
     * POST: Lee el archivo y carga los animales con su respectiva informacion del archivo en refugio. 
     * En caso de que no haya archivo, se crea uno nuevo.
     */
    void cargar_animales(Refugio* refugio);

    /*
     * PRE: -
     * POST: Guarda los animales con su respectiva informacion en el archivo.
     */
    void guardar_animales(Animal* vector_copiado[], int tope_animales);

    ~Lector_csv();
}; 

#endif