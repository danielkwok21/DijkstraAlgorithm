#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include "string"
#include <iostream>
#include <list>
#include <iterator>

//function declarations
list<Edge> getAvailableEdges(Node cn);
Edge* minWeightEdge(list<Edge> edges);
void updateNodeWeight(Node n, int newWeight);
bool visited(Node n);

//global variable declaration
list<Node> visitedNodes;

Algorithm::Algorithm(Node *n, int nl, Edge *e, int el, Node sn, Node en)
:nodesp(n), nodelength(nl), edgesp(e), edgelength(el), startNode(sn), endNode(en)
{
    string path = dijkstra();
}

string Algorithm::dijkstra(){
    string path="";
    Node *currentNode = &startNode;
    currentNode->setWeight(0);
    visitedNodes.push_back(*currentNode);

    list<Edge> neightbourEdges = getAvailableEdges(*currentNode);

    Node *chosenNode = minWeightNode(*currentNode, neightbourEdges);
    currentNode = chosenNode;
    visitedNodes.push_back(*currentNode);

    updateNodeWeight(*currentNode, chosenNode->getWeight());

    return path;
}

Node* Algorithm::minWeightNode(Node cn, list<Edge> edges){
    Node nextNode = edges.front().getAN(cn);

    std::list<Edge>::iterator i;
    for(i=edges.begin(); i!=edges.end();i++){
        Node potentialNextNode = (*i).getAN(cn);
        int nextNodeWeight = potentialNextNode.getWeight();
        int potentialNextNodeWeight = cn.getWeight() + nextNodeWeight;
        cout<<"potentialNextNodeWeight: "<<potentialNextNodeWeight<<endl;
        if(potentialNextNodeWeight<nextNode.getWeight()){
            cout<<"switch"<<endl;
            nextNode = potentialNextNode;
        }
    }
    cout<<"next node, ie node with lowest potential weight is: "<<nextNode.getName()<<endl;

    Node *nextNodep = &nextNode;
    return nextNodep;
}

void Algorithm::updateNodeWeight(Node n, int newWeight){
    if(n.getWeight()==-1 || n.getWeight()<newWeight){
        n.setWeight(newWeight);
        n.setVisited();
    }
    cout<<"\n"<<n.getName()<<": "<<n.getWeight()<<endl;
}

list<Edge> Algorithm::getAvailableEdges(Node cn){
    list<Edge> availableEdges;
    for(int i=0; i<edgelength; i++){
        if((edgesp+i)->getSN().getName()==cn.getName()||(edgesp+i)->getEN().getName()==cn.getName()){
            if(!visited){
                availableEdges.push_back(*(edgesp+i));
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
