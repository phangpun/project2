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

  ///////////////////////////////////////////////////////
  //                                                   //
  //  DOUBLY LINKED LIST RECEIVER IMPLEMENTATION HERE  //
  //                                                   //
  ///////////////////////////////////////////////////////

  if (argc != 3) {
	  fprintf(stderr, "Pleas check arguments\n");
	  exit(EXIT_FAILURE);
  }


  ifstream Input_File_Stream(argv[1]);

  if (Input_File_Stream.fail()) {
	  cout << "Please check input argument" << endl;
	  exit(EXIT_FAILURE);
  }
  else {
	  cout << "Input file name is \"" << argv[1] << "\"" << endl;
	  cout << "Output file name is \"" << argv[2] << "\"" << endl;
  }

  ofstream Output_File_Stream(argv[2]);
  if (Output_File_Stream.fail()) {
	  cout << "Please check output argument" << endl;
	  exit(EXIT_FAILURE);
  }

  time_t start;
  time_t end;

  time(&start);

  
  double_list Input_List;
  int maximum_message_number = 0;
  int maximum_packet_number = 0;
  while (!Input_File_Stream.eof()) {
	  string line;
	  stringstream linestream;

	  int message_num, packet_num;
	  string data;


	  getline(Input_File_Stream, line);
	  //cout << line << endl;

	  linestream.str(line);


	  linestream >> message_num;
	  //cout << message_num << endl;

	  linestream >> packet_num;
	  //cout << packet_num << endl;

	  linestream >> data;
	  //cout << data << endl;

	  d_list_elem *Element = new d_list_elem(message_num, packet_num, data);
	  Input_List.d_list_insert_back(Element);

	  if (message_num > maximum_message_number) maximum_message_number = message_num;
	  if (packet_num > maximum_packet_number) maximum_packet_number = packet_num;
  }

  time(&end);


  double_list::Iter p = find(Input_List.begin(), Input_List.end(), 4);
  if (p == Input_List.end())
  {
	  Output_File_Stream << "No 4th message" << endl;
	  cout << "No 4th message" << endl;
  }
  else
  {
	  Output_File_Stream << "4th message exists" << endl;
	  cout << "4th message exists" << endl;
  }

  

  return 0;
}
