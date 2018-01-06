#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>
#include <limits>

int main()
{
    Node A('A');
    Node B('B');
    Node C('C');
    Node D('D');
    Node E('E');
    Node F('F');
    Node G('G');
    Node *nodes[] = {&A, &B, &C, &D, &E, &F, &G};

    Edge e1(4, &A, &B);
    Edge e2(3, &A, &C);
    Edge e3(7, &A, &E);
    Edge e4(6, &B, &C);
    Edge e5(11, &C, &D);
    Edge e6(8, &C, &E);
    Edge e7(5, &B, &D);
    Edge e8(2, &E, &D);
    Edge e9(5, &E, &G);
    Edge e10(10, &D, &G);
    Edge e11(2, &D, &F);
    Edge e12(3, &G, &F);
    Edge *edges[] = {&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12};

    Node *nodesp = *nodes;
    int nodeslength = sizeof(nodes)/sizeof(nodes[0]);
    int edgeslength = sizeof(edges)/sizeof(edges[0]);
    Edge *edgesp = *edges;
    Node *startNodep = &A;
    Node *endNodep = &F;
    Algorithm newProcess(nodesp, nodeslength, edgesp, edgeslength, startNodep, endNodep);

    return 0;
}









