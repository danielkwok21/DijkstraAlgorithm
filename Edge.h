#ifndef EDGE_H
#define EDGE_H


#include "Node.h"

class Edge
{
    public:
        Edge();
        Edge(int w, Node sn, Node en);
        int getWeight();
        Node getSN();
        Node getEN();
        Node getAN(Node n);
        bool isEqual(Edge e);
        virtual ~Edge();

    protected:

    private:
        int weight;
        Node startNode;
        Node endNode;
};

#endif // EDGE_H
