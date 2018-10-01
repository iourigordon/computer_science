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
#define LEFT_CHILD(i) (i)*2+1
#define RIGHT_CHILD(i) (i)*2+2

#define PRNT_BUFF_LENGTH 1024

enum {
    PRNT_LEFT_EDGE,
    PRNT_RIGHT_EDGE,
    PRNT_BOTH
};

#define PRINT_SPACES(buff,buff_len,num) \
memset(buff,0,buff_len); \
for (int i=0;i<num;i++) \
    sprintf(buff+i," "); \
cout << buff

int print_node_edges(char* buff, int offset, int delta, int type )
{
    switch (type) {
        case PRNT_LEFT_EDGE:
            sprintf(buff+offset-delta,"/");
            buff[offset-delta+1] = ' ';
            return offset-delta+1;
        case PRNT_RIGHT_EDGE:
            sprintf(buff+offset+2+delta,"\\");
            buff[offset+2+delta+1] = ' ';
            return offset+2+delta+1; 
        case PRNT_BOTH:
            sprintf(buff+offset-delta,"/");
            buff[offset-delta+1] = ' ';
            sprintf(buff+offset+2+delta,"\\");
            buff[offset+2+delta+1] = ' ';
            return offset+2+delta+1; 
    }
    return 0;
}

void print_heap(vector<int>& heap, int node_width) 
{
    int root;
    int curr_line, next_line;
    char prnt_buff[PRNT_BUFF_LENGTH];
    char edge_buff[PRNT_BUFF_LENGTH];
    int heap_height = pow(2,floor(log2(heap.size())))*4;
    int chld_delta = (heap_height-node_width)/2-1;
    queue<int> heap_queue;

    root = 0;

    PRINT_SPACES(prnt_buff,PRNT_BUFF_LENGTH,chld_delta);
    cout << heap[root] << endl;

    memset(edge_buff,' ',PRNT_BUFF_LENGTH);
    edge_buff[print_node_edges(edge_buff,chld_delta,chld_delta/4,PRNT_BOTH)+1] = '\0'; 
    cout << edge_buff << endl;

    curr_line = 1;
    next_line = 0;
    heap_queue.push(root);
    
    memset(edge_buff,' ',PRNT_BUFF_LENGTH);
    PRINT_SPACES(prnt_buff,PRNT_BUFF_LENGTH,(chld_delta-node_width)/2);
 
    int edge_pos = (chld_delta-node_width)/2;
    for (;!heap_queue.empty();) {
        root = heap_queue.front();
        heap_queue.pop();
        if (LEFT_CHILD(root) < heap.size()) {
            cout << heap[LEFT_CHILD(root)];
            if (LEFT_CHILD(LEFT_CHILD(root)) < heap.size()) {
                print_node_edges(edge_buff,edge_pos,chld_delta/4,PRNT_LEFT_EDGE);
            }
            if (RIGHT_CHILD(LEFT_CHILD(root)) < heap.size()) {
                print_node_edges(edge_buff,edge_pos-1,chld_delta/4,PRNT_RIGHT_EDGE);
            }
            heap_queue.push(LEFT_CHILD(root));
            next_line+=1;
        }

        edge_pos+=chld_delta+node_width;
        PRINT_SPACES(prnt_buff,PRNT_BUFF_LENGTH,chld_delta);
        
        if (RIGHT_CHILD(root) < heap.size()) {
            cout << heap[RIGHT_CHILD(root)];
            if (LEFT_CHILD(RIGHT_CHILD(root)) < heap.size()) {
                print_node_edges(edge_buff,edge_pos,chld_delta/4,PRNT_LEFT_EDGE);
            }
            if (RIGHT_CHILD(RIGHT_CHILD(root)) < heap.size()) {
                print_node_edges(edge_buff,edge_pos-1,chld_delta/4,PRNT_RIGHT_EDGE);
            }
            heap_queue.push(RIGHT_CHILD(root));
            next_line+=1;
        }
        if ((--curr_line == 0) && (next_line != 0)) {
            cout << endl;
            edge_buff[heap_height] = '\0';
            cout << edge_buff << endl;
            curr_line = next_line;
            next_line = 0;
            chld_delta = (chld_delta-node_width)/2;
            memset(edge_buff,' ',PRNT_BUFF_LENGTH);
            PRINT_SPACES(prnt_buff,PRNT_BUFF_LENGTH,(chld_delta-node_width)/2);
            edge_pos = (chld_delta-node_width)/2;
        } else {
            PRINT_SPACES(prnt_buff,PRNT_BUFF_LENGTH,chld_delta);
            edge_pos+=chld_delta;
 
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

        print_heap(int_vector,2);
        int_vector.erase(int_vector.begin());
        cout << "-----------------------" << endl;
    }

	return 0;
}

