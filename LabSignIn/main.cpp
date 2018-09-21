
#include <cstdlib>
#include <iostream>
#include "twoDArray.h"

using namespace std;

//Lab SignIn Project

int main() {
    
    int** p;
    int sizes[] = {4, 3, 6, 3, 0, 3, 5, -1};
    
    p = Chart<int>::allocate_twod(sizes);

    int n = Chart<int>::array_size(sizes);
    
    Chart<int>::init_twod_lab(p, sizes, 0);
    Chart<int>::print(p, sizes);
    
//    Chart<int>::lab_menu();
    
    Chart<int>::print(p, sizes); 

    return 0;
}

