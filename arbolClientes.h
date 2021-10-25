#ifndef ARBOLCLIENTES_H_INCLUDED
#define ARBOLCLIENTES_H_INCLUDED
#include "clientes.h"


typedef struct _nodoArbol{
    stClientes dato;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stClientes dato);
nodoArbol* agregarArbol(nodoArbol* arbol, nodoArbol* nuevo);

#endif // ARBOLCLIENTES_H_INCLUDED
