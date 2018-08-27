#include <iostream>
#include <vector>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100

int main(int argc, char* argv[]) {
	vector<int> int_vector;

	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	print_int_array(int_vector);
	    
	return 0;
}
