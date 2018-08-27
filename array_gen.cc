#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

//
// Prints int array
//

void print_int_array(vector<int>& int_array)
{
    for (auto& elem: int_array)
        cout << elem << " ";
    cout << endl;
}

//
// Generates an array of integers bound by parameter size
// max element is bounded by parameter max_element
// resizes and populates an array passed by reference
//

void generate_int_array(int max_size, int max_element, vector<int>& int_array)
{
    int_array.resize(max_size);
    for (auto& elem: int_array)
        elem = rand()%max_element;
 
}

