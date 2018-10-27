#include "ListaDoble.h"

listaD::~listaD()
{
   nodosupermercado* aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int listaD::largoLista(){
    int cont=0;

    nodosupermercado* aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaD::InsertarInicio(string v)
{
   if (ListaVacia())
     primero = new nodosupermercado(v);
   else
   {
     primero=new nodosupermercado (v,primero);
     primero->siguiente->anterior=primero;
   }
}
 
void listaD::InsertarFinal(string v)
{
   if (ListaVacia())
     primero = new nodosupermercado(v);
   else
     { nodosupermercado* aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodosupermercado(v);
        aux->siguiente->anterior=aux;       
      }    
}


void listaD::InsertarPos(string v,int pos)
{
   if (ListaVacia())
     primero = new nodosupermercado(v);
   else{
        if(pos <=1)
          InsertarInicio(v);    
        else
        {
             nodosupermercado* aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             nodosupermercado* nuevo= new nodosupermercado(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
        }
}
      
void listaD::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                nodosupermercado* aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              nodosupermercado* temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void listaD::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                nodosupermercado* aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}



void listaD:: borrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            nodosupermercado* aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            nodosupermercado* temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaD::Mostrar()
{
   nodosupermercado *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->codSuper << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}
void listaD::leerarchivo(string archivo){
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
