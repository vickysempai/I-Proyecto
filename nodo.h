
#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

   nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }
    void siguiente()
    

 private:
    int valor;
    nodo *siguiente;
    nodo *anterior;
    
        
   friend class listaDC;
};


#endif /* NODO_H */

