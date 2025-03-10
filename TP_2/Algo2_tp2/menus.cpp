#include <iostream>
#include "menus.hpp"
#include "Refugio.hpp"

using namespace std;

/*
 * PRE: -
 * POST: Muestra las opciones a seleccionar.
 */
void mostrar_menu(){
    cout << "================== MENU ==================" << endl;
    cout << " > 1. Listar animal" << endl;
    cout << " > 2. Rescatar animal" << endl;
    cout << " > 3. Buscar animal" << endl;
    cout << " > 4. Cuidar animal" << endl;
    cout << " > 5. Adoptar animal" << endl;
    cout << " > 6. Guardar y salir" << endl;
    cout << "==========================================" << endl;
}

/*
 * PRE: La opcion debe ser mayor o igual a 1 y menor o igual a 6.
 * POST: Devuelve TRUE en caso de que la opcion este dentro del rango, FALSE en caso contrario.
 */
bool comando_invalido(int comando){
    return (comando > OPCION_MAXIMA);
}

/*
 * PRE: -
 * POST: Pide la opcion valida al usuario y la guarda.
 */
int pedir_comando(){
    unsigned int comando;
    cin >> comando;
    while (comando_invalido(comando)){
        cout << "Error! El numero a ingresar es entre 1 y 6 como figura en el menu. Intenta de vuelta" << endl;
        cin >> comando;
    }
    return comando;
}

/*
 * PRE: -
 * POST: Pide al usuario el nombre del animal por rescatar.
 */
void pedir_nombre_animal(string& nombre){
    cout << endl << "Ingrese el NOMBRE del animal que desea rescatar: " << endl;
    getline(cin >> ws, nombre);
}

/*
 * PRE: -
 * POST: Valida el nombre del animal ingresado. En caso de que ese nombre ya exista, da la opcion de volver a ingresar
 * otro nombre o volver al menu principal.
 */
bool desea_reingresar_animal(){
    int opcion;
    cout << "Ese nombre ya se encuentra en el refugio!" << endl;
    cout << "Desea:" << endl << " 1. Ingresar otro nombre." << endl << " 2. Volver al menu" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while(opcion != REINGRESAR_ANIMAL && opcion != VOLVER_MENU){
        cout << "Ingrese una opcion valida (1/2): ";
        cin >> opcion;
    }
    return(opcion == REINGRESAR_ANIMAL);
}

/*
 * PRE: La opcion debe ser mayor o igual a 0 y menor o igual a 100.
 * POST: Devuelve TRUE en caso de que la opcion este dentro del rango, FALSE en caso contrario.
 */
bool es_edad_valida(int edad){
    return(edad >= EDAD_MINIMA && edad <= EDAD_MAXIMA);
}

/*
 * PRE: Las opciones son PEQUENO, DIMINUTO, MEDIANO, GRANDE o GIGANTE.
 * POST: Devuelve TRUE en caso de que el tamaño este dentro de las opciones, FALSE en caso contrario.
 */
bool es_tamano_valido(string tamano){
    return(tamano == S_PEQUENO || tamano == S_DIMINUTO || tamano == S_MEDIANO || tamano == S_GRANDE || tamano == S_GIGANTE);
}

/*
 * PRE: Las opciones son CONEJO, PERRO, GATO, CABALLO o ROEDOR, ERIZO o LAGARTIJA.
 * POST: Devuelve TRUE en caso de que la especie este dentro de las opciones, FALSE en caso contrario.
 */
bool es_especie_valida(char especie){
    return(especie == CONEJO || especie == PERRO || especie == GATO || especie == CABALLO || especie == ROEDOR 
        || especie == ERIZO || especie == LAGARTIJA);
}

/*
 * PRE: Las opciones son DORMILON, JUGUETON, SOCIABLE o TRAVIESO.
 * POST: Devuelve TRUE en caso de que la personalidad este dentro de las opciones, FALSE en caso contrario.
 */
bool es_personalidad_valida(string personalidad){
    return(personalidad == DORMILON || personalidad == JUGUETON || personalidad == SOCIABLE || personalidad == TRAVIESO);
}

/*
 * PRE: -
 * POST: Pide los datos restantes validos al usuario y los guarda.
 */
