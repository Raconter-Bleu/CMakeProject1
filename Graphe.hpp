//
//  Graphe.hpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//

#ifndef Graphe_hpp
#define Graphe_hpp
#include "Node.hpp"
#include <string>
#include<stack>
#include <functional>
#include <vector> 
#include <iostream>

struct OptimalPath {
    std::vector<int> nodesID;
    double minWeight;
};

class Graphe {
    
    
private:
    int maxNodeCount;
    int maxEdgeCount;
    std::vector < std::vector<Edge> > graph;

public:
    Graphe():maxEdgeCount(0),maxNodeCount(0){}
    int getMaxNodeCount();
    void setMaxNodeCount(int maxNodeCount);
    int getMaxEdgeCount();
    void setMaxEdgeCount(int maxEdgeCount);
    std::stack<std::vector < std::vector<Edge> >> CircuitSearch ();
    //����һ��stack���������װ�ü���ͼ���������������Ļ���
    OptimalPath dijkstra();
    void setNodes(int* idNodes, int (*toId)[3]);
    std::string printGraphe();
    
};

#endif /* Graphe_hpp */
