#pragma once

#include <vector>
#include <string>
#include <set>

namespace dag {

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
  const SizeType children_count() const;
  ConstReference label() const;
  void add_child(Node<Label>* child);
  std::vector<Node<Label>*>& get_children();
  int get_tree_size() const;
  const std::vector<std::string> get_all_labels() const;
  void get_all_labels_recursion(std::vector<std::string>& labels) const;
  bool is_leaf() const;

  const int id();
  void set_id(int id);

  const SizeType parents_count() const;
  void add_parent(Node<Label>* parent);
  std::vector<Node<Label>*>& get_parents();
  bool is_root() const;


  void print();

  std::vector<Node<Label>*>& get_leaves();
  void add_leaf(Node<Label>* leaf);

  std::set<Node<Label>*>& get_descents();
  void add_descend(Node<Label>* descent);
  void assign_descent(std::set<Node<Label>*>& descent_set);

  void reachability();



// Member variables
private:
  /// All children of this node.
  std::vector<Node<Label>*> children_;
  std::vector<Node<Label>*> parents_;
  std::vector<Node<Label>*> leaves_;
  std::set<Node<Label>*> descent_;

  /// Data representing the label of this node. Only this Node object owns it.
  Label label_;

  int id_;
};

// Implementation details
#include "node_impl.h"

}
