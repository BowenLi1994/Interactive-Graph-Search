/// \file parser/bracket_notation_parser_impl.h
///
/// \details
/// Contains the implementation of the BracketNotationParser class.

#pragma once
using namespace parser;
/// This is currently a copy of the previous version but with the efficient
/// tokanization.
PathTreeParser::Supernode PathTreeParser::parse_single(
    const std::string& tree_string,std::vector<Node>& nodes_set) {


    // for(auto node: nodes_set){
    //     std::cout<<"node: "<<node.id()<<std::endl;
    // }


  int id_counter=0;
  std::vector<std::string> tokens = get_tokens(tree_string);

  // Tokenize the input string - get iterator over tokens.
  auto tokens_begin = tokens.begin();
  auto tokens_end = tokens.end();

  // Deal with the root node separately.
  ++tokens_begin; // Advance tokens to label.
  std::string match_str = *tokens_begin;
  if (match_str == kLeftBracket || match_str == kRightBracket) { // Root has an empty label.
    match_str = "";
    // Do not advance tokens - we're already at kLeftBracket or kRightBracket.
  } else { // Non-empty label.
    ++tokens_begin; // Advance tokens.
  }
//     //std::cout<<match_str<<std::endl;
    Supernode sroot;
    sroot.set_id(id_counter);
    std::vector<int> ids_set=get_ids(match_str);
    
    for(auto id: ids_set)
        sroot.add_node(&nodes_set[id]);

    //sroot.print_all_nodes();
  
    node_stack.push_back(&sroot);
    id_counter++;

  //Iterate all remaining tokens.
  while (tokens_begin != tokens_end) {

    match_str = *tokens_begin;

   if(match_str!=kLeftBracket && match_str!=kRightBracket)
       break;


    if (match_str == kLeftBracket) { // Enter node.
      ++tokens_begin; // Advance tokens to label.
      match_str = *tokens_begin;

      if (match_str == kLeftBracket || match_str == kRightBracket) { // Node has an empty label.
        match_str = "";
        // Do not advance tokens - we're already at kLeftBracket or kRightBracket.
      } else { // Non-empty label.
        ++tokens_begin; // Advance tokens.
      }

      // Create new node.
      Supernode*  snode=new Supernode;
      snode->set_id(id_counter);
      id_counter++;
      std::vector<int> ids_set=get_ids(match_str);

        for(auto id: ids_set){

            snode->add_node(&nodes_set[id]);
        }

        node_stack.back()->add_child(snode);
        node_stack.push_back(snode);

    }

    if (match_str == kRightBracket) { // Exit node.
      node_stack.pop_back();
      ++tokens_begin; // Advance tokens.
    }
  }


   
    
    return sroot;
}

void PathTreeParser::parse_collection(std::vector<Supernode*>& path_trees_collection,std::vector<Node>& trees_collection,
      const std::string& file_path) {
    
  std::ifstream trees_file(file_path);
  if (!trees_file) {
    throw std::runtime_error("ERROR: Problem with opening the file '" + file_path + "' in BracketNotationParser::parse_collection_efficient.");
  }
  // Read the trees line by line, parse, and move into the container.
  int tree_counter=0;
  std::string tree_string;
  while (std::getline(trees_file, tree_string)) {
    std::cout<<"parse path-tree "<<tree_counter<<":"<<std::endl;
    Supernode* node=new Supernode;
    *node=parse_single(tree_string,trees_collection[tree_counter].get_all_nodes());
//    Supernode node=parse_single(tree_string);
//    node.print_heay_tree();
////    Supernode* sroot=new Supernode;
////    sroot=&node;
//
    path_trees_collection.push_back(node); // -> This invokes a move constructor (due to push_back(<rvalue>)).
    tree_counter++;
  }
   trees_file.close();
}


// This is only a tokanizer that returns a vector with correct tokens.
std::vector<std::string> PathTreeParser::get_tokens(
    const std::string& tree_string) {
  std::vector<std::string> tokens;

  // Get pointer to the structure elements.
  const char* s_elems = kStructureElements.c_str();

  // Get pointer to the beginning of the input string.
  const char* begin = tree_string.c_str();
  // Pointer to the beginning of consecutive searches.
  const char* next_begin = begin;
  // Remember iter from previous iteration in old_iter - for label begin.
  const char* old_iter = begin;
  // iter is a pointer to consecutive occurences of either '{' or '}'.
  for(const char* iter = strpbrk(next_begin, s_elems); iter != NULL; iter = strpbrk(next_begin, s_elems)) {
    // Next iteration will start from the position right of iter.
    next_begin = iter + 1;
    // Check if the character just before the found position is an escape_char.
    // Then, disregard the current position.
    if (iter > begin && *(iter-1) == kEscapeChar) {
      continue;
    }
    // If there is something between two consecutive brackets, it's potentially
    // a label - record it.
    if (iter > old_iter + 1) {
      tokens.push_back(typename std::vector<std::string>::value_type(old_iter+1, iter)); // Calls the allocator of string.
    }
    // Record the found bracket.
    tokens.push_back(typename std::vector<std::string>::value_type(iter, iter+1)); // Calls the allocator of string.
    old_iter = iter;
  }

  return tokens;
}

bool PathTreeParser::validate_input(const std::string& tree_string) const {
  int bracket_diff_counter = 0; // Counts difference between the numbers of left and right brackets.
  int bracket_pair_counter = 0; // Counts number of bracket pairs - number of nodes assuming correct nesting.
  // Loop over all characters.
  for(auto it = tree_string.begin(); it != tree_string.end(); ++it) {
    if (*it == kEscapeChar) { // Skip next character if kEscapeChar is found.
      ++it;
    } else if (*it == kLeftBracket[0]) { // Increase bracket_counter when kLeftBracket found.
      bracket_diff_counter++;
      bracket_pair_counter++;
    } else if (*it == kRightBracket[0]) { // Decrease bracket_counter when kRightBracket found.
      bracket_diff_counter--;
    }
  }
  if (bracket_diff_counter != 0 || bracket_pair_counter == 0) {
    return false;
  }
  return true;
}


 std::vector<int> PathTreeParser::get_ids(const std::string &node_string){
     
     std::vector<int> ids_set;
     std::vector<std::string> nodes_set;
     
     functions::SplitString(node_string, nodes_set, "-");
     
     for(auto nodes: nodes_set){
         
         ids_set.push_back(std::stoi(nodes));
     }
     
     
    
     
     
     return ids_set;
 }
