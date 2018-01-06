#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

Edge::Edge(int w, Node sn, Node en)
:weight(w), startNode(sn), endNode(en)
{

}

int Edge::getWeight(){
    return weight;
}

//startNode
Node Edge::getSN(){
    return startNode;
}

//endNode
Node Edge::getEN(){
    return endNode;
}

//adjacentNode
Node Edge::getAN(Node n){
    if(n.isEqual(startNode)){
        return endNode;
    }
    return startNode;
}

bool Edge::isEqual(Edge e){
    bool equalStartNodes = this->getSN().isEqual(e.getSN());
    bool equalEndNodes = this->getEN().isEqual(e.getEN());

    return equalStartNodes && equalEndNodes;
}


Edge::~Edge()
{

}
