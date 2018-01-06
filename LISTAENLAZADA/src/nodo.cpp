#include "nodo.h"

nodo::nodo()
{
    valor = 0;
    siguiente = 0;
}

void nodo::setPosicion(int pos){
    if(this->siguiente==0)
    {
        this->posicion=pos;
    }else{
        this->posicion=pos;
        this->siguiente->setPosicion(this->posicion+1);
    }
}
