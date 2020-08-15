

#pragma once

#include "../tree/node/node.h"
#include "../tree/label/string_label.h"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>



namespace analyzer {

using Label=label::StringLabel;
using Node=node::Node<Label>;

struct analyze_result{
    int tree_number;
    int max_size;
    double avg_size;
    int max_depth;
    double avg_depth;
    int max_fanout;
    double avg_fanout;
};

struct analyze_result analyze(std::vector<Node>& trees_collection);
void print_anylyze_result(analyze_result result);
void tree_fanout_depth(Node& node, std::vector<int>& fanout, std::vector<int>& depth);

struct analyze_result analyze(std::vector<Node>& trees_collection){
    
    struct analyze_result result;
    result.tree_number=(int)trees_collection.size();
    
    
    int max_size=0;
    int sum_size=0;
    int max_depth=0;
    int sum_depth=0;
    
    int max_fanout=0;
    int sum_fanout=0;
    
    for(auto& tree:trees_collection){
        if(tree.get_tree_size()>max_size)
            max_size=tree.get_tree_size();
        sum_size+=tree.get_tree_size();
        
        std::vector<int> depth;
        std::vector<int> fanout;
        tree_fanout_depth(tree, fanout, depth);
        int single_tree_max_depth, single_tree_max_fanout;
        single_tree_max_depth=*std::max_element(depth.begin(), depth.end());
        
        single_tree_max_fanout=*std::max_element(fanout.begin(), fanout.end());
        
        if(single_tree_max_fanout>max_fanout)
            max_fanout=single_tree_max_fanout;
        sum_fanout+=single_tree_max_fanout;
        
        if(single_tree_max_depth>max_depth)
            max_depth=single_tree_max_depth;
        sum_depth+=single_tree_max_depth;
        
        
    }
    
    result.max_size=max_size;
    result.avg_size=(double)sum_size/(double)trees_collection.size();
    
    result.max_depth=max_depth;
    result.avg_depth=(double)sum_depth/(double)trees_collection.size();
    
    result.max_fanout=max_fanout;
    result.avg_fanout=(double)sum_fanout/(double)trees_collection.size();
    
    
    
    
    
    return result;
    
}



void print_anylyze_result(analyze_result result){
    
    std::cout<<"Number of trees: "<<result.tree_number<<std::endl;
    std::cout<<"Largest tree size: "<<result.max_size<<std::endl;
    std::cout<<"Average tree size: "<<result.avg_size<<std::endl;
    std::cout<<"Depthest tree: "<<result.max_depth<<std::endl;
    std::cout<<"Average tree depth: "<<result.avg_depth<<std::endl;
    std::cout<<"Widest tree: "<<result.max_fanout<<std::endl;
    std::cout<<"Average tree fanout: "<<result.avg_fanout<<std::endl;
    
}

void tree_fanout_depth(Node& node, std::vector<int>& fanout, std::vector<int>& depth){
    
    fanout.push_back(node.sibling());
    depth.push_back(node.depth());
    
    for(auto& child : node.get_children()){
        tree_fanout_depth(child, fanout, depth);
    }
    
}


}