void pedir_datos_restantes(int& edad, string& tamano, char& especie, string& personalidad){
    cout << "Genial! Proceda a completar los siguientes datos del animal." << endl;
    cout << "Ingrese la EDAD. Puede ser entre 0 y 100: ";
    cin >> edad;
    while(!es_edad_valida(edad)){
        cout << "Esa edad no es correcta. El rango es entre 0 y 100. Volve a ingresar: " << endl;
        cin >> edad;
    }
    cout << "Ingrese el TAMAÑO. Las opciones son: diminuto, pequeño, mediano, grande o gigante: " << endl;
    getline( cin >> ws, tamano);
    while(!es_tamano_valido(tamano)){
        cout << "Ese tamaño no es correcto. Las opciones son: diminuto, pequeño, mediano, grande o gigante: " << endl;
        getline( cin >> ws, tamano);
    }
    cout << "Ingrese la ESPECIE, sus opciones son P(perro), G(gato), C(caballo), R(roedor), O(conejo), E(erizo) o L(lagartija): " << endl;
    cin >> especie;
    while(!es_especie_valida(especie)){
        cout << "Esa especie no es valida. Sus opciones son P(perro), G(gato), C(caballo), R(roedor), O(conejo), E(erizo) o L(lagartija):" << endl;
        cin >> especie;
    }
    cout << "Por ultimo, ingrese su PERSONALIDAD. Las opciones son: dormilon, jugueton, sociable o travieso: " << endl;
    getline( cin >> ws, personalidad);
    while(!es_personalidad_valida(personalidad)){
        cout << "La personalidad ingresada es incorrecta. Sus opciones son: dormilon, jugueton, sociable o travieso: " << endl;
        getline( cin >> ws, personalidad);
    }
}

/*
 * PRE: -
 * POST: Guarda los datos ingresados por el usuario y rescata al animal.
 */
void guardar_datos(Refugio* refugio, string nombre){
    int edad;
    string tamano, personalidad;
    char especie;
    pedir_datos_restantes(edad, tamano, especie, personalidad); 
    system("clear");
    refugio->rescatar_animal(especie, nombre, edad, tamano, personalidad);
    cout << "==========================================" << endl;
    cout << "¡Felicidades! ¡Rescataste al animal con exito!" << endl;
}

/*
 * PRE: -
 * POST: Pide el nombre del animal a cargar. Si su nombre ya existe, puede ingresar uno nuevo o volver al menu. En caso contrario
 * carga el animal nuevo.
 */    
void cargar_animal_nuevo(Refugio* refugio){
    string nombre;
    pedir_nombre_animal(nombre);
    bool volver_menu = false;
    while(refugio->esta_animal(nombre) && !volver_menu){
        if(desea_reingresar_animal()){
            pedir_nombre_animal(nombre);
        }else{
            volver_menu = true;
        }
    }
    if(!volver_menu){
        guardar_datos(refugio, nombre);
    }  
}

/*
 * PRE: -
 * POST: Pide al usuario el espacio disponible para la mascota proxima a adoptar.
 */
void preguntar_espacio_animal(int& espacio){
    cout << "Ingrese el espacio disponible para la mascota que busca adoptar (en metros cuadrados):" << endl;
    cin >> espacio;
    cout << endl;
}

/*
 * PRE: -
 * POST: Convierte el tamaño expresado en palabras a enteros y lo devuelve.
 */
int convertir_tamano_a_entero(int espacio){
    int tamano;
    if(espacio <= DIMINUTO && espacio >= MENOR_TAMANO){
        tamano =  NUM_DIMINUTO;
    }
    else if(espacio <= MEDIANO && espacio >= DIMINUTO){
        tamano = NUM_PEQUENO;
    }
    else if(espacio >= MEDIANO && espacio < GRANDE){
        tamano = NUM_MEDIANO;
    }
    else if(espacio >= GRANDE && espacio < GIGANTE){
        tamano = NUM_GRANDE;
    }
    else if(espacio >= GIGANTE){
        tamano = NUM_GIGANTE;
    }

    return tamano;
}

/*
 * PRE: -
 * POST: Pide el nombre del animal a adoptar o "S/s" en caso de querer volver al menu. Valida el nombre ingresado y lo vuelve a
 * pedir en caso de que este no se encuentre en la lista.
 */
void elegir_animal(Refugio* refugio, string &nombre, int tamano){
    cout << "Ingrese el nombre del animal que quiere adoptar o S/s en caso de querer salir: " << endl;
    getline(cin >> ws, nombre);
    cout << endl;
    if(nombre != SALIR_MINUSCULA && nombre != SALIR_MAYUSCULA){
        if(!refugio->esta_animal(nombre)){
            cout << "El nombre no se encuentra en la lista. " << endl;
            cout << endl;
        }
    }
}
/*
 * PRE: La opcion debe ser mayor o igual a 1 y menor o igual a 4.
 * POST: Devuelve TRUE en caso de que la opcion este dentro del rango, FALSE en caso contrario.
 */
