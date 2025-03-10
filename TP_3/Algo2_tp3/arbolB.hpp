#ifndef ARBOLB_HPP
#define ARBOLB_HPP

#include "nodo.hpp"
#include <string>

template <typename Dato, typename Info, class Nodo>

class arbolB{
private:
    Nodo* raiz;
    int orden_m;

    int elementos_totales;
    int elementos_eliminados;

    void partir_hijo(Nodo* padre, Nodo* hijo, int indice){
        //hijo corresponde a un hijo completo del nodo padre
        //La mitad derecha del hijo se copiará sobre el nuevo nodo
        //El valor medio del hijo se copiará sobre el padre
        //hijo quedará a a izquierda del valor medio que subió al padre
        //Y nuevo_nodo será el hijo derecho al valor medio
        //De esta forma hijo realizó un split en dos nodos distintos

        Nodo* nuevo_nodo = new Nodo(orden_m); //Se instancia el nuevo nodo que quedará del lado derecho
        nuevo_nodo->es_hoja = hijo->es_hoja;

        if(!(hijo->es_hoja)){
            //Se copian los hijos de la parte derecha a nuevo_nodo
            for (int j = 0; j < (orden_m/2); j++){
                if(hijo->hijos[j+((orden_m+1)/2)] != nullptr){
                    nuevo_nodo->hijos[j] = hijo->hijos[j+((orden_m+1)/2)];
                    (nuevo_nodo->cantidad_de_hijos)++;
                    hijo->hijos[j+((orden_m+1)/2)] = nullptr;
                    (hijo->cantidad_de_hijos)--;
                }
            }
        }

        //Copia la mitad derecha de la info de hijo a nuevo_nodo
        for(int j = 0; j < ((orden_m/2)-1); j++){
            nuevo_nodo->llaves[j] = hijo->llaves[j+((orden_m+1)/2)];
            nuevo_nodo->informacion[j] = hijo->informacion[j+((orden_m+1)/2)];
            nuevo_nodo->eliminado[j] = hijo->eliminado[j+((orden_m+1)/2)];
            (nuevo_nodo->cantidad_de_llaves)++;
            hijo->llaves[j+((orden_m+1)/2)] = '.';
            //hijo->eliminado[j+((orden_m+1)/2)] = true;
            //hijo->informacion[j+((orden_m+1)/2)] = nullptr;
            //aca llenaría el vector de info/eliminado con 0, pero hace falta?
            (hijo->cantidad_de_llaves)--;
        }

        //Se mueven los hijos para hacer espacio
        for(int j = ((padre->cantidad_de_hijos)-1); j > (indice-1); j--){
            padre->hijos[j+1] = padre->hijos[j];
        }
        padre->hijos[indice] = nuevo_nodo;
        (padre->cantidad_de_hijos)++;

        //Se mueve la info para hacer espacio
        for(int j = ((padre->cantidad_de_llaves)-1); j >= (indice-1); j--){
            padre->llaves[j+1] = padre->llaves[j];
            padre->informacion[j+1] = padre->informacion[j];
            padre->eliminado[j+1] = padre->eliminado[j];
        }

        //Se copia el valor medio sobre padre
        padre->llaves[indice-1] = hijo->llaves[(orden_m-1)/2];
        padre->informacion[indice-1] = hijo->informacion[(orden_m-1)/2];
        padre->eliminado[indice-1] = hijo->eliminado[(orden_m-1)/2];
        hijo->llaves[(orden_m-1)/2] = '.';
        //hijo->eliminado[(orden_m-1)/2] = true;
        //hijo->informacion[(orden_m-1)/2] = nullptr;
        //Aca llenaría el vector/bool de info con 0, hace falta?
        (hijo->cantidad_de_llaves)--;
        (padre->cantidad_de_llaves)++;

    } //END arbolB método de spliteo de hijos



