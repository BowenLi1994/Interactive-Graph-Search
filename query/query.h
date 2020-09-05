# pragma once
#include <vector>
#include <iostream>


namespace query{

    class Query{
        public:

            Query();
            void add_node(int id);
            std::vector<int>& get_nodes();
            void print();


        private:
            std::vector<int> nodes_;

    };

    #include "query_imp.h"

}