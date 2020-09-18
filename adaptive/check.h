#pragma once

#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <typeinfo>

#include "../interleave/interleave_ordered.h"
#include "../path-tree/path-tree.h"

namespace  adaptive{

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


int check_children_reachablity(Node & node, Node& target, int& steps);

struct tree_parameter{
    
    int tree_size;
    int tree_fanout;
    int tree_path;
    
};


struct tree_parameter tree_analyse(Node& node);
void get_depth_recusive(Node& node, std::vector<int>& depth);

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



struct tree_parameter tree_analyse(Node& node){
    struct tree_parameter result;
    std::vector<int> depth_set;
    get_depth_recusive(node, depth_set);

//    for(auto depth:depth_set){
//        std::cout<<"node depth: "<<depth<<std::endl;
//    }

    std::map<int, int> depth_map;
    //int max_depth;
    
    for(auto depth : depth_set){
        std::map<int,int>::iterator it;
        it=depth_map.find(depth);
        if(it!=depth_map.end()){
            it->second++;
        }
        else{
            depth_map.emplace(depth, 1);
        }
    }
    
    int size_temp;
    int path_temp;
    int width_temp;

    // for(auto it = depth_map.cbegin(); it != depth_map.cend(); ++it){
    //     std::cout <<it->first << " " << it->second<< "\n";
    // }
    // for(auto map: depth_map){
    //     std:cout<<" depth: "<<map.first<<" number: "<<map.second<<std::endl;
    // }
    
    if(depth_map.size()==0){
        size_temp=path_temp=width_temp=0;
    }
    else if(depth_map.size()==1){
        size_temp=1;
        path_temp=1;
        width_temp=1;
    }
    else{
        size_temp=node.get_tree_size();
        std::map<int, int>::iterator it=depth_map.end();
        path_temp=(--it)->first-depth_map.begin()->first+1;
        //std::cout<<"length: "<<path_temp<<std::endl;

        // std::cout<<"begin: "<<depth_map.begin()->first<<" "<<depth_map.begin()->second<<std::endl;
        

        // std::cout<<"end: "<<(--it)->first<<" "<<depth_map.end()->second<<std::endl;
        int max_value=0;
        for(auto pair :depth_map){
            if(pair.second>max_value)
                max_value=pair.second;
        }
        width_temp=max_value;
        

    }
    
    result.tree_fanout=width_temp;
    result.tree_path=path_temp;
    result.tree_size=size_temp;
    
    
    return result;
}



void get_depth_recusive(Node& node, std::vector<int>& depth){
    
    depth.push_back(node.depth());
    for(auto& child: node.get_children()){
        get_depth_recusive(child, depth);
    }
}



}


