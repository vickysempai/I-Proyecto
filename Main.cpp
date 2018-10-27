#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <cstring>

#include "listasimple.h"
#include "listaDCalv.h"
#include "ListaDCinventario.h"
#include "ListaDoble.h"
//#include "funcionesmenus.cpp"
using namespace std;


lista ciudades; //CODCIUDAD;nombre
listaDCalv usuarios;//CodCiudad;CEDULA; Nombre;Telefono;  0 Cliente,1 Administrador,2 Vendedor y 3 Cliente-Funcionario
listaD supermercado;//CodCiudad;CODSUPER;Nombre
listaDCinventario inventario;//CodSuper;CODPRODUCTO;Nombre;CantidadProducto;PrecioUnitario

void consultarprecio(){
	string codigo;
	cout<<"indique el codigo del producto"<<endl;
	cin>>codigo;
	inventario.consultarprecio(codigo);
}
void consultarproductos(){
	inventario.Mostrar();
}

void consultardescuento(){cout<<"en construccion...";}
void comprar(){cout<<"en construccion...";}
void facturacion(){cout<<"en construccion...";}

void insertarproducto(){cout<<"en construccion...";}
void eliminarproducto(){cout<<"en construccion...";}
void modificarproducto(){cout<<"en construccion...";}
void consultardescuentos(){cout<<"en construccion...";}
void registrarclientes(){cout<<"en construccion...";}
void reportes(){cout<<"en construccion...";}

void menuadministrador(){
	int accion;
	cout<<"1.Insertar Producto"<<endl;
	cout<<"2.Eliminar Producto"<<endl;
	cout<<"3.Modificar Producto"<<endl;
	cout<<"4.Consultar Precio"<<endl;
	cout<<"5.Consultar Descuentos"<<endl;
	cout<<"6.Consultar Productos de un Super"<<endl;
	cout<<"7.Registrar Clientes	"<<endl;
	cout<<"8.Reportes"<<endl;
	cin>>accion;
	switch(accion)
	{
		case 1: 
			insertarproducto();
			break;
		case 2: 
			eliminarproducto();
			break;
		case 3:
			modificarproducto();
			break;
		case 4: 
			consultarprecio();
			break;
		case 5:
			consultardescuentos();
			break;
		case 6:
			consultarproductos();
			break;
		case 7:
			registrarclientes();
			break;
		case 8:
			reportes();
			break;
		default:
			cout<<"no se reconoce"<<endl;
			break;
	}
	
	menuadministrador();
}

void menuvendedor(){cout<<"en construccion...";}
void menufuncionario(){cout<<"en construccion...";}
void registrarse(){cout<<"en construccion...";}

void menucliente()
{
	string accion;
	cout<<"1.Consultar Precio"<<endl;
	cout<<"2.Consultar Descuento"<<endl;
	cout<<"3.Consultar Productos"<<endl;
	cout<<"4.Comprar ( Carrito)"<<
	cout<<"5.Facturación"<<endl; 
	cin>>accion;
		if(accion=="1")consultarprecio();
		if(accion=="2")consultardescuento();
		if(accion=="3")consultarproductos();
		if(accion=="4")comprar();
		if(accion=="5")facturacion();
		else cout<<"no se reconoce la accion";
	
}

void CargarArchivos(){
	ciudades.leerarchivo("ciudad.txt");
	//ciudades.Mostrar();
	supermercado.leerarchivo("supermercado.txt");
	//supermercado.Mostrar();
	inventario.leerarchivo("inventario.txt");
	//inventario.Mostrar();
	usuarios.InsertarFinal("0");
	usuarios.InsertarFinal("1");
	usuarios.InsertarFinal("2");
	usuarios.InsertarFinal("3");
	//usuarios.Mostrar();
	usuarios.leerarchivo("usuarios.txt");
}

void ingresar(){
	string cedula,tipo;
	cout<<"por favor ingrese su cedula "<<endl;
	cin>>cedula;
	cout<<"ingrese su tipo de usuario"<<endl;
	cout<<"0-cliente"<<endl;
	cout<<"1-administrador"<<endl;
	cout<<"2-vendedor"<<endl;
	cout<<"3-cliente/funcionario"<<endl;
	cin>>tipo;
	cout<<"bool = 	"<<	usuarios.verificarcedula(tipo,cedula)<<endl;;
	if(usuarios.verificarcedula(tipo,cedula)){
		if(tipo=="0") menucliente();
		if(tipo=="1") menuadministrador();
		if(tipo=="2") menuvendedor();
		if(tipo=="3") menufuncionario();
		}
		else registrarse();
	}
	
int main(int argc, char** argv) {
	CargarArchivos();
	ingresar();
	return 1;
}


