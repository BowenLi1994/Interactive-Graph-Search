

#pragma once


#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../tree/tree.h"
#include "../path-tree/path-tree.h"
#include "../binary-search/binary_supernode.h"

namespace interleave {

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;


struct id_frequency_size{
    int pos_;
    int frequency_;
    int subtree_size_;
    id_frequency_size(int pos,int frequency, int subtree_size):pos_(pos),frequency_(frequency),subtree_size_(subtree_size){}
    
};


void frquency(const Node &root, Supernode* sroot,Node& target,bool&found,int& steps);

bool frequency_sort (const struct id_frequency_size& i,const struct id_frequency_size& j);


void frequency(const Node &root, Supernode* sroot,Node& target,bool&found, int& steps){
     
    // std::cout<<"sroot: "<<std::endl;
    // sroot->print_all_nodes();


    if(found==false){
        
        int binary_index=binary::binary_search_supernode(sroot, target, steps);
        bool child_flag=false;

        // std::cout<<"binary search result index: "<<binary_index<<std::endl;
        
        // for(auto node: sroot->getNodes()[binary_index]->get_children()){
        //     std::cout<<"node: "<<node.id()<<" frequency: "<<node.get_tree_frequency()<<" subtree size: "<<node.get_tree_size()<<std::endl;
        // }

        std::vector<struct id_frequency_size> sort_vector;

        for(int i=0;i<(int)sroot->getNodes()[binary_index]->get_children().size();i++){
            int pos=i;
            int subtree_frequency=sroot->getNodes()[binary_index]->get_children()[i].get_tree_frequency();
            int subtree_size=sroot->getNodes()[binary_index]->get_children()[i].get_tree_size();
            struct id_frequency_size temp(pos,subtree_frequency,subtree_size);
            sort_vector.push_back(temp);
        }

        std::sort(sort_vector.begin(),sort_vector.end(),frequency_sort);

        // for(auto ifs:sort_vector){
        //    std::cout<<"node: "<<sroot->getNodes()[binary_index]->get_children()[ifs.pos_].id()<<" frequency: "<<sroot->getNodes()[binary_index]->get_children()[ifs.pos_].get_tree_frequency()<<" subtree size: "<<sroot->getNodes()[binary_index]->get_children()[ifs.pos_].get_tree_size()<<std::endl;
        // }





        int target_pos=-1;
        
        
        for(int i=0;i<(int)sort_vector.size();i++){
             int pos=sort_vector[i].pos_;
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
            target.set_depth(sroot->getNodes()[binary_index]->depth());
            found=true;
        }
        else{
            
            for(auto& schild: sroot->getChildren()){
                if(schild->is_contained(sroot->getNodes()[binary_index]->get_children()[target_pos].id()))
                   frequency(sroot->getNodes()[binary_index]->get_children()[target_pos], schild, target, found, steps);
            }
            
        }
    }
          
 }
     
     
    

bool frequency_sort (const struct id_frequency_size& i,const struct id_frequency_size& j)
{
    if(i.frequency_!=j.frequency_)
        return i.frequency_ > j.frequency_;
    else
    {
        return i.subtree_size_>j.subtree_size_;
    }
    
}



}



