//
//  adaptive_sbling.h
//  adaptive_sbling
//
//  Created by Bowen Li on 4/8/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <typeinfo>

namespace  adaptive{

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


int check_children_reachablity(Node & node, Node& target, int& steps);


int check_children_reachablity(Node & node, Node& target, int& steps){
    //std::cout<<"checking"<<std::endl;
    int target_pos=-1;
    
    
    std::vector<std::pair<int, int>> sort_vector;
    int pos=0;
    if((int)node.children_count()>1){
        for(auto& child: node.get_children()){
            sort_vector.push_back(std::make_pair(pos, (int)child.get_tree_size()));
            pos++;
        }
        std::sort(sort_vector.begin(),sort_vector.end(),interleave::nodes_sort);
    }
    
    if(node.children_count()==1){
        if(Reachability::Reachability(node.get_children()[0], target, steps))
            target_pos=0;
    }
    else{
        for(int i=0;i<(int)sort_vector.size();i++){
            //std::cout<<"node id:"<<node_id<<std::endl;
            if(Reachability::Reachability(node.get_children()[sort_vector[i].first], target,steps)){
                   target_pos=sort_vector[i].first;
                   break;
            }
        }
    }

    return target_pos;
}








}


