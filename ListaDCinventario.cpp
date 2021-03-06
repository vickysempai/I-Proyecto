#include "ListaDCinventario.h"

listaDCinventario::~listaDCinventario()
{
   nodoinventario* aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      primero->anterior=aux->anterior;
      aux->anterior->siguiente=primero;
      delete aux;
   }
   actual = NULL;
}


int listaDCinventario::largoLista()
{
    int cont=0;

    nodoinventario* aux = primero;
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

void listaDCinventario::InsertarInicio(string v)
{
  
   if (ListaVacia())
   {
     primero = new nodoinventario(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     nodoinventario* nuevo=new nodoinventario (v);
     nuevo->siguiente=primero;
     nuevo->anterior= primero->anterior;
     primero->anterior->siguiente=nuevo;
     nuevo->siguiente->anterior=nuevo;
     primero= nuevo;
   }
}
 
void listaDCinventario::InsertarFinal(string v)
{
   if (ListaVacia())
     {
     primero = new nodoinventario(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     nodoinventario* nuevo = new nodoinventario(v);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}


void listaDCinventario::InsertarPos(string v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodoinventario(v);
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
             nodoinventario* aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             nodoinventario* nuevo= new nodoinventario(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
       }
   }
}   

void listaDCinventario::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        nodoinventario* temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         nodoinventario* aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         nodoinventario* temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void listaDCinventario::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        nodoinventario* temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        nodoinventario* aux = primero->anterior;
        nodoinventario* temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}

void listaDCinventario:: borrarPosicion(int pos)
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
       nodoinventario* aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       nodoinventario* temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}

void listaDCinventario::Mostrar()
{
   nodoinventario* aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout <<"super = "<<aux->CodSuper<<"		CodProducto = "<<aux->CodProducto<<"		nombre = "<<aux->Nombre<< "-> "<<endl;
      aux = aux->siguiente;
     }
}
void listaDCinventario::consultarprecio(string codigo){
	nodoinventario* aux=primero;
	while(aux->siguiente!=primero)
     {             
      if(codigo==aux->CodProducto){
	  cout<<aux->Nombre<<"		"<<aux->PrecioUnitario<<endl;
	  break;
	  }
	  else aux=aux->siguiente;
      
     }
     
}
void listaDCinventario::leerarchivo(string archivo){
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
