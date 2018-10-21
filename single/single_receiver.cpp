#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <sstream>

//#include "single_list.h"

using namespace std;

/* DO NOT CHANGE INCLUDED HEADERS */

int main(int argc, char* argv[])
{
  /* 1st arg: input file name , 2nd arg: output file name */

	if (argc != 3) {
		fprintf(stderr, "Pleas check arguments\n");
		exit(EXIT_FAILURE);
	}

	
	FILE* input_file_pointer = NULL;
	FILE* output_file_pointer = NULL;

	input_file_pointer = fopen(argv[0], "rb");
	output_file_pointer = fopen(argv[1], "wb");

	if (input_file_pointer == NULL) {
		fprintf(stderr, "Please check input argument\n");
		exit(EXIT_FAILURE);
	}

	if (output_file_pointer == NULL) {
		fprintf(stderr, "Please check output argument\n");
		exit(EXIT_FAILURE);
	}

  ///////////////////////////////////////////////////////
  //                                                   //
  //  SINGLY LINKED LIST RECEIVER IMPLEMENTATION HERE  //
  //                                                   //
  ///////////////////////////////////////////////////////
  
	
  return 0;
}
