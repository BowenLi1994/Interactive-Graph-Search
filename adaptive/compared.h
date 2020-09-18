#pragma once

#include <map>
#include <vector>
#include <math.h>
#include "check.h"


namespace adaptive{


using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;



void compared(Node& root,Node& target,Supernode * sroot, bool& found, int& steps);

void compared(Node& root,Node& target,Supernode * sroot, bool& found, int& steps){
    
    
    struct tree_parameter result;
    result=tree_analyse(root); 

    if(result.tree_path==0)
        result.tree_path=1;   

    double wide_metric =(double)root.children_count();
    double long_metric  =(double)std::log(result.tree_path)/(double)std::log(2);

    // std::cout<<"path long: "<<result.tree_path<<std::endl;
    // std::cout<<"wide: "<<wide_metric<<" long: "<<long_metric<<std::endl;

    int target_pos=check_children_reachablity(root, target, steps);
       
    if(target_pos==-1){
        target.set_depth(root.depth());
        found=true;
    }

    if(!found){

        //bfs
        if(wide_metric <= long_metric){       
            if(sroot->is_contained(root.get_children()[target_pos].id()))
                compared(root.get_children()[target_pos], target, sroot, found, steps);
            else{
                for(auto& schild: sroot->getChildren())
                    if(schild->is_contained(root.get_children()[target_pos].id()))
                        compared(root.get_children()[target_pos], target, schild, found, steps);
            }
        }
        //dfs
        else{
            //std::cout<<"dfs"<<std::endl;
            int index= binary::binary_search_supernode(sroot, target, steps);
            // //std::cout<<"binary result: "<<index<<std::endl;
            if(sroot->is_contained(sroot->getNodes()[index]->id())){
                if(sroot->getNodes()[index]->id()!=root.id())
                    compared(*(sroot->getNodes()[index]), target, sroot, found, steps);
                else{
                    if(sroot->is_contained(root.get_children()[target_pos].id()))
                        compared(root.get_children()[target_pos], target, sroot, found, steps);
                    else{
                        for(auto& schild: sroot->getChildren()){
                            if(schild->is_contained(root.get_children()[target_pos].id()))
                                compared(root.get_children()[target_pos], target, schild, found, steps);
                        }

                        }
                }
            }
            else{
                for(auto& schild: sroot->getChildren()){
                    if(schild->is_contained(root.get_children()[target_pos].id()))
                        compared(*(schild->getNodes()[index]), target, schild, found, steps);
                }

            }
        } 

        

    }
    
}



}      

    // if(!found){
        
    //     if(wide_metric <= long_metric){
        
    //         if(sroot->is_contained(root.get_children()[target_pos].id()))
    //             compared(root.get_children()[target_pos], target, sroot, found, steps);
    //         else{
    //             for(auto& schild: sroot->getChildren())
    //                 if(schild->is_contained(root.get_children()[target_pos].id()))
    //                     compared(root.get_children()[target_pos], target, schild, found, steps);
    //         }
    //     }
        
    //     else{
    //         //std::cout<<"dfs"<<std::endl;
    //         int index= binary::binary_search_supernode(sroot, target, steps);
    //         //std::cout<<"binary result: "<<index<<std::endl;
    //         if(sroot->is_contained(sroot->getNodes()[index]->id())){
    //                 if(sroot->getNodes()[index]->id()!=root.id())
    //                   compared(*(sroot->getNodes()[index]), target, sroot, found, steps);
    //                 else{
    //                     if(sroot->is_contained(root.get_children()[target_pos].id()))
    //                         compared(root.get_children()[target_pos], target, sroot, found, steps);
    //                     else{
    //                         for(auto& schild: sroot->getChildren()){
    //                             if(schild->is_contained(root.get_children()[target_pos].id())){
    //                                 compared(root.get_children()[target_pos], target, schild, found, steps);
    //                             }

    //                         }
    //                     }
    //                 }
                    
                       
    //         }
    //         else{
    //             for(auto& schild: sroot->getChildren()){
    //                 if(schild->is_contained(root.get_children()[target_pos].id())){
    //                     //index=binary::binary_search_supernode(schild, target, steps);
    //                     compared(*(schild->getNodes()[index]), target, schild, found, steps);
    //                 }

    //             }
    //         }
            
                
              
    //     }
        
    // }
 
    