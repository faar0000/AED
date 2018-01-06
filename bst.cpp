#include <node.h>
#include <bst.h>
#include "iostream"

using namespace std;

template <typename T>
T Node<T>::getdato(){
    return this->m_dato;
}

template <typename T>
bool Bst<T>::find(T value, Node<T>**& p){
    p = &root;
    while ((*p)) {
        if((*p)->getdato() == value)
            return true;
        p = &(*p)->child[(*p)->getdato() < value];
    }
    return false;
}

template <typename T>
bool Bst<T>::add(T value){
    Node<T>** q;
    if(find(value, q))
        return false;
    *q = new Node<T>(value);
    return true;
}

template <typename T>
int Bst<T>::n_nodos(){
    int count = 0;
    if (root == NULL)
        return count;
    return n_nodos(root);
}
template <typename T>
int Bst<T>::n_nodos(Node<T> *p){
    if (!p){
        return 0;
    } else
        return 1 + n_nodos(p->child[0]) + n_nodos(p->child[1]);
}

template <typename T>
T Bst<T>::nodo_mayor(){
    Node<T>*p;
    p = root;
    if(!p)
        return 0;
    while (p->child[1]) {
        p = p->child[1];
        if(p->child[1] == NULL)
            return p->getdato();
    }
}

template <typename T>
T Bst<T>::padre(T nodo){
    Node<T>*p,*q;
    p = root;
    q = p;
    if(p->getdato() == nodo)
            return 0;
    p = p->child[p->getdato() < nodo];
    while (p){
        if(p->getdato() == nodo)
            return q->getdato();
        if(p == NULL)
            return q->getdato();
        else{
            q = p;
            p = p->child[p->getdato() < nodo];
        }
    }
    return 0;
}

template <typename T>
T Bst<T>::tio(T nodo){
    return hno(padre(nodo));
}

template <typename T>
T Bst<T>::hno(T nodo){
    Node<T>*p;
    p = root;
    while (p){
        if(p->getdato() == nodo)
            return p->getdato();
        if(p->child[0]->getdato() == nodo)
            return p->child[1]->getdato();
        if(p->child[1]->getdato() == nodo)
            return p->child[0]->getdato();
        p = p->child[p->getdato() < nodo];
    }
    return 0;
}

template <typename T>
int Bst<T>::findheight(){
    if (root == NULL)
        return 0;
    return findheight(root);
}

template <typename T>
int Bst<T>::findheight(Node<T> *p){
    int hleft = 0;
    int hright = 0;
    if (p->child[0])
        hleft = findheight(p->child[0]);
    if (p->child[1])
        hright = findheight(p->child[1]);
    if (hleft > hright)
        return hleft + 1;
    else
        return hright +1;
}

template <typename T>
void Bst<T>::show_tree(){
    int h = findheight();
    for (int i = 1; i <= h; i++){
        show_tree(root, i);
        std::cout << '\n';
    }
}

template <typename T>
void Bst<T>::show_tree(Node<T>* p,int h){
    if (!p)
        return;
    if (h == 1)
        std::cout << p->getdato() << '\t';
    else if (h > 1){
        show_tree(p->child[0], h-1);
        show_tree(p->child[1], h-1);
    }
}

template <typename T>
T Bst<T>::r_padre(T nodo){
    Node<T>* p;
    p = root;
    if(p->getdato() == nodo)
        return 0;
    return r_padre(p,nodo);
}

template <typename T>
T Bst<T>::r_padre(Node<T>* p,T nodo){

    if(p->child[0] != NULL && p->child[1] != NULL){
        if(p->child[0]->getdato() == nodo || p->child[1]->getdato() == nodo)
            return p->getdato();
        return r_padre(p->child[p->getdato() < nodo],nodo);
    }
    if(p->child[0] == NULL && p->child[1] != NULL){
        if(p->child[1]->getdato() == nodo)
            return p->getdato();
        return r_padre(p->child[1],nodo);
    }
    if(p->child[1] == NULL && p->child[0] != NULL){
        if(p->child[0]->getdato() == nodo)
            return p->getdato();
        return r_padre(p->child[0],nodo);
    }
    else
        return 0;
}

template <typename T>
T Bst<T>::r_tio(T nodo){
    return r_hno(r_padre(nodo));
}

template <typename T>
T Bst<T>::r_hno(T nodo){
    Node<T>* p;
    p = root;
    if(p->getdato() == nodo)
        return 0;
    return r_hno(p,nodo);
}

template <typename T>
T Bst<T>::r_hno(Node<T>*p,T nodo){
    if(p->child[0] == NULL || p->child[1] == NULL)
        return 0;
    if(p->child[0]->getdato() == nodo)
        return p->child[1]->getdato();
    if(p->child[1]->getdato() == nodo)
        return p->child[0]->getdato();
    else
        return r_hno(p->child[p->getdato() < nodo],nodo);
}
template <typename T>
void Bst<T>::printTree(){
    Node<T>* curPtr; //cursor to print items
    curPtr = root;
    //printTree_inorden(curPtr);
    printTree_preorden(curPtr);
    //printTree_postorden(curPtr);
}
template <typename T>
void Bst<T>::printTree_inorden( Node<T>* ptr ) {
    if(ptr) {
        printTree_inorden(ptr->child[0]);
            cout<<ptr->getdato()<<'\n';
        printTree_inorden(ptr->child[1]);
    }
}
template <typename T>
void Bst<T>::printTree_preorden( Node<T>* ptr ) {
    if(ptr) {
        cout<<ptr->getdato()<<'\n';
        printTree_preorden(ptr->child[0]);
        printTree_preorden(ptr->child[1]);
    }
}
template <typename T>
void Bst<T>::printTree_postorden( Node<T>* ptr ) {
    if(ptr) {
        printTree_postorden(ptr->child[0]);
        printTree_postorden(ptr->child[1]);
        cout<<ptr->getdato()<<'\n';
    }
}
