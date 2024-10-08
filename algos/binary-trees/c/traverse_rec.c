#include <stdio.h>
#include "common.h"

#define visit(val) printf("%d ", val)

BinaryTree BT;

BinaryTree newbt(int val)
{
  BinaryTree bt;
  bt.value = val;
  bt.left = bt.right = NULL;
  return bt;
}

/* ---------------------- Traverse ------------------------ */
/* Traverse the given binary tree `bt' in the order of
   left, middle (root) and right, recursively. */
void pre_order(btree bt)
{
  if (bt == NULL)
    return;

  /* print the node value only for the first time */
  visit(bt->value);
  pre_order(bt->left);
  pre_order(bt->right);
}

/* Traverse the given binary tree `bt' in the order of
   middle, left, right, recursively */
void in_order(btree bt)
{
  if (bt == NULL)
    return;

  in_order(bt->left);
  /* print the node value only for the second time */
  visit(bt->value);
  in_order(bt->right);
}

/* Traverse the given binary tree `bt' in the order of
   left, right, middle (root/node) */
void pos_order(btree bt)
{
  if (bt == NULL)
    return;

  pos_order(bt->left);
  pos_order(bt->right);
  visit(bt->value);
}


/* Main as the test function */
int main(int argc, char *argv[])
{
  BinaryTree t2, t3, t4, t5, t6, t7;
  t2 = newbt(2);
  t3 = newbt(3);
  t4 = newbt(4);
  t5 = newbt(5);
  t6 = newbt(6);
  t7 = newbt(7);

  BT.value = 1;
  BT.left = &t2;
  BT.right = &t3;

  t2.left = &t4;
  t2.right = &t5;
  t3.left = &t6;
  t3.right = &t7;

  printf("Traversing in pre-order: \n");
  pre_order(&BT);
  printf("\n");
  printf("Traversing in pre-order: \n");
  in_order(&BT);
  printf("\n");
  printf("Traversing in pre-order: \n");
  pos_order(&BT);
  printf("\n");

  return 0;
}