    void insertar_no_lleno(Nodo* nodo_actual, Dato dato, Info info){
        bool repetido_post_division = false;
        int i = (nodo_actual->cantidad_de_llaves)-1;

        if(nodo_actual->es_hoja){ //Si la llave no es repetida y esta posicionado sobre una hoja
            //mueve las llaves y hace espacio para la nueva
            while((i >= 0) && (dato < (nodo_actual->llaves[i]))){
                nodo_actual->llaves[i +1] = nodo_actual->llaves[i];
                nodo_actual->informacion[i +1] = nodo_actual->informacion[i];
                nodo_actual->eliminado[i +1] = nodo_actual->eliminado[i];
                i--;
            }
            //Inserta la llave junto con su info, define como no eliminada a la llave y adiciona uno al contador del nodo
            nodo_actual->llaves[i+1] = dato;
            nodo_actual->informacion[i+1] = info;
            nodo_actual->eliminado[i+1] = false;
            (nodo_actual->cantidad_de_llaves)++;
            elementos_totales++;
        }else{
            //Si no es hoja, busca el hijo correspondiente al que moverse
            i = ((nodo_actual->cantidad_de_hijos)-1);
            while((i > 0) && (dato < (nodo_actual->llaves[i-1]))){
                i--;
            }

            //Parte al hijo si este está lleno
            if((nodo_actual->hijos[i]->cantidad_de_llaves) == (orden_m-1) && nodo_actual->hijos[i]->es_hoja){ //parte cuando hay hijos con lugar
                partir_hijo(nodo_actual, nodo_actual->hijos[i], (i+1));
                if(dato > (nodo_actual->llaves[i])){
                    i++;
                }
                else if (dato == nodo_actual->llaves[i]){ //Checkea si al partir no subió el dato que se iba a insertar, para evitar repetir
                    repetido_post_division = true;
                }
            }
            if(!repetido_post_division){
                //Llamado recursivo
                insertar_no_lleno((nodo_actual->hijos[i]), dato, info);
            }
        }
    }
     //END arbolB método de inserción sobre nodos no llenos



    void limpiar_nodo(Nodo*& nodo_actual){
            for(int i = 0; i < nodo_actual->cantidad_de_hijos; i++){
            limpiar_nodo(nodo_actual->hijos[i]); //llamado recursivo para eliminar primero a los hijos
        }
        //se libera la raíz actual una vez no tenga más hijos por liberar
        //lógica de abajo hacia arriba
        delete nodo_actual;
        nodo_actual = nullptr;
    
    } //END arbolB método que se encarga de limpiar la memoria asociada a los nodos


public:
    arbolB(int m){
        orden_m = m;
        raiz = new Nodo(m);
        elementos_totales = 0;
    
    } //END constructor para el arbolB

    Nodo* obtener_raiz(){
            return (raiz); 
    } //END getter de la raíz del árbol

    void insertar(Dato dato, Info info){
        if((raiz->cantidad_de_llaves) == (orden_m-1)){
            //Se lleno la raíz
            Nodo* raiz_aux = raiz;
            raiz = new Nodo(orden_m);
            raiz->es_hoja = false;
            raiz->cantidad_de_hijos = 1;
            raiz->hijos[0] = raiz_aux;
            partir_hijo(raiz, raiz_aux, 1);
            insertar_no_lleno(raiz, dato, info);
        }
        else{
            insertar_no_lleno(raiz, dato, info);
        }
    } //END arbolB método de inserción
    
    
    Info busqueda(Nodo* nodo_actual, Dato dato_buscado){
        if(!nodo_actual){
            return nullptr;
        }
        //Busca el index correcto (en el que debería estar según lógica) dentro del nodo actual
        int i = 0;
        while((i < (nodo_actual->cantidad_de_llaves)) && (dato_buscado > (nodo_actual->llaves[i]))){
            i++;
        }
        //Si efectivamente se encontraba en el nodo actual, ejecuta al revisar si este no fue eliminado
        if((i < (nodo_actual->cantidad_de_llaves)) && (dato_buscado == (nodo_actual->llaves[i])) && (!nodo_actual->eliminado[i])){
            //cout<<nodo_actual->informacion[i]<<endl;
            return nodo_actual->informacion[i]; //Dsp cambiar a que devuelva la data si se necesita
        }
        else if((nodo_actual->es_hoja) || nodo_actual->hijos[i] == nullptr){
            //La llave buscada no está en el árbol
            return nullptr;
        }else{
            //Llamado recursivo para bajar sobre los hijos
            return busqueda(nodo_actual->hijos[i], dato_buscado);
        }  
    } //END arbolB método de búsqueda en el diccionario


    void copiar_info_disponible(Info vector[], int index = 0){
        if (raiz != nullptr){
            raiz->copiar_nodo_disponible(vector, index);
        }
    }


