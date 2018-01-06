#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Nodo{
	public:
		T m_Dato;
		Nodo<T> * m_pIzq;
		Nodo<T> * m_pDer;
	public:
	Nodo(){
		m_pIzq = m_pDer = 0;
	}
	Nodo(T d){
		m_Dato = d;
		m_pIzq = m_pDer = 0;
	}
};

template<class T>
class AVL{
	public:
		Nodo <T> * m_pRoot;
	public:
		AVL():m_pRoot(0){
		}
		void SDF();
		bool find_hoja(T d);
		bool find (T d, Nodo<T>**&p);
};


template<class T>
void AVL<T>::SDF(){
    Nodo<T>*p=m_pRoot;
    stack<Nodo<T>*> = Pila;
    Pila.push(p);
    while(!Pila.IsEmpty()){
        Nodo<T>*q=Pila.top();
        *Pila.pop();
        cout<<q->m_Dato;
        if(q->m_pIzq) Pila.push(q->m_pIzq);
        if(q->m_pDer) Pila.push(q->m_pDer);
    }
}

bool AVL<T> :: find(T d , Nodo<T> **&p){
	p=&m_pRoot;
	while(*p){
		if((*p)->m_Dato == d)return true;
		if ((*p)->m_Dato > d){
			p=&((*p)->m_pIzq);
		}
		else{
			p=&((*p)->m_pDer);
		}
	}
	return false;
}



template <class T>
bool AVL<T>::find_hoja(){
    Nodo<T>**q;
    if(find(d,q)){
        if(!(*q)->m_pIzq&&!(*q)->m_pDer){
            delete*q;
            *q=0;
        }
    }
}

