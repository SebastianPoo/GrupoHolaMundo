#ifndef LISTACONSUMO_H_INCLUDED
#define LISTACONSUMO_H_INCLUDED

typedef struct _nodoLista{
 	stConsumos dato;
    struct _nodoLista* sig;
}nodoLista;


nodoLista* inicLista();
nodoLista* crearNodoLista(stConsumos dato);
nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo);
void muestraLista(nodoLista* lista);
void muestraNodo(nodoLista* nodo);

#endif // LISTACONSUMO_H_INCLUDED
