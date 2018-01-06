#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Heap {
public:
  vector<T> list;
  void increase_key(vector<int> A,int k,int n);
  void swap_(int child, int parent);
  int left(int i);
  int right(int i);
  int padre(int i);
public:
  Heap();
  void insert_(T value);
  void makeheap(vector<int>A,int n);
  void heapfy(vector<int>A,int i,int n);
  void delete_max(vector<int> A,int n);
  void eliminar(vector<int> A,int i,int n);
  void print(vector<int> A);
  int getSize();

};

template <class T>
Heap<T> :: Heap(){

}

template <class T>
int Heap<T> :: getSize(){
  return list.size();
}

template<class T>
void Heap<T>::print(vector<int>A){
    //cout<<"LISTA: "<<A<<endl;
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<"-";
    }

}

template<class T>
void Heap<T>::makeheap(vector<int>A,int n){
    for(int i=(n/2);i>=0;i--) {
        heapfy(A,i,n);
    }
}


template<class T>
void Heap<T>::heapfy(vector<int>A,int i,int n){
    if(left(i)>n){return;}
    int M=i;
    if((A[i])<A[left(A[i])]and left(i)<=n){
        M=left(i);
    }
    if(A[M]<A[right(i)]and right(i)<n){
        M=right(i);
    }
    if(M==i) return;
    swap_(A[i],A[M]);
    heapfy(A,M,n);
}

/*template<class T>
void Heap<T>::heapfy(vector<int>A,int i,int n){
    if(left(i)>n){return;}
    int M=i;
    if((A[i])<A[left(A[i])]and left(i)<=n){
        M=A[left(A[i])];
    }
    if(M<A[right(A[i])]){
        M=A[right(A[i])];
    }
    if(M==i) return;
    swap_(A[i],A[M]);
    heapfy(A,M,n);
}*/

template <class T>
void Heap<T>::swap_(int child, int parent) {
  T temp;
  temp = list[child];
  list[child] = list[parent];
  list[parent] = temp;
}

template <class T>
int Heap<T> :: padre(int i) {
  if (i % 2 == 0)
	return (i/2 )-1;
  else
	return i/2;

}

template <class T>
int Heap<T> :: left(int i){
  return (2*i)+1;
}

template <class T>
int Heap<T> :: right(int parent){
  return (2*parent)+2;
}

template <class T>
void Heap<T> :: insert_(T value) {

  list.push_back(value);
  //increase_key(list,value,getSize());

}
template<class T>
void Heap<T>::increase_key(vector<int> A,int k,int n){
    A[n]=k;
    n++;
    while(n!=0){
        if(A[n]>A[padre(n)])
            swap_(list[n],list[padre(n)]);
        else
            return;
        n=padre(n);
    }

}

template<class T>
void Heap<T>::delete_max(vector<int> A,int n){
    swap(A[0],A[n]);
    n--;
    heapfy(A,0,n);

}
template <class T>
void Heap<T>::eliminar(vector<int> A,int i,int n){
    A[i]=(A[0]+1);
    increase_key(A,i,n);
    delete_max(A,n);
}



int main(){
    int a[] = {5,3,8,11,13,15,12};
    Heap<int> heap;
    int len = sizeof(a) /sizeof(int);
    int i =0;
    for (i = 0; i < len; i++)
    {
      heap.insert_(a[i]);
    }
    heap.print(heap.list);
    cout<<endl;
    cout<<endl;
   // heap.makeheap(heap.list,7);
    heap.print(heap.list);
  return 0;

}
