



#pragma once


Supernode::Supernode(){
    id_=-1;
}

int Supernode::id(){
    return id_;
}

std::vector<Node *> Supernode::getNodes(){
    
    return nodes_;
}

std::vector<Supernode *> Supernode::getChildren(){
    
    return children_;
}


const Supernode::SizeType Supernode::children_count() const{
    
    return children_.size();
}


void Supernode::add_child(Supernode* child){
    children_.push_back(child);
        
}

const Supernode::SizeType Supernode::nodes_count() const{
    
    return nodes_.size();
}

void Supernode::add_node(Node* node){
    nodes_.push_back(node);
        
}

int Supernode::get_heavy_tree_size() const{
    
    int size = 1;
    for (const auto& child: children_) {
        size += child->get_heavy_tree_size();
    }
    return size;
    
}

void Supernode::print_all_nodes(){
    for(auto node: nodes_)
        std::cout<<"node: "<<node->id()<<std::endl;
}


void Supernode::print_heay_tree(){
    
    std::cout<<"Super node: "<<this->id()<<std::endl;
    std::cout<<"It includes nodes:"<<std::endl;
    this->print_all_nodes();
    
    if(this->children_count()!=0){
        std::cout<<"It includes children:"<<std::endl;
        for(auto child:this->getChildren())
            std::cout<<"Super Node:"<<child->id()<<std::endl;
    }
    else{
        std::cout<<"Leaf node"<<std::endl;
    }
    
    for(auto child:this->getChildren())
        child->print_heay_tree();
}


void Supernode::set_id(int id){
    id_=id;
}
