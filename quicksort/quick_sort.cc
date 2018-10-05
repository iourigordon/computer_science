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

void quick_sort(vector<int>& sort_array)
{
    int temp,j;
    for (int i=1;i<sort_array.size();i++) {
        temp = sort_array[i];
        for (j=i;j>0,temp<sort_array[j-1];j--) {
            sort_array[j] = sort_array[j-1];
        }
        sort_array[j] = temp;
    }
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        quick_sort(int_vector);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

