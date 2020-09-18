#pragma once

#include <map>
#include "check.h"
namespace adaptive{


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;



void comprehensive(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,double threshold);



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








}


