#ifndef CELDACONSUMO_H_INCLUDED
#define CELDACONSUMO_H_INCLUDED
#include "listaConsumo.h"

typedef struct{
    int id;
    nodoLista* listaConsumos;
}stCelda;

int buscarPosEmpleado(stCelda adl[], int validos, int id);
int agregarEnArreglo(stCelda adl[], int validos, int id);
int buscarPorID(stCelda adl[], int validos, int id);
int buscarPorID(stCelda adl[], int validos, int id);
#endif // CELDACONSUMO_H_INCLUDED
