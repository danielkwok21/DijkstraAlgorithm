#ifndef EDGE_H
#define EDGE_H


class Edge
{
    public:
        Edge();
        Edge(int weight, Node startNode, Node endNode);
        virtual ~Edge();

    protected:

    private:
        int weight;
        Node startNode;
        Node endNode;
};

#endif // EDGE_H
