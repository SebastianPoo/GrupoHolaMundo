#ifndef CELDACONSUMO_H_INCLUDED
#define CELDACONSUMO_H_INCLUDED
#include "listaConsumo.h"

typedef struct{
    int id;
    nodoLista* listaConsumos;

}stCelda;

int agregarEnArreglo(stCelda* adl, int validos, int id);
int altaCelda(stCelda* adl, stConsumos e, int validos);
int buscarPorID(stCelda* adl, int validos, int id);
stCelda* ConsumosToCelda (stConsumos consumos[], int vConsumos, stCelda* celdas, int** vCeldas);
#endif // CELDACONSUMO_H_INCLUDED
