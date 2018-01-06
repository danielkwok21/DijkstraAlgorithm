#ifndef NODE_H
#define NODE_H
#include <list>
class Node
{
    public:
        Node(char name, int weight);
        char getName();
        int getWeight();
        void setWeight(int newWeight);
        bool is(Node n);
        list<Node> getAvailableNodes(Node n);
        bool visited();
        void setVisited();
        bool isEqual(Node n);
        virtual ~Node();
    protected:

    private:
        char name;
        int weight;
        bool wasVisited;
};

#endif // NODE_H
