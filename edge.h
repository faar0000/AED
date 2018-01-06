#ifndef EDGE_H
#define EDGE_H
#include <iostream>
using namespace std;
template<typename VertexType,typename EdgeType> class Vertex;
template<typename VertexType,typename EdgeType> class Graph;
template<typename VertexType,typename EdgeType>
class Edge
{
    friend class Graph<VertexType,EdgeType>;
public:
    Edge(EdgeType);
    EdgeType getData();
    Vertex<VertexType,EdgeType> *getPointerToNextVertex()
    {
        return this->pointerToNextVertex;
    }
    Edge<VertexType,EdgeType> *getPointerToNextEdge()
    {
        return this->pointerToNextEdge;
    }
    void setVisit()
    {
        this->visit=false;
    }
    bool getVisit()
    {
        return this->visit;
    }
private:
    bool visit;
    EdgeType edgeData;
    Vertex<VertexType,EdgeType> *pointerToNextVertex;
    Edge<VertexType,EdgeType> *pointerToNextEdge;

};

#endif // EDGE_H
