#ifndef NODE_H
#define NODE_H

#include <list>
class Node
{
    public:
        Node(char n);
        Node(char n, int w);
        char getName() const;
        int getWeight() const;
        void setWeight(int newWeight);
        bool is(Node n);
        bool getVisited();
        void setVisited();
        void printDetails();
        char getUpdatedBy();
        void setUpdatedBy(Node n);

        //override operator==
        bool operator==(const Node *other)const{
            return getName() == other->getName();
        }
        //override operator!=
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
