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

	//argument number check
	if (argc != 3) {
		fprintf(stderr, "Pleas check arguments\n");
		exit(EXIT_FAILURE);
	}

	//Input stream open
	ifstream Input_File_Stream(argv[1]);
	
	//Input stream check
	if (Input_File_Stream.fail()) {
		cout << "Please check input argument" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << "Input file name is \"" << argv[1] << "\"" << endl;
		cout << "Output file name is \"" << argv[2] << "\"" << endl;
	}

	//Output stream open
	ofstream Output_File_Stream(argv[2]);
	if (Output_File_Stream.fail()) {
		cout << "Please check output argument" << endl;
		exit(EXIT_FAILURE);
	}
	

	//for time check
	time_t start;
	time_t end;

	//time check start
	time(&start);


	//first single_list Input_List
	//Input_List is used for saving raw data of input stream.
	//There is no rearrangement of data
	single_list Input_List;
	int maximum_message_number = 0; //to find the number of message (scope of message)
	while (!Input_File_Stream.eof()) {
		string line;
		stringstream linestream;

		//input data
		int message_num, packet_num;
		string data;

		//get line from input data by string line
		getline(Input_File_Stream, line);

		//convert data from string to linestream
		linestream.str(line);

		//saving data
		linestream >> message_num;
		linestream >> packet_num;
		linestream >> data;

		//new element allocation
		list_elem *Element = new list_elem(message_num, packet_num, data);
		
		//save data to Input_list to front
		//data order is converted
		Input_List.list_insert_front(Element);

		//updata the number of message
		if (message_num > maximum_message_number) maximum_message_number = message_num;
	}

	Input_File_Stream.close();


	//====================== all data are saved to Input_List =================//



	//creation of pointer array Message_Sorted_List
	//each element of pointer array refer to single_list
	//each list is used for saving the same message number data
	single_list** Message_Sorted_List = new single_list*[maximum_message_number];
	for (int i = 0; i < maximum_message_number; i++) {
		single_list* New_List = new single_list;
		Message_Sorted_List[i] = New_List;
	}
	
	

	list_elem *Input_Element = Input_List.list_head();
	list_elem *Next_Input_Element = NULL;
	//searching all element of Input_List
	while (!Input_List.list_empty()) {
		Next_Input_Element = Input_List.list_next(Input_Element);
		int Message_Num = Input_List.list_get_data1(Input_Element);

		list_elem *Sorted_Element = new list_elem(*Input_Element);

		//data is saved to each List
		//data is inseted to front then, order of data is converted from Input_List
		//Then order of data is same with input data
		Message_Sorted_List[Message_Num - 1]->list_insert_front(Sorted_Element);

		//remove data from Input_List
		Input_List.list_remove(Input_Element);
		
		Input_Element = Next_Input_Element;
	}
	
	//====================== all data are sorted by message_number =================//

	//Each List has data which are the same message number
	//Each List has to be sorted by packet number
	for (int i = 0; i < maximum_message_number; i++) {
		//for one List of Message_Sorted_List
		single_list *Target_List = Message_Sorted_List[i];

		list_elem *Before_Element = NULL;
		list_elem *Present_Element = Target_List->list_head();
		list_elem *Next_Element = NULL;

		if (Present_Element == NULL) continue;


		int Present_packet_num = Target_List->list_get_data2(Present_Element);
		int Next_packet_num = 0;
		
		//packet sorting start in each List
		while (Target_List->list_next(Present_Element) != NULL) {
			Next_Element = Target_List->list_next(Present_Element);
			Next_packet_num = Target_List->list_get_data2(Next_Element);


			//if adjacent data have same number of packet
			//delete the previous data
			if (Present_packet_num == Next_packet_num) {
				Target_List->list_remove(Present_Element);
				Present_Element = Next_Element;
				Present_packet_num = Target_List->list_get_data2(Present_Element);
				continue;
			}

			//if previous data's packet number is smaller than next data
			//swap the data and set the pointers to compare previous one of swapped data
			else if (Present_packet_num > Next_packet_num) {
				list_elem* Element = new list_elem(*Next_Element);
				
				//swap data
				Target_List->list_insert_before(Present_Element, Element);
				Target_List->list_remove(Next_Element);
					
				//set pointers
				if (Before_Element == NULL) {//in case previous data don't exist
					Present_Element = Element;
					Present_packet_num = Target_List->list_get_data2(Present_Element);
					continue;
				}
				else {//in case previous data exists
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
			
			//next data
			Before_Element = Present_Element;
			Present_Element = Next_Element;
			Present_packet_num = Next_packet_num;
		}

	}
	

	//====================== all data are sorted by message_number and packet_number =================//


	//data is written to output file stream 
	for (int i = 0; i < maximum_message_number; i++) {
		single_list *Target_List = Message_Sorted_List[i];

		list_elem* Element = Target_List->list_head();
		list_elem* Next_Element = NULL;

		//get packet number
		int packet = Target_List->list_get_data2(Element);
		int next_packet = 0;

		string word = Target_List->list_get_data3(Element);
		string next_word = "";

		//data write start
		Output_File_Stream << "- Message " << i + 1 << endl;

		while (Element != NULL) {//for all data of each list
			Next_Element = Target_List->list_next(Element);

			//last element case
			if (Next_Element == NULL) {
				Output_File_Stream << word << endl;
				break;
			}

			next_packet = Target_List->list_get_data2(Next_Element);
			next_word = Target_List->list_get_data3(Next_Element);

			//first element case
			if (Element == Target_List->list_head()) {
				if (packet != 1) {
					for (int j = 1; j < packet; j++) {
						Output_File_Stream << "WARNING: packet " << j << " of message " << i + 1 << " is missing" << endl;
					}
				}
			}

			//middle element case
			Output_File_Stream << word << endl;


			//write WARNINGs
			int difference = next_packet - packet;
			if (difference != 1) {
				for (int j = 1; j < difference; j++) {
					Output_File_Stream << "WARNING: packet " << packet + j << " of message " << i + 1 << " is missing" << endl;
				}
			}


			//next data
			Element = Next_Element;
			packet = next_packet;
			word = next_word;
		}
		//data write end
		Output_File_Stream << "-End Message " << i + 1 << endl << endl;
	}

	//delete all data 
	for (int i = 0; i < maximum_message_number; i++) {
		delete Message_Sorted_List[i];
	}
	delete[] Message_Sorted_List;
	

	//end time check
	time(&end);
	
	//time is written
	Output_File_Stream << "Running Time: " << difftime(end, start) << " s." << endl;
  
	Output_File_Stream.close();
		
	
	return 0;
}
