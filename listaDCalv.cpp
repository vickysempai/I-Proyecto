#include "listaDCalv.h"
#include <cstdlib>
#include <iostream>

int listaDCalv::largoLista()
{
    int cont=0;

    nodotipo* aux = primero;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {
        while(aux!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    return cont;
    }
    
}

void listaDCalv::InsertarInicio(string v)
{
  
   if (ListaVacia())
   {
     primero = new nodotipo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     nodotipo* nuevo=new nodotipo (v);
     nuevo->siguiente=primero;
     nuevo->anterior= primero->anterior;
     primero->anterior->siguiente=nuevo;
     nuevo->siguiente->anterior=nuevo;
     primero= nuevo;
   }
}
 
void listaDCalv::InsertarFinal(string v)
{
   if (ListaVacia())
     {
     primero = new nodotipo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     nodotipo* nuevo = new nodotipo(v);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}


void listaDCalv::InsertarPos(string v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodotipo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(v);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(v);
        else
        {     
             nodotipo* aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             nodotipo* nuevo= new nodotipo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
       }
   }
}   

void listaDCalv::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        nodotipo* temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         nodotipo* aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         nodotipo* temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void listaDCalv::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        nodotipo* temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        nodotipo* aux = primero->anterior;
        nodotipo* temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}

void listaDCalv:: borrarPosicion(int pos)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<0))
        cout << "Error en posicion" << endl;
   else
   {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       nodotipo* aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       nodotipo* temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}

void listaDCalv::Mostrar()
{
   nodotipo* aux = primero;
   do{
   	//aux->ListaC.Mostrar();
   	cout<<aux->tipo<<"->";
   	aux = aux->siguiente;
   }while(aux!=primero);
     cout<<endl;
}   

bool listaDCalv::verificarcedula(string tipo,string cedula)
{
   nodotipo* aux=primero;
   while(aux->siguiente!=primero) {
		   	if(aux->tipo==tipo){
		      return aux->ListaC.verificar(cedula);}
		    else aux=aux->siguiente;
		   }
    return false;
}

void listaDCalv::leerarchivo(string archivo){
	string linea;
    ifstream myfile (archivo.c_str());
    if (myfile.is_open())
    {
  	nodotipo* aux;
    while ( getline (myfile,linea) )
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
	    
	    aux=primero;
	    while(aux->siguiente!=primero) {
		   	if(aux->tipo==atributos[4]){
		        aux->ListaC.InsertarFinal(linea);
			    aux=aux->siguiente;}
		        else aux=aux->siguiente;
		   }
    }
    myfile.close();
	delete aux;
  }
  else cout << "Unable to open file"; 
}
