#include "Lector_csv.hpp"

#include <sstream>
#include <fstream>

void Lector_csv::definir_personalidad(string personalidad, Personalidad* &personalidad_del_animal){
	if (personalidad == DORMILON){
		personalidad_del_animal = new Personalidad_dormilon();
	}
	else if (personalidad == JUGUETON){
		personalidad_del_animal = new Personalidad_jugueton();
	}
	else if (personalidad == SOCIABLE){
		personalidad_del_animal = new Personalidad_sociable();
	}
	else if (personalidad == TRAVIESO){
		personalidad_del_animal = new Personalidad_travieso();
	}else{
		personalidad_del_animal = new Personalidad_predeterminado();
	}
}

void Lector_csv::definir_tamano(string tamano_s, Tamano* &tamano){
	if(tamano_s == S_DIMINUTO){
		tamano = new Tamano_diminuto();
	}
	else if(tamano_s == S_PEQUENO){
		tamano = new Tamano_pequeno();
	}
	else if(tamano_s == S_MEDIANO){
		tamano = new Tamano_mediano();
	}
	else if(tamano_s == S_GRANDE){
		tamano = new Tamano_grande();
	}else{
		tamano = new Tamano_gigante();
	}
}

Lector_csv::Lector_csv(string archivo){
    nombre_archivo = archivo;
}

void Lector_csv::cargar_animales(Refugio* refugio){
    ifstream archivo_refugio_r(nombre_archivo);

    if(!archivo_refugio_r.is_open()){
        cout << "No se encontro un archivo con nombre \"" << nombre_archivo<< "\", se va a crear el archivo" << endl;
        archivo_refugio_r.open(nombre_archivo, ios::out);
        archivo_refugio_r.close();
        archivo_refugio_r.open(nombre_archivo, ios::in);
    }

    string linea = " ";

    while(getline(archivo_refugio_r, linea)){
        string nombre, edad, tamano, especie, personalidad;
        stringstream stream(linea);

        getline(stream, nombre, DELIMITADOR);
        getline(stream, edad, DELIMITADOR);
        getline(stream, tamano, DELIMITADOR);
        getline(stream, especie, DELIMITADOR);
        getline(stream, personalidad);

        Tamano* tamano_definido = nullptr;
        definir_tamano(tamano, tamano_definido);

        Personalidad* personalidad_definida = nullptr;
        definir_personalidad(personalidad, personalidad_definida);
        
        refugio->agregar_animal(especie[0], nombre, stoi(edad), tamano_definido, personalidad_definida);
    }

    archivo_refugio_r.close();
}


void Lector_csv::guardar_animales(Animal* vector_copiado[], int tope_animales){
    ofstream archivo_refugio_w(nombre_archivo);

    for (int i = 0; i < tope_animales; i++){
        string nombre, edad, tamano, especie, personalidad;
        vector_copiado[i]->completar_informacion(nombre, edad, tamano, especie, personalidad);
        archivo_refugio_w << nombre << ',' << edad << ',' << tamano << ',' << especie << ',' << personalidad << endl;
    }
    archivo_refugio_w.close();
}

Lector_csv::~Lector_csv(){
    
}