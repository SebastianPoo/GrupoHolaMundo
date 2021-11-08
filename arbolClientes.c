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
        if(nuevo->dato.id %2 == 0){
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

void muestraNodoArbolPersona(nodoArbol* nodo){
    muestraUnCliente(nodo->dato);
    muestraLista(nodo->listaConsumo);

}

void enOrdenPersona(nodoArbol* arbol){
    if(arbol){
        enOrdenPersona(arbol->izq);
        muestraNodoArbolPersona(arbol);
        enOrdenPersona(arbol->der);
    }
}

nodoArbol* buscaNodoArbolCliente(nodoArbol* arbol, int id){
    nodoArbol* respuesta = NULL;
    if(arbol){
        if(arbol->dato.nroCliente == id){
            respuesta = arbol;
        }else{
            if(id < arbol->dato.id){
                respuesta = buscaNodoArbolCliente(arbol->izq, id);
            }else{
                respuesta = buscaNodoArbolCliente(arbol->der, id);
            }
        }
    }

    return respuesta;
}

nodoArbol* arrayToArbol (stClientes c[], int base, int tope)
{
    int medio;

    nodoArbol* arbol=NULL;

    if(!(base>tope))
    {

        medio=(base+tope)/2;

        arbol=crearNodoArbol(c[medio]);

        arbol->izq=arrayToArbol(c,base,medio-1);
        arbol->der=arrayToArbol(c,medio+1,tope);
    }

    return arbol;
}

nodoArbol* alta(nodoArbol* adl, stClientes e, stConsumos a){
    nodoLista* nuevo = crearNodoLista(a);

    nodoArbol* respuesta = inicArbol();

    respuesta = buscaNodoArbolCliente(adl, e.id);
    if(respuesta==NULL){
        nodoArbol* nuevoArbol=crearNodoArbol (e);
        nuevoArbol->listaConsumo= agregarAlPrincipio(nuevoArbol->listaConsumo, nuevo);
        adl = agregar_adl(adl, nuevoArbol);

    }else{

    respuesta->listaConsumo= agregarAlPrincipio(respuesta->listaConsumo, nuevo);

    }
    return adl;
}

nodoArbol* agregar_adl(nodoArbol* adl, nodoArbol* nuevo)
{
    if (adl==NULL)
    {
        adl=nuevo;
    }
    else
    {
        if(adl->dato.id > nuevo->dato.id)
        {
            adl->izq=agregar_adl(adl->izq, nuevo);
        }
        else
        {
            adl->der=agregar_adl(adl->der, nuevo);
        }
    }
    return adl;
}

nodoArbol* archivo2adl(stClientes a[], char archivo[], int v){
    FILE *archi = fopen(archivo, "rb");
    stConsumos e;
    nodoArbol* adl= inicArbol();
    int i=0;
    if(archi){

        while(fread(&e, sizeof(stConsumos), 1, archi)>0){
        for(i=0; i<v; i++){
            if (e.idCliente==a[i].id){
              adl=alta(adl, a[i], e);

            }
        }
        }


    printf("\n %d \n", i);
        fclose(archi);
    }

    return adl;
}



nodoArbol* archivo2adl2(stClientes a[], stConsumos b [], int v, int vConsumos){

    nodoArbol* adl= inicArbol();
     for (int i=0; i<v; i++){
         for (int j=0; j<vConsumos; j++){
            if (a[i].id==b[j].idCliente){
                adl=alta(adl, a[i], b[j]);
            }
         }
     }
    return adl;
}
