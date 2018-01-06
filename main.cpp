#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>

int main()
{
    Node A('A', -1);
    Node B('B', -1);
    Node C('C', -1);
    Node D('D', -1);
    Node E('E', -1);
    Node F('F', -1);
    Node G('G', -1);
    Node nodes[] = {A, B, C, D, E, F, G};

    Edge e1(4, A, B);
    Edge e2(3, A, C);
    Edge e3(7, A, E);
    Edge e4(6, B, C);
    Edge e5(11, C, D);
    Edge e6(8, C, E);
    Edge e7(5, B, D);
    Edge e8(2, E, D);
    Edge e9(5, E, G);
    Edge e10(10, D, G);
    Edge e11(2, D, F);
    Edge e12(3, G, F);
    Edge edges[] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12};

    Node *nodesp = nodes;
    int nodeslength = sizeof(nodes)/sizeof(nodes[0]);
    int edgeslength = sizeof(edges)/sizeof(edges[0]);
    Edge *edgesp = edges;
    Algorithm newProcess(nodesp, nodeslength, edgesp, edgeslength, A, F);
    return 0;
}









