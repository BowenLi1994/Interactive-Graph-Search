#pragma once
using namespace dag;

void Oracle::generate_dag_oracle(DAG_Node* root){

    for(auto leaf : root->get_leaves()){
        //std::cout<<"leaf: "<<leaf->id()<<std::endl;
        single_leaf_backtrack(leaf);
    }

}

void Oracle::single_leaf_backtrack(DAG_Node* node){
    
    if(node->is_root())
       return;
    else{
        for(auto parent:node->get_parents()){
            //std::cout<<"node: "<<node->id()<<"'s parent: "<<parent->id()<<std::endl;
            parent->assign_descent(node->get_descents());
            parent->add_descend(node);
            single_leaf_backtrack(parent);
        }
    }
}
