
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <random>

#include "../tree/tree.h"
#include "../modfication/tree_string.h"

using Label=label::StringLabel;
using Node=node::Node<Label>;

void get_leaves(Node& root, std::vector<Node *>& root_leaves);
void concatnate(std::string filename, int trees_number);

void get_leaves(Node& root, std::vector<Node *>& root_leaves){
   
    if(root.is_leaf()){
        root_leaves.push_back(&root);
    }
    for(auto& child:root.get_children())
        get_leaves(child, root_leaves);
    
}

void concatnate(std::string filename, int trees_number){
    

    std::string filepath=functions::getFilePath(filename);
    if(filepath=="NULL")
        return;
    
    parser::BracketNotationParser bnp;
    std::vector<Node> trees_collection;
    bnp.parse_collection(trees_collection, filepath);
    
   
    


    std::string sTreenum =std::to_string(trees_number);
    std::string outfile_name="concatnate_"+sTreenum;
    std::string outfile_path="/home/bowen/igs_dataset/amazon/manual/";
    std::ofstream outfile(outfile_path+outfile_name+".tree");

    if(!outfile.is_open()){
        std::cout<<"cannot open file: "<<outfile_name<<std::endl;
        return;
    }

    for(int i=0;i<trees_number;i++){

        int trees_pos=rand()%(int)trees_collection.size();
        get_leaves(trees_collection[trees_pos], trees_collection[trees_pos].get_leaf());
        int leaves_pos=rand()%(int)trees_collection[trees_pos].get_leaf().size();

        int trees_pos2=rand()%(int)trees_collection.size();
        trees_collection[trees_pos].get_leaf()[leaves_pos]->add_child(trees_collection[trees_pos2]);

        std::string temp;
        tree_string(trees_collection[trees_pos],temp);

        outfile<<temp;
        outfile<<"\n";

    }

    outfile.close();
    
    
}




