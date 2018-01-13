#include "Algorithm.h"
#include "Node.h"
#include "Edge.h"
using namespace std;
#include <iostream>
#include <limits>

int main()
{
    //all nodes
    Node Nought('-', 0);
    Node A('A');
    Node B('B');
    Node C('C');
    Node D('D');
    Node E('E');
    Node F('F');
    Node G('G');
    Node H('H');
    Node I('I');
    Node *nodes[] = {&Nought, &A, &B, &C, &D, &E, &F, &G, &H, &I};

    Node *nodesp = *nodes;
    int nodeslength = sizeof(nodes)/sizeof(nodes[0]);
    Node *noughtp = &Nought;

    //here to customize start and end node
    //simply replace address
    Node *startNodep = &A;
    Node *endNodep = &I;

    //all edges
    Edge e0(0, &Nought, startNodep);
    Edge e1(4, &A, &B);
    Edge e2(8, &B, &C);
    Edge e3(7, &C, &D);
    Edge e4(9, &D, &E);
    Edge e5(10, &E, &F);
    Edge e6(2, &F, &G);
    Edge e7(1, &G, &H);
    Edge e8(7, &H, &I);
    Edge e9(8, &H, &A);
    Edge e10(11, &H, &B);
    Edge e11(6, &I, &G);
    Edge e12(2, &I, &C);
    Edge e13(4, &C, &F);
    Edge e14(14, &D, &F);
    Edge *edges[] = {&e0, &e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12, &e13, &e14};

    Edge *edgesp = *edges;
    int edgeslength = sizeof(edges)/sizeof(edges[0]);

    Algorithm newProcess(nodesp, nodeslength, edgesp, edgeslength, noughtp, endNodep);

    return 0;
}









