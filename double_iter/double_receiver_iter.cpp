#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "double_list_iter.h"

using namespace std;

/* YOU CAN CHANGE INCLUDED HEADERS ^0^ */

int main(int argc, char* argv[])
{
  /* 1st arg: input file name , 2nd arg: output file name */

  double_list dlist;
  
  ///////////////////////////////////////////////////////
  //                                                   //
  //  DOUBLY LINKED LIST RECEIVER IMPLEMENTATION HERE  //
  //                                                   //
  ///////////////////////////////////////////////////////

  double_list::Iter p = find(dlist.begin(), dlist.end(), 4);
  if (p == dlist.end())
  {
    fout << "No 4th message" << endl;
  }
  else
  {
    fout << "4th message exists" << endl;
  }


  return 0;
}
