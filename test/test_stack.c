#include "unity.h"
#include "stack.h"

#include <stdlib.h>
#include <assert.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_function_stackElementCreate()
{
	StackElement *ptr;
  
  ptr=stackElementCreate(1);
  
  TEST_ASSERT_NOT_NULL(ptr);
  TEST_ASSERT_EQUAL(1,ptr->data);
  TEST_ASSERT_EQUAL(NULL,ptr->next);
}


void test_function_stackCreate()
{
  Stack *ptr;
  
  ptr=stackCreate();
  
  TEST_ASSERT_NOT_NULL(ptr);
  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
  TEST_ASSERT_EQUAL(0,ptr->length);
}
  
void test_stackAdd_adding_one_element_into_the_stack()
{
  Stack *ptr;
  
  ptr=stackCreate();
  
  stackAdd(ptr,stackElementCreate(1));
  
  TEST_ASSERT_EQUAL(1,ptr->head->data);
  TEST_ASSERT_NULL(ptr->head->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->data);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(1,ptr->length);
}
 
void test_stackAdd_adding_two_element_into_the_stack()
{
  int i;
  Stack *ptr;
  
  ptr=stackCreate();
  
  for(i=1;i<=2;i++){
    stackAdd(ptr,stackElementCreate(i));
  }
  
  TEST_ASSERT_EQUAL(2,ptr->head->data);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->data);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(2,ptr->length);
  
}

void test_stackAdd_adding_three_element_into_the_stack()
{
  int i;
  Stack *ptr;
  
  ptr=stackCreate();
  
  for(i=1;i<=3;i++){
    stackAdd(ptr,stackElementCreate(i));
  }
  
  TEST_ASSERT_EQUAL(3,ptr->head->data);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->data);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(3,ptr->length);
  
}

void test_stackAdd_given_Element_equal_NULL_Should_do_nothing()
{
  int i;
  Stack *ptr;
  
  ptr=stackCreate();
  
  stackAdd(ptr,stackElementCreate(1));
  stackAdd(ptr,NULL);
  stackAdd(ptr,stackElementCreate(2));
  
  TEST_ASSERT_EQUAL(2,ptr->head->data);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->data);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(2,ptr->length);
  
}

void test_stackAdd_adding_five_element_into_Stack()
{
  Stack *ptr;
  StackElement *RemoveEle;
  int i;
  
  ptr=stackCreate();
  
  for(i=1;i<=5;i++){
    stackAdd(ptr,stackElementCreate(i));
  }
  
  TEST_ASSERT_EQUAL(5,ptr->head->data);
  TEST_ASSERT_EQUAL(4,ptr->head->next->data);
  TEST_ASSERT_EQUAL(3,ptr->head->next->next->data);
  TEST_ASSERT_EQUAL(2,ptr->head->next->next->next->data);
  TEST_ASSERT_EQUAL(1,ptr->head->next->next->next->next->data);
  TEST_ASSERT_NULL(ptr->head->next->next->next->next->next);
  TEST_ASSERT_EQUAL(5,ptr->length);
}

void test_stackRemove_given_three_element_in_Stack_should_remove_head_Element()
{
  int i;
  Stack *ptr;
  StackElement *RemovedEle;
  
  ptr=stackCreate();
  
  for(i=1;i<=3;i++){
    stackAdd(ptr,stackElementCreate(i));
  }
  
  RemovedEle=stackRemove(ptr);
  
  TEST_ASSERT_EQUAL(3,RemovedEle->data);
  TEST_ASSERT_EQUAL(2,ptr->head->data); 
  TEST_ASSERT_EQUAL(1,ptr->head->next->data); 
  TEST_ASSERT_EQUAL(2,ptr->length);
}



  
  
  
  
  
  