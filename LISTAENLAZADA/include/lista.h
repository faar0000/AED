#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"


class lista
{
    public:
        lista();
        int tam;
        void insertar(nodo* n);
        void insertar(int valor);
        void insertar(int valor,int pos);
        void insertarAleatorio(int valor);
        void elimar(int valor);
        void mayor();
        void Pop_front();
        void Pop_back();
        void Push_back(nodo* n);
        void Push_back(int valor);
        void Push_front(nodo* n);
        bool buscar(int valor);
        bool buscar1(nodo*n);
        bool find1(int d,nodo ** &p);
        //void interseccion(lista * mi_lista1,lista *mi_lista2);
        //void unionrep(lista * mi_lista1,lista *mi_lista2);
        void mostrar();
        nodo * primero;
        nodo * actual;
    protected:
    private:
};

#endif // LISTA_H
