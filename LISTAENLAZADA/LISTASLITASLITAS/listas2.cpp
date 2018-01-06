#include<iostream>

using namespace std;

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

class linkedList {
    public:
        linkedList();
        ~linkedList();
        void mostrar();
        bool buscar(Node<T>*p);
        void push_back(int d);
        void addtofront(int d);
        void insertordenado(int d);
        bool isempty();

    private:
        Node* head;
};

void linkedList::mostrar(){
    Node *temp = head;
    while(temp!=0){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    delete temp;
}
bool linkedList::buscar(Node<T>*p){
    if(!p) return false;
    Node *temp = head;
    while (temp != 0){
        if(temp->val==val)
        {
            return true;
        }

        temp =temp->siguiente;
    }
    return false;

}

void linkedList::insertordenado(int d){

    Node *node = new Node;
    node->next = NULL;
    node->prev = NULL;
    node->val = d;

    Node *temp = head;
    while (temp != 0){
        if(temp->next==NULL)
        if(temp->val==d)
        {
            return true;
        }

        temp =temp->siguiente;
    }


}

void linkedList::push_back(int d)
{
    Node *node = new Node;
    node->next = NULL;
    node->prev = NULL;
    node->val = d;

    if (head == NULL) {
        head = node;
    } else {
        Node *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = node;
        node->prev = last;
    }
}

void linkedList::addtofront(int d)
{
    Node *node = new Node;
    node->next = NULL;
    node->prev = NULL;
    node->val = d;

    if (head == NULL) {
        head = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

linkedList::linkedList(){};

int main(){
    linkedList<int> A;
    A.push_back(2);
    A.push_back(5);
    A.push_back(10);

    linkedList<int> B;
    A.push_back(6);
    A.push_back(2);
    A.push_back(7);



    return 1;
}
