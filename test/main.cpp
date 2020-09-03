#include <iostream>
#include <string>
#include <regex>
#include <vector>


#include "../ranodm/random.h"

int main(int argc, const char * argv[]) {



    



    std::vector<int>result;
    // random_generator::uniform(0,10,20,result);
    random_generator::zipf(10,3,10,result);
    for(auto i:result){
      std::cout<<i<<std::endl;
    }
    

  
    return 0;
}



