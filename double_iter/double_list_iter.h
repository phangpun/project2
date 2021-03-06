#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <iterator>
#include <string>

using namespace std;

///////////////////////////////////////
// YOU CAN CHANGE THIS FILE  ^0^ //
///////////////////////////////////////

/*
  Glossary of list terms:

  - "front": The first element in a list. Undefined in an empty list.
  Returned by list_front().

  - "back": The last element in a list. Undefined in an empty list.
  Returned by list_back().
  
  - "tail": The element figuratively just after the last element of
  a list. Well defined even in an empty list. Returned by list_end(). 
  Used as the end sentinel for an iteration from front to back.
  
  - "beginning": In a non-empty list, the front. In an empty list,
  the tail. Returned by list_begin(). Used as the starting point for 
  an iteration from front to back.
  
  - "head": The element figuratively just before the first element
  of a list. Well defined even in an empty list. Returned by list_rend(). 
  Used as the end sentinel for an iteration from back to front.
  
  - "interior element": An element that is not the head or tail, that is,
  a real list element. An empty list does not have any interior elements.
*/

class double_list;

/* List element. */
class d_list_elem{

 friend class double_list;

 private:

  int data1; /* Data of list element. */
  int data2; /* Data of list element. */
  string data3; /* Data of list element. */
  d_list_elem *next; /* Next list element. */
  d_list_elem *prev;   /* Previous list element. */    

 public:
  /* List element constructor. */
  d_list_elem (){
    next = NULL;
    prev = NULL;
  }
  d_list_elem (int _data1, int _data2, string _data3, d_list_elem *_next =NULL, d_list_elem *_prev = NULL){
    data1 = _data1;
    data2 = _data2;
    data3 = _data3;
    next = _next;
    prev = _prev;
  }
};


/* Doubly Linked List. */
class double_list{

private:
	d_list_elem *head; //same with double_list.h / double_list.cpp
	d_list_elem *tail; //same with double_list.h / double_list.cpp
  
public:
		
	double_list();//same with double_list.h / double_list.cpp
	~double_list();//same with double_list.h / double_list.cpp

	void d_list_insert_front(d_list_elem *); //same with double_list.h / double_list.cpp
	void d_list_insert_back(d_list_elem *elem); //same with double_list.h / double_list.cpp

	d_list_elem* d_list_front(void); //same with double_list.h / double_list.cpp
	bool d_list_empty(void); //same with double_list.h / double_list.cpp


	//custom iterator implementation
	class Iter : public std::iterator<std::bidirectional_iterator_tag, d_list_elem> {
		
	public:
		int& operator*();
		bool operator==(const Iter& p) const;
		bool operator!=(const Iter& p) const;
		Iter& operator++();
		Iter& operator--();
		friend class double_list;
	private:
		d_list_elem * Element = NULL;
		Iter(d_list_elem* e);
	};
  

	Iter begin() const;
	Iter end() const;
};



#endif /* __DOUBLE_LIST_H__ */
