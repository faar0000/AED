#include "graph.h"

template<typename VetexType,typename EdgeType>
Graph<VetexType,EdgeType>::Graph()
    :firstPointerToVertex(nullptr),lastPointerToVertex(nullptr)
{

}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::proof(VertexType d)
{
    Vertex<VertexType,EdgeType> *newVertex = new Vertex<VertexType,EdgeType>(d);
}
template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::inicializate()
{
    this->firstPointerToVertex=nullptr;
}

template<typename VertexType, typename EdgeType>
int Graph<VertexType,EdgeType>::getSize()
{
    int cont=0;
    Vertex<VertexType,EdgeType> *temp=firstPointerToVertex;
    while (temp) {
        temp=temp->pointerToNextVertex;
        cont++;
    }
    return cont;
}

template<typename VertexType, typename EdgeType>
bool Graph<VertexType,EdgeType>::isEmpty()
{
    return this->firstPointerToVertex==nullptr;
}

template<typename VertexType, typename EdgeType>

Vertex<VertexType, EdgeType> *Graph<VertexType,EdgeType>::findVertex(VertexType d)
{
    Vertex<VertexType,EdgeType> *temp=firstPointerToVertex;
    while (temp) {
        if(temp->getData()==d)
            return temp;
        temp=temp->pointerToNextVertex;
    }
    return nullptr;
}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::insertEdge(Vertex<VertexType, EdgeType> *origin, Vertex<VertexType, EdgeType> *destyne, EdgeType d)
{
    Edge<VertexType,EdgeType> *newEdge=new Edge<VertexType,EdgeType>(d);
    Edge<VertexType,EdgeType> *temp=origin->pointerToNextEdge;
    if(!temp)
    {
        origin->pointerToNextEdge=newEdge;
        newEdge->pointerToNextVertex=destyne;
    }
    else
    {
        while (temp->pointerToNextEdge) {
            temp=temp->pointerToNextEdge;
        }
        temp->pointerToNextEdge=newEdge;
        newEdge->pointerToNextVertex=destyne;
    }
}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::insertVertex(VertexType d)
{
    Vertex<VertexType,EdgeType> *newVertex = new Vertex<VertexType,EdgeType>(d);
    if(isEmpty())
    {
        firstPointerToVertex=lastPointerToVertex=newVertex;
    }
    else
    {
        lastPointerToVertex->pointerToNextVertex=newVertex;
        lastPointerToVertex=newVertex;
    }
}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::adjacencyList()
{
    Vertex<VertexType,EdgeType> *temp=firstPointerToVertex;
    Edge<VertexType,EdgeType> *ed;
    while (temp) {
        cout << temp->getData() << "-->" ;
        ed=temp->pointerToNextEdge;
        while (ed) {
            cout << ed->getData() << "-->";
            ed=ed->pointerToNextEdge;
        }
        cout << endl;
        temp=temp->pointerToNextVertex;
    }

}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::deleteEdge(Vertex<VertexType, EdgeType> *origin, Vertex<VertexType, EdgeType> *destyne)
{
    Edge<VertexType,EdgeType> *temp=origin->pointerToNextEdge;
    Edge<VertexType,EdgeType> *temp1=origin->pointerToNextEdge;
    if(!temp)
        return;
    else if(temp->pointerToNextVertex==destyne)
    {
        origin->pointerToNextEdge=temp->pointerToNextEdge;
        delete temp;
    }
    else 
    { 
        temp=temp->pointerToNextEdge;
        while (temp->pointerToNextVertex!=destyne) {
            temp=temp->pointerToNextEdge;
            temp1=temp1->pointerToNextEdge;
        }
        temp1->pointerToNextEdge=temp->pointerToNextEdge;
        delete temp;
    }

}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::cancel()
{
    Vertex<VertexType,EdgeType> *temp;
    while (temp) {
        temp=firstPointerToVertex;
        firstPointerToVertex=firstPointerToVertex->pointerToNextVertex;
        delete temp;
    }
}

template<typename VertexType, typename EdgeType>
bool Graph<VertexType,EdgeType>::isCicle(Vertex<VertexType,EdgeType> v)
{
    Vertex<VertexType,EdgeType> *tem=this->firstPointerToVertex;
    //insertEdge();
}
template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::dijkstra(Vertex<VertexType, EdgeType> *origin, Vertex<VertexType, EdgeType> *destyne)
{
    Edge<VertexType,EdgeType> *Longitude;
    list<Vertex<VertexType,EdgeType>*> vertexS;//lista de vertice V(T)
    list<Vertex<VertexType,EdgeType>*> vertexF;//lista de vertive F(T)
    list<Vertex<VertexType,EdgeType>*> vertexC;
    list<Edge<VertexType,EdgeType>*> edges; //lista de aristas E(T)
    vertexS.push_back(origin);
    vertexF.push_back(origin);
    vertexC.push_back(origin);
    typename list<Vertex<VertexType,EdgeType>*>::iterator itVertex=vertexS.begin();//ITERADOR A VERTICE
    typename list<Vertex<VertexType,EdgeType>*>::iterator itVertex2=vertexC.begin();//ITERADOR A VERTICE
    /*while (itVertex!=vertexS.end()) {
        cout << (*itVertex)->getData() << endl;
        itVertex++;
    }
    */
    typename list<Edge<VertexType,EdgeType>*>::iterator itEdge=edges.begin();//ITERADOR A ARISTA
    Edge<VertexType,EdgeType> *temp=(*itVertex)->pointerToNextEdge;
    temp=(*itVertex)->pointerToNextEdge;//crea un temporal para recorrer las ariastas de los nodos
    Longitude=temp;//actualiza l al primer arista dela arista
    //int i;
    /*
    while (itVertex!=vertexS.end()) {
        if(itVertex2==vertexC.end())
        {
            vertexC.push_back(Longitude->pointerToNextVertex);
            vertexF.push_back(Longitude->pointerToNextVertex);
            Longitude->pointerToNextVertex->setVisit(true);
            itVertex2=vertexC.begin();
            temp=(*itVertex2)->pointerToNextEdge;//crea un temporal para recorrer las ariastas de los nodos
            if(temp->pointerToNextEdge->pointerToNextVertex->getVisit())
            {
                Longitude=temp->pointerToNextEdge;//actualiza l al primer arista dela arista
            }
        }
        else if(itVertex2!=vertexC.end())
        {
            temp=(*itVertex2)->pointerToNextEdge;//crea un temporal para recorrer las ariastas de los nodos
        }
        while (temp) {
            cout << temp->getData() << endl;
            if(temp->getData()<Longitude->getData() and temp->pointerToNextVertex->getVisit()==true)
                Longitude=temp;
            temp=temp->pointerToNextEdge;
        }
        guardar((*itVertex)->getData());
        itVertex2++;
        itVertex++;
    }*/
}
template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::guardar(string s)
{
    ofstream f;
    f.open("save.txt",ios::app);
    f << s << endl;
}
