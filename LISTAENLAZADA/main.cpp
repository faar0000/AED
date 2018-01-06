#include "lista.h"

#include <iostream>

using namespace std;

int main (){




    nodo* A = new nodo();
    A->valor=10;
    cout<<A->valor<<endl;

    nodo* B = new nodo();
    B->valor=20;
    cout<<B->valor<<endl;

    nodo* C = new nodo();
    C->valor=30;
    cout<<C->valor<<endl;

    nodo* D = new nodo();
    D->valor=69;
    cout<<D->valor<<endl;
    cout<< "MI LISTA 1 "<<endl;

    lista* mi_lista = new lista();

    mi_lista->insertar(100);
    //mi_lista->insertar(A);
    mi_lista->insertar(B);
    mi_lista->insertar(50);
    mi_lista->insertar(C);
   // mi_lista->insertarAleatorio(2222);


    mi_lista->insertar(25,2);
   // mi_lista->mostrar();
    mi_lista->elimar(50);
   // mi_lista->mostrar();
    mi_lista->Push_front(A);
    mi_lista->Push_front(D);
    mi_lista->insertar(101);
    mi_lista->Push_back(150);
    //mi_lista->mostrar();
    mi_lista->Pop_front();
    mi_lista->mostrar();

    //OTRAAAAAAAAAAAAAAAAAA LISTA
    cout<< "MI LISTA 2 "<<endl;

    lista* mi_lista2 = new lista();
    mi_lista2->insertar(101);
    mi_lista2->insertar(150);
    mi_lista2->insertar(60);
    mi_lista2->mostrar();

//    mi_lista->interseccion(mi_lista,mi_lista2);




    cout<<"-------------------"<<endl;
   // cout<<mi_lista->buscar(59);
    //cout<<mi_lista->buscar(50);




    return 0;
}
