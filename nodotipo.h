#ifndef NODOTIPO_H
#define NODOTIPO_H
#include <cstdlib>
#include <string>
/*strcpy*/
#include <stdio.h>
#include <string.h>

#include "ListaDC.h"

using namespace std;

class nodotipo {
	public:
    nodotipo(string valor)
	    {
	    tipo=valor;
	    siguiente = NULL;
	    anterior =NULL;
	
		}
		
		
	nodotipo(string valor,nodotipo* nuevonodo)
	    {
	    	tipo=valor;
	    	siguiente=nuevonodo;
		}
		
   private:
   	string tipo;
    listaDC ListaC; //clientes
    /*listaDC ListaA; //administrador
    listaDC ListaV; //vendedor
    listaDC ListaCF;*/ //cliente funcionario
    nodotipo *siguiente;
    nodotipo *anterior;
  	friend class listaDCalv;
};



#endif /* NODOTIPO_H */
