#include "lista.h"
#include "nodo.h"
#include <iostream>
#include <cstdlib>

using namespace std ;

lista::lista()
{
    tam=0;
    primero = NULL;
    actual = NULL;
}

void lista::insertar(nodo * n){

    if(buscar(n->valor))
    {
        cout<<"Ya se inserto: "<<n->valor<<endl;
    }else{
        if (primero == NULL){
        primero=n;
        actual=n;
    }
    else {
        actual->siguiente=n;
        actual=n;

    }
    actual->setPosicion(tam);
    tam ++;

    }
}

void lista::Pop_front(){
    if(!primero)return;
    nodo* temp = primero;
    primero = primero ->siguiente;
    delete temp;
    primero->setPosicion(0);
}

void lista::Pop_back(){
    if(!primero) return;
    if(primero==actual){
        delete primero;
        primero = actual =0;
    }
    nodo* temp = primero;
    nodo *eliminar;
    for( ; temp->siguiente!=actual;temp=temp->siguiente);
    delete actual;
    actual=temp;
    //temp->setPosicion(temp->posicion);
    while(temp->siguiente!=actual){
        temp=temp->siguiente;


    }
}

void lista::Push_back(nodo * n){
        if(buscar(n->valor))
    {
        cout<<"Ya se inserto: "<<n->valor<<endl;
    }else{
        if (primero == NULL){
        primero=n;
        actual=n;
    }
    else {
        actual->siguiente=n;
        actual=n;

    }
    actual->setPosicion(tam);
    tam ++;

    }
}
void lista::Push_back(int valor){
    nodo* temp = new nodo();
    temp->valor=valor;
    this->insertar(temp);
}

void lista::Push_front(nodo * n){
    if(buscar(n->valor))
    {
        cout<<"Ya se inserto: "<<n->valor<<endl;
    }else{
        if (primero == NULL){
        primero=n;
        actual=n;
    }
    else {
        n->siguiente=primero;
        primero=n;

    }
    primero->setPosicion(0);
    }

}

void lista::insertarAleatorio(int valor){
    int pos=rand()% this->tam;
    nodo* nodeValue =new nodo();
    nodeValue->valor =valor;
    if(pos==0){
        primero = nodeValue;
        nodeValue->setPosicion(0);
    }
    else {
        nodo* temp = primero;
        while(temp!=0){
            if(temp->siguiente->posicion==pos)
                {
                    nodeValue->siguiente = temp->siguiente;
                    temp->siguiente = nodeValue;
                    nodeValue->setPosicion(pos);
                    return;
                }
                temp = temp->siguiente;
        }
    }

}



void lista::insertar(int valor,int pos)
{
    if(pos>this->tam)
    {
        cout<<"No se puede insertar en la posicion: "<<pos<<endl;
        return;
    }
    else{
        cout<<"empezo insertar"<<endl;
        nodo* nodeValue = new nodo();
        nodeValue->valor = valor;


        if(pos==0){
            primero = nodeValue;
            nodeValue->setPosicion(0);
        }else{

            nodo* temp = primero;

            while(temp!=0)
            {

                cout<<"pos_actual "<<temp->siguiente->posicion<<endl;
                if(temp->siguiente->posicion==pos)
                {
                    nodeValue->siguiente = temp->siguiente;
                    temp->siguiente = nodeValue;
                    nodeValue->setPosicion(pos);
                    return;
                }
                temp = temp->siguiente;
            }

        }




    }
}

void lista::elimar(int valor){
    nodo *temp = primero;
    nodo *eliminar;
     while (temp != 0){
        if(temp->siguiente->valor==valor)
        {
            eliminar=temp->siguiente;
            temp->siguiente=eliminar->siguiente;
            delete eliminar;
            temp->setPosicion(temp->posicion);
            return;
        }

        temp =temp->siguiente;
     }
}


bool lista::buscar(int valor)
{
     nodo *temp = primero;
     while (temp != 0){
        if(temp->valor==valor)
        {
            return true;
        }

        temp =temp->siguiente;
    }
    return false;
}

bool lista::find1(int d,nodo **&p){
    p=&primero;
    while(*p){
        if(*p->valor==d)return 1;
        if((*p)->valor>d)return false;
        p=&(*p)->siguiente;
    }
    return false;
}

bool lista::buscar1(nodo * n){
   // nodo * n = primero;
    if(!n) return false;
//    if(n->valor==n) return true;
  //  buscar(n,n->siguiente);
}

void lista::mayor(){
    //assert(head==0);

//    nodo *tmp=primero->valor;


}

void lista::insertar(int valor)
{
    nodo* temp = new nodo();
    temp->valor=valor;

    this->insertar(temp);

}

/*void lista::interseccion(lista * mi_lista1,lista *mi_lista2){
    nodo*temp = primero;
    lista* mi_lista3 = new lista();
    for( ; temp;temp=temp->siguiente){
        if(mi_lista2->buscar(temp->valor==true))
            if(mi_lista3->buscar(temp->valor==false))
                insertar(temp->valor);
    }
    mostrar(mi_lista3);
}

void lista::unionrep(lista * mi_lista1,lista *mi_lista2){
    nodo*temp = primero;
    lista* mi_lista3 = new lista();
    for( ; temp;temp=temp->siguiente){
        if(mi_lista2->buscar(temp->valor==true))
            if(mi_lista3->buscar(temp->valor==false))
                insertar(temp->valor);
    }
    mostrar(mi_lista3);
}


}
*/
void lista::mostrar(){
    nodo *temp = primero;


    while (temp != 0){
        cout<<temp->valor<<"("<<temp->posicion<<")->";
        temp =temp->siguiente;
    }
    if(temp==0)
        cout<<"end"<<endl;
    delete temp;
}


