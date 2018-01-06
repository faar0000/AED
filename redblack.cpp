
#include "iostream"

using namespace std;

#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Nodo{
	public:
		T m_Dato;
		int fe;
		bool color;
		Nodo<T> * m_son[2];
	public:
	Nodo(){
		m_son[0] = m_son[1] = 0;
	}
	Nodo(T d){
	    fe=0;
		m_Dato = d;
		m_son[0] = m_son[1] = 0;
	}
};
template<class T>
class RB{
    public:
		Nodo <T> * m_pRoot;
    public:
		SBT():m_pRoot(0){
		}
		bool find(T value,Nodo<T>**&p);
		bool add(T value);




};

template <typename T>
bool AVL<T>::find(T value, Nodo<T>**& p){
    p = &m_pRoot;
    while ((*p)) {
        if((*p)->m_Dato== value)
            return true;
        p = &(*p)->m_son[(*p)->m_Dato< value];
    }
    return false;
}

template <typename T>
bool AVL<T>::add(T value){
    Nodo<T>** q;
    if(find(value, q))
        return false;
    *q = new Nodo<T>(value);
    return true;
}

template <typename T>
T AVL<T>::padre(T nodo){
    Nodo<T>*p,*q;
    p = m_pRoot;
    q = p;
    if(p->m_Dato== nodo)
            return 0;
    p = p->m_son[p->m_Dato < nodo];
    while (p){
        if(p->m_Dato == nodo)
            return q->m_Dato;
        if(p == NULL)
            return q->m_Dato;
        else{
            q = p;
            p = p->m_son[p->m_Dato < nodo];
        }
    }
    return 0;
}
template <typename T>
T AVL<T>::tio(T nodo){
    return hermano(padre(nodo));
}

template <typename T>
T AVL<T>::hermano(T nodo){
    Nodo<T>*p;
    p = m_pRoot;
    while (p){
        if(p->m_Dato == nodo)
            return p->m_Dato;
        if(p->m_son[0]->m_Dato == nodo)
            return p->m_son[1]->m_Dato;
        if(p->m_son[1]->m_Dato == nodo)
            return p->m_son[0]->m_Dato;
        p = p->m_son[p->m_Dato < nodo];
    }
    return 0;
}

