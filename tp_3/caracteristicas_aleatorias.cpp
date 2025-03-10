#include "caracteristicas_aleatorias.hpp"
#include "Tamano_diminuto.hpp"
#include "Tamano_pequeno.hpp"
#include "Tamano_mediano.hpp"
#include "Tamano_grande.hpp"
#include "Tamano_gigante.hpp"
#include "Personalidad_dormilon.hpp"
#include "Personalidad_jugueton.hpp"
#include "Personalidad_sociable.hpp"
#include "Personalidad_travieso.hpp"

Caracteristicas_aleatorias::Caracteristicas_aleatorias(){
        cargar_caracteristicas();
}

void Caracteristicas_aleatorias::cargar_caracteristicas(){
        cantidad_especies = 7;
        especies = new string [cantidad_especies];
        especies[0] = "P";
	especies[1] = "G";
	especies[2] = "L";
	especies[3] = "C";
	especies[4] = "O";
	especies[5] = "R";
	especies[6] = "E";
        cantidad_personalidades = 4;
        cantidad_tamanios = 5; 
        cantidad_coordenadas = 5;
        coordenadas = new struct coordenadas [cantidad_coordenadas];
} 

int Caracteristicas_aleatorias::posicion_aleatoria(int limite){
        int  posicion = rand() % limite;
        return(posicion);
}

Tamano* Caracteristicas_aleatorias::tamanio_aleatorio(){
        Tamano* tamanio_aux = nullptr;
        int numero_aleatorio = posicion_aleatoria(cantidad_tamanios);
        if(numero_aleatorio == 0){
                tamanio_aux = new Tamano_diminuto(); 
        }else if(numero_aleatorio == 1){
                tamanio_aux = new Tamano_pequeno();
        }else if(numero_aleatorio == 2){
                tamanio_aux = new Tamano_mediano();
        }else if(numero_aleatorio == 3){
                tamanio_aux = new Tamano_gigante();
        }else{
                tamanio_aux = new Tamano_diminuto();
        }
        return (tamanio_aux);
}

Personalidad* Caracteristicas_aleatorias::personalidad_aleatoria(){
        Personalidad* personalidad_aux = nullptr;
        int numero_aleatorio = posicion_aleatoria(cantidad_tamanios);
        if(numero_aleatorio == 0){
                personalidad_aux = new Personalidad_dormilon(); 
        }else if(numero_aleatorio == 1){
                personalidad_aux = new Personalidad_jugueton();
        }else if(numero_aleatorio == 2){
                personalidad_aux = new Personalidad_sociable();
        }else{
                personalidad_aux = new Personalidad_travieso();
        }
        return (personalidad_aux);

}

int Caracteristicas_aleatorias::edad_aleatoria(int edad_limite){
        return(posicion_aleatoria(edad_limite));
}

string Caracteristicas_aleatorias::especie_aleatoria(){
        return(especies[posicion_aleatoria(cantidad_especies)]);
}

struct coordenadas Caracteristicas_aleatorias::coordenada_aleatoria(int limite_filas,int limite_columnas){
        struct coordenadas aux;
        aux.fila = rand() % limite_filas;
        aux.columna = rand() % limite_columnas;
        return(aux);
}


struct coordenadas* Caracteristicas_aleatorias::vector_coordenadas(int limite_filas,int limite_columnas){
        int i = 0;
        struct coordenadas coordenada_aux;

        while(i < cantidad_coordenadas){
                coordenada_aux = coordenada_aleatoria(limite_filas,limite_columnas);
                if(!esta_repetido(i,coordenada_aux) && (coordenada_aux.fila != 0 && coordenada_aux.columna != 0)){
                        coordenadas[i] = coordenada_aux;
                        i++;
                }
        }
        return coordenadas;
}

bool Caracteristicas_aleatorias::esta_repetido(int tope,struct coordenadas coordenada){
        bool esta = false;
        int i = 0;
        while(i < tope && !esta){
                if((coordenadas[i].fila == coordenada.fila) && (coordenadas[i].columna == coordenada.columna)){
                        esta = true;   
                }
                i++;  
        }
        return(esta);
}


Caracteristicas_aleatorias::~Caracteristicas_aleatorias(){
        delete [] especies;
        delete [] coordenadas;
}