bool es_opcion_submenu_valida(int opcion){
    return (opcion >= MIN_SUBMENU && opcion <= MAX_SUBMENU);
}

/*
 * PRE: -
 * POST: Muestra las opciones a seleccionar de la pregunta individual.
 */
void mostrar_pregunta_individual(){
    cout << "------------------------------------------" << endl;
    cout << "Que desea hacer?" << endl;
    cout << " > 1. Bañar" << endl;
    cout << " > 2. Alimentar" << endl;
    cout << " > 3. Saltear" << endl;
    cout << "------------------------------------------" << endl; 
}

/*
 * PRE: La opcion debe ser mayor o igual a 1 y menor o igual a 3.
 * POST: Devuelve TRUE en caso de que la opcion este dentro del rango, FALSE en caso contrario.
 */
bool es_opcion_pregunta_valida(int opcion){
    return (opcion >= MIN_PREGUNTA_INDIVIDUAL && opcion <= MAX_PREGUNTA_INDIVIDUAL); 
}

/*
 * PRE: -
 * POST: Pide una nueva opcion al usuario y la guarda hasta que esta opcion sea valida.
 */
void validar_opcion_pregunta_elegida(int &opcion_elegida){
    while(!es_opcion_pregunta_valida(opcion_elegida)){
        cout << "El dato ingresado no es correcto. Las opciones son (1)Bañar (2)Alimentar o (3)Saltear, por favor ingrese otra opción: " << endl;
        cin >> opcion_elegida;
    }
}

/*
 * PRE: -
 * POST: Procesa la opcion ingresada por el usuario.
 */
void procesar_pregunta_individual(Refugio* refugio, int opcion, int& index, bool& parar){
    if(opcion == BANAR_INDIVIDUAL){
        refugio->banar_individualmente(index);
        cout << "Volveras al submenu" << endl;
        parar = true;
    }
    else if(opcion == ALIMENTAR_INDIVIDUAL){
        refugio->alimentar_individualmente(index);
        cout << "Volveras al submenu" << endl;
        parar = true;
    }
    else if(opcion == SALTEAR){
        return;
    }
}

/*
 * PRE: -
 * POST: Muestra las opciones a seleccionar del submenu de cuidar_animales.
 */
void mostrar_submenu(){
    cout << "==========================================" << endl;
    cout << "Seleccionaste la opcion de cuidar animales." << endl << "Que desea hacer?:" << endl;
    cout << " > 1. Elegir individualmente." << endl;
    cout << " > 2. Alimentar a todos." << endl;
    cout << " > 3. Bañar a todos." << endl;
    cout << " > 4. Regresar al inicio." << endl;
    cout << "------------------------------------------" << endl;
}

/*
 * PRE: -
 * POST: Pide el numero de la accion elegida al usuario y la guarda.
 */
