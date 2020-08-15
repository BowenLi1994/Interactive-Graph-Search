
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <random>

#include "../tree/node/node.h"
#include "../tree/label/string_label.h"
#include "../tree/parser/bracket_notation_parser.h"

using Label=label::StringLabel;
using Node=node::Node<Label>;

void tree_string(Node &root,std::string& tree_string);
int combine(std::string filename, int trees_number);


int  combine(std::string filename, int trees_number) {

    std::string filepath=functions::getFilePath(filename);
    if(filepath=="NULL")
        return 0;
    
    parser::BracketNotationParser bnp;

    std::vector<Node> trees_collection;
    
////   // std::cout<<trees_filepath<<std::endl;
    bnp.parse_collection(trees_collection, filepath);
////   // std::cout<<"tree size: "<<trees_collection.size()<<std::endl;
////
    std::string sTreenum =std::to_string(trees_number);
    std::string outfile_name="combine_"+sTreenum;
    std::string outfile_path="/home/bowen/igs_dataset/amazon/manual/";
    std::ofstream outfile(outfile_path+outfile_name+".tree");
////
    if(!outfile.is_open()){
       std::cout<<"cannot open file: "<<outfile_name<<std::endl;
       return 0;
    }
//
//    //std::cout<<"outfile_name:"<<outfile_name<<std::endl;
//
   for(int i=0;i<trees_number;i++){

        int tree_size=rand()%999+1;
        Label target_label("root");
        Node root(target_label);
        for(int j=0;j<tree_size;j++){
            int trees_pos=rand()%10000;
            root.add_child(trees_collection[trees_pos]);
        }
        std::string temp;
        tree_string(root,temp);

        outfile<<temp;
        outfile<<"\n";

    }

    outfile.close();
    
    return 0;
}

void tree_string(Node &root,std::string& temp){
    
    //std::cout<<"{";
    temp+="{";
    //std::cout<<root.label().to_string();
    temp+=root.label().to_string();
    for(auto& child: root.get_children()){
        tree_string(child,temp);
    }
    //std::cout<<"}";
     temp+="}";
}

