#include<iostream>
#include <fstream>
#include <string>
#include "funciones.h"
using namespace std;


void mostrar_menu(){
    cout<< "1. Listar libros leidos" << endl;
    cout<< "2. Agregar libro" << endl;
    cout<< "3. Editar puntaje de un libro por titulo" << endl;
    cout<< "4. Mostrar libro favorito" << endl;
    cout<< "5. Mostrar los 3 libros con menor puntaje" << endl;
    cout<< "6. Mostrar genero mas leido" << endl;
    cout<< "7. Mostrar genero favorito" << endl;
    cout<< "8. Guardar y salir" << endl;
}

/*
Pre:-
Post: Devuelve verdadero verdadero si numero es mayor a MENOR_VALIDO y es menor a MAYOR_VALIDO
*/
bool es_numero_valido(int numero){
    return(numero > MENOR_VALIDO && numero < MAYOR_VALIDO);
}

int pedir_opcion(){
    int opcion_elegida;
    cout << "Ingrese el número de su acción elegida : ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

void chequear_opcion_seleccionada(int& numero){   
    
    while(!es_numero_valido(numero)){
        cout << "Ingrese nuevamente un valor entre 1 y 8" << endl;
        cin >> numero;
    }
}

void procesar_opcion(int& opcion, Biblioteca* biblioteca,int tope_inicial){

    
    if(opcion == 1){
        listar_libros(biblioteca);
    }else if(opcion == 2){
        agregar_nuevo_libro(biblioteca,tope_inicial);
    }else if(opcion == 3){
        editar_puntaje_segun_titulo(biblioteca);
    }else if(opcion == 4){
        mostrar_libro_favorito(biblioteca);
    }else if(opcion == 5){
        mostrar_peores_libros(biblioteca);
    }else if(opcion == 6){
        mostrar_genero_mas_leido(biblioteca);
    }else if(opcion == 7){
        mostrar_generos_favoritos(biblioteca);
    }
}


/*
Pre: Recibe una estructura de biblioteca valida.
Post: Genera un nuevo vector dinamico con dimension igual al doble del ingresado y pasa toda la información del vector viejo al 
      nuevo.
*/
void redimensionar_vector(Biblioteca* biblioteca_1){
    Libro** vector_2 = new Libro*[2*(biblioteca_1 -> cantidad_libros)];

    for(int i = 0; i < biblioteca_1 -> cantidad_libros; i++){
        vector_2[i] = biblioteca_1 -> libros[i];
    }
    delete [] biblioteca_1 -> libros;
    biblioteca_1 -> libros = vector_2;
}

/*
Pre: La biblioteca tiene que tener espacio suficiente para agregar un nuevo libro.
Post: Agrega un nuevo libro a la biblioteca.
*/
void agregar_libro(Biblioteca* biblioteca,Libro* libro){
    biblioteca -> libros[biblioteca -> cantidad_libros ++]  = libro;
}

void cargar_biblioteca(Biblioteca* biblioteca,int& tope_inicial){
    biblioteca->cantidad_libros = 0;
    tope_inicial = TOPE_INICIAL;

    fstream archivo(ARCHIVO);
    if(archivo.is_open()){
        string titulo,genero,puntaje;
        while(getline(archivo,titulo,';')){
            
            getline(archivo,genero,';');
            getline(archivo,puntaje);

            Libro* libro = new Libro;
            libro -> titulo = titulo;
            libro -> genero = genero;
            libro -> puntaje = stoi(puntaje);

            if(biblioteca -> cantidad_libros > tope_inicial ){
            
                redimensionar_vector(biblioteca);
            }
            agregar_libro(biblioteca,libro);
        
        }
        archivo.close();
    }else{
        cout << "El archivo no existe " << endl;
    }
}

/*
Pre: La letra ingresada tiene que ser una que pertenezca a un genero establecido previamente.
Post: Segun la letra ingresada crea una una variable con el genero relacionado.
*/
void determinar_genero(string inicial_genero,string& genero){
    if(inicial_genero == AVENTURA){
        genero = "Aventura";
    }else if(inicial_genero == CIENCIA_FICCION){
        genero = "Ciencia ficción";
    }else if(inicial_genero == DIDACTICA){
        genero = "Dicatica";
    }else if(inicial_genero == POLICIACA){
        genero = "Policiaca";
    }else if(inicial_genero == ROMANCE){
        genero = "Romance";
    }else if(inicial_genero == TERROR){
        genero = "Terror";
    }
}


void listar_libros(Biblioteca* biblioteca){
    string genero;
    for (int i = 0; i < biblioteca -> cantidad_libros; i++){

        determinar_genero(biblioteca -> libros[i] -> genero, genero);
        cout << endl;
        cout << "--- " << "libro " << i << " ---" << endl;
        cout << "Titulo: " << biblioteca -> libros[i] -> titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Puntaje: " << biblioteca -> libros[i] -> puntaje << endl;
        cout << endl;
    }
}

/*
Pre: -
Post: Devuelve verdadero si el libro ingresado se encuetra en la biblioteca, sino devulve falso.
*/
bool esta_libro(Biblioteca* biblioteca,Libro libro){
    bool esta = false;
    for (int i = 0; i < biblioteca -> cantidad_libros; i++){
        if(biblioteca -> libros[i] -> titulo == libro.titulo){
            esta = true;
        }
    }
    return(esta);
}

/*
Pre: -
Post: Devuelve verdadero si genero es igual a AVENTURA, CIENCIA_FICCION, DIDACTICA, POLICIACA, ROMANCE o TERROR.
*/
bool esta_genero(string genero){
    return (genero == AVENTURA || genero == CIENCIA_FICCION || genero == DIDACTICA || genero == POLICIACA || genero == ROMANCE 
        || genero == TERROR);
}
/*
Pre: -
Post: Devuelve verdadero si el puntaje es mayor igual a MENOR_PUNTAJE y menor igual a MAYOR_PUNTAJE.
*/
bool es_puntaje_valido(int puntaje){
    return (puntaje <= MAYOR_PUNTAJE && puntaje >= MENOR_PUNTAJE);
}
/*
Pre: La biblioteca tiene que ser valida.
Post: Valida que el titulo del libro ingresado no se encuntre en la biblioteca, en el caso de no ser valido solicita que se ingrese 
nuevamente.
*/
void validar_titulo(Biblioteca* biblioteca,Libro& libro_nuevo){
    while(esta_libro(biblioteca,libro_nuevo) == true){
        cout << endl;
        cout << "El libro ya se encuentra en la biblioteca" << endl;
        cout << "Ingrese el titulo del libro " << endl;
        cin >> libro_nuevo.titulo;
        cout << endl;
    }
}
/*
Pre: La biblioteca tiene que ser valida.
Post: Valida que el titulo del libro ingresado este en el vector, en el caso de no ser valido solicita que se ingrese nuevamente.
*/
void validar_titulo_2(Biblioteca* biblioteca, Libro& libro_buscado){
    while(esta_libro(biblioteca,libro_buscado) == false){
        cout << endl;
        cout << "El libro no se encuntra dentro de la biblioteca " << endl;
        cout << "Ingrese el titulo del libro " << endl;
        cin >> libro_buscado.titulo;
        cout << endl;
    }
}
/*
Pre:-
Post: Valida que el genero del libro sea uno preestablecido, en el caso de no serlo lo solicita nuevamente
*/
void validar_genero(Libro& libro_nuevo){
    while(esta_genero(libro_nuevo.genero) == false){
        cout << "Genero invalido " << endl;
        cout << "ingrese nuevamente el genero (caracter_indicador)" << endl;
        cin >> libro_nuevo.genero;
        cout << endl;
    }
}
/*
Pre:-
Post: Valida que el valor del puntaje se encuentre en el rango solicitado, en el caso de no ser valido solicita nuevamente el puntaje.
*/
void validar_puntaje(Libro& libro_nuevo){
    while(es_puntaje_valido(libro_nuevo.puntaje) == false){
        cout << "Puntaje invalido" << endl;
        cout << "Ingrese nuevamente el puntaje(rango valido entreo 0 y 100) " << endl;
        cin >> libro_nuevo.puntaje;
        cout << endl;
    }
}


void agregar_nuevo_libro(Biblioteca* biblioteca, int& tope_inicial){
    
    Libro libro_aux;
    Libro* libro_nuevo = new Libro;


    cout << "Ingrese el titulo del libro " << endl; 
    getline(cin >> ws,libro_aux.titulo);
    validar_titulo(biblioteca,libro_aux);
    cout << endl;

    cout << "ingrese Genero (caracter_indicador)" << endl;
    cin >> libro_aux.genero;
    cout << endl;
    validar_genero(libro_aux);

    cout << "Ingrese Puntaje " << endl;
    cin >> libro_aux.puntaje;
    cout << endl;
    validar_puntaje(libro_aux);
    
    libro_nuevo -> titulo = libro_aux.titulo;
    libro_nuevo -> genero = libro_aux.genero;
    libro_nuevo -> puntaje = libro_aux.puntaje;


    if(biblioteca -> cantidad_libros > tope_inicial ){
            
        redimensionar_vector(biblioteca);
    }
    agregar_libro(biblioteca,libro_nuevo);
    
}
/*
Pre: Tiene que ser una biblioteca valida.
Post: Devuelve la posición del libro que tenga el mismo titulo que el ingresado, si no esta devuelve posición -1.
*/
int posicion_libro_buscado(Biblioteca* biblioteca, string titulo_ingresado){
    int posicion = ERROR;
    for(int i = 0; i < biblioteca -> cantidad_libros; i++){
        if(biblioteca -> libros[i] -> titulo == titulo_ingresado){
            posicion = i;
        }
    }
    return posicion;
}

void editar_puntaje_segun_titulo(Biblioteca* biblioteca){
    Libro libro_aux;

    cout << "Ingresar titulo del libro " << endl;
    getline(cin >> ws,libro_aux.titulo);
    validar_titulo_2(biblioteca,libro_aux);

    cout << "Ingrese el nuevo puntaje " << endl;
    cin >> libro_aux.puntaje;
    validar_puntaje(libro_aux);
    biblioteca -> libros[posicion_libro_buscado(biblioteca,libro_aux.titulo)] -> puntaje = libro_aux.puntaje;
}

/*
Pre: La biblioteca tiene que estar cargada en el campo de puntaje
Post: Ordena los libros de la biblioteca de forma descendente por titulo.
*/
void ordenar_por_puntaje(Biblioteca* biblioteca){
    Libro* aux;
    for (int i = 1; i < biblioteca -> cantidad_libros; i++){
        for(int j = 0; j < (biblioteca -> cantidad_libros - i); j++){
            if(biblioteca ->  libros[j] -> puntaje < biblioteca ->  libros[j+1] -> puntaje){
                aux = biblioteca ->  libros[j];
                biblioteca ->  libros[j] = biblioteca ->  libros[j+1];
                biblioteca ->  libros[j+1] = aux;

            }
        }
    }

}
/*
Pre:-
Post: Devuelve verdadero si la biblioteca esta ordenada ascendentemente por puntaje, sino devuelve falso.
*/
bool esta_ordenado_por_puntaje(Biblioteca* biblioteca){
    bool ordenado = true;
    int cont = 0;
    int i = 0;
    while(cont < biblioteca -> cantidad_libros){
        if(biblioteca -> libros[i] < biblioteca -> libros[i + 1]){
            ordenado = false;
            cont = biblioteca -> cantidad_libros;
        }
        i++;
        cont++;
    }
    return(ordenado);
}

void mostrar_libro_favorito(Biblioteca* biblioteca){
    if(!esta_ordenado_por_puntaje(biblioteca)){
        ordenar_por_puntaje(biblioteca);
    }
    cout << "--- Libro/s favorito/s ---" << endl;
    cout << endl;
    cout << biblioteca -> libros[0] -> titulo << endl;
    int i = 1;
    while(biblioteca -> libros[i] -> puntaje == biblioteca -> libros[0] -> puntaje){
        cout << biblioteca -> libros[i] -> titulo << endl;
        i++;
    }
    cout << endl;
    cout << "-------------------------" << endl;
}


/*
Pre:-
Post: Imprime los 3 libros con menor puntaje.
*/
void imprimir_peores_libros(Biblioteca* biblioteca){
    cout << "--- Peores libros --- " << endl;
    cout << endl;
    for(int i = biblioteca -> cantidad_libros - 1; i > biblioteca -> cantidad_libros - 4; i--){
        cout << "Libro: " << biblioteca -> libros[i] -> titulo << " Puntaje: " << biblioteca -> libros[i] -> puntaje << endl;    
    }
    cout << "-------------------------" << endl;
    
}
/*
Pre:La biblioteca tiene que ser valida.
Post: Ordenada de forma descendente los libros de la biblioteca por su titulo.
*/
void ordenar_por_titulo(Biblioteca* biblioteca){
    Libro* aux;
    for(int i = biblioteca -> cantidad_libros -1 ; i > 1; i--){
        for(int j = i - 1; j > 0; j--){
            if(biblioteca -> libros[i] -> puntaje == biblioteca -> libros[j] -> puntaje){
                if(biblioteca -> libros[i] -> titulo > biblioteca -> libros[j] -> titulo){
                    aux = biblioteca -> libros[i];
                    biblioteca -> libros[i] = biblioteca -> libros[j];
                    biblioteca -> libros[j] = aux;
                }
            }
            
        }
    } 
}


void mostrar_peores_libros(Biblioteca* biblioteca){
    if(!esta_ordenado_por_puntaje(biblioteca)){
        ordenar_por_puntaje(biblioteca);
    }
    ordenar_por_titulo(biblioteca);
    imprimir_peores_libros(biblioteca);
}


/*
Pre: EL vector libros tiene que ser valido.
Post: Te devuelve verdadero si genero_ingresado se encuentra el el vector libros, sino devuelve falso.
*/
bool esta_genero_2(Libro_2 libros[MAX_GENEROS],int tope, string genero_ingresado){
    bool esta = false;
    for(int i = 0; i < tope; i++){
        if(libros[i].genero == genero_ingresado){
            esta = true;
        }
    }
    return esta;
}
/*
Pre:El vector libros tiene que ser valido.
Post:Agrega un nuevo elemento al vector libros y aumenta las apariciones y su tope en 1.
*/
void agregar_genero(Libro_2 libros[MAX_GENEROS],int& tope,string genero_ingresado){
    libros[tope].genero = genero_ingresado;
    libros[tope].apariciones = 0;
    libros[tope].apariciones ++;
    tope ++;
}
/*
Pre:El vector libros tiene que ser valido.
Post: Te devuelve la posición de genero_buscado, en el caso de no encontrarse en el vector devuelve -1.
*/
int posicion_genero(Libro_2 libros[MAX_GENEROS],int tope,string genero_buscado){
    int posicion = ERROR;
    for(int i = 0; i < tope; i++){
        if( libros[i].genero == genero_buscado){
            posicion = i;
        }
    }
    return posicion;
}
/*
Pre: El vector libros tiene que ser valido.
Post: Segun el valor de genero_buscado aumenta el campo de aparciones en uno del vector libros.
*/
void aumentar_apariciones(Libro_2 libros[MAX_GENEROS],int tope,string genero_buscado){
    if(genero_buscado == AVENTURA){
        libros[posicion_genero(libros,tope,genero_buscado)].apariciones++; 
    }else if(genero_buscado == CIENCIA_FICCION){
        libros[posicion_genero(libros,tope,genero_buscado)].apariciones++;
    }else if(genero_buscado == DIDACTICA){
        libros[posicion_genero(libros,tope,genero_buscado)].apariciones++;
    }else if(genero_buscado == POLICIACA){
        libros[posicion_genero(libros,tope,genero_buscado)].apariciones++;
    }else if(genero_buscado == ROMANCE){
        libros[posicion_genero(libros,tope,genero_buscado)].apariciones++;
    }else if(genero_buscado == TERROR){
        libros[posicion_genero(libros,tope,genero_buscado)].apariciones++;
    }
}
/*
Pre:El vector libros tiene que ser valido.
Post: Duvuelve la posición del genero que tenga mayor cantidad de apariciones, en el caso de tener todos la misma cantidad de
apariciones devuelve del primer elemento del vector libros.
*/ 
int posicion_genero_mas_leido(Libro_2 libros[MAX_GENEROS],int tope){
    int posicion = 0;
    for(int i = 0; i < tope - 1; i++){
        for(int j = i + 1; j < tope; j++){
            if(libros[j].apariciones > libros[i].apariciones){
                posicion = j;
            }
        }
    }
    return posicion;
}

/*
Pre: El vector libros tiene que ser valido.
Post: Muestra por pantalla los generos de los libros que tengan la misma cantidad de apariciones que el genero más leido.
*/
void imprimir_apariciones_repetidas(Libro_2 libros[MAX_GENEROS],int tope){
    string genero_aux;
    for(int i = 0; i < tope; i++){
        if(libros[i].apariciones == libros[posicion_genero_mas_leido(libros,tope)].apariciones && libros[i].genero != libros[posicion_genero_mas_leido(libros,tope)].genero){
            determinar_genero(libros[i].genero,genero_aux);
            cout << genero_aux << endl;
        }
    }
}
/*
Pre: El vector libros tiene que ser valido.
Post: Muestra por pantalla el genero con mayor cantidad de apariciones y en el caso de haya otros con igual puntaje también los 
imprime.
*/
void imprimir_generos_mas_leidos(Libro_2 libros[MAX_GENEROS],int tope){
    cout << "--- Genero/s más leido --- " << endl;
    cout << endl;
    string genero_aux;
    determinar_genero(libros[posicion_genero_mas_leido(libros,tope)].genero,genero_aux);
    cout << genero_aux << endl;
    imprimir_apariciones_repetidas(libros,tope);
    cout << "-------------------------" << endl;
}
/*
Pre:-
Post:
*/
void mostrar_genero_mas_leido(Biblioteca* biblioteca){
    Libro_2 libros[MAX_GENEROS];
    int tope = 0;

    for (int i = 0; i < biblioteca -> cantidad_libros; i++){
        if(!esta_genero_2(libros,tope,biblioteca -> libros[i] -> genero)){
            agregar_genero(libros,tope,biblioteca -> libros[i] -> genero);
        }else{
            aumentar_apariciones(libros,tope,biblioteca -> libros[i] -> genero);
        }

    }
    imprimir_generos_mas_leidos(libros,tope);

}



/*
Pre:-
Post: Calcula promedio.
*/
int promedio(int puntaje,int total){
    return(puntaje / total);
}
/*
Pre: El vector libros tiene que ser valido.
Post: Se aumenta el puntaje del del genero que tenga el mismo valor que genero_buscado.
*/
void aumentar_puntaje(Biblioteca* biblioteca,Libro_2 libros[MAX_GENEROS],int tope,int puntaje_actual,string genero_buscado){

    if(genero_buscado == AVENTURA){

        libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total = 
                                                libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total + puntaje_actual;

    }else if(genero_buscado == CIENCIA_FICCION){
            libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total = 
                                                libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total + puntaje_actual;
    }else if(genero_buscado == DIDACTICA){
            libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total = 
                                                libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total + puntaje_actual;
    }else if(genero_buscado == POLICIACA){
            libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total = 
                                                libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total + puntaje_actual;
    }else if(genero_buscado == ROMANCE){
            libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total = 
                                                libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total + puntaje_actual;
    }else if(genero_buscado == TERROR){
            libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total = 
                                                libros[posicion_genero(libros,tope,genero_buscado)].puntaje_total + puntaje_actual;
    }
}
/*
Pre: El vector libros tiene que ser valido.
Post: Agrega el valor ingresado en puntaje_total al vector libros en la posición del tope en le campo de puntaje_total.
*/
void agregar_puntaje(Libro_2 libros[MAX_GENEROS],int tope,int puntaje_total){
    //libros[tope].puntaje_total = 0;
    libros[tope].puntaje_total = puntaje_total;
}
/*
Pre: El vector libros tiene que ser valido.
Post: Carga el valor del promedio de libros en libros_2 y tambien agrega su genero
*/
void calcular_promedio(Libro_2 libros[MAX_GENEROS],int tope,Libro_3 libros_2[MAX_GENEROS],int& tope_2){
    for(int i = 0; i < tope; i++){
        libros_2[tope_2].promedio = 0;
        libros_2[tope_2].promedio = promedio(libros[i].puntaje_total, libros[i].apariciones);
        libros_2[tope_2].genero = libros[i].genero;
        tope_2++;
    }
}
/*
Pre: El vector libros tiene que ser valido.
Post: Devuelve la posición con mayor promedio, en el caso de ser todos iguales devuelve el primer elemento del vector.
*/
int posicion_mayor_promedio(Libro_3 libros[MAX_GENEROS],int tope){
    int posicion = 0;
    for(int i = 0; i < tope - 1; i++){
        for(int j = i + 1; j < tope; j++){
            if(libros[j].promedio > libros[i].promedio){
                posicion = j;
            }
        }
    }
    return posicion;
}

/*
Pre: El vector libros tiene que ser valido.
Post: Muestra por pantalla todos los generos que tengan el mismo promedio que el mayor promedio.
*/
void imprimir_promedios_repetidos(Libro_3 libros[MAX_GENEROS],int tope){
    string genero_aux;
    for(int i = 0; i < tope; i++){

        if(libros[i].promedio == libros[posicion_mayor_promedio(libros,tope)].promedio && libros[i].genero != libros[posicion_mayor_promedio(libros,tope)].genero){
            determinar_genero(libros[i].genero,genero_aux);
            cout << genero_aux << endl;
        }
    }
}
/*
Pre: El vector libros tiene que ser valido
Post: Muestra por pantalla todos los generos que tengan el mayor promedio.
*/
void imprimir_mayores_promedios(Libro_3 libros[MAX_GENEROS], int tope){
    
    cout << "Genero/s con mayor promedio/s" << endl;
    cout << endl;
    string genero_aux;
    determinar_genero(libros[posicion_mayor_promedio(libros,tope)].genero,genero_aux);
    cout << genero_aux << endl;
    imprimir_promedios_repetidos(libros,tope);
    cout << "-------------------------" << endl;
}


void mostrar_generos_favoritos(Biblioteca* biblioteca){
    Libro_2 libros[MAX_GENEROS];
    Libro_3 libros_2[MAX_GENEROS];
    int tope = 0;
    int tope_2 = 0;

    for(int i = 0; i < biblioteca -> cantidad_libros; i++){
        if(!esta_genero_2(libros,tope,biblioteca -> libros[i] -> genero)){
            agregar_puntaje(libros,tope,biblioteca -> libros[i] -> puntaje);
            agregar_genero(libros,tope,biblioteca -> libros[i] -> genero);
        }else{
            aumentar_apariciones(libros,tope,biblioteca -> libros[i] -> genero);
            aumentar_puntaje(biblioteca,libros,tope,biblioteca -> libros[i] -> puntaje,biblioteca -> libros[i] -> genero);
        }
    }
    calcular_promedio(libros,tope,libros_2,tope_2);
    imprimir_mayores_promedios(libros_2,tope_2);
}

void reescribir_archivo(Biblioteca* biblioteca){
    ofstream archivo(ARCHIVO);
    for(int i = 0; i < biblioteca -> cantidad_libros; i++){
        archivo << biblioteca -> libros[i] -> titulo << ';' << biblioteca -> libros[i] -> genero << ';' 
                << biblioteca -> libros[i] -> puntaje << '\n';
    }
    archivo.close();
}

void eliminar_biblioteca(Biblioteca* biblioteca){
    for (int i = 0; i < biblioteca -> cantidad_libros; i++){
        delete  biblioteca -> libros[i];
    }
    delete [] biblioteca -> libros;
    biblioteca -> libros = nullptr;
    delete  biblioteca;
}



