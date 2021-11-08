#include "celdaConsumo.h"
#include "clientes.h"
#include "consumos.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int altaCelda(stCelda* adl, stConsumos e, int validos){
    nodoLista* nuevo = crearNodoLista(e);
    int pos = buscarPorID(adl, validos, nuevo->dato.id);

    if(pos == -1){
        validos = agregarEnArreglo(adl, validos, nuevo->dato.id);
        pos = validos - 1;
    }

    adl[pos].listaConsumos = agregarAlPrincipio(adl[pos].listaConsumos, nuevo);

    return validos;
}

int buscarPorID(stCelda* adl, int validos, int id){
    int rta = -1;
    int i=0;
    while(i<validos && rta == -1){
        if(adl[i].id==id){
            rta = i;
        }
        i++;
    }

    return rta;
}

int agregarEnArreglo(stCelda* adl, int validos, int id){
     adl[validos].id = id;
    adl[validos].listaConsumos = inicLista();
    validos++;
    return validos;
}

stCelda* ConsumosToCelda (stConsumos consumos[], int vConsumos, stCelda* celdas, int** vCeldas){
    int i =0;
    while (i < vConsumos-1){
        (*vCeldas)=alta(celdas, consumos[i], vCeldas);
        i++;
    }
    return celdas;
}
