#ifndef ARBOLCLIENTES_H_INCLUDED
#define ARBOLCLIENTES_H_INCLUDED
#include "clientes.h"
#include "listaConsumo.h"


typedef struct _nodoArbol{
    stClientes dato;
    nodoLista* listaConsumo;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stClientes dato);
nodoArbol* agregarArbol(nodoArbol* arbol, nodoArbol* nuevo);
nodoArbol* buscaNodoArbolCliente(nodoArbol* arbol, int id);
void muestraNodoArbolPersona(nodoArbol* nodo);
nodoArbol* arrayToArbol (stClientes c[], int base, int tope);
nodoArbol* alta(nodoArbol* adl, stClientes e, stConsumos a);
nodoArbol* agregar_adl(nodoArbol* adl, nodoArbol* nuevo);
nodoArbol* archivo2adl(stClientes a[], char archivo[], int v);
nodoArbol* archivo2adl2(stClientes a[], stConsumos b [], int v, int vConsumos);
#endif // ARBOLCLIENTES_H_INCLUDED
