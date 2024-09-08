#ifndef _COMMON_H
#define _COMMON_H

typedef struct binary_tree BinaryTree;
typedef struct binary_tree *btree;

struct binary_tree {
  int value;
  btree left;
  btree right;
};


BinaryTree newbt(int val);

#endif
