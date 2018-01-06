#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Nodo{
	public:
		T m_Dato;
		int fe;
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
class AVL{
	public:
		Nodo <T> * m_pRoot;
	public:
		AVL():m_pRoot(0){
		}
		bool find(T value,Nodo<T>**&p);
		bool add(T value);
		void add(T d,Nodo<T>*&p);
		void rdd(Nodo<T>*&p);
		void rii(Nodo<T>*&p);
		void rdi(Nodo<T>*&p);
		void rid(Nodo<T>*&p);
		void Inorden(Nodo<T>*r);
		void mostrar(Nodo<T>*arbol,int cont);

};

template<class T>
void AVL <T> :: mostrar(Nodo<T>*arbol,int cont){
	if(arbol == NULL){return;
	}
	else{
		mostrar(arbol->m_son[1],cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->m_Dato<<endl;
		mostrar(arbol->m_son[0],cont+1);
	}
}

template<class T>
void AVL<T>::Inorden(Nodo<T>*r){
    if(!r) return;
    Inorden(r->m_son[0]);
    cout<<r->m_Dato<<"-";
    Inorden(r->m_son[1]);
}


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
void AVL<T>::add(T d,Nodo<T>*&p){
    if(!p){
        p=new Nodo<T>(d);
        return;
    }
    if(p->m_Dato==d)return;
    add(d,p->m_son[p->m_Dato<d]);
    if(p->m_Dato<d)p->fe++;
    else p->fe--;
    switch(p->fe){
        case 0: return;
        case 2: if(p->m_son[1]->fe==1)rdd(p);else rdi(p);break;
        case -2:if(p->m_son[0]->fe==-1)rii(p);else rid(p);break;
    }
}

template<typename T>
void AVL<T>::rdd(Nodo<T> * & p){
    Nodo<T> * q = p->m_son[1];
    p->m_son[1] = q->m_son[0];
    q->m_son[0] = p;
    p->fe=0;
    q->fe=0;
    p=q;

}
template <typename T>
void AVL<T>::rii(Nodo<T>*&p){
    Nodo<T>*q=p->m_son[0];
    p->m_son[0]=q->m_son[1];
    q->m_son[1]=p;
    p->fe=0;
    q->fe=0;
    q=p;
}


template<typename T>
void AVL<T>::rdi(Nodo<T>*&p){
    Nodo<T>*q=p->m_son[1];
    Nodo<T>*r=q->m_son[0];
    p->m_son[1]=r->m_son[0];
    q->m_son[0]=r->m_son[1];
    r->m_son[1]=q;
    r->m_son[0]=p;
    switch (r->fe){
        case 0:p->fe=q->fe=0;break;
        case 1:p->fe=0;q->fe=-1;break;
        case -1:p->fe=1;q->fe=0;break;
    }
    p=r;
}


template<typename T>
void AVL<T>::rid(Nodo<T>*&p){
    Nodo<T>*q=p->m_son[0];
    Nodo<T>*r=q->m_son[1];
    p->m_son[0]=r->m_son[1];
    q->m_son[1]=r->m_son[0];
    r->m_son[1]=p;
    r->m_son[0]=q;
    switch (r->fe){
        case 0:p->fe=q->fe=0;break;
        case 1:p->fe=0;q->fe=-1;break;
        case -1:p->fe=1;q->fe=0;break;
    }
    p=r;
}

int main(){
    int contador=0;
    AVL<int> B;
    B.add(10,B.m_pRoot);
    B.add(20,B.m_pRoot);
    B.add(30,B.m_pRoot);
    B.add(40,B.m_pRoot);
    B.add(50,B.m_pRoot);
    B.add(60,B.m_pRoot);
    B.add(70,B.m_pRoot);
    cout<<endl;
    B.mostrar(B.m_pRoot,contador);
    cout<<endl;

    B.Inorden(B.m_pRoot);

}

