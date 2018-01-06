#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vertex.h>
#include <vertex.cpp>
#include <edge.h>
#include <edge.cpp>
#include <string>
#include <list>
#include <queue>
#include <fstream>
using namespace std;
template<typename VertexType,typename EdgeType>
class Graph
{
public:
    Graph();  
    void proof(VertexType);
    void inicializate();
    int getSize();
    bool isEmpty();
    Vertex<VertexType,EdgeType> * findVertex(VertexType);
    void insertEdge(Vertex<VertexType,EdgeType>*,Vertex<VertexType,EdgeType>*,EdgeType);
    void insertVertex(VertexType);
    void adjacencyList();
    void deleteEdge(Vertex<VertexType,EdgeType>*,Vertex<VertexType,EdgeType>*);
    void cancel();
    //----------------------------------
    bool isCicle(Vertex<VertexType,EdgeType>);
    void kruskal();
    void prim();
    int sumaDistancia(int,Graph<VertexType,EdgeType>);
    void dijkstra(Vertex<VertexType,EdgeType> *,Vertex<VertexType,EdgeType> *);
    void search();
    void guardar(string);

private:
    Vertex<VertexType,EdgeType> *firstPointerToVertex;
    Vertex<VertexType,EdgeType> *lastPointerToVertex;
};

#endif // GRAPH_H

