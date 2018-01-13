#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

/**
*constructor for an edge
*@param w,      weight of edge
*@param *sn,    endNode of edge
*@param *en,    endNode of edge
*/
Edge::Edge(int w, Node *sn, Node *en)
:weight(w), startNode(sn), endNode(en)
{

}

/**
*@return weight of edge
*/
int Edge::getWeight(){
    return weight;
}


/**
*@return one of the endNode of edge
*/
Node* Edge::getSN(){
    return startNode;
}


/**
*@return the other endNode of edge
*/
Node* Edge::getEN(){
    return endNode;
}

/**
*@param n,  endNode of edge
*@return pointer to the endNode of this edge
*/
Node* Edge::getAN(Node n){
    if(n.is(*startNode)){
        return endNode;
    }
    return startNode;
}

/**
*compares edge
*@param e,  another edge
*@return true if edge are equal, false if not
*/
bool Edge::is(Edge e){
    bool equalStartNodes = getSN()->is(*e.getSN());
    bool equalEndNodes = getEN()->is(*e.getEN());

    return equalStartNodes && equalEndNodes;
}


Edge::~Edge()
{

}
