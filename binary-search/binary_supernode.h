//
//  baseline.h
//  igs
//
//  Created by Bowen Li on 2/16/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once

#include<vector>
#include<string>
#include <typeinfo>



#include "../tree/label/string_label.h"
#include "../tree/node/node.h"
#include "../others/reachability.h"
#include "../path-tree/path-tree.h"


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;

namespace binary{

int binary_search_supernode(Supernode* supernode, Node& target,int &step);


int binary_search_supernode_recurion(Supernode* supernode,Node& target,int begin,int end,int &step);


int binary_search_supernode(Supernode* supernode, Node& target,int& step){
    
    int begin=0;
    int end=(int)supernode->nodes_count()-1;

    
    
    
    
    
    return binary_search_supernode_recurion(supernode, target,begin,end,step);;
}
     
     
     
int binary_search_supernode_recurion(Supernode* supernode,Node& target,int begin,int end,int &step){
    
    
    //std::cout<<"binary search: "<<"node: "<<target.id()<<" begin: "<<begin<<" end: "<<end<<std::endl;
    int index=-1;
    
    //basecase:
    if(end==begin){
        
        //std::cout<<"base: "<<std::endl;
        if(Reachability::Reachability(*(supernode->getNodes()[begin]), target, step))
            return begin;
        else
            return -1;
    }
    
    
    int mid_index=begin+(end-begin)/2;
    
    //std::cout<<"mid index: "<<mid_index<<std::endl;
    
    if(Reachability::Reachability(*supernode->getNodes()[mid_index], target, step)){
        //std::cout<<"mid can reach"<<std::endl;
        index=mid_index;
        if(mid_index+1>end)
            mid_index=end-1;
        int right_index=binary_search_supernode_recurion(supernode, target,mid_index+1, end,step);
        if(right_index!=-1)
            index=right_index;
        
    }
    
     else{
         //std::cout<<"mid cannot reach"<<std::endl;
         if(mid_index==begin)
             return -1;
        int left_index=binary_search_supernode_recurion(supernode, target, begin,mid_index-1, step);
        index=left_index;
    }
    
    return index;
    
    
}


}


