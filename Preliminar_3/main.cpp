#ifndef _PRINCIPAL_
#define _PRINCIPAL_ 1

#include <iostream>
#include <string>
#include <vector>
#include "Generales.h"

using namespace std;
int main()
{
    struct listadoble lista;
    string lista_busqueda[2] = {"Hola", "como"};
    int contador = 2;

    Ingresar_noticias("Nacional", lista);

    //Agregar(lista, "Hola");
    //Agregar(lista, "como");
    //Agregar(lista, "Estas");
    //Agregar(lista, "Bien");
    //Agregar(lista, "Adios");
    //Agregar(lista, "Caho");

    //Esta zona es para poder sacar cada palabra de un string y guardarla en una lista de tamaño 2
    /*cout << "Lista de 2 palabras separadas por comas: " << endl;
    getline(cin, busqueda);
    
    istringstream iss(busqueda);
    while (getline(iss, palabra, ',')){
        lista_busqueda[contador] = palabra;
        contador++;
    }*/

    //Llamada de funciones
    //Mostrar(lista);
    //Top5(lista);
    //Busqueda_Palabras(lista, lista_busqueda, contador);
    //Eliminar_Busqueda(lista, lista_busqueda, contador);
    //Reorganizar(lista, 2, 1);
    //cout << "" << endl;
    Mostrar(lista);
    return 0;
}

#endif