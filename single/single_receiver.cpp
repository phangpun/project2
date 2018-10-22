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

		list_elem *Element = new list_elem(message_num, packet_num, data);
		Input_List.list_insert_front(Element);

		if (message_num > maximum_message_number) maximum_message_number = message_num;
		if (packet_num > maximum_packet_number) maximum_packet_number = packet_num;
	}



	time_t start;
	time_t end;

	time(&start);

	single_list Message_Sorted_List;

	

	for (int i = maximum_message_number; !Input_List.list_empty(); i--) {
		list_elem *Input_Element = Input_List.list_head();
		list_elem *Next_Input_Element = NULL;

		while (Input_Element != NULL) {
			Next_Input_Element = Input_List.list_next(Input_Element);
			if (Input_List.list_get_data1(Input_Element) == i) {

				list_elem *Sorted_Element = new list_elem(*Input_Element);
				Message_Sorted_List.list_insert_front(Sorted_Element);

				Input_List.list_remove(Input_Element);
			}
			Input_Element = Next_Input_Element;
		}
	}

	list_elem *Before_Element = NULL;
	list_elem *Present_Element = Message_Sorted_List.list_head();
	list_elem *Next_Element = NULL;

	for (int i = 1; i <= maximum_message_number;) {
		if (Present_Element == NULL) break;

		Next_Element = Message_Sorted_List.list_next(Present_Element);
		if (Next_Element == NULL) break;
		

		int present_message_num = Message_Sorted_List.list_get_data1(Present_Element);
		int next_message_num = Message_Sorted_List.list_get_data1(Next_Element);
		if (present_message_num != next_message_num) {
			i++;
			Present_Element = Next_Element;
			continue;
		}



		int present_packet_num = Message_Sorted_List.list_get_data2(Present_Element);
		int next_packet_num = Message_Sorted_List.list_get_data2(Next_Element);
		


		while (present_packet_num >= next_packet_num) {



			// in case packet numbers are same -> remove higher one
			if (present_packet_num == next_packet_num) {
				//set Before_Element
				Before_Element = Message_Sorted_List.list_head();

				if (Before_Element != Present_Element) {
					while (Message_Sorted_List.list_next(Before_Element) != Present_Element) {
						Before_Element = Message_Sorted_List.list_next(Before_Element);
					}
					Message_Sorted_List.list_remove(Present_Element);
					Present_Element = Before_Element;
					Next_Element = Message_Sorted_List.list_next(Present_Element);
				}
				else {
					Message_Sorted_List.list_remove(Present_Element);
					Present_Element = Next_Element;
					Next_Element = Message_Sorted_List.list_next(Present_Element);
				}

				present_message_num = Message_Sorted_List.list_get_data1(Present_Element);
				next_message_num = Message_Sorted_List.list_get_data1(Next_Element);
				if (present_message_num != next_message_num) {
					Present_Element = Next_Element;
					Next_Element = Message_Sorted_List.list_next(Present_Element);
				}

				
			}
			
			// in case packet numbers are not in order -> switch upside down
			else if (present_packet_num > next_packet_num) {
				list_elem *Element = new list_elem(*Next_Element);

				Message_Sorted_List.list_remove(Next_Element);
				Message_Sorted_List.list_insert_before(Present_Element, Element);


				//set Present_Element
				Present_Element = Message_Sorted_List.list_head();
				if (Present_Element != Element) {//head is not the replaced Element
					while (Message_Sorted_List.list_next(Present_Element) != Element) {
						Present_Element = Message_Sorted_List.list_next(Present_Element);
					}
					//set Next_Element
					Next_Element = Element;
				}
				else {//head is the replaced Element 
					Next_Element = Message_Sorted_List.list_next(Present_Element);
				}

				present_packet_num = Message_Sorted_List.list_get_data2(Present_Element);
				next_packet_num = Message_Sorted_List.list_get_data2(Next_Element);
			}

			present_packet_num = Message_Sorted_List.list_get_data2(Present_Element);
			next_packet_num = Message_Sorted_List.list_get_data2(Next_Element);
		}

		Present_Element = Next_Element;

	}

	list_elem* output_Element = Message_Sorted_List.list_head();
	list_elem* next_output_Element;
	
	int output_message_number = 0;
	int output_packet_number = 0;
	string output_packet_data = "";

	int next_output_message_number = 0;
	int next_output_packet_number = 0;
	string next_output_packet_data = "";

	bool first_packet = true;
	bool last_packet = false;

	int difference_packet_number = 0;

	while (output_Element != NULL) {
		next_output_Element = Message_Sorted_List.list_next(output_Element);

		output_message_number = Message_Sorted_List.list_get_data1(output_Element);
		output_packet_number = Message_Sorted_List.list_get_data2(output_Element);
		output_packet_data = Message_Sorted_List.list_get_data3(output_Element);

		if (next_output_Element != NULL) {
			next_output_message_number = Message_Sorted_List.list_get_data1(next_output_Element);
			next_output_packet_number = Message_Sorted_List.list_get_data2(next_output_Element);
			next_output_packet_data = Message_Sorted_List.list_get_data3(next_output_Element);

			if (first_packet) {
				Output_File_Stream << "- Message " << output_message_number << endl;
				//cout << "- Message " << output_message_number << endl;
				if (output_packet_number != 1) {
					for (int i = 1; i < output_packet_number; i++) {
						Output_File_Stream << "WARNING: packet " << i << " of message " << output_message_number << " is missing" << endl;
						//cout << "WARNING: packet " << i << " of message " << output_message_number << " is missing" << endl;
					}
					Output_File_Stream << output_packet_data << endl;
					//cout << output_packet_data << endl;
				}
				else {
					Output_File_Stream << output_packet_data << endl;
					//cout << output_packet_data << endl;

					difference_packet_number = next_output_packet_number - output_packet_number;
					for (int i = 1; i < difference_packet_number; i++) {
						Output_File_Stream << "WARNING: packet " << output_packet_number + i << " of message " << output_message_number << " is missing" << endl;
						//cout << "WARNING: packet " << output_packet_number + i << " of message " << output_message_number << " is missing" << endl;
					}

				}
				first_packet = false;
			}
			else {
				Output_File_Stream << output_packet_data << endl;
				//cout << output_packet_data << endl;

				difference_packet_number = next_output_packet_number - output_packet_number;
				if (difference_packet_number > 1) {
					for (int i = 1; i < difference_packet_number; i++) {
						Output_File_Stream << "WARNING: packet " << output_packet_number + i << " of message " << output_message_number << " is missing" << endl;
						//cout << "WARNING: packet " << output_packet_number + i << " of message " << output_message_number << " is missing" << endl;
					}
				}


			}

			last_packet = (output_message_number != next_output_message_number);
			if (last_packet) {
				Output_File_Stream << "- End Message " << output_message_number << endl << endl;
				//cout << "- End Message " << output_message_number << endl << endl;
				first_packet = true;
			}
		}
		else {
			Output_File_Stream << output_packet_data << endl;
			//cout << output_packet_data << endl;

			Output_File_Stream << "- End Message " << output_message_number << endl << endl;
			//cout << "- End Message " << output_message_number << endl << endl;

		}
		output_Element = next_output_Element;
	}

	time(&end);

	double seconds = difftime(end, start);

	Output_File_Stream << "Running Time: " << seconds << " s." << endl;

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
