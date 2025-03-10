#ifndef _NODO_HPP_
#define _NODO_HPP_

#include <iostream>

using namespace std;

template <typename Dato, typename Info, class Nodo> class arbolB; //Forward declaration del árbol para permitir las clases friend.
                                        //Permite total encapsulamiento del nodo haciendolo 100% privado.

template <typename Dato, typename Info>

class Nodo{
private:
    Dato* llaves;        //llaves
    Info* informacion;  //información asociada a cada llave
    bool* eliminado;   //bool que indica eliminación lógica

    Nodo** hijos;    //hijos
    
    int cantidad_de_llaves;  //# de llaves
    int cantidad_de_hijos;  //# de hijos
    bool es_hoja;          //bool que indica si el nodo es o no hoja

    Nodo(int orden_m){
        hijos = new Nodo*[orden_m]();
    
        llaves = new Dato[orden_m -1]();
        informacion = new Info[orden_m -1]();
        eliminado = new bool[orden_m -1]();

        cantidad_de_llaves = 0;
        cantidad_de_hijos = 0;
        es_hoja = true;    
    } //END constructor para la clase Nodo



    void copiar_nodo_disponible(Info vector[], int &indice){
        int i;
        for (i = 0; i < cantidad_de_llaves; i++){
            if (es_hoja == false && hijos[i] != nullptr){
                hijos[i]->copiar_nodo_disponible(vector, indice);
            }
            if (!eliminado[i]){
                vector[indice] = informacion[i];
                indice++;
            }
        }
        if(es_hoja == false && hijos[i] != nullptr){
          hijos[i]->copiar_nodo_disponible(vector, indice);
        }
    }//END Nodo procedimiento recorrido y copiado recursiva por los Nodos
    


    void copiar_info_completa(Info vector[], int &indice){
        int i;
        for (i = 0; i < cantidad_de_llaves; i++){
            if (es_hoja == false && hijos[i] != nullptr){
                hijos[i]->copiar_info_completa(vector, indice);
            }
            vector[indice] = informacion[i];
            indice++;
        }
        if(es_hoja == false && hijos[i] != nullptr){
          hijos[i]->copiar_info_completa(vector, indice);
        }
    }//END Nodo procedimiento recorrido y copiado recursiva por los Nodos


    ~Nodo(){
        delete[] llaves;
        delete[] informacion;
        delete[] eliminado;
        delete[] hijos;

        llaves = nullptr;
        informacion = nullptr;
        eliminado = nullptr;
        hijos = nullptr;

        cantidad_de_llaves = 0;
        cantidad_de_hijos = 0;

        es_hoja = true;
    } //END destructor para la clase Nodo

public:
    void recorrer_juli(int tabulacion){
        int i;
        string tabulaciones;
        for (int i = 0; i < tabulacion; i++) {
            tabulaciones += '\t';
        }

        for (i = 0; i < cantidad_de_llaves; i++) {
            if (!es_hoja)
                hijos[i]->recorrer_juli(tabulacion + 1);
            cout << tabulaciones << llaves[i] <<endl;
        }
        if (!es_hoja) {
            hijos[i]->recorrer_juli(tabulacion + 1);
        }
    }

    void recorrer(){
        int i;
        for (i = 0; i < cantidad_de_llaves; i++){
          if (es_hoja == false){
            hijos[i]->recorrer();
        }
        if (!eliminado[i]){
            cout << "- " << llaves[i] << endl;
        }
        }
        if (es_hoja == false){
          hijos[i]->recorrer();
        }
    } //END Nodo procedimiento recorrida recursiva por los Nodos

friend class arbolB<Dato, Info, Nodo<Dato, Info>>;

}; //END declaración de la clase Nodo (para árbolB)

#endif