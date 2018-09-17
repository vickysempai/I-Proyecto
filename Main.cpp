#include <cstdlib>
#include "ListaDC.h"
#include "nodo.h"

using namespace std;

int main(int argc, char** argv) {
    listaDC lista;
    lista.InsertarFinal(12);
    lista.InsertarFinal(11);
    lista.Mostrar();
    

    return 0;
}

