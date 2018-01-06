#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

Edge::Edge(int w, Node *sn, Node *en)
:weight(w), startNode(sn), endNode(en)
{

}

int Edge::getWeight(){
    return weight;
}

//startNode
Node* Edge::getSN(){
    return startNode;
}

//endNode
Node* Edge::getEN(){
    return endNode;
}

//adjacentNode
Node* Edge::getAN(Node n){
    if(n.is(*startNode)){
        return endNode;
    }
    return startNode;
}

bool Edge::is(Edge e){
    bool equalStartNodes = getSN()->is(*e.getSN());
    bool equalEndNodes = getEN()->is(*e.getEN());

    return equalStartNodes && equalEndNodes;
}


Edge::~Edge()
{

}
