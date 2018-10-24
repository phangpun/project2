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
	
	time_t start;
	time_t end;

	time(&start);


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







	//single_list Message_Sorted_List;
	single_list** Message_Sorted_List = new single_list*[maximum_message_number];
	for (int i = 0; i < maximum_message_number; i++) {
		single_list* New_List = new single_list;
		Message_Sorted_List[i] = New_List;
	}
	
	

	list_elem *Input_Element = Input_List.list_head();
	list_elem *Next_Input_Element = NULL;

	while (!Input_List.list_empty()) {
		Next_Input_Element = Input_List.list_next(Input_Element);

		int Message_Num = Input_List.list_get_data1(Input_Element);
		
		

		list_elem *Sorted_Element = new list_elem(*Input_Element);

		Message_Sorted_List[Message_Num - 1]->list_insert_front(Sorted_Element);

		Input_List.list_remove(Input_Element);
		
		Input_Element = Next_Input_Element;
	}

	


	for (int i = 0; i < maximum_message_number; i++) {
		single_list *Target_List = Message_Sorted_List[i];

		list_elem *Before_Element = NULL;
		list_elem *Present_Element = Target_List->list_head();
		list_elem *Next_Element = NULL;

		if (Present_Element == NULL) continue;


		int Present_packet_num = Target_List->list_get_data2(Present_Element);
		int Next_packet_num = 0;
		
		while (Target_List->list_next(Present_Element) != NULL) {
			Next_Element = Target_List->list_next(Present_Element);
			Next_packet_num = Target_List->list_get_data2(Next_Element);


				
			if (Present_packet_num == Next_packet_num) {
				Target_List->list_remove(Present_Element);//head is strange
				Present_Element = Next_Element;
				Present_packet_num = Target_List->list_get_data2(Present_Element);
				continue;
			}
			else if (Present_packet_num > Next_packet_num) {
				list_elem* Element = new list_elem(*Next_Element);
				Target_List->list_insert_before(Present_Element, Element);
				

				Target_List->list_remove(Next_Element);
					
				if (Before_Element == NULL) {
					Present_Element = Element;
					Present_packet_num = Target_List->list_get_data2(Present_Element);
					continue;
				}
				else {
					Present_Element = Before_Element;
					Present_packet_num = Target_List->list_get_data2(Present_Element);

					Before_Element = Target_List->list_head();
					if (Before_Element == Present_Element) {
						Before_Element = NULL;
					}
					else
					{
						while (Target_List->list_next(Before_Element) != Present_Element) {
							Before_Element = Target_List->list_next(Before_Element);
						}
					}
					continue;
				}
			}
			
			Before_Element = Present_Element;
			Present_Element = Next_Element;
			Present_packet_num = Next_packet_num;
		}

	}
	

	for (int i = 0; i < maximum_message_number; i++) {
		single_list *Target_List = Message_Sorted_List[i];

		list_elem* Element = Target_List->list_head();
		list_elem* Next_Element = NULL;

		int packet = Target_List->list_get_data2(Element);
		int next_packet = 0;

		string word = Target_List->list_get_data3(Element);
		string next_word = "";


		Output_File_Stream << "- Message " << i + 1 << endl;
		//cout << "- Message " << i + 1 << endl;

		while (Element != NULL) {
			Next_Element = Target_List->list_next(Element);

			if (Next_Element == NULL) {
				Output_File_Stream << word << endl;
				//cout << word << endl;
				break;
			}

			next_packet = Target_List->list_get_data2(Next_Element);
			next_word = Target_List->list_get_data3(Next_Element);

			if (Element == Target_List->list_head()) {
				if (packet != 1) {
					for (int j = 1; j < packet; j++) {
						Output_File_Stream << "WARNING: packet " << j << " of message " << i + 1 << " is missing" << endl;
						//cout << "WARNING: packet " << j << " of message " << i + 1 << " is missing" << endl;
					}
				}
			}

			Output_File_Stream << word << endl;
			//cout << word << endl;

			int difference = next_packet - packet;
			if (difference != 1) {
				for (int j = 1; j < difference; j++) {
					Output_File_Stream << "WARNING: packet " << packet + j << " of message " << i + 1 << " is missing" << endl;
					//cout << "WARNING: packet " << packet + j << " of message " << i + 1 << " is missing" << endl;
				}
			}
			Element = Next_Element;
			packet = next_packet;
			word = next_word;
		}
		Output_File_Stream << "-End Message " << i + 1 << endl << endl;
		//cout << "-End Message " << i + 1 << endl << endl;
	}

	for (int i = 0; i < maximum_message_number; i++) {
		delete Message_Sorted_List[i];
	}
	delete[] Message_Sorted_List;
	
	time(&end);
	
	Output_File_Stream << "Running Time: " << difftime(end, start) << " s." << endl;
  
	
	return 0;
}
