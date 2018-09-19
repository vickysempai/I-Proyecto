#ifndef NODOINVENTARIO_H
#define NODOINVENTARIO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <cstring>

using namespace std;

class nodoinventario{
	public:
		nodoinventario(string linea)
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
		CodSuper=atributos[0];
	    CodProducto=atributos[1];
	    Nombre=atributos[2];
	    CantidadProducto=atributos[3];
	    PrecioUnitario=atributos[4];
	    siguiente = NULL;
	    anterior = NULL;
		}
	nodoinventario(string linea, nodoinventario *sig)
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
		CodSuper=atributos[0];
	    CodProducto=atributos[1];
	    Nombre=atributos[2];
	    CantidadProducto=atributos[3];
	    PrecioUnitario=atributos[4];
	    siguiente = sig;
		}
    

 private:
    string CodSuper;
	string CodProducto;
	string Nombre;
	string CantidadProducto;
	string PrecioUnitario;
    nodoinventario *siguiente;
    nodoinventario *anterior;
    
        
   friend class listaDCinventario;
};


#endif /* NODOINVENTARIO_H */

