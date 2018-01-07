#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

Node::Node(char n)
:name(n)
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
    return name == n.getName();
}

void Node::printDetails(){
    cout<<"Node:"<<name<<"|Weight:"<<weight<<"|"<<"|Visited:"<<wasVisited<<"Updated by:"<<updatedBy<<endl;
    //cout<<"Node:"<<name<<"|"<<"Weight:"<<weight<<"|"<<"Visited:"<<wasVisited<<endl;

}

bool Node::visited(){
    return wasVisited;
}

void Node::setVisited(){
    wasVisited = true;
}

char Node::getUpdatedBy(){
    return updatedBy;
}
void Node::setUpdatedBy(Node n){
    updatedBy = n.getName();
}

Node::~Node()
{

}
