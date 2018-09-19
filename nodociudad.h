#ifndef NODOCIUDAD_H
#define NODOCIUDAD_H

#include <iostream>
#include <string>
/*strcpy*/
#include <stdio.h>
#include <string.h>

using namespace std;

class nodociudad {
   public:
    nodociudad(string linea)
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
		codigo=atributos[0];
	    ciudad=atributos[1];
	    siguiente = NULL;
		}
		
	nodociudad(string linea, nodociudad *sig)
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
		codigo=atributos[0];
	    ciudad=atributos[1];
	    siguiente = sig;
		}
		
 private:
    string codigo;
    string ciudad;
    nodociudad *siguiente;
    
        
   friend class lista;
};
typedef nodociudad *pnodo;


#endif /* NODOCIUDAD_H */

