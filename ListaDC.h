#ifndef LISTADC_H
#define LISTADC_H
#include <fstream>
#include <sstream>
#include "nodousuario.h"

class listaDC {
   public:
    listaDC() { primero = actual = NULL; }
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
    void leerarchivo(string v);
    bool verificar(string cedula);
     
   private:
    nodousuario* primero;
    nodousuario* actual;
    friend class nodoTipo;
};

#endif /* LISTADC_H */

