#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class BinomialNode{
    public:
        int grado;
        T m_dato;
        vector<BinomialNode<T> *> m_hijos;
        BinomialNode<T>* m_padre;
        BinomialNode<T>* pMin;
    public:
        BinomialNode(T d){
            grado=0;
            m_dato=d;
        }
};

template <class T>
class BinomialHeap{
    public:
        vector<BinomialNode<T>*> roots;
        BinomialNode<T>* pMin;
    public:
        BinomialHeap(){
            pMin=0;
        };
        void insert_(T d);
        void merge_();
        void actmin();
        void swap_(BinomialNode<T> *&A,BinomialNode<T> *&B);
        void Sort_k();
        void delete_(BinomialNode<T>*p);
        void deletemin();
        void find_(BinomialNode<T>*p);
        void print(vector<BinomialNode<T>*> A);
        void decrease_key(BinomialNode<T>*p);
};

template <class T>
void BinomialHeap<T>::insert_(T d){
    roots.insert(roots.begin(),new BinomialNode<T>(d));
    merge_();
    actmin();
}

template<class T>
void BinomialHeap<T>::swap_(BinomialNode<T> *&A,BinomialNode<T> *&B){
    BinomialNode<T> *C;
    C=A;
    A=B;
    B=C;
}


template<class T>
void BinomialHeap<T>::deletemin(){
    typename vector<BinomialNode<T>*>::iterator It;
    It=pMin->m_hijos.begin();
    for( ; It!=pMin->m_hijos.end();It++){
        roots.push_back(*It);
    }
    roots.erase(std::remove(roots.begin(), roots.end(), pMin), roots.end());
    Sort_k();
    actmin();
    merge_();

}

template<class T>
void BinomialHeap<T>::decrease_key(BinomialNode<T>* p){
    actmin();
    p->dato=pMin->dato-1;
    while(p->dato<p->m_padre->dato){
        swap_(p->m_Padre,p);
    }

}

template <class T>
void BinomialHeap<T>::Sort_k(){
     for(int i=0;i<roots.size();i++){
                    for(int j=0;j<roots.size()-1;j++){
                        if(roots[i]->grado < roots[j]->grado){
                            swap_(roots[i],roots[j]);
                        }
                    }
                }
}

template<class T>
void BinomialHeap<T>::actmin(){
    pMin=roots[0];
    for(int i=0;i<roots.size()-1;i++){
        if(pMin->m_dato>roots[i+1]->m_dato){
            pMin=roots[i+1];
        }
    }
}

template <class T>
void BinomialHeap<T>::merge_(){
    if(roots.size()<2)
            return;
    int i=0;
    while(i<roots.size()-1){
        if(roots.size()<2)
            return;
        if(roots[i]->grado==roots[i+1]->grado){
            if(roots[i]->m_dato < roots[i+1]->m_dato){
                roots[i+1]->m_padre= roots[i];
                (roots[i]->m_hijos).insert(roots[i]->m_hijos.begin(),roots[i+1]);
                roots[i]->grado=roots[i]->grado+1;
               // pMin=roots[i];
                roots.erase(std::remove(roots.begin(), roots.end(), roots[i+1]), roots.end());
            }
            else{
                roots[i]->m_padre= roots[i+1];
                (roots[i+1]->m_hijos).insert(roots[i+1]->m_hijos.begin(),roots[i]);
                roots[i+1]->grado=roots[i+1]->grado+1;
               // pMin=roots[i+1];
                roots.erase(std::remove(roots.begin(), roots.end(), roots[i]), roots.end());
            }
            i=0;
        }
        else{
            i++;
        }
        Sort_k();
    }
}

template <class T>
void BinomialHeap<T>:: print(vector<BinomialNode<T>*> A){
    if(A.empty()){return;}
    for(int i=0;i<A.size();i++){
        cout<<A[i]->m_dato<<"-grado->"<<A[i]->grado<<endl;
    }
    cout<<"MIN: "<<pMin->m_dato;
}


template<class T>
void BinomialHeap<T>::delete_(BinomialNode<T>*p){
    //find_(p->m_dato);
    decrease_key(p,pMin->dato--);
    deletemin();
    merge_();
}


int main(){
    BinomialHeap<int> Bh;
  //  Bh.insert_(1);
    Bh.insert_(2);
    Bh.insert_(3);
    Bh.insert_(4);
    Bh.insert_(5);
   // Bh.insert_(6);
    Bh.insert_(7);
    Bh.insert_(23);
    Bh.insert_(15);
    Bh.print(Bh.roots);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"OTRO:  "<<endl;
    cout<<endl;

    Bh.deletemin();

    Bh.print(Bh.roots);
    //Bh.decrease_key();
    return 0;
}


