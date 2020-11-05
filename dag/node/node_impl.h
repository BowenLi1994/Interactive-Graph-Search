#pragma once
using namespace  dag;


template<class Label>
Node<Label>::Node(ConstReference label) : label_(label) {}

template<class Label>
const typename Node<Label>::SizeType Node<Label>::children_count() const {
  return children_.size();
}

template<class Label>
typename Node<Label>::ConstReference Node<Label>::label() const {
  return label_;
}

template<class Label>
void Node<Label>::add_child(Node<Label>* child) {
  children_.push_back(child);
}

template<class Label>
std::vector<Node<Label>*>& Node<Label>::get_children(){
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
const int Node<Label>::id(){

  return id_;
}

template<class Label>
void Node<Label>::set_id(int id){
  id_=id;
}

template<class Label>
const typename Node<Label>::SizeType Node<Label>::parents_count() const{

  return parents_.size();
}

template<class Label>
void Node<Label>::add_parent(Node* parent){
  parents_.push_back(parent);
}

template<class Label>
std::vector<Node<Label>*>& Node<Label>::get_parents(){

  return parents_;
}

template<class Label>
bool Node<Label>::is_root() const{

    if(parents_.size()==0 && children_.size()!=0)
      return true;
    else
      return false;

}

template<class Label>
void Node<Label>::print(){

  std::cout<<"node: "<<this->id()<<std::endl;
  int child_counter=0;
    
  if(this->children_count()!=0){
        
    for(auto child: children_){
        std::cout<<"child "<<child_counter<<": id: "<<child->id()<<std::endl;
        child_counter++;
    }
        
  }
  else{
      std::cout<<"Leaf Node."<<std::endl;
  }
    
  for(auto child: children_){
    child->print();
  }
}

template<class Label>
std::vector<Node<Label>*>& Node<Label>::get_leaves(){
  return leaves_;
}

template<class Label>
void  Node<Label>::add_leaf(Node<Label>* leaf){
  leaves_.push_back(leaf);
}

template<class Label>
std::set<Node<Label>*>&  Node<Label>::get_descents(){

  return descent_;
}

template<class Label>
void  Node<Label>:: add_descend(Node<Label>* descent){
  
  descent_.insert(descent);

}

template<class Label>
void Node<Label>::assign_descent(std::set<Node<Label>*>& descent_set){

  descent_.insert(descent_set.begin(),descent_set.end());

}

template<class Label>
void Node<Label>::reachability(){

  std::cout<<"node: "<<this->id()<<std::endl;
  int descent_counter=0;
    
  if(this->get_descents().size()!=0){
        
    for(auto descent:descent_){
        std::cout<<"descent "<<descent_counter<<": id: "<<descent->id()<<std::endl;
        descent_counter++;
    }
        
  }
  else{
      std::cout<<"Leaf Node."<<std::endl;
  }
    
  for(auto child: children_){
    child->reachability();
  }
}