int pedir_opcion_individual(){
    int opcion_elegida;
    cout << "Ingrese el número de su acción elegida: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

/*
 * PRE: -
 * POST: Pide al usuario una nueva opcion valida hasta ingresarla correctamente y la guarda.
 */
void validar_opcion_submenu_elegida(int &opcion_elegida){
    while(!es_opcion_submenu_valida(opcion_elegida)){
        cout << "El dato ingresado no es correcto. Las opciones son (1)Elegir al animal individualmente, (2)Bañar a todos, "\
        "(3)ALimentar a todos o (4)Regresar al inicio. Por favor ingrese otra opción: ";
        cin >> opcion_elegida;
    }
}

/*
 * PRE: -
 * POST: Muestra al primer animal de la lista con las respectivas preguntas del submenu. Pide al usuario que ingrese una opcion,
 * la valida y procesa la accion de la pregunta individual.
 */
void elegir_animal_individual(Refugio* refugio){
    bool parar = false;
    int i = 1;
    while(i < refugio->obtener_cantidad_animales() && !parar){
        refugio->mostrar_un_animal(i);
        mostrar_pregunta_individual();
        int respuesta = pedir_opcion_individual();
        validar_opcion_pregunta_elegida(respuesta);
        procesar_pregunta_individual(refugio, respuesta, i, parar);
        i++; 
    }
}

/*
 * PRE: -
 * POST: Procesa la opcion del submenu (elegir animal individual, alimentar a todos, bañar a todos o regresar al menu).
 */
void procesar_opcion_submenu(Refugio* refugio, int opcion, bool& parar){
    switch (opcion){
        case ELEGIR_INDIVIDUALMENTE:
            elegir_animal_individual(refugio);
            break;
        case ALIMENTAR_TODOS:
            refugio->alimentar_todos();
            cout << "Has alimentado a todos los animales." << endl;
            break;
        case BANAR_TODOS:
            refugio->banar_todos();
            cout << "Has bañado a todos los animales." << endl;
            break;
        case REGRESAR_INICIO:
            cout << "Ha elegido regresar al inicio." << endl;
            parar = true;
            break;
    }
}

/*
 * PRE: -
 * POST: Muestra el submenu, pide la opcion valida al usuario y en base a esa respuesta procesa la accion.
 */
void cuidar_animales(Refugio* refugio){
    int i = 1;
    bool parar = false;
    while(i < refugio->obtener_cantidad_animales() && !parar){
        mostrar_submenu();
        int respuesta = pedir_opcion_individual();
        validar_opcion_submenu_elegida(respuesta);
        procesar_opcion_submenu(refugio, respuesta, parar);
        i++;
    }
}

/*
 * PRE: -
 * POST: Pide al usuario el nombre a buscar del animal. Si lo encuentra lo muestra, en caso contrario le avisa al usuario que 
 * no se encuentra.
 */
void buscar_animal(Refugio* refugio){
    string nombre;
    cout << "Ingrese el nombre del animal que desea buscar: " << endl;
    getline(cin >> ws, nombre);
    refugio->mostrar_animal_buscado(nombre);
    if(!refugio->esta_animal(nombre)){
        cout << "Ese animal no se encuentra!" << endl;
    }
}

/*
 * PRE: -
 * POST: Le pide al usuario el nombre de un animal. Si lo encuentra lo elimina, en caso contrario le avisa al usuario que 
 * no se encuentra.
 */
void adoptar_animal(Refugio* refugio){
    int espacio;
    string nombre;

    preguntar_espacio_animal(espacio);
    int tamano = convertir_tamano_a_entero(espacio); 
    refugio->mostrar_animales_habilitados(tamano);
    elegir_animal(refugio, nombre, tamano);
    refugio->eliminar_animal(nombre);
    cout << "Felicitaciones! Animal adoptado :)" << endl;
}

/*
 * PRE: -
 * POST: Ejecuta la accion del menu en base a la opcion ingresada por el usuario. Modifica el estado de suciedad y hambre de 
 * los animales al concretar cada accion.
 */
void ejecutar_comandos(Refugio* refugio, bool &fin_de_ordenes, int comando){
    if(comando == OPCION_LISTAR_ANIMALES){
        cout << "Elegiste la opcion N º " << OPCION_LISTAR_ANIMALES << ": LISTAR ANIMALES." << endl;
        cout << "==========================================" << endl;
        (*refugio).listar_animales();
    } else if(comando == OPCION_RESCATAR_ANIMAL){
        cout << "Elegiste la opcion N º " << OPCION_RESCATAR_ANIMAL << ": RESCATAR ANIMAL." << endl;
        cout << "==========================================" << endl;
        cargar_animal_nuevo(refugio);
    } else if(comando == OPCION_BUSCAR_ANIMAL){
        cout << "Elegiste la opcion N º " << OPCION_BUSCAR_ANIMAL << ": BUSCAR ANIMAL." << endl;
        cout << "==========================================" << endl;
        buscar_animal(refugio);
    } else if(comando == OPCION_CUIDAR_ANIMALES){
        cout << "Elegiste la opcion N º " << OPCION_CUIDAR_ANIMALES << ": CUIDAR ANIMALES." << endl;
        cout << "==========================================" << endl;
        cuidar_animales(refugio);
    } else if(comando == OPCION_ADOPTAR_ANIMAL){
        cout << "Elegiste la opcion N º " << OPCION_ADOPTAR_ANIMAL << ": ADOPTAR ANIMAL." << endl;
        cout << "==========================================" << endl;
        adoptar_animal(refugio);
    } else if(comando == OPCION_GUARDAR_SALIR){
        cout << "Elegiste la opcion N º " << OPCION_GUARDAR_SALIR << ": GUARDAR Y SALIR." << endl;
        cout << "==========================================" << endl;
        (*refugio).cerrar_refugio();
        fin_de_ordenes = true;
    }
    (*refugio).modificar_estado_animales();
}

void siguiente_accion(Refugio* refugio, bool &fin_de_ordenes){
    mostrar_menu();
    int comando = pedir_comando();
    ejecutar_comandos(refugio, fin_de_ordenes, comando);
}


