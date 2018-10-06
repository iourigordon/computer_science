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
// Super fast on small arrays, outperforms quicksort
//

int partition(vector<int>& sort_array, int start_idx, int end_idx)
{
    int i,j,temp;
    int pivot = sort_array[start_idx];

    for (i=start_idx-1,j=end_idx+1;i<end_idx && j>start_idx;) {
        for (;sort_array[++i]<pivot && i<end_idx;)
            ;
        for (;sort_array[--j]>pivot && j>start_idx;)
            ;
        if (i<j) {
            temp = sort_array[i];
            sort_array[i] = sort_array[j];
            sort_array[j] = temp;
        } else
            return j;
    }
    return -1;
}

void quick_sort(vector<int>& sort_array, int start_idx, int end_idx)
{
    int pivot;

    if (!(start_idx<end_idx))
        return;
    pivot = partition(sort_array,start_idx,end_idx);

    quick_sort(sort_array,start_idx,pivot);
    quick_sort(sort_array,pivot+1,end_idx);
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        quick_sort(int_vector,0,int_vector.size()-1);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

