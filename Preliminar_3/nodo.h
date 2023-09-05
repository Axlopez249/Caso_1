#ifndef _NODO_
#define _NODO_ 1
#include <iostream>
#include <string>

using namespace std;
// void es un apuntador genérico a cualquier cosa 
// cuando ya necesite acceder a los datos de alguna forma requiero
// hacer casting al tipo de dato que yo se que está apuntando
struct nodo
{
    string data;
    nodo *next = nullptr;
    nodo *previous = nullptr;
};


#endif