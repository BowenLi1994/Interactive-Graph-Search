#include <iostream>
#include <string>
#include <vector>

#include "../tree/tree.h"
#include "../path-tree/path-tree.h"
#include "../log/log.h"
// #include "../interleave/interleave_frequency.h"
#include "../adaptive/compared.h"
#include "../query/parser/query_parser.h"
#include "../experiment/experiment.h"
#include "../adaptive/check.h"

int main(int argc, const char * argv[]){

    using Label=label::StringLabel;
    using Node=node::Node<Label>;
    using Supernode=supernode::Supernode;
    using Query=query::Query;
    using Log=query::Query;

  std::string tree_path="/home/bowen/igs_dataset/amazon/manual/concatnate_1.tree";
  std::vector<Node> trees_collection;
  parser::BracketNotationParser bnp;
  bnp.parse_collection(trees_collection,tree_path);

  trees_collection[0].print_all_label();

  for(auto& tree: trees_collection){

    std::vector<Node *> nodes_set;
    tree.traverse_tree(nodes_set);
    int node_counter=0;
    for(auto node: nodes_set){
     struct adaptive::tree_parameter result;
     result=adaptive::tree_analyse(*node);
     double alpha1=(double)((double)pow(result.tree_size,0)*result.tree_fanout)/double(result.tree_path+1);
     double alpha2=(double)((double)pow(result.tree_size,0.5)*result.tree_fanout)/double(result.tree_path+1);
     double alpha3=(double)((double)pow(result.tree_size,1)*result.tree_fanout)/double(result.tree_path+1);
     std::cout<<"node: "<<node_counter<<" alpha1: "<<alpha1<<" alpha2: "<<alpha2<<" alpha3: "<<alpha3<<std::endl;
     node_counter++;
    }

   
    
  }

  
  // std::string ptrees_path="/home/bowen/igs_dataset/path-tree/bolzano.ptree";
  // std::vector<Supernode *> ptree_collection;
  // parser::PathTreeParser ptp;
  // ptp.parse_collection(ptree_collection,trees_collection,ptrees_path);

    // std::cout<<"calculate tree: "<<1000<<std::endl;
    // for(auto query_id: query_collection[1000].get_nodes()){

      // Label target_label("target");
      // Node target_node(target_label);
      // target_node.set_id(1);
      // bool found=0;
      // int steps=0;
      // adaptive::comprehensive(trees_collection[0],target_node,ptree_collection[0],found,steps,1,0);
     

    // }




 


  //trees_collection[150].print_all_label();

  // int trees_number=(int)trees_collection.size();

  // for(int i=0;i<trees_number;i++){

  //   std::cout<<"calculate tree: "<<i<<std::endl;
  //   for(auto query_id: query_collection[i].get_nodes()){

  //     Label target_label("target");
  //     Node target_node(target_label);
  //     target_node.set_id(query_id);
  //     bool found=0;
  //     int steps=0;
  //     trees_collection[i].reset_checked();
  //     baseline::Topdown(trees_collection[i], target_node, found, steps);

  //     std::cout<<"steps: "<<steps<<std::endl;

  //   }

  // }





  return 0;

}







