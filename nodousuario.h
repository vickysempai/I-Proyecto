class nodousuario {
	public:
    nodousuario(string linea)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
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
