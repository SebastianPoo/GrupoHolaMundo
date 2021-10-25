#include "celdaConsumo.h
#include "clientes.h"
#include "consumos.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int alta(stCelda adl[], stConsumos e, int validos){
    nodo* nuevo = crearNodoLista(e);
    int pos = buscarPosEmpleado(adl, validos, e.id);

    if(pos == -1){
        validos = agregarEnArreglo(adl, validos, e.id);
        pos = validos - 1;
    }

    adl[pos].listaEmpleados = agregarAlPrincipio(adl[pos].listaEmpleados, nuevo);

    return validos;
}

int buscarPorID(stCelda adl[], int validos, int id){
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

int agregarEnArreglo(stCelda adl[], int validos, int id){
     adl[validos].id = id;
    adl[validos].listaEmpleados = inicLista();
    validos++;
    return validos;
}

