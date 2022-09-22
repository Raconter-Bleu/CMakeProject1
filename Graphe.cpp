//
//  Graphe.cpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//

#include "Graphe.hpp"

//Graphe::Graphe(){
//    maxNodeCount = 0;
//    maxEdgeCount = 0;
//}

int Graphe::getMaxNodeCount(){
    return maxNodeCount;
}
void Graphe::setMaxNodeCount(int maxNodeCount){
    this->maxNodeCount = maxNodeCount;
}
int Graphe::getMaxEdgeCount(){
    return maxEdgeCount;
}
void Graphe::setMaxEdgeCount(int maxEdgeCount){
    this->maxEdgeCount = maxEdgeCount;
}

void Graphe::setNodes(int* idNodes, int (*toId)[3]){
    for (int i=0 ; i< maxNodeCount; i++) {
        Node node(idNodes[i]);
        std::vector<Edge> edges;
        for (int j=0; j<maxEdgeCount; j++) {
            if (toId[j][0] == idNodes[i]) {
                Edge e(toId[j][1],toId[j][2]);
                edges.push_back(e);
            }
        }
        node.setEdges(edges);
        
        this->nodes.push_back(node);
    }
    
}


std::stack<std::vector<Node>> Graphe::CircuitSearch(){
    std::vector<Edge>edgeTo;
    //记录到达当前顶点的最后一条边 

    std::stack<std::vector<Node>>circuit[100];
    int n_circuit = 0;
    //报错：”this不能在常量表达式中使用“  ，所以先用常数，开个100个

    std::vector<bool>visited ( maxNodeCount, false );
    std::vector<bool>onStack ( maxEdgeCount, false );
    //记录遍历和访问的数组
    /*std::vector<Node>notes_temp = nodes;*/
    //默认从0点开始遍历
    
    std::function<void(int)> DFS = [&] (int v) {
       
        onStack[v] = true;
        visited[v] = true;
    
        for(int i = 0; i < maxNodeCount; i++)
        {
          
            for(std::vector<Edge>::iterator it = nodes[i].getEdges ().begin(); it != nodes[i].getEdges ().end (); it++)
            {
                int w = (*it).getToId();
                if(!visited[w])   //点V没被访问过，继续递归. V是from，W是to！！！！！！！！！！！
                {
                    edgeTo[w] = *it;   //记录每个点最后一次被访问时，点屁股后门跟的那条边
                    DFS ( w );
                }
                else if(onStack[w])  //这个顶点被访问过，并且这个顶点在访问历史记录栈里，说明发现了一个环
                {
                    //我们现在要做的是，先把这个点加入到环中，然后再把这个点屁股后面跟的边加入到这个点中，然后通过while循环直到绕一圈
                    std::vector<Node> circuit_temp;//记录环的临时图图

                    Edge edge_temp = *it;//临时一条边

                    std::vector<Edge>edges_temp;//临时边集合，用于给node赋值
                    edges_temp.push_back ( edge_temp );

                    Node node_tempFrom ( v );//临时from点

                    Node node_tempTo ( w );//临时to点

                    circuit_temp.push_back ( node_tempTo );

                    while(node_tempFrom.getId() != w){
                        circuit_temp.push_back ( v );
                        node_tempFrom.setEdges ( edges_temp );

                        //下面是循环条件
                        edge_temp = edgeTo[node_tempFrom.getId ()];
                        node_tempTo = node_tempFrom.getId ();
                        node_tempFrom=
                                        
                    }
                    circuit[n_circuit].push ( circuit_temp );


                }


            }
        }
        
        
    
    };


    return ;
}
OptimalPath Graphe::dijkstra(){
    OptimalPath optimalPath;
    
    
    
    
    return optimalPath;
}

std::string Graphe::printGraphe(){
    std::string str = "";
    for (int i =0 ; i<maxNodeCount; i++) {
        
        str += "Node "+std::to_string(this->nodes[i].getId())+ ": \n ";

        for (int j=0; j<this->nodes[i].getEdges().size(); j++) {
            str += " "+std::to_string(this->nodes[i].getEdges()[j].getToId());
            str += " weight = " + std::to_string ( this->nodes[i].getEdges ()[j].getWeight( ));
        }
        str +="\n";
        
    }
    
    
    
    
    return str;
}
