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
class Stack{
    private:
        Nodo<T>* m_pTope;
    public:
        Stack()
        {
            m_pTope=0;
        }
    void push(T d);
    void pop();
    bool isEmpty();
    void print();
    void top();
};

template<class T>
void Stack<T>::top(){
    cout<<"Tope: "<<m_pTope->m_Dato;
}

template<class T>
void Stack<T>::print(){
        Nodo<T>* temp=m_pTope;
        while(temp!=0){
            cout<<temp->m_Dato<<" -> ";
            temp=temp->m_pAnt;
        }
        delete temp;
}

template<class T>
void Stack<T>::push(T d){
    Nodo<T>* pNuevo=new Nodo<T>(d);
    if(isEmpty()){
        m_pTope=pNuevo;
    }
    else{
        pNuevo->m_pAnt=m_pTope;
        m_pTope=pNuevo;
    }
}

template<class T>
void Stack<T>::pop(){
    if(!isEmpty){
        Nodo<T>* tmp=m_pTope;
        m_pTope=m_pTope->m_pAnt;
        delete tmp;
    }
}

template<class T>
bool Stack<T>::isEmpty(){
    return m_pTope==0;
}

int main(){
    Stack<int> pila;
    pila.push(2);
    pila.push(10);
    pila.print();
    cout<<endl;
    pila.top();


}
