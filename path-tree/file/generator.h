#pragma once

#include"../path-tree.h"

namespace path_tree_file {

using Label=label::StringLabel;
using Node=node::Node<label::StringLabel>;
using Supernode= supernode::Supernode;






void generator(std::vector<Supernode *>& supernodes_collection,std::vector<std::string>& paths_string);
void singel_generator(Supernode * sroot,std::string& path_string);
std::string nodes_combine(Supernode* snode);



void generator(std::vector<Supernode *>& supernodes_collection,std::vector<std::string>& paths_string){
    
    for(auto supernode: supernodes_collection){
        
        std::string path_string;
        singel_generator(supernode,path_string);
        paths_string.push_back(path_string);
        //std::cout<<path_string<<std::endl;
        

        
    }
    
    
    
}

std::string nodes_combine(Supernode* snode){
    std::string combined_node;
    for(auto node: snode->getNodes())
        combined_node=combined_node+std::to_string(node->id())+"-";
    
    combined_node.erase(combined_node.end()-1);
    return combined_node;
}


void singel_generator(Supernode * sroot, std::string& path_string){
        
    path_string+="{";
    std::string combined_node=nodes_combine(sroot);
    path_string+=combined_node;
    for(auto schild: sroot->getChildren()){
        singel_generator(schild, path_string);
    }
    path_string+="}";
    
}


     
    
}



