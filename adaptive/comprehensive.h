//
//  adaptive_comprehensize.h
//  adaptive_comprehensive
//
//  Created by Bowen Li on 4/12/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once

#include <map>

namespace adaptive{


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;

struct tree_parameter{
    
    int tree_size;
    int tree_fanout;
    int tree_path;
    
};


struct tree_parameter tree_analyse(Node& node);

void comprehensive(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,double threshold);
void get_depth_recusive(Node& node, std::vector<int>& depth);


void comprehensive(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,double threshold){
    
    
    struct tree_parameter result;
    result=tree_analyse(root);
    double comprhensive_threshold=threshold;
    double tree_threshold=(double)(result.tree_size*result.tree_fanout)/double(result.tree_path+1);
    
    
    int target_pos=check_children_reachablity(root, target, steps);
       
    if(target_pos==-1){
        target.set_depth(root.depth());
        found=true;
    }
    
    if(!found){
        
        if(tree_threshold >= comprhensive_threshold){
        
            if(sroot->is_contained(root.get_children()[target_pos].id()))
                comprehensive(root.get_children()[target_pos], target, sroot, found, steps, threshold);
            else{
                for(auto& schild: sroot->getChildren())
                    if(schild->is_contained(root.get_children()[target_pos].id()))
                        comprehensive(root.get_children()[target_pos], target, schild, found, steps, threshold);
            }
        }
        
        else{
            //std::cout<<"dfs"<<std::endl;
            int index=binary::binary_search_supernode(sroot, target, steps);
            //std::cout<<"binary result: "<<index<<std::endl;
            if(sroot->is_contained(sroot->getNodes()[index]->id())){
                    if(sroot->getNodes()[index]->id()!=root.id())
                       comprehensive(*(sroot->getNodes()[index]), target, sroot, found, steps, threshold);
                    else{
                        if(sroot->is_contained(root.get_children()[target_pos].id()))
                            comprehensive(root.get_children()[target_pos], target, sroot, found, steps, threshold);
                        else{
                            for(auto& schild: sroot->getChildren()){
                                if(schild->is_contained(root.get_children()[target_pos].id())){
                                    comprehensive(root.get_children()[target_pos], target, schild, found, steps, threshold);
                                }

                            }
                        }
                    }
                    
                       
            }
            else{
                for(auto& schild: sroot->getChildren()){
                    if(schild->is_contained(root.get_children()[target_pos].id())){
                        //index=binary::binary_search_supernode(schild, target, steps);
                        comprehensive(*(schild->getNodes()[index]), target, schild, found, steps, threshold);
                    }

                }
            }
            
                
              
        }
        
    }
 
    
    
    
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
        path_temp=depth_map.end()->first-depth_map.begin()->first+1;
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


