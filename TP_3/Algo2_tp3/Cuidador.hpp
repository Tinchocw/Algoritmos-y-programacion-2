#ifndef CUIDADOR_HPP
#define CUIDADOR_HPP

#include "Animal.hpp"
#include "Menu.hpp"

class Consola;

class Cuidador{

private:
    
    Animal** vector_animales;
    int cantidad_de_animales;

    Refugio* refugio;
    Consola* consola;

    /*
     * PRE: -
     * POST: Carga los animales de refugio.
     */
    void cargar_animales();

public:

    Cuidador(Refugio* puntero_a_refugio, Consola* puntero_a_consola);

    /*
     * PRE: -
     * POST: Muestra los animales disponibles del vector animales. Pregunta si desea bañar o alimentar individualmente
     * o saltear. Realiza la accion elegida.
     */
    void cuidar_animales();

    ~Cuidador();

};



#endif