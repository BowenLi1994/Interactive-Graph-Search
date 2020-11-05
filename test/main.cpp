#include <iostream>
#include <string>
#include <vector>

// #include "../tree/tree.h"
// #include "../dag/parser/parser.h"
//#include "../dag/dag.h"
#include "../oracle/oracle.h"

using Label=label::StringLabel;
using DAG_Node=dag::Node<Label>;

int main(int argc, const char * argv[]){



  std::string file_path="../dataset/single_case1.dag";

  parser::DAGParser dp;
  DAG_Node* root=dp.parse_collection(file_path);

  // for(auto leaf:root->get_leaves())
  //   std::cout<<leaf->id()<<std::endl;

  dag::Oracle o;
  o.generate_dag_oracle(root);

  root->reachability();







  return 0;

}







