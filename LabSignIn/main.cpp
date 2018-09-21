
#include <cstdlib>
#include <iostream>
#include "twoDArray.h"

using namespace std;

//Lab SignIn Project

int main() {
    
    int** p;
    int sizes[] = {7, 3, 4, -1};
    
    p = Chart<int>::allocate_twod(sizes);

    int n = Chart<int>::array_size(sizes);
//    cout << n << endl;
    
//    Chart<int>::lab_menu();
    
    Chart<int>::init_and_print(p, sizes); 

    return 0;
}

