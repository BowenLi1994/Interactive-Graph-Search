
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <random>

#include "../tree/tree.h"

using Label=label::StringLabel;
using Node=node::Node<Label>;

void tree_string(Node &root,std::string& tree_string);


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

