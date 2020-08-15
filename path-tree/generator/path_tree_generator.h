//
//  path_tree_generator.h
//  tree_interleave
//
//  Created by Bowen Li on 3/4/20.
//  Copyright © 2020 Bowen Li. All rights reserved.
//

#pragma once


#include "../../tree/node/node.h"
#include "../../tree/label/string_label.h"
#include "../../others/reachability.h"
#include "../../path-tree/super_node/supernode.h"

namespace path_tree_generator {

using Label=label::StringLabel;
using Node=node::Node<label::StringLabel>;
using Supernode= supernode::Supernode;






void single_path_tree_generator(Node& root,std::vector<Supernode *>& tree_paths);

//(1)find the node with the largest subtree size among all children
void first_time_tag(Node& node,std::vector<int>& heavy_id);

//(2) generate the heavy path
void second_time_retrive(Node& node,std::vector<int>& heavy_id,std::vector<Supernode *>& tree_paths);
void generate_path(Node&node,Supernode* snode);

//(3)link the heavy path
void third_time_link(std::vector<Supernode *>& tree_paths);
//a node in snode1 should parent the first node in snode2
bool check_supernode_link(Supernode* snode1,Supernode* snode2);


void heavy_path_trees_collection_generator(std::vector<Node>& trees_collection, std::vector<Supernode* >& Supernodes_collection);


void single_path_tree_generator(Node& root,std::vector<Supernode *>& tree_paths){
    
     std::vector<int> heavy_id;
    
     first_time_tag(root, heavy_id);
     second_time_retrive(root, heavy_id,tree_paths);
    int path_counter=0;
    for(auto path:tree_paths){
        path->set_id(path_counter);
        path_counter++;
    }
     third_time_link(tree_paths);
    
}


void first_time_tag(Node& node,std::vector<int>& heavy_id){
    
    
    //std::cout<<"root: "<<node.id()<<std::endl;
    
    if(node.is_leaf())
        return;
    
    int max_degree=0;
    int max_index=0;
    //bool
    for(int i=0;i<(int)node.children_count();i++){
        int subtree_size=node.get_children()[i].get_tree_size();
        if(subtree_size>max_degree){
            max_degree=subtree_size;
            max_index=i;
        }
    }
    //std::cout<<"max index: "<<max_index<<std::endl;
    
    heavy_id.push_back(node.get_children()[max_index].id());
    for(auto& child:node.get_children())
        first_time_tag(child, heavy_id);
    

}


void second_time_retrive(Node& node,std::vector<int>& heavy_id,std::vector<Supernode *>& tree_paths){

    bool exsit_flag=0;
    
    for(auto i:heavy_id)
        if(i==node.id())
            exsit_flag=1;

    if(exsit_flag==0){
        Supernode* snode=new Supernode;
        generate_path(node, snode);
        tree_paths.push_back(snode);
    }

    for(auto& child:node.get_children())
        second_time_retrive(child, heavy_id, tree_paths);



}

void generate_path(Node&node,Supernode* snode){
    snode->add_node(&node);
    int max_degree=0;
    int max_index=0;
    if(node.is_leaf())
        return;
    for(int i=0;i<(int)node.children_count();i++){
        int subtree_size=node.get_children()[i].get_tree_size();
        if(subtree_size>max_degree){
            max_degree=subtree_size;
            max_index=i;
        }
    }
    generate_path(node.get_children()[max_index], snode);

}


void third_time_link(std::vector<Supernode *>& tree_paths){

    for(auto path1:tree_paths)
        for(auto path2:tree_paths)
            if(check_supernode_link(path1, path2))
                path1->add_child(path2);
}







//a node in snode1 should parent the first node in snode2
bool check_supernode_link(Supernode* snode1,Supernode* snode2){
    bool flag=false;
    int target_id=snode2->getNodes()[0]->id();

    for(auto& node: snode1->getNodes())
        for(auto& child:node->get_children())
            if(child.id()==target_id)
                flag=true;


    return flag;
}




void heavy_path_trees_collection_generator(std::vector<Node>& trees_collection, std::vector<Supernode* >& Supernodes_collection){

    int tree_number=(int)trees_collection.size();
    for(int i=0;i<tree_number;i++){

        std::vector<Supernode *> tree_paths;
        single_path_tree_generator(trees_collection[i], tree_paths);

        Supernodes_collection.push_back(tree_paths[0]);

    }

}



     
    
}



