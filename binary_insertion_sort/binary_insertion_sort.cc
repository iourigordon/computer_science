#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

// although index search is only O(log i), the sort will still take O(n^2)
// to complete, because of all the swaps
//

int binary_index_search(vector<int>& sort_array, int value, int low, int high)
{
    int mid;
    for (;low<high;){
        mid = (low+high)/2;
        if (value>sort_array[mid])
            low = mid+1;
        else if (value<sort_array[mid])
            high = mid-1;
        else
            break;
    }
    return (value <= sort_array[low])?low:low+1;
}

//
// The best case scenarion is when array is already sorted: O(n)
// The wort case is when every element needs to be inserted: O(n^2)
// Super fast on small arrays, outperforms quicksort
//

void insertion_sort(vector<int>& sort_array)
{
    int temp,j,new_loc;
    for (int i=1;i<sort_array.size();i++) {
        temp = sort_array[i];
        new_loc = binary_index_search(sort_array,temp,0,i);
        for (j=i;new_loc<j;j--) {
            sort_array[j] = sort_array[j-1];
        }
        sort_array[new_loc] = temp;
    }
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        insertion_sort(int_vector);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

