#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include "string"
#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include <algorithm>

//function declarations

Algorithm::Algorithm(Node *n, int nl, Edge *e, int el, Node *np, Node *en)
:nodesp(n), nodelength(nl), edgesp(e), edgelength(el), nought(np), endNode(en)
{
    string path = dijkstra();
    cout<<"Final answer: "<<path<<endl;
    cout<<"total cost: "<<endNode->getWeight();
}

string Algorithm::dijkstra(){
    string path="";
    Node *currentNode = nought;
    list<Edge> incidentEdges;
    priorityList.push_front(*currentNode);

    do{

        cout<<"\n\n\nnew round"<<endl;
        cout<<"current Node for this round is:"<<endl;
        currentNode->printDetails();

        incidentEdges = getAvailableEdges(currentNode);
        currentNode = updateAdjacentNodes(currentNode, incidentEdges);

        printNodes();

    }while(!priorityList.empty());

    return getSolution();
}

string Algorithm::getSolution(){
    string sol;
    Node n = *endNode;
    do{
        bool found = false;
        int i=0;
        cout<<"sol: "<<sol<<endl;
        cout<<"n.getName(): "<<n.getName()<<endl;
        string thisNode(1, n.getName());
        sol.append(thisNode);
        do{
            if((*(nodesp-i)).getName()==n.getUpdatedBy()){
                cout<<(*(nodesp-i)).getName()<<" and "<<n.getUpdatedBy()<<endl;
                n = *(nodesp-i);
                found = true;
            }
            i++;
        }while(!found||i>nodelength);

        sol.append("|");
    }while(!n.is(*nought));

    return sol;
}

void Algorithm::printNodes(){
    cout<<"All nodes:"<<endl;
    for(int i=0; i<nodelength; i++){
        (nodesp-i)->printDetails();
    }
}

void Algorithm::printPriorityList() {
//look at priorityList's content
    std::list<Node>::iterator n;
    cout<<"priorityList:"<<endl;
    for(n=priorityList.begin(); n!=priorityList.end(); n++){
        (*n).printDetails();
    }
}
/*
void Algorithm::printPotentialNodes() {
//look at potentialNodes's content
    std::list<Node>::iterator n;
    cout<<"potential nodes:"<<endl;
    for(n=potentialNodes.begin(); n!=potentialNodes.end(); n++){
        (*n).printDetails();
    }
}
*/

sortByWeight(Node *n1, Node *n2){
    return n1->getWeight()<n2->getWeight();
}
Node* Algorithm::updateAdjacentNodes(Node *currentNode, list<Edge> edges){
    cout<<"Available nodes"<<endl;
    list<Node> potentialNodes;
    bool updates = false;
    Node *nextNode;
    list<Edge>::iterator e;
    for(e=edges.begin(); e!=edges.end(); e++){
        Node *adjacentNode = (*e).getAN(*currentNode);
        int newWeight = currentNode->getWeight()+(*e).getWeight();

        if(newWeight<adjacentNode->getWeight()){
            cout<<adjacentNode->getName()<<"|";
            updates = true;
            adjacentNode->setWeight(newWeight);
            adjacentNode->setUpdatedBy(*currentNode);
            adjacentNode->setVisited();
            replaceUnique(&priorityList, *adjacentNode);

            cout<<"new adjacentNode"<<endl;
            adjacentNode->printDetails();
        }
    }
    priorityList.sort([](Node &n1, Node &n2){
        if(!(n1.getWeight() > n2.getWeight())){
            return n1.getWeight() < n2.getWeight();
        }
    });

    cout<<"pre pop"<<endl;
    printPriorityList();

    priorityList.pop_front();

    cout<<"post pop"<<endl;
    printPriorityList();

    if(!updates){
        cout<<"No updates"<<endl;
        nextNode = getPrevNode(*currentNode);
        cout<<"prev node was: "<<nextNode->getName()<<endl;
        return nextNode;
    }

    return &priorityList.front();
}

Node* Algorithm::getPrevNode(Node currentNode){
    char prevNodeName = currentNode.getUpdatedBy();
    for(int i=0;i<nodelength; i++){
        if((*(nodesp-i)).getName()==prevNodeName){
            return &(*(nodesp-i));
        }
    }
}

void Algorithm::replaceUnique(list<Node> *uniqueList, Node n){
    bool pushed = false;

    std::list<Node>::iterator j;
    for(j=uniqueList->begin(); j!=uniqueList->end();j++){
        if((*j).getName()==n.getName()){
            cout<<"element not unique"<<endl;
            (*j) = n;
            pushed = true;
        }
    }
    if(!pushed){
        cout<<"element unique"<<endl;
        uniqueList->push_back(n);
    }
}

Node Algorithm::minWeightNode(list<Node> nodes){
    Node minWeightNode = nodes.front();
    std::list<Node>::iterator j;
    for(j=nodes.begin(); j!=nodes.end();j++){
        if((*j).getWeight()<minWeightNode.getWeight()){
            minWeightNode = (*j);
        }
    }
    cout<<"next node, ie node with lowest potential weight is: "<<minWeightNode.getName()<<endl;
    return minWeightNode;
}

list<Edge> Algorithm::getAvailableEdges(Node *cn){
    cout<<"Available Edges:"<<endl;

    list<Edge> availableEdges;
    for(int i=0; i<edgelength; i++){
        Edge currentEdge = (*(edgesp-i));

        if(currentEdge.getSN()->is(*cn)||currentEdge.getEN()->is(*cn)){
            availableEdges.push_back(currentEdge);
        }
    }
    std::list<Edge>::iterator i;
    for(i=availableEdges.begin(); i!=availableEdges.end();i++){
        cout<<(*i).getWeight()<<"|";
    }
    cout<<endl;
    return availableEdges;
}

void printPath(string tempPath){
    cout<<"Current path:"<<tempPath<<endl;
}


Algorithm::~Algorithm()
{
    //dtor
}
