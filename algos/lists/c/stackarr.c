#include "stackarr.h"

/* Push `val' onto the `top' of current stack if it is not full. */
void push(StackARRPtr stack, int val)
{
  if (is_full(stack))
    Error("Cannot push to full stack.");

  /* posfix ++ returns original top frist and inc it afterwards */
  stack->entry[stack->top++] = val;
}

void pop(StackARRPtr stack, int *val)
{
  if (is_empty(stack))
    Error("Cannot pop from empty stack");

  /* prefix -- dec original top frist and return it afterwards */
  *val = stack->entry[--stack->top];;

  /* optional: clean the old top */
  stack->entry[stack->top + 1] = -1;
}

int peek(StackARRPtr stack)
{
  return stack->entry[stack->top];
}

/* `top' is initialized to be 0 instead of -1 (another common choice).
   In such a case, we always push/pop value to the index pointed to by
   `top' and inc/dec `top' accordingly after the operation. */
void init(StackARRPtr stack)
{
  stack->top = 0;
}

int is_empty(StackARRPtr stack)
{
  return stack->top == 0;
}

int is_full(StackARRPtr stack)
{
  return stack->top >= MAX_DEPTH;
}

/* Test */
int main(int argc, char *argv[])
{
  int i, val;
  StackARR stack;
  StackARRPtr stackptr = &stack;
  init(stackptr);

  for (i = 0; i < MAX_DEPTH; i++)
    push(stackptr, i * 2);

  for (i = 0; i < MAX_DEPTH; i++) {
    pop(stackptr, &val);
    printf("poped val = %d\n", val);
  }

  return 0;
}
