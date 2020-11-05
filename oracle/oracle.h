#pragma once

#include "../dag/dag.h"

namespace dag{

class Oracle{

public:
    using Label=label::StringLabel;
    using DAG_Node=dag::Node<Label>; 

public:

    void generate_dag_oracle(DAG_Node* root);
    void single_leaf_backtrack(DAG_Node* node);
    //void parse_dag_oracle(std::string file_path);


private:
    int ** dag_oracle;


};
#include "oracle_impl.h"

}