    void copiar_info_completa(Info vector[], int index = 0){
        if (raiz != nullptr){
            raiz->copiar_info_completa(vector, index);
        }
    }


    void eliminar(Nodo* nodo_actual, Dato dato_buscado){
        if(!nodo_actual){
        cout<<"No encontrado!"<<endl;//Después sacar, solo para debug.
        //El nodo_actual es nullptr
        }else{
            //Busca el índice de remoción en el nodo actual
            int i = 0;
            while((i < nodo_actual->cantidad_de_llaves) && dato_buscado > (nodo_actual->llaves[i])){
                i++;
            }

            //Si la llave a eliminar lógicamente está en el nodo actual
            if((i < nodo_actual->cantidad_de_llaves) && (dato_buscado == nodo_actual->llaves[i])){
                nodo_actual->eliminado[i] = true; //Eliminación lógica
                elementos_eliminados++;
            }

            //Si no estoy en una hoja y hay hijos sobre los cuales seguir buscando
            else{
                eliminar(nodo_actual->hijos[i], dato_buscado); //Llamada recursiva al próximo hijo
            }
        }
    } //END arbolB procedimiento de eliminación lógica del diccionario

    
    bool eliminar_y_recuperar(Nodo* nodo_actual, Dato dato_buscado, Info copia_eliminado){
        bool copiado = false;
        if(!nodo_actual){
            cout<<"No encontrado!"<<endl;//Después sacar el print, solo para debug.
            //El nodo_actual es nullptr
        }
        else{
            //Busca el índice de remoción en el nodo actual
            int i = 0;
            while((i < nodo_actual->cantidad_de_llaves) && dato_buscado > (nodo_actual->llaves[i])){
                i++;
            }

            //Si la llave a eliminar lógicamente está en el nodo actual
            if((i < nodo_actual->cantidad_de_llaves) && (dato_buscado == nodo_actual->llaves[i])){
                nodo_actual->eliminado[i] = true; //Eliminación lógica
                copiado = true;
                elementos_eliminados++;
            }

            //Si no estoy en una hoja y hay hijos sobre los cuales seguir buscando
            else{
                eliminar(nodo_actual->hijos[i], dato_buscado); //Llamada recursiva al próximo hijo
            }
        }
        return copiado;
    } //END arbolB procedimiento de "popeo" del diccionario

    void recorrer(){
        if (raiz != nullptr){
            raiz->recorrer();
        }
    } //END arbolB procedimiento de llamada a la recorrida del árbol
    

    int obtener_cantidad_elementos(){
        return (elementos_totales - elementos_eliminados);
    }// END getter de los elementos disponibles dentro del diccionario


    int obtener_cantidad_totales(){
        return (elementos_totales);
    }// END getter de los elementos totales dentro del diccionario

    ~arbolB(){
        limpiar_nodo(raiz);
        raiz = nullptr;
    
    } //END destructor del arbolB

}; //END declaración de la clase árbolB

#endif




/*
insertar(key, info, &key a pasar que puede o no subir, &info que puede o no subir, &nodo){
    (!no_es_hoja) -> bajo{
        busco el indice correcto
        entro al hijo correspondiente
        (ahora tengo los 3 casos para haber vuelto al padre después de la recursión):
            -No subió un median key, porque había espacio en la hoja (nodo que subió -> null) return!

            -Suió algo y había lugar en el padre -> los meto tanto a la median key como al nodo que vino como hijo derecho (referencio a nullptr el nodo luego de insertarlo)

            -Subi y se llenó el padre -> otro split (llamo a la secuencia pasandole los parámetros actualizados nodo_nuevo -> nodo que genero para arriba)
    }

    else -> llegue a la hoja{
        busco_donde_insertar
        inserto (independientemente de que se haya llenado)
        if(se lleno la hoja){
            parto la hoja y voy a crear una hoja (nuevo nodo es hoja)
            al nuevo nodo le paso la derecha a la median key
            a los valores por parámetro del llamado recursivo les asigno:
                la key --> la median key
                la info asociada a la median key
                el nodo generado que lo voy a tener que declarar como hijo del padre a la derecha del median key
        }
    }
}

//caso donde spliteo la raíz -> reasigno la raíz a otro nodo

*/