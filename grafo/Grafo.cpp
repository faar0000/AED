#include "lista.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

template <class V,class E>
class vertex;

template<class V,class E>
class arista {
public:
  E m_dista;
  vertex<V,E> m_destino;
public:
  arista();
  arista (E d);
  E get_distancia(){return m_dista;}
  bool operator==(const arista<V,E> &a){
    return m_dista==a.m_dista;}
  bool operator>(const arista<V,E> &a){
    return m_dista>a.m_dista;}
  bool operator<(const arista<V,E> &a){
    return m_dista<a.m_dista;}
  friend std::ostream& operator<<(std::ostream &out,const arista<V,E> &a){
    out<<a.m_dista;
    return out;}
};
template<class V,class E>
arista<V,E>::arista(){
  this->m_dista=0;
}
template<class V,class E>
arista<V,E>::arista(E d){
  this->m_dista=d;
}

template<class V,class E>
class vertex {
public:
  List<arista<V,E>> m_aristas;
  V m_dato;
public:
  vertex (){};
  vertex (V d);
  bool operator == (const vertex<V,E> &v) const{
    return v.m_dato == m_dato;}
  bool operator > (const vertex<V,E> &v) const{
    return v.m_dato > m_dato;}
  bool operator < (const vertex<V,E> &v) const{
    return v.m_dato < m_dato;}
  friend std::ostream& operator<<(std::ostream &out,const vertex<V,E> &v){
    out<<v.m_dato;
    return out;}
};

template<class V,class E>
vertex<V,E>::vertex(V d){
  m_dato=d;
  m_aristas;
}



template<class V,class E>
class Graph
{
private:
    List<vertex<V,E>> m_g;
public:
    Graph(){};
    void add_vertex(V v1){
        m_g.add(vertex<V,E>(v1));
    }
    bool add_arista(V v1,V v2,E A){
        Nodo<vertex<V,E>> **p;
        Nodo<vertex<V,E>> **q;
        bool o1=m_g.find(vertex<V,E>(v1),p);
        bool o2=m_g.find(vertex<V,E>(v2),q);
        if(o1==true && o2==true){
            arista<V,E> ari=arista<V,E>(A);
            ari.m_destino=(*q)->m_Dato;
            ((*p)->m_Dato.m_aristas).add(ari);
            return true;
        }
        return false;
    }
    void GraphViz(){
        ofstream archivo;
        archivo.open("grafo.txt");
        archivo<<"digraph Grafo {"<<endl;
        if(!m_g.is_empty()){
            Nodo<vertex<V,E>> *temp;
            temp=m_g.m_pHead;
            while(temp!=NULL){
                archivo<<(temp->m_Dato).m_dato<<"[label="<<"\""<<(temp->m_Dato).m_dato<<"\""<<"]"<<endl;
                temp=temp->m_pSig;
            }
            temp=m_g.m_pHead;
            while(temp!=NULL){
                Nodo<vertex<V,E>> **p;
                bool o1=m_g.find(vertex<V,E>((temp->m_Dato).m_dato),p);
                    if(o1){
                            List<arista<V,E>> temp2;
                            Nodo<arista<V,E>> *temp3;
                            temp2=((*p)->m_Dato.m_aristas);
                            temp3=temp2.m_pHead;
                            while(temp3!=temp2.m_pLast){
                                archivo<<" "<<(temp->m_Dato).m_dato<<" -> "<<((temp3->m_Dato).m_destino).m_dato<<"[label="<<"\""
                                <<(temp3->m_Dato).m_dista<<"\""<<",weight="<<"\""<<(temp3->m_Dato).m_dista<<"\""<<" color=\"green\""<<"]"<<endl;
                                temp3=temp3->m_pSig;
                            }
                    }
                temp=temp->m_pSig;
            }
        }
        archivo<<"}"<<endl;
        archivo.close();
        string comando="dot -Tpng Grafo.txt -o Grafo.png";
        system(comando.c_str());
    }

    void copy_(Matriz<int> G,int O,vector<int>d){
        for(i=0;i<;i++){

        }
    }

    vector<int> Dijkstra(Graph<V,E> D,V begin, V end){
        List<vertex<V,E>> temp;
        List<vertex<V,E>> temp2;
        Nodo<vertex<V,E>> *temp1;
        temp=D.m_g;
        temp1=temp.m_pHead;
        int FIL=temp.size();
        Matrix<etiqueta<V,E>> M(FIL,FIL);
        etiqueta<V,E> A(((temp.m_pHead)->m_Dato.m_dato),'A');
        int j=0;
        while(temp1!=NULL){
            Nodo<arista<V,E>>*temp3;
            temp2=temp1->m_Dato.m_aristas;
            temp3=temp2.m_pHead;
            while(temp3!=NULL){

            }
        }

        vector<int> s(G.fil());
        vector<int> d(G.fil());
        s[O]=1;
        copy_(G,O,d);
        int N=1;
        while(N<G.fil()){
            int se= Getmin(d,s);
            s[se]=1; N++;
            for(int i=0;i<n;i++){
                if(s[i]==0){
                    d[i]=min(d[i],d[se]+M[se][i]);
                }
            }
        }
        return d;
}
};


int main(){
    Graph<int,int> A;
    A.add_vertex(1);
    A.add_vertex(2);
    A.add_vertex(3);
    A.add_vertex(10);
    A.add_vertex(11);
    A.add_vertex(12);
    A.add_vertex(13);
    A.add_vertex(3);
    A.add_arista(13,1,55);
    A.add_arista(12,11,3);
    A.add_arista(3,13,9);
    A.add_arista(1,3,15);
    A.add_arista(3,11,12);
    A.add_arista(11,12,90);
    A.add_arista(5,10,70);
    A.add_arista(10,11,45);
    A.add_arista(2,10,15);
    A.add_arista(1,10,20);
    A.add_arista(12,13,15);
    A.GraphViz();
    return 0;
}
