 #ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
using namespace std;
template<typename VertexType,typename EdgeType> class Edge;
template<typename VertexType,typename EdgeType> class Graph;
template<typename VertexType,typename EdgeType>
class Vertex
{
    friend class Graph<VertexType,EdgeType>;
public:
    Vertex(VertexType);
    VertexType getData();    
    Vertex<VertexType,EdgeType> *getPointerToNextVertex()
    {
        return this->pointerToNextVertex;
    }
    Edge<VertexType,EdgeType> *getPointerToNextEdge()
    {
        return this->pointerToNextEdge;
    }
    void setVisit(bool d)
    {
        this->visit=d;
    }
    bool getVisit()
    {
        return this->visit;
    }
private:
    bool visit;
    VertexType vertexData;
    Vertex<VertexType,EdgeType> *pointerToNextVertex;
    Edge<VertexType,EdgeType> *pointerToNextEdge;

};

#endif // VERTEX_H
