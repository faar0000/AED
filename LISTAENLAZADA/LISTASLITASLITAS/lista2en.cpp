#include<iostream>

using namespace std;

template<class T>
class Nodo
{
     public:
        Nodo<T>  * m_pSig;
        Nodo<T>  * m_pPrev;
             T     m_Dato;
     public:
       Nodo(T d)
       {
          m_pSig=0;
          m_pPrev=0;
          m_Dato=d;
       }
};

template<class T>
class List_en
{
    typedef Nodo<T>  * pNodo;
    private:
        pNodo m_pHead;
        pNodo m_pLast;
    public:
        List_en()
        {
            m_pHead = 0;
            m_pLast =0;
        }

        void push_back(T d)
        {
            pNodo temp = new Nodo<T>(d);
            temp->m_pSig = NULL;
            temp->m_pPrev = NULL;
            temp->m_Dato = d;

            if (m_pHead == NULL) {
                m_pHead = temp;
            } else {
                m_pLast = m_pHead;
                while (m_pLast->m_pSig != NULL)
                    m_pLast = m_pLast->m_pSig;
                m_pLast->m_pSig = temp;
                temp->m_pPrev = m_pLast;
            }
        }

        void mostrar(){
            Nodo<T> *p = m_pHead;
            for(;p!=NULL;p=p->m_pSig){
                cout<<p->m_Dato<<" ";
            }
            cout<<endl;
        }



        bool buscar(T d){
            if(m_pHead=NULL)return false;
            Nodo<T>* temp = m_pHead;
            while (temp != 0){
                if(temp->m_Dato==d)
                {
                    return true;
                }

                temp =temp->m_pSig;
            }
            return false;
        }

        void eliprimero(){
            if(m_pHead=NULL)return;
            Nodo<T>* temp = m_pHead;
            if(temp->m_pSig==NULL){
                m_pHead = 0;
                m_pLast =0;
                delete temp;
            }
            else{


            }
        }

};

int main(){
    List_en<int> A;
    A.push_back(4);
    A.push_back(7);
    A.push_back(8);
    cout<<endl;
    A.buscar(7);
    A.push_front(20);
    A.mostrar();
    return 0;
}
