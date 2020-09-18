#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <typeinfo>
#include "check.h"

namespace  adaptive{

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;

void sibling(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,int threshold);



void sibling(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,int threshold){
    
    //std::cout<<"-------->sibling search: "<<std::endl;
    
     int sibling_threshold=threshold;
     int out_degree=(int)root.children_count();
     int sibling_degree=root.sibling();
    
    
     int target_pos=check_children_reachablity(root, target, steps);
    
     if(target_pos==-1){
         target.set_depth(root.depth());
         found=true;
     }
    
    if(!found){
        
        if(out_degree/sibling_degree >=sibling_threshold){
               //std::cout<<"bfs"<<std::endl;
            
            if(sroot->is_contained(root.get_children()[target_pos].id()))
                sibling(root.get_children()[target_pos], target, sroot, found, steps, threshold);
            else{
                for(auto& schild: sroot->getChildren())
                    if(schild->is_contained(root.get_children()[target_pos].id()))
                        sibling(root.get_children()[target_pos], target, schild, found, steps, threshold);
            }
        }
        
        else{
            //std::cout<<"dfs"<<std::endl;
            int index=binary::binary_search_supernode(sroot, target, steps);
            //std::cout<<"binary result: "<<index<<std::endl;
            if(sroot->is_contained(sroot->getNodes()[index]->id())){
                    if(sroot->getNodes()[index]->id()!=root.id())
                       sibling(*(sroot->getNodes()[index]), target, sroot, found, steps, threshold);
                    else{
                        if(sroot->is_contained(root.get_children()[target_pos].id()))
                            sibling(root.get_children()[target_pos], target, sroot, found, steps, threshold);
                        else{
                            for(auto& schild: sroot->getChildren()){
                                if(schild->is_contained(root.get_children()[target_pos].id())){
                                    sibling(root.get_children()[target_pos], target, schild, found, steps, threshold);
                                }

                            }
                        }
                    }
                    
                       
            }
            else{
                for(auto& schild: sroot->getChildren()){
                    if(schild->is_contained(root.get_children()[target_pos].id())){
                        //index=binary::binary_search_supernode(schild, target, steps);
                        sibling(*(schild->getNodes()[index]), target, schild, found, steps, threshold);
                    }

                }
            }
            
                
              
        }
        
    }
    
}



}


