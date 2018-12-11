#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10 
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

void insert_sort(vector<int>& src_array, int start_idx, int end_idx)
{
    int temp,j;
    for (int i=start_idx+1;i<end_idx;i++) {
        temp=src_array[i];
        for (j=i;(j>start_idx)&&(temp<src_array[j-1]);j--) {
            src_array[j]=src_array[j-1];
        }
        src_array[j]=temp;
    }
}

//#define DEBUG_PRINT

void merge(vector<int>& src_array, int left_idx, int right_idx, int end_idx)
{
    int temp;
    int i,j,dst_idx;
#ifdef DEBUG_PRINT
    cout << "Left Side" << endl;
    for (int i=left_idx;i<right_idx;i++) {
        cout << src_array[i] << " ";
    }
    cout << endl;
    cout << "====================" << endl;
    cout << "Right Side" << endl;
    for (int i=right_idx;i<end_idx;i++) {
        cout << src_array[i] << " ";
    }
    cout << endl;
    cout << "====================" << endl;
#endif
    i=left_idx,j=right_idx;
    for (int dst_idx=i;dst_idx<end_idx;dst_idx++) {
        if ((j<end_idx) && ((i >= right_idx) || (src_array[i] > src_array[j]))) {
            if (src_array[i] > src_array[j]) {
                temp=src_array[dst_idx];
                src_array[dst_idx] = src_array[j];
                src_array[j]=temp;
                insert_sort(src_array,j,end_idx);
                i++;
            } else {
                src_array[dst_idx]=src_array[j++];
            }
        } else {
            src_array[dst_idx] = src_array[i++];
        }
    }
#ifdef DEBUG_PRINT
    cout << "Merged Array" << endl;
    for (int i=left_idx;i<end_idx;i++) {
        cout << src_array[i] << " ";
    }
    cout << endl;
    cout << "====================" << endl;
#endif
}

//
// Bottom up sort performance is bounded by O(nlogn)
// 

void bottom_up_merge_sort(vector<int>& sort_array)
{
    for (int width=1; width<sort_array.size(); width*=2) {
        for (int i=0; i<sort_array.size(); i+=width*2) {
                merge(sort_array,i,min(i+width,(int)sort_array.size()),min(i+width*2,(int)sort_array.size()));
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

        bottom_up_merge_sort(int_vector);
        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

