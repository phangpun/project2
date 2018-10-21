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
}

single_list::~single_list()
{
  /*** MODIFY HERE ***/
}

int
single_list::list_get_data1(list_elem *elem)
{
  /*** MODIFY HERE ***/
}

int
single_list::list_get_data2(list_elem *elem)
{
  /*** MODIFY HERE ***/
}

string
single_list::list_get_data3(list_elem *elem)
{
  /*** MODIFY HERE ***/
}


/* Returns the element after ELEM in its list. */
list_elem *
single_list::list_next (list_elem *elem)
{
  /*** MODIFY HERE ***/
}


/* Returns LIST's head. */
list_elem *
single_list::list_head (void)
{
  /*** MODIFY HERE ***/
}

/* Insert ELEM at the beginning of LIST, so that it becomes the head 
   in LIST. */
void 
single_list::list_insert_front (list_elem *elem)
{
    /*** MODIFY HERE ***/
}

/* Insert ELEM just before BEFORE, which may be either an interior
 element or a head. */
void 
single_list::list_insert_before (list_elem *before, list_elem *elem)
{
  /*** MODIFY HERE ***/
}

/* Insert ELEM just after AFTER, which may be either an interior
 element or a head. */
void 
single_list::list_insert_after (list_elem *after, list_elem *elem)
{
  /*** MODIFY HERE ***/
}

/* Replace FROM with TO and destruct FROM */
void 
single_list::list_replace (list_elem *from, list_elem *to)
{
  /*** MODIFY HERE ***/
}


/* Removes ELEM from its list and destructs it. */
void
single_list::list_remove (list_elem *elem)
{
  /*** MODIFY HERE ***/
}

/* Returns true if LIST is empty, false otherwise. */
bool 
single_list::list_empty (void)
{
  /*** MODIFY HERE ***/  
}


