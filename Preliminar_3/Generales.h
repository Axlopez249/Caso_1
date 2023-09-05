#ifndef _GENERALES_
#define _GENERALES_ 1
#define END 999999999
#define START 0

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Lista.h"
#include "news.cpp"


using namespace std;

void Ingresar_noticias(const string &busqueda, listadoble &lista){
    Newsapi newsapi;
    vector<News *> noticias = newsapi.getRecords(busqueda);

    for (News* noticia : noticias) {
        // Verificar si record no es nulo (por seguridad)
        lista.Add(END, noticia->getTitle());
    }   
    
}

void Agregar(listadoble &lista, string dato){
    lista.Add(END, dato);    
    return;
}

void Mostrar(listadoble &lista){
    lista.mostrar();
}

void Busqueda_Palabras(listadoble &lista, string palabras_buscar[], int &tamaño){
    vector<string> strings_lista;
    lista.Acarrear(strings_lista);

    int contador = 0;
    for (const string& elemento : strings_lista) {
        contador++;
        if (contador > 5) {
            return;
        }
        istringstream iss(elemento);
        string palabra;

        bool encontrada = false;
        while (iss >> palabra) {
            //tomo palabra por palabra
            for (int i = 0; i < tamaño; i++)
            {
                if (palabras_buscar[i] == palabra){
                    cout << elemento << endl;
                    encontrada = true;
                    contador ++;
                    break;
                }
            }
            if (encontrada){
                break;
            }
        }
    }
}

void Eliminar_Busqueda(listadoble &lista, string palabras_buscar[], int &tamaño){
    vector<string> strings_lista;
    lista.Acarrear(strings_lista);

    int contador = 0;
    for (const string& elemento : strings_lista) {
        contador++;
        if (contador > 5) {
            return;
        }
        istringstream iss(elemento);
        string palabra;

        bool encontrada = false;
        while (iss >> palabra) {
            //tomo palabra por palabra
            for (int i = 0; i < tamaño; i++)
            {
                if (palabras_buscar[i] == palabra){
                    lista.eliminar(elemento);
                    encontrada = true;
                    contador ++;
                    break;
                }
            }
            if (encontrada){
                break;
            }
        }
    }
}

void Reorganizar(listadoble &lista, int actual_position, int new_position) {
    if (actual_position < 1 || actual_position > lista.size || new_position > lista.size) {
        // Verificar que las posiciones sean válidas
        cout << "Posiciones inválidas. La lista tiene " << lista.size << " elementos." << endl;
        return;
    }

    if (actual_position == new_position) {
        // No es necesario hacer nada si las posiciones son iguales
        return;
    }

    // Obtener el dato en la posición actual
    string data = lista.tomar_dato(actual_position);

    // Eliminar el dato de la posición actual
    lista.eliminar(data);

    // Calcular la nueva posición después de eliminar el dato
    if (new_position < 0) {
        new_position = actual_position + (abs(new_position));
    } else {
        new_position = actual_position - new_position;
    }

    // Insertar el dato en la nueva posición
    lista.Add(new_position, data);
}

void Top5(listadoble &lista){
    vector<string> strings_lista;
    lista.Acarrear(strings_lista);

    int contador = 0;
    for (const string& elemento : strings_lista) {
        contador++;

        if (contador > 5) {
            return;
        }

        cout << contador << "  " << elemento << std::endl;
    }
}


#endif