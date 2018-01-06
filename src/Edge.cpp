#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

Edge::Edge()
{
    cout<<"default constructor"<<endl;
}
/*
Edge::Edge(int w, Node sn, Node en)
{
    int weight = w;
    Node startNode = sn;
    Node endNode = en;
    public:
    private:
}
*/
Edge::~Edge()
{
    //dtor
}
