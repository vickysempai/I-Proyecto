#include "ListaDoble.h"

int listaD::largoLista(){
    int cont=0;

    pnodo aux;
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
     { pnodo aux = primero;
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
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodosupermercado(v);
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

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodo temp = aux->siguiente;
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

                pnodo aux = primero;
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
            pnodo aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
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
