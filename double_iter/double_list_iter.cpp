#include <iostream>
#include <string>

#include "double_list_iter.h"

using namespace std;

//////////////////////////////////////////////
// YOU CAN CHANGE INCLUDED HEADERS ^0^ //
//////////////////////////////////////////////

/* Our doubly linked lists have two header elements: the "head"
   just before the first element and the "tail" just after the
   last element. The "prev" link of the front header is null, as
   is the "next" link of the back header. Their other two links
   point toward each other via the interior elements of the list.

   An empty list looks like this:

                      +------+     +------+
                  <---| head |<--->| tail |--->
                      +------+     +------+

   A list with two elements in it looks like this:

        +------+     +-------+     +-------+     +------+
    <---| head |<--->|   1   |<--->|   2   |<--->| tail |<--->
        +------+     +-------+     +-------+     +------+

   The symmetry of this arrangement eliminates lots of special
   cases in list processing. That's a lot simpler than the code 
   would be without header elements.

   (Because only one of the pointers in each header element is used,
   we could in fact combine them into a single header element
   without sacrificing this simplicity.  But using two separate
   elements allows us to do a little bit of checking on some
   operations, which can be valuable.) 

   You SHOULD NOT change the name, input arguments, and
   input/output data types of existing functions. */



//same with double_list.cpp
double_list::double_list()
{
	/*** MODIFY HERE ***/
	head = new d_list_elem;
	tail = new d_list_elem;
	head->next = tail;
	tail->prev = head;
}

//same with double_list.cpp
double_list::~double_list()
{
	/*** MODIFY HERE ***/
	while (head->next != tail) {
		d_list_elem *target = head->next;

		head->next = target->next;
		(target->next)->prev = head;

		delete target;
	}
	delete head;
	delete tail;
}

//same with double_list.cpp
void
double_list::d_list_insert_front(d_list_elem *elem)
{
	/*** MODIFY HERE ***/
	elem->prev = head;
	elem->next = head->next;

	(head->next)->prev = elem;
	head->next = elem;
}

//same with double_list.cpp
void
double_list::d_list_insert_back(d_list_elem *elem)
{
	/*** MODIFY HERE ***/
	elem->prev = tail->prev;
	elem->next = tail;

	(tail->prev)->next = elem;
	tail->prev = elem;
}

//same with double_list.cpp
d_list_elem *
double_list::d_list_front(void)
{
	/*** MODIFY HERE ***/
	if (head->next == tail) return NULL;
	else return head->next;
}

//same with double_list.cpp
bool
double_list::d_list_empty(void)
{
	/*** MODIFY HERE ***/
	if (head->next == tail) return true;
	else return false;
}



//Iteration implementation
//almost same with text book

double_list::Iter::Iter(d_list_elem* e) {
	Element = e;
}

int&
double_list::Iter::operator*() {
	return Element->data1;
}

bool
double_list::Iter::operator==(const Iter& p) const {
	return (Element->data1 == p.Element->data1);
}

bool
double_list::Iter::operator!=(const Iter& p) const {
	return (Element->data1 != p.Element->data1);
}

double_list::Iter&
double_list::Iter::operator++() {
	Element = Element->next;
	return *this;
}

double_list::Iter&
double_list::Iter::operator--() {
	Element = Element->prev;
	return *this;
}

double_list::Iter
double_list::begin() const {
	return Iter(head->next);
}

double_list::Iter
double_list::end() const {
	return Iter(tail->prev);
}