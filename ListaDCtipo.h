#ifndef LISTADCTIPO_H
#define LISTADCTIPO_H
#include <fstream>
#include <sstream>
#include "nodotipo.h"

class listaDCtipo {
   public:
    listaDCtipo() { primero = actual = NULL; }
    
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
    bool verificarcedula(string tipo,string cedula);
    
   private:
    nodotipo* primero;
    nodotipo* actual;
};

#endif /* LISTADCTIPO_H */
