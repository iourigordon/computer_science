#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10 
#define MAX_ARRAY_ELEM 10
#define MAX_ITERATIONS 10

void counting_sort(vector<int> sort_array, vector<int>& out_array)
{
    vector<int> hist(MAX_ARRAY_ELEM,0);

    for (int i=0;i<MAX_ARRAY_SIZE;i++) {
        hist[sort_array[i]] = hist[sort_array[i]] + 1;
    }

    print_int_array(hist);

    int elem_count;
    int pos_count = 0;
    for (int i=0;i<hist.size();i++) {
        elem_count = hist[i];
        hist[i] = pos_count;
        pos_count+=elem_count;
    }

    print_int_array(hist);

    for (int i=0;i<sort_array.size();i++) {
        out_array[hist[sort_array[i]]] = sort_array[i];
        hist[sort_array[i]] = hist[sort_array[i]] + 1;
    }
}

int main(int argc, char* argv[])
{
    vector<int> out_array;
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        out_array.resize(MAX_ARRAY_SIZE);
        counting_sort(int_vector,out_array);
        print_int_array(out_array);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

