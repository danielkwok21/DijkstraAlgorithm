#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

Node::Node(){
    cout<<"hello world from node"<<endl;
}

Node::Node(char n, int w)
{
    public:
        char getName(){
            return name;
        }
        void setVariables(){
            name = n;
            weight = w;
        }
    private:
        char name;
        char weight;
}

Node::~Node()
{
    //dtor
}
