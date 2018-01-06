#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Record
{
    private:
        string key;
        long int address;
    public:
        Record(){
            key="";
            address=0;
        }
        Record(string key_,long int address_){
            key=key_;
            address=address_;
        }
        string get_key(){return key;}
        long int get_address(){return address;}
};

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
          m_pSig=NULL;
          m_pPrev=NULL;
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
            m_pHead = NULL;
            m_pLast =NULL;
        }

        pNodo get_pHead(){return m_pHead;}
        pNodo get_pLast(){return m_pLast;}
        void push_back(T d)
        {
            pNodo temp = new Nodo<T>(d);
            if (m_pHead == NULL) {
                m_pHead = temp;
            }else{
                m_pLast = m_pHead;
                while (m_pLast->m_pSig != NULL)
                    m_pLast = m_pLast->m_pSig;
                m_pLast->m_pSig = temp;
                temp->m_pPrev = m_pLast;
            }
        }

        bool find(string d,Nodo<T> **&p)
        {
            p = &m_pHead;

            while(*p)
            {
                if(((*p)->m_Dato).get_key()==d)
                {
                    return true;
                }
                p=&(*p)->m_pSig;
            }
            return false;
        }

        void Indexar(ifstream &file){

            char key[1000];
            long int address=0;
            char informacion[50000];
                while(!file.eof()){
                    stringstream ss;
                    string s;
                    file.getline(key,100,'$');
                    file.getline(informacion,50000,'@');
                    ss<<key;
                    ss>>s;
                    Record R(s,address);
                    push_back(R);
                    address=address+strlen(key)+strlen(informacion)+3;
                }
        }

        void Leer(string key_,ifstream &file)
        {
            Nodo<T> **p;
            if(find(key_,p)){
                char informacion[50000];
                long int address=((*p)->m_Dato).get_address();
                file.seekg(address);
                file.getline(informacion,50000,'@');
                cout<<informacion<<endl;
            }
            else{
                cout<<"error"<<endl;
            }
        }

        void Print()
        {
            int i=0;
            Nodo<Record> *p = m_pHead;
            for(;p!=m_pLast->m_pSig;p=p->m_pSig){
                i++;
                cout<<i<<"-"<<(p->m_Dato).get_key()<<endl;
            }
        }
        void primero(){
            cout<<"Primera enfermedad: "<<get_pHead()->m_Dato.get_key()<<endl;
        }
        void ultimo(){
            cout<<"Ultima enfermadad: "<<get_pLast()->m_Dato.get_key()<<endl;
        }
};


int main()
{
    ifstream file("db.txt");
    ifstream file2("db.txt");
    List<Record> A;
    A.Indexar(file);


    A.Print();
    //A.Leer("sida",file2);
    A.primero();
    //cout<<"\n"<<A.get_pHead()->m_Dato.get_key()<<endl;
    //cout<<A.get_pLast()->m_Dato.get_key()<<endl;
    A.ultimo();
    cout<<endl;
    A.Leer("sida",file2);
    A.Leer("asma",file2);
    return 0;
}

