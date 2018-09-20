#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

#define PARENT(i) i
#define LEFT_CHILD(i) i*2
#define RIGHT_CHILD(i) i*2+1

void heapify(vector<int>& to_sort)
{
    int temp,swap;
    int left_chld;
    int right_chld;
    int prnt_node = PARENT(to_sort.size()-1);

    for (;prnt_node>=0;) {
        while (LEFT_CHILD(prnt_node) < to_sort.size()) {
            if (to_sort[prnt_node] < to_sort[LEFT_CHILD(prnt_node)])
                swap = LEFT_CHILD(prnt_node);
            if ((RIGHT_CHILD(prnt_node) < to_sort.size()) && 
                (to_sort[swap] < to_sort[RIGHT_CHILD(prnt_node)]))
                swap = RIGHT_CHILD(prnt_node); 
            if (swap!=prnt_node){
                temp = to_sort[prnt_node];
                to_sort[prnt_node] = to_sort[swap];
                to_sort[swap] = temp;
            }
            prnt_node = swap;
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

        print_int_array(int_vector);

        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

