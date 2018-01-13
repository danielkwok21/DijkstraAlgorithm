#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

/**
*first constructor
*used for all nodes in graph other than nought
*Node default weight: max_int, ie 2147483647
*Node default visit status: false;
*/
Node::Node(char n)
:name(n)
{
}

/**
*second constructor
*used for nought
*@param n,  name
*@param w,  initial weight (redundant argument, would be initialized as 0)
*@param v,  sets visit status as true;
*/
Node::Node(char n, int w)
:name(n), weight(w), wasVisited(true)
{
}

/**
*@return name of node
*/
char Node::getName() const{
    return name;
}

/**
*@return weight of node
*/
int Node::getWeight() const{
    return weight;
}

/**
*sets weight of node
*/
void Node::setWeight(int newWeight){
    weight = newWeight;
}

/**
*compares nodes
*@param n,  another node
*@return true if nodes are equal, false if not
*/
bool Node::is(Node n){
    return name == n.getName();
}

/**
*prints node information*
*/
void Node::printDetails(){
    cout<<"Node:"<<name<<"\t|Weight:"<<weight<<"\t|Visited:"<<wasVisited<<"\t|Updated by:"<<updatedBy<<endl;
    //cout<<"Node:"<<name<<"|"<<"Weight:"<<weight<<"|"<<"Visited:"<<wasVisited<<endl;
}

/**
*marks node as visited
*@return status of node, ie visited or not
*/
bool Node::getVisited(){
    return wasVisited;
}

/**
*sets node as visited
*/
void Node::setVisited(){
    wasVisited = true;
}

/**
*@return the name of the node that updated this node
*/
char Node::getUpdatedBy(){
    return updatedBy;
}

/**
*sets the name of the node that updated this node
*@param n,  node that updated this node
*/
void Node::setUpdatedBy(Node n){
    updatedBy = n.getName();
}


Node::~Node()
{

}
