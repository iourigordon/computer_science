#ifndef __print_tree_h__
#define __print_tree_h__

struct Tree 
{
  Tree * left, * right;
  int element;
};

void print_ascii_tree(Tree * t);

#endif
