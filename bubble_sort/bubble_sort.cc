#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

//
// The best case scenarion is when array is already sorted: O(n)
// The wort case is when every element needs to be inserted: O(n^2)
// 

void bubble_sort(vector<int>& sort_array)
{
    int  temp;
    bool swap;

    swap = true;
    for (;swap!=false;) {
        swap = false;
        for (int i=0; i< sort_array.size()-1; i++) {
            if (sort_array[i] > sort_array[i+1]) {
                temp = sort_array[i];
                sort_array[i] = sort_array[i+1];
                sort_array[i+1] = temp;
                swap = true;
            }
        }
    }
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        bubble_sort(int_vector);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

