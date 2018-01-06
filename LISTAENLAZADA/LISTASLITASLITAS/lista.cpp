#include<iostream>

using namespace std;

template<class T>
class Record
{
    public:
         char key;
         long int address;
};

template<class T>
class Nodo
{
     public:
        Nodo<T>  * m_pSig;
             T     m_Dato;
     public:
       Nodo(T d)
       {
          m_pSig=0;
          m_Dato=d;
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

      void push_front(T d)
      {
           pNodo pNuevo   =  new Nodo<T>(d);
           if ( !m_pHead )
				m_pHead = m_pLast = pNuevo;
           else
			{
                pNuevo->m_pSig = m_pHead;
				m_pHead = pNuevo;
            }
      }

    void

    void pop_front(){
	  if(!m_pHead) return;
      pNodo temp = m_pHead;
      m_pHead = m_pHead->m_pSig;
      delete temp;
    }
	void pop_back()
   {
		if(!m_pHead) return;
		if(m_pHead == m_pLast)
		{
		  delete m_pHead;
		  m_pHead = m_pLast =0;
		}
		pNodo tmp = m_pHead;
		for(  ; tmp->m_pSig!=m_pLast; tmp = tmp->m_pSig);
		delete m_pLast;
		m_pLast = tmp;
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


    void eliminar(T d){//Funcion booleana que recibe un dato a eliminar
        Nodo<T>**q;//Un puntero que apunta a otro puntero que apunta a la direccion de q
        if(find1(d,q)){//Se llama a la funcion Find con el valor d , lo encuentra entra al bucle
            Nodo<T> *tmp=*q;//Se crea un puntero temporal que es igual al contenido de q(temporal apunta al nodo con valor d)
            *q=(*q)->m_pSig;//q ,que guarda la dirrecion que contiene el nodo siguiente, ahora sera el siguiente de ese.
            delete tmp;//se elimina el temporal que apuntaba al d
        }
    }

   void Add(T d, Nodo<T> * & p)
   {
        if(!p) {p = new Nodo<T>(d); return;}
        Add(d, p->m_pSig);
   }
};

int main()
{
    List<int>  A;
    A.Add1(2);
    A.Add1(69);
    A.Add1(10);

    A.mostrar();
    //A.find1();
    cout<<endl;
    A.eliminar(10);
    A.eliminar(69);
    A.mostrar();

    int s=8;
    return 1;
}


