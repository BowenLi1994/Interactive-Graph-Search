#pragma once

#include <map>
#include "check.h"
#include <math.h>
namespace adaptive{


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;



void comprehensive(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,double threshold,double alpha1,double alpha2,double alpha3);



void comprehensive(Node& root,Node& target,Supernode * sroot, bool& found, int& steps,double threshold,double alpha1,double alpha2,double alpha3){
    
    
    struct tree_parameter result;
    result=tree_analyse(root);
    double comprhensive_threshold=threshold;
    //std::cout<<"pow: "<<pow(result.tree_size,alpha)<<std::endl;
    double wide_metric=(double)pow(result.tree_fanout,alpha1);
    double size_metric=(double)pow(result.tree_size,alpha2);
    double long_metric=(double)pow(result.tree_path,alpha3);
    double tree_threshold=wide_metric*size_metric/(long_metric+1);
    //std::cout<<"threshold: "<<tree_threshold<<std::endl;
    
    
    int target_pos=check_children_reachablity(root, target, steps);
       
    if(target_pos==-1){
        target.set_depth(root.depth());
        found=true;
    }
    
    if(!found){
        
        if(tree_threshold <= comprhensive_threshold){
        
            if(sroot->is_contained(root.get_children()[target_pos].id()))
                comprehensive(root.get_children()[target_pos], target, sroot, found, steps, threshold,alpha1,alpha2,alpha3);
            else{
                for(auto& schild: sroot->getChildren())
                    if(schild->is_contained(root.get_children()[target_pos].id()))
                        comprehensive(root.get_children()[target_pos], target, schild, found, steps, threshold,alpha1,alpha2,alpha3);
            }
        }
        
        else{
            //std::cout<<"dfs"<<std::endl;
            int index=binary::binary_search_supernode(sroot, target, steps);
            //std::cout<<"binary result: "<<index<<std::endl;
            if(sroot->is_contained(sroot->getNodes()[index]->id())){
                    if(sroot->getNodes()[index]->id()!=root.id())
                       comprehensive(*(sroot->getNodes()[index]), target, sroot, found, steps, threshold,alpha1,alpha2,alpha3);
                    else{
                        if(sroot->is_contained(root.get_children()[target_pos].id()))
                            comprehensive(root.get_children()[target_pos], target, sroot, found, steps, threshold,alpha1,alpha2,alpha3);
                        else{
                            for(auto& schild: sroot->getChildren()){
                                if(schild->is_contained(root.get_children()[target_pos].id())){
                                    comprehensive(root.get_children()[target_pos], target, schild, found, steps, threshold,alpha1,alpha2,alpha3);
                                }

                            }
                        }
                    }
                    
                       
            }
            else{
                for(auto& schild: sroot->getChildren()){
                    if(schild->is_contained(root.get_children()[target_pos].id())){
                        //index=binary::binary_search_supernode(schild, target, steps);
                        comprehensive(*(schild->getNodes()[index]), target, schild, found, steps, threshold,alpha1,alpha2,alpha3);
                    }

                }
            }
            
                
              
        }
        
    }
 
    
    
    
}








}


