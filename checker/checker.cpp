#include <iostream>
#include <string>
#include <vector>

#include "../tree/tree.h"
#include "../path-tree/path-tree.h"
#include "../experiment/experiment.h"

int main(int argc, const char * argv[]){

  using Label=label::StringLabel;
  using Node=node::Node<Label>;
  using Supernode=supernode::Supernode;


  std::string tree_path="/home/bowen/igs_dataset/amazon/manual/combine_1000.tree";
  std::vector<Node> trees_collection;
  parser::BracketNotationParser bnp;
  bnp.parse_collection(trees_collection,tree_path);


  std::string ptree_path="/home/bowen/igs_dataset/path-tree/combine1000.ptree";
  std::vector<Supernode *> ptree_collection;
  parser::PathTreeParser ptp;
  ptp.parse_collection(ptree_collection,trees_collection,ptree_path);

  //trees_collection[7].print_all_label();

  // trees_collection[7].print_all_nodes();

  //int tree_size=(int)trees_collection[7].get_tree_size();

  //  Label target_label("target");
  //   Node target_node(target_label);
  //   target_node.set_id(14);
  //   bool found=0;
  //   int steps=0;
  //   trees_collection[7].reset_checked();
  //   interleave::ordered(trees_collection[7],ptree_collection[7],target_node,found,steps);
  //   std::cout<<"depth: "<<target_node.depth()<<std::endl;



  int tree_counter=0;
  for(auto& tree: trees_collection){

    std::cout<<"calculate tree: "<<tree_counter<<std::endl;

    int tree_size=(int)tree.get_tree_size();

    // std::vector<Node *> nodes_set;
    // tree.traverse_tree(nodes_set);

    for(int i=0;i<tree_size;i++){

      Label target_label("target");
      Node target_node(target_label);
      target_node.set_id(i);
      bool found=0;
      int steps=1;
      tree.reset_checked();
      baseline::Topdown(tree,target_node,found,steps);

      if(steps<=0)
        std::cout<<"tree: "<<tree_counter<<" node: "<<i<<" depth: "<<target_node.depth()<<" steps: "<<steps<<std::endl;

    }

    tree_counter++;


  }



 

  




  return 0;

}