#include <iostream>
 using namespace std;

 template<class T>
 class Nodo{
     public:
        Nodo<T>  * m_pAnt;
             T     m_Dato;
     public:
       Nodo(T d){

          m_pAnt=0;
          m_Dato=d;
       }
 };
template<class T>
class Cola{
    private:
        Nodo<T>* m_pFirst;
    public:
        Cola()
        {
            m_pFirst=0;
        }
    void push(T d);
    void pop();
    bool isEmpty();
    void front1();
    void print();
};
template<class T>
void Cola<T>::print(){
        Nodo<T>* temp=m_pFirst;
        while(temp!=0){
            cout<<temp->m_Dato<<" -> ";
            temp=temp->m_pAnt;
        }
        delete temp;
}

template<class T>
void Cola<T>::push(T d){
    Nodo<T>* pNuevo=new Nodo<T>(d);
    if(isEmpty()){
        m_pFirst=pNuevo;
    }
    else{
        pNuevo->m_pAnt=m_pFirst;
        m_pFirst=pNuevo;
    }
}

template<class T>
bool Cola<T>::isEmpty(){
    return m_pFirst==0;
}

template<class T>
void Cola<T>::front1(){
    cout<<"Primero: "<<m_pFirst->m_Dato;
}
template<class T>
void Cola<T>::pop(){
    if(!isEmpty){
        Nodo<T>* tmp=m_pFirst;
        m_pFirst=m_pFirst->m_pAnt;
        delete tmp;
    }
}

int main(){
    Cola<int> A;
    A.push(2);
    A.push(10);
    A.print();
    cout<<endl;
    A.front1();

}
