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

/**
 * Testing function stackElementCreate.
 *            ___________
 *   ptr---->|  Data=1  |
 *          |__________|---->NULL
 *
 *
 */
void test_function_stackElementCreate()
{
	StackElement *ptr;

  ptr=stackElementCreate(1);

  TEST_ASSERT_NOT_NULL(ptr);
  TEST_ASSERT_EQUAL(1,ptr->data);
  TEST_ASSERT_EQUAL(NULL,ptr->next);
}
/**
 * Testing function stackCreate.
 *
 *    ptr---+-->head-----+
 *          |            |
 *          +-->tail-----+
 *                       |
 *                       v
 *                      NULL
 */
void test_function_stackCreate()
{
  Stack *ptr;

  ptr=stackCreate();

  TEST_ASSERT_NOT_NULL(ptr);
  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
  TEST_ASSERT_EQUAL(0,ptr->length);
}
/**
 * Testing function stackAdd when one element added to the stack.
 *
 *                            __________
 *    ptr---+-->head------>  |  Data=1  |
 *          |                |__________|---->NULL
 *          |                    ^
 *          |                    |
 *          +-->tail-------------+
 *
 */
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

 /**
 * Testing function stackAdd when two element added to the stack.
 *
 *                      _________      _________
 *    ptr---+-->head-->| Data=2 |     | Data=1 |
 *          |          |________|---->|________|---->NULL
 *          |                             ^
 *          |                             |
 *          +-->tail----------------------+
 *
 */
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

 /**
 * Testing function stackAdd when three element added to the stack.
 *
 *                   _________      _________      _________
 * ptr---+-->head-->| Data=3 |     | Data=2 |     | Data=1 |
 *       |          |________|---->|________|---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */

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

 /**
 * this test is to prevent the situation below are not happening.
 * Which is the NULL element is adding to the stack.
 *                   _________                     _________
 * ptr---+-->head-->| Data=3 |                    | Data=1 |
 *       |          |________|---->NULL           |________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */
void test_stackAdd_given_Element_equal_NULL_Should_do_nothing()
{
  int i;
  Stack *ptr;

  ptr=stackCreate();

  stackAdd(ptr,stackElementCreate(1));
  stackAdd(ptr,NULL);
  stackAdd(ptr,stackElementCreate(3));

  TEST_ASSERT_EQUAL(3,ptr->head->data);
  TEST_ASSERT_EQUAL_PTR(ptr->tail,ptr->head->next);
  TEST_ASSERT_EQUAL(1,ptr->tail->data);
  TEST_ASSERT_NULL(ptr->tail->next);
  TEST_ASSERT_EQUAL(2,ptr->length);

}

 /**
 * Testing function stackAdd when five element added to the stack
 *
 *                   _________                     _________
 * ptr---+-->head-->| Data=5 |                    | Data=1 |
 *       |          |________|----> * * * * *---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 */
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

// Testing function stackRemove when there are no element in stack.
void test_stackRemove_given_no_element_in_Stack_should_remove_nothing()
{
  Stack *ptr;
  StackElement *RemovedEle;

  ptr=stackCreate();
  RemovedEle=stackRemove(ptr);
  
  TEST_ASSERT_NULL(RemovedEle);
  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
}

/**
 * Testing function stackRemove when there are only one element in stack.
 *
 *                            __________
 *    ptr---+-->head------>  |  Data=1  |
 *          |                |__________|---->NULL
 *          |                    ^
 *          |                    |
 *          +-->tail-------------+
 *
 *                       ||
 *                       ||
 *                      \ /
 *                                ___________
 *    ptr---+-->head-----+       |  Data=1  |
 *          |            |       |__________|----->NULL
 *          +-->tail-----+
 *                       |
 *                       v
 *                      NULL
 */
void test_stackRemove_given_one_element_in_Stack_should_remove_head_Element()
{
  Stack *ptr;
  StackElement *RemovedEle;

  ptr=stackCreate();
  stackAdd(ptr,stackElementCreate(1));
  RemovedEle=stackRemove(ptr);

  TEST_ASSERT_EQUAL(1,RemovedEle->data);
  TEST_ASSERT_NULL(RemovedEle->next);
  
  TEST_ASSERT_NULL(ptr->head);
  TEST_ASSERT_NULL(ptr->tail);
  TEST_ASSERT_EQUAL(0,ptr->length);
}


 /**
 * Testing function stackRemove when there are three element in stack.
 *
 *
 *                   _________      _________      _________
 * ptr---+-->head-->| Data=3 |     | Data=2 |     | Data=1 |
 *       |          |________|---->|________|---->|________|---->NULL
 *       |                                            ^
 *       |                                            |
 *       +-->tail-------------------------------------+
 *
 *                            ||
 *                            ||
 *                           \ /
 *
 *            +-------------------------------+
 *            |      _________            ____v____      _________
 * ptr---+-->head   | Data=3 |           | Data=2 |     | Data=1 |
 *       |          |________|--->NULL   |________|---->|________|---->NULL
 *       |                                                    ^
 *       |                                                    |
 *       +-->tail---------------------------------------------+
 *
 */
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
  TEST_ASSERT_NULL(RemovedEle->next);
  
  TEST_ASSERT_EQUAL(2,ptr->head->data);
  TEST_ASSERT_EQUAL(1,ptr->head->next->data);
  TEST_ASSERT_EQUAL(2,ptr->length);
}


//test whether after removing are able to add again
void test_Add_and_Remove_Element_to_stack()
{
  int i;
  Stack *ptr;
  StackElement *RemovedEle;

  ptr=stackCreate();

  for(i=1;i<=3;i++){
    stackAdd(ptr,stackElementCreate(i));
  }

  RemovedEle=stackRemove(ptr);

  stackAdd(ptr,stackElementCreate(5));

  TEST_ASSERT_EQUAL(3,RemovedEle->data);
  TEST_ASSERT_NULL(RemovedEle->next);
  
  TEST_ASSERT_EQUAL(5,ptr->head->data);
  TEST_ASSERT_EQUAL(2,ptr->head->next->data);
  TEST_ASSERT_EQUAL(1,ptr->head->next->next->data);
  TEST_ASSERT_NULL(ptr->head->next->next->next);
  TEST_ASSERT_EQUAL(3,ptr->length);
}







