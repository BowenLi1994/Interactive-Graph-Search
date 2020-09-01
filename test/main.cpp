#include <iostream>
#include <string>
#include <regex>
#include <vector>



#include "../tree/tree.h"
#include "../path-tree/path-tree.h"





int main(int argc, const char * argv[]) {
    


    
    using Label=label::StringLabel;
    using Node=node::Node<Label>;
    using Supernode=supernode::Supernode;
    
    
    std::string tree_path="../dataset/singel_case1.tree";

    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;

    bnp.parse_collection(trees_collection,tree_path);
    
    for(auto node: trees_collection[0].get_all_nodes()){
        std::cout<<"node: "<<node->id()<<" depth: "<<node->depth()<<" sibling: "<<node->sibling()<<" next right sibling: "<<node->right_sibling()<<std::endl;
    }

    // trees_collection[0].print_all_label();

    // std::string ptree_path="/home/bowen/igs_dataset/path-tree/singel_case1.ptree";
    // std::vector<Supernode *> ptrees_collection;



    // parser::PathTreeParser ptp;
    // ptp.parse_collection(ptrees_collection,trees_collection,ptree_path);
    
    // ptrees_collection[0]->print_heay_tree();

  
    return 0;
}


