#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <cstdlib>
#include "nodociudad.h"
#include <fstream>
#include <sstream>
using namespace std;


class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Buscar(string numero);
    void Buscar(string numero, int pos);
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
    void Sumar(int numero1,int numero2);
    void leerarchivo(string v);
    /*int GetValor(int pos);
    void SumarDiferenteTamano(int numero1,int numero2);
    bool PosicionValida(int pos);
    void InsertarNumero(int numero);*/
   
   private:
    pnodo primero;
    pnodo actual;
};

#endif /* LISTASIMPLE_H */
