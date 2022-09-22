//
//  Edge.hpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <vector>

class Edge{
private:
    double weight;
      
    int toId;
    
    int fromId;
    
public:
    Edge(int fromId,int toId, double weight);
    double getWeight();
    void setWeight(double Weight);
    int getToId();
    void setToId(int toId);
    int getFromId ();
    void setFromId ( int toId );

    
};
#endif /* Edge_hpp */
