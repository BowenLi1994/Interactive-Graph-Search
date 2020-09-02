#include <iostream>
#include <string>
#include <regex>
#include <vector>



#include "../tree/tree.h"
#include "../path-tree/path-tree.h"
#include "../binary-search/binary_supernode.h"
#include "../experiment/experiment.h"





int main(int argc, const char * argv[]) {
    


    
    using Label=label::StringLabel;
    using Node=node::Node<Label>;
    using Supernode=supernode::Supernode;
    
    
    std::string tree_path="../dataset/bolzano.tree";

    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;

    bnp.parse_collection(trees_collection,tree_path);

    

    //trees_collection[0].print_all_label();

    std::string ptree_path="/home/bowen/igs_dataset/path-tree/bolzano.ptree";
    std::vector<Supernode *> ptrees_collection;

    // std::vector<Node *> nodes_set;
    // nodes_set.reserve(trees_collection[0].get_tree_size());
    // trees_collection[0].traverse_tree(nodes_set);

    // for(auto node: nodes_set){
    //     std::cout<<"node: "<<node->id()<<" depth: "<<node->depth()<<" sibling: "<<node->sibling()<<" next right sibling: "<<node->right_sibling()<<std::endl;
    // }



    parser::PathTreeParser ptp;
    // std::string ptree="{0-1-3-6-7{2}{4}{5}{8}{9-10-11-12{13}}}";
    // ptp.parse_single(ptree,trees_collection[0]);
    ptp.parse_collection(ptrees_collection,trees_collection,ptree_path);

    trees_collection[59].print_all_label();
    ptrees_collection[59]->print_heay_tree();

   //ptrees_collection[59]->getNodes()[0]->print_all_label();


for(int i=0;i<trees_collection[59].get_tree_size();i++){
    
        std::cout<<"node: "<<i<<std::endl;
        Label target_label("target");
        Node target_node(target_label);
        target_node.set_id(i);
        bool found=0;
        int steps=0;
        interleave::ordered(trees_collection[59],ptrees_collection[59],target_node,found,steps);
} 

  //  ptrees_collection[0]->getNodes()[0]->print_all_label();

    
    // ptrees_collection[0]->print_heay_tree();


    // for(auto node: trees_collection[0].get_all_nodes()){
    //     std::cout<<"node: "<<node.id()<<" depth: "<<node.depth()<<" sibling: "<<node.sibling()<<" next right sibling: "<<node.right_sibling()<<std::endl;
    // }

    //   std::string ptree="{0-1-3-6-7{2}{4}{5}{8}{9-10-11-12{13}}}";
    //   Supernode sroot=ptp.parse_single(ptree,trees_collection[0]);

    //   sroot.print_heay_tree();


  
    return 0;
}


