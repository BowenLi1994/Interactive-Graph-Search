

#pragma once


#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../binary-search/binary_supernode.h"

namespace interleave {

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


void ordered(const Node &root, Supernode* sroot,Node& target,bool&found,int& steps);
bool nodes_sort (const std::pair<int, int>& i,const std::pair<int, int>& j);


void ordered(const Node &root, Supernode* sroot,Node& target,bool&found, int& steps){
     
    // std::cout<<"root: "<<root.id()<<std::endl;
    // std::cout<<"super node: "<<std::endl;
    // sroot->print_all_nodes();
    
    
//    if(sroot->nodes_count()==1){
//        return;
//    }
    
    if(found==false){
        
        int binary_index=binary::binary_search_supernode(sroot, target, steps);
        //std::cout<<"binary search result: "<<binary_index<<std::endl;
//        if(binary_index==0){
//            steps--;
//        }
        bool child_flag=false;
        
        
        std::vector<std::pair<int, int>> sort_vector;
        for(int i=0;i<(int)sroot->getNodes()[binary_index]->get_children().size();i++){
            int pos=i;
            int subtree_size=(int)sroot->getNodes()[binary_index]->get_children()[i].get_tree_size();
            sort_vector.push_back(std::make_pair(pos,subtree_size));
        }
        std::sort(sort_vector.begin(),sort_vector.end(),nodes_sort);

        int target_pos=-1;
        
        
        for(int i=0;i<(int)sort_vector.size();i++){
             int pos=sort_vector[i].first;
             //std::cout<<"child: "<<sroot->getNodes()[binary_index]->get_children()[pos].id()<<" right sibling: "<<sroot->getNodes()[binary_index]->get_children()[pos].right_sibling()<<std::endl;
             if(!sroot->is_contained(sroot->getNodes()[binary_index]->get_children()[pos].id())){
                 if(Reachability::Reachability(sroot->getNodes()[binary_index]->get_children()[pos], target, steps)){
                     child_flag=true;
                     target_pos=pos;
                     break;
                 }
             }
         }
            
        if(!child_flag){

            //std::cout<<"target node: "<<sroot->getNodes()[binary_index]->id()<<std::endl;
            target.set_depth(sroot->getNodes()[binary_index]->depth());
            found=true;
        }
        else{
            
            for(auto& schild: sroot->getChildren()){
                if(schild->is_contained(sroot->getNodes()[binary_index]->get_children()[target_pos].id()))
                    ordered(sroot->getNodes()[binary_index]->get_children()[target_pos], schild, target, found, steps);
            }
            
        }
    }
          
 }
     
     
    

bool nodes_sort (const std::pair<int, int>& i,const std::pair<int, int>& j)
{
   return i.second > j.second;
}



}



