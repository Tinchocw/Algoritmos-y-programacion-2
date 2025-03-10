#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>

using namespace std;

const string DORMILON = "dormilon";
const string JUGUETON = "jugueton";
const string SOCIABLE = "sociable";
const string TRAVIESO = "travieso";
const string S_PEQUENO = "pequeño";
const string S_DIMINUTO = "diminuto";
const string S_MEDIANO = "mediano";
const string S_GRANDE = "grande";
const string S_GIGANTE = "gigante";

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

const int MENOR_TAMANO = 1;
const int DIMINUTO = 2;
const int PEQUENO = 9;
const int MEDIANO = 10;
const int GRANDE = 20;
const int GIGANTE = 50;

const int MAX_HIGIENE = 100;
const int MAX_HAMBRE = 100;
const int MIN_HIGIENE = 0;
const int MIN_HAMBRE = 0;
const int SUMA_HAMBRE_DORMILON = 5;
const int SUMA_HAMBRE_JUGUETON = 20;
const int SUMA_HAMBRE = 10;
const int SUMA_SUCIEDAD_SOCIABLE = 5;
const int SUMA_SUCIEDAD_TRAVIESO = 20;
const int SUMA_SUCIEDAD = 10;

class Animal{
protected:
    string nombre;
    int edad;
    string personalidad;
    int tamano;
    int hambre;
    int higiene;
protected:

    /*
     * PRE: 
     * POST: Asigna al atributo nombre el nombre recibido por parametro.
     */
    void nombrar_animal(string nombre);

    /*
     * PRE: 
     * POST: Asigna al atributo personalidad la personalidad recibida por parametro.
     */
    void definir_personalidad(string personalidad);

    /*
     * PRE: 
     * POST: Asigna al atributo edad la edad recibida por parametro.
     */
    void definir_edad(int edad);

    /*
     * PRE: 
     * POST: Asigna al atributo tamano el tamaño recibido por parametro.
     */
    void definir_tamano(int tamano);

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
    virtual void incrementar_hambre();

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
     * PRE: tamaño_deseado debe ser mayor o igual al tamaño.
     * POST: Devuelve TRUE en caso de que el tamaño este dentro del rango deseado, FALSE en caso contrario.
     */
    bool tiene_tamano_deseado(int tamano_deseado);

    /*
     * PRE: 
     * POST: Convierte el tamaño expresado en enteros a un string.
     */
    string convertir_int_a_string();

    /*
    * PRE:
    * POST:
    */
    virtual ~Animal();
};

#endif