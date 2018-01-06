#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        Node(char name, int weight);
        virtual ~Node();
        char getName();
    protected:

    private:
        char name;
        int weight;
};

#endif // NODE_H
