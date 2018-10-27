#include "listasimple.h"
using namespace std;
lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int lista::largoLista(){
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

void lista::InsertarInicio(string v)
{
   if (ListaVacia())
     primero = new nodociudad(v);
   else
     primero=new nodociudad(v,primero);
}
 
void lista::InsertarFinal(string v)
{
   if (ListaVacia())
     primero = new nodociudad(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodociudad(v);
      }    
}


void lista::InsertarPos(string v,int pos)
{
   if (ListaVacia())
     primero = new nodociudad(v);
   else{
        if(pos <=1){
          pnodo nuevo = new nodociudad(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodociudad(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
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



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodociudad *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->ciudad << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}
void lista::Buscar(string numero){
    if(ListaVacia())
              cout << "Lista vacia" <<endl;
    else{
        pnodo aux;
        aux = primero;
        while(aux!=NULL){
            if (numero==aux->codigo){
                cout << "el numero : "<<numero<<" SI se encuentra en la lista" <<endl;
                aux=aux->siguiente;
                return;
            }
            else
                aux=aux->siguiente;
            }
        cout << "el numero : "<<numero<<" NO se encuentra en la lista" <<endl;
    }
}

void lista::leerarchivo(string archivo){
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
/*
void lista::Buscar(string numero, int pos){
    if(ListaVacia())
              cout << "Lista vacia" <<endl;
    else{
        pnodo aux;
        aux = primero;
        int numero_nodo=0;
        while(aux!=NULL){
            numero_nodo++;
            if(numero_nodo==pos){
                if (numero==aux->codigo){
                    cout << "el numero : "<<numero<<" SI se encuentra en la posicion" <<endl;
                    aux=aux->siguiente;
                    return;
                }
            }
            else
                aux=aux->siguiente;
            }
        cout << "el numero : "<<numero<<" NO se encuentra en la posicion" <<endl;
    }
}
int Largo(int numero){
    int cont=0;
    while(numero!=0){
        cont++;
        numero=numero/10;
    }
    return cont;
}

int lista::GetCodigo(int pos){
	if (ListaVacia()||(largoLista()<=pos))
            cout<<"lista vacia o fuera de rango"<<endl;
	else{
		int cont=0;
    	pnodo aux= primero;
    	while(cont!= pos){
            cont++;
            aux=aux->siguiente;
    	}
    	return aux->codigo;            
	}
}*/

