#include <iostream>
#include <string>
#include <regex>
#include <vector>



#include "../tree/tree.h"
#include "../path-tree/path-tree.h"





int main(int argc, const char * argv[]) {
    

    //std::string tree_string="{0{1{2}{3}}{4{5}}}";
    //std::string tree_string="{1{2{3}{4{5}{6}{7{8}{9}}}{10{11{12{13}}{14}}}}}";
    //std::string tree_string="{0{1{2{3{4{5}}}}}{6}{7}{8}}";
    //std::string tree_string="{1{2{3{4{5}{6}}{7}{8}{9}}{10{11{12{13}}{14}}}{15}{16}}";
    
    using Label=label::StringLabel;
    using Node=node::Node<Label>;
    using Supernode=supernode::Supernode;
    
    
    std::string tree_path="../dataset/singel_case1.tree";

    std::vector<Node> trees_collection;
    parser::BracketNotationParser bnp;
    bnp.parse_collection(trees_collection, tree_path);

    // for(auto node: trees_collection[0].get_all_nodes()){
    //     std::cout<<"node: "<<node.id()<<std::endl;
    // }
    
    
    //cout<<"";

   //trees_collection[0].print_all_label();
    

   
    
//    std::vector<Supernode*> supernodes_collection;
//    path_tree_generator::heavy_path_trees_collection_generator(trees_collection, supernodes_collection);
// //
//    std::string path_string;
//    path_tree_file::singel_generator(supernodes_collection[0], path_string);

//    std::cout<<"path: "<<path_string<<std::endl;
    
    std::string path_tree="{0-1-3-6-7{2}{4}{5}{8}{9-10-11-12{13}}}";
// ////
    parser::PathTreeParser ptp;
//    for(int i=0;i<(int)trees_collection[0].get_all_nodes().size();i++)
//        std::cout<<"nodes: "<<trees_collection[0].get_all_nodes()[i]->id()<<std::endl;
//
    
    
    // for(int i=0;i<(int)trees_collection[0].get_tree_size();i++){
    //     std::cout<<"node: "<<trees_collection[0].get_all_nodes()[i]->id()<<std::endl;
    // }
    // std::cout<<"node: "<<trees_collection[0].get_all_nodes()[0]->id()<<" depth: "<<trees_collection[0].get_all_nodes()[0]->depth()<<std::endl;
    
    Supernode sroot=ptp.parse_single(path_tree,trees_collection[0].get_all_nodes());
//

    
    
//    std::string ptree_path="/Users/brandonli/Desktop/Interactive Graph Search/dataset/singel_case1.ptree";
//    std::vector<Supernode *> supernodes_collection;
//    parser::PathTreeParser ptp;
//    ptp.parse_collection(supernodes_collection, ptree_path);
//
//    //trees_collection[0].print_all_label();
//
//    //supernodes_collection[0]->print_heay_tree();
//
//    Label target_label("target");
//    Node target_node(target_label);
//    target_node.set_id(13);
//    bool found=0;
//    int steps=0;
//    interleave::ordered(trees_collection[0],supernodes_collection[0],target_node,found,steps);
//
    

    
    //std::cout<<ptp.validate_input(pathTree_string)<<std::endl;
   
    
    
    
//    std::vector<int> heavy_id;
//    path_tree_generator::first_time_tag(root, heavy_id);
//    for(auto i: heavy_id)
//        std::cout<<i<<std::endl;
    
    
    //std::cout<<root.get_children()[0].get_children()[0].p->get_tree_size()<<std::endl;
    
    //root.print_all_label();
    
    //std::cout<<Reachability::Reachability(root.get_children()[0], 5)<<std::endl;
    
//
//    for(int i=0;i<17;i++){
//
//        std::cout<<"node: "<<i<<std::endl;
//        int step=1;
//        bool found=false;
//        Label lable("target");
//        Node target(lable);
//        target.set_id(i);
//        baseline::Topdown(root, target, found, step);
//        std::cout<<"step: "<<step<<std::endl;
//        std::cout<<"depth: "<<target.depth()<<std::endl;
//        std::cout<<"***************"<<std::endl;
//    }

//    std::vector<Supernode *> tree_paths;
//    path_tree_generator::single_path_tree_generator(root,tree_paths);
//
//
//    for(int i=0;i<(int)root.get_tree_size();i++){
//
//
//        root.reset_checked();
//        std::cout<<"node: "<<i<<std::endl;
//        int step=0;
//        Label lable("target");
//        Node target(lable);
//        target.set_id(i);
//        bool found=false;
//        adaptive::comprehensive(root, target, tree_paths[0], found, step, 3);
//        std::cout<<"steps: "<<step<<std::endl;
//        std::cout<<std::endl;
//    }
    
//        int step=0;
//        Label lable("target");
//        Node target(lable);
//        target.set_id(4);
//        bool found=false;
//        adaptive::sibling(root, target, tree_paths[0], found, step, 3);
//        std::cout<<"steps: "<<step<<std::endl;

    //std::cout<<"steps: "<<binary::binary_search_supernode(tree_paths[0], target, step)<<std::endl;
    //tree_paths[0]->print_heay_tree();

    
    return 0;
}


