#ifndef __VEHICULO_H__
#define __VEHICULO_H__

#include "constantes.hpp"

class Vehiculo{
private:

	int cantidad_combustible;
	struct coordenadas posicion;

public:

	Vehiculo();

	/*
	 * PRE: 
	 * POST: 
	 */
	bool puede_aumentar_combustible(string cantidad_a_agregar);

	/*
	 * PRE: -
	 * POST: Aumenta el combustible en base a la cantidad recibida.
	 */
	void aumentar_combustible(string cantidad_a_agregar);

	/*
	 * PRE: -
	 * POST: Disminuye el combustible en base a la cantidad recibida.
	 */
	void disminuir_combustible(int cantidad_perdida);

	/*
	 * PRE: -
	 * POST: Devuelve la cantidad de combustible.
	 */
	int obtener_cantidad_combustible();
	
	/*
	 * PRE: -
	 * POST: Devuelve TRUE en caso de que la cantidad de combustible menos la cantidad necesaria
	 * sea mayor o igual a 0, FALSE en caso contrario
	 */
	bool puede_llegar(int combustible_necesario);

	/*
	 * PRE: -
	 * POST: Devuelve la posicion del vehiculo.
	 */
	struct coordenadas obtener_posicion();

	/*
	 * PRE: fila y columna mayor o iguales a 0 y menor o iguales a MAX_FILAS y MAX_COLUMNAS.
	 * POST: Cambia la posicion del vehiculo con respecto a la coordenada recibida.
	 */
	void cambiar_posicion(int fila,int columna);

	/*
	 * PRE: -
	 * POST: Posiciona al vehiculo en su coordenada inicial.
	 */
	void reiniciar_posicion();


	~Vehiculo();

};

#endif