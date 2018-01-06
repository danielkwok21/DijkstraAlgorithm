#ifndef NODE_H
#define NODE_H
#include <list>
class Node
{
    public:
        Node(char name);
        char getName();
        int getWeight();
        void setWeight(int newWeight);
        bool is(Node n);
        list<Node> getAvailableNodes(Node n);
        bool visited();
        void setVisited();
        void printDetails();
        virtual ~Node();
    protected:

    private:
        char name;
        int weight = 2147483647;
        bool wasVisited = false;
};

#endif // NODE_H
