#pragma once
#include "../../tree/tree.h"
#include "../../path-tree/path-tree.h"
#include "../../ranodm/random.h"
#include <random>




namespace query{

using Label=label::StringLabel;
using Node=node::Node<Label>;
using Supernode=supernode::Supernode;

void  fixed_generator(std::vector<Node>& trees_collection,std::vector<std::string>& result,std::string method,int num_val);

void  theta_generator(std::vector<Node>& trees_collection,std::vector<std::string>& result,std::string method,double theta);

std::string combine_vector(std::vector<int>& random_set);
void get_leaves(Node& root, std::vector<Node *>& root_leaves);


void  fixed_generator(std::vector<Node>& trees_collection,std::vector<std::string>& result,std::string method,int num_val){

    int tree_counter=0;
    for(auto tree: trees_collection){

        std::cout<<"generate query: "<<tree_counter<<std::endl;
        int tree_size=(int)tree.get_tree_size();

        std::vector<int> random_set;
        random_set.clear();

        if(method=="uniform"){
            random_generator::uniform(0,tree_size-1,num_val,random_set);            
        }

        if(method=="normal"){       
            get_leaves(tree,tree.get_leaf());
            int leaf_number=(int)tree.get_leaf().size();
            //std::cout<<"leaf number: "<<leaf_number<<std::endl;
            int ran_val=std::rand()%leaf_number;
            int ran_dev=std::rand()%(tree_size-1)+1;
            int ran_mean=tree.get_leaf()[ran_val]->id();


            random_generator::normal(tree_size-1,ran_mean,ran_dev,num_val,random_set);

        }

        if(method=="zipf"){

            int ran_alpha=std::rand()%4;

            random_generator::zipf(tree_size-1, ran_alpha,num_val,random_set);

        }

        result.push_back(combine_vector(random_set));
        tree_counter++;


    }

}


std::string combine_vector(std::vector<int>& random_set){
    std::string result;
    for(auto num: random_set){
        result=result+std::to_string(num)+"-";
    }

    result.erase(result.end()-1);

    return result;

}

void get_leaves(Node& root, std::vector<Node *>& root_leaves){
   
    if(root.is_leaf()){
        root_leaves.push_back(&root);
    }
    for(auto& child:root.get_children())
        get_leaves(child, root_leaves);
    
}


void  theta_generator(std::vector<Node>& trees_collection,std::vector<std::string>& result,std::string method,double theta){
    
     int tree_counter=0;
     for(auto tree: trees_collection){

         std::cout<<"generate query: "<<tree_counter<<std::endl;
        int tree_size=(int)tree.get_tree_size();

        std::vector<int> random_set;
        random_set.clear();

        if(method=="uniform"){
            int num_val=(int)((double)tree_size*theta);
            random_generator::uniform(0,tree_size-1,num_val,random_set);            
        }

        if(method=="normal"){       
            get_leaves(tree,tree.get_leaf());
            int leaf_number=(int)tree.get_leaf().size();
            //std::cout<<"leaf number: "<<leaf_number<<std::endl;
            int ran_val=std::rand()%leaf_number;
            int ran_dev=std::rand()%(tree_size-1)+1;
            int ran_mean=tree.get_leaf()[ran_val]->id();


            int num_val=(int)((double)tree_size*theta);
            random_generator::normal(tree_size-1,ran_mean,ran_dev,num_val,random_set);

        }

        if(method=="zipf"){

            int ran_alpha=std::rand()%4;


            int num_val=(int)((double)tree_size*theta);
            random_generator::zipf(tree_size-1, ran_alpha,num_val,random_set);

            for(int i=0;i<(int)random_set.size();i++){
                
                random_set[i]=(tree_size-1)-random_set[i];
            
            }

        }

        result.push_back(combine_vector(random_set));
        tree_counter++;


    }

}




}