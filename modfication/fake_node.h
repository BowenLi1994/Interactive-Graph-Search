
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <random>

#include "../tree/tree.h"
#include "../modfication/tree_string.h"
#include "../others/others.h"

using Label=label::StringLabel;
using Node=node::Node<Label>;


void fake_node(std::string filename);



void fake_node(std::string filename){
    

    std::string filepath=functions::getFilePath(filename);
    if(filepath=="NULL")
        return;
    
    parser::BracketNotationParser bnp;
    std::vector<Node> trees_collection;
    bnp.parse_collection(trees_collection, filepath);
    
    std::string outfile_name="froot_"+filename;

    std::string outfile_path="/home/bowen/igs_dataset/amazon/manual/";
    std::ofstream outfile(outfile_path+outfile_name+".tree");

    if(!outfile.is_open()){
        std::cout<<"cannot open file: "<<outfile_name<<std::endl;
        return;
    }


    for(auto tree:trees_collection){

        Label target_label("root");
        Node root(target_label);
        root.add_child(tree);

        std::string temp;
        tree_string(root,temp);

        outfile<<temp;
        outfile<<"\n";

    }
    
    outfile.close();
    
    
}




