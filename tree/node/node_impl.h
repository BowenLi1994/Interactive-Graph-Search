/// \file node/node_impl.h
///
/// \details
/// Contains the implementation of the Node class.

#pragma once

template<class Label>
Node<Label>::Node(ConstReference label) : label_(label),depth_(0),sibling_number_(1),nex_right_sibling_(-1),checked_(false) {}

template<class Label>
const typename Node<Label>::SizeType Node<Label>::children_count() const {
  return children_.size();
}

template<class Label>
typename Node<Label>::ConstReference Node<Label>::label() const {
  return label_;
}

template<class Label>
Node<Label>& Node<Label>::add_child(Node<Label> child) {
  children_.push_back(child);
  return children_.back();
}

template<class Label>
std::vector<Node<Label>>& Node<Label>::get_children(){
  return children_;
}

template<class Label>
int Node<Label>::get_tree_size() const {
  int size = 1;
  for (const auto& child : children_) {
    size += child.get_tree_size();
  }
  return size;
}

template<class Label>
const std::vector<std::string> Node<Label>::get_all_labels() const {
  std::vector<std::string> labels;
  get_all_labels_recursion(labels);
  return labels;
}
template<class Label>
void Node<Label>::get_all_labels_recursion(std::vector<std::string>& labels) const {
  labels.push_back(label_.to_string());
  for (const auto& child : children_) {
    child.get_all_labels_recursion(labels);
  }
}

template<class Label>
bool Node<Label>::is_leaf() const {
  return children_.size() == 0;
}

template<class Label>
void Node<Label>::set_id(int id){
    id_=id;
}

template<class Label>
int Node<Label>::id() const{
    
    return id_;
}

template<class Label>
void Node<Label>::set_depth(int depth){
    
    depth_=depth;
}

template<class Label>
int Node<Label>::depth() const{
    
    return depth_;
}

template<class Label>
void Node<Label>::set_sibling(const int sibling){
    sibling_number_=sibling;
}

template<class Label>
int Node<Label>::sibling() const{
    
    return sibling_number_;
}

template<class Label>
void Node<Label>::set_right_sibling(int right_sibling){
    
    nex_right_sibling_=right_sibling;
}

template<class Label>
int Node<Label>::right_sibling() const{
    
    return nex_right_sibling_;
}

template<class Label>
void Node<Label>::print_all_label(){
    
    std::cout<<"label id: "<<this->id()<<" depth: "<<this->depth()<<" sibling number: "<<this->sibling()<<" next sibling: "<<this->right_sibling()<<std::endl;
    
    //this->print_parent();
    int child_counter=0;
    
    if(this->children_count()!=0){
        
    for(auto child: children_){
        std::cout<<"child "<<child_counter<<": id: "<<child.id()<<std::endl;
        child_counter++;
        }
        
    }
    else{
        std::cout<<"Leaf Node."<<std::endl;
    }
    
    for(auto child: children_){
        child.print_all_label();
        
    }
    
    
    
}


template<class Label>
void Node<Label>::pre_prosseing(){
    
    if(this->children_count()==0)
        return;
    
    else{
        //std::cout<<"current node: "<<this->id()<<std::endl;
        int child_counter=0;
        for(auto & child: this->get_children()){
            
            child.set_sibling((int)this->children_count());
            if(child_counter!=(int)this->children_count()-1){
                child.set_right_sibling(this->get_children()[child_counter+1].id());
            }
            
            
            child_counter++;
        }
        
         for(auto & child: this->get_children()){
             child.pre_prosseing();
         }
        
        
        
    }
    
}


template<class Label>
const bool Node<Label>::is_checked(){
    return checked_;
}

template<class Label>
void Node<Label>::set_check(bool flag){
    checked_=flag;
}

template<class Label>
void Node<Label>::reset_checked(){
    this->set_check(false);
    for(auto& child : this->get_children()){
        child.reset_checked();
    }
}
