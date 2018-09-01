#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 1

void merge(vector<int>& src_array, vector<int>& dst_array, int start_idx, int merge_width)
{
    int i,j;

    for (i=start_idx,j=merge_width+start_idx;i<(start_idx+merge_width);) {
        if ((j<src_array.size()) && (src_array[i] > src_array[j])) {
            dst_array[i] = src_array[j];
            j++;
        } else {
            dst_array[i] = src_array[i++];
        }
    }
}

//
// The best case scenarion is when array is already sorted: O(n)
// The wort case is when every element needs to be inserted: O(n^2)
// 

void bottom_up_merge_sort(vector<int>& sort_array)
{
    vector<int> temp_array = sort_array;

    for (int width=1; width<sort_array.size(); width*=2) {
        for (int i=0; (i+width*2)<sort_array.size(); i+=width*2) {
            merge(sort_array,temp_array,i,width);
        }
        sort_array=temp_array;
    } 
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        bottom_up_merge_sort(int_vector);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

