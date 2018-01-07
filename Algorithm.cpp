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

//global variable declaration
list<Node> visitedNodes;

Algorithm::Algorithm(Node *n, int nl, Edge *e, int el, Node *sn, Node *en)
:nodesp(n), nodelength(nl), edgesp(e), edgelength(el), startNode(sn), endNode(en)
{
    startNode->setWeight(0);
    startNode->setVisited();
    startNode->printDetails();
    string path = dijkstra();
    cout<<"Final answer: "<<path<<endl;
}



string Algorithm::dijkstra(){
    string path="";
    Node currentNode = *startNode;
    list<Edge> incidentEdges;

    do{
        cout<<"\n\nnew round"<<endl;
        cout<<"currentNode:"<<currentNode.getName()<<endl;
        incidentEdges = getAvailableEdges(currentNode);
        updateAdjacentNodes(currentNode, incidentEdges);

        priorityList.sort([](Node &n1, Node &n2){
			if(!(n1.getWeight() > n2.getWeight())){
                return n1.getWeight() < n2.getWeight();
                }
        });
        printPriorityList();

        currentNode = priorityList.front();
        cout<<"new currentNode: "<<endl;
        currentNode.printDetails();
        priorityList.pop_front();
        printPriorityList();
        printNodes();
    }while(!priorityList.empty());
/*
    char n = endNode.getName();
    while(n!=startNode.getName()){
        path.append(n);
        n =

    }
   */
    path = getSolution();

    return path;
}

string Algorithm::getSolution(){
    string sol;
    Node n = *endNode;
    do{
        cout<<"n.getName(): "<<n.getName()<<endl;
        string thisNode(1, n.getName());
        sol.append(thisNode);
        string prevNode(1, n.getUpdatedBy());
        //sol.append(prevNode);
        for(int i=0;i<nodelength; i++){
            if((*(nodesp-i)).getName()==n.getUpdatedBy()){
                n = *(nodesp-i);
            }
        }

        sol.append("|");
    }while(!n.is(*startNode));
    string firstNode(1, (*startNode).getName());
    sol.append(firstNode);

    return sol;
}

void Algorithm::printNodes(){
    cout<<"All nodes:"<<endl;
    for(int i=0; i<nodelength; i++){
        (nodesp-i)->printDetails();
    }
}


void Algorithm::printPriorityList(){
//look at priorityList's content
    std::list<Node>::iterator n;
    cout<<"priorityList:"<<endl;
    for(n=priorityList.begin(); n!=priorityList.end(); n++){
        (*n).printDetails();
    }
}

sortByWeight(Node *n1, Node *n2){
    return n1->getWeight()<n2->getWeight();
}

void Algorithm::updateAdjacentNodes(Node cn, list<Edge> edges){
    cout<<"Available Nodes:"<<endl;

    std::list<Edge>::iterator i;
    for(i=edges.begin(); i!=edges.end();i++){
            //cout<<"current node:"<<endl;
            cn.printDetails();
            //cout<<"this edge.getWeight():"<<(*i).getWeight()<<endl;
        int potentialWeight = cn.getWeight()+(*i).getWeight();
        Node *potentialNode = (*i).getAN(cn);
            //cout<<"potentialNode.getName(): "<<potentialNode->getName()<<endl;
            //cout<<"potentialNode.getWeight(): "<<potentialNode->getWeight()<<endl;
            //cout<<"potentialWeight: "<<potentialWeight<<endl;

        if(potentialNode->getWeight()>potentialWeight){
            potentialNode->setWeight(potentialWeight);
            potentialNode->setVisited();
            potentialNode->setUpdatedBy(cn);
            priorityList.push_back(*potentialNode);
        }
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

list<Edge> Algorithm::getAvailableEdges(Node cn){
    cout<<"Available Edges:"<<endl;

    cout<<"current node:"<<endl;
    cn.printDetails();
    list<Edge> availableEdges;
    for(int i=0; i<edgelength; i++){
        Edge currentEdge = (*(edgesp-i));

        if(currentEdge.getSN()->is(cn)||currentEdge.getEN()->is(cn)){
           // cout<<"hit"<<endl;
            //cout<<"currentEdge.getSN().name:"<<currentEdge.getSN()->getName()<<endl;
            //cout<<"currentEdge.getEN().name:"<<currentEdge.getEN()->getName()<<endl;
            availableEdges.push_back(currentEdge);

        }
    }
    std::list<Edge>::iterator i;
    cout<<"availableEdges:"<<endl;
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
