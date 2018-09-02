#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10 
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

void merge(vector<int>& src_array, vector<int>& dst_array, int left_idx, int right_idx, int end_idx)
{
    int i,j,dst_idx;

    i=left_idx,j=right_idx;
    for (int dst_idx=i;dst_idx<end_idx;dst_idx++) {
        if ((j<end_idx) && ((i >= right_idx) || (src_array[i] > src_array[j]))) {
            dst_array[dst_idx] = src_array[j++];
        } else {
            dst_array[dst_idx] = src_array[i++];
        }
    }
}

//
// Bottom up search performance is bounded by O(nlogn)
// 

void bottom_up_merge_sort(vector<int>& sort_array)
{
    vector<int> temp_array = sort_array;

    for (int width=1; width<sort_array.size(); width*=2) {
        for (int i=0; i<sort_array.size(); i+=width*2) {
                merge(sort_array,temp_array,i,min(i+width,(int)sort_array.size()),min(i+width*2,(int)sort_array.size()));
        }
        sort_array = temp_array;
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

