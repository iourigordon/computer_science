#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

//
// The complexity is always  O(n^2)
// 

void selection_sort(vector<int>& sort_array)
{
    int  min_idx,temp;

    for (int i=0;i<sort_array.size()-1;i++) {
        min_idx = i;
        for (int j=(min_idx+1);j<sort_array.size();j++) {
            if (sort_array[j] < sort_array[min_idx])
                min_idx = j;
        }
        temp = sort_array[i];
        sort_array[i] = sort_array[min_idx];
        sort_array[min_idx] = temp;
    }
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        selection_sort(int_vector);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

