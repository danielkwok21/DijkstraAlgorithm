#ifndef NODE_H
#define NODE_H

#include <list>
class Node
{
    public:
        Node();
        Node(char n);
        Node(char n, int w, char u);
        char getName() const;
        int getWeight();
        void setWeight(int newWeight);
        bool is(Node n);
        list<Node> getAvailableNodes(Node n);
        bool visited();
        void setVisited();
        void printDetails();
        char getUpdatedBy();
        void setUpdatedBy(Node n);

        bool operator==(const Node *other)const{
            return getName() == other->getName();
        }

        bool operator!=(const Node *other)const{
            return getName() != other->getName();
        }

        virtual ~Node();
    protected:

    private:
        char name;
        int weight = 2147483647;
        bool wasVisited = false;
        char updatedBy =' ';
};

#endif // NODE_H
