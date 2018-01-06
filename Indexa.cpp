#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class Record
{
    private:
        char key;
        long int address;
    public:
        Record(char key_,long int address_){
            key=key_;
            address=address_;
        }
        Record(char key_){
            key=key_;
        }

};

template<class T>
class Nodo
{
     public:
        Nodo<T>  * m_pSig;
             T     m_Dato;
     public:
       Nodo(T d){

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
    bool find(T d,Nodo<T> **&p);
    bool add(T d);
    bool delete_(T d);
    void Indexar(char *filname);
    void Read(char *key,char *filename);
    void print();
};

template<class T>
bool List<T>::find(T d,Nodo<T> **&p){
    p = &m_pHead;
    while(*p){
        if((*p)->m_Dato==d) return true;
        if((*p)->m_Dato>d) return false;
        p=&(*p)->m_pSig;
    }
    return false;
}

template<class T>
bool List<T>::add(T d){
    Nodo<T> **q;
    if(!find(d,q)){
        Nodo<T> *Nuevo = new Nodo<T>(d);
        Nuevo->m_pSig=*q;
        *q=Nuevo;
        return true;
    }
    return false;
}

template<class T>
bool List<T>::delete_(T d){
    Nodo<T> **q;
    if(find(d,q)){
        Nodo<T> *temp =(*q);
        (*q)=(*q)->m_pSig;
        delete temp;
    }
}

template<class T>
void List<T>::print(){
    Nodo<T> *p = m_pHead;
    for(;p!=NULL;p=p->m_pSig){
        cout<<p->m_Dato<<" ";
    }
}

template<class T>
void List<T>::Indexar(char *filename)
{
    ifstream file(filename);
    char key[1000];
    long int address=0;
    char informacion[5000];
    while(!file.eof()){
        file.getline(key,100,'$');
        file.getline(informacion,5000,'@');
        Record R(key,address);
        add(R);
        address=address+strlen(key)+strlen(informacion)+3;
    }
}

template<class T>
void List<T>::Read(char *key,char *filename)
{
    Nodo<T> **p;
    if(find(Record(key),p)){
        char info[10000];
        long int address=(*p)->m_Dato.address;
        ifstream file(filename);
        file.seekg(ios::beg);
        file.seekg(address);
        file.getline(info,10000,'@');
    }

}


int main(){
    List<Record> A;
    A.Indexar([db.txt]);
    return 0;
}
