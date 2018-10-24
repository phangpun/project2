#include <iostream>
#include <string>

#include "single_list.h"

using namespace std;


//////////////////////////////////////////////
// CAUTION: DO NOT CHANGE INCLUDED HEADERS  //
//////////////////////////////////////////////


/* Our singly linked lists have one header elements: the "head" which
   points the first element. The "next" link of the back header is
   NULL. 
   An empty list looks like this:

                  
          HEAD ---> NULL 
                  

   A list with two elements in it looks like this:
   
                   +-------+    +-------+
          HEAD --->|   1   |--->|   2   |--->NULL
                   +-------+    +-------+

   You should not change the name, input arguments, and
   input/output data types of existing functions. */



/*** COMPLETE FUNCTIONS BELOW ***/

/* SINGLY LINKED LIST */

/* Initializes LIST as an empty list with a head. */
single_list::single_list()
{
  /*** MODIFY HERE ***/
	
	head = NULL;
}

single_list::~single_list()
{
  /*** MODIFY HERE ***/
	//delete all element of single_list
	list_elem* element_pointer = head;
	list_elem* next_element_pointer = NULL;
	if (element_pointer != NULL) {//until no element in list
		while (element_pointer != NULL) {
			next_element_pointer = element_pointer->next;
			delete element_pointer;
			element_pointer = next_element_pointer;
		}
	}
}

int
single_list::list_get_data1(list_elem *elem)
{
  /*** MODIFY HERE ***/
	return elem->data1;
}

int
single_list::list_get_data2(list_elem *elem)
{
  /*** MODIFY HERE ***/
	return elem->data2;
}

string
single_list::list_get_data3(list_elem *elem)
{
  /*** MODIFY HERE ***/
	return elem->data3;
}


/* Returns the element after ELEM in its list. */
list_elem *
single_list::list_next (list_elem *elem)
{
  /*** MODIFY HERE ***/
	return elem->next;
}


/* Returns LIST's head. */
list_elem *
single_list::list_head (void)
{
  /*** MODIFY HERE ***/
	return head;
}

/* Insert ELEM at the beginning of LIST, so that it becomes the head 
   in LIST. */
void 
single_list::list_insert_front (list_elem *elem)
{
    /*** MODIFY HERE ***/

	elem->next = head;
	head = elem;
}

/* Insert ELEM just before BEFORE, which may be either an interior
 element or a head. */
void 
single_list::list_insert_before (list_elem *before, list_elem *elem)
{
  /*** MODIFY HERE ***/
	if (before == head) {
		list_insert_front(elem);
	}
	else {
		list_elem* prev_pointer = head; //find previous pointer of before
		while (prev_pointer->next != before) {
			prev_pointer = prev_pointer->next;
		}
		elem->next = before;
		prev_pointer->next = elem;
	}
}

/* Insert ELEM just after AFTER, which may be either an interior
 element or a head. */
void 
single_list::list_insert_after (list_elem *after, list_elem *elem)
{
  /*** MODIFY HERE ***/
	elem->next = after->next;
	after->next = elem;
}

/* Replace FROM with TO and destruct FROM */
void 
single_list::list_replace (list_elem *from, list_elem *to)
{
  /*** MODIFY HERE ***/
	if (from == head) {
		head = to;
		to->next = from->next;
		delete from;
	}
	else {
		list_elem* prev_pointer = head; //find previous pointer of before
		while (prev_pointer->next != from) {
			prev_pointer = prev_pointer->next;
		}
		prev_pointer->next = to;
		to->next = from->next;
		delete from;
	}
}


/* Removes ELEM from its list and destructs it. */
void
single_list::list_remove (list_elem *elem)
{
  /*** MODIFY HERE ***/
	if (elem == head) {
		head = elem->next;
		delete elem;
	}
	else {
		list_elem* prev_pointer = head; //find previous pointer of before
		while (prev_pointer->next != elem) {
			prev_pointer = prev_pointer->next;
		}
		prev_pointer->next = elem->next;
		delete elem;
	}
}

/* Returns true if LIST is empty, false otherwise. */
bool 
single_list::list_empty (void)
{
  /*** MODIFY HERE ***/  
	if (head == NULL) return true;
	else return false;
}


