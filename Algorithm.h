#ifndef ALGORITHM_H
#define ALGORITHM_H

using namespace std;
#include "string"
#include "Node.h"
#include "Edge.h"
#include <list>
#include <iterator>

class Algorithm
{
    public:
        Algorithm(Node *n, int nl, Edge *e, int el, Node sn, Node en);
        void printPath(string tempPath);

        virtual ~Algorithm();

    protected:

    private:
        list<Edge> getAvailableEdges(Node cn);
        void updateNodeWeight(Node n, int newWeight);
        Node* minWeightNode(Node cn, list<Edge> edges);
        string dijkstra();
        int nodelength;
        int edgelength;
        Node *nodesp;
        Edge *edgesp;
        Node startNode;
        Node endNode;
        bool visited;
};

#endif // ALGORITHM_H
