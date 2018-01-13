#ifndef ALGORITHM_H
#define ALGORITHM_H

using namespace std;
#include "string"
#include "Node.h"
#include "Edge.h"
#include <list>
#include <set>
#include <iterator>

class Algorithm
{
    public:
        Algorithm(Node *n, int nl, Edge *e, int el, Node *np, Node *en);
        void printPath(string tempPath);

        virtual ~Algorithm();

    protected:

    private:
        //functions
        list<Edge> getAvailableEdges(Node *cn);
        Node* updateAdjacentNodes(Node *currentNode, list<Edge> edges);
        void updateNodeWeight(Node *n, int newWeight);
        Node minWeightNode(list<Node> nodes);
        string dijkstra();
        void printPriorityList();
        void printPotentialNodes();
        void printNodes();
        string getSolution();
        void replaceUnique(list<Node> *uniqueList, Node n);
        Node* getPrevNode(Node currentNode);

        //variables
        list<Node> priorityList;
        int nodelength;
        int edgelength;
        Node *nodesp;
        Edge *edgesp;
        Node *nought;
        Node *endNode;
};

#endif // ALGORITHM_H
