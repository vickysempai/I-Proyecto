#include <cstdlib>
#include <iostream>
#include "ListaDC.h"

int listaDC::largoLista()
{
    int cont=0;

    nodousuario* aux = primero;
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

void listaDC::InsertarInicio(string v)
{
  
   if (ListaVacia())
   {
     primero = new nodousuario(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     nodousuario* nuevo=new nodousuario (v);
     nuevo->siguiente=primero;
     nuevo->anterior= primero->anterior;
     primero->anterior->siguiente=nuevo;
     nuevo->siguiente->anterior=nuevo;
     primero= nuevo;
   }
}
 
void listaDC::InsertarFinal(string v)
{
   if (ListaVacia())
     {
     primero = new nodousuario(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     nodousuario* nuevo = new nodousuario(v);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}


void listaDC::InsertarPos(string v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodousuario(v);
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
             nodousuario* aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             nodousuario* nuevo= new nodousuario(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
       }
   }
}   

void listaDC::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        nodousuario* temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         nodousuario* aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         nodousuario* temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        nodousuario* temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        nodousuario* aux = primero->anterior;
        nodousuario* temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}

void listaDC:: borrarPosicion(int pos)
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
       nodousuario* aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       nodousuario* temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}

bool listaDC::verificar(string cedula)
{
   nodousuario* aux=primero;
   do{
    	cout<<aux->cedula<<"	"<<cedula<<endl;
      if(aux->cedula==cedula) return true;
      else aux = aux->siguiente;
     }while(aux!=primero);
     return false;
}   

void listaDC::Mostrar()
{
   nodousuario* aux=primero;
   do{
		cout<<aux->cedula<<"->";
		aux = aux->siguiente;
   }while(aux != primero);
   cout<<endl;
}   
void listaDC::leerarchivo(string archivo){
	string line;
  ifstream myfile (archivo.c_str());
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      InsertarFinal(line);
      
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  }
