#ifndef _STACK_ARR
#define _STACK_ARR

#include "../../common/common.h"

/* Array implementation of Stack.  For the purposes of such small
   programs, function macros are rarely used to tweak performance. */

#define MAX_DEPTH 10

typedef struct stack_tag StackARR;
typedef struct stack_tag *StackARRPtr;

struct stack_tag {
  int entry[MAX_DEPTH];
  int top;
};


void push(StackARRPtr, int);
void pop(StackARRPtr, int*);
int peek(StackARRPtr);
void init(StackARRPtr);
int is_empty(StackARRPtr);
int is_full(StackARRPtr);

#endif
