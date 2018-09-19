#ifndef LISTADC_H
#define LISTADC_H

#include "nodousuario.h"

typedef nodousuario *pnodo;

class listaDC {
   public:
    listaDC() { primero = actual = NULL; }
    ~listaDC();
    
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

