class nodousuario {
	public:
    nodousuario(string linea)
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
    //string codSuper;
    //string codProducto;
    //string cantidadProducto;
    //string precioUnitario;
    nodousuario *siguiente;
    nodousuario *anterior;
    

   friend class listaCiudades;
};

typedef nodo *pnodo;


#endif /* NODO_H */
