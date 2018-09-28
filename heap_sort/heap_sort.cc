#include <string.h>
#include <stdlib.h>

#include <cmath>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#include "array_gen.h"

#define MAX_ARRAY_SIZE 10
#define MAX_ARRAY_ELEM 100
#define MAX_ITERATIONS 10

#define PARENT(i) (i)/2
#define LEFT_CHILD(i) i*2+1
#define RIGHT_CHILD(i) i*2+2

#define PRNT_BUFF_LENGTH 1024

void print_heap(vector<int>& heap) 
{
    int root;
    int curr_line, next_line;
    char prnt_buff[PRNT_BUFF_LENGTH];
    int heap_height = pow(2,floor(log2(heap.size())))*4;
    int prnt_offset = heap_height;
    int chld_delta = prnt_offset;
    queue<int> heap_queue;

    cout << "heap.size() = " << heap.size() << endl;
    cout << "floor(log2(heap.size()) = " << floor(log2(heap.size())) << endl;
    cout << "pow(2,floor(log2(heap.size()))) = " << pow(2,log2(heap.size())) << endl;
    cout << "chld_delta = " << chld_delta << endl;
    root = 0;

    for (int i=0;i<prnt_offset;i++)
        sprintf(prnt_buff+i," ");
    cout << prnt_buff;
    cout << heap[root] << endl;
    curr_line = 1;
    next_line = 0;
    heap_queue.push(root);
    

    memset(prnt_buff,0,PRNT_BUFF_LENGTH);
    for (int i=0;i<(chld_delta-2)/2;i++)
        sprintf(prnt_buff+i," ");
    cout << prnt_buff;
 
    for (;!heap_queue.empty();) {
        root = heap_queue.front();
        heap_queue.pop();
        if (LEFT_CHILD(root) < heap.size()) {
            cout << heap[LEFT_CHILD(root)];
            heap_queue.push(LEFT_CHILD(root));
            next_line+=1;
        }
        memset(prnt_buff,0,PRNT_BUFF_LENGTH);
        for (int i=0;i<chld_delta;i++)
            sprintf(prnt_buff+i," ");
        cout << prnt_buff;
        
        if (RIGHT_CHILD(root) < heap.size()) {
            cout << heap[RIGHT_CHILD(root)];
            heap_queue.push(RIGHT_CHILD(root));
            next_line+=1;
        }
        if (--curr_line == 0) {
            cout << endl;
            curr_line = next_line;
            next_line = 0;
            chld_delta = (chld_delta-2)/2;
            memset(prnt_buff,0,PRNT_BUFF_LENGTH);
            for (int i = 0; i < (chld_delta-2)/2;i++)
                sprintf(prnt_buff+i," ");
            cout << prnt_buff;
        } else {
            memset(prnt_buff,0,PRNT_BUFF_LENGTH);
            for (int i = 0; i < chld_delta;i++)
                sprintf(prnt_buff+i," ");
            cout << prnt_buff;
 
        }
    }
}

void heapify(vector<int>& to_sort)
{
    int heap_root,temp,swap;
    int prnt_node = PARENT(to_sort.size()-1);

    heap_root = prnt_node;
    for (;heap_root>=0;) {
        prnt_node = heap_root;
        swap = prnt_node;
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
            } else {
                break;
            }
            prnt_node = swap;
        }
        heap_root = heap_root - 1;
    }
}

int main(int argc, char* argv[])
{
	vector<int> int_vector;

    for (int i=0;i<MAX_ITERATIONS;i++) {
        cout << "+++++++++++++++++++++++" << endl;
    	generate_int_array(MAX_ARRAY_SIZE, MAX_ARRAY_ELEM, int_vector);
	    print_int_array(int_vector);

        heapify(int_vector);

        print_int_array(int_vector);

        print_heap(int_vector);
        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

