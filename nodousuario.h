#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include <cstdlib>
#include <string>
/*strcpy*/
#include <stdio.h>
#include <string.h>

using namespace std;

class nodousuario {
	public:
    nodousuario (string linea)
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
	    codCiudad=atributos[0];
	    nombre=atributos[1];
	    cedula=atributos[2];
	    telefono=atributos[3];
	    categoria=atributos[4];
	    siguiente = NULL;
	    anterior =NULL;
		}
		
		
	nodousuario(string linea,nodousuario* nuevonodo)
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
	    codCiudad=atributos[0];
	    nombre=atributos[1];
	    cedula=atributos[2];
	    telefono=atributos[3];
	    categoria=atributos[4];
	    siguiente = nuevonodo;
		}
		
   private:
    string codCiudad;
    string nombre;
    string cedula;
    string telefono;
    string categoria;
    nodousuario *siguiente;
    nodousuario *anterior;
    

   friend class listaDC;
};

typedef nodousuario *pnodo;


#endif /* NODOUSUARIO_H */
