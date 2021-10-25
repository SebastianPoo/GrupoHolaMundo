#include "clientes.h"
#include "consumos.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define nomArchivo "clientes.dat"
#define backupClientes "backupArchivo.dat"
#define nomArchiConsumos "consumos.dat"
#define ANIO 2021
#include "listaConsumo.h"
#include "arbolClientes.h"


nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stClientes dato){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbol* agregarArbol(nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.id < arbol->dato.id){
            arbol->izq = agregarArbol(arbol->izq, nuevo);
        }else{
            arbol->der = agregarArbol(arbol->der, nuevo);
        }
    }

    return arbol;
}

nodoArbol* archivo2Arbol(char archivo [], nodoArbol* arbol){
    stClientes e;
    FILE *pArchiClientes = fopen(archivo, "rb");
    if(pArchiClientes ){

        while(fread(&e, sizeof(stClientes), 1, pArchiClientes)>0){
                arbol = agregarArbol(arbol, crearNodoArbol(e));
        }
        fclose(pArchiClientes);
    }

    return arbol;
}
