#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <sstream>

#include "single_list.h"

using namespace std;

/* DO NOT CHANGE INCLUDED HEADERS */

int main(int argc, char* argv[])
{
  /* 1st arg: input file name , 2nd arg: output file name */

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
	
	


	single_list Input_List;
	
	while (!Input_File_Stream.eof()) {
		string line;
		stringstream linestream;

		int message_num, packet_num;
		string data;


		getline(Input_File_Stream, line);
		cout << line << endl;

		linestream.str(line);

		
		linestream >> message_num;
		//cout << message_num << endl;
		
		linestream >> packet_num;
		//cout << packet_num << endl;

		linestream >> data;
		//cout << data << endl;

		list_elem *Element = new list_elem(message_num, packet_num, data);
		
		Input_List.list_insert_front(Element);
	}


	single_list Sorted_List;
	

	for (int number_of_message = 1; !Input_List.list_empty(); number_of_message++) {
		list_elem *Element = Input_List.list_head();




	}

	Input_File_Stream.close();
	Output_File_Stream.close();




	//FILE* input_file_pointer = NULL;
	//FILE* output_file_pointer = NULL;

	//input_file_pointer = fopen(argv[0], "rb");
	//output_file_pointer = fopen(argv[1], "wb");

	//if (input_file_pointer == NULL) {
	//	fprintf(stderr, "Please check input argument\n");
	//	exit(EXIT_FAILURE);
	//}

	//if (output_file_pointer == NULL) {
	//	fprintf(stderr, "Please check output argument\n");
	//	exit(EXIT_FAILURE);
	//}

  ///////////////////////////////////////////////////////
  //                                                   //
  //  SINGLY LINKED LIST RECEIVER IMPLEMENTATION HERE  //
  //                                                   //
  ///////////////////////////////////////////////////////
  
	
  return 0;
}
