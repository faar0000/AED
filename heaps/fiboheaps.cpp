#include <iostream>
#include <stack>
#include <list>

using namespace std;

template <class T>
class BinomialNode{
	public:
	    int grado;
		T m_dato;
		bool color;
        list<BinomialNode<T>*> m_hijos;
        BinomialNode<T>* m_padre;
	public:
        BinomialNode(T d){
            grado=0;
            m_dato=d;
            color=0;
        }
        int get_grado(){return grado;}
};

template <class T>
class BinomialHeap{
        public:
        list<BinomialNode<T>*> roots;
    public:
        BinomialHeap(){};
        void insert_(T d);
        void union_( BinomialNode<T> *p, BinomialNode<T> *q );
        void delete_min();
        void delete_(BinomialNode<T> *p);
        void decrease_key();
        void swap_(BinomialNode<T> *&A,BinomialNode<T> *&B);
        void Sort_k();
        void merge_();
        void printroots();
        void print(list<BinomialNode<T>*> A);
};


template<class T>
void BinomialHeap<T>::print(list<BinomialNode<T>*> A){
    if(A.empty()){return;}
    typename list<BinomialNode<T>*>::iterator It;
    for(It=A.begin();It!=A.end();It++){
        cout<<" raiz:"<<(*It)->m_dato<<"-";
    }
}

template<class T>
void BinomialHeap<T>::insert_(T d){
    roots.push_front(new BinomialNode<T>(d));
}

template<class T>
void BinomialHeap<T>::swap_(BinomialNode<T> *&A,BinomialNode<T> *&B){
    BinomialNode<T> *C;
    C=A;
    A=B;
    B=C;
}

template<class T>
void BinomialHeap<T>::merge_(){
    typename list<BinomialNode<T>*>::iterator it =roots.begin();
    typename vector<BinomialNode<T>*> v(log(roots.size()));
    for(; it!=roots.end();it++){
        int p=v[(it*)->grado];
        if(v[p]==0){
            v[p]=*it;
        }
        else{
            int q=union_((*it),v[p])
            v[p]=0;
            v[q->grado];

        }
    }

}

template<class T>
void BinomialHeap<T>::union_(BinomialNode<T>*p,BinomialNode<T>*q){
    typename list<BinomialNode<T>*>::iterator It;
    if(p->m_dato<q->m_dato){
        p->m_hijos.push_front(q);
        roots.remove(q);
        p->grado++;
    }
    else{
        q->m_hijos.push_front(p);
        roots.remove(p);
        q->grado++;
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
void BinomialHeap<T>::decrease_key(BinomialNode<T>* p){
    actmin();
    p->dato=pMin->dato-1;
    while(p->dato<p->m_padre->dato){
        swap_(p->m_Padre,p);
    }

}



int main(){
    BinomialHeap<int> A;
    A.insert_(1);
    A.insert_(2);
   // A.insert_(3);
    //A.insert_(4);
    //A.insert_(5);
   // A.print(A.roots);
    return 0;
}
