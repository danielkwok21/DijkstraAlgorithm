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
list<Edge> getAvailableEdges(Node cn);
Edge minWeightEdge(list<Edge> edges);
void updateNodeWeight(Node n, int newWeight);
bool visited(Node n);

//global variable declaration
list<Node> visitedNodes;

Algorithm::Algorithm(Node *n, int nl, Edge *e, int el, Node *sn, Node *en)
:nodesp(n), nodelength(nl), edgesp(e), edgelength(el), startNode(sn), endNode(en)
{
    startNode->setWeight(0);
    startNode->setVisited();
    startNode->printDetails();
    string path = dijkstra();
}

string Algorithm::dijkstra(){
    string path="";
    Node *currentNode = startNode;
    currentNode->printDetails();
    startNode->printDetails();

    while(!(*currentNode).is(*endNode)){
        list<Edge> neightbourEdges = getAvailableEdges(*currentNode);

        Node chosenNode = minWeightNode(*currentNode, neightbourEdges);
        currentNode = &chosenNode;
        visitedNodes.push_back(*currentNode);

        updateNodeWeight(*currentNode, chosenNode.getWeight());
        currentNode->printDetails();
    }
    return path;
}
sortByWeight(Node n1, Node n2){
    return n1.getWeight()<n2.getWeight();
}

Node Algorithm::minWeightNode(Node cn, list<Edge> edges){

    list<Node> updatedNodes;
    std::list<Edge>::iterator i;
    for(i=edges.begin(); i!=edges.end();i++){
            cout<<"cn.getWeight:"<<cn.getWeight()<<endl;
            cout<<"(*i).getWeight():"<<(*i).getWeight()<<endl;
        int potentialWeight = cn.getWeight()+(*i).getWeight();
        Node *potentialNode = (*i).getAN(cn);
            cout<<"potentialNode.getName(): "<<potentialNode->getName()<<endl;
            cout<<"potentialNode.getWeight(): "<<potentialNode->getWeight()<<endl;
            cout<<"potentialWeight: "<<potentialWeight<<endl;

        if(potentialNode->getWeight()>potentialWeight){
            potentialNode->setWeight(potentialWeight);
            updatedNodes.push_back(*potentialNode);
        }
    }

    Node minWeightNode = updatedNodes.front();
    std::list<Node>::iterator j;
    for(j=updatedNodes.begin(); j!=updatedNodes.end();j++){
        if((*j).getWeight()<minWeightNode.getWeight()){
            minWeightNode = (*j);
        }
    }
    cout<<"next node, ie node with lowest potential weight is: "<<minWeightNode.getName()<<endl;
    return minWeightNode;
}

void Algorithm::updateNodeWeight(Node n, int newWeight){
    if(n.getWeight()==-1 || n.getWeight()<newWeight){
        n.setWeight(newWeight);
        n.setVisited();
    }
    cout<<"\n"<<n.getName()<<": "<<n.getWeight()<<endl;
}

list<Edge> Algorithm::getAvailableEdges(Node cn){
    cout<<"inside getAvailableEdges"<<endl;
    list<Edge> availableEdges;
    for(int i=0; i<edgelength; i++){
        Edge currentEdge = (*(edgesp-i));
        if(currentEdge.getSN()->is(cn)){
            currentEdge.getEN()->printDetails();
            if(!(currentEdge.getEN()->visited())){
                availableEdges.push_back(currentEdge);
            }
        }
        if(currentEdge.getEN()->is(cn)){
            currentEdge.getSN()->printDetails();
            if(!(currentEdge.getSN()->visited())){
                availableEdges.push_back(currentEdge);
            }
        }
    }
    std::list<Edge>::iterator i;
    for(i=availableEdges.begin(); i!=availableEdges.end();i++){
        cout<<(*i).getWeight()<<"|";
    }
    return availableEdges;
}

void printPath(string tempPath){
    cout<<"Current path:"<<tempPath<<endl;
}


Algorithm::~Algorithm()
{
    //dtor
}
