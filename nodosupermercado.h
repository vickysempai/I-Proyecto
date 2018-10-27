#ifndef NODOSUPERMERCADO_H
#define NODOSUPERMERCADO_H

#include <cstdlib>
#include <string>
/*strcpy*/
#include <stdio.h>
#include <string.h>

using namespace std;

class nodosupermercado {
   public:
    nodosupermercado(string linea)
	    {
		char str[linea.size()+1];
	    strcpy(str,linea.c_str());
	    char * pch;
	    pch = strtok (str,";");
	    string atributos[5];
	   	int cont=0;
	    while (pch != NULL)
	    {
	    	atributos[cont]=pch;
	    	pch = strtok (NULL, ";");
	    	cont++;
	    }
		codSuper=atributos[0];
	    codProducto=atributos[1];
	    codProducto=atributos[2];
	    siguiente = NULL;
		}
	nodosupermercado(string linea, nodosupermercado *sig)
	    {
		char str[linea.size()+1];
	    strcpy(str,linea.c_str());
	    char * pch;
	    pch = strtok (str,";");
	    string atributos[5];
	   	int cont=0;
	    while (pch != NULL)
	    {
	    	atributos[cont]=pch;
	    	pch = strtok (NULL, ";");
	    	cont++;
	    }
		codSuper=atributos[0];
	    codProducto=atributos[1];
	    codProducto=atributos[2];
	    siguiente = sig;
		}
    

 private:
    string codSuper;
    string codProducto;
    string nombre;
    nodosupermercado *siguiente;
    nodosupermercado *anterior;
    
        
   friend class listaD;
};

#endif /* NODO_H */

