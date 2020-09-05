/// \file node/node.h
///
/// \details
/// Contains the declaration of the Node class (represents a node in a tree).

#pragma once

#include <vector>
#include <string>

namespace node {

/// \tparam Label Satellite data associated with the node.
template <class Label>
class Node {
// Types and type aliases
public:
  using Reference = Label&;
  using ConstReference = const Label&;

  using SizeType = typename std::vector<Node<Label>>::size_type;

// Member functions
public:

  Node(ConstReference label);

  /// Returns the number of children of this node.
  ///
  /// \return Number of children (i.e., entries in children_).
  const SizeType children_count() const;

  /// Retrieves the label.
  ///
  /// \return The label of this node.
  ConstReference label() const;

  
  /// param Node to be added.
  Node<Label>& add_child(Node<Label> child);

  /// Returns the reference to children_ vector.
  ///
  /// \return Reference to children_ vector.
  std::vector<Node<Label>>& get_children();

  /// Calculates the size (number of nodes) in tree rooted at this. It traverses
  /// the entire subtree recursively.
  ///
  /// \return Size of subtree rooted at this.
  int get_tree_size() const;

  /// Traverses the tree and collects string representations of all labels.
  ///
  /// return Vector with labels of all nodes.
  const std::vector<std::string> get_all_labels() const;
  void get_all_labels_recursion(std::vector<std::string>& labels) const;

  /// Verifies if this node is a leaf.
  ///
  /// \return True if this node is leaf, false otherwise.
  bool is_leaf() const;
 
    
  //id setter and getter
  void set_id(int id);
  int id() const;
    
  //depth setter and getter
  void set_depth(int depth);
  int depth() const;
    
  /// getter and setter for sibling number and next right sibling node id
  void set_sibling(int sibling);
  int sibling() const;
    
  void set_right_sibling(const int right_sibling);
  int right_sibling() const;


    void print_all_label();
    void pre_prosseing(std::vector<Node*>& nodes_set);
    
    const bool is_checked();
    void set_check(bool flag);
    
    void reset_checked();
    
    void add_leaf(Node<Label>* child);
    std::vector<Node<Label>*>& get_leaf();
    

    void add_node(Node<Label>* node);
    std::vector<Node<Label>*>& get_all_nodes();

    void traverse_tree(std::vector<Node<Label>*>& nodes_set);
    
    void add_frequency();
    int frequency();
    
    
    
    
// Member variables
private:
    
  
  /// All children of this node.
  std::vector<Node<Label>> children_;
  std::vector<Node<Label>* > leaf_;
  std::vector<Node<Label>*> all_nodes_;

  /// Data representing the label of this node. Only this Node object owns it.
  Label label_;
    
  int sibling_number_;
  int nex_right_sibling_;
  int id_;
  int depth_;
  bool checked_;
  int frequency_;
};

// Implementation details
#include "node_impl.h"

}
