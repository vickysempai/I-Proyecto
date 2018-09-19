#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
#include "nodosupermercado.h"

using namespace std;

typedef nodosupermercado *pnodo;

class listaD {
   public:
    listaD() { primero = actual = NULL; }
    ~listaD();
    
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
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
    pnodo actual;

};

#endif /* LISTADOBLE_H */
