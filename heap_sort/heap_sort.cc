#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

#define PARENT(i) floor(i-1)/2
#define LEFT_CHILD i*2+1
#define RIGHT_CHILD i*2+2

void heapify(vector<int>& to_sort)
{
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

