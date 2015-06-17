#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


Stack *stackCreate(){
  Stack *ptr=malloc(sizeof(Stack));
  assert(ptr != NULL);
  
  ptr->head=NULL;
  ptr->tail=NULL;
  ptr->length=0;
  return ptr;
}


StackElement *stackElementCreate(int data){
  StackElement *ptr=malloc(sizeof(StackElement));
  assert(ptr != NULL);
  
  ptr->data=data;
  ptr->next=NULL;
  
  return ptr;
}

void stackAdd(Stack *stack,StackElement *NewElem){
  
  
  if(stack->head==NULL && stack->tail==NULL){
    stack->head=NewElem;
    stack->tail=stack->head;
    (stack->length)++;
  }
  else if(stack==NULL||NewElem==NULL){}
  
  
  else{
    NewElem->next=stack->head;
    stack->head=NewElem;
    (stack->length)++;
  }
}


StackElement *stackRemove(Stack *stack){
  StackElement *ptr;
  
  if(stack->head==NULL && stack->tail==NULL){
    return NULL;
  }
  else if(stack->head->next==NULL){
    ptr=stack->head;
    stack->head=NULL;
    stack->tail=NULL;
    (stack->length)--;
  }
  else{
    ptr=stack->head;
    stack->head=stack->head->next;
    (stack->length)--;
  }
  
  return ptr;
    
   
}
  




