#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10 
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

void merge_sort(vector<int>& source, vector<int>& dest, int left_idx, int right_idx, int end_idx) {
	if ((end_idx-left_idx)<2)
		return;

	merge_sort(dest,source,left_idx,(left_idx+right_idx)/2,right_idx);
	merge_sort(dest,source,right_idx,(right_idx+end_idx)/2,end_idx);

	//do actual merge here

	int i = left_idx;
	int j = right_idx;
	for (int k=left_idx;k<end_idx;k++) {
		if ((i<right_idx) && ((source[i] < source[j]) || j>=end_idx))
			dest[k] = source[i++];
		else
			dest[k] = source[j++];
	}
}

int main(int argc, char* argv[]) {
	vector<int> int_vector,temp;

	for (int i=0;i<MAX_ITERATIONS;i++) {
		generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
        cout << "+++++++++++++++++++++++" << endl;
		print_int_array(int_vector);
		temp = int_vector;

		merge_sort(temp, int_vector, 0, int_vector.size()/2, int_vector.size());

		print_int_array(int_vector);	
        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
	}
	return 0;
}
