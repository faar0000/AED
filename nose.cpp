#include <iostream>
 using namespace std;

 template<class T>
 class Nodo{
     public:
        Nodo<T>  * m_pIz;
        Nodo<T>  * m_pDer;
             T     m_Dato;
     public:
       Nodo(T d){

          m_pDer=m_pIz=0;
          m_Dato=d;
       }
 };

 template<class T>
class SBT{
    public:
        Nodo<T>* m_pRoot;
    public:

        SBT()
        {
            m_pRoot=0;
        }
    void push(T d);
    bool find(T d,Nodo<T>**&p);
    void add1(T d, Nodo<T>*&p);
    bool add(T d);
    void mostrar(Nodo<T>*arbol,int cont);
    void mayor();
    void nodos(Nodo<T>*arbol,int lala);
    void hermano(T d);
    void tio(T d);
    void padre(T d);
};
template<class T>
void SBT<T>::push(T d){
    if(m_pRoot==NULL){
        m_pRoot= new Nodo<T>(d);
    }
    else{
        Nodo<T>*tmp1=m_pRoot;
        Nodo<T>*tmp2=m_pRoot;
        while(tmp2){
            if(d==tmp2->m_Dato){return;}
            tmp1=tmp2;
            if(d>tmp2->m_Dato){tmp2=tmp2->m_pDer;}
            else{tmp2=tmp2->m_pIz;}
        }
        Nodo<T>*Nuevo=new Nodo<T>(d);
        if(d<tmp1->m_Dato){tmp1->m_pIz=Nuevo;}
        else{tmp1->m_pDer=Nuevo;}
    }
}

template<class T>
bool SBT<T>::find(T d,Nodo<T>**&p){
    p=&m_pRoot;
    while(*p){
        if ((*p)->m_Dato==d){return true;}
        if((*p)->m_Dato>d){
            p=&((*p)->m_pIz);
        }
        else{
            p=&((*p)->m_pDer);
        }
    }
    return false;
}
template<class T>
void SBT<T>::hermano(T d){
    if(m_pRoot==NULL){return;}
    else{
        Nodo<T>*tmp1=m_pRoot;
        Nodo<T>*tmp2=m_pRoot;
        while(tmp2->m_Dato!=d){
            tmp1=tmp2;
            if(d>tmp2->m_Dato){
                    tmp2=tmp2->m_pDer;
            }
            else{
                    tmp2=tmp2->m_pIz;
            }
        }
        if(d>tmp1->m_Dato){
            tmp1=tmp1->m_pIz;
            cout<<"HERMANO: "<<tmp1->m_Dato<<endl;
        }
        else{
            tmp1=tmp1->m_pDer;
            cout<<"HERMANO: "<<tmp1->m_Dato<<endl;
        }

    }
}

template<class T>
void SBT<T>::tio(T d){

}



template<class T>
void SBT<T>::padre(T d){
    if(m_pRoot==NULL){return;}
    else{
        Nodo<T>*tmp1=m_pRoot;
        Nodo<T>*tmp2=m_pRoot;
        while(tmp2->m_Dato!=d){
            tmp1=tmp2;
            if(d>tmp2->m_Dato){
                    tmp2=tmp2->m_pDer;
            }
            else{
                    tmp2=tmp2->m_pIz;
            }
        }

        cout<<"PADRE: "<<tmp1->m_Dato<<endl;
    }
}

template<class T>
bool SBT<T>::add(T d){
    Nodo<T>**q;
    if(find(d,q))return false;
    *q=new Nodo<T>(d);
    return true;
}

template<class T>
void SBT<T>::mostrar(Nodo<T>*arbol,int cont){
    if(arbol=NULL){return;
    }
    else{
        mostrar(arbol->m_pDer,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"   ";
        }
        cout<<arbol->m_Dato<<endl;
        mostrar(arbol->m_pIz,cont+1);
    }

}

template<class T>
void SBT<T>::nodos(Nodo<T>*arbol,int lala){
    if(arbol=NULL){
            return;
    }
    else{
        nodos(arbol->m_pDer,lala+1);
        }
        nodos(arbol->m_pIz,lala+1);
    cout<<"NODOS: "<<lala<<endl;
    }

template<class T>
void SBT<T>::add1(T d, Nodo<T>*&p){
    if(!p){p=new Nodo<T>(d);return;}
    if(p->m_Dato==d)return;
    if(p->m_Dato>d)add1(d,p->m_pIz);
    else{
        add1(d,p->m_pDer);
    }
}

template<class T>
void SBT<T>::mayor(){
    Nodo<T>*tmp=m_pRoot;
    while(tmp->m_pDer!=NULL){
        tmp=tmp->m_pDer;
    }
    cout<<"MAYOR: "<<tmp->m_Dato<<endl;
}
int main(){
    SBT<int> A;
    int contador=0;

    int lala=0;
  /*  A.add(20);
    A.add(10);
    A.add(35);
    A.add(15);
    A.add(5);
   */
   A.add1(20,A.m_pRoot);
   A.add1(10,A.m_pRoot);
   A.add1(35,A.m_pRoot);
   A.add1(15,A.m_pRoot);
   A.add1(5,A.m_pRoot);
   //A.nodos(A.m_pRoot,lala);
   A.padre(35);
    A.hermano(35);
    A.mayor();
    A.mostrar(A.m_pRoot,contador);
    

}

