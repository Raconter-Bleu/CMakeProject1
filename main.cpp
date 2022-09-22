//
//  main.cpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//


#include "Graphe.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int nodes[7] = {0,1,2,3,4,5,6};
    int edges[][3] = {
        {0,1,2000},
        {0,2,2400},
        {0,3,3600},
        {1,2,2000},
        {1,3,2600},
        {2,3,2000},
        {2,4,3400},
        {2,6,8600},
        {3,4,2000},
        {3,5,4000},
        {3,6,4800},
        {4,5,2000},
        {4,6,2100},
        {5,6,2000}
        
        
    };
    
    Graphe graphe;
    graphe.setMaxEdgeCount(sizeof(edges)/sizeof(int)/3);
    graphe.setMaxNodeCount(7);
    graphe.setNodes(nodes, edges);

    std::cout << graphe.printGraphe()<<std::endl;

    return 0;
}
