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
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			delete element_pointer;
			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}
}

int
single_list::list_get_data1(list_elem *elem)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* next_element_pointer = element_pointer->next;
		
		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == elem->data1);
			bool condition2 = (element_pointer->data2 == elem->data2);
			bool condition3 = (element_pointer->data3 == elem->data3);

			if (condition1 && condition2 && condition3) return element_pointer->data1;
			
			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}

	return 0;
}

int
single_list::list_get_data2(list_elem *elem)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == elem->data1);
			bool condition2 = (element_pointer->data2 == elem->data2);
			bool condition3 = (element_pointer->data3 == elem->data3);

			if (condition1 && condition2 && condition3) return element_pointer->data2;

			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}
	return 0;
}

string
single_list::list_get_data3(list_elem *elem)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == elem->data1);
			bool condition2 = (element_pointer->data2 == elem->data2);
			bool condition3 = (element_pointer->data3 == elem->data3);

			if (condition1 && condition2 && condition3) return element_pointer->data3;

			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}
	return "";
}


/* Returns the element after ELEM in its list. */
list_elem *
single_list::list_next (list_elem *elem)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == elem->data1);
			bool condition2 = (element_pointer->data2 == elem->data2);
			bool condition3 = (element_pointer->data3 == elem->data3);

			if (condition1 && condition2 && condition3) return element_pointer->next;

			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}

	return NULL;
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
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* before_element_pointer = NULL;
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == before->data1);
			bool condition2 = (element_pointer->data2 == before->data2);
			bool condition3 = (element_pointer->data3 == before->data3);

			if (condition1 && condition2 && condition3) {
				if (element_pointer == head) {
					head = element_pointer->next;
				}
				else {
					before_element_pointer->next = next_element_pointer;
				}

				delete element_pointer;
				return;
			}

			before_element_pointer = element_pointer;
			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}
}

/* Insert ELEM just after AFTER, which may be either an interior
 element or a head. */
void 
single_list::list_insert_after (list_elem *after, list_elem *elem)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == after->data1);
			bool condition2 = (element_pointer->data2 == after->data2);
			bool condition3 = (element_pointer->data3 == after->data3);

			if (condition1 && condition2 && condition3) {
				if (next_element_pointer == NULL) {
					elem->next = NULL;
				}
				else {
					elem->next = element_pointer->next;
				}

				element_pointer->next = elem;
				return;
			}

			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}
}

/* Replace FROM with TO and destruct FROM */
void 
single_list::list_replace (list_elem *from, list_elem *to)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* before_element_pointer = NULL;
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == from->data1);
			bool condition2 = (element_pointer->data2 == from->data2);
			bool condition3 = (element_pointer->data3 == from->data3);

			if (condition1 && condition2 && condition3) {
				if (element_pointer == head) {
					to->next = element_pointer->next;
					head = to;
				}
				else {
					to->next = element_pointer->next;
					before_element_pointer = to;
				}
				delete element_pointer;
				return;
			}

			before_element_pointer = element_pointer;
			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
	}
}


/* Removes ELEM from its list and destructs it. */
void
single_list::list_remove (list_elem *elem)
{
  /*** MODIFY HERE ***/
	list_elem* element_pointer = head;
	if (head != NULL) {
		list_elem* before_element_pointer = NULL;
		list_elem* next_element_pointer = element_pointer->next;

		while (next_element_pointer != NULL) {
			bool condition1 = (element_pointer->data1 == elem->data1);
			bool condition2 = (element_pointer->data2 == elem->data2);
			bool condition3 = (element_pointer->data3 == elem->data3);

			if (condition1 && condition2 && condition3) {
				if (element_pointer == head) {
					head = element_pointer->next;
				}
				else {
					before_element_pointer->next = next_element_pointer;
				}
				delete element_pointer;
				return;
			}

			before_element_pointer = element_pointer;
			element_pointer = next_element_pointer;
			next_element_pointer = element_pointer->next;
		}
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


