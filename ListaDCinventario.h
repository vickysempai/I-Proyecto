#ifndef LISTADCINVENTARIO_H
#define LISTADCINVENTARIO_H

#include "nodoinventario.h"

typedef nodoinventario *pnodo;

class listaDCinventario {
   public:
    listaDCinventario() { primero = actual = NULL; }
    ~listaDCinventario();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
    pnodo actual;
};

#endif /* LISTADC_H */

