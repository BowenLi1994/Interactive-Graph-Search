

#pragma once
using namespace parser;

/// This is currently a copy of the previous version but with the efficient
/// tokanization.
node::Node<BracketNotationParser::Label> BracketNotationParser::parse_single(
    const std::string& tree_string) {

    
  int id_counter=0;
  int depth_counter=0;
    
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
  Label root_label(match_str);
  node::Node<Label> root(root_label);
  node_stack.push_back(std::ref(root));
    root.set_id(id_counter);
    root.set_depth(depth_counter);
    id_counter++;
    depth_counter++;

    root.get_all_nodes().push_back(std::ref(root));

  //std::string last_string="null";
  // Iterate all remaining tokens.
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
      Label node_label(match_str);
      node::Node<Label> n(node_label);
        n.set_id(id_counter);
        n.set_depth(depth_counter);
        id_counter++;
        depth_counter++;
        //n.set_sibling((int)node_stack.back().get().children_count());

      // Move n to become a child.
      // Return reference from add_child to the 'new-located' object.
      // Put a reference to just-moved n (last child of its parent) on a stack.

      root.get_all_nodes().push_back(std::ref(n));
    

      node_stack.push_back(std::ref(node_stack.back().get().add_child(n)));
    }

    if (match_str == kRightBracket) { // Exit node.
      node_stack.pop_back();
      ++tokens_begin; // Advance tokens.
      depth_counter--;
    }
  }
    
  root.pre_prosseing();
  return root;
}

void BracketNotationParser::parse_collection(
    std::vector<node::Node<BracketNotationParser::Label>>& trees_collection,
    const std::string& file_path) {
  std::ifstream trees_file(file_path);
  if (!trees_file) {
    throw std::runtime_error("ERROR: Problem with opening the file '" + file_path + "' in BracketNotationParser::parse_collection_efficient.");
  }
  // Read the trees line by line, parse, and move into the container.
  int tree_counter=0;
  std::string tree_string;
  while (std::getline(trees_file, tree_string)) {
   
    std::cout<<"parse tree:"<<tree_counter<<std::endl;
    trees_collection.push_back(parse_single(tree_string)); // -> This invokes a move constructor (due to push_back(<rvalue>)).
    tree_counter++;
  }
  trees_file.close();
}

/// This is only a tokanizer that returns a vector with correct tokens.
std::vector<std::string> BracketNotationParser::get_tokens(
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

bool BracketNotationParser::validate_input(const std::string& tree_string) const {
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
