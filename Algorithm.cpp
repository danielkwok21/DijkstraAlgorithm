#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include "string"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

//function declarations


/**
*constructor
*@param *n,     pointer to nodes array
*@param nl,     length of nodes array
*@param *e,     pointer to edges array
*@param el,     length of nodes array
*@param *np,    pointer to nought node
*@param *en,    pointer to end node
*/
Algorithm::Algorithm(Node *n, int nl, Edge *e, int el, Node *np, Node *en)
:nodesp(n), nodelength(nl), edgesp(e), edgelength(el), nought(np), endNode(en)
{
    string path = dijkstra();
    cout<<"Final answer: "<<path<<endl;
    cout<<"total cost: "<<endNode->getWeight();
}

/**
*dijkstra function
*1. pushes all nodes to prioritylist
*2. for each of the node in prioritylist, get the appropriate next node to traverse to
*3. loop till next node is end node
*/
string Algorithm::dijkstra(){
    Node *currentNode = nought;
    for(int i=0; i<nodelength; i++){
        priorityList.push_back(*(nodesp-i));
    }

    do{
        list<Edge> incidentEdges = getAvailableEdges(currentNode);
        currentNode = updateAdjacentNodes(currentNode, incidentEdges);

    }while(!currentNode->is(*endNode));

    printNodes();
    return getSolution();
}

/**
*updateAdjacentNodes function
*@param *currentNode,   pointer to currently traversed node
*@param edges,          list of all edges of currentNode
*@return next appropriate node
*/
Node* Algorithm::updateAdjacentNodes(Node *currentNode, list<Edge> edges){
    list<Edge>::iterator e;
    for(e=edges.begin(); e!=edges.end(); e++){

        //for each potential next node, get the potential new weight
        //and compare with current weight
        Node *adjacentNode = (*e).getAN(*currentNode);
        int newWeight = currentNode->getWeight()+(*e).getWeight();

        if(newWeight<adjacentNode->getWeight()){
            adjacentNode->setWeight(newWeight);
            adjacentNode->setUpdatedBy(*currentNode);
            adjacentNode->setVisited();
            replaceUnique(&priorityList, *adjacentNode);
        }
    }

    //sorts priority list
    priorityList.sort([](Node &n1, Node &n2){
        if(!(n1.getWeight() > n2.getWeight())){
            return n1.getWeight() < n2.getWeight();
        }
    });

    //pops currently traversed node
    priorityList.pop_front();

    return &(priorityList.front());
}

/**
*getSolution function
*this is needed because i couldn't find way to store
*a node's owner(the node that modified this node) as type Node,
*hence I'm only able to store it as its name, type char
*this function converts the name back to the Node of the same name
*@return string of solution
*/
string Algorithm::getSolution(){
    string sol;
    Node n = *endNode;
    do{
        bool found = false;
        int i=0;
        string thisNode(1, n.getName());
        sol.append(thisNode);
        do{
            if((*(nodesp-i)).getName()==n.getUpdatedBy()){
                n = *(nodesp-i);
                found = true;
            }
            i++;
        }while(!found||i>nodelength);

        sol.append("|");
    }while(!n.is(*nought));

    return sol;
}

/**
*printNodes function
*prints the node array
*/
void Algorithm::printNodes(){
    cout<<"All nodes:"<<endl;
    for(int i=0; i<nodelength; i++){
        (nodesp-i)->printDetails();
    }
}

/**
*printPriorityList function
*prints the priorityList
*/
void Algorithm::printPriorityList() {
//look at priorityList's content
    std::list<Node>::iterator n;
    cout<<"priorityList:"<<endl;
    for(n=priorityList.begin(); n!=priorityList.end(); n++){
        (*n).printDetails();
    }
}

/**
*replaceUnique function
*@param *uniqueList,    pointer to priorityList
*@param n,              node to push into list
*I wasn't able to find a way to implement a set in c++, hence used list as a substitution
*this has its draw back as I would have to explicitly code out how the
*pushing in, overriding etc would happen
*/
void Algorithm::replaceUnique(list<Node> *uniqueList, Node n){
    bool pushed = false;

    std::list<Node>::iterator j;
    for(j=uniqueList->begin(); j!=uniqueList->end();j++){
        if((*j).getName()==n.getName()){
            (*j) = n;
            pushed = true;
        }
    }
    if(!pushed){
        uniqueList->push_back(n);
    }
}

/**
*minWeightNode function
*@param nodes,  adjacent nodes of a particular node
*@return the minimum weight of all adjacent nodes
*/
Node Algorithm::minWeightNode(list<Node> nodes){
    Node minWeightNode = nodes.front();
    std::list<Node>::iterator j;
    for(j=nodes.begin(); j!=nodes.end();j++){
        if((*j).getWeight()<minWeightNode.getWeight()){
            minWeightNode = (*j);
        }
    }
    return minWeightNode;
}

/**
*getAvailableEdges function
*@param *currentNode,   currently traversed node
*@return all incident edges of a graph
*/
list<Edge> Algorithm::getAvailableEdges(Node *currentNode){

    list<Edge> availableEdges;
    for(int i=0; i<edgelength; i++){
        Edge currentEdge = (*(edgesp-i));

        if(currentEdge.getSN()->is(*currentNode)||currentEdge.getEN()->is(*currentNode)){
            availableEdges.push_back(currentEdge);
        }
    }
    return availableEdges;
}

Algorithm::~Algorithm()
{
    //dtor
}
