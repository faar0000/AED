#include<iostream>

using namespace std;



template<class T>
class Nodo
{
     public:
        Nodo<T>  * m_pSig;
             T     m_Dato;
            int m_K;
             T hijos[100];
     public:
       Nodo(T d)
       {
          m_pSig=0;
          m_Dato=d;
          m_K=0;
          hijos[0]=0;
       }
};

template<class T>
class List
{
    typedef Nodo<T>  * pNodo;
    private:
       pNodo m_pHead;
       pNodo m_pLast;
    public:
       List()
       {
         m_pHead = 0;
         m_pLast =0;
       }

        void mostrar(){
        pNodo temp = m_pHead;
        while(temp!=0){
            cout<<temp->m_Dato<<" -> ";
            temp=temp->m_pSig;
        }
        delete temp;
        }

        bool find1(T d,Nodo<T>**&p){//Funcion booleana que recibe un puntero que apunta a un puntero que apunta a la direccion de P
        p=&m_pHead;//P va a guardar la direccion  del puntero Head(esto para recorrer la lista)
        while(*p){//Mientras exsita un nodo
            if((*p)->m_Dato==d)return 1;//Si el valor de *P es igual al d retorna 1
            if((*p)->m_Dato>d)return false;//Si el valor de *P es mayor a d(Se asume que es una lista ordenada) , retorna falso.
            p=&(*p)->m_pSig;//Ahora p guardara la direccion del nodo siguiente de p.
        }               //La funcion al encontrar el valor,en p guarda la direccion que contiene el nodo siguiente ,en el nodo de menor valor que d.
        return false;//Si no encuentra el dato retorna falso.
        }


        bool Add1(T d){//Funcion booleana que recibe un dato.
        Nodo<T>**q;//Un puntero que apunta a otro puntero que apunta a la direccion de q
        if(!find1(d,q)){//Se llama a la funcion Find con el valor d , lo encuentra entra al bucle
            Nodo<T>*Nuevo=new Nodo<T>(d);//Se crea un nuevo nodo con el valor d, que es apuntado por un puntero nuevo
            Nuevo->m_pSig=*q;//El puntero siguiente del nuevo nodo sera q ,que guarda la dirrecion que contiene el nodo siguiente,
            *q=Nuevo;//El contenido de q que es el que apunta al siguiente nodo , ahora guardara al nuevo nodo (apunta al nuevo nodo)
            return true;//retorna falso al crear el nuevo nodo
        }
        return false;// retorna falso si no lo añade (puede ser un valor repetido)

    }
};
int main()
{
    List<int>  A;
    A.Add1(2);
    A.Add1(69);
    A.Add1(10);


    A.mostrar();
    return 0;
}
