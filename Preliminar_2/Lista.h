#ifndef _LISTAGENERICA_
#define _LISTAGENERICA_ 1

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>
#include "nodo.h"

using namespace std;


struct listadoble {
    struct nodo* start = nullptr;
    struct nodo* end = nullptr;
    int size = 0;

    /*void Add(const string& pData) {
        nodo* newNode = new nodo();
        newNode->data = pData;

        if (start == nullptr) {
            start = newNode;
            end = newNode;
        } else {
            end->next = newNode;
            end = newNode;
        }
    }*/

    int Add(int pPosition, const string &pdata) {
        int result = 0;

        // Crear un nuevo nodo y asignarle el dato
        struct nodo* newNodo = new nodo();
        newNodo->data = pdata;

        if (size == 0) {
            // Caso especial: la lista está vacía
            start = newNodo;
            end = newNodo;
            newNodo->next = nullptr;
            newNodo->previous = nullptr;
        } else {
            if (pPosition == 1) {
                // Insertar al principio de la lista
                newNodo->next = start;
                newNodo->previous = nullptr;
                start->previous = newNodo;
                start = newNodo;
            } else if (pPosition >= size) {
                // Insertar al final de la lista
                newNodo->next = nullptr;
                newNodo->previous = end;
                end->next = newNodo;
                end = newNodo;
            } else {
                // Insertar en una posición específica
                int currentPosition = 1;
                nodo* cursor = start;

                while (cursor != nullptr && currentPosition < pPosition) {
                    cursor = cursor->next;
                    currentPosition++;
                }

                newNodo->next = cursor;
                newNodo->previous = cursor->previous;
                cursor->previous->next = newNodo;
                cursor->previous = newNodo;
            }
        }

        size++;
        return result;
    }

    void Acarrear(vector<string> &objetos ){
        nodo* nodo_actual = start;

        while (nodo_actual != nullptr) {
            objetos.push_back(nodo_actual->data);
            nodo_actual = nodo_actual->next;
        }

    }

    void mostrar(){
        nodo* nodo_actual = start;
        int contador=1;
        while (nodo_actual != nullptr) {
            cout << contador << " " << nodo_actual->data << endl;
            nodo_actual = nodo_actual->next;
            contador++;
        }
    }

    void eliminar(string pdata){
        nodo* nodo_actual = start;

        while (nodo_actual != nullptr) {
            if (nodo_actual->data == pdata){
                nodo *anterior = nodo_actual->previous;
                nodo *posterior = nodo_actual->next;

                if (anterior) {
                    anterior->next = posterior;
                } else {
                    start = posterior; // Si es el primer nodo
                }

                if (posterior) {
                    posterior->previous = anterior;
                } else {
                    end = anterior; // Si es el último nodo
                }

                delete nodo_actual;
                size --;
                return;
            }
            nodo_actual = nodo_actual->next;
        }
    }

    string tomar_dato(int position){
        nodo* nodo_actual = start;

        int contador = 1;
        while (nodo_actual != nullptr) {
            if (contador==position)
            {
                return nodo_actual->data;
            }
            nodo_actual = nodo_actual->next;
            contador++;
        }

        return "";
    }
};
#endif