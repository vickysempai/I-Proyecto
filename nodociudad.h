#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>
using namespace std;

class nodociudad {
   public:
    nodo(int v)
    {
       codigo = v;
       siguiente = NULL;
       anterior =NULL;
    }

   nodo(int v, nodo * signodo)
    {
       codigo = v;
       siguiente = signodo;
    }

 private:
    int codigo;
    string ciudad;
    nodociudad *siguiente;
    nodociudad *anterior;
    
        
   friend class listaDC;
};


#endif /* NODO_H */

