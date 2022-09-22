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
    //��¼���ﵱǰ��������һ���� 

    std::stack<std::vector<Node>>circuit[100];
    int n_circuit = 0;
    //������this�����ڳ������ʽ��ʹ�á�  ���������ó���������100��

    std::vector<bool>visited ( maxNodeCount, false );
    std::vector<bool>onStack ( maxEdgeCount, false );
    //��¼�����ͷ��ʵ�����
    /*std::vector<Node>notes_temp = nodes;*/
    //Ĭ�ϴ�0�㿪ʼ����
    
    std::function<void(int)> DFS = [&] (int v) {
       
        onStack[v] = true;
        visited[v] = true;
    
        for(int i = 0; i < maxNodeCount; i++)
        {
          
            for(std::vector<Edge>::iterator it = nodes[i].getEdges ().begin(); it != nodes[i].getEdges ().end (); it++)
            {
                int w = (*it).getToId();
                if(!visited[w])   //��Vû�����ʹ��������ݹ�. V��from��W��to����������������������
                {
                    edgeTo[w] = *it;   //��¼ÿ�������һ�α�����ʱ����ƨ�ɺ��Ÿ���������
                    DFS ( w );
                }
                else if(onStack[w])  //������㱻���ʹ���������������ڷ�����ʷ��¼ջ�˵��������һ����
                {
                    //��������Ҫ�����ǣ��Ȱ��������뵽���У�Ȼ���ٰ������ƨ�ɺ�����ı߼��뵽������У�Ȼ��ͨ��whileѭ��ֱ����һȦ
                    std::vector<Node> circuit_temp;//��¼������ʱͼͼ

                    Edge edge_temp = *it;//��ʱһ����

                    std::vector<Edge>edges_temp;//��ʱ�߼��ϣ����ڸ�node��ֵ
                    edges_temp.push_back ( edge_temp );

                    Node node_tempFrom ( v );//��ʱfrom��

                    Node node_tempTo ( w );//��ʱto��

                    circuit_temp.push_back ( node_tempTo );

                    while(node_tempFrom.getId() != w){
                        circuit_temp.push_back ( v );
                        node_tempFrom.setEdges ( edges_temp );

                        //������ѭ������
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
