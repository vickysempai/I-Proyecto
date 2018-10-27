/*
#include "listasimple.h"
#include "listaDCalv.h"
#include "ListaDCinventario.h"
#include "ListaDoble.h"
using namespace std;

lista ciudades; //CODCIUDAD;nombre
listaDCalv usuarios;//CodCiudad;CEDULA; Nombre;Telefono;  0 Cliente,1 Administrador,2 Vendedor y 3 Cliente-Funcionario
listaD supermercado;//CodCiudad;CODSUPER;Nombre
listaDCinventario inventario;//CodSuper;CODPRODUCTO;Nombre;CantidadProducto;PrecioUnitario

void consultarprecio(){
	string codigo;
	cout<<"indique el codigo del producto";
	cin>>codigo;
	inventario.consultarprecio(codigo);
}


void consultardescuento(){cout<<"en construccion...";}
void consultarproductos(){cout<<"en construccion...";}
void comprar(){cout<<"en construccion...";}
void facturacion(){cout<<"en construccion...";}

void insertarproducto(){cout<<"en construccion...";}
void eliminarproducto(){cout<<"en construccion...";}
void modificarproducto(){cout<<"en construccion...";}
void consultardescuentos(){cout<<"en construccion...";}
void registrarclientes(){cout<<"en construccion...";}
void reportes(){cout<<"en construccion...";}

void menuadministrador(){
	string accion;
	cout<<"1.	Insertar Producto		2.	Eliminar Producto	   	3.	Modificar Producto"<<endl;
	cout<< "4.	Consultar Precio  	5.	Consultar Descuentos		6.	Consultar Productos de un Super	"<<endl;
	cout<<"	7.	Registrar Clientes		8.	Reportes"<<endl;
	cin>>accion;
		if(accion=="1")insertarproducto();
		if(accion=="2")eliminarproducto();
		if(accion=="3")modificarproducto();
		if(accion=="4")consultarprecio();
		if(accion=="5")consultardescuentos();
		if(accion=="6")consultarproductos();
		if(accion=="7")registrarclientes();
		if(accion=="8")reportes();
	else cout<<"no se reconoce"<<endl;
}
void menuvendedor(){cout<<"en construccion...";}
void menufuncionario(){cout<<"en construccion...";}
void registrarse(){cout<<"en construccion...";}*/
