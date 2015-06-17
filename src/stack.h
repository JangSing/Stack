#ifndef stack_H
#define stack_H


typedef struct StackElement_t{
  int data;
  struct StackElement_t *next;
}StackElement;

typedef struct{
  StackElement *head;
  StackElement *tail;
  int length;
}Stack;

Stack *stackCreate();
StackElement *stackElementCreate(int data);
void stackAdd(Stack *stack,StackElement *NewElem);
StackElement *stackRemove(Stack *stack);

#endif // stack_H
