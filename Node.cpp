#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

Node::Node(char n, int w)
:name(n), weight(w)
{

}

char Node::getName(){
    return name;
}

int Node::getWeight(){
    return weight;
}

void Node::setWeight(int newWeight){
    weight = newWeight;
}

bool Node::is(Node n){
    return this->getName() == n.getName();
}



/*
list<Node> Node::getAvailableNodes(){
    list<Node> availableNodes;
    for(int i=0; i<edgelength; i++){
        if((edgesp+i)->getSN().getName()==this.getName()){
            if(!visited){
                availableEdges.push_back((edgesp+i)->getEN());
            }
        }else if((edgesp+i)->getEN().getName()==this.getName()){
            if(!visited){
                availableEdges.push_back((edgesp+i)->getSN());
            }
        }
    }

    std::list<Node>::iterator i;
    for(i=availableNodes.begin(); i!=availableNodes.end();i++){
        cout<<(*i).getWeight()<<"|";
    }
    return availableNodes;
}
*/
bool Node::visited(){
    return wasVisited;
}

void Node::setVisited(){
    wasVisited = true;
}

bool Node::isEqual(Node n){
    bool equalName = this->getName() == n.getName();
    return equalName;
}

Node::~Node()
{

}